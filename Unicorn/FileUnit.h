//---------------------------------------------------------------------------

#ifndef FileUnitH
#define FileUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TFileForm : public TForm
{
__published:	// IDE-managed Components
	TEdit *FromFile;
	TLabel *Label1;
	TLabel *Label2;
	TEdit *ToFile;
	TButton *OKBtn;
	TButton *CancelBtn;
	TButton *BrowseFrom;
	TButton *BrowseTo;
	TOpenDialog *MulDialog;
	void __fastcall BrowseFromClick(TObject *Sender);
	void __fastcall BrowseToClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFileForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFileForm *FileForm;
//---------------------------------------------------------------------------
#endif
