//---------------------------------------------------------------------------

#ifndef XSSParseUnitH
#define XSSParseUnitH
// STL
#include <map>
#include <fstream>
#include <string>
// VCL
#include <System.hpp>
#include <oxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
#include <msxmldom.hpp>

class TXSSParser
{
	private:
		struct titem
		{
                	AnsiString addid;
			AnsiString name;
                        AnsiString name2;
		        AnsiString id;
		        AnsiString color;
		        AnsiString category;
		        AnsiString subsection;
		        AnsiString description;
		};

                struct tchar
                {
                	AnsiString addid;
                	AnsiString name;
                        AnsiString id;
                        AnsiString color;
                        AnsiString category;
                        AnsiString subsection;
                        AnsiString description;
                };

                struct tdefault
                {
                        AnsiString name;
                        AnsiString name2;
                        AnsiString id;
                        AnsiString color;
                        AnsiString category;
                        AnsiString subsection;
                        AnsiString description;
                };

		typedef std::map<AnsiString, int> t_defined;
		typedef std::map<AnsiString, tdefault> t_defaults;

	public:
        	TXSSParser(
                	AnsiString	fn,
                        AnsiString	nxwpath,
                        IXMLNode	*CHARS,
                        IXMLNode	*ITEMS,
                	bool		c73
                        );

        	TXSSParser(AnsiString fn);

                void Parse();

        private:
        	static IXMLNode *chars;
                static IXMLNode *items;

                static titem Item;
                static tchar Char;

                static t_defaults defaults;
                static t_defined defined;

                std::ifstream file;

                static char buffer[];
                static int istanze;
                static char *riga;
                static bool compat73;
                bool destroybuf;
                AnsiString noxpath;

                void ParseNewLine();
		void RemoveSpaces();
                void ParseItem();
                void ParseChar();
                void ParseDefault(AnsiString code);
                void IgnoreSection();
                void ClearStructs();
};

//---------------------------------------------------------------------------
#endif
