#include <stdio.h>
#include <cstring>
#include <time.h>
#include "mex.h"
#include "matrix.h"

#include "WorkXFNew.h"

#ifdef __unix__
#define _strcmpi strcasecmp
#endif

#define NUMBER_OF_HEADER_FIELDS     (sizeof(header_field_names)/sizeof(*header_field_names))
#define NUMBER_OF_DATAHEADER_FIELDS (sizeof(dataheader_field_names)/sizeof(*dataheader_field_names))

bool xf_initialized = false;	// Is x-file I/O library initialized?

XFile* xf;

static void xfileAtExit(void)   // This is mex at exit routine
{
	if(xf_initialized) // Clearing memory by deleting active XFile object
	{
        xf->close();
        delete xf;
        xf_initialized = false;
	}
}
