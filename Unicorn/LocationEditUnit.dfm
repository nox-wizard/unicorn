object LocationEdit: TLocationEdit
  Left = 213
  Top = 336
  Width = 268
  Height = 174
  Caption = 'Modifica locazione'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 14
  object Label1: TLabel
    Left = 9
    Top = 9
    Width = 46
    Height = 14
    Caption = 'Categoria'
  end
  object Label2: TLabel
    Left = 9
    Top = 34
    Width = 73
    Height = 14
    Caption = 'Sotto categoria'
  end
  object Label3: TLabel
    Left = 9
    Top = 60
    Width = 27
    Height = 14
    Caption = 'Nome'
  end
  object Label4: TLabel
    Left = 9
    Top = 86
    Width = 52
    Height = 14
    Caption = 'Coordinate'
  end
  object Categories: TComboBox
    Left = 95
    Top = 9
    Width = 156
    Height = 22
    ItemHeight = 14
    TabOrder = 0
  end
  object Subcategories: TComboBox
    Left = 95
    Top = 34
    Width = 156
    Height = 22
    ItemHeight = 14
    TabOrder = 1
  end
  object Name: TEdit
    Left = 95
    Top = 60
    Width = 156
    Height = 22
    TabOrder = 2
  end
  object X: TEdit
    Left = 95
    Top = 86
    Width = 44
    Height = 22
    TabOrder = 3
  end
  object Y: TEdit
    Left = 146
    Top = 86
    Width = 45
    Height = 22
    TabOrder = 4
  end
  object Z: TEdit
    Left = 198
    Top = 86
    Width = 44
    Height = 22
    TabOrder = 5
  end
  object OKBtn: TButton
    Left = 9
    Top = 112
    Width = 80
    Height = 27
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 6
  end
  object CancelBtn: TButton
    Left = 95
    Top = 112
    Width = 81
    Height = 27
    Cancel = True
    Caption = 'Annulla'
    ModalResult = 2
    TabOrder = 7
  end
end
