//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ObjectEditUnit.h"
#include "HuesUnit.h"
#include "stringhe.hpp"
#include "UtilUnit.h"
#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "UOARTLib_OCX"
#pragma resource "*.dfm"
TObjectEditForm *ObjectEditForm;
//---------------------------------------------------------------------------
__fastcall TObjectEditForm::TObjectEditForm(TComponent* Owner)
	: TForm(Owner)
{
}                       
//---------------------------------------------------------------------------
void __fastcall TObjectEditForm::ColorPaletteBtnClick(TObject *Sender)
{
	PaletteForm->ColoredArt->ArtIndex = ArtID->Text.ToIntDef(0);
        PaletteForm->ColoredArt->ArtType = 0;
	if ( PaletteForm->ShowModal() )
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
        	Color->Text = PaletteForm->ColorCode->Caption;
                Preview->ArtColor = color;
        }
}
//---------------------------------------------------------------------------
void __fastcall TObjectEditForm::ArtIDExit(TObject *Sender)
{
	Preview->ArtIndex = HexToInt(ArtID->Text);
}
//---------------------------------------------------------------------------
void __fastcall TObjectEditForm::ColorExit(TObject *Sender)
{
	Preview->ArtColor = HexToInt(Color->Text);
}
//---------------------------------------------------------------------------
