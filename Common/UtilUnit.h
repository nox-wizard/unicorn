//---------------------------------------------------------------------------

#ifndef UtilUnitH
#define UtilUnitH
#include <System.hpp>
#include <oxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
#include <msxmldom.hpp>

/*!
\brief convert the hexadecimal number in the specified string to an int
\param str the string to convert
\return the value of the string parsed in hexadecimal base
*/
int HexToInt(AnsiString str);

/*!
\brief get the first node of the specified type, creating it if it doesn't exists
\param n parent node to search in
\param type type of the node
\return the interface to the node found
*/
_di_IXMLNode GetNode(_di_IXMLNode list, AnsiString type);

/*!
\brief Convert the matrix index (x, y) in a vector index
\param x row index
\param y column index
\param r the number of rows in the matrix
\param c the number of columns in the matrix
\return the equivalent vector index
*/
inline int m2v(int x, int y, int c)
{
	return x+(c*y);
}

/*!
\brief Convert the vector index in a matrix index (x,y)
\param v the index
\param c the number of columns in the matrix
\param x will be the row index
\param y will be the column index
*/
inline void v2m(int v, int c, int &x, int &y)
{
	y = v/c;
        x = v%c;
}

/*!
\brief Convert an OleVariant var in a bool var checking for nulls
\param v the OleVariant var
\return true of the var reppresent a true value, else false, false if the variant
is NULL
*/
inline bool Boolize(OleVariant &v)
{
        return ( v.IsNull() ? false : AnsiString(v) == AnsiString("y") );
}

/*!
\brief Convert an OleVariant var in an AnsiString var, checking for nulls
\param v the OleVariant var
\return the string rappresented by the var, or an empty string if the variant
is NULL
*/
inline AnsiString Stringize(OleVariant &v)
{
        return ( v.IsNull() ? AnsiString("") : AnsiString(v) );
}

/*!
\brief Convert an OleVariant var in an long var, checking for nulls
\param v the OleVariant var
\return the long rappresented by the var, or an empty string if the variant
is NULL
*/
inline long Longize(OleVariant &v)
{
        return ( v.IsNull() ? 0l : long(v) );
}

//---------------------------------------------------------------------------
#endif
