//---------------------------------------------------------------------------
#pragma hdrstop

#include "LoadFunctions.h"
#include "MainUnit.h"
#include "ConnectUnit.h"
#include <vector>
#include "stringhe.hpp"
//---------------------------------------------------------------------------

#pragma package(smart_init)
void LoadLocations()
{
	MainForm->LocCategory->Items->Clear();
        MainForm->LocPlaces->Clear();

	if ( ValidateCategories(SplashForm->Locations->DocumentElement->ChildNodes, true, SplashForm->Locations) )
        {
        	SplashForm->Locations->SaveToFile();
        	SplashForm->Locations->LoadFromFile();
        }
        
        for(int i = 0; i < SplashForm->Locations->DocumentElement->ChildNodes->Count; i++)
        {
        	#define tnode1 SplashForm->Locations->DocumentElement->ChildNodes->Nodes[i]
                #define tnode2 tnode1->ChildNodes->Nodes[j]
		TTreeNode *t = MainForm->LocCategory->Items->Add(
                	NULL,
                        tnode1->Attributes["name"]
                        );
                for(int j = 0; j < tnode1->ChildNodes->Count; j++)
                        MainForm->LocCategory->Items->AddChild(
                        	t,
                                tnode2->Attributes["name"]
                        	);
                #undef tnode1
                #undef tnode2
        }
}
//---------------------------------------------------------------------------

void LoadItems()
{
	MainForm->ItmCategories->Items->Clear();
        MainForm->ItmList->Clear();

	if ( ValidateCategories(SplashForm->Items->DocumentElement->ChildNodes, true, SplashForm->Items) )
        {
        	SplashForm->Items->SaveToFile();
        	SplashForm->Items->LoadFromFile();
        }
        
        for(int i = 0; i < SplashForm->Items->DocumentElement->ChildNodes->Count; i++)
        {
        	#define tnode1 SplashForm->Items->DocumentElement->ChildNodes->Nodes[i]
                #define tnode2 tnode1->ChildNodes->Nodes[j]
		TTreeNode *t = MainForm->ItmCategories->Items->Add(
                	NULL,
                        tnode1->Attributes["name"]
                        );
                for(int j = 0; j < tnode1->ChildNodes->Count; j++)
                        MainForm->ItmCategories->Items->AddChild(
                        	t,
                                tnode2->Attributes["name"]
                        	);
                #undef tnode1
                #undef tnode2
        }
}
//---------------------------------------------------------------------------
void LoadCharacters()
{
	MainForm->ChrCategories->Items->Clear();
        MainForm->ChrList->Clear();

	if ( ValidateCategories(SplashForm->Characters->DocumentElement->ChildNodes, true, SplashForm->Characters) )
        {
        	SplashForm->Characters->SaveToFile();
        	SplashForm->Characters->LoadFromFile();
        }
        
        for(int i = 0; i < SplashForm->Characters->DocumentElement->ChildNodes->Count; i++)
        {
        	#define tnode1 SplashForm->Characters->DocumentElement->ChildNodes->Nodes[i]
                #define tnode2 tnode1->ChildNodes->Nodes[j]
		TTreeNode *t = MainForm->ChrCategories->Items->Add(
                	NULL,
                        tnode1->Attributes["name"]
                        );
                for(int j = 0; j < tnode1->ChildNodes->Count; j++)
                        MainForm->ChrCategories->Items->AddChild(
                        	t,
                                tnode2->Attributes["name"]
                        	);
                #undef tnode1
                #undef tnode2
        }
}
//---------------------------------------------------------------------------
void LoadSettings()
{
        _di_IXMLNode tnode;
        // caricamento delle impostazioni relative ai comandi
        tnode = GetSetupNode("commands");
        MainForm->CmdPrefix->Text = Stringize(tnode->Attributes["prefix"]);
        MainForm->NewLine->Checked = Boolize(tnode->Attributes["newline"]);

        /*
        MainForm->HotKeys->Checked = AnsiString(tnode->Attributes["hotkeys"]) == AnsiString("y");

        if (MainForm->HotKeys->Checked)
        {
		typedef LRESULT (CALLBACK* KEYBOARDPROC)(int nCode,WPARAM wParam,LPARAM lParam);

		KEYBOARDPROC ProcWndowKey = (KEYBOARDPROC)GetProcAddress(Application->Handle,"HotKeyGet");
		if (ProcWndowKey)
			SetWindowsHookEx(WH_KEYBOARD, (HOOKPROC)ProcWndowKey, Application->Handle, NULL);
        }
*/

        // caricamento delle impostazioni relative alla visualizzazione
        tnode = GetSetupNode("visualization");
        MainForm->AoT->Checked = Boolize(tnode->Attributes["aot"]);
        MainForm->ExitOnClose->Checked = Boolize(tnode->Attributes["exitonclose"]);

        // caricamento delle impostazioni varie
        tnode = GetSetupNode("misc");
        MainForm->DefaultClient->Text = Stringize(tnode->Attributes["defaultclient"]);
        MainForm->NXWPath->Text = Stringize(tnode->Attributes["nxwpath"]);
}
//---------------------------------------------------------------------------
void LoadClients()
{
	MainForm->ClientList->Clear();
        #define tlist SplashForm->Launcher->DocumentElement->ChildNodes

        for(int i = 0; i < tlist->Count; i++)
        	MainForm->ClientList->AddItem(Stringize(tlist->Nodes[i]->Attributes["name"]), MainForm->ClientList);

        #undef tlist
}
//---------------------------------------------------------------------------
void LoadRegistry()
{
        TRegistry *Reg = new TRegistry(KEY_READ);
	try
        {
        	Reg->RootKey = HKEY_LOCAL_MACHINE;
                Reg->OpenKey("SOFTWARE\\Origin Worlds Online\\Ultima Online\\1.0", false);
                MainForm->uopath = ExtractFileDir(Reg->ReadString("ExePath"));
        }
        catch(...)
        {
        	Errors::ThrowError(
                	Stringhe_err_uodir_notfound,
                        Errors::ehFatal,
                        MB_OK
                	);
        }
        delete Reg;
}
//---------------------------------------------------------------------------
void LoadDynCmds()
{
	for(int i = 0; i < MainForm->HowManyDyns; i++)
        	delete MainForm->DynButtons[i];

        MainForm->HowManyDyns = 0;

	#define Comandi  SplashForm->DynCmds->DocumentElement->ChildNodes
        #define	CurrNode Comandi->Nodes[i]
        for (int i = 0; i < Comandi->Count && i < 48; i++ )
        {
        	MainForm->DynButtons[i] = new TButton(MainForm->CustomCmdsTab);
                MainForm->DynButtons[i]->Caption = CurrNode->Attributes["title"];
                MainForm->DynButtons[i]->Tag = i;
                MainForm->HowManyDyns++;

                MainForm->DynButtons[i]->Left = 120 + 80*(i % 8);
                MainForm->DynButtons[i]->Top  =   0 + 32*(i / 8);

                MainForm->DynButtons[i]->Visible = true;
                MainForm->DynButtons[i]->OnClick = MainForm->DynButtonClick;
                MainForm->DynButtons[i]->OnMouseDown = MainForm->DynButtonMouseDown;
                MainForm->DynButtons[i]->Width = 75;
                MainForm->DynButtons[i]->Height = 25;
                MainForm->DynButtons[i]->Parent = MainForm->CustomCmdsTab;
        }
        #undef Comandi
        #undef CurrNode
}
//---------------------------------------------------------------------------
bool ValidateCategories(_di_IXMLNodeList list, bool sub, TXMLDocument *doc)
{
	std::vector<int> dacanc;
        std::vector<_di_IXMLNode> dacanc_nodi;
	if ( list->Count == 1 )
        	return false;
                
	bool modified = false;
	#define NODENAME(x) list->Nodes[x]->Attributes["name"]
	for(int i = 0; i < list->Count; i++)
        {
        	bool pass = false;
        	for(std::vector<int>::iterator it = dacanc.begin(); it != dacanc.end(); it++)
                	if ( *it == i )
                        {
                        	pass = true; break;
                        }

                if ( pass ) continue;
                
                if ( list->Nodes[i]->ChildNodes->Count == 0 )
                {
		        dacanc.push_back(i);
	                dacanc_nodi.push_back(list->Nodes[i]);
                }

		OleVariant str1, str2;
        	for(int j = i+1; j < list->Count; j++)
                {
                	str1 = NODENAME(i);
                        if ( str1.Type() == varNull )
                        	continue;
                	try
			{
                	        str2 = NODENAME(j);
                                if ( str2.Type() == varNull )
                                	continue;
                		if ( AnsiString(str1) == AnsiString(str2) )
	                        {
        	                	modified = true;
                	        	JoinNodes(list->Nodes[i], list->Nodes[j]);
                        	        dacanc.push_back(j);
                                        dacanc_nodi.push_back(list->Nodes[j]);
	                        }
                        }
                        catch( ... )
                        {
                        	// TODO messagebox
                        }
                }
                if ( sub )
	                if ( ValidateCategories(list->Nodes[i]->ChildNodes, false, doc) )
                        	modified = true;
        }

	for(std::vector<_di_IXMLNode>::iterator it = dacanc_nodi.begin(); it != dacanc_nodi.end(); it++)
        	list->Remove(*it);
        
        #undef NODENAME
        return modified;
}
//---------------------------------------------------------------------------

void JoinNodes(_di_IXMLNode dest, _di_IXMLNode sorg)
{
	#define list1 dest->ChildNodes
        #define list2 sorg->ChildNodes
	for(int i = 0; i < list2->Count; i++)
                list1->Add(list2->Nodes[i]->CloneNode(true));
        #undef list1
        #undef list2
}
//---------------------------------------------------------------------------

