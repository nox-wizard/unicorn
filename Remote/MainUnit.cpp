//---------------------------------------------------------------------------
#include <fstream>
#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include "AddAcctUnit.h"
#include "stringhe.hpp"
#include "UtilUnit.h"
#include "ErrorUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
        recbuf = new char [65536];
        topbuf = recbuf;
        freerec = 65536;
        Errors::AssignHandle(Application->Handle);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RCServersBeforeOpen(TObject *Sender)
{
        if ( ! FileExists(((TXMLDocument*)Sender)->FileName) )
        {
        	AnsiString MissingFile = ExtractFileName(((TXMLDocument*)Sender)->FileName);
                std::ofstream ofile(AnsiString(((TXMLDocument*)Sender)->FileName).c_str());
                ofile << "<?xml version=\"1.0\"?>" << std::endl << '<' << ChangeFileExt(MissingFile, "").c_str() << "/>" << std::endl;
                ofile.close();
        }
}
//---------------------------------------------------------------------------
void TMainForm::LoadServers()
{
	ServerList->Clear();
	#define SERVERS RCServers->DocumentElement->ChildNodes
        for(int i = 0; i < SERVERS->Count; i++)
        	ServerList->AddItem(Stringize(SERVERS->Nodes[i]->Attributes["name"]), ServerList);
        #undef SERVERS
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::RCConnectBtnClick(TObject *Sender)
{
        // TODO verificare che i dati siano validi
	if ( !RCConnectBtn->Tag )
        {
                RCConnection->Host = ServerIP->Text;
                RCConnection->Port = ServerPort->Text.ToIntDef(2594);
                RCConnectBtn->Caption = Stringhe_rac_Disconnect;
                RCConnectBtn->Tag = 1;
                RCConnection->Open();
        }
        else
        {
        	SendRACCommand("QUIT");
        	RCConnection->Close();
        	RCConnectBtn->Caption = Stringhe_rac_Connect;
                RCConnectBtn->Tag = 0;
        	// disconnetti
                delete ss;
                ss = NULL;
        }
}
//---------------------------------------------------------------------------
char *TMainForm::LastLine(char *buffer)
{
        char *t, *p = buffer;
        do
        {
        	t = strchr(p, '\n');
                if ( !t ) break;
                p = t+1;
        } while(t);
        return p;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RCConnectionConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
	ss = new TWinSocketStream(Socket, 1000); // 5 minues timeout
        if ( SendRACCommand("", "Login : ") )
        {
        	if ( SendRACCommand(ServerUsername->Text, "password : ") )
                {
                	if ( SendRACCommand(ServerPassword->Text) )
                        {
                        	ReloadConsole();
                        }
                        else
                        {
		        	Errors::ThrowError(
                                	Stringhe_rac_InvalidLogin,
                		        Errors::ehInfo,
                        		MB_YESNO
	        	                );
        	                        RCConnectBtnClick(Sender);
                        }
                }
                else
                {
	        	Errors::ThrowError(
                        	Stringhe_rac_InvalidConsole,
                	        Errors::ehInfo,
                        	MB_YESNO
        	                );
                                RCConnectBtnClick(Sender);
                        RCConnectBtnClick(Sender);
                }
        }
        else
        {
        	Errors::ThrowError(
                	Stringhe_rac_InvalidConsole,
                        Errors::ehInfo,
                        MB_YESNO
                        );
                RCConnectBtnClick(Sender);
        }
}
//---------------------------------------------------------------------------
bool TMainForm::SendRACCommand(AnsiString command, AnsiString expectedprompt)
{
	TCursor sc = Screen->Cursor;
        Screen->Cursor = crHourGlass;
        Application->ProcessMessages();
	if ( ! command.IsEmpty() )
        {
        	command += "\r\n";
	      	int len = command.Length();
        	char *sendbuf = new char[len+1];
	        for(int j = 1; j < len; j++)
        		sendbuf[j-1] = command[j];
	        sendbuf[len] = '\0';

        	ss->Write(sendbuf, len+2);
	        delete[] sendbuf;
        }

        if ( ! ss->WaitForData(30000) )
        {
                Errors::ThrowError(
                	Stringhe_rac_ConnTimeout,
                        Errors::ehNonFatal,
                        MB_OK
                        );
                RCConnectBtnClick(RCConnectBtn);
        }

        int i, p;
      	for(i = 0, p = 1; i < freerec && p; i++) // legge l'output
        {
       		p = ss->Read(recbuf+i, 1);
               	if ( (unsigned char)recbuf[i] == 0xFF ) // IAC, all commands start with this
                {
       	        	ss->Read(recbuf+i, 2);
               	        i--;
                }
       	}

        recbuf[--i] = '\0';

        if ( ! expectedprompt.IsEmpty() )
        {
	       	char *prompt = LastLine(recbuf);
        	RCOutput->Lines->Append(recbuf);

	        Screen->Cursor = sc;
        	Application->ProcessMessages();
	       	return( ! strcmp(prompt, expectedprompt.c_str() ) );
        }
        Screen->Cursor = sc;
        Application->ProcessMessages();
        return 0;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RCSendCmdBtnClick(TObject *Sender)
{
	SendRACCommand(RCCommand->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RCSendBroadBtnClick(TObject *Sender)
{
	SendRACCommand("! " + RCBroadCast->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RCHelpBtnClick(TObject *Sender)
{
	SendRACCommand("HELP");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RCWhoBtnClick(TObject *Sender)
{
	SendRACCommand("WHO");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RCPerfDumpBtnClick(TObject *Sender)
{
	SendRACCommand("PDUMP");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RCSaveWorldBtnClick(TObject *Sender)
{
	SendRACCommand("SAVE");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RCReloadCronBtnClick(TObject *Sender)
{
	SendRACCommand("RELOADCRON");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RCReloadBlocksBtnClick(TObject *Sender)
{
	SendRACCommand("RELOADBLOCKS");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RCShutdownBtnClick(TObject *Sender)
{
	SendRACCommand("SHUTDOWN");
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RCAbortBtnClick(TObject *Sender)
{
	if (Application->MessageBox(Stringhe_rac_SureAbort.c_str(), Stringhe_rac_Sure.c_str(), MB_YESNO) == IDYES )
        	SendRACCommand("ABORT");
}
//---------------------------------------------------------------------------
void TMainForm::ReloadConsole()
{
	RCAbortBtn->Enabled = RCConnection->Active;
        RCHelpBtn->Enabled = RCConnection->Active;
        RCPerfDumpBtn->Enabled = RCConnection->Active;
        RCReloadBlocksBtn->Enabled = RCConnection->Active;
        RCReloadCronBtn->Enabled = RCConnection->Active;
        RCSaveWorldBtn->Enabled = RCConnection->Active;
        RCShutdownBtn->Enabled = RCConnection->Active;
        RCWhoBtn->Enabled = RCConnection->Active;
        RCSendCmdBtn->Enabled = RCConnection->Active;
        RCSendBroadBtn->Enabled = RCConnection->Active;
        RCAddAcctBtn->Enabled = RCConnection->Active;
        RCCommand->Enabled = RCConnection->Active;
        RCBroadCast->Enabled = RCConnection->Active;
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::RCAddAcctBtnClick(TObject *Sender)
{
	if ( AddAcctForm->ShowModal() == mrOk )
        {
        	SendRACCommand("addacct " + AddAcctForm->newUsername->Text +
                               ", " + AddAcctForm->newPassword->Text, "" );
                char *p = strchr(strchr(recbuf, '\n'), '\n'), *t = strchr(p, '\n');
                *t = '\0';
                int accnum;
                if ( std::sscanf(p, "Account %d created\r", &accnum) )
                {
                	Errors::ThrowError(
                        	Stringhe_rac_AccountCreated,
                                Errors::ehInfo,
                                MB_OK
                                );
                }
                else
                {
                	if (
                        	Errors::ThrowError(
                                	Stringhe_rac_AccountNotCreated,
	                                Errors::ehWarning,
                                	MB_YESNO
                                	) == IDYES
                        )
                        {
                        	RCAddAcctBtnClick(RCAddAcctBtn);
                        }
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{
        ReloadConsole();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ServerPortChange(TObject *Sender)
{
        ServerList->ItemIndex = -1;        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AddServerBtnClick(TObject *Sender)
{
        AddServerForm->ServerName->Text = ServerUsername->Text + " @ " + ServerIP->Texts;
        if ( AddServerForm->ShowModal() == mrOk )
        {
                _di_IXMLNode N = RCServers->DocumentElement->AddChild("server");
                N->Attributes["name"] = AddServerForm->ServerName->Text;
                N->Attributes["host"] = ServerIP->Text;
                N->Attributes["port"] = ServerPort->Text;
                N->Attributes["user"] = ServerUsername->Text;
                N->Attributes["password"] = ServerPassword->Text;
        }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ServerListChange(TObject *Sender)
{
        #define N RCServers->DocumentElement->ChildNodes->Nodes[ServerList->ItemIndex]
        ServerIP->Text = Stringize(N->Attributes["name"]);
        ServerPort->Text = Stringize(N->Attributes["name"]);
        ServerUsername->Text = Stringize(N->Attributes["user"]);
        ServerPassword->Text = Stringize(N->Attributes["password"]);
        #undef N
}
//---------------------------------------------------------------------------

