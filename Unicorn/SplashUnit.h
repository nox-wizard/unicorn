//---------------------------------------------------------------------------

#ifndef SplashUnitH
#define SplashUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <ComCtrls.hpp>
#include <oxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
#include <msxmldom.hpp>
#include <ImgList.hpp>
#include <Menus.hpp>
#include <trayicon.h>
#include "ErrorUnit.h"
//---------------------------------------------------------------------------
class TSplashForm : public TForm
{
__published:	// IDE-managed Components
	TImage *Logo;
	TProgressBar *Barra;
	TLabel *WTFDoing;
	TXMLDocument *Locations;
	TXMLDocument *Settings;
	TPopupMenu *MenuIcona;
	TMenuItem *Esci1;
	TTrayIcon *Icona;
	TXMLDocument *Launcher;
	TTimer *Countdown;
	TXMLDocument *DynCmds;
	TXMLDocument *Items;
	TXMLDocument *Characters;
	TMenuItem *ApriTab1;
	TMenuItem *Partenza1;
	TMenuItem *Viaggio1;
	TMenuItem *ComandiGenerali1;
	TMenuItem *Personalizzati1;
	TMenuItem *Impostazioni1;
	TMenuItem *Oggetti1;
	TMenuItem *Personaggi1;
	TMenuItem *Ringraziamenti1;
        TMenuItem *Tweak1;
	void __fastcall LogoClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall IconaClick(TObject *Sender);
	void __fastcall Esci1Click(TObject *Sender);
	void __fastcall CountdownTimer(TObject *Sender);
	void __fastcall Ringraziamenti1Click(TObject *Sender);
	void __fastcall LocationsBeforeOpen(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TSplashForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSplashForm *SplashForm;
//---------------------------------------------------------------------------
#endif
