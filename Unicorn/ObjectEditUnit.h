//---------------------------------------------------------------------------

#ifndef ObjectEditUnitH
#define ObjectEditUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <UOARTLib_OCX.h>
#include <OleCtrls.hpp>
//---------------------------------------------------------------------------
class TObjectEditForm : public TForm
{
__published:	// IDE-managed Components
	TComboBox *Categories;
	TComboBox *Subcategories;
	TEdit *Name;
	TButton *OKBtn;
	TButton *CancelBtn;
	TLabel *Label2;
	TLabel *Label1;
	TLabel *Label3;
	TLabel *Label4;
	TUOArt *Preview;
	TLabel *Label5;
	TEdit *ArtID;
	TEdit *IngameID;
	TLabel *Label6;
	TEdit *Color;
	TButton *ColorPaletteBtn;
	void __fastcall ColorPaletteBtnClick(TObject *Sender);
	void __fastcall ArtIDExit(TObject *Sender);
	void __fastcall ColorExit(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TObjectEditForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TObjectEditForm *ObjectEditForm;
//---------------------------------------------------------------------------
#endif
