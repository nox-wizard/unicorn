//---------------------------------------------------------------------------


#include "SettingsUnit.h"
#include "MainUnit.h"
#include "SplashUnit.h"
#include "LoadFunctions.h"
#include "XSSParseUnit.h"
#include "ProgressUnit.h"
#include "stringhe.hpp"

#pragma hdrstop
#pragma package(smart_init)

inline char Charize(bool p)
{
        return p ? 'y' : 'n';
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::NewLineClick(TObject *Sender)
{
        GetSetupNode("commands")->Attributes["newline"] = Charize( NewLine->Checked );
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CmdPrefixChange(TObject *Sender)
{
        GetSetupNode("commands")->Attributes["prefix"] = CmdPrefix->Text;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Use0xClick(TObject *Sender)
{
        GetSetupNode("commands")->Attributes["use0x"] = Charize( Use0x->Checked );
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BrowseDefClientBtnClick(TObject *Sender)
{
	if( ClientDialog->Execute() )
        {
        	GetSetupNode("misc")->Attributes["defaultclient"] = ClientDialog->FileName;
                DefaultClient->Text = ClientDialog->FileName;
        }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Label2Click(TObject *Sender)
{
	ExitOnCloseClick(Sender);
        ExitOnClose->Checked = !ExitOnClose->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AoTClick(TObject *Sender)
{
        GetSetupNode("visualization")->Attributes["aot"] = Charize( AoT->Checked );
	MainForm->FormStyle = ( AoT->Checked ? fsStayOnTop : fsNormal );
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ExitOnCloseClick(TObject *Sender)
{
        GetSetupNode("visualization")->Attributes["exitonclose"] = Charize( ExitOnClose->Checked);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ShowArtClick(TObject *Sender)
{
        GetSetupNode("visualization")->Attributes["showartid"] = Charize(ShowArt->Checked);
        if ( ! ShowArt->Checked )
        {
        	ItmArt->ArtIndex = -1;
                ChrArt->ArtIndex = -1;
        }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Show3DRoomClick(TObject *Sender)
{
        GetSetupNode("visualization")->Attributes["show3droom"] = Charize(Show3DRoom->Checked);
        if ( Show3DRoom->Checked )
        	ItmArt->DrawFlags |= 1;
        else
        	ItmArt->DrawFlags &= ~1;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BrowseNoxWizardBtnClick(TObject *Sender)
{
	if( OpenNoxWizard->Execute() )
        {
                GetSetupNode("misc")->Attributes["nxwpath"] = ExtractFileDir(OpenNoxWizard->FileName);
                NXWPath->Text = ExtractFileDir(OpenNoxWizard->FileName);
        }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::LoadXSSBtnClick(TObject *Sender)
{
	if ( NXWPath->Text.IsEmpty() )
	{
		Errors::ThrowError(
			Stringhe_err_nxwpath_invalid,
			Errors::ehFatal,
			MB_OK
		);
	} else if ( OpenScript->Execute() )
        {
        	TXSSParser par(
                	OpenScript->FileName,
                        NXWPath->Text,
                        SplashForm->Characters->DocumentElement,
                        SplashForm->Items->DocumentElement,
                        NoX73Comp->Checked
                        );
                ProgressForm->Show();
                par.Parse();
                ProgressForm->Hide();
                SplashForm->Items->SaveToFile();
                SplashForm->Items->LoadFromFile();
                SplashForm->Characters->SaveToFile();
                SplashForm->Characters->LoadFromFile();
                LoadItems();
                LoadCharacters();
        }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::NoX73CompClick(TObject *Sender)
{
        GetSetupNode("misc")->Attributes["compat73"] = Charize( NoX73Comp->Checked );
}
//---------------------------------------------------------------------------

