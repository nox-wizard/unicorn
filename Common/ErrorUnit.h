//---------------------------------------------------------------------------

#ifndef ErrorUnitH
#define ErrorUnitH

#include <fstream>
#include <system.hpp>
#include <forms.hpp>

namespace Errors
{
        enum ehFlags { ehFatal, ehNonFatal, ehWarning, ehInfo };
        int ThrowError(
                AnsiString errmsg,
                ehFlags flags,
                int emflags,
                HWND handle = 0
                );

        void AssignHandle(HWND handle);
        void LogToFile(AnsiString filename);
}

//---------------------------------------------------------------------------
#endif
