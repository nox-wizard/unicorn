object ObjectEditForm: TObjectEditForm
  Left = 192
  Top = 106
  Width = 359
  Height = 233
  Caption = 'Modifica oggetto'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 14
  object Label2: TLabel
    Left = 17
    Top = 43
    Width = 73
    Height = 14
    Caption = 'Sotto categoria'
  end
  object Label1: TLabel
    Left = 17
    Top = 17
    Width = 46
    Height = 14
    Caption = 'Categoria'
  end
  object Label3: TLabel
    Left = 17
    Top = 69
    Width = 27
    Height = 14
    Caption = 'Nome'
  end
  object Label4: TLabel
    Left = 17
    Top = 95
    Width = 46
    Height = 14
    Caption = 'Ingame ID'
  end
  object Label5: TLabel
    Left = 17
    Top = 121
    Width = 27
    Height = 14
    Caption = 'Art ID'
  end
  object Label6: TLabel
    Left = 17
    Top = 146
    Width = 31
    Height = 14
    Caption = 'Colore'
  end
  object Categories: TComboBox
    Left = 103
    Top = 9
    Width = 157
    Height = 22
    ItemHeight = 14
    TabOrder = 0
  end
  object Subcategories: TComboBox
    Left = 103
    Top = 34
    Width = 157
    Height = 22
    ItemHeight = 14
    TabOrder = 1
  end
  object Name: TEdit
    Left = 103
    Top = 60
    Width = 157
    Height = 22
    TabOrder = 2
  end
  object OKBtn: TButton
    Left = 17
    Top = 172
    Width = 81
    Height = 27
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 6
  end
  object CancelBtn: TButton
    Left = 103
    Top = 172
    Width = 81
    Height = 27
    Cancel = True
    Caption = 'Annulla'
    ModalResult = 2
    TabOrder = 7
  end
  object Preview: TUOArt
    Left = 267
    Top = 9
    Width = 76
    Height = 184
    TabOrder = 8
    ControlData = {00000100DB07000004130000000000000000000000000000}
  end
  object ArtID: TEdit
    Left = 103
    Top = 112
    Width = 157
    Height = 22
    TabOrder = 4
    OnExit = ArtIDExit
  end
  object IngameID: TEdit
    Left = 103
    Top = 86
    Width = 157
    Height = 22
    TabOrder = 3
  end
  object Color: TEdit
    Left = 103
    Top = 138
    Width = 122
    Height = 22
    TabOrder = 5
    OnExit = ColorExit
  end
  object ColorPaletteBtn: TButton
    Left = 233
    Top = 138
    Width = 29
    Height = 27
    Caption = '...'
    TabOrder = 9
    OnClick = ColorPaletteBtnClick
  end
end
