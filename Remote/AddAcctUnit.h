//---------------------------------------------------------------------------

#ifndef AddAcctUnitH
#define AddAcctUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TAddAcctForm : public TForm
{
__published:	// IDE-managed Components
	TButton *OKBtn;
	TButton *CancelBtn;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *newUsername;
	TEdit *newPassword;
private:	// User declarations
public:		// User declarations
	__fastcall TAddAcctForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAddAcctForm *AddAcctForm;
//---------------------------------------------------------------------------
#endif
