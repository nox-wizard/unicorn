//---------------------------------------------------------------------------

#include "MapUnit.h"
#include "MainUnit.h"
#include "SplashUnit.h"
#include "LoadFunctions.h"
#include "XSSParseUnit.h"
#include "FileUnit.h"
#include "stringhe.hpp"
#include "LocationEditUnit.h"

#pragma hdrstop
#pragma package(smart_init)
//---------------------------------------------------------------------------
void __fastcall TMainForm::MappaMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        switch(Button)
        {
                case mbLeft: // tasto sinistro
	                {
        	        	short x = (short)X, y = (short)Y;
                	        Mappa->CtrlToMap(&x, &y);
                		Mappa->SetCenter(x, y);
                                newx->Text = x;
                                newy->Text = y;
                                newz->Text = Mappa->GetMapHeight(x, y);
        	        }
                        break;
                case mbRight: // tasto destro
                        break;
                case mbMiddle: // tasto centrale
                        break;
        }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::TravelTabShow(TObject *Sender)
{
	short oldx, oldy;
        Mappa->GetCenter(&oldx, &oldy);
        newx->Text = oldx;
        newy->Text = oldy;
        newz->Text = Mappa->GetMapHeight(oldx, oldy);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::VaiBtnClick(TObject *Sender)
{
	short 	snewx = newx->Text.ToInt(),
        	snewy = newy->Text.ToInt();

        if ( snewx < 1 || snewx > 6144 || snewy < 1 || snewy > 4096 )
        {
        	Errors::ThrowError(
                	Stringhe_InvalidCoord,
                        Errors::ehInfo,
                        MB_YESNO
                        );
		short oldx, oldy;
	        Mappa->GetCenter(&oldx, &oldy);
	        newx->Text = oldx;
        	newy->Text = oldy;
                newz->Text = Mappa->GetMapHeight(oldx, oldy);
                return;
        }
        Mappa->SetCenter(snewx, snewy);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::LocCategoryChange(TObject *Sender,
      TTreeNode *Node)
{
	if ( Node->Level )
        {
        	#define lista SplashForm->Locations->DocumentElement->ChildNodes->Nodes[Node->Parent->Index]->ChildNodes->Nodes[Node->Index]->ChildNodes
                LocPlaces->Tag = Node->Parent->Index + ( Node->Index << 8 );
                LocPlaces->Clear();
                for(int i = 0; i < lista->Count; i++)
                        LocPlaces->AddItem(lista->Nodes[i]->Text, LocPlaces);
                #undef lista
        }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::LocPlacesClick(TObject *Sender)
{
	if ( LocPlaces->ItemIndex != -1 )
        {
                #define tnode SplashForm->Locations->DocumentElement->ChildNodes->Nodes[LocPlaces->Tag&0xFF]\
                	->ChildNodes->Nodes[LocPlaces->Tag >> 8]->ChildNodes->Nodes[LocPlaces->ItemIndex]
                newx->Text = tnode->Attributes["x"];
                newy->Text = tnode->Attributes["y"];
                newz->Text = tnode->Attributes["z"];
                Mappa->SetCenter(tnode->Attributes["x"], tnode->Attributes["y"]);
                #undef tnode
        }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Modifica1Click(TObject *Sender)
{
	LocationEdit->Categories->Clear();
        LocationEdit->Subcategories->Clear();
        #define tnode1 SplashForm->Locations->DocumentElement->ChildNodes->Nodes[i]
        for(int i = 0; i < SplashForm->Locations->DocumentElement->ChildNodes->Count; i++)
        	LocationEdit->Categories->Items->Add(tnode1->Attributes["name"]);
        #undef tnode1

        LocationEdit->Categories->ItemIndex = LocPlaces->Tag & 0xFF;

        #define tnode1 SplashForm->Locations->DocumentElement->ChildNodes->Nodes[LocPlaces->Tag&0xFF]
        #define tnode2 tnode1->ChildNodes->Nodes[i]
        for(int i = 0; i < tnode1->ChildNodes->Count; i++)
        	LocationEdit->Subcategories->Items->Add(tnode2->Attributes["name"]);
        #undef tnode1
        #undef tnode2

        LocationEdit->Subcategories->ItemIndex = LocPlaces->Tag >> 8;

        #define tnode SplashForm->Locations->DocumentElement->ChildNodes->\
        	Nodes[LocPlaces->Tag&0xFF]->ChildNodes->Nodes[LocPlaces->Tag>>8]->\
                ChildNodes->Nodes[LocPlaces->ItemIndex]
        LocationEdit->Name->Text = tnode->Text;
	LocationEdit->X->Text = tnode->Attributes["x"];
        LocationEdit->Y->Text = tnode->Attributes["y"];
        LocationEdit->Z->Text = tnode->Attributes["z"];
        #undef tnode

        if ( LocationEdit->ShowModal() == mrOk)
        {
              	SplashForm->Locations->DocumentElement->ChildNodes->
                Nodes[LocPlaces->Tag&0xFF]->ChildNodes->Nodes[LocPlaces->Tag>>8]->
                ChildNodes->Delete(LocPlaces->ItemIndex);

                _di_IXMLNode tnode = SplashForm->Locations->DocumentElement->AddChild("category");
                tnode->Attributes["name"] = LocationEdit->Categories->Text;
                tnode = tnode->AddChild("subsection");
                tnode->Attributes["name"] = LocationEdit->Subcategories->Text;
                tnode = tnode->AddChild("place");
                tnode->Attributes["name"] = LocationEdit->Name->Text;
                tnode->Attributes["x"] = LocationEdit->X->Text;
                tnode->Attributes["y"] = LocationEdit->Y->Text;
                tnode->Attributes["z"] = LocationEdit->Z->Text;
               	SplashForm->Locations->SaveToFile();
      		SplashForm->Locations->LoadFromFile();
                LoadLocations();
        }
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Elimina1Click(TObject *Sender)
{
	if ( LocPlaces->ItemIndex != -1 )
        {
		SplashForm->Locations->DocumentElement->ChildNodes->
        		Nodes[LocPlaces->Tag&0xFF]->ChildNodes->Nodes[LocPlaces->Tag>>8]->
                	ChildNodes->Delete(LocPlaces->ItemIndex);
                SplashForm->Locations->SaveToFile();
                SplashForm->Locations->LoadFromFile();
                LoadLocations();
        }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Inserisci1Click(TObject *Sender)
{
	LocationEdit->Categories->Clear();
        LocationEdit->Subcategories->Clear();
        #define tnode1 SplashForm->Locations->DocumentElement->ChildNodes->Nodes[i]
        for(int i = 0; i < SplashForm->Locations->DocumentElement->ChildNodes->Count; i++)
        	LocationEdit->Categories->Items->Add(tnode1->Attributes["name"]);
        #undef tnode1

        LocationEdit->Categories->ItemIndex = LocPlaces->Tag & 0xFF;

        if ( SplashForm->Locations->DocumentElement->ChildNodes->Count )
        {
	        #define tnode1 SplashForm->Locations->DocumentElement->ChildNodes->Nodes[LocPlaces->Tag&0xFF]
        	#define tnode2 tnode1->ChildNodes->Nodes[i]
	        for(int i = 0; i < tnode1->ChildNodes->Count; i++)
        		LocationEdit->Subcategories->Items->Add(tnode2->Attributes["name"]);
	        #undef tnode1
        	#undef tnode2
        }

        LocationEdit->Subcategories->ItemIndex = LocPlaces->Tag >> 8;
	LocationEdit->X->Text = newx->Text;
	LocationEdit->Y->Text = newy->Text;
	LocationEdit->Z->Text = newz->Text;

        if ( LocationEdit->ShowModal() == mrOk)
        {
                _di_IXMLNode tnode = SplashForm->Locations->DocumentElement->AddChild("category");
                tnode->Attributes["name"] = LocationEdit->Categories->Text;
                tnode = tnode->AddChild("subsection");
                tnode->Attributes["name"] = LocationEdit->Subcategories->Text;
                tnode = tnode->AddChild("place");
                tnode->Attributes["name"] = LocationEdit->Name->Text;
                tnode->Attributes["x"] = LocationEdit->X->Text;
                tnode->Attributes["y"] = LocationEdit->Y->Text;
		tnode->Attributes["z"] = LocationEdit->Z->Text;
                SplashForm->Locations->SaveToFile();
                SplashForm->Locations->LoadFromFile();
                LoadLocations();
        }
}
//---------------------------------------------------------------------------

