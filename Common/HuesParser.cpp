//---------------------------------------------------------------------------


#pragma hdrstop

#include "HuesParser.h"
#include "CRC32Unit.h"
#include "UtilUnit.h"
#include "MainUnit.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

namespace Hues
{
	//! hue structure
	struct THue
        {
                short colortable[32];
        	char name[20];
        };

        struct THueGroup
        {
        	int header;
                struct THueMul
                {
                	short colortable[32];
                        short TableStart;
                        short TableEnd;
                        char name[20];
                } hues[8];
        };

	//! hues vector
	THue hues[3000];

        /*!
        \brief Caches the hues.mul in the hues.uni file
        */
        void CacheHues(AnsiString uopath)
	{
        	TFileStream *huesmul = new TFileStream(
                	uopath + "\\hues.mul",
                        fmOpenRead|fmShareCompat
                        );
                TFileStream *huesuni = new TFileStream(
                	ExtractFileDir(Application->ExeName) + "\\mulcache\\hues.uni",
                        fmCreate|fmShareCompat
                        );

                THue huetmp;
                THueGroup huegroup;
                for(register int i = 0; i < 375; i++)
                {
                	huesmul->Read(&huegroup, sizeof(THueGroup));
                        for(int j = 0; j < 8; j++)
                        {
                        	memcpy(&huetmp.colortable, &huegroup.hues[j].colortable, sizeof(huegroup.hues[j].colortable));
                                memcpy(&huetmp.name, &huegroup.hues[j].name, sizeof(huegroup.hues[j].name));
	                        huesuni->Write(&huetmp, sizeof(huetmp));
                        }
                }
                delete huesmul;
                delete huesuni;
        }

	/*!
        \brief Load the hues in the hues array
        \param oldcrc32 The saved crc32 for hues.mul
        \param uopath Path to uo directory, for load hues.mul
        \return the current crc32 of the hues.mul file
        */
	long LoadHues(long oldcrc32, AnsiString uopath)
        {
        	long huescrc32 = 0;
                CRC32::FileCrc32((uopath + "\\hues.mul").c_str(), huescrc32);
//                long oldcrc32 = GetSetupNode("cachecrc")->Attributes["hues"];
                if ( !FileExists(ExtractFileDir(Application->ExeName) + "\\mulcache\\hues.uni") )
                	oldcrc32 = 0;

                if ( huescrc32 != oldcrc32 )
                {
                	CacheHues(uopath);
//                        GetSetupNode("cachecrc")->Attributes["hues"] = AnsiString(huescrc32);
                }

                TFileStream *huescache = new TFileStream(
                	ExtractFileDir(Application->ExeName) + "\\mulcache\\hues.uni",
                        fmOpenRead|fmShareCompat
                        );

               	huescache->Read(&hues, 3000*sizeof(THue));

                delete huescache;
                return huescrc32;
        }

        /*!
        \brief Paint the hues palette in the specified canvas
        \param C the canvas
        \param x x-dimension of the hue box
        \param y y-dimension of the hue box
        \param g gradient level
        */
        void PaintHues(TCanvas* C, int x, int y, int g)
        {
        	int X, Y;
        	for(int i = 0; i < 3000; i++)
                {
                	v2m(i, 60, X, Y);
                	TRect rect(X*x, Y*y, (X+1)*x, (Y+1)*y);
                        C->Brush->Color = Hues::ScaleColor(hues[i].colortable[g]);
                        C->FillRect(rect);
                }
        }

        /*!
        \brief Paint the gradient hue overview in the specified canvas
        \param hue the hue index
        \param C the canvas
        \param x x-dimension of the hue box
        \param y y-dimension of the hue box
        */
        void PaintHue(int hue, TCanvas* C, int x, int y)
        {
	        for(int i = 0; i < 32; i++)
        	{
	        	TRect rect(i*x, 0, i*x+x, y);
        	        C->Brush->Color = ScaleColor(hues[hue].colortable[i]);
			C->FillRect(rect);
        	}
        }

        /*!
        \brief get an hue name
        \param hue index of the hue
        \return the name of the hue
        */
        AnsiString GetName(int hue)
        {
                char name[21];
                strncpy(name, hues[hue].name, 20);
                name[20] = '\0';
        	return AnsiString(name);
        }

        /*!
        \brief set an hue name
        \param hindex the index of the hue
        \param name the name of the hue
        */
        void SetName(int hindex, AnsiString name)
        {
                strncpy(hues[hindex].name, name.c_str(), 20);
        }

        /*!
        \brief get an hues gradient
        \param hindex hue index
        \param gindex gradient index
        */
        WORD GetHue(int hindex, int gindex)
        {
                return hues[hindex].colortable[gindex];
        }

        /*!
        \brief change an hues gradient
        \param hue hue index
        \param g gradient index
        \param wColor the new gradient
        */
        void ChangeHue(int hue, int g, WORD wColor)
        {
                hues[hue].colortable[g] = wColor;
        }

        /*!
        \brief convert an hue to the equivalent 32bpp color
        \param wColor the hue
        \return the equivalent 32bpp color
        */
	TColor ScaleColor(WORD wColor)
	{
		DWORD dwNewColor;

		dwNewColor = ((((((wColor >> 10) & 0x01f) * 0x0ff / 0x01f))
			| (((((wColor >> 5) & 0x01f) * 0x0ff / 0x01f)) << 8)
			| ((((wColor & 0x01f) * 0x0ff / 0x01f)) << 16)));
		return TColor(dwNewColor);
	}

        /*!
        \brief Inverse function of Scalecolor, convert a 32bpp color into an hue
        \param dwColor the color
        \return the equivalent hue
        */
        WORD UnscaleColor(TColor dwColor)
        {
	        WORD wNewColor

        	= ( ( ( dwColor & 0xff ) /8) << 10 )
	        | ( ( ( (dwColor >> 8) & 0xff ) /8 ) << 5 )
        	| ( ( (dwColor >> 16) & 0xff ) /8 );

                return wNewColor;
        }

        /*!
        \brief Write an hues to hues.mul file
        \param hindex Hue Index
        \param uopath path to ultima online files
        */
        void WriteHue(int hindex, AnsiString uopath)
        {
                int offset =
                        (hindex/8)*sizeof(THueGroup) + // complete THueGroups preceding
                        4 + // Header
                        (hindex%8)*sizeof(THueGroup::THueMul);
                THueGroup::THueMul newhue;
                THue hue = hues[hindex];
                newhue.TableEnd = newhue.TableStart = 0; // unused ?
                strncpy(newhue.name, hue.name, 20);
                memcpy(&newhue.colortable, &hue.colortable, 32*2);
                TFileStream *ptrF = new TFileStream(uopath + "\\hues.mul", fmOpenReadWrite|fmShareCompat);
                ptrF->Seek(offset, soFromBeginning);
                ptrF->Write(&newhue, sizeof(newhue));
        }

};
