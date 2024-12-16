//XRead.h
#ifndef __WorkXF_h
#define __WorkXF_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <stdint.h>
#include <sys/stat.h>
//#include <sys/time.h>
#include <sys/types.h>
#include <expcross.h>

#define SIGNATURE_LENGTH (20)
#define XFILE_SIGNATURE "$&X-File"
#define XFILE_VERSION "v01.040"
//#define MIN_COMMENT_LEN (512)
#define MIN_COMMENT_LEN (0)

#define XFILE_VERSION_1_40 new FileFormatVersion(1,40)
#define XFILE_VERSION_1_42 new FileFormatVersion(1,42)
#define XFILE_VERSION_1_43 new FileFormatVersion(1,43)

using namespace std;

typedef enum
{
  VECTOR_BY_TIME           = 0,  // ���������� ������ �������, ��������� �� �������
  VECTOR_BY_VAR            = 1,  // ���������� ������ �������, ��������� �� ����������
  MULTIDIMENSIONAL         = 2,  // ����������� ������
  MULTIDIMENSIONAL_BY_TIME = 3,  // ����������� ������ �������, ��������� �� �������
  MULTIMEDIA               = 4,  // ����������� (�����, �����������, ����)
  DFORM_MAX                = MULTIMEDIA
} DForm;

typedef enum
{
  DTYPE_INT8   = 0, // 8-��� ����� �����
  DTYPE_UINT8  = 1, // ����������� 8-��� ����� �����
  DTYPE_INT16  = 2, // 16-��� ����� �����
  DTYPE_UINT16 = 3, // ����������� 16-��� ����� �����
  DTYPE_INT32  = 4, // 32-��� ����� �����
  DTYPE_UINT32 = 5, // ����������� 32-��� ����� �����
  DTYPE_FLOAT  = 6, // ����� � ��������� ������
  DTYPE_DOUBLE = 7, // ����� � ��������� ������ ��������� ��������
  DTYPE_MAX    = DTYPE_DOUBLE
} DType;

class FileFormatVersion
{
  public:
   FileFormatVersion(char* str)            {  fromStr(str); }
   FileFormatVersion(int major, int minor) {  major_ = major; minor_ = minor;               }
   char* toStr(char* str)                  {  sprintf(str, "v%02d.%03d", major_, minor_);  return str;}
   int   fromStr(const char* str)
   {
     str+=2;
     int count = sscanf(str, "%02u", &major_);
     str+=3;
     count += sscanf(str, "%03u", &minor_);
     return (count == 2);
   }
   unsigned int getMajor() {return major_;}
   unsigned int getMinor() {return minor_;}

  private:
    unsigned int major_;
    unsigned int minor_;
};

/// ��������� ��������� X-�����
#ifdef OS_LINUX
typedef struct XFileHeader {
  char     sign[SIGNATURE_LENGTH];
  uint32_t headlen;
  uint32_t datalen;
  uint8_t  dform;
  uint8_t  dtype;
  uint32_t shotnum;
  uint32_t shottime_sec;
  uint32_t shottime_usec;
  //  uint32_t addon_len;
  //  char     addon[addon_len]
  //  uint32_t comment_len;
  //  char     comment[comment_len]
  //  data
} __attribute__((packed)) XFileHeader;

typedef struct TimeInterval {
  unsigned long begin; 		// ������ ���������� ���������
  unsigned long end;		// ����� ���������� ���������
  unsigned long delta;		// ��� ���������� ���������
}  __attribute__((packed)) TimeInterval;

#elif defined(OS_WINDOWS)
#pragma pack(push,1)
typedef struct XFileHeader {
  char     sign[SIGNATURE_LENGTH];
  uint32_t headlen;
  uint32_t datalen;
  uint8_t  dform;
  uint8_t  dtype;
  uint32_t shotnum;
  uint32_t shottime_sec;
  uint32_t shottime_usec;
  //  uint32_t addon_len;
  //  char     addon[addon_len]
  //  uint32_t comment_len;
  //  char     comment[comment_len]
  //  data
}  XFileHeader;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct TimeInterval {
  unsigned long begin; 		// ������ ���������� ���������
  unsigned long end;		// ����� ���������� ���������
  unsigned long delta;		// ��� ���������� ���������
}  TimeInterval;

#pragma pack(pop)
#endif

//#include "ReadWriteFile.h"
extern long DELTA_MULTIPLIER;
extern long DELTA_FILE_MULTIPLIER;

#define NANOSECONDS_IN_SECOND (1000000000.0)
#define LMS_TICKS_IN_USECOND (10UL)
#define NANOSECONDS_IN_LMS_TICK (100UL)
#define USECOND (10UL)
#define DELTA_USECOND (USECOND*DELTA_MULTIPLIER)
#define MSECOND (USECOND*1000)
#define DELTA_MSECOND (MSECOND*DELTA_MULTIPLIER)
#define SECOND (MSECOND*1000)
#define DELTA_SECOND (SECOND*DELTA_MULTIPLIER)

#define MAX_BUFF_SIZE	10000000

//////////////////////////////////////////////////////////////////////////////////
typedef enum FileMode {
  MODE_READ = 0,
  MODE_WRITE = 1
} FileMode;

//////////////////////////////////////////////////////////////////////////////////
class XFile {
  public:
    XFile();
    XFile(FILE* xFile, const char* xFileName, bool write);
    XFile(const char* xFileName, bool write);

    /*XFile(FILE* xFile, const char* xFileName, FileMode mode):
      XFile(xFile, xFileName, mode == MODE_WRITE) {}

    XFile(const char* xFileName, FileMode mode):
      XFile(xFileName, mode == MODE_WRITE) {}
*/
    void baseInit();

    int makeHeader(FileFormatVersion* version,
               uint8_t  dform,
               uint8_t  dtype,
               uint32_t shotnum,
               uint32_t shottime_sec,
               uint32_t shottime_usec,
               char* addon,
               char* comment);

    // ------------
    int getHeader(FileFormatVersion** version,
                  XFileHeader** header,
                  char** addon,
                  char** comment);
    // ------------

    // ------------
    int32_t      readSamples(void* buffer,
                              TimeInterval interval,        
                              uint32_t decimation = 1);

    int32_t      readSamplesFromTime(void* buffer,
                                      float time,
                                      uint32_t samples,
                                      uint32_t decimation = 1
                                      );
    int32_t      readSamplesFromNumber(void* buffer,
                                        uint32_t startSampleNumber,
                                        uint32_t samples,
                                        uint32_t decimation = 1);
    // ------------
    // Basic reserveData
    int   reserveData(float freq,  uint32_t samples, double beginTimeInSeconds = 0);
    int   reserveData(TimeInterval interval);
    // Basic getDataPointer
    void*          getDataPointer(TimeInterval interval);
    void*          getDataPointer(float timeInSeconds);
    void* getDataPointerForSample(uint32_t offsetInSamples);
    void* getDataPointerByCoord(uint32_t offsetInSamples, ...);
    //void*          getDataPointerForSample(uint32_t offsetInSamples);

    // DFORM0
    int   reserveData(int cnum, float freq, uint32_t samples, double beginTimeInSeconds = 0);
    int   reserveData(int cnum, TimeInterval interval);
    //void* getDataPointer(uint32_t offsetInSamples, uint16_t channel);
    // DFORM3
    int   reserveData(float freq,  uint32_t samples, uint8_t dim, ...);
    int   reserveData(float freq,  uint32_t samples, double beginTimeInSeconds,uint8_t dim, ...);
    int   reserveData(TimeInterval interval,uint8_t dim, ...);


    int samplesWritten(uint32_t samples);
    int samplesWritten(TimeInterval interval);

    uint32_t       getSamplesLeft(void* dataPointer);

    uint32_t       getSamples();
    int            getDataSize();
    long           getFileSize();
    int            getSampleSize();
    float          getDuration();
    double         getDelta();
    uint8_t        getDform() {return head_.dform;}
    uint8_t        getDtype()  {return head_.dtype;}

    uint32_t       channels() { return cnum_; }
    uint8_t        dim()      {return dim_;}
    uint32_t*      arrayDimensions() {return arrayDimensions_;}

    int            setData(void* data);
    void           setComment(char* comment);
    void           setAddon(char* addon);

    bool           isAnXFile() {return !strncmp(XFILE_SIGNATURE, head_.sign, strlen(XFILE_SIGNATURE));}

    virtual void*     getSampleExternal(int channel, uint32_t sample);
    virtual uint32_t  getSamplesExternal(int channel, uint32_t sample);

    virtual void   percentIndication(const char* /*fileName*/, float /*percentage*/) {}
	const char* getFileName() {return fileName_;}
	
    vector <TimeInterval>  getInterval() {return interval_;}
    double       getBeginTimeInSeconds() 
    {
      if(interval_.size() > 0)
        return (double)interval_[0].begin * (NANOSECONDS_IN_LMS_TICK / NANOSECONDS_IN_SECOND);
      else
        return 0.0;
    }

    int   save();
    int   loadHeader();
    int   loadData();

    int open();
    int close();

    virtual ~XFile();

    bool toClose;

  protected:

    uint64_t   deltaMultiplier_;

    FileFormatVersion* version_;
    bool        isExternalGetSamplesEnabled_;

    FILE*       file_;
    char*       fileName_;

    XFileHeader head_;
    uint16_t    addonlen_;
    char*       addon_;
    uint16_t    commentlen_;
    char*       comment_;

    void*       data_;

    uint32_t    cnum_;            ///< ���������� �������� ��� DFORM0
    uint8_t     dim_;             ///< ���������� ��������� ������� (dim_-������ ������)
    uint32_t*   arrayDimensions_; ///< ������, ���������� dim_ ���������, � ������ �� �������
                                  ///< ������ ������ ������� �� ��������������� ����������.

    vector <TimeInterval> interval_;
    vector <TimeInterval> intervalFilled_;
    void*       currentDataPtr_;
    bool        isWriteEnabled_;

    long        dataPosition_;
};

#endif
