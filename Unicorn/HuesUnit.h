//---------------------------------------------------------------------------

#ifndef HuesUnitH
#define HuesUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <UOARTLib_OCX.h>
#include <OleCtrls.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TPaletteForm : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *HueBox;
	TUOArt *ColoredArt;
	TButton *OKBtn;
	TButton *CancelBtn;
	TImage *ColorPalette;
	TImage *HueColors;
	TTrackBar *ColorIndexBar;
	TLabel *ColorCode;
	void __fastcall ColorIndexBarChange(TObject *Sender);
	void __fastcall ColorPaletteMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
private:	// User declarations
public:		// User declarations
	__fastcall TPaletteForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPaletteForm *PaletteForm;
//---------------------------------------------------------------------------
#endif
