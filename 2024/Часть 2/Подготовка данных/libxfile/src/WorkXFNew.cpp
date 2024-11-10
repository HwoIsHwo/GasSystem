#include "WorkXFNew.h"
#include <stdarg.h>
#include <math.h>

//#include "ReadWriteFile.h"
long DELTA_MULTIPLIER;
long DELTA_FILE_MULTIPLIER;

#define BIG_ENDIAN

//////////////////////////////////////////////////////////////////////////////////
uint64_t getSamples(TimeInterval* interval, uint64_t deltaMultiplier)
{
  uint64_t samples = ((uint64_t)(interval->end - interval->begin)) * deltaMultiplier / interval->delta ;
  //samples += 1;
  return samples;
}

//////////////////////////////////////////////////////////////////////////////////
bool  isInside(TimeInterval* intervalSmall, TimeInterval* intervalBig)
{
  bool isAfterBegin = intervalSmall->begin <= intervalBig->begin;
  bool isBeforeEnd  = intervalSmall->end   >= intervalBig->end;

  return  (isAfterBegin && isBeforeEnd);
}

//////////////////////////////////////////////////////////////////////////////////
bool  isInside(TimeInterval* interval, float time)
{
  time *= NANOSECONDS_IN_SECOND / NANOSECONDS_IN_LMS_TICK;

  bool isAfterBegin = interval->begin <= time;
  bool isBeforeEnd  = interval->end   >= time;

  return  (isAfterBegin && isBeforeEnd);
}

//////////////////////////////////////////////////////////////////////////////////
int64_t getSampleNumber(TimeInterval* interval, float time, uint64_t deltaMultiplier)
{
  if(!isInside(interval, time))
    return -1;

  time *= NANOSECONDS_IN_SECOND / NANOSECONDS_IN_LMS_TICK;
  time = time - interval->begin;
  time *= deltaMultiplier;

  int64_t sample = (int64_t)(time / interval->delta);

  return sample;
}

//////////////////////////////////////////////////////////////////////////////////
int64_t getSampleNumber(TimeInterval* intervalSmall, TimeInterval* intervalBig, uint64_t deltaMultiplier)
{
  if(!isInside(intervalSmall, intervalBig))
    return -1;

  int64_t delta = intervalSmall->begin - intervalBig->begin;
  delta *= deltaMultiplier;

  int64_t sample = delta / intervalSmall->delta;

  return sample;
}

//////////////////////////////////////////////////////////////////////////////////
void XFile::baseInit()
{
  toClose                      = true;
  isExternalGetSamplesEnabled_ = false;
  file_                        = NULL;
  fileName_                    = NULL;
  memset(&head_, 0, sizeof(head_));
  head_.dtype                  = DTYPE_MAX + 1;
  addonlen_                    = 0;
  addon_                       = NULL;
  commentlen_                  = 0;
  comment_                     = NULL;
  data_                        = NULL;

  cnum_                        = 0;

  dim_                         = 0;
  arrayDimensions_             = NULL;

  version_                     = NULL;
  deltaMultiplier_             = 1;
  currentDataPtr_              = data_;
  isWriteEnabled_              = false;
  dataPosition_                = 0;

  interval_.clear();
  intervalFilled_.clear();
}

//////////////////////////////////////////////////////////////////////////////////
XFile::XFile()
{
  baseInit();
}

//////////////////////////////////////////////////////////////////////////////////
XFile::XFile(FILE* xFile,const char* xFileName, bool write)
{
  baseInit();
  file_           = xFile;
  fileName_       = strdup(xFileName);
  isWriteEnabled_ = write;
}

//////////////////////////////////////////////////////////////////////////////////
XFile::XFile(const char* xFileName, bool write)
{
  baseInit();
  fileName_ = strdup(xFileName);
  isWriteEnabled_ = write;
}

//////////////////////////////////////////////////////////////////////////////////
XFile::~XFile()
{   
  close();

  if(fileName_)
    free(fileName_);

  if(data_)
    free(data_);

  if(version_)
    delete version_;

  if(addon_)
    delete addon_;

  if(comment_)
    delete comment_;

  if(arrayDimensions_)
    delete arrayDimensions_;
}

//////////////////////////////////////////////////////////////////////////////////
void XFile::setComment(char* comment)
{
  if(comment_)
    free(comment_);

  if(comment) {
    if(strlen(comment) < MIN_COMMENT_LEN) {
      comment_ = (char*)malloc(MIN_COMMENT_LEN);
      memset(comment_,0,MIN_COMMENT_LEN);
      strcpy(comment_, comment);
    }
    else {
      comment_ = (char*)malloc(strlen(comment) + 1);
      memset(comment_,0, strlen(comment) + 1);
      strcpy(comment_, comment);
      commentlen_ = strlen(comment_);
    }
  } else {
    comment_    = NULL;
    commentlen_ = 0;
  }
  if(commentlen_ < MIN_COMMENT_LEN)
    commentlen_ = MIN_COMMENT_LEN;
}

//////////////////////////////////////////////////////////////////////////////////
void XFile::setAddon(char* addon)
{
  if(addon_)
    free(addon_);

  if(addon) {
    addon_ = strdup(addon);
    addonlen_ = strlen(addon_);
  } else {
    addon_    = NULL;
    addonlen_ = 0;
  }
}

//////////////////////////////////////////////////////////////////////////////////
int XFile::makeHeader(FileFormatVersion* version,
           uint8_t  dform,
           uint8_t  dtype,
           uint32_t shotnum,
           uint32_t shottime_sec,
           uint32_t shottime_usec,
           char* addon,
           char* comment)
{
  memset(head_.sign, 0, sizeof(head_.sign));

  head_.dform        = dform;
  head_.dtype        = dtype;
  head_.shotnum      = shotnum;
  head_.shottime_sec = shottime_sec;
  head_.shottime_usec = shottime_usec;

  if(version_)
    delete version_;

  version_ = version;

  if(version_->getMajor() <= 1 && version_->getMinor() <= 40)
    deltaMultiplier_ = 1;
  else if (version_->getMajor() <= 1 && version_->getMinor() <= 42)
    deltaMultiplier_ = 100;
  else
    deltaMultiplier_ = 1000;
            
  sprintf(head_.sign, "%s ", XFILE_SIGNATURE);

  if(version_)
    version_->toStr(head_.sign + strlen(head_.sign));

  setComment(comment);
  setAddon(addon);

  head_.headlen = sizeof(head_);// +  addonlen_ + commentlen_;
  return 0;
}

//////////////////////////////////////////////////////////////////////////////////
int XFile::getHeader(FileFormatVersion** version,
                     XFileHeader** header,
                     char** addon,
                     char** comment)
{
  *header = (XFileHeader*)malloc(sizeof(XFileHeader));
  **header = head_;

  *version = new FileFormatVersion(head_.sign + strlen(XFILE_SIGNATURE));

  if(version_->getMajor() <= 1 && version_->getMinor() <= 40)
    deltaMultiplier_ = 1;
  else   if(version_->getMajor() <= 1 && version_->getMinor() <= 42)
    deltaMultiplier_ = 100;
  else 
    deltaMultiplier_ = 1000;     
  
  if(addon_)
    *addon   = strdup(addon_);
  else
    *addon   = NULL;

  if(comment_)
    *comment = strdup(comment_);
  else
    *comment = NULL;

  return 0;
}

/////////////////////////////////////////////////////////
/// \brief XFile::reserveData - Универсальный reserveData
/// \param freq
/// \param samples
/// \return
/////////////////////////////////////////////////////////
int   XFile::reserveData(float freq,  uint32_t samples, double beginTimeInSeconds)
{
  int size;
  if((size = getDataSize()) > 0)
    data_ = malloc(samples * getSampleSize());
  else
    return -1;

  TimeInterval tempInterval;

  // delta необходимо высчитывать тщательно из-за возможной погрешности
  tempInterval.delta = (unsigned long)((uint64_t)NANOSECONDS_IN_SECOND  * deltaMultiplier_ / freq / NANOSECONDS_IN_LMS_TICK);
  tempInterval.begin = (unsigned long)(beginTimeInSeconds * (NANOSECONDS_IN_SECOND / NANOSECONDS_IN_LMS_TICK));
  
  // Смотрим отличие частоты при tempInterval.delta (усечение до целого) и tempInterval.delta+1
  float freqComputed        = (double)1.0 * NANOSECONDS_IN_SECOND / NANOSECONDS_IN_LMS_TICK / ((double)tempInterval.delta / deltaMultiplier_);
  float freqComputedPlusOne = (double)1.0 * NANOSECONDS_IN_SECOND / NANOSECONDS_IN_LMS_TICK / ((double)(tempInterval.delta + 1) / deltaMultiplier_);
  if((freq - freqComputedPlusOne) < (freqComputed - freq))
    tempInterval.delta++;

  tempInterval.end   = tempInterval.begin + ceil((double)tempInterval.delta * samples / deltaMultiplier_) ;

  interval_.clear();
  interval_.push_back(tempInterval);
  return 0;
}

//////////////////////////////////////////////////////////////////////////////////
/// \brief XFile::reserveData -  Универсальный reserveData
/// \param interval
/// \return
///
int XFile::reserveData(TimeInterval interval)
{
  uint32_t samples = ::getSamples(&interval,deltaMultiplier_);

  int size;
  if((size = getDataSize()) > 0)
    data_ = malloc(samples * getSampleSize());
  else
    return -1;

  interval_.clear();
  interval_.push_back(interval);
  return 0;
}


//////////////////////////////////////////////////////////////////////////////////
/// \brief XFile::reserveData - reserveData для DFORM0
/// \param cnum
/// \param freq
/// \param samples
/// \return
///
int XFile::reserveData(int cnum, float freq, uint32_t samples, double beginTimeInSeconds)
{
  if(head_.dform == VECTOR_BY_TIME)
    cnum_ = cnum;
  else
    return -1;

  return reserveData(freq, samples, beginTimeInSeconds);
}

//////////////////////////////////////////////////////////////////////////////////
/// \brief XFile::reserveData - Для DFORM3
/// \param freq
/// \param samples
/// \param dim
/// \return
///
int   XFile::reserveData(float freq,  uint32_t samples, uint8_t dim, ...)
{
  if(head_.dform != MULTIDIMENSIONAL_BY_TIME)
    return -1;

  va_list vl;
  va_start(vl, dim);

  dim_ = dim;

  uint32_t offset = 0;
  if(arrayDimensions_)
    delete arrayDimensions_;

  arrayDimensions_ = new uint32_t[dim_];

  for(int iDim = 0; iDim < dim_; iDim++) {
    arrayDimensions_[iDim] = va_arg(vl,int);
    if(arrayDimensions_[iDim] <= 0) {
      dim_ = 0;
      delete arrayDimensions_;
      return -1;
    }
  }
  va_end(vl);
  return reserveData(freq, samples);
}

int   XFile::reserveData(float freq,  uint32_t samples, double beginTimeInSeconds, uint8_t dim, ...)
{
  if(head_.dform != MULTIDIMENSIONAL_BY_TIME)
    return -1;

  va_list vl;
  va_start(vl, dim);

  dim_ = dim;

  uint32_t offset = 0;
  if(arrayDimensions_)
    delete arrayDimensions_;

  arrayDimensions_ = new uint32_t[dim_];

  for(int iDim = 0; iDim < dim_; iDim++) {
    arrayDimensions_[iDim] = va_arg(vl,int);
    if(arrayDimensions_[iDim] <= 0) {
      dim_ = 0;
      delete arrayDimensions_;
      return -1;
    }
  }
  va_end(vl);
  return reserveData(freq, samples, beginTimeInSeconds);
}


//////////////////////////////////////////////////////////////////////////////////
/// \brief XFile::reserveData - Для DFORM3
/// \param interval
/// \param dim
/// \return
///
int   XFile::reserveData(TimeInterval interval,uint8_t dim, ...)
{
  if(head_.dform != MULTIDIMENSIONAL_BY_TIME)
    return -1;

  va_list vl;
  va_start(vl, dim);

  dim_ = dim;

  uint32_t offset = 0;
  if(arrayDimensions_)
    delete arrayDimensions_;

  arrayDimensions_ = new uint32_t[dim_];

  for(int iDim = 0; iDim < dim_; iDim++) {
    arrayDimensions_[iDim] = va_arg(vl,int);
    if(arrayDimensions_[iDim] <= 0) {
      dim_ = 0;
      delete arrayDimensions_;
      return -1;
    }
  }
  va_end(vl);
  return reserveData(interval);
}

//////////////////////////////////////////////////////////////////////////////////
/// \brief XFile::reserveData - Для DFORM3
/// \param offsetInSamples
/// \param dim
/// \return
///
void* XFile::getDataPointerByCoord(uint32_t offsetInSamples, ...)
{
  if(head_.dform != MULTIDIMENSIONAL_BY_TIME &&
     head_.dform != VECTOR_BY_TIME)
   return NULL;

  va_list vl;
  va_start(vl, offsetInSamples);

  uint32_t offset = 0;

  if(head_.dform == MULTIDIMENSIONAL_BY_TIME) {
    int* coordinates = new int[dim_];

    for(int iDim = 0; iDim < dim_; iDim++) {
      coordinates[iDim] = va_arg(vl,int);
      if(coordinates[iDim] < 0 || coordinates[iDim] >= arrayDimensions_[iDim])
        return NULL;
    }
    for(int iDim = 0; iDim < dim_; iDim++) {
       if(iDim != (dim_ - 1))
         offset += coordinates[iDim] * arrayDimensions_[iDim + 1];
       else
         offset += coordinates[iDim];
    }
  } else if(head_.dform == VECTOR_BY_TIME) {
    offset = va_arg(vl,int);
  }
  va_end(vl);
  return (char*)getDataPointerForSample(offsetInSamples) + (offset * getDataSize());
}

//////////////////////////////////////////////////////////////////////////////////
/// \brief XFile::reserveData - reserveData для DFORM0
/// \param cnum
/// \param interval
/// \return
int XFile::reserveData(int cnum, TimeInterval interval)
{
  if(head_.dform == VECTOR_BY_TIME)
    cnum_ = cnum;
  else
    return -1;

  return reserveData(interval);
}

//////////////////////////////////////////////////////////////////////////////////
int XFile::samplesWritten(uint32_t samples)
{
  vector <TimeInterval>::iterator itFilled;  // declare an iterator to a vector of strings
  vector <TimeInterval>::iterator it;  // declare an iterator to a vector of strings

  TimeInterval* currentInterval;
  if(intervalFilled_.size() == 0) {
    intervalFilled_.push_back(interval_[0]);
    intervalFilled_[0].end = 0;
  }
  for(itFilled=intervalFilled_.begin(), it=interval_.begin(); itFilled < intervalFilled_.end(); itFilled++, it++) {
    currentInterval = &(*itFilled);
    currentInterval->begin = (*it).begin;
    currentInterval->end   = (*it).begin;
    currentInterval->delta = (*it).delta;
    currentInterval->end += ceil(((double)currentInterval->delta * samples) / deltaMultiplier_);
  }
  return 0;
}

//////////////////////////////////////////////////////////////////////////////////
int XFile::samplesWritten(TimeInterval interval)
{
   vector <TimeInterval>::iterator itFilled;  // declare an iterator to a vector of strings

   TimeInterval* currentInterval;
   for(itFilled=intervalFilled_.begin(); itFilled < intervalFilled_.end(); itFilled++) {
     currentInterval        = &(*itFilled);
     currentInterval->begin = interval.begin;
     currentInterval->delta = interval.delta;
     currentInterval->end +=  (interval.end - interval.begin);
   }
   return 0;
}

//////////////////////////////////////////////////////////////////////////////////
void*          XFile::getDataPointer(TimeInterval interval)
{
  vector <TimeInterval>::iterator itFilled;  // declare an iterator to a vector of strings

  TimeInterval* currentInterval;
  if(!intervalFilled_.empty()) {
    for(itFilled=intervalFilled_.begin(); itFilled < intervalFilled_.end(); itFilled++) {
      currentInterval        = &(*itFilled);

      if(isInside(&interval, currentInterval)) {
        int offsetInSamples = getSampleNumber(&interval, currentInterval,deltaMultiplier_);
        return getDataPointerForSample(offsetInSamples);
      }
    }
  }
  return (char*)data_;
}

void*        XFile::getDataPointerForSample(uint32_t offsetInSamples)
{
  return (char*)data_ + (offsetInSamples * getSampleSize());
}

//////////////////////////////////////////////////////////////////////////////////
/// \brief XFile::getDataPointer - Для DFORM0
/// \param offsetInSamples
/// \param channel
/// \return
///
/*void*           XFile::getDataPointer(uint32_t offsetInSamples, uint16_t channel)
{
  if(head_.dform != VECTOR_BY_TIME)
    return NULL;

  return (char*)getDataPointerForSample(offsetInSamples) + channel * getDataSize();
}*/

//////////////////////////////////////////////////////////////////////////////////
void*          XFile::getDataPointer(float timeInSeconds)
{
    vector <TimeInterval>::iterator itFilled;  // declare an iterator to a vector of strings

    TimeInterval* currentInterval;
    if(!intervalFilled_.empty()) {
      for(itFilled=intervalFilled_.begin(); itFilled < intervalFilled_.end(); itFilled++) {
        currentInterval        = &(*itFilled);

        if(isInside(currentInterval, timeInSeconds)) {
          int offsetInSamples = getSampleNumber(currentInterval, timeInSeconds,deltaMultiplier_);
          return getDataPointerForSample(offsetInSamples);
        }
      }
    }
   return (char*)data_;
}

//////////////////////////////////////////////////////////////////////////////////
int            XFile::getSampleSize()
{
  long long dataElements = 1;
  switch(head_.dform) {
    case VECTOR_BY_TIME:
      return cnum_ * getDataSize();
      break;
    case MULTIDIMENSIONAL_BY_TIME:
      for(int iDim = 0; iDim < dim_; iDim++)
        dataElements *= arrayDimensions_[iDim];
      return (dim_ > 0) ? dataElements * getDataSize() : 0;
      break;
    default:
      break;
  }
  return 0;
}

//////////////////////////////////////////////////////////////////////////////////
uint32_t       XFile::getSamplesLeft(void* dataPointer)
{
  vector <TimeInterval>::iterator it;  // declare an iterator to a vector of strings

  TimeInterval* currentInterval;
  for(it=interval_.begin(); it < interval_.end(); it++) {
    currentInterval        = &(*it);
    int offsetInSamples = ((uint64_t)((char*)dataPointer - (char*)data_)) / getSampleSize();
    int samplesTotal    = ::getSamples(currentInterval,deltaMultiplier_);
    return samplesTotal - offsetInSamples;

  }
  return 0;
}

//////////////////////////////////////////////////////////////////////////////////
uint32_t       XFile::getSamples()
{
  vector <TimeInterval>::iterator it;  // declare an iterator to a vector of strings

  TimeInterval* currentInterval;
  for(it=interval_.begin(); it < interval_.end(); it++) {
    currentInterval        = &(*it);
    int samplesTotal    = ::getSamples(currentInterval,deltaMultiplier_);
    return samplesTotal;
  }
  return 0;
}

//////////////////////////////////////////////////////////////////////////////////
float       XFile::getDuration()
{
  double duration = ((double)getSamples() - 1)*getDelta();
  if(duration < 0) 
    duration = 0;
  return duration;

  vector <TimeInterval>::iterator it;  // declare an iterator to a vector of strings
  it = interval_.end();
  --it;
  TimeInterval* currentInterval;
  return ((double)(*it).end) / (NANOSECONDS_IN_SECOND / NANOSECONDS_IN_LMS_TICK);
}

//////////////////////////////////////////////////////////////////////////////////
double       XFile::getDelta()
{
  vector <TimeInterval>::iterator it;  // declare an iterator to a vector of strings
  it = interval_.end();
  --it;

  return ((double)(*it).delta) / (NANOSECONDS_IN_SECOND / NANOSECONDS_IN_LMS_TICK) / deltaMultiplier_;
}


//////////////////////////////////////////////////////////////////////////////////
int            XFile::getDataSize()
{
  switch(head_.dtype) {
    case DTYPE_INT8:   return sizeof(int8_t);
    case DTYPE_UINT8:  return sizeof(uint8_t);
    case DTYPE_INT16:  return sizeof(int16_t);
    case DTYPE_UINT16: return sizeof(uint16_t);
    case DTYPE_INT32:  return sizeof(int32_t);
    case DTYPE_UINT32: return sizeof(uint32_t);
    case DTYPE_FLOAT:  return sizeof(float);
    case DTYPE_DOUBLE: return sizeof(double);
    default: return -1;
  }
}

static long getFileSize(int fd)
{
    struct stat stat_buf;
    int rc = fstat(fd, &stat_buf);
    return rc == 0 ? stat_buf.st_size : -1;
}

long            XFile::getFileSize()
{
  if(!file_)
   return -1;

  return ::getFileSize(fileno(file_));
}

//////////////////////////////////////////////////////////////////////////////////
int            XFile::setData(void* data)
{
  if(data_)
    free(data_);
  data_ = data;
  return 0;
}

//////////////////////////////////////////////////////////////////////////////////
void*     XFile::getSampleExternal(int channel, uint32_t sample)
{
  return NULL;
}

//////////////////////////////////////////////////////////////////////////////////
uint32_t  XFile::getSamplesExternal(int channel, uint32_t sample)
{
  return 0;
}

#define SWAP_U_16(num) ((num>>8) | (num<<8))
#define SWAP_U_32(num) (((num>>24)&0xff)   |   \
                       ((num<<8)&0xff0000) |   \
                       ((num>>8)&0xff00)   |   \
                       ((num<<24)&0xff000000))


//////////////////////////////////////////////////////////////////////////////////
int XFile::save()
{
  vector <TimeInterval>::iterator itFilled;  // declare an iterator to a vector of strings

  TimeInterval* currentInterval;
  int totalSamples = 0;
  int rc;

  for(itFilled=intervalFilled_.begin(); itFilled < intervalFilled_.end(); itFilled++) {
    currentInterval        = &(*itFilled);
    totalSamples += ::getSamples(currentInterval,deltaMultiplier_);
  }
  uint16_t tnum_ = intervalFilled_.size();
  head_.datalen = (totalSamples * getSampleSize());

#ifdef BIG_ENDIAN
  XFileHeader head = head_;
  head.headlen      = SWAP_U_32(head.headlen);
  head.datalen      = SWAP_U_32(head.datalen);
  head.shotnum      = SWAP_U_32(head.shotnum);
  head.shottime_sec = SWAP_U_32(head.shottime_sec);
  head.shottime_usec = SWAP_U_32(head.shottime_usec);
  rc = fwrite(&head,     sizeof(head),     1, file_);
#else
  rc = fwrite(&head_,     sizeof(head_),     1, file_);
#endif

  rc = fwrite(&addonlen_, sizeof(addonlen_), 1, file_);
  if(addonlen_)
    rc = fwrite(addon_, addonlen_, 1, file_);

  rc = fwrite(&commentlen_, sizeof(commentlen_), 1, file_);
  if(commentlen_)
    rc = fwrite(comment_, commentlen_, 1, file_);

  // Пишем структуру данных. Для разных DFORM она разная
  switch(head_.dform) {
    case VECTOR_BY_TIME:
      #ifdef BIG_ENDIAN
        cnum_      = SWAP_U_32(cnum_);
        tnum_      = SWAP_U_32(tnum_);
      #endif

      rc = fwrite(&cnum_, sizeof(cnum_), 1, file_);
      rc = fwrite(&tnum_, sizeof(tnum_), 1, file_);

      for(itFilled=intervalFilled_.begin(); itFilled < intervalFilled_.end(); itFilled++) {
        #ifdef BIG_ENDIAN
          itFilled->begin      = SWAP_U_32(itFilled->begin);
          itFilled->end        = SWAP_U_32(itFilled->end);
          itFilled->delta      = SWAP_U_32(itFilled->delta);
        #endif
        rc = fwrite(&(*itFilled), sizeof(TimeInterval), 1, file_);
        /*
      typedef struct TimeInterval {
        unsigned long begin; 		// начало временного интервала
        unsigned long end;		// конец временного интервала
        unsigned long delta;		// шаг временного интервала
      }  __attribute__((packed)) TimeInterval;
        */
      }
      break;
    case VECTOR_BY_VAR:
      break;
    case MULTIDIMENSIONAL:
      break;
    case MULTIDIMENSIONAL_BY_TIME:
      rc = fwrite(&dim_, sizeof(dim_), 1, file_);
      for(int iDim = 0; iDim < dim_; iDim++)
        rc = fwrite(&arrayDimensions_[iDim], sizeof(arrayDimensions_[iDim]), 1, file_);

      rc = fwrite(&tnum_, sizeof(tnum_), 1, file_);

      for(itFilled=intervalFilled_.begin(); itFilled < intervalFilled_.end(); itFilled++) {
        rc = fwrite(&(*itFilled), sizeof(TimeInterval), 1, file_);
      }
      break;
    case MULTIMEDIA:
      break;
    default:
      break;
  }

  uint32_t dataPortion = head_.datalen / 1000;
  if(dataPortion == 0)
    dataPortion = 1;

  uint32_t currentOffset = 0;
  float iPercent;

  #ifdef BIG_ENDIAN
    uint32_t* ptr;
  #endif
  for (iPercent = 0; iPercent < 100.0; iPercent+= 0.1) {
    if((head_.datalen - currentOffset) < dataPortion)
      break;

//#ifdef BIG_ENDIAN
//  itFilled->begin      = SWAP_U_32(itFilled->begin);
//  itFilled->end        = SWAP_U_32(itFilled->end);
//  itFilled->delta      = SWAP_U_32(itFilled->delta);
//#endif

    #ifdef BIG_ENDIAN
      ptr = (uint32_t*)((char*)data_ + currentOffset);
      for(int iData = 0; iData < dataPortion / sizeof(float); iData++) {
        *ptr = SWAP_U_32(*ptr);
        ptr++;
      }
    #endif
    rc = fwrite((char*)data_ + currentOffset, dataPortion, 1, file_);
    currentOffset += dataPortion;
    percentIndication(fileName_, iPercent);
  }
  if(currentOffset < head_.datalen) {
    #ifdef BIG_ENDIAN
      ptr = (uint32_t*)((char*)data_ + currentOffset);
      for(int iData = 0; iData < (head_.datalen - currentOffset) / sizeof(float); iData++) {
        *ptr = SWAP_U_32(*ptr);
        ptr++;
      }
    #endif
    rc = fwrite((char*)data_ + currentOffset, head_.datalen - currentOffset, 1, file_);
  }
  percentIndication(fileName_, 100.0);

  return 0;
}

//////////////////////////////////////////////////////////////////////////////////
int XFile::open()
{
  if(!file_ && fileName_) {
   if(isWriteEnabled_)
     file_ = fopen(fileName_, "wb");
   else
     file_ = fopen(fileName_, "rb");
   if(file_)
     return 0;
  }
  return -1;
}

//////////////////////////////////////////////////////////////////////////////////
int XFile::close()
{
  if(toClose && (file_ != NULL))
    fclose(file_);

  file_ = NULL;
  return 0;
}

//////////////////////////////////////////////////////////////////////////////////
int XFile::loadHeader()
{
    int rc;
    // Загружаем заголовок, комментарий, addon
    rc = fread(&head_,     sizeof(head_),     1, file_);
    version_ = new FileFormatVersion(head_.sign + strlen(XFILE_SIGNATURE));

    rc = fread(&addonlen_, sizeof(addonlen_), 1, file_);
    if(addonlen_) {
      if(addon_)
        free(addon_);
      addon_ = (char*)malloc(addonlen_ + 1);
      rc = fread(addon_, addonlen_, 1, file_);
      addon_[addonlen_] = 0;
    }

    rc = fread(&commentlen_, sizeof(commentlen_), 1, file_);
    if(commentlen_) {
      if(comment_)
        free(comment_);
      comment_ = (char*)malloc(commentlen_ + 1);
      rc = fread(comment_, commentlen_, 1, file_);
      comment_[commentlen_] = 0;
    }
    uint16_t tnum_;
    TimeInterval currentInterval;

    // Считываем  структуру данных. Для разных DFORM она разная
    switch(head_.dform) {
      case VECTOR_BY_TIME:
        rc = fread(&cnum_, sizeof(cnum_), 1, file_);
        rc = fread(&tnum_, sizeof(tnum_), 1, file_);

        // Считываем временные отрезки
        interval_.clear();
        for(int iInterval = 0; iInterval < tnum_; iInterval++) {
          rc = fread(&currentInterval, sizeof(currentInterval), 1, file_);
          interval_.push_back(currentInterval);
        }
        break;
      case VECTOR_BY_VAR:
        break;
      case MULTIDIMENSIONAL:
        break;
      case MULTIDIMENSIONAL_BY_TIME:
        rc = fread(&dim_, sizeof(dim_), 1, file_);
        arrayDimensions_ = new uint32_t[dim_];

        for(int iDim = 0; iDim < dim_; iDim++)
          rc = fread(&arrayDimensions_[iDim], sizeof(arrayDimensions_[iDim]), 1, file_);

        rc = fread(&tnum_, sizeof(tnum_), 1, file_);

        // Считываем временные отрезки
        interval_.clear();
        for(int iInterval = 0; iInterval < tnum_; iInterval++) {
          rc = fread(&currentInterval, sizeof(currentInterval), 1, file_);
          interval_.push_back(currentInterval);
        }
        break;
      case MULTIMEDIA:
        break;
      default:
        break;
    }

    dataPosition_ = ftell(file_);
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////
int XFile::loadData()
{
   TimeInterval currentInterval = interval_[0];
   interval_.clear();
   int rc     = reserveData(currentInterval);
   //void* data = getDataPointer(0);

   uint32_t dataPortion = head_.datalen / 1000;

   if(dataPortion == 0)
     dataPortion = 1;

   uint32_t currentOffset = 0;
   float iPercent;

   for (iPercent = 0; iPercent < 100.0; iPercent+= 0.1) {
     if((head_.datalen - currentOffset) < dataPortion)
       break;

     rc = fread((char*)data_ + currentOffset, dataPortion, 1, file_);
     currentOffset += dataPortion;
     percentIndication(fileName_, iPercent);
   }
   if(currentOffset < head_.datalen) {
     rc = fread((char*)data_ + currentOffset, head_.datalen - currentOffset, 1, file_);
   }
   percentIndication(fileName_, 100.0);
   return 0;
}

int32_t  XFile::readSamples(void* buffer,
                          TimeInterval interval,                         
                          uint32_t decimation)
{
  // Смотрим начало интервала и его конец, вычисляем начальный номер отсчета и количество
  // отсчетов интервала
  //int samplesTotal    = ::getSamples(currentInterval,deltaMultiplier_);  
  return 0;
}

int32_t  XFile::readSamplesFromTime(void* buffer,
                                  float time,
                                  uint32_t samples,
                                  uint32_t decimation
                                  )
{
  char* firstSamplePointer    = (char*)getDataPointer(time);
  uint32_t  startSampleNumber = (firstSamplePointer - (char*)data_) / getSampleSize();
  return readSamplesFromNumber(buffer,
                               startSampleNumber,
                               samples,
                               decimation);
}

int32_t  XFile::readSamplesFromNumber(void* buffer,
                                    uint32_t startSampleNumber,
                                    uint32_t samples,
                                    uint32_t decimation)
{
  if(decimation == 0)
    decimation = 1;
    
  const int CHANNEL_0_OFFSET = 0;
  uint32_t totalSamples = getSamples();
  if((startSampleNumber + samples) > totalSamples) {
    samples = totalSamples - startSampleNumber;
  }
  //    return -1; // Недостаточно отсчетов

  // Получаем смещение данных для указанного отсчета
  char* startingSample   = (char*)getDataPointerForSample(startSampleNumber);
  char* plusOneSample    = (char*)getDataPointerForSample(startSampleNumber + 1);
  char* lastSample       = (char*)getDataPointerForSample(startSampleNumber + samples);
  char* decimationSample = (char*)getDataPointerForSample(startSampleNumber + decimation);

  uint32_t fileOffset     = startingSample - (char*)data_ + dataPosition_;
  uint32_t readDataCount  = (lastSample - startingSample);
  uint32_t decimationStep = decimationSample - startingSample;
  uint32_t sampleStep     = plusOneSample - startingSample;

  fseek(file_, fileOffset, SEEK_SET);
  int rc;
  // Вырожденный случай, можно считывать все данные подряд
  uint32_t dataPortion = head_.datalen / 100;

  if(dataPortion == 0)
    dataPortion = 1;

  uint32_t currentOffset = 0;

  if(decimation == 1) {
    while(1) {
      if(currentOffset > readDataCount)
        break;
      //if(currentOffset >= head_.datalen)
      //  break;

      if((head_.datalen - currentOffset) < dataPortion)
        dataPortion = head_.datalen - currentOffset;

      if((readDataCount - currentOffset) < dataPortion)
        dataPortion = readDataCount - currentOffset;
      //if(currentOffset >= head_.datalen)
      //  break;

      if((head_.datalen - currentOffset) < dataPortion)
        dataPortion = head_.datalen - currentOffset;

      if((readDataCount - currentOffset) < dataPortion)
        dataPortion = readDataCount - currentOffset;

      rc = fread((char*)buffer + currentOffset, dataPortion, 1, file_);
      currentOffset += dataPortion;
      if(dataPortion == 0)
        break;
    }
    samples = currentOffset / sampleStep;
  } else {
     uint32_t currentOffset = 0;
    // Иначе цикл с перемещением указателя чтения файла
    for(int iCurrentSample = 0; iCurrentSample < samples; iCurrentSample++) {
      fseek(file_, fileOffset, SEEK_SET);
      if(currentOffset + sampleStep > head_.datalen) {
        break;
      }
      rc = fread((char*)buffer + currentOffset, sampleStep, 1, file_);
      currentOffset += sampleStep;
      fileOffset += decimationStep;
    }
    samples = currentOffset / sampleStep;    
  }
  return samples;
}

