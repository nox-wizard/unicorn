//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FileUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFileForm *FileForm;
//---------------------------------------------------------------------------
__fastcall TFileForm::TFileForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFileForm::BrowseFromClick(TObject *Sender)
{
	if ( MulDialog->Execute() )
		FromFile->Text = MulDialog->FileName;
}
//---------------------------------------------------------------------------
void __fastcall TFileForm::BrowseToClick(TObject *Sender)
{
	if ( MulDialog->Execute() )
		ToFile->Text = MulDialog->FileName;
}
//---------------------------------------------------------------------------
