//---------------------------------------------------------------------------


#pragma hdrstop

#include "XSSParseUnit.h"
#include <cstring>
#include <locale>
#include <cstdlib>
//---------------------------------------------------------------------------

#pragma package(smart_init)

TXSSParser::TXSSParser(AnsiString fn, AnsiString nxwpath, IXMLNode *CHARS, IXMLNode *ITEMS, bool c73)
{
        filename = ExtractFileName(fn);
	compat73 = c73;
	chars = CHARS;
        items = ITEMS;
        file.open(fn.c_str());
        noxpath = nxwpath;
        istanze++;
}

TXSSParser::TXSSParser(AnsiString fn)
{
        filename = ExtractFileName(fn);
        file.open(fn.c_str());
}

void TXSSParser::Parse()
{
        while(file)
        {
        	file.getline(buffer, 256);
                RemoveSpaces();
                if ( ! std::strlen(riga) )
                	continue;
                ParseNewLine();
        }

}

void TXSSParser::RemoveSpaces()
{
	riga = buffer;
	while ( std::isspace(*riga) )
        	riga++;
}

void TXSSParser::ParseNewLine()
{
	if ( !std::strncmpi(riga, "//", 2) )
        	return;
        if ( !std::strncmpi(riga, "#define", 7 ) )
	{
        	char *p = riga+7;
                char *s;
                while( std::isspace(*p) )
                	p++;
                s = p;
                while( ! std::isspace(*p) )
                	p++;
                *p = '\0';
                p++;
                defined.insert( t_defined::value_type( AnsiString(s), std::atoi(p) ) );
        }
        else if ( !std::strncmpi(riga, "#include", 8 ) )
        {
        	char *p = riga+8;
                while( std::isspace(*p) )
                	p++;

                char *t;
                while( t = strchr(p, '/') )
                	*t = '\\';

                TXSSParser *subparse = new TXSSParser(noxpath + "\\" + AnsiString(p) );
                subparse->Parse();
        }
        else if ( !std::strncmpi(riga, "SECTION", 7 ) )
        {
        	char *p = riga+7;
                char *s;
                while( std::isspace(*p) )
                	p++;
                if ( !std::strncmpi(p, "ITEMLIST", 8 ) )
                	IgnoreSection();
                if ( !std::strncmpi(p, "NPCLIST", 7 ) )
                	IgnoreSection();
                if ( !std::strncmpi(p, "ITEM", 4 ) )
                {
                	p += 4;
                	while( std::isspace(*p) ) p++;

                        Item.addid = p;
                        ParseItem();
                }
                else if ( !std::strncmpi(p, "NPC", 3 ) )
                {
                	p += 3;
                	while( std::isspace(*p) ) p++;

                        Char.addid = p;
                        ParseChar();
                }
                else if ( !std::strncmpi(p, "DEFAULT", 7 ) )
                {
                	p += 7;
                	while( std::isspace(*p) ) p++;

                        ParseDefault(AnsiString(p));
                }
                else
                {
                	IgnoreSection();
                	return;
                }
        }
        else
        	return;
}

void TXSSParser::IgnoreSection()
{
        while(*riga != '}')
        {
                file.getline(buffer, 255);
        	RemoveSpaces();
        }
}

void TXSSParser::ParseItem()
{
	while(1)
        {
                file.getline(buffer, 255);
                RemoveSpaces();

        	if ( *riga == '}' )
                	break;

                if ( !strncmpi(riga, "NAME2", 5) )
                {
                	char *p = riga+5;
                        while ( std::isspace(*p) ) p++;
                        Item.name2 = p;
                }
                else if ( !strncmpi(riga, "NAME", 4) )
                {
                	char *p = riga+4;
                        while ( std::isspace(*p) ) p++;
                        Item.name = p;
                }
                else if ( ! strncmpi(riga, "ID", 2) )
                {
                	char *p = riga+2;
                        while ( std::isspace(*p) ) p++;
                        Item.id = p;
                }
                else if ( ! strncmpi(riga, "COLOR", 5) )
                {
                	char *p = riga+5;
                        while ( std::isspace(*p) ) p++;
                        Item.color = p;
                }
                else if ( ! strncmpi(riga, "///CATEGORY", 11) )
                {
                	char *p = riga+11;
                        while ( std::isspace(*p) ) p++;
                        Item.category = p;
                }
                else if ( ! strncmpi(riga, "///SUBSECTION", 13) )
                {
                	char *p = riga+13;
                        while ( std::isspace(*p) ) p++;
                        Item.subsection = p;
                }
                else if ( ! strncmpi(riga, "///DESCRIPTION", 14) )
                {
                	char *p = riga+14;
                        while ( std::isspace(*p) ) p++;
                        Item.description = p;
                }
                else if ( ! strncmpi(riga, "///NOTLIST", 7) )
                {
                	ClearStructs();
                        IgnoreSection();
                        return;
                }
                else if ( ! strncmp(riga, "#copy", 5) )
                {
                	char *p = riga+5;
                        while ( std::isspace(*p) ) p++;

                        tdefault temp;

                        if ( defaults.count(AnsiString(p)) )
                        	temp = defaults[AnsiString(p)];
                        else
                        	continue;

                        Item.color = temp.color.IsEmpty() ? Item.color : temp.color;
                        Item.category = temp.category.IsEmpty() ? Item.category : temp.category;
                        Item.description = temp.description.IsEmpty() ? Item.description : temp.description;
                        Item.subsection = temp.subsection.IsEmpty() ? Item.subsection : temp.subsection;
                        Item.id = temp.id.IsEmpty() ? Item.id : temp.id;
                        Item.name = temp.name.IsEmpty() ? Item.name : temp.name;
                        Item.name2 = temp.name2.IsEmpty() ? Item.name2 : temp.name2;
                }
        }

        if ( defined.count(Item.color) )
                Item.color = defined[Item.color];
        if ( defined.count(Item.id) )
                Item.color = defined[Item.id];
        if ( compat73 && defined.count(Item.addid) )
        	Item.addid = defined[Item.addid];                       

        _di_IXMLNode tnode = items->AddChild("category");
        tnode->Attributes["name"] = ( Item.category.IsEmpty() ? filename : Item.category );
        tnode = tnode->AddChild("subsection");
        tnode->Attributes["name"] = ( Item.subsection.IsEmpty() ? filename : Item.subsection );
        tnode = tnode->AddChild("item");
        tnode->Attributes["name"] = ( Item.description.IsEmpty() ? ( Item.name2.IsEmpty() ? Item.name : Item.name2 ) : Item.description );
        tnode->Attributes["addid"] = Item.addid;
        tnode->Attributes["color"] = Item.color;
        tnode->Attributes["id"] = Item.id;

        ClearStructs();

}

void TXSSParser::ParseChar()
{
	while(file)
        {
                file.getline(buffer, 255);
                RemoveSpaces();

        	if ( *riga == '}' )
                	break;

                if ( !strncmpi(riga, "NAME", 4) )
                {
                	char *p = riga+4;
                        while ( std::isspace(*p) ) p++;
                        Char.name = p;
                }
                else if ( ! strncmpi(riga, "ID", 2) )
                {
                	char *p = riga+2;
                        while ( std::isspace(*p) ) p++;
                        Char.id = p;
                }
                else if ( ! strncmpi(riga, "COLOR", 5) )
                {
                	char *p = riga+5;
                        while ( std::isspace(*p) ) p++;
                        Char.color = p;
                }
                else if ( ! strncmpi(riga, "///CATEGORY", 11) )
                {
                	char *p = riga+11;
                        while ( std::isspace(*p) ) p++;
                        Char.category = p;
                }
                else if ( ! strncmpi(riga, "///SUBSECTION", 13) )
                {
                	char *p = riga+13;
                        while ( std::isspace(*p) ) p++;
                        Char.subsection = p;
                }
                else if ( ! strncmpi(riga, "///DESCRIPTION", 14) )
                {
                	char *p = riga+14;
                        while ( std::isspace(*p) ) p++;
                        Char.description = p;
                }
                else if ( ! strncmpi(riga, "///NOTLIST", 10) )
                {
                	ClearStructs();
                        IgnoreSection();
                        return;
                }
                else if ( ! strncmp(riga, "#copy", 5) )
                {
                	char *p = riga+5;
                        while ( std::isspace(*p) ) p++;

                        tdefault temp;

                        if ( defaults.count(AnsiString(p)) )
                        	temp = defaults[AnsiString(p)];
                        else
                        	continue;

                        Char.color = temp.color.IsEmpty() ? Char.color : temp.color;
                        Char.category = temp.category.IsEmpty() ? Char.category : temp.category;
                        Char.description = temp.description.IsEmpty() ? Char.description : temp.description;
                        Char.subsection = temp.subsection.IsEmpty() ? Char.subsection : temp.subsection;
                        Char.id = temp.id.IsEmpty() ? Char.id : temp.id;
                        Char.name = temp.name.IsEmpty() ? Char.name : temp.name;
                        // Char.name2 = temp.name2.IsEmpty() ? Char.name2 : temp.name2;
                }
        }

        if ( defined.count(Char.color) )
                Char.color = defined[Char.color];
        if ( defined.count(Char.id) )
                Char.color = defined[Char.id];
        if ( compat73 && defined.count(Char.addid) )
        	Item.addid = defined[Char.addid];

        _di_IXMLNode tnode = chars->AddChild("category");
        tnode->Attributes["name"] = ( Char.category.IsEmpty() ? filename : Char.category );
        tnode = tnode->AddChild("subsection");
        tnode->Attributes["name"] = ( Char.subsection.IsEmpty() ? filename : Char.subsection );
        tnode = tnode->AddChild("char");
        tnode->Attributes["name"] = ( Char.description.IsEmpty() ? Char.name : Char.description );
        tnode->Attributes["addid"] = Char.addid;
        tnode->Attributes["color"] = Char.color;
        tnode->Attributes["id"] = Char.id;

        ClearStructs();

}

void TXSSParser::ParseDefault(AnsiString code)
{
	tdefault temp;
        temp.category = "";
        temp.color = "";
        temp.description = "";
        temp.id = "";
        temp.name = "";
        temp.name2 = "";
        temp.subsection = "";
	while(1)
        {
                file.getline(buffer, 255);
                RemoveSpaces();

        	if ( *riga == '}' )
                	break;

                if ( !strncmpi(riga, "NAME2", 5) )
                {
                	char *p = riga+5;
                        while ( std::isspace(*p) ) p++;
                        temp.name2 = p;
                }
                if ( !strncmpi(riga, "NAME", 4) )
                {
                	char *p = riga+4;
                        while ( std::isspace(*p) ) p++;
                        temp.name = p;
                }
                else if ( ! strncmpi(riga, "ID", 2) )
                {
                	char *p = riga+2;
                        while ( std::isspace(*p) ) p++;
                        temp.id = p;
                }
                else if ( ! strncmpi(riga, "COLOR", 5) )
                {
                	char *p = riga+5;
                        while ( std::isspace(*p) ) p++;
                        temp.color = p;
                }
                else if ( ! strncmpi(riga, "///CATEGORY", 11) )
                {
                	char *p = riga+5;
                        while ( std::isspace(*p) ) p++;
                        temp.category = p;
                }
                else if ( ! strncmpi(riga, "///SUBSECTION", 13) )
                {
                	char *p = riga+5;
                        while ( std::isspace(*p) ) p++;
                        temp.subsection = p;
                }
                else if ( ! strncmpi(riga, "///DESCRIPTION", 14) )
                {
                	char *p = riga+5;
                        while ( std::isspace(*p) ) p++;
                        temp.description = p;
                }
                else if ( ! strncmp(riga, "#copy", 5) )
                {
                	char *p = riga+5;
                        while ( std::isspace(*p) ) p++;

                        tdefault temp2;

                        if ( defaults.count(AnsiString(p)) )
                        	temp2 = defaults[AnsiString(p)];
                        else
                        	continue;

                        temp.color = temp2.color.IsEmpty() ? temp.color : temp2.color;
                        temp.category = temp2.category.IsEmpty() ? temp.category : temp2.category;
                        temp.description = temp2.description.IsEmpty() ? temp.description : temp2.description;
                        temp.subsection = temp2.subsection.IsEmpty() ? temp.subsection : temp2.subsection;
                        temp.id = temp2.id.IsEmpty() ? temp.id : temp2.id;
                        temp.name = temp2.name.IsEmpty() ? temp.name : temp2.name;
                }
        }

        if ( defined.count(temp.color) )
                temp.color = defined[temp.color];
        if ( defined.count(Char.id) )
                temp.color = defined[temp.id];

        defaults.insert( t_defaults::value_type( AnsiString(code), temp ) );

}

void TXSSParser::ClearStructs()
{
	Item.addid = "";
        Item.category = "";
        Item.color = "";
        Item.description = "";
        Item.id = "";
        Item.name = "";
        Item.name2 = "";
        Item.subsection = "";

	Char.addid = "";
        Char.category = "";
        Char.color = "";
        Char.description = "";
        Char.id = "";
        Char.name = "";
        Char.subsection = "";

}

char TXSSParser::buffer[256];
char *TXSSParser::riga = buffer;
TXSSParser::t_defined TXSSParser::defined;
TXSSParser::t_defaults TXSSParser::defaults;
TXSSParser::titem TXSSParser::Item;
TXSSParser::tchar TXSSParser::Char;
IXMLNode *TXSSParser::chars;
IXMLNode *TXSSParser::items;
int TXSSParser::istanze = 0;
bool TXSSParser::compat73 = false;

