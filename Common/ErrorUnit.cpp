//---------------------------------------------------------------------------
#include "ErrorUnit.h"
#include "stringhe.hpp"
#pragma hdrstop
#pragma package(smart_init)
//---------------------------------------------------------------------------

namespace Errors
{
        bool tolog = false;
        HWND Handle;

        int ThrowError(AnsiString errmsg, ehFlags flags, int emflags, HWND handle)
        {
        	if ( ! handle )
                	handle = Handle;
        	AnsiString caption;
	        int mbris;
        	switch(flags)
                {
                	case ehFatal:
                	        mbris = MessageBox(
                                	handle,
                                        errmsg.c_str(),
                                        Stringhe_eu_FatalError.c_str(),
                                        emflags | MB_ICONSTOP
                                        );
                                return mbris;
                        case ehNonFatal:
                        	mbris = MessageBox(
                                	handle,
                                        errmsg.c_str(),
                                        Stringhe_eu_Error.c_str(),
                                        emflags | MB_ICONEXCLAMATION
                                        );
                                return mbris;
                        case ehWarning:
                	        mbris = MessageBox(
                                	handle,
                                        errmsg.c_str(),
                                        Stringhe_eu_Warning.c_str(),
                                        emflags | MB_ICONEXCLAMATION
                                        );
                                return mbris;
                        case ehInfo:
                        	mbris = MessageBox(
                                	handle,
                                        errmsg.c_str(),
                                        Stringhe_eu_Info.c_str(),
                                        emflags | MB_ICONINFORMATION
                                        );
                                return mbris;
                        default:
                        	return -1;
                }
        }

        void AssignHandle(HWND handle)
        {
                Handle = handle;
        }

        void LogToFile(AnsiString filename)
        {
                //TODO write it
        }
}

