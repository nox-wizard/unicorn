//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <msxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
#include <ScktComp.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TComboBox *ServerList;
        TXMLDocument *RCServers;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TEdit *ServerPort;
        TEdit *ServerIP;
        TEdit *ServerPassword;
        TEdit *ServerUsername;
        TButton *RCConnectBtn;
        TButton *AddServerBtn;
        TMemo *RCOutput;
        TLabel *Label12;
        TLabel *Label13;
        TEdit *RCBroadCast;
        TEdit *RCCommand;
        TButton *RCSendCmdBtn;
        TButton *RCSendBroadBtn;
        TGroupBox *GroupBox10;
        TButton *RCHelpBtn;
        TButton *RCWhoBtn;
        TButton *RCPerfDumpBtn;
        TButton *RCSaveWorldBtn;
        TButton *RCReloadCronBtn;
        TButton *RCReloadBlocksBtn;
        TButton *RCAddAcctBtn;
        TButton *RCChangeCfgBtn;
        TButton *RCShutdownBtn;
        TButton *RCAbortBtn;
        TClientSocket *RCConnection;
        void __fastcall RCServersBeforeOpen(TObject *Sender);
        void __fastcall RCConnectBtnClick(TObject *Sender);
        void __fastcall RCConnectionConnect(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall RCSendCmdBtnClick(TObject *Sender);
        void __fastcall RCSendBroadBtnClick(TObject *Sender);
        void __fastcall RCHelpBtnClick(TObject *Sender);
        void __fastcall RCWhoBtnClick(TObject *Sender);
        void __fastcall RCAbortBtnClick(TObject *Sender);
        void __fastcall RCShutdownBtnClick(TObject *Sender);
        void __fastcall RCPerfDumpBtnClick(TObject *Sender);
        void __fastcall RCSaveWorldBtnClick(TObject *Sender);
        void __fastcall RCReloadCronBtnClick(TObject *Sender);
        void __fastcall RCReloadBlocksBtnClick(TObject *Sender);
        void __fastcall RCAddAcctBtnClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall ServerPortChange(TObject *Sender);
        void __fastcall AddServerBtnClick(TObject *Sender);
        void __fastcall ServerListChange(TObject *Sender);
private:	// User declarations
        void LoadServers();
        TWinSocketStream *ss;
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
        char *LastLine(char*);
        bool SendRACCommand(AnsiString command, AnsiString expectedprompt = "[NoX-Wizard Shard]");
        char *recbuf, *topbuf;
        int freerec; // free receive buffer
        void ReloadConsole();
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
