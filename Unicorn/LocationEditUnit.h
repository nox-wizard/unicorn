//---------------------------------------------------------------------------

#ifndef LocationEditUnitH
#define LocationEditUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TLocationEdit : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TComboBox *Categories;
	TComboBox *Subcategories;
	TEdit *Name;
	TEdit *X;
	TEdit *Y;
	TEdit *Z;
	TButton *OKBtn;
	TButton *CancelBtn;
private:	// User declarations
public:		// User declarations
	__fastcall TLocationEdit(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TLocationEdit *LocationEdit;
//---------------------------------------------------------------------------
#endif
