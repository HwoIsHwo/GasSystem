/***************************************************************************
****																	****
****           MEX (DLL, mexw32 or mexw64) file libxfile                ****
****																	****
***************************************************************************/
#include "mexxfile.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
    static FileFormatVersion* version;
    static XFileHeader* header;
    static char* addon;
    static char* comment;
    
    int fn_buflen;
	char *function_name;	// pointer to funtion name string
	/*****************************************************************************/
	// Checking number of arguments
    if (nrhs < 1)
		mexErrMsgTxt("X-file I/O library mex-function has at least one argument - function name!");
	/*****************************************************************************/
	// Checking if first argument is not a string
    if (!mxIsChar(prhs[0]))
		mexErrMsgTxt("X-file I/O library mex-function's first argument must be string - function name!");
	/*****************************************************************************/
	// Getting function name
	fn_buflen = (int)mxGetN(prhs[0])*sizeof(mxChar)+1;
	function_name = (char *) mxMalloc(fn_buflen);
	mxGetString(prhs[0], function_name, fn_buflen); //Passing function name to the pointer function_name
	/*************************************************************************************/
	if(_strcmpi(function_name, "fopen")==0)
	{	
		// Checking inputs and outputs
		if(nrhs != 3)
			mexErrMsgTxt("Function FOPEN has 2 arguments!");
		if(nlhs > 0) 
			mexErrMsgTxt("Function FOPEN doesn't return any values!");
		for(int i = 1; i < nrhs; i++)
			if (!mxIsChar(prhs[i]))
				mexErrMsgTxt("All FOPEN arguments must be character vectors or string scalars!");
		/*****************************************************************************/
        // Checking if SEPARATRIX lib already initialized
		if(xf_initialized)
        {
            xf->close();
            delete xf;
            xf_initialized = false;
        }
        // Creating new X-file session
        int xf_name_len;
        char *xf_name;
        xf_name_len = (int)mxGetN(prhs[1])*sizeof(mxChar)+1;
        xf_name = (char *) mxMalloc(xf_name_len);
        mxGetString(prhs[1], xf_name, xf_name_len); //Passing X-file name to the pointer xf_name
        int access_type_len;
        char *access_type;
        access_type_len = (int)mxGetN(prhs[2])*sizeof(mxChar)+1;
        access_type = (char *) mxMalloc(access_type_len);
        mxGetString(prhs[2], access_type, access_type_len); //Passing X-file access type specificator to the pointer access_type
        ////mexPrintf("fopen(%s, '%s')", xf_name, access_type);
        if(_strcmpi(access_type, "r") == 0)
        {
            xf = new XFile(xf_name, MODE_READ);
            xf->open();
            xf->loadHeader();
            if(!xf->isAnXFile())// Checking if file is X-file
            	mexErrMsgTxt("File is not X-file.");
            xf->getHeader(&version, &header, &addon, &comment);
        }
        else if (_strcmpi(access_type, "w") == 0)
        {
            xf = new XFile(xf_name, MODE_WRITE);
            //xf->open();
        }
        else				
            mexErrMsgTxt("Uknown X-file access type!");
          
    	xf_initialized = true;
		mexAtExit(xfileAtExit);
	}
    else if (_strcmpi(function_name, "get") == 0)
	{
        // Checking if X-file I/O active session exists
		if (!xf_initialized)
			mexErrMsgTxt("An active X-file I/O session doesn't exist!");
		// Checking number of input arguments
		if (nrhs != 2)
			mexErrMsgTxt("Function GET requares single argument!");
		/*****************************************************************************/
		// Checking inputs
		if (!mxIsChar(prhs[1]))
			mexErrMsgTxt("Function GET: argument must be a string!");
		/*****************************************************************************/
        int arg_len;
        char *arg;
        arg_len = (int)mxGetN(prhs[1])*sizeof(mxChar)+1;
        arg = (char *) mxMalloc(arg_len);
        mxGetString(prhs[1], arg, arg_len); //Passing GET function's argument name to the pointer arg
        if (_strcmpi(arg, "header") == 0)
        {
            // Checking outputs
            if (nlhs > 1)
                mexErrMsgTxt("Function GET with HEADER option: too many output arguments");
            /*****************************************************************************/
            const char *header_field_names[] = {"sign", "headlen", "datalen", "dform", "dtype", "shotnum", "shottime_sec", "shottime_usec", "addon", "comment"};
            int signf_num, headlenf_num, datalenf_num, dformf_num, dtypef_num, shotnumf_num, shottime_secf_num, shottime_usecf_num, addonf_num, commentf_num;
            plhs[0] = mxCreateStructMatrix(1, 1, NUMBER_OF_HEADER_FIELDS, header_field_names);
            
            signf_num           = mxGetFieldNumber(plhs[0], "sign");
            headlenf_num        = mxGetFieldNumber(plhs[0], "headlen");
            datalenf_num        = mxGetFieldNumber(plhs[0], "datalen");
            dformf_num          = mxGetFieldNumber(plhs[0], "dform");
            dtypef_num          = mxGetFieldNumber(plhs[0], "dtype");
            shotnumf_num        = mxGetFieldNumber(plhs[0], "shotnum");
            shottime_secf_num   = mxGetFieldNumber(plhs[0], "shottime_sec");
            shottime_usecf_num  = mxGetFieldNumber(plhs[0], "shottime_usec");
            addonf_num          = mxGetFieldNumber(plhs[0], "addon");
            commentf_num        = mxGetFieldNumber(plhs[0], "comment");
                    
            mxSetFieldByNumber(plhs[0], 0, signf_num,           mxCreateString(header->sign));
            mxSetFieldByNumber(plhs[0], 0, headlenf_num,        mxCreateDoubleScalar((double)header->headlen));
            mxSetFieldByNumber(plhs[0], 0, datalenf_num,        mxCreateDoubleScalar((double)header->datalen));
            mxSetFieldByNumber(plhs[0], 0, dformf_num,          mxCreateDoubleScalar((double)header->dform));
            mxSetFieldByNumber(plhs[0], 0, dtypef_num,          mxCreateDoubleScalar((double)header->dtype));
            mxSetFieldByNumber(plhs[0], 0, shotnumf_num,        mxCreateDoubleScalar((double)header->shotnum));
            mxSetFieldByNumber(plhs[0], 0, shottime_secf_num,   mxCreateDoubleScalar((double)header->shottime_sec));
            mxSetFieldByNumber(plhs[0], 0, shottime_usecf_num,  mxCreateDoubleScalar((double)header->shottime_usec));
            mxSetFieldByNumber(plhs[0], 0, addonf_num,          mxCreateString(addon));
            mxSetFieldByNumber(plhs[0], 0, commentf_num,        mxCreateString(comment));
        }
        else if (_strcmpi(arg, "dataheader") == 0)
        {
            // Checking outputs
            if (nlhs > 1)
                mexErrMsgTxt("Function GET with DATAHEADER option: too many output arguments");
            /*****************************************************************************/
            if(xf->getDform() == VECTOR_BY_TIME)
            {
                const char *dataheader_field_names[] = {"chnum", "samplenum", "duration", "starttime", "delta"};
                int chnum_num, samplenum_num, duration_num, starttime_num, delta_num;
                plhs[0] = mxCreateStructMatrix(1, 1, NUMBER_OF_DATAHEADER_FIELDS, dataheader_field_names);

                chnum_num     = mxGetFieldNumber(plhs[0], "chnum");
                samplenum_num = mxGetFieldNumber(plhs[0], "samplenum");
                duration_num  = mxGetFieldNumber(plhs[0], "duration");
                starttime_num = mxGetFieldNumber(plhs[0], "starttime");
                delta_num     = mxGetFieldNumber(plhs[0], "delta");

                mxSetFieldByNumber(plhs[0], 0, chnum_num,     mxCreateDoubleScalar((double)xf->channels()));
                mxSetFieldByNumber(plhs[0], 0, samplenum_num, mxCreateDoubleScalar((double)xf->getSamples()));
                mxSetFieldByNumber(plhs[0], 0, duration_num,  mxCreateDoubleScalar((double)xf->getDuration()));
                mxSetFieldByNumber(plhs[0], 0, starttime_num, mxCreateDoubleScalar((double)xf->getBeginTimeInSeconds()));
                mxSetFieldByNumber(plhs[0], 0, delta_num,     mxCreateDoubleScalar((double)xf->getDelta()));
            }
            else
                mexErrMsgTxt("Function GET with DATAHEADER option: Data type is not supported or uknown");
        }
        else if (_strcmpi(arg, "data") == 0)
        {
            // Checking outputs
            if (nlhs > 2)
                mexErrMsgTxt("Function GET with HEADER option: too many output arguments");
            /*****************************************************************************/
            if(xf->getDform() == VECTOR_BY_TIME)
            {
                mwSize dims[2];
                dims[0] = (mwSize)xf->channels();
                dims[1] = (mwSize)xf->getSamples();
                if(xf->getDtype() == DTYPE_INT8){
                    plhs[0] = mxCreateNumericArray(2, dims, mxINT8_CLASS, mxREAL);
                    xf->readSamplesFromNumber((int8_t*)mxGetPr(plhs[0]), 0, xf->getSamples(), 0);
                }
                else if(xf->getDtype() == DTYPE_UINT8){
                    plhs[0] = mxCreateNumericArray(2, dims, mxUINT8_CLASS, mxREAL);
                    xf->readSamplesFromNumber((uint8_t*)mxGetPr(plhs[0]), 0, xf->getSamples(), 0);
                }
                else if(xf->getDtype() == DTYPE_INT16){
                    plhs[0] = mxCreateNumericArray(2, dims, mxINT16_CLASS, mxREAL);
                    xf->readSamplesFromNumber((int16_t*)mxGetPr(plhs[0]), 0, xf->getSamples(), 0);
                }
                else if(xf->getDtype() == DTYPE_UINT16){
                    plhs[0] = mxCreateNumericArray(2, dims, mxUINT16_CLASS, mxREAL);
                    xf->readSamplesFromNumber((uint16_t*)mxGetPr(plhs[0]), 0, xf->getSamples(), 0);
                }
                else if(xf->getDtype() == DTYPE_INT32){
                    plhs[0] = mxCreateNumericArray(2, dims, mxINT32_CLASS, mxREAL);
                    xf->readSamplesFromNumber((int32_t*)mxGetPr(plhs[0]), 0, xf->getSamples(), 0);
                }
                else if(xf->getDtype() == DTYPE_UINT32){
                    plhs[0] = mxCreateNumericArray(2, dims, mxUINT32_CLASS, mxREAL);
                    xf->readSamplesFromNumber((uint32_t*)mxGetPr(plhs[0]), 0, xf->getSamples(), 0);
                }
                else if(xf->getDtype() == DTYPE_FLOAT){
                    plhs[0] = mxCreateNumericArray(2, dims, mxSINGLE_CLASS, mxREAL);
                    xf->readSamplesFromNumber((float*)mxGetPr(plhs[0]), 0, xf->getSamples(), 0);
                }
                else if(xf->getDtype() == DTYPE_DOUBLE){
                    plhs[0] = mxCreateNumericArray(2, dims, mxDOUBLE_CLASS, mxREAL);
                    xf->readSamplesFromNumber((double*)mxGetPr(plhs[0]), 0, xf->getSamples(), 0);
                }
                else
                    mexErrMsgTxt("Bad X-file, uknown data type");
                if(nlhs > 1)
                {
                    mxArray* rhs[2];
                    rhs[0] = mxCreateDoubleScalar(0.0);
                    rhs[1] = mxCreateDoubleScalar((double)xf->getDuration());
                    rhs[2] = mxCreateDoubleScalar((double)xf->getSamples());
                    mexCallMATLAB(1, &plhs[1], 3, rhs, "linspace");
                    for(int i = 0; i < 3; i++)
                        mxDestroyArray(rhs[i]);
                }
            }
        }
        else
            mexErrMsgTxt("Function GET: uknown argument!");
	}
    else if(_strcmpi(function_name, "fclose") == 0)
    {
        // Checking if X-file I/O active session exists
		if (!xf_initialized)
			mexErrMsgTxt("An active X-file I/O session doesn't exist!");
		// Checking outputs
		if (nlhs > 0)
			mexErrMsgTxt("Function FCLOSE: too many output arguments");
		// Checking number of input arguments
		if (nrhs != 1)
			mexErrMsgTxt("Function FCLOSE: too many input arguments!");
        /*****************************************************************************/
        xf->close();
        delete xf;
        xf_initialized = false;
    }
    else if(_strcmpi(function_name, "isactive") == 0)
    {
        // Checking if X-file I/O active session exists
        if (nlhs > 1)
			mexErrMsgTxt("Function FCLOSE: too many output arguments");
        // Checking number of input arguments
        if (nrhs != 1)
			mexErrMsgTxt("Function FCLOSE: too many input arguments!");
        /*****************************************************************************/
        plhs[0] = mxCreateLogicalScalar(xf_initialized);
    }
	else
	{
		mexPrintf("Function %s doesn't exist.", function_name);
		mexErrMsgTxt("Uknown function name!");
	}
}

