object MainForm: TMainForm
  Left = 216
  Top = 561
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Unicorn'
  ClientHeight = 221
  ClientWidth = 764
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCloseQuery = FormCloseQuery
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Pager: TPageControl
    Left = 0
    Top = 0
    Width = 764
    Height = 221
    ActivePage = s
    Align = alClient
    PopupMenu = CharsPopup
    TabIndex = 7
    TabOrder = 0
    object LauncherTab: TTabSheet
      Caption = 'Partenza'
      ImageIndex = 2
      object Label9: TLabel
        Left = 448
        Top = 0
        Width = 80
        Height = 13
        Caption = 'Files da sostituire'
      end
      object GroupBox5: TGroupBox
        Left = 144
        Top = 0
        Width = 297
        Height = 193
        Caption = 'Informazioni...'
        TabOrder = 0
        object Label3: TLabel
          Left = 8
          Top = 16
          Width = 92
          Height = 13
          Caption = 'Nome Connessione'
        end
        object Label4: TLabel
          Left = 8
          Top = 48
          Width = 47
          Height = 13
          Caption = 'Server: IP'
        end
        object Label5: TLabel
          Left = 160
          Top = 48
          Width = 25
          Height = 13
          Caption = 'Porta'
        end
        object Label6: TLabel
          Left = 8
          Top = 80
          Width = 71
          Height = 13
          Caption = 'Nome Account'
        end
        object Label7: TLabel
          Left = 168
          Top = 80
          Width = 46
          Height = 13
          Caption = 'Password'
        end
        object Label8: TLabel
          Left = 8
          Top = 112
          Width = 26
          Height = 13
          Caption = 'Client'
        end
        object EntryName: TEdit
          Left = 112
          Top = 16
          Width = 121
          Height = 21
          Enabled = False
          TabOrder = 0
        end
        object ServerIP: TEdit
          Left = 64
          Top = 48
          Width = 89
          Height = 21
          Enabled = False
          MaxLength = 15
          TabOrder = 1
        end
        object ServerPort: TEdit
          Left = 192
          Top = 48
          Width = 41
          Height = 21
          Enabled = False
          MaxLength = 5
          TabOrder = 2
        end
        object AccountName: TEdit
          Left = 88
          Top = 80
          Width = 73
          Height = 21
          Enabled = False
          TabOrder = 3
        end
        object AccountPassword: TEdit
          Left = 224
          Top = 80
          Width = 65
          Height = 21
          Enabled = False
          TabOrder = 4
        end
        object ClientPath: TEdit
          Left = 40
          Top = 112
          Width = 177
          Height = 21
          Enabled = False
          TabOrder = 5
        end
        object BrowseClient: TButton
          Left = 224
          Top = 112
          Width = 67
          Height = 25
          Caption = 'Sfoglia...'
          Enabled = False
          TabOrder = 6
          OnClick = BrowseClientClick
        end
        object EditBtn: TButton
          Left = 8
          Top = 144
          Width = 75
          Height = 25
          Caption = 'Modifica'
          Enabled = False
          TabOrder = 7
          OnClick = EditBtnClick
        end
        object OKBtn: TButton
          Left = 128
          Top = 144
          Width = 75
          Height = 25
          Caption = 'OK'
          Enabled = False
          TabOrder = 8
          OnClick = OKBtnClick
        end
        object CancelBtn: TButton
          Left = 208
          Top = 144
          Width = 75
          Height = 25
          Caption = 'Annulla'
          Enabled = False
          TabOrder = 9
          OnClick = CancelBtnClick
        end
        object LaunchBtn: TButton
          Left = 240
          Top = 16
          Width = 49
          Height = 57
          Caption = 'Lancia'
          Enabled = False
          TabOrder = 10
          OnClick = LaunchBtnClick
        end
      end
      object ClientList: TListBox
        Left = 0
        Top = 0
        Width = 137
        Height = 169
        ItemHeight = 13
        TabOrder = 1
        OnClick = ClientListClick
      end
      object AddBtn: TButton
        Left = 0
        Top = 168
        Width = 65
        Height = 25
        Caption = 'Aggiungi'
        TabOrder = 2
        OnClick = AddBtnClick
      end
      object RemoveBtn: TButton
        Left = 64
        Top = 168
        Width = 65
        Height = 25
        Caption = 'Rimuovi'
        TabOrder = 3
        OnClick = RemoveBtnClick
      end
      object FileList: TListBox
        Left = 448
        Top = 16
        Width = 153
        Height = 153
        Enabled = False
        ItemHeight = 13
        TabOrder = 4
      end
      object AddFileBtn: TButton
        Left = 448
        Top = 168
        Width = 73
        Height = 25
        Caption = 'Aggiungi'
        Enabled = False
        TabOrder = 5
        OnClick = AddFileBtnClick
      end
      object RemoveFileBtn: TButton
        Left = 528
        Top = 168
        Width = 73
        Height = 25
        Caption = 'Rimuovi'
        Enabled = False
        TabOrder = 6
        OnClick = RemoveFileBtnClick
      end
    end
    object TravelTab: TTabSheet
      Caption = 'Viaggio'
      OnShow = TravelTabShow
      object GroupBox2: TGroupBox
        Left = 320
        Top = 0
        Width = 73
        Height = 73
        Caption = 'Comandi'
        TabOrder = 0
        object GoCmd: TButton
          Left = 8
          Top = 16
          Width = 57
          Height = 17
          Caption = 'Vai'
          TabOrder = 0
          OnClick = GoCmdClick
        end
        object SendCmd: TButton
          Left = 8
          Top = 32
          Width = 57
          Height = 17
          Caption = 'Invia'
          TabOrder = 1
          OnClick = SendCmdClick
        end
        object SetMOREXYZCmd: TButton
          Left = 8
          Top = 48
          Width = 57
          Height = 17
          Caption = 'MOREXYZ'
          TabOrder = 2
          OnClick = SetMOREXYZCmdClick
        end
      end
      object GroupBox3: TGroupBox
        Left = 392
        Top = 144
        Width = 169
        Height = 49
        Caption = 'Coordinate'
        TabOrder = 1
        object newy: TEdit
          Left = 48
          Top = 20
          Width = 33
          Height = 21
          MaxLength = 4
          TabOrder = 0
        end
        object newx: TEdit
          Left = 8
          Top = 20
          Width = 33
          Height = 21
          MaxLength = 4
          TabOrder = 1
        end
        object VaiBtn: TButton
          Left = 128
          Top = 16
          Width = 33
          Height = 25
          Caption = 'Vai'
          TabOrder = 2
          OnClick = VaiBtnClick
        end
        object newz: TEdit
          Left = 88
          Top = 20
          Width = 33
          Height = 21
          MaxLength = 4
          TabOrder = 3
        end
      end
      object LocPlaces: TListBox
        Left = 152
        Top = 0
        Width = 161
        Height = 193
        ExtendedSelect = False
        ItemHeight = 13
        PopupMenu = PlacesPopup
        TabOrder = 2
        OnClick = LocPlacesClick
      end
      object LocCategory: TTreeView
        Left = 0
        Top = 0
        Width = 153
        Height = 193
        Indent = 19
        PopupMenu = PlacesPopup
        ReadOnly = True
        RowSelect = True
        TabOrder = 3
        OnChange = LocCategoryChange
      end
      object Mappa: TUOMap
        Left = 568
        Top = 0
        Width = 193
        Height = 193
        TabStop = False
        TabOrder = 4
        OnMouseDown = MappaMouseDown
        ControlData = {00000100F2130000F21300000000000001000C000800000000}
      end
    end
    object ItemTab: TTabSheet
      Caption = 'Oggetti'
      ImageIndex = 6
      object Label15: TLabel
        Left = 320
        Top = 0
        Width = 52
        Height = 13
        Caption = 'ID Oggetto'
      end
      object GroupBox15: TGroupBox
        Left = 504
        Top = 144
        Width = 65
        Height = 49
        Caption = 'Alza / Abb'
        TabOrder = 6
        object NudgeDelta: TEdit
          Left = 8
          Top = 16
          Width = 33
          Height = 21
          TabOrder = 0
          Text = '00'
        end
        object NudgeControl: TUpDown
          Left = 41
          Top = 17
          Width = 15
          Height = 20
          Min = 0
          Position = 0
          TabOrder = 1
          Wrap = False
          OnClick = NudgeControlClick
        end
      end
      object ItmCategories: TTreeView
        Left = 0
        Top = 0
        Width = 153
        Height = 193
        Indent = 19
        PopupMenu = ItemsPopup
        ReadOnly = True
        RowSelect = True
        TabOrder = 0
        OnChange = ItmCategoriesChange
      end
      object ItmList: TListBox
        Left = 152
        Top = 0
        Width = 161
        Height = 193
        ExtendedSelect = False
        ItemHeight = 13
        PopupMenu = ItemsPopup
        TabOrder = 1
        OnClick = ItmListClick
      end
      object AddItemCmd: TButton
        Left = 320
        Top = 24
        Width = 65
        Height = 17
        Caption = 'Aggiungi'
        TabOrder = 2
        OnClick = AddItemCmdClick
      end
      object itemid: TEdit
        Left = 400
        Top = 0
        Width = 137
        Height = 21
        ReadOnly = True
        TabOrder = 3
      end
      object GroupBox13: TGroupBox
        Left = 568
        Top = 0
        Width = 185
        Height = 193
        Caption = 'Oggetto'
        TabOrder = 4
        object ItmArt: TUOArt
          Left = 2
          Top = 15
          Width = 176
          Height = 176
          TabOrder = 0
          ControlData = {000001003112000031120000000000000000FFFFFFFF0000}
        end
      end
      object RemoveCmd3: TButton
        Left = 320
        Top = 40
        Width = 65
        Height = 17
        Caption = 'Rimuovi'
        TabOrder = 5
        OnClick = RemoveCmdClick
      end
      object DupeCmd2: TButton
        Left = 320
        Top = 56
        Width = 65
        Height = 17
        Caption = 'Duplica'
        TabOrder = 7
        OnClick = DupeCmdClick
      end
    end
    object SpawnTabs: TTabSheet
      Caption = 'Personaggi'
      ImageIndex = 7
      object Label16: TLabel
        Left = 320
        Top = 0
        Width = 73
        Height = 13
        Caption = 'ID Personaggio'
      end
      object ChrCategories: TTreeView
        Left = 0
        Top = 0
        Width = 153
        Height = 193
        Indent = 19
        PopupMenu = CharsPopup
        ReadOnly = True
        RowSelect = True
        TabOrder = 0
        OnChange = ChrCategoriesChange
      end
      object ChrList: TListBox
        Left = 152
        Top = 0
        Width = 161
        Height = 193
        ExtendedSelect = False
        ItemHeight = 13
        PopupMenu = CharsPopup
        TabOrder = 1
        OnClick = ChrListClick
      end
      object AddCharCmd: TButton
        Left = 320
        Top = 24
        Width = 65
        Height = 17
        Caption = 'Aggiungi'
        TabOrder = 2
        OnClick = AddCharCmdClick
      end
      object charid: TEdit
        Left = 400
        Top = 0
        Width = 137
        Height = 21
        ReadOnly = True
        TabOrder = 3
      end
      object GroupBox14: TGroupBox
        Left = 568
        Top = 0
        Width = 185
        Height = 193
        Caption = 'Personaggio'
        TabOrder = 4
        object ChrArt: TUOArt
          Left = 2
          Top = 15
          Width = 176
          Height = 176
          TabOrder = 0
          ControlData = {000001003112000031120000000000000100FFFFFFFF0000}
        end
      end
      object RemoveCmd2: TButton
        Left = 320
        Top = 40
        Width = 65
        Height = 17
        Caption = 'Rimuovi'
        TabOrder = 5
        OnClick = RemoveCmdClick
      end
      object InvulCmd2: TButton
        Left = 392
        Top = 24
        Width = 65
        Height = 17
        Caption = 'Invul'
        TabOrder = 6
        OnClick = InvulCmdClick
      end
      object NoInvulCmd2: TButton
        Left = 392
        Top = 40
        Width = 65
        Height = 17
        Caption = 'Mortale'
        TabOrder = 7
        OnClick = NoInvulCmdClick
      end
      object HideCmd2: TButton
        Left = 320
        Top = 64
        Width = 65
        Height = 17
        Caption = 'Nascondi'
        TabOrder = 8
        OnClick = HideCmdClick
      end
      object UnHideCmd2: TButton
        Left = 320
        Top = 80
        Width = 65
        Height = 17
        Caption = 'Rivela'
        TabOrder = 9
        OnClick = UnHideCmdClick
      end
      object FreezeCmd2: TButton
        Left = 392
        Top = 64
        Width = 65
        Height = 17
        Caption = 'Congela'
        TabOrder = 10
        OnClick = FreezeCmdClick
      end
      object UnFreezeCmd2: TButton
        Left = 392
        Top = 80
        Width = 65
        Height = 17
        Caption = 'Scongela'
        TabOrder = 11
        OnClick = UnfreezeCmdClick
      end
      object KillCmd2: TButton
        Left = 464
        Top = 24
        Width = 65
        Height = 17
        Caption = 'Uccidi'
        TabOrder = 12
        OnClick = KillCmdClick
      end
      object ResurrectCmd2: TButton
        Left = 464
        Top = 40
        Width = 65
        Height = 17
        Caption = 'Resuscita'
        TabOrder = 13
        OnClick = ResurrectCmdClick
      end
    end
    object MiscCmdPage: TTabSheet
      Caption = 'Comandi Generali'
      ImageIndex = 3
      object GroupBox7: TGroupBox
        Left = 0
        Top = 0
        Width = 185
        Height = 105
        Caption = 'Oggetti && NPC'
        TabOrder = 0
        object RemoveCmd: TButton
          Left = 8
          Top = 16
          Width = 65
          Height = 17
          Caption = 'Rimuovi'
          TabOrder = 0
          OnClick = RemoveCmdClick
        end
        object DupeCmd: TButton
          Left = 8
          Top = 32
          Width = 65
          Height = 17
          Caption = 'Duplica'
          TabOrder = 1
          OnClick = DupeCmdClick
        end
      end
      object GroupBox8: TGroupBox
        Left = 184
        Top = 0
        Width = 441
        Height = 105
        Caption = 'Impostazioni Personaggi'
        TabOrder = 1
        object InvulCmd: TButton
          Left = 8
          Top = 16
          Width = 65
          Height = 17
          Caption = 'Invul'
          TabOrder = 0
          OnClick = InvulCmdClick
        end
        object NoInvulCmd: TButton
          Left = 8
          Top = 32
          Width = 65
          Height = 17
          Caption = 'Mortale'
          TabOrder = 1
          OnClick = NoInvulCmdClick
        end
        object HideCmd: TButton
          Left = 8
          Top = 56
          Width = 65
          Height = 17
          Caption = 'Nascondi'
          TabOrder = 2
          OnClick = HideCmdClick
        end
        object UnHideCmd: TButton
          Left = 8
          Top = 72
          Width = 65
          Height = 17
          Caption = 'Rivela'
          TabOrder = 3
          OnClick = UnHideCmdClick
        end
        object MakeGMCmd: TButton
          Left = 80
          Top = 16
          Width = 65
          Height = 17
          Caption = 'Make GM'
          TabOrder = 4
          OnClick = MakeGMCmdClick
        end
        object MakeCNSCmd: TButton
          Left = 80
          Top = 32
          Width = 65
          Height = 17
          Caption = 'Make Cons'
          TabOrder = 5
          OnClick = MakeCNSCmdClick
        end
        object FreezeCmd: TButton
          Left = 80
          Top = 56
          Width = 65
          Height = 17
          Caption = 'Congela'
          TabOrder = 6
          OnClick = FreezeCmdClick
        end
        object UnfreezeCmd: TButton
          Left = 80
          Top = 72
          Width = 65
          Height = 17
          Caption = 'Scongela'
          TabOrder = 7
          OnClick = UnfreezeCmdClick
        end
        object KillCmd: TButton
          Left = 152
          Top = 16
          Width = 65
          Height = 17
          Caption = 'Uccidi'
          TabOrder = 8
          OnClick = KillCmdClick
        end
        object ResurrectCmd: TButton
          Left = 152
          Top = 32
          Width = 65
          Height = 17
          Caption = 'Resuscita'
          TabOrder = 9
          OnClick = ResurrectCmdClick
        end
        object RefreshCmd: TButton
          Left = 152
          Top = 56
          Width = 65
          Height = 17
          Caption = 'Aggiorna'
          TabOrder = 10
          OnClick = RefreshCmdClick
        end
        object ZeroKillsCmd: TButton
          Left = 152
          Top = 72
          Width = 65
          Height = 17
          Caption = 'Azzera Kills'
          TabOrder = 11
          OnClick = ZeroKillsCmdClick
        end
        object JailCmd: TButton
          Left = 224
          Top = 16
          Width = 65
          Height = 17
          Caption = 'Imprigiona'
          TabOrder = 12
          OnClick = JailCmdClick
        end
        object ReleaseCmd: TButton
          Left = 224
          Top = 32
          Width = 65
          Height = 17
          Caption = 'Libera'
          TabOrder = 13
          OnClick = ReleaseCmdClick
        end
        object ShowIDsCmd: TButton
          Left = 224
          Top = 56
          Width = 65
          Height = 17
          Caption = 'Mostra IDs'
          TabOrder = 14
          OnClick = ShowIDsCmdClick
        end
        object BankCmd: TButton
          Left = 296
          Top = 16
          Width = 65
          Height = 17
          Caption = 'Apri Banca'
          TabOrder = 15
          OnClick = BankCmdClick
        end
        object SBankCmd: TButton
          Left = 296
          Top = 32
          Width = 65
          Height = 17
          Caption = 'Apri SBanca'
          TabOrder = 16
          OnClick = SBankCmdClick
        end
        object AllMoveOnCmd: TButton
          Left = 296
          Top = 56
          Width = 65
          Height = 17
          Caption = 'Muovi tutto'
          TabOrder = 17
          OnClick = AllMoveOnCmdClick
        end
        object AllMoveOffCmd: TButton
          Left = 296
          Top = 72
          Width = 65
          Height = 17
          Caption = 'Non muovi tutto'
          TabOrder = 18
          OnClick = AllMoveOffCmdClick
        end
        object ShowPriv3Cmd: TButton
          Left = 224
          Top = 72
          Width = 65
          Height = 17
          Caption = 'Mostra priv3'
          TabOrder = 19
          OnClick = ShowPriv3CmdClick
        end
        object DisconnectCmd: TButton
          Left = 368
          Top = 16
          Width = 65
          Height = 17
          Caption = 'Disconnetti'
          TabOrder = 20
          OnClick = DisconnectCmdClick
        end
        object KickCmd: TButton
          Left = 368
          Top = 32
          Width = 65
          Height = 17
          Caption = 'Espelli'
          TabOrder = 21
          OnClick = KickCmdClick
        end
      end
      object Button1: TButton
        Left = 680
        Top = 152
        Width = 65
        Height = 17
        Caption = 'Sample'
        TabOrder = 2
        Visible = False
      end
      object GroupBox16: TGroupBox
        Left = 0
        Top = 104
        Width = 137
        Height = 89
        Caption = 'Meteo'
        TabOrder = 3
        object Label19: TLabel
          Left = 72
          Top = 16
          Width = 38
          Height = 13
          Caption = 'Stagioni'
        end
        object DryCmd: TButton
          Left = 8
          Top = 16
          Width = 57
          Height = 17
          Caption = 'Secco'
          TabOrder = 0
          OnClick = DryCmdClick
        end
        object RainCmd: TButton
          Left = 8
          Top = 32
          Width = 57
          Height = 17
          Caption = 'Pioggia'
          TabOrder = 1
          OnClick = RainCmdClick
        end
        object SnowCmd: TButton
          Left = 8
          Top = 48
          Width = 57
          Height = 17
          Caption = 'Neve'
          ModalResult = 1
          TabOrder = 2
          OnClick = SnowCmdClick
        end
        object Seasons: TComboBox
          Left = 72
          Top = 32
          Width = 57
          Height = 21
          Style = csDropDownList
          ItemHeight = 13
          TabOrder = 3
          Items.Strings = (
            'Spring'
            'Summer'
            'Fall'
            'Winter'
            'Dead')
        end
        object SetSeasonCmd: TButton
          Left = 72
          Top = 61
          Width = 57
          Height = 20
          Caption = 'Imposta'
          TabOrder = 4
          OnClick = SetSeasonCmdClick
        end
        object EclipseCmd: TButton
          Left = 8
          Top = 64
          Width = 57
          Height = 17
          Caption = 'Eclissi'
          ModalResult = 1
          TabOrder = 5
          OnClick = EclipseCmdClick
        end
      end
      object Regione: TGroupBox
        Left = 136
        Top = 104
        Width = 81
        Height = 89
        Caption = 'Regione'
        TabOrder = 5
        object GuardsOnCmd: TButton
          Left = 8
          Top = 16
          Width = 65
          Height = 17
          Caption = 'Guardie'
          TabOrder = 0
          OnClick = GuardsOnCmdClick
        end
        object GuardsOffCmd: TButton
          Left = 8
          Top = 32
          Width = 65
          Height = 17
          Caption = 'No Guardie'
          TabOrder = 1
          OnClick = GuardsOffCmdClick
        end
        object AnnounceOnCmd: TButton
          Left = 8
          Top = 48
          Width = 65
          Height = 17
          Caption = 'Annunci'
          TabOrder = 2
          OnClick = AnnounceOnCmdClick
        end
        object AnnounceOffCmd: TButton
          Left = 8
          Top = 64
          Width = 65
          Height = 17
          Caption = 'No Annunci'
          TabOrder = 3
          OnClick = AnnounceOffCmdClick
        end
      end
      object GroupBox17: TGroupBox
        Left = 216
        Top = 104
        Width = 89
        Height = 89
        Caption = 'Lista giocatori'
        TabOrder = 4
        object WholistCmd: TButton
          Left = 8
          Top = 16
          Width = 65
          Height = 17
          Caption = 'Tutti'
          TabOrder = 0
          OnClick = WholistCmdClick
        end
        object OfflistCmd: TButton
          Left = 8
          Top = 32
          Width = 65
          Height = 17
          Caption = 'Non collegati'
          TabOrder = 1
          OnClick = OfflistCmdClick
        end
        object PlayerListCmd: TButton
          Left = 8
          Top = 48
          Width = 65
          Height = 17
          Caption = 'Collegati'
          TabOrder = 2
          OnClick = PlayerListCmdClick
        end
        object GMsCmd: TButton
          Left = 8
          Top = 64
          Width = 65
          Height = 17
          Caption = 'GMs'
          TabOrder = 3
          Visible = False
          OnClick = GMsCmdClick
        end
      end
      object GroupBox21: TGroupBox
        Left = 304
        Top = 104
        Width = 89
        Height = 89
        Caption = 'Server'
        TabOrder = 6
        object SaveCmd: TButton
          Left = 8
          Top = 16
          Width = 65
          Height = 17
          Caption = 'Salva'
          TabOrder = 0
          OnClick = SaveCmdClick
        end
        object PdumpCmd: TButton
          Left = 8
          Top = 32
          Width = 65
          Height = 17
          Caption = 'Performance'
          TabOrder = 1
          OnClick = PdumpCmdClick
        end
        object ReloadScriptCmd: TButton
          Left = 8
          Top = 48
          Width = 65
          Height = 17
          Caption = 'Ricarica Scripts'
          TabOrder = 2
          OnClick = ReloadScriptCmdClick
        end
        object ReloadServerCmd: TButton
          Left = 8
          Top = 64
          Width = 65
          Height = 17
          Caption = 'Ricarica Conf'
          TabOrder = 3
          OnClick = ReloadServerCmdClick
        end
      end
    end
    object CustomCmdsTab: TTabSheet
      Caption = 'Personalizzati'
      ImageIndex = 4
      object GroupBox9: TGroupBox
        Left = 0
        Top = 0
        Width = 113
        Height = 177
        Caption = 'Comandi Personali'
        TabOrder = 0
        object Label10: TLabel
          Left = 8
          Top = 16
          Width = 73
          Height = 13
          Caption = 'Titolo comando'
        end
        object Label11: TLabel
          Left = 8
          Top = 56
          Width = 96
          Height = 13
          Caption = 'Comando da inserire'
        end
        object CmdTitle: TEdit
          Left = 8
          Top = 32
          Width = 97
          Height = 21
          TabOrder = 0
        end
        object DynamicCmd: TEdit
          Left = 8
          Top = 72
          Width = 97
          Height = 21
          TabOrder = 1
        end
        object AddDynCmd: TButton
          Left = 8
          Top = 104
          Width = 97
          Height = 25
          Caption = 'Aggiungi Comando'
          TabOrder = 2
          OnClick = AddDynCmdClick
        end
        object AddParams: TButton
          Left = 8
          Top = 144
          Width = 97
          Height = 25
          Caption = 'Aggiungi Parametri'
          TabOrder = 3
          OnClick = AddParamsClick
        end
      end
    end
    object TweakTab: TTabSheet
      Caption = 'Tweak'
      ImageIndex = 9
      object Label18: TLabel
        Left = 0
        Top = 0
        Width = 30
        Height = 13
        Caption = 'Valore'
      end
      object Value: TEdit
        Left = 40
        Top = 0
        Width = 145
        Height = 21
        TabOrder = 0
      end
      object GroupBox18: TGroupBox
        Left = 0
        Top = 24
        Width = 185
        Height = 161
        Caption = 'Personaggi'
        TabOrder = 1
        object SetNPCAICmd: TButton
          Left = 8
          Top = 16
          Width = 65
          Height = 17
          Caption = 'NPC AI'
          TabOrder = 0
          OnClick = SetNPCAICmdClick
        end
        object SetFontCmd: TButton
          Left = 72
          Top = 16
          Width = 57
          Height = 17
          Caption = 'Font'
          TabOrder = 1
          OnClick = SetFontCmdClick
        end
        object SetSTRBtn: TButton
          Left = 8
          Top = 32
          Width = 65
          Height = 17
          Caption = 'Forza'
          TabOrder = 2
          Visible = False
          OnClick = SetSTRBtnClick
        end
        object SetINTBtn: TButton
          Left = 8
          Top = 48
          Width = 65
          Height = 17
          Caption = 'Intelligenza'
          TabOrder = 3
          Visible = False
          OnClick = SetINTBtnClick
        end
        object SetDEXBtn: TButton
          Left = 8
          Top = 64
          Width = 65
          Height = 17
          Caption = 'Destrezza'
          TabOrder = 4
          Visible = False
          OnClick = SetDEXBtnClick
        end
        object SetHPBtn: TButton
          Left = 8
          Top = 80
          Width = 65
          Height = 17
          Caption = 'Punti Ferita'
          Enabled = False
          TabOrder = 5
          Visible = False
        end
        object SetStaminaBtn: TButton
          Left = 8
          Top = 96
          Width = 65
          Height = 17
          Caption = 'Stamina'
          TabOrder = 6
          Visible = False
          OnClick = SetStaminaBtnClick
        end
        object SetManaBtn: TButton
          Left = 8
          Top = 112
          Width = 65
          Height = 17
          Caption = 'Mana'
          TabOrder = 7
          Visible = False
          OnClick = SetManaBtnClick
        end
        object SkillList: TComboBox
          Left = 8
          Top = 132
          Width = 129
          Height = 21
          Style = csDropDownList
          ItemHeight = 13
          ItemIndex = 49
          TabOrder = 8
          Text = 'AllSkills'
          Items.Strings = (
            'Alchemy'
            'Anatomy'
            'AnimalLore'
            'ItemID'
            'ArmsLore'
            'Parrying'
            'Begging'
            'Blacksmithing'
            'Bowcraft'
            'Peacemaking'
            'Camping'
            'Carpentry'
            'Cartography'
            'Cooking'
            'DetectingHidden'
            'Enticement'
            'EvalutatingIntel'
            'Healing'
            'Fishing'
            'Forensics'
            'Herding'
            'Hiding'
            'Provocation'
            'Inscription'
            'Lockpicking'
            'Magery'
            'MagicResistance'
            'Tactics'
            'Snooping'
            'Musicianship'
            'Poisoning'
            'Archery'
            'SpiritSpeak'
            'Stealing'
            'Tailoring'
            'Taming'
            'TasteID'
            'Tinkering'
            'Tracking'
            'Veterinary'
            'Swordsmanship'
            'Macefighting'
            'Fencing'
            'Wrestling'
            'Lumberjacking'
            'Mining'
            'Meditation'
            'Stealth'
            'RemoveTraps'
            'AllSkills')
        end
        object SetSkillBtn: TButton
          Left = 144
          Top = 128
          Width = 33
          Height = 25
          Caption = 'Skill'
          TabOrder = 9
          Visible = False
          OnClick = SetSkillBtnClick
        end
      end
      object GroupBox19: TGroupBox
        Left = 192
        Top = 0
        Width = 185
        Height = 185
        Caption = 'Oggetti'
        TabOrder = 2
        object SetAmountCmd: TButton
          Left = 8
          Top = 16
          Width = 57
          Height = 17
          Caption = 'Amount'
          TabOrder = 0
          OnClick = SetAmountCmdClick
        end
        object SetMoreXCmd: TButton
          Left = 8
          Top = 32
          Width = 57
          Height = 17
          Caption = 'MoreX'
          TabOrder = 1
          OnClick = SetMoreXCmdClick
        end
        object SetMoreYCmd: TButton
          Left = 8
          Top = 48
          Width = 57
          Height = 17
          Caption = 'MoreY'
          TabOrder = 2
          OnClick = SetMoreYCmdClick
        end
        object SetMoreZCmd: TButton
          Left = 8
          Top = 64
          Width = 57
          Height = 17
          Caption = 'MoreZ'
          TabOrder = 3
          OnClick = SetMoreZCmdClick
        end
        object SetMoreXYZCmd2: TButton
          Left = 8
          Top = 80
          Width = 57
          Height = 17
          Caption = 'More XYZ'
          TabOrder = 4
          OnClick = SetMoreXYZCmd2Click
        end
        object SetTypeCmd: TButton
          Left = 8
          Top = 96
          Width = 57
          Height = 17
          Caption = 'Tipo'
          TabOrder = 5
          OnClick = SetTypeCmdClick
        end
        object SetMoreCmd: TButton
          Left = 8
          Top = 112
          Width = 57
          Height = 17
          Caption = 'More'
          TabOrder = 6
          OnClick = SetMoreCmdClick
        end
        object SetHexMoreXY: TButton
          Left = 8
          Top = 128
          Width = 57
          Height = 17
          Caption = 'HexMoreXYZ'
          TabOrder = 7
          OnClick = SetHexMoreXYZCmdClick
        end
      end
      object GroupBox20: TGroupBox
        Left = 384
        Top = 0
        Width = 185
        Height = 185
        Caption = 'Comuni'
        TabOrder = 3
        object SetXCmd: TButton
          Left = 8
          Top = 16
          Width = 57
          Height = 17
          Caption = 'X'
          TabOrder = 0
          Visible = False
          OnClick = SetXCmdClick
        end
        object SetYCmd: TButton
          Left = 8
          Top = 32
          Width = 57
          Height = 17
          Caption = 'Y'
          TabOrder = 1
          Visible = False
          OnClick = SetYCmdClick
        end
        object SetZCmd: TButton
          Left = 8
          Top = 48
          Width = 57
          Height = 17
          Caption = 'Z'
          TabOrder = 2
          Visible = False
          OnClick = SetZCmdClick
        end
      end
      object ColorPaletteBtn: TButton
        Left = 576
        Top = 8
        Width = 75
        Height = 25
        Caption = 'Colori'
        TabOrder = 4
        OnClick = ColorPaletteBtnClick
      end
    end
    object s: TTabSheet
      Caption = 'Impostazioni'
      ImageIndex = 1
      object GroupBox1: TGroupBox
        Left = 160
        Top = 0
        Width = 153
        Height = 105
        Caption = 'Invio comandi'
        TabOrder = 0
        object Label1: TLabel
          Left = 32
          Top = 32
          Width = 80
          Height = 13
          Caption = 'Prefisso comandi'
        end
        object NewLine: TCheckBox
          Left = 8
          Top = 16
          Width = 129
          Height = 17
          Caption = 'Invia riga vuota prima'
          Checked = True
          State = cbChecked
          TabOrder = 0
          OnClick = NewLineClick
        end
        object CmdPrefix: TEdit
          Left = 8
          Top = 32
          Width = 17
          Height = 21
          MaxLength = 1
          TabOrder = 1
          Text = #39
          OnChange = CmdPrefixChange
        end
        object Use0x: TCheckBox
          Left = 8
          Top = 56
          Width = 137
          Height = 17
          Caption = 'Inserisci 0x nei valori hex'
          TabOrder = 2
          OnClick = Use0xClick
        end
        object HotKeys: TCheckBox
          Left = 8
          Top = 80
          Width = 121
          Height = 17
          Caption = 'Abilita le hotkeys'
          Checked = True
          State = cbChecked
          TabOrder = 3
        end
      end
      object GroupBox6: TGroupBox
        Left = 0
        Top = 112
        Width = 361
        Height = 49
        Caption = 'Client Predefinito'
        TabOrder = 2
        object DefaultClient: TEdit
          Left = 8
          Top = 16
          Width = 313
          Height = 21
          ReadOnly = True
          TabOrder = 0
        end
        object BrowseDefClientBtn: TButton
          Left = 328
          Top = 16
          Width = 27
          Height = 25
          Caption = '...'
          TabOrder = 1
          OnClick = BrowseDefClientBtnClick
        end
      end
      object GroupBox12: TGroupBox
        Left = 320
        Top = 0
        Width = 185
        Height = 105
        Caption = 'XSS Script Parser'
        TabOrder = 3
        object Label17: TLabel
          Left = 8
          Top = 16
          Width = 165
          Height = 26
          Caption = 'Percorso relativo per il caricamento degli script'
          WordWrap = True
        end
        object LoadXSSBtn: TButton
          Left = 8
          Top = 72
          Width = 75
          Height = 25
          Caption = 'Carica Script'
          TabOrder = 0
          OnClick = LoadXSSBtnClick
        end
        object NXWPath: TEdit
          Left = 8
          Top = 48
          Width = 121
          Height = 21
          TabOrder = 1
        end
        object BrowseNoxWizardBtn: TButton
          Left = 134
          Top = 48
          Width = 27
          Height = 25
          Caption = '...'
          TabOrder = 2
          OnClick = BrowseNoxWizardBtnClick
        end
        object NoX73Comp: TCheckBox
          Left = 88
          Top = 80
          Width = 81
          Height = 17
          Caption = '.73 Version'
          TabOrder = 3
          OnClick = NoX73CompClick
        end
      end
      object GroupBox4: TGroupBox
        Left = 0
        Top = 0
        Width = 153
        Height = 105
        Caption = 'Visualizzazione'
        TabOrder = 1
        object Label2: TLabel
          Left = 26
          Top = 32
          Width = 114
          Height = 26
          Caption = 'Esci dal programma alla chiusura della finestra'
          WordWrap = True
          OnClick = Label2Click
        end
        object AoT: TCheckBox
          Left = 8
          Top = 16
          Width = 97
          Height = 17
          Caption = 'Sempre in primo piano'
          TabOrder = 0
          OnClick = AoTClick
        end
        object ExitOnClose: TCheckBox
          Left = 8
          Top = 32
          Width = 17
          Height = 17
          Checked = True
          State = cbChecked
          TabOrder = 1
          OnClick = ExitOnCloseClick
        end
        object ShowArt: TCheckBox
          Left = 8
          Top = 64
          Width = 137
          Height = 17
          Caption = 'Mostra art alla selezione'
          Checked = True
          State = cbChecked
          TabOrder = 2
          OnClick = ShowArtClick
        end
        object Show3DRoom: TCheckBox
          Left = 8
          Top = 80
          Width = 137
          Height = 17
          Caption = 'Visualizza "stanza" 3D'
          TabOrder = 3
          OnClick = Show3DRoomClick
        end
      end
    end
    object ThanksTab: TTabSheet
      Caption = 'Ringraziamenti'
      ImageIndex = 8
      object ThanksMemo: TMemo
        Left = 0
        Top = 0
        Width = 756
        Height = 193
        Align = alClient
        Lines.Strings = (
          
            '- Skyfire, perch'#233' Unicorn '#232' partito su una sua idea, e suoi sono' +
            ' logo ed icona, inoltre '#232' il mio supporto morale ogni qual volta' +
            ' il BCB mi fa impazzire.'
          
            '- Nemesys per avermi dato fiducia come GM su Dragons'#39' Land e com' +
            'e sistemista su Dragons.it'
          
            '- ThE FoOl, che mi fa "assistenza psichiatrica" quando la progra' +
            'mmazione mi fa impazzire'
          '- Mizar che mi ha aiutato molto quando ero in difficolt'#224
          
            '- Chrono, Judas, Kenshiro, limaCAT, insomma tutta la chat #heave' +
            'n-uo su AzzurraNet, per il supporto morale quando sclero per una' +
            ' funzione che non parte.'
          
            '- Il team di sviluppo di Nox-Wizard, ottimo emulatore per Ultima' +
            ' OnLine, per cui Unicorn '#232' stato scritto.'
          
            '- Il creatore di Accomplice, dai cui sorgenti ho trovato come in' +
            'viare i comandi ad Ultima OnLine'
          
            '- Il team di sviluppo di Axis, per aver creato i due activex UOM' +
            'ap e UOArt che utilizzo per la mappa e gli oggetti.'
          
            '- La Nullsoft con il suo NSIS che mi permette di non dover richi' +
            'edere la registrazione degli ocx a mano.'
          
            '- Il mio professore di informatica per avermi insegnato la progr' +
            'ammazione ad oggetti.'
          
            '- La febbre a 37.6C che ho in questo momento che mi ha suggerito' +
            ' come risolvere il parser xss'
          ''
          'e tanti altri che ora non ricordo')
        ReadOnly = True
        TabOrder = 0
      end
    end
  end
  object ClientDialog: TOpenDialog
    DefaultExt = '*.exe'
    Filter = 'File eseguibili|*.exe|Tutti i files|*.*'
    Options = [ofReadOnly, ofHideReadOnly, ofFileMustExist, ofEnableSizing, ofDontAddToRecent]
    Left = 736
  end
  object OpenScript: TOpenDialog
    DefaultExt = '*.xss'
    Filter = 'XSS Scripts|*.xss|Tutti i files|*.*'
    Left = 712
  end
  object PlacesPopup: TPopupMenu
    Left = 688
    Top = 24
    object Modifica1: TMenuItem
      Caption = '&Modifica'
      OnClick = Modifica1Click
    end
    object Inserisci1: TMenuItem
      Caption = '&Inserisci'
      OnClick = Inserisci1Click
    end
    object Elimina1: TMenuItem
      Caption = '&Elimina'
      OnClick = Elimina1Click
    end
  end
  object ItemsPopup: TPopupMenu
    Left = 736
    Top = 24
    object MenuItem1: TMenuItem
      Caption = '&Modifica'
      OnClick = MenuItem1Click
    end
    object MenuItem2: TMenuItem
      Caption = '&Inserisci'
      OnClick = MenuItem2Click
    end
    object Elimina2: TMenuItem
      Caption = '&Elimina'
      OnClick = Elimina2Click
    end
  end
  object CharsPopup: TPopupMenu
    Left = 712
    Top = 24
    object MenuItem3: TMenuItem
      Caption = '&Modifica'
      OnClick = MenuItem3Click
    end
    object MenuItem4: TMenuItem
      Caption = '&Inserisci'
      OnClick = MenuItem4Click
    end
    object Elimina3: TMenuItem
      Caption = '&Elimina'
      OnClick = Elimina3Click
    end
  end
  object OpenNoxWizard: TOpenDialog
    Options = [ofReadOnly, ofHideReadOnly, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Left = 688
  end
end
