//---------------------------------------------------------------------------

#ifndef CRC32UnitH
#define CRC32UnitH
#include <windows.h>

// Read 4K of data at a time (used in the C++ streams, Win32 I/O, and assembly functions)
#define MAX_BUFFER_SIZE	4096
// Map a "view" size of 10MB (used in the filemap function)
#define MAX_VIEW_SIZE	10485760
//#define _ASSERTE(x) assert(x != NULL)

//---------------------------------------------------------------------------
namespace CRC32
{
	long StringCrc32(LPCTSTR szString, long &dwCrc32);
	long FileCrc32(LPCTSTR szFilename, long &dwCrc32);
};

#endif
 