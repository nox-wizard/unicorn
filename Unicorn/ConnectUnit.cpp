//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ConnectUnit.h"
#include "SplashUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TConnectForm *ConnectForm;
//---------------------------------------------------------------------------
__fastcall TConnectForm::TConnectForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TConnectForm::ServerListSelect(TObject *Sender)
{
	#define SERVER SplashForm->RCServers->DocumentElement->ChildNodes->Nodes[ServerList->ItemIndex]->ChildNodes
        _di_IXMLNode serverinfo = SERVER->FindNode("connection"),
        	     serveruser = SERVER->FindNode("account");
	ServerIP->Text = serverinfo->Attributes["addr"];
        ServerPort->Text = serverinfo->Attributes["port"];
        ServerUsername->Text = serveruser->Attributes["name"];
        ServerPassword->Text = serveruser->Attributes["pass"];
        #undef SERVER
}
//---------------------------------------------------------------------------

void _
