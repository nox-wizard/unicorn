; software related
!define MUI_PRODUCT "Unicorn GM-Tools Suite"
!define MUI_VERSION "0.3.1"

; inclusione d'obbligo
!include "MUI.nsh"

SetCompressor bzip2

; ----------------------------------------------------------------
; componenti
; ----------------------------------------------------------------
  !define MUI_LICENSEPAGE
  !define MUI_COMPONENTSPAGE
  !define MUI_DIRECTORYPAGE
  !define MUI_STARTMENUPAGE

  !define MUI_FINISHPAGE
  !define MUI_FINISHPAGE_RUN "$INSTDIR\unicorn.exe"

  !define MUI_ABORTWARNING

  !define MUI_UNINSTALLER
  !define MUI_UNCONFIRMPAGE

; ----------------------------------------------------------------
; lingue
; ----------------------------------------------------------------
!insertmacro MUI_LANGUAGE "English"
!insertmacro MUI_LANGUAGE "Italian"

!include "ZipDLL.nsh"

LangString DESC_basefiles ${LANG_ENGLISH} "Executable and library files needed to execute Unicorn"
LangString DESC_basefiles ${LANG_ITALIAN} "File eseguibili e di libreria necessari all'esecuzione di unicorn"

LangString DESC_rainbow ${LANG_ENGLISH} "Unicorn's Hues-Editor"
LangString DESC_rainbow ${LANG_ITALIAN} "L'editor Hues di Unicorn"

LangString DESC_calling ${LANG_ENGLISH} "Unicorn's Remote Console Client for NoX"
LangString DESC_calling ${LANG_ITALIAN} "Il client per la Remote Console di NoX di Unicorn"

LangString DL_TITLE ${LANG_ENGLISH} "Download"
LangString DL_TITLE ${LANG_ITALIAN} "Scarico"

LangString DL_SUBTITLE ${LANG_ENGLISH} "Downloading runtime libraries"
LangString DL_SUBTITLE ${LANG_ITALIAN} "Sto scaricando le librerie runtime"


; ----------------------------------------------------------------
; Dati generici
; ----------------------------------------------------------------
  LicenseData /LANG=${LANG_ENGLISH} "docs/license.txt"
  LicenseData /LANG=${LANG_ITALIAN} "docs/license.txt"
  OutFile "unicorn-suite.exe"
  InstallDir "$PROGRAMFILES\${MUI_PRODUCT}"
  !define TEMP $R0

!insertmacro MUI_RESERVEFILE_LANGDLL

Section "-Unicorn" basefiles

  ; ----------------------------------------------------------------
  ; Files
  ; ----------------------------------------------------------------
  SetOutPath "$INSTDIR"
  CreateDirectory "$INSTDIR\mulcache"
  File "bin\unicorn.exe"        ; Unicorn Executable
  File "bin\unicorn.enu"        ; Unicorn English Resource DLL
  File "bin\uomap.ocx"          ; UOMap ActiveX
  File "bin\uoart.ocx"          ; UOArt ActiveX

  File "docs\license.txt"       ; GPL
  File "docs\History.txt"       ; ChangeLog
  File "docs\TODO.txt"          ; TODO

  ; ----------------------------------------------------------------
  ; Menu avvio
  ; ----------------------------------------------------------------
  !insertmacro MUI_STARTMENU_WRITE_BEGIN
    CreateDirectory "$SMPROGRAMS\${MUI_STARTMENUPAGE_VARIABLE}"
    CreateShortCut "$SMPROGRAMS\${MUI_STARTMENUPAGE_VARIABLE}\Unicorn GM-Tool.lnk" "$INSTDIR\unicorn.exe"
    CreateShortCut "$SMPROGRAMS\${MUI_STARTMENUPAGE_VARIABLE}\Disinstalla.lnk" "$INSTDIR\Uninstall.exe"

  ; ----------------------------------------------------------------
  ; Registro di configurazione
  ; ----------------------------------------------------------------
  ;Write shortcut location to the registry (for Uninstaller)
  WriteRegStr HKCU "Software\${MUI_PRODUCT}" "Start Menu Folder" "${MUI_STARTMENUPAGE_VARIABLE}"
  !insertmacro MUI_STARTMENU_WRITE_END

  ;Write language to the registry (for the uninstaller)
  WriteRegStr HKCU "Software\${MUI_PRODUCT}" "Installer Language" $LANGUAGE
  WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Unicorn" "DisplayIcon" "$INSTDIR\Unicorn.exe,0"
  WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Unicorn" "DisplayName" "Unicorn GM-Tool"
  WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Unicorn" "InstallLocation" "$INSTDIR"
  WriteRegStr HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Unicorn" "UninstallString" "$INSTDIR\Uninstall.exe"
  WriteRegDWORD HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Unicorn" "NoModify" 1
  WriteRegDWORD HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Unicorn" "NoRepair" 1


  ; ----------------------------------------------------------------
  ; Registrazione ocx
  ; ----------------------------------------------------------------
  RegDLL "$INSTDIR\uomap.ocx"
  RegDLL "$INSTDIR\uoart.ocx"

  WriteUninstaller "$INSTDIR\Uninstall.exe"
SectionEnd

Section "Rainbow" rainbow
  File "bin\rainbow.exe"
  File "bin\rainbow.enu"
  !insertmacro MUI_STARTMENU_WRITE_BEGIN
    CreateShortCut "$SMPROGRAMS\${MUI_STARTMENUPAGE_VARIABLE}\Rainbow.lnk" "$INSTDIR\rainbow.exe"
  !insertmacro MUI_STARTMENU_WRITE_END
SectionEnd

Section "Calling" calling
  File "bin\Calling.exe"
  File "bin\Calling.enu"
  !insertmacro MUI_STARTMENU_WRITE_BEGIN
    CreateShortCut "$SMPROGRAMS\${MUI_STARTMENUPAGE_VARIABLE}\Calling.lnk" "$INSTDIR\Calling.exe"
  !insertmacro MUI_STARTMENU_WRITE_END
SectionEnd

Section "Uninstall"

  UnRegDLL "$INSTDIR\uomap.ocx"
  UnRegDLL "$INSTDIR\uoart.ocx"

  Delete "$INSTDIR\unicorn.exe"
  Delete "$INSTDIR\unicorn.enu"

  Delete "$INSTDIR\rainbow.exe"
  Delete "$INSTDIR\rainbow.enu"

  Delete "$INSTDIR\calling.exe"
  Delete "$INSTDIR\calling.enu"

  Delete "$INSTDIR\license.txt"
  Delete "$INSTDIR\History.txt"

  Delete "$INSTDIR\Uninstall.exe"
  Delete "$INSTDIR\uomap.ocx"
  Delete "$INSTDIR\uoart.ocx"

  Delete "$INSTDIR\mulcache\*.uni"

  RMDir "$INSTDIR\mulcache"
  
  ;Remove shortcut
  ReadRegStr ${TEMP} HKCU "Software\${MUI_PRODUCT}" "Start Menu Folder"

  StrCmp ${TEMP} "" noshortcuts

  Delete "$SMPROGRAMS\${TEMP}\Unicorn GM-Tool.lnk"
  Delete "$SMPROGRAMS\${TEMP}\Disinstalla.lnk"
  Delete "$SMPROGRAMS\${TEMP}\Rainbow.lnk"
  Delete "$SMPROGRAMS\${TEMP}\Calling.lnk"
  RMDir "$SMPROGRAMS\${TEMP}" ;Only if empty, so it won't delete other shortcuts

  noshortcuts:

  RMDir "$INSTDIR"

  DeleteRegValue HKCU "Software\${MUI_PRODUCT}" "Start Menu Folder"
  DeleteRegValue HKCU "Software\${MUI_PRODUCT}" "Installer Language"
  DeleteRegValue HKCU "Software\Borland\Locales" "$INSTDIR\Unicorn.exe"
  DeleteRegValue HKCU "Software\Borland\Locales" "$INSTDIR\rainbow.exe"
  DeleteRegValue HKCU "Software\Borland\Locales" "$INSTDIR\Calling.exe"
  DeleteRegKey HKLM "SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\Unicorn"

  ;Display the Finish header
  !insertmacro MUI_UNFINISHHEADER

SectionEnd

!insertmacro MUI_FUNCTIONS_DESCRIPTION_BEGIN
  !insertmacro MUI_DESCRIPTION_TEXT ${basefiles} $(DESC_basefiles)
  !insertmacro MUI_DESCRIPTION_TEXT $(rainbow) $(DESC_rainbow)
  !insertmacro MUI_DESCRIPTION_TEXT $(calling) $(DESC_calling)
!insertmacro MUI_FUNCTIONS_DESCRIPTION_END

Function .onInit
  Banner::show /NOUNLOAD "Downloading runtime libraries..."
    IfFileExists "$SYSDIR\stlpmt45.dll" nodownload_stlpmt download_stlpmt

    download_stlpmt:
      NSISdl::download http://flameeyes.web.ctonet.it/bcb-rtl/stlpmt45.zip "$TEMP\stlpmt45.zip"
        Pop $R0 ;Get the return value
        StrCmp $R0 "success" +4
          MessageBox MB_OK "Download failed: $R0."
	  Delete "$SYSDIR\stlpmt45.dll"
          Quit
	!insertmacro MUI_ZIPDLL_EXTRACTALL "$TEMP\stlpmt45.zip" "$SYSDIR"

    nodownload_stlpmt:
    IfFileExists "$SYSDIR\borlndmm.dll" nodownload_borlndmm download_borlndmm

    download_borlndmm:
      NSISdl::download http://flameeyes.web.ctonet.it/bcb-rtl/borlndmm.zip "$TEMP\borlndmm.zip"
        Pop $R0 ;Get the return value
        StrCmp $R0 "success" +4
          MessageBox MB_OK "Download failed: $R0."
	  Delete "$SYSDIR\borlndmm.dll"
          Quit
	!insertmacro MUI_ZIPDLL_EXTRACTALL "$TEMP\borlndmm.zip" "$SYSDIR"

    nodownload_borlndmm:
    IfFileExists "$SYSDIR\cc3260mt.dll" nodownload_cc3260mt download_cc3260mt

    download_cc3260mt:
      NSISdl::download http://flameeyes.web.ctonet.it/bcb-rtl/cc3260mt.zip "$TEMP\cc3260mt.zip"
        Pop $R0 ;Get the return value
        StrCmp $R0 "success" +4
          MessageBox MB_OK "Download failed: $R0."
	  Delete "$SYSDIR\borlndmm.dll"
          Quit
	!insertmacro MUI_ZIPDLL_EXTRACTALL "$TEMP\cc3260.zip" "$SYSDIR"

    nodownload_cc3260mt:

  Banner::destroy
  !insertmacro MUI_LANGDLL_DISPLAY
FunctionEnd

Function .onInstSuccess

  StrCmp $LANGUAGE "1040" Italian
    WriteRegStr HKCU "Software\Borland\Locales" "$INSTDIR\Unicorn.exe" "ENU"
    WriteRegStr HKCU "Software\Borland\Locales" "$INSTDIR\rainbow.exe" "ENU"
    WriteRegStr HKCU "Software\Borland\Locales" "$INSTDIR\Calling.exe" "ENU"
  Italian:
FunctionEnd

Function un.onInit
  ;Get language from registry
  ReadRegStr $LANGUAGE HKCU "Software\${MUI_PRODUCT}" "Installer Language"
FunctionEnd
