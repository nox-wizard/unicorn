//---------------------------------------------------------------------------

#include <vcl.h>
#include <registry.hpp>
#pragma hdrstop

#include "MainUnit.h"
#include "HuesParser.h"
#include "UtilUnit.h"
#include "ErrorUnit.h"
#include "stringhe.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
        LoadRegistry();
        Hues::LoadHues(0, uopath);
        Hues::PaintHues(ColorPalette->Canvas, 10, 10, 5);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::GradientIndexChange(TObject *Sender)
{
	Hues::PaintHues(ColorPalette->Canvas, 10, 10, GradientIndex->Position);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ColorPaletteMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
	int hindex = m2v(X/10, Y/10, 60);
	Hues::PaintHue(hindex, HueColors->Canvas, 10, 30);

        ColorName->Text = Hues::GetName(hindex);
        AnsiString colorcode; colorcode.sprintf("%x", hindex );
        ColorCode->Caption = colorcode;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::HueColorsMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        int gindex = X/10;
        int hindex = HexToInt(ColorCode->Caption);
        Colors->Color = Hues::ScaleColor(Hues::GetHue(hindex, gindex));
        if (Colors->Execute())
        {
                Hues::ChangeHue(hindex, gindex, Hues::UnscaleColor(Colors->Color) );
        	Hues::PaintHue(hindex, HueColors->Canvas, 10, 30);
        }
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::SaveBtnClick(TObject *Sender)
{
        int hindex = HexToInt(ColorCode->Caption);
        Hues::SetName(hindex, ColorName->Text);
        Hues::WriteHue(hindex, uopath);
}
//---------------------------------------------------------------------------
void TMainForm::LoadRegistry()
{
        TRegistry *Reg = new TRegistry(KEY_READ);
	try
        {
        	Reg->RootKey = HKEY_LOCAL_MACHINE;
                Reg->OpenKey("SOFTWARE\\Origin Worlds Online\\Ultima Online\\1.0", false);
                uopath = ExtractFileDir(Reg->ReadString("ExePath"));
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

