object MainForm: TMainForm
  Left = 276
  Top = 138
  BorderStyle = bsSingle
  Caption = 'Unicorn'#39's Calling'
  ClientHeight = 378
  ClientWidth = 773
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label12: TLabel
    Left = 0
    Top = 328
    Width = 45
    Height = 13
    Caption = 'Comando'
  end
  object Label13: TLabel
    Left = 0
    Top = 352
    Width = 48
    Height = 13
    Caption = 'Broadcast'
  end
  object GroupBox1: TGroupBox
    Left = 552
    Top = 0
    Width = 217
    Height = 169
    Caption = 'Connessione'
    TabOrder = 0
    object Label2: TLabel
      Left = 8
      Top = 48
      Width = 32
      Height = 13
      Caption = 'Utente'
    end
    object Label3: TLabel
      Left = 8
      Top = 72
      Width = 46
      Height = 13
      Caption = 'Password'
    end
    object Label4: TLabel
      Left = 8
      Top = 96
      Width = 38
      Height = 13
      Caption = 'Indirizzo'
    end
    object Label5: TLabel
      Left = 8
      Top = 120
      Width = 25
      Height = 13
      Caption = 'Porta'
    end
    object ServerList: TComboBox
      Left = 8
      Top = 16
      Width = 145
      Height = 21
      ItemHeight = 13
      TabOrder = 0
      OnChange = ServerListChange
    end
    object ServerPort: TEdit
      Left = 80
      Top = 112
      Width = 121
      Height = 21
      TabOrder = 1
      OnChange = ServerPortChange
    end
    object ServerIP: TEdit
      Left = 80
      Top = 88
      Width = 121
      Height = 21
      TabOrder = 2
    end
    object ServerPassword: TEdit
      Left = 80
      Top = 64
      Width = 121
      Height = 21
      TabOrder = 3
    end
    object ServerUsername: TEdit
      Left = 80
      Top = 40
      Width = 121
      Height = 21
      TabOrder = 4
    end
    object RCConnectBtn: TButton
      Left = 8
      Top = 136
      Width = 201
      Height = 25
      Caption = 'Connetti'
      TabOrder = 5
      OnClick = RCConnectBtnClick
    end
    object AddServerBtn: TButton
      Left = 160
      Top = 16
      Width = 49
      Height = 17
      Cancel = True
      Caption = 'Aggiungi'
      TabOrder = 6
      OnClick = AddServerBtnClick
    end
  end
  object RCOutput: TMemo
    Left = 0
    Top = 0
    Width = 545
    Height = 321
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Lucida Console'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object RCBroadCast: TEdit
    Left = 56
    Top = 352
    Width = 433
    Height = 21
    Enabled = False
    TabOrder = 2
  end
  object RCCommand: TEdit
    Left = 56
    Top = 328
    Width = 433
    Height = 21
    Enabled = False
    TabOrder = 3
  end
  object RCSendCmdBtn: TButton
    Left = 496
    Top = 328
    Width = 49
    Height = 17
    Caption = 'Invia'
    Enabled = False
    TabOrder = 4
    OnClick = RCSendCmdBtnClick
  end
  object RCSendBroadBtn: TButton
    Left = 496
    Top = 352
    Width = 49
    Height = 17
    Caption = 'Broadcast'
    Enabled = False
    TabOrder = 5
    OnClick = RCSendBroadBtnClick
  end
  object GroupBox10: TGroupBox
    Left = 552
    Top = 176
    Width = 217
    Height = 145
    Caption = 'Comandi'
    TabOrder = 6
    object RCHelpBtn: TButton
      Left = 8
      Top = 16
      Width = 97
      Height = 25
      Caption = 'Aiuto'
      TabOrder = 0
      OnClick = RCHelpBtnClick
    end
    object RCWhoBtn: TButton
      Left = 8
      Top = 40
      Width = 97
      Height = 25
      Caption = 'Chi c'#39#232'?'
      TabOrder = 1
      OnClick = RCWhoBtnClick
    end
    object RCPerfDumpBtn: TButton
      Left = 8
      Top = 64
      Width = 97
      Height = 25
      Caption = 'Performance'
      TabOrder = 2
      OnClick = RCPerfDumpBtnClick
    end
    object RCSaveWorldBtn: TButton
      Left = 8
      Top = 88
      Width = 97
      Height = 25
      Caption = 'Salva Mondo'
      TabOrder = 3
      OnClick = RCSaveWorldBtnClick
    end
    object RCReloadCronBtn: TButton
      Left = 8
      Top = 112
      Width = 97
      Height = 25
      Caption = 'Ricarica crontab'
      TabOrder = 4
      OnClick = RCReloadCronBtnClick
    end
    object RCReloadBlocksBtn: TButton
      Left = 112
      Top = 16
      Width = 97
      Height = 25
      Caption = 'Ricarica blocchi'
      TabOrder = 5
      OnClick = RCReloadBlocksBtnClick
    end
    object RCAddAcctBtn: TButton
      Left = 112
      Top = 40
      Width = 97
      Height = 25
      Caption = 'Aggiungi Account'
      Enabled = False
      TabOrder = 6
      OnClick = RCAddAcctBtnClick
    end
    object RCChangeCfgBtn: TButton
      Left = 112
      Top = 64
      Width = 97
      Height = 25
      Caption = 'Configura'
      Enabled = False
      TabOrder = 7
    end
    object RCShutdownBtn: TButton
      Left = 112
      Top = 88
      Width = 97
      Height = 25
      Caption = 'Spegni Server'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 8
      OnClick = RCShutdownBtnClick
    end
    object RCAbortBtn: TButton
      Left = 112
      Top = 112
      Width = 97
      Height = 25
      Caption = 'Termina Server'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 9
      OnClick = RCAbortBtnClick
    end
  end
  object RCServers: TXMLDocument
    FileName = 'rcservers.xml'
    NodeIndentStr = #9
    Options = [doNodeAutoCreate, doNodeAutoIndent, doAttrNull, doAutoSave]
    BeforeOpen = RCServersBeforeOpen
    Left = 728
    Top = 144
    DOMVendorDesc = 'MSXML'
  end
  object RCConnection: TClientSocket
    Active = False
    ClientType = ctBlocking
    Port = 0
    OnConnect = RCConnectionConnect
    Left = 696
    Top = 144
  end
end
