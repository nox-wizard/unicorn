//---------------------------------------------------------------------------

#ifndef MainUnitH
#define MainUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
#include <msxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TImage *HueColors;
        TTrackBar *GradientIndex;
        TEdit *ColorName;
        TButton *SaveBtn;
        TImage *ColorPalette;
        TLabel *ColorCode;
        TColorDialog *Colors;
        TXMLDocument *XMLDocument1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall GradientIndexChange(TObject *Sender);
        void __fastcall ColorPaletteMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall HueColorsMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall SaveBtnClick(TObject *Sender);
private:	// User declarations
        void LoadRegistry();
        AnsiString uopath;
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
