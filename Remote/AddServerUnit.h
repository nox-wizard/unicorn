//---------------------------------------------------------------------------

#ifndef AddServerUnitH
#define AddServerUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TAddServerForm : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *ServerName;
        TButton *OKBtn;
        TButton *CancelBtn;
private:	// User declarations
public:		// User declarations
        __fastcall TAddServerForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAddServerForm *AddServerForm;
//---------------------------------------------------------------------------
#endif
