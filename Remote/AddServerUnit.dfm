object AddServerForm: TAddServerForm
  Left = 783
  Top = 488
  BorderStyle = bsDialog
  Caption = 'Aggiungi Server'
  ClientHeight = 71
  ClientWidth = 228
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 77
    Height = 13
    Caption = 'Nome del server'
  end
  object ServerName: TEdit
    Left = 96
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object OKBtn: TButton
    Left = 8
    Top = 40
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 1
  end
  object CancelBtn: TButton
    Left = 152
    Top = 40
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 2
  end
end
