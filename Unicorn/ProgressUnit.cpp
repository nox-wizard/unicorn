//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ProgressUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TProgressForm *ProgressForm;
//---------------------------------------------------------------------------
__fastcall TProgressForm::TProgressForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
