//---------------------------------------------------------------------------
#pragma hdrstop

#include "UtilUnit.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

int HexToInt(AnsiString str)
{
	int ris = 0;
	for(int i = 1; i <= str.Length(); i++)
        {
        	int val;
        	if ( str[i] >= '0' && str[i] <= '9' )
                	val = str[i]-'0';
                else if ( str[i] >= 'a' && str[i] <= 'f' )
                	val = str[i]-'a' + 10;
                else if ( str[i] >= 'A' && str[i] <= 'F' )
                	val = str[i]-'A' + 10;
                else
                	return -1;
                ris = (ris*16) + val;
        }
        return ris;
}
//---------------------------------------------------------------------------
_di_IXMLNode GetNode(_di_IXMLNode n, AnsiString type)
{
	_di_IXMLNode ret = n->ChildNodes->FindNode(type);
        if ( ! ret )
        	ret = n->AddChild(type);
        return ret;
}
//---------------------------------------------------------------------------

