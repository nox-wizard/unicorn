object GotoForm: TGotoForm
  Left = 192
  Top = 107
  Width = 208
  Height = 90
  Caption = 'Vai all'#39'hues...'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 56
    Height = 13
    Caption = 'Indice (dec)'
  end
  object Index: TEdit
    Left = 72
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object OKBtn: TButton
    Left = 8
    Top = 32
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 1
  end
  object CacelBtn: TButton
    Left = 120
    Top = 32
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Annulla'
    ModalResult = 2
    TabOrder = 2
  end
end
