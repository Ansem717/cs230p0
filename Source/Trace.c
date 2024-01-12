//------------------------------------------------------------------------------
//
// File Name:	Trace.c
// Author(s):	Doug Schilling (dschilling)
//				Andy Malik (andy.malik)
// Project:		Project 0
// Course:		CS230S24
//
// Copyright © 2024 DigiPen (USA) Corporation.
//
//------------------------------------------------------------------------------

#include "stdafx.h"
#include <stdarg.h>

#include "Trace.h"

//------------------------------------------------------------------------------
// Private Constants:
//------------------------------------------------------------------------------

static const char* traceFileName = "Trace.log";

//------------------------------------------------------------------------------
// Private Structures:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Variables:
//------------------------------------------------------------------------------

static FILE* TraceFile;

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

// Initialize the Tracing/Logging module.
// - Open "trace.log" for writing in text mode.
// - Perform error handling in the event that the file failed to open.
void TraceInit()
{
	errno_t e = fopen_s(&TraceFile, traceFileName, "wt");
	printf(e ? "ERROR - Trace.log did not open.\n" : "SUCCESS - Trace.log opened.\n");
}

// Output a message to the Tracing/Logging file.
// - Print the given message to the file if it was opened successfully.
// - Every message must be printed on its own line.
// - There must be no blank lines between messages.
void TraceMessage(const char * formatString, ...)
{
	UNREFERENCED_PARAMETER(formatString);

	if (TraceFile != NULL) {
		va_list argptr;
		va_start(argptr, formatString);
		vfprintf_s(TraceFile, formatString, argptr);
		fprintf_s(TraceFile, "\n");
		va_end(argptr);
	}
}

// Shutdown the Tracing/Logging module.
// - Close the file if-and-only-if the file was opened successfully
void TraceShutdown()
{
	if (TraceFile != NULL) {
		fclose(TraceFile);
	}
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------

