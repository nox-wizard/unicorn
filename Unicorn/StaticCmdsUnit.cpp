//---------------------------------------------------------------------------
#include "StaticCmdsUnit.h"
#include "MainUnit.h"
#include "stringhe.hpp"
#pragma hdrstop
#pragma package(smart_init)
//---------------------------------------------------------------------------

void __fastcall TMainForm::RemoveCmdClick(TObject *Sender)
{
	SendCommand("remove");	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::InvulCmdClick(TObject *Sender)
{
	SendCommand("invul");	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::NoInvulCmdClick(TObject *Sender)
{
	SendCommand("noinvul");	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::HideCmdClick(TObject *Sender)
{
	SendCommand("hide");	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::UnHideCmdClick(TObject *Sender)
{
	SendCommand("unhide");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MakeGMCmdClick(TObject *Sender)
{
	SendCommand("makegm");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MakeCNSCmdClick(TObject *Sender)
{
	SendCommand("makecns");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SendCmdClick(TObject *Sender)
{
	short x, y, z;
        Mappa->GetCenter(&x, &y);
	SendCommand( Caption.sprintf( "xgo %d %d %d", x, y, newz->Text.ToInt() ) );
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SetMOREXYZCmdClick(TObject *Sender)
{
	short x, y, z;
        Mappa->GetCenter(&x, &y);
	SendCommand( Caption.sprintf( "setmorexyz %d %d %d", x, y, newz->Text.ToInt() ) );
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::GoCmdClick(TObject *Sender)
{
	short x, y, z;
        Mappa->GetCenter(&x, &y);
	SendCommand( Caption.sprintf( "go %d %d %d", x, y, newz->Text.ToInt() ) );
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AddItemCmdClick(TObject *Sender)
{
	SendCommand( "additem " + itemid->Text );	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::AddCharCmdClick(TObject *Sender)
{
	SendCommand( "addnpc " + charid->Text );
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DryCmdClick(TObject *Sender)
{
	SendCommand( "dry" );
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SnowCmdClick(TObject *Sender)
{
	SendCommand( "snow" );
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RainCmdClick(TObject *Sender)
{
	SendCommand( "rain" );
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SetSeasonCmdClick(TObject *Sender)
{
	if ( Seasons->ItemIndex != -1 )
        	SendCommand( Caption.sprintf("setseason %d", Seasons->ItemIndex) );
        else
        	Errors::ThrowError(
                	Stringhe_cmd_NotSelectedSeason,
                        Errors::ehNonFatal,
                        MB_OK
                	);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::EclipseCmdClick(TObject *Sender)
{
	SendCommand( "eclipse" );
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FreezeCmdClick(TObject *Sender)
{
	SendCommand( "freeze" );
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::UnfreezeCmdClick(TObject *Sender)
{
	SendCommand( "unfreeze" );
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetAmountCmdClick(TObject *Sender)
{
	SendCommand( "setamount " + Value->Text );
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SetMoreXCmdClick(TObject *Sender)
{
	SendCommand( "setmorex " + Value->Text );
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SetMoreYCmdClick(TObject *Sender)
{
	SendCommand( "setmorey " + Value->Text );
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SetMoreZCmdClick(TObject *Sender)
{
	SendCommand( "setmorez " + Value->Text );
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SetMoreXYZCmd2Click(TObject *Sender)
{
	SendCommand( "setmorexyz " + Value->Text );
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SetHexMoreXYZCmdClick(TObject *Sender)
{
	SendCommand( "sethexmorexyz " + Value->Text );
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SetTypeCmdClick(TObject *Sender)
{
	SendCommand( "settype " + Value->Text );
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SetMoreCmdClick(TObject *Sender)
{
	SendCommand( "setmore " + Value->Text );
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SetNPCAICmdClick(TObject *Sender)
{
	SendCommand( "setnpcai " + Value->Text );
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SetFontCmdClick(TObject *Sender)
{
	SendCommand( "setfont " + Value->Text );
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::KillCmdClick(TObject *Sender)
{
	SendCommand("kill");	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ResurrectCmdClick(TObject *Sender)
{
	SendCommand("resurrect");	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RefreshCmdClick(TObject *Sender)
{
	SendCommand("refresh");	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::SetSkillBtnClick(TObject *Sender)
{
	SendCommand("set " + SkillList->Items->Strings[SkillList->ItemIndex] + " " + Value->Text );
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SetSTRBtnClick(TObject *Sender)
{
	SendCommand("set str " + Value->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SetINTBtnClick(TObject *Sender)
{
	SendCommand("set int " + Value->Text);	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SetDEXBtnClick(TObject *Sender)
{
	SendCommand("set dex " + Value->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SetStaminaBtnClick(TObject *Sender)
{
	SendCommand("stamina " + Value->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SetManaBtnClick(TObject *Sender)
{
	SendCommand("mana " + Value->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ZeroKillsCmdClick(TObject *Sender)
{
	SendCommand("zerokills");	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::JailCmdClick(TObject *Sender)
{
	SendCommand("jail");	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ReleaseCmdClick(TObject *Sender)
{
	SendCommand("Release");	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ShowIDsCmdClick(TObject *Sender)
{
	SendCommand("showids");	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BankCmdClick(TObject *Sender)
{
	SendCommand("xbank");	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SBankCmdClick(TObject *Sender)
{
	SendCommand("xsbank");	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SetXCmdClick(TObject *Sender)
{
	SendCommand("newx " + Value->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SetYCmdClick(TObject *Sender)
{
	SendCommand("newy " + Value->Text);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SetZCmdClick(TObject *Sender)
{
	SendCommand("newz " + Value->Text);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DupeCmdClick(TObject *Sender)
{
	SendCommand("dupe");	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SaveCmdClick(TObject *Sender)
{
	SendCommand("save");	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AllMoveOnCmdClick(TObject *Sender)
{
	SendCommand("allmoveon");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AllMoveOffCmdClick(TObject *Sender)
{
	SendCommand("allmoveoff");	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::GuardsOnCmdClick(TObject *Sender)
{
	SendCommand("guardson");	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::GuardsOffCmdClick(TObject *Sender)
{
	SendCommand("guardsoff");	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AnnounceOnCmdClick(TObject *Sender)
{
	SendCommand("announceon");	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AnnounceOffCmdClick(TObject *Sender)
{
	SendCommand("announceoff");	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::GMsCmdClick(TObject *Sender)
{
	SendCommand("gms");	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::PdumpCmdClick(TObject *Sender)
{
	SendCommand("pdump");	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ReloadScriptCmdClick(TObject *Sender)
{
	SendCommand("reloadcachedscripts");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ShowPriv3CmdClick(TObject *Sender)
{
	SendCommand("showpriv3");	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::DisconnectCmdClick(TObject *Sender)
{
	SendCommand("disconnect");	
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::KickCmdClick(TObject *Sender)
{
	SendCommand("kick");	
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::WholistCmdClick(TObject *Sender)
{
	SendCommand( "wholist" );
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PlayerListCmdClick(TObject *Sender)
{
	SendCommand( "pl" );
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::OfflistCmdClick(TObject *Sender)
{
	SendCommand( "offlist" );
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ReloadServerCmdClick(TObject *Sender)
{
	SendCommand("reloadserver");	
}
//---------------------------------------------------------------------------

