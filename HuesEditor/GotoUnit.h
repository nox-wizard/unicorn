//---------------------------------------------------------------------------

#ifndef GotoUnitH
#define GotoUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TGotoForm : public TForm
{
__published:	// IDE-managed Components
        TEdit *Index;
        TLabel *Label1;
        TButton *OKBtn;
        TButton *CacelBtn;
private:	// User declarations
public:		// User declarations
        __fastcall TGotoForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGotoForm *GotoForm;
//---------------------------------------------------------------------------
#endif
