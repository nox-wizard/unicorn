//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include "UtilUnit.h"
#include "ErrorUnit.h"
#include "stringhe.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "IpBroker"
#pragma link "IpHtml"
#pragma link "IpUtils"
#pragma link "IpBroker"
#pragma link "IpHtml"
#pragma link "IpUtils"
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
        Errors::AssignHandle(Application->Handle);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
        RSSFeed->Active = true;
        _di_IXMLNode item = RSSFeed->DocumentElement->ChildNodes->FindNode("channel");
        if ( ! item )
        {
                Errors::ThrowError(
                        Stringhe_err_invalid_rssfeed,
                        Errors::ehFatal,
                        MB_OK
                        );
                Application->Terminate();
        }

        item = item->ChildNodes->FindNode("item");
        if ( ! item )
        {
                Errors::ThrowError(
                        Stringhe_err_invalid_rssfeed,
                        Errors::ehFatal,
                        MB_OK
                        );
                Application->Terminate();
        }

        Title->Caption = item->ChildNodes->FindNode("title")->Text;
        Author->Caption = item->ChildNodes->FindNode("author")->Text;
        Date->Caption = item->ChildNodes->FindNode("pubDate")->Text;
        AnsiString desc = item->ChildNodes->FindNode("description")->Text;
        Description->Lines->SetText(desc.c_str());
}
//---------------------------------------------------------------------------


