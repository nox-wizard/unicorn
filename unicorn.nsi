; software related
!define MUI_PRODUCT "Unicorn GM-Tools Suite"
!define MUI_VERSION "0.2"

; inclusione d'obbligo
!include "MUI.nsh"

; ----------------------------------------------------------------
; componenti
; ----------------------------------------------------------------
  !define MUI_LICENSEPAGE
;  !define MUI_COMPONENTSPAGE
  !define MUI_DIRECTORYPAGE
  !define MUI_STARTMENUPAGE
  
  !define MUI_FINISHPAGE
  !define MUI_FINISHPAGE_RUN "$INSTDIR\unicorn.exe"

  !define MUI_ABORTWARNING
  
  !define MUI_UNINSTALLER
  !define MUI_UNCONFIRMPAGE
  
  ;Modern UI System
  !insertmacro MUI_SYSTEM
  
; ----------------------------------------------------------------
; lingue
; ----------------------------------------------------------------
!insertmacro MUI_LANGUAGE "English"
!insertmacro MUI_LANGUAGE "Italian"

LangString DESC_basefiles ${LANG_ENGLISH} "Executable and library files needed to execute Unicorn"
LangString DESC_basefiles ${LANG_ITALIAN} "File eseguibili e di libreria necessari all'esecuzione di unicorn"

LangString DESC_rainbow $(LANG_ENGLISH) "Unicorn's Hues-Editor"
LangString DESC_rainbow $(LANG_ITALIAN) "L'editor Hues di Unicorn"

LangString DESC_calling $(LANG_ENGLISH) "Unicorn's Remote Console Client for NoX"
LangString DESC_calling $(LANG_ITALIAN) "Il client per la Remote Console di NoX di Unicorn"

; ----------------------------------------------------------------
; Dati generici
; ----------------------------------------------------------------
  LicenseData /LANG=${LANG_ENGLISH} "docs/license.txt"
  LicenseData /LANG=${LANG_ITALIAN} "docs/license.txt"
  OutFile "unicorn-suite.exe"
  InstallDir "$PROGRAMFILES\${MUI_PRODUCT}"
  !define TEMP $R0

Section "Unicorn" basefiles

  ; ----------------------------------------------------------------
  ; Files
  ; ----------------------------------------------------------------
  SetOutPath "$INSTDIR"
  CreateDirectory "$INSTDIR\mulcache"
  File "bin\unicorn.exe"        ; Unicorn Executable
  File "bin\unicorn.enu"        ; Unicorn English Resource DLL
  File "bin\uomap.ocx"          ; UOMap ActiveX
  File "bin\uoart.ocx"          ; UOArt ActiveX
  File "bin\borlandmm.dll"      ; runtime libraries
  File "bin\cc3260mt.dll"       ; runtime libraries                               

  File "docs\license.txt"       ; GPL
  File "docs\History.txt"       ; ChangeLog
  File "docs\TODO.txt"          ; TODO

  ; ----------------------------------------------------------------
  ; Menu avvio
  ; ----------------------------------------------------------------
  !insertmacro MUI_STARTMENU_WRITE_BEGIN
    CreateDirectory "$SMPROGRAMS\${MUI_STARTMENU_VARIABLE}"
    CreateShortCut "$SMPROGRAMS\${MUI_STARTMENU_VARIABLE}\Unicorn GM-Tool.lnk" "$INSTDIR\unicorn.exe"
    CreateShortCut "$SMPROGRAMS\${MUI_STARTMENU_VARIABLE}\Disinstalla.lnk" "$INSTDIR\Uninstall.exe"

  ; ----------------------------------------------------------------
  ; Registro di configurazione
  ; ----------------------------------------------------------------
  ;Write shortcut location to the registry (for Uninstaller)
  WriteRegStr HKCU "Software\${MUI_PRODUCT}" "Start Menu Folder" "${MUI_STARTMENU_VARIABLE}"
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
    CreateShortCut "$SMPROGRAMS\${MUI_STARTMENU_VARIABLE}\Rainbow.lnk" "$INSTDIR\rainbow.exe"
SectionEnd

Section "Calling" calling
  File "bin\Calling.exe"
  File "bin\Calling.enu"
  !insertmacro MUI_STARTMENU_WRITE_BEGIN
    CreateShortCut "$SMPROGRAMS\${MUI_STARTMENU_VARIABLE}\Calling.lnk" "$INSTDIR\Calling.exe"
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
  RMDir "$SMPROGRAMS\${TEMP}" ;Only if empty, so it won't delete other shortcuts
    
  noshortcuts:

  RMDir "$INSTDIR"
  
  DeleteRegValue HKCU "Software\${MUI_PRODUCT}" "Start Menu Folder"
  DeleteRegValue HKCU "Software\${MUI_PRODUCT}" "Installer Language"
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
  ;Language selection
  ;Font
  Push Tahoma
  Push 8
  ;Languages
  !insertmacro MUI_LANGDLL_PUSH "English"
  !insertmacro MUI_LANGDLL_PUSH "Italian"
  Push 2F ;2 = number of languages, F = change font
  LangDLL::LangDialog "Installer Language" "Please select a language."
  Pop $LANGUAGE
  StrCmp $LANGUAGE "cancel" 0 +2
    Abort
FunctionEnd

Function .onInstSuccess

  StrCmp $LANGUAGE "1040" Italian
    WriteRegStr HKCU "Software\Borland\Locales" "$INSTDIR\Unicorn.exe" "ENU"
  Italian:
FunctionEnd

Function un.onInit
  ;Get language from registry
  ReadRegStr $LANGUAGE HKCU "Software\${MUI_PRODUCT}" "Installer Language"
FunctionEnd
