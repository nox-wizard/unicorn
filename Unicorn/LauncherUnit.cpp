//---------------------------------------------------------------------------


#include "LauncherUnit.h"
#include "MainUnit.h"
#include "SplashUnit.h"
#include "LoadFunctions.h"
#include "XSSParseUnit.h"
#include "FileUnit.h"

#pragma hdrstop
#pragma package(smart_init)

//---------------------------------------------------------------------------
void __fastcall TMainForm::ClientListClick(TObject *Sender)
{
	if ( ClientList->ItemIndex != -1 )
        {
        	#define tnode SplashForm->Launcher->DocumentElement->ChildNodes->Nodes[ClientList->ItemIndex]
        	_di_IXMLNode tnode2;
                EntryName->Text = tnode->Attributes["name"];
                tnode2 = tnode->ChildNodes->FindNode("client");
                ClientPath->Text = tnode2->Text;
                tnode2 = tnode->ChildNodes->FindNode("server");
                ServerIP->Text = tnode2->Attributes["ip"];
                ServerPort->Text = tnode2->Attributes["port"];
                tnode2 = tnode->ChildNodes->FindNode("account");
                AccountName->Text = tnode2->Attributes["user"];
                AccountPassword->Text = tnode2->Attributes["password"];

                tnode2 = tnode->ChildNodes->FindNode("files");
                if ( tnode2 )
	                for(int i = 0; i < tnode2->ChildNodes->Count; i++)
        	        	FileList->AddItem(ExtractFileName(tnode2->ChildNodes->Nodes[i]->Text), FileList);

                EditBtn->Enabled = true;
                LaunchBtn->Enabled = true;
                #undef tnode
        }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::EditBtnClick(TObject *Sender)
{
	EntryName->Enabled = true;
        ClientPath->Enabled = true;
        AccountName->Enabled = true;
        AccountPassword->Enabled = true;
        ServerIP->Enabled = true;
        ServerPort->Enabled = true;
        OKBtn->Enabled = true;
        CancelBtn->Enabled = true;
        BrowseClient->Enabled = true;
        ClientList->Enabled = false;
        EditBtn->Enabled = false;
        LaunchBtn->Enabled = false;

        OKBtn->Tag = 1;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CancelBtnClick(TObject *Sender)
{
	EntryName->Enabled = false;
        ClientPath->Enabled = false;
        AccountName->Enabled = false;
        AccountPassword->Enabled = false;
        ServerIP->Enabled = false;
        ServerPort->Enabled = false;
        OKBtn->Enabled = false;
        CancelBtn->Enabled = false;
        BrowseClient->Enabled = false;
        ClientList->Enabled = true;
        EditBtn->Enabled = true;
        LaunchBtn->Enabled = true;

	EntryName->Text = "";
        ClientPath->Text = "";
        AccountName->Text = "";
        AccountPassword->Text = "";
        ServerIP->Text = "";
        ServerPort->Text = "";

        LoadClients();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::OKBtnClick(TObject *Sender)
{
	switch(OKBtn->Tag)
        {
        	case 1:
                {
			_di_IXMLNode client = SplashForm->Launcher->DocumentElement->ChildNodes->
        			Nodes[ClientList->ItemIndex], tnode;
	        	client->Attributes["name"] = EntryName->Text;

	        	tnode = client->ChildNodes->FindNode("client");
		        tnode->Text = ClientPath->Text;
        		tnode = client->ChildNodes->FindNode("server");
		        tnode->Attributes["ip"] = ServerIP->Text;
        		tnode->Attributes["port"] = ServerPort->Text;
	        	tnode = client->ChildNodes->FindNode("account");
	        	tnode->Attributes["user"] = AccountName->Text;
		        tnode->Attributes["password"] = AccountPassword->Text;

                }
                break;
                case 2:
                {
                	_di_IXMLNode newent = SplashForm->Launcher->DocumentElement->
                        	AddChild("entry"), tnode;
                        newent->Attributes["name"] = EntryName->Text;
                        tnode = newent->AddChild("client");
                        tnode->Text = ClientPath->Text;
                        tnode = newent->AddChild("server");
                        tnode->Attributes["ip"] = ServerIP->Text;
                        tnode->Attributes["port"] = ServerPort->Text;
                        tnode = newent->AddChild("account");
                        tnode->Attributes["user"] = AccountName->Text;
                        tnode->Attributes["password"] = AccountPassword->Text;
                }
                break;
        }
        ReloadClients();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BrowseClientClick(TObject *Sender)
{
	if ( ClientDialog->Execute() )
        	ClientPath->Text = ClientDialog->FileName;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RemoveBtnClick(TObject *Sender)
{
	if ( ClientList->ItemIndex != -1 )
        {
        	SplashForm->Launcher->DocumentElement->ChildNodes->
                	Delete( ClientList->ItemIndex );
                ReloadClients();
        }
}
//---------------------------------------------------------------------------
void TMainForm::ReloadClients()
{
	SplashForm->Launcher->SaveToFile();
        SplashForm->Launcher->LoadFromFile();

	EntryName->Enabled = false;
        ClientPath->Enabled = false;
        AccountName->Enabled = false;
        AccountPassword->Enabled = false;
        ServerIP->Enabled = false;
        ServerPort->Enabled = false;
	OKBtn->Enabled = false;
        CancelBtn->Enabled = false;
        BrowseClient->Enabled = false;
        ClientList->Enabled = true;
        EditBtn->Enabled = true;
        LaunchBtn->Enabled = true;

        EntryName->Text = "";
        ClientPath->Text = "";
	AccountName->Text = "";
	AccountPassword->Text = "";
	ServerIP->Text = "";
	ServerPort->Text = "";

	LoadClients();
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::AddBtnClick(TObject *Sender)
{
	EntryName->Enabled = true;
        ClientPath->Enabled = true;
        AccountName->Enabled = true;
        AccountPassword->Enabled = true;
        ServerIP->Enabled = true;
        ServerPort->Enabled = true;
        OKBtn->Enabled = true;
        CancelBtn->Enabled = true;
        BrowseClient->Enabled = true;
        ClientList->Enabled = false;
        EditBtn->Enabled = false;
        LaunchBtn->Enabled = false;

        ClientPath->Text = Stringize(GetSetupNode("misc")->Attributes["defaultclient"]);
	EntryName->Text = "";
        AccountName->Text = "";
        AccountPassword->Text = "";
        ServerIP->Text = "";
        ServerPort->Text = "2593";

        OKBtn->Tag = 2;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::LaunchBtnClick(TObject *Sender)
{
        TFileStream* logincfg = new TFileStream(uopath + "\\login.cfg", fmCreate | fmShareCompat );
        char *buffer = new char [255];
        std::sprintf(buffer, "LoginServer=%s,%s\r\n", ServerIP->Text.c_str(), ServerPort->Text.c_str());
        logincfg->Write(buffer, strlen(buffer));
        delete logincfg;

        AnsiString uocfg_name = uopath + "\\uo.cfg", uobak_name = uopath + "\\uo.bak";
        RenameFile( uocfg_name, uobak_name );
        std::ifstream ifile ( uobak_name.c_str() );
        std::ofstream ofile ( uocfg_name.c_str() );

        bool savepw = false, pw = false, acc = false;

        AnsiString pass = AccountPassword->Text;
        for(int i = 1; i <= pass.Length(); i++)
        {
        	pass[i] += 13;
        }

        while(ifile)
        {
        	ifile.getline(buffer, 255);
                if ( ! std::strncmpi(buffer, "RememberAcctPW", 14 ) )
                {
                	ofile << "RememberAcctPW=on" << std::endl;
                        savepw = true;
                }
                else if ( ! std::strncmpi(buffer, "AcctPassword", 12 ) )
                {
                        ofile << "AcctPassword=" << pass.c_str() << std::endl;
                        pw = true;
                }
                else if ( ! std::strncmpi(buffer, "AcctID", 6 ) )
                {
                        ofile << "AcctID=" << AccountName->Text.c_str() << std::endl;
                        acc = true;
                }
                else
                	ofile << buffer << std::endl;
        }

        if ( ! pw )
        	ofile << "AcctPassword=" << pass.c_str() << std::endl;
        if ( ! acc )
        	ofile << "AcctID=" << AccountName->Text.c_str() << std::endl;
        if ( ! savepw )
        	ofile << "RememberAcctPW=on" << std::endl;

        delete[] buffer;

        DeleteFile( uobak_name );

        // qui devo cominciare a copiare i files... suicidiooooo

        _di_IXMLNode tnode = SplashForm->Launcher->DocumentElement->ChildNodes->
        	Nodes[ClientList->ItemIndex]->ChildNodes->FindNode("files");
        if ( tnode )
        {
        	for(int i = 0; i < tnode->ChildNodes->Count; i++)
	        {
		        AnsiString from = Stringize(tnode->ChildNodes->Nodes[i]->Attributes["from"]),
                		   to = Stringize(tnode->ChildNodes->Nodes[i]->Attributes["to"]);
	                CopyFile(from.c_str(), to.c_str(), false);
        	}
        }

        ShellExecute(
        	NULL,
                NULL,
                ClientPath->Text.c_str(),
                NULL,
                NULL,
                SW_SHOW
                );
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AddFileBtnClick(TObject *Sender)
{
	if ( FileForm->ShowModal() == mrOk )
        {
        	_di_IXMLNode tnode = SplashForm->Launcher->DocumentElement->ChildNodes->
                	Nodes[ClientList->ItemIndex]->ChildNodes->FindNode("files");
                tnode = tnode->AddChild("file");
                tnode->Attributes["from"] = FileForm->FromFile->Text;
                tnode->Attributes["to"] = FileForm->ToFile->Text;
                FileList->AddItem(ExtractFileName(FileForm->ToFile->Text), FileList);
                FileForm->FromFile->Text = "";
                FileForm->ToFile->Text = "";
        }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RemoveFileBtnClick(TObject *Sender)
{
	if ( FileList->ItemIndex != -1 )
        {
        	_di_IXMLNode tnode = SplashForm->Launcher->DocumentElement->ChildNodes->
                	Nodes[ClientList->ItemIndex]->ChildNodes->FindNode("files");
                tnode->ChildNodes->Delete(FileList->ItemIndex);
                FileList->ClearSelection();
        }
}
//---------------------------------------------------------------------------

