//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainUnit.h"
#include "UtilUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormShow(TObject *Sender)
{
        RSSFeed->Active = true;
        _di_IXMLNodeList news = RSSFeed->DocumentElement->ChildNodes->FindNode("item")->ChildNodes;
        Title->Caption = news->FindNode("title")->Text;
        Author->Caption = news->FindNode("author")->Text;
        Date->Caption = news->FindNode("pubdate")->Text;
        Description->Lines->SetText(AnsiString(GetNode("item")->Text).c_str());
}
//---------------------------------------------------------------------------

