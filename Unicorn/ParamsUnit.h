//---------------------------------------------------------------------------

#ifndef ParamsUnitH
#define ParamsUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <ValEdit.hpp>
//---------------------------------------------------------------------------
class TParamsForm : public TForm
{
__published:	// IDE-managed Components
	TValueListEditor *Params;
	TButton *OKBtn;
	TButton *CancelBtn;
private:	// User declarations
public:		// User declarations
	__fastcall TParamsForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TParamsForm *ParamsForm;
//---------------------------------------------------------------------------
#endif
