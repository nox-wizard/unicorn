//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("MainUnit.cpp", MainForm);
USEFORM("SplashUnit.cpp", SplashForm);
USEFORM("FileUnit.cpp", FileForm);
USEFORM("HuesUnit.cpp", PaletteForm);
USEFORM("LocationEditUnit.cpp", LocationEdit);
USEFORM("ObjectEditUnit.cpp", ObjectEditForm);
USEFORM("ParamsUnit.cpp", ParamsForm);
USEFORM("ProgressUnit.cpp", ProgressForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "Unicorn GM-Tool";
                 Application->CreateForm(__classid(TMainForm), &MainForm);
                 Application->CreateForm(__classid(TSplashForm), &SplashForm);
                 Application->CreateForm(__classid(TFileForm), &FileForm);
                 Application->CreateForm(__classid(TPaletteForm), &PaletteForm);
                 Application->CreateForm(__classid(TLocationEdit), &LocationEdit);
                 Application->CreateForm(__classid(TObjectEditForm), &ObjectEditForm);
                 Application->CreateForm(__classid(TParamsForm), &ParamsForm);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------




