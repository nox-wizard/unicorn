//---------------------------------------------------------------------------

#ifndef LoadFunctionsH
#define LoadFunctionsH

#include <oxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
#include <msxmldom.hpp>

#include "UtilUnit.h"
#include "SplashUnit.h"

void LoadLocations();
void LoadItems();
void LoadCharacters();
void LoadSettings();
void LoadClients();
void LoadRegistry();
void LoadDynCmds();
void LoadRCServers();

inline _di_IXMLNode GetSetupNode(AnsiString &name)
{
        return GetNode(SplashForm->Settings->DocumentElement, name);
}

bool ValidateCategories(_di_IXMLNodeList list, bool sub, TXMLDocument *doc);
void JoinNodes(_di_IXMLNode dest, _di_IXMLNode sorg);
//---------------------------------------------------------------------------
#endif
