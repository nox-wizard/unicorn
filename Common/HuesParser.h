//---------------------------------------------------------------------------

#ifndef HuesParserH
#define HuesParserH

#include <graphics.hpp>

namespace Hues
{
	long LoadHues(long oldcrc32, AnsiString uopath);
        void PaintHues(TCanvas* C, int x, int y, int g);
        void PaintHue(int hue, TCanvas* C, int x, int y);
        AnsiString GetName(int hue);
        void SetName(int hindex, AnsiString name);
        WORD GetHue(int hindex, int gindex);
        void WriteHue(int hindex, AnsiString uopath);
        void ChangeHue(int hue, int g, WORD wColor);
        TColor ScaleColor(WORD wColor);
        WORD UnscaleColor(TColor dwColor);
};

//---------------------------------------------------------------------------
#endif

