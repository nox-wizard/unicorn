//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HuesUnit.h"
#include "MainUnit.h"
#include "SplashUnit.h"
#include "HuesParser.h"
#include "UtilUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UOARTLib_OCX"
#pragma resource "*.dfm"
TPaletteForm *PaletteForm;
//---------------------------------------------------------------------------
__fastcall TPaletteForm::TPaletteForm(TComponent* Owner)
	: TForm(Owner)
{
	Hues::PaintHues(ColorPalette->Canvas, 10, 10, 5);
}
//---------------------------------------------------------------------------
void __fastcall TPaletteForm::ColorIndexBarChange(TObject *Sender)
{
	Hues::PaintHues(ColorPalette->Canvas, 10, 10, ColorIndexBar->Position);
}
//---------------------------------------------------------------------------
void __fastcall TPaletteForm::ColorPaletteMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{

	int hindex = m2v(X/10, Y/10, 60);
	Hues::PaintHue(hindex, HueColors->Canvas, 10, 25);

        HueBox->Caption = Hues::GetName(hindex);
        ColorCode->Caption = ColorCode->Caption.sprintf("%x", hindex );
        ColoredArt->ArtColor = hindex;
}
//---------------------------------------------------------------------------


