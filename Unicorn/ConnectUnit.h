//---------------------------------------------------------------------------

#ifndef ConnectUnitH
#define ConnectUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TConnectForm : public TForm
{
__published:	// IDE-managed Components
	TComboBox *ServerList;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TEdit *ServerUsername;
	TEdit *ServerPassword;
	TButton *OKBtn;
	TButton *CancelBtn;
	TLabel *Label4;
	TEdit *ServerIP;
	TEdit *ServerPort;
	TLabel *Label5;
	void __fastcall ServerListSelect(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TConnectForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TConnectForm *ConnectForm;
//---------------------------------------------------------------------------
#endif
