//---------------------------------------------------------------------------
#include <fstream>
#include <vcl.h>
#pragma hdrstop

#include "SplashUnit.h"
#include "MainUnit.h"
#include "LoadFunctions.h"
#include "ErrorUnit.h"
#include "stringhe.hpp"
#include "HuesUnit.h"
#include "HuesParser.h"
#include "UtilUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "trayicon"
#pragma resource "*.dfm"
TSplashForm *SplashForm;
//---------------------------------------------------------------------------
__fastcall TSplashForm::TSplashForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSplashForm::LogoClick(TObject *Sender)
{
	Hide();
        Countdown->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TSplashForm::FormShow(TObject *Sender)
{
	static const short passo = 10;
        AnsiString apppath = ExtractFileDir(Application->ExeName);

        WTFDoing->Caption = Stringhe_sf_Settings;
        Barra->Position += passo;
        Settings->FileName = apppath + "\\settings.xml";
        Settings->Active = true;
        LoadSettings();

        WTFDoing->Caption = Stringhe_sf_Registry;
        Barra->Position += passo;
        LoadRegistry();

	WTFDoing->Caption = Stringhe_sf_Locations;
	Barra->Position += passo;
        Locations->FileName = apppath + "\\locations.xml";
        Locations->Active = true;
        LoadLocations();

        WTFDoing->Caption = Stringhe_sf_Items;
        Barra->Position += passo;
        Items->FileName = apppath + "\\items.xml";
        Items->Active = true;
        LoadItems();

        WTFDoing->Caption = Stringhe_sf_NPCs;
        Barra->Position += passo;
        Characters->FileName = apppath + "\\characters.xml";
        Characters->Active = true;
        LoadCharacters();

        WTFDoing->Caption = Stringhe_sf_Launcher;
        Barra->Position += passo;
        Launcher->FileName = apppath + "\\launcher.xml";
        Launcher->Active = true;
        LoadClients();

        WTFDoing->Caption = Stringhe_sf_DynCmds;
        Barra->Position += passo;
        DynCmds->FileName = apppath + "\\dyncmds.xml";
        DynCmds->Active = true;
        LoadDynCmds();

        WTFDoing->Caption = Stringhe_sf_Muls;
        Barra->Position += passo;
        GetSetupNode("cachecrc")->Attributes["hues"] =
                AnsiString(
                        Hues::LoadHues(Longize(GetSetupNode("cachecrc")->Attributes["hues"]),
                        MainForm->uopath)
                        );

        Countdown->Enabled = true;
        WTFDoing->Caption = Stringhe_sf_Complete;
}
//---------------------------------------------------------------------------


void __fastcall TSplashForm::IconaClick(TObject *Sender)
{
	if ( MainForm->Visible )
        	MainForm->Hide();
        else
        	MainForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TSplashForm::Esci1Click(TObject *Sender)
{
	Icona->Visible = false;
	Application->Terminate();
}
//---------------------------------------------------------------------------


void __fastcall TSplashForm::CountdownTimer(TObject *Sender)
{
	if ( Visible ) Hide();	
}
//---------------------------------------------------------------------------


void __fastcall TSplashForm::Ringraziamenti1Click(TObject *Sender)
{
	MainForm->Pager->ActivePageIndex = ((TMenuItem*)Sender)->Tag;
        MainForm->Show();
}
//---------------------------------------------------------------------------


void __fastcall TSplashForm::LocationsBeforeOpen(TObject *Sender)
{
        if ( ! FileExists(((TXMLDocument*)Sender)->FileName) )
        {
        	AnsiString MissingFile = ExtractFileName(((TXMLDocument*)Sender)->FileName);
                std::ofstream ofile(AnsiString(((TXMLDocument*)Sender)->FileName).c_str());
                ofile << "<?xml version=\"1.0\"?>" << std::endl << '<' << ChangeFileExt(MissingFile, "").c_str() << "/>" << std::endl;
                ofile.close();
        }
}
//---------------------------------------------------------------------------

