//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include "SplashUnit.h"
#include "ConnectUnit.h"
#include "LoadFunctions.h"

#include <cstdio>
#include <fstream>
#include "XSSParseUnit.h"
#include "ErrorUnit.h"
#include "UtilUnit.h"
#include "HuesUnit.h"
#include "stringhe.hpp"
#include "LocationEditUnit.h"
#include "ObjectEditUnit.h"
#include "ParamsUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UOMAPLib_OCX"
#pragma link "UOARTLib_OCX"
#pragma resource "*.dfm"

TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
        Errors::AssignHandle(Application->Handle);
	HowManyDyns = 0;
}
//---------------------------------------------------------------------------
bool TMainForm::FindUO()
{
	UOHandle = FindWindow( "Ultima Online", NULL );
	if ( !UOHandle )
		UOHandle = FindWindow( "Ultima Online Third Dawn", NULL );
        return UOHandle;
}
//---------------------------------------------------------------------------
void TMainForm::SendCommand(AnsiString cmd)
{
	if ( FindUO() )
        {
        	if ( NewLine->Enabled )
	               	SendMessage(UOHandle, WM_CHAR, '\n', 0);

               	SendMessage(UOHandle, WM_CHAR, CmdPrefix->Text[1], 0);
                for(int i = 1; i <= cmd.Length(); i++)
                	SendMessage(UOHandle, WM_CHAR, cmd[i], 0);

               	SendMessage(UOHandle, WM_CHAR, '\n', 0);
        }
        else
        	Errors::ThrowError(
                	Stringhe_mu_UONotFound,
                        Errors::ehNonFatal,
                        MB_OK
                        );

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	if ( ExitOnClose->Checked )
        {
        	SplashForm->Icona->Hide = true;
        	CanClose = true;
        }
        else
        {
        	Hide();
                CanClose = false;
        }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DynButtonClick(TObject *Sender)
{
	#define tnode SplashForm->DynCmds->DocumentElement->ChildNodes->Nodes[t->Tag]
	TButton *t = (TButton*)Sender;
        AnsiString numparams = tnode->Attributes["params"];
        int nparams = numparams.ToIntDef(0);
        if ( !nparams )
	        SendCommand(tnode->Attributes["value"]);
        else
        {
        	ParamsForm->Caption = tnode->Attributes["title"];
                ParamsForm->Params->Strings->Clear();
                ParamsForm->Params->KeyOptions.Clear();
                ParamsForm->Params->FixedCols = 1;
                for(int i = 0; i < tnode->ChildNodes->Count; i++)
                	ParamsForm->Params->InsertRow(tnode->ChildNodes->Nodes[i]->Text, "", false);
                if ( ParamsForm->ShowModal() == mrOk )
                {
                	for(int i = 0; i < ParamsForm->Params->RowCount; i++)
                        {
	                	AnsiString command = tnode->Attributes["value"];
	                        command += " " + ParamsForm->Params->Strings->Values[
                                	ParamsForm->Params->Strings->Names[i]
                                        ];
                                SendCommand(command);
                        }
                }
        }
        #undef tnode
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DynButtonMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
	if ( Button == mbRight )
        {
                SplashForm->DynCmds->DocumentElement->ChildNodes->Delete(((TButton*)Sender)->Tag);
                LoadDynCmds();
        }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ItmCategoriesChange(TObject *Sender,
      TTreeNode *Node)
{
	if ( Node->Level )
        {
        	#define lista SplashForm->Items->DocumentElement->ChildNodes->Nodes[Node->Parent->Index]->ChildNodes->Nodes[Node->Index]->ChildNodes
                ItmList->Tag = Node->Parent->Index + ( Node->Index << 8 );
                ItmList->Clear();
                for(int i = 0; i < lista->Count; i++)
                        ItmList->AddItem(lista->Nodes[i]->Attributes["name"], LocPlaces);
                #undef lista
        }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ChrCategoriesChange(TObject *Sender,
      TTreeNode *Node)
{
	if ( Node->Level )
        {
                #define lista SplashForm->Characters->DocumentElement->ChildNodes->\
                	Nodes[Node->Parent->Index]->ChildNodes->\
                        Nodes[Node->Index]->ChildNodes
                ChrList->Tag = Node->Parent->Index + ( Node->Index << 8 );
                ChrList->Clear();
                for(int i = 0; i < lista->Count; i++)
                        ChrList->AddItem(lista->Nodes[i]->Attributes["name"], ChrList);
                #undef lista
        }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ItmListClick(TObject *Sender)
{
	if ( ItmList->ItemIndex != -1 )
        {
                #define tnode SplashForm->Items->DocumentElement->ChildNodes->Nodes[ItmList->Tag&0xFF]\
                	->ChildNodes->Nodes[ItmList->Tag >> 8]->ChildNodes->Nodes[ItmList->ItemIndex]
                itemid->Text = tnode->Attributes["addid"];
                if ( ShowArt->Checked )
                {
                	AnsiString t = tnode->Attributes["id"];
	                ItmArt->ArtIndex = HexToInt(t);
                        t = tnode->Attributes["color"];
        	        ItmArt->ArtColor = HexToInt(t);
                }
                #undef tnode
        }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ChrListClick(TObject *Sender)
{
	if ( ChrList->ItemIndex != -1 )
        {
                #define tnode SplashForm->Characters->DocumentElement->ChildNodes->Nodes[ChrList->Tag&0xFF]\
                	->ChildNodes->Nodes[ChrList->Tag >> 8]->ChildNodes->Nodes[ChrList->ItemIndex]
                charid->Text = tnode->Attributes["addid"];
                if ( ShowArt->Checked )
                {
                	AnsiString t = tnode->Attributes["id"];
	                ChrArt->ArtIndex = HexToInt(t);
                        t = tnode->Attributes["color"];
        	        ChrArt->ArtColor = HexToInt(t);
                }
                #undef tnode
        }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::NudgeControlClick(TObject *Sender, TUDBtnType Button)
{
	switch(Button)
        {
        	case btNext:
                	SendCommand(Caption.sprintf("incz %d", NudgeDelta->Text.ToInt())); 
                	break;
                case btPrev:
                	SendCommand(Caption.sprintf("decz %d", NudgeDelta->Text.ToInt())); 
                	break;
        }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ColorPaletteBtnClick(TObject *Sender)
{
	if ( PaletteForm->ShowModal() == mrOk )
        {
        	if ( PaletteForm->ColorCode->Caption.IsEmpty() )
                {
                	Errors::ThrowError(
                        	Stringhe_mu_ColorNotSelected,
                                Errors::ehNonFatal,
                                MB_OK
                                );
                        return;
                }
                int color = HexToInt(PaletteForm->ColorCode->Caption);
                if ( Use0x->Checked )
                	SendCommand(Caption.sprintf("dye 0x%x 0x%x", color >> 8, color & 0xFF));
                else
                	SendCommand(Caption.sprintf("dye %x %x", color >> 8, color & 0xFF));
        }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormShow(TObject *Sender)
{
	LauncherTab->Show();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Elimina2Click(TObject *Sender)
{
	if ( ItmList->ItemIndex != -1 )
        {
		SplashForm->Items->DocumentElement->ChildNodes->
        		Nodes[ItmList->Tag&0xFF]->ChildNodes->Nodes[ItmList->Tag>>8]->
                	ChildNodes->Delete(ItmList->ItemIndex);
                SplashForm->Items->SaveToFile();
                SplashForm->Items->LoadFromFile();
                LoadItems();
        }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Elimina3Click(TObject *Sender)
{
	if ( ChrList->ItemIndex != -1 )
        {
		SplashForm->Characters->DocumentElement->ChildNodes->
        		Nodes[ChrList->Tag&0xFF]->ChildNodes->Nodes[ChrList->Tag>>8]->
                	ChildNodes->Delete(ChrList->ItemIndex);
                SplashForm->Characters->SaveToFile();
                SplashForm->Characters->LoadFromFile();
                LoadCharacters();
        }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MenuItem2Click(TObject *Sender)
{
	ObjectEditForm->Categories->Clear();
        ObjectEditForm->Subcategories->Clear();
        ObjectEditForm->Preview->ArtType = 0;
        #define tnode1 SplashForm->Items->DocumentElement->ChildNodes->Nodes[i]
        for(int i = 0; i < SplashForm->Items->DocumentElement->ChildNodes->Count; i++)
        	ObjectEditForm->Categories->Items->Add(tnode1->Attributes["name"]);
        #undef tnode1

        ObjectEditForm->Categories->ItemIndex = ItmList->Tag & 0xFF;

        if ( SplashForm->Items->DocumentElement->ChildNodes->Count )
        {
	        #define tnode1 SplashForm->Items->DocumentElement->ChildNodes->Nodes[ItmList->Tag&0xFF]
        	#define tnode2 tnode1->ChildNodes->Nodes[i]
	        for(int i = 0; i < tnode1->ChildNodes->Count; i++)
        		ObjectEditForm->Subcategories->Items->Add(tnode2->Attributes["name"]);
	        #undef tnode1
        	#undef tnode2
        }

        ObjectEditForm->Subcategories->ItemIndex = ItmList->Tag >> 8;

        ObjectEditForm->Name->Text = "";
        ObjectEditForm->Name->Text = "";
        ObjectEditForm->IngameID->Text = "";
        ObjectEditForm->Color->Text = "";
        ObjectEditForm->ArtID->Text = "";

        ObjectEditForm->Preview->ArtColor = 0;
        ObjectEditForm->Preview->ArtIndex = 0;

        if ( ObjectEditForm->ShowModal() == mrOk)
        {
                _di_IXMLNode tnode = SplashForm->Items->DocumentElement->AddChild("category");
                tnode->Attributes["name"] = ObjectEditForm->Categories->Text;
                tnode = tnode->AddChild("subsection");
                tnode->Attributes["name"] = ObjectEditForm->Subcategories->Text;
                tnode = tnode->AddChild("item");
	        tnode->Attributes["name"] = ObjectEditForm->Name->Text;
        	tnode->Attributes["addid"] = ObjectEditForm->IngameID->Text;
	        tnode->Attributes["color"] = ObjectEditForm->Color->Text;
        	tnode->Attributes["id"] = ObjectEditForm->ArtID->Text;
                SplashForm->Items->SaveToFile();
                SplashForm->Items->LoadFromFile();
		LoadItems();
        }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MenuItem4Click(TObject *Sender)
{
	ObjectEditForm->Categories->Clear();
        ObjectEditForm->Subcategories->Clear();
        ObjectEditForm->Preview->ArtType = 1;
        #define tnode1 SplashForm->Characters->DocumentElement->ChildNodes->Nodes[i]
        for(int i = 0; i < SplashForm->Characters->DocumentElement->ChildNodes->Count; i++)
        	ObjectEditForm->Categories->Items->Add(tnode1->Attributes["name"]);
        #undef tnode1

        ObjectEditForm->Categories->ItemIndex = ChrList->Tag & 0xFF;

        if ( SplashForm->Characters->DocumentElement->ChildNodes->Count )
        {
	        #define tnode1 SplashForm->Characters->DocumentElement->ChildNodes->Nodes[ChrList->Tag&0xFF]
        	#define tnode2 tnode1->ChildNodes->Nodes[i]
	        for(int i = 0; i < tnode1->ChildNodes->Count; i++)
        		ObjectEditForm->Subcategories->Items->Add(tnode2->Attributes["name"]);
	        #undef tnode1
        	#undef tnode2
        }

        ObjectEditForm->Subcategories->ItemIndex = ChrList->Tag >> 8;

        ObjectEditForm->Name->Text = "";
        ObjectEditForm->Name->Text = "";
        ObjectEditForm->IngameID->Text = "";
        ObjectEditForm->Color->Text = "";
        ObjectEditForm->ArtID->Text = "";

        ObjectEditForm->Preview->ArtColor = 0;
        ObjectEditForm->Preview->ArtIndex = 0;

        if ( ObjectEditForm->ShowModal() == mrOk)
        {
                _di_IXMLNode tnode = SplashForm->Characters->DocumentElement->AddChild("category");
                tnode->Attributes["name"] = ObjectEditForm->Categories->Text;
                tnode = tnode->AddChild("subsection");
                tnode->Attributes["name"] = ObjectEditForm->Subcategories->Text;
                tnode = tnode->AddChild("char");
	        tnode->Attributes["name"] = ObjectEditForm->Name->Text;
        	tnode->Attributes["addid"] = ObjectEditForm->IngameID->Text;
	        tnode->Attributes["color"] = ObjectEditForm->Color->Text;
        	tnode->Attributes["id"] = ObjectEditForm->ArtID->Text;
                SplashForm->Characters->SaveToFile();
                SplashForm->Characters->LoadFromFile();
		LoadCharacters();
        }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MenuItem1Click(TObject *Sender)
{
	if ( ItmList->ItemIndex == -1 )
        	MenuItem2Click(Sender);

	ObjectEditForm->Categories->Clear();
        ObjectEditForm->Subcategories->Clear();
        ObjectEditForm->Preview->ArtType = 0;
        #define tnode1 SplashForm->Items->DocumentElement->ChildNodes->Nodes[i]
        for(int i = 0; i < SplashForm->Items->DocumentElement->ChildNodes->Count; i++)
        	ObjectEditForm->Categories->Items->Add(tnode1->Attributes["name"]);
        #undef tnode1

        ObjectEditForm->Categories->ItemIndex = ItmList->Tag & 0xFF;

        if ( SplashForm->Items->DocumentElement->ChildNodes->Count )
        {
	        #define tnode1 SplashForm->Items->DocumentElement->ChildNodes->Nodes[ItmList->Tag&0xFF]
        	#define tnode2 tnode1->ChildNodes->Nodes[i]
	        for(int i = 0; i < tnode1->ChildNodes->Count; i++)
        		ObjectEditForm->Subcategories->Items->Add(tnode2->Attributes["name"]);
	        #undef tnode1
        	#undef tnode2
        }

        ObjectEditForm->Subcategories->ItemIndex = ItmList->Tag >> 8;

        #define tnode SplashForm->Items->DocumentElement->ChildNodes->\
        	Nodes[ItmList->Tag&0xFF]->ChildNodes->Nodes[ItmList->Tag>>8]->\
                ChildNodes->Nodes[ItmList->ItemIndex]
        ObjectEditForm->Name->Text = tnode->Attributes["name"];
        ObjectEditForm->Preview->ArtColor = HexToInt(tnode->Attributes["color"]);
        ObjectEditForm->Preview->ArtIndex = HexToInt(tnode->Attributes["id"]);
        ObjectEditForm->Name->Text = tnode->Attributes["name"];
        ObjectEditForm->IngameID->Text = tnode->Attributes["addid"];
        ObjectEditForm->Color->Text = tnode->Attributes["color"];
        ObjectEditForm->ArtID->Text = tnode->Attributes["id"];
        #undef tnode

        if ( ObjectEditForm->ShowModal() == mrOk)
        {
                _di_IXMLNode tnode = SplashForm->Items->DocumentElement->AddChild("category");
                tnode->Attributes["name"] = ObjectEditForm->Categories->Text;
                tnode = tnode->AddChild("subsection");
                tnode->Attributes["name"] = ObjectEditForm->Subcategories->Text;
                tnode = tnode->AddChild("item");
	        tnode->Attributes["name"] = ObjectEditForm->Name->Text;
        	tnode->Attributes["addid"] = ObjectEditForm->IngameID->Text;
	        tnode->Attributes["color"] = ObjectEditForm->Color->Text;
        	tnode->Attributes["id"] = ObjectEditForm->ArtID->Text;
                SplashForm->Items->SaveToFile();
                SplashForm->Items->LoadFromFile();
		LoadItems();
        }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MenuItem3Click(TObject *Sender)
{
	ObjectEditForm->Categories->Clear();
        ObjectEditForm->Subcategories->Clear();
        ObjectEditForm->Preview->ArtType = 1;
        #define tnode1 SplashForm->Characters->DocumentElement->ChildNodes->Nodes[i]
        for(int i = 0; i < SplashForm->Characters->DocumentElement->ChildNodes->Count; i++)
        	ObjectEditForm->Categories->Items->Add(tnode1->Attributes["name"]);
        #undef tnode1

        ObjectEditForm->Categories->ItemIndex = ChrList->Tag & 0xFF;

        if ( SplashForm->Characters->DocumentElement->ChildNodes->Count )
        {
	        #define tnode1 SplashForm->Characters->DocumentElement->ChildNodes->Nodes[ChrList->Tag&0xFF]
        	#define tnode2 tnode1->ChildNodes->Nodes[i]
	        for(int i = 0; i < tnode1->ChildNodes->Count; i++)
        		ObjectEditForm->Subcategories->Items->Add(tnode2->Attributes["name"]);
	        #undef tnode1
        	#undef tnode2
        }

        ObjectEditForm->Subcategories->ItemIndex = ChrList->Tag >> 8;

        #define tnode SplashForm->Characters->DocumentElement->ChildNodes->\
        	Nodes[ChrList->Tag&0xFF]->ChildNodes->Nodes[ChrList->Tag>>8]->\
                ChildNodes->Nodes[ChrList->ItemIndex]
        ObjectEditForm->Name->Text = tnode->Attributes["name"];
        ObjectEditForm->Preview->ArtColor = HexToInt(tnode->Attributes["color"]);
        ObjectEditForm->Preview->ArtIndex = HexToInt(tnode->Attributes["id"]);
        ObjectEditForm->Name->Text = tnode->Attributes["name"];
        ObjectEditForm->IngameID->Text = tnode->Attributes["addid"];
        ObjectEditForm->Color->Text = tnode->Attributes["color"];
        ObjectEditForm->ArtID->Text = tnode->Attributes["id"];
        #undef tnode

        if ( ObjectEditForm->ShowModal() == mrOk)
        {
                _di_IXMLNode tnode = SplashForm->Characters->DocumentElement->AddChild("category");
                tnode->Attributes["name"] = ObjectEditForm->Categories->Text;
                tnode = tnode->AddChild("subsection");
                tnode->Attributes["name"] = ObjectEditForm->Subcategories->Text;
                tnode = tnode->AddChild("char");
	        tnode->Attributes["name"] = ObjectEditForm->Name->Text;
        	tnode->Attributes["addid"] = ObjectEditForm->IngameID->Text;
	        tnode->Attributes["color"] = ObjectEditForm->Color->Text;
        	tnode->Attributes["id"] = ObjectEditForm->ArtID->Text;
                SplashForm->Characters->SaveToFile();
                SplashForm->Characters->LoadFromFile();
		LoadCharacters();
        }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AddDynCmdClick(TObject *Sender)
{
	if ( ! DynamicCmd->Text.IsEmpty() && ! CmdTitle->Text.IsEmpty() )
        {
		_di_IXMLNode cmd = SplashForm->DynCmds->DocumentElement->AddChild("command");
        	cmd->Attributes["title"] = CmdTitle->Text;
                cmd->Attributes["value"] = DynamicCmd->Text;
                SplashForm->DynCmds->SaveToFile();
                SplashForm->DynCmds->LoadFromFile();
                LoadDynCmds();
        }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AddParamsClick(TObject *Sender)
{
	if ( ! DynamicCmd->Text.IsEmpty() && ! CmdTitle->Text.IsEmpty() )
        {
                ParamsForm->Params->Strings->Clear();
                ParamsForm->Params->KeyOptions.Clear() << keyEdit << keyAdd << keyDelete << keyUnique;
                ParamsForm->Params->FixedCols = 0;
        	if ( ParamsForm->ShowModal() == mrOk )
                {
                	_di_IXMLNode cmd = SplashForm->DynCmds->DocumentElement->AddChild("command");
	        	cmd->Attributes["title"] = CmdTitle->Text;
        	        cmd->Attributes["value"] = DynamicCmd->Text;
                        int params = ParamsForm->Params->Strings->Count;
                        cmd->Attributes["params"] = params;

                        for(int i = 0; i < params; i++ )
                        	cmd->AddChild("param")->Text = ParamsForm->Params->Strings->Names[i];

                	SplashForm->DynCmds->SaveToFile();
	                SplashForm->DynCmds->LoadFromFile();
        	        LoadDynCmds();
                }
        }
}
//---------------------------------------------------------------------------
/*
__declspec(dllexport) LRESULT CALLBACK HotKeyGet
	(int nCode, WPARAM wParam,  LPARAM lParam)
{
	MainForm->Caption = "FUNZIONA";
	return 0;
}
*/
