object ParamsForm: TParamsForm
  Left = 254
  Top = 159
  Width = 244
  Height = 361
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 14
  object Params: TValueListEditor
    Left = 0
    Top = 0
    Width = 251
    Height = 323
    Ctl3D = True
    DropDownRows = 0
    KeyOptions = [keyEdit, keyAdd, keyDelete, keyUnique]
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goEditing, goTabs, goAlwaysShowEditor, goThumbTracking]
    ParentCtl3D = False
    ScrollBars = ssVertical
    TabOrder = 0
    TitleCaptions.Strings = (
      'Parametro'
      'Valore')
    ColWidths = (
      108
      119)
  end
  object OKBtn: TButton
    Left = 0
    Top = 327
    Width = 81
    Height = 27
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 1
  end
  object CancelBtn: TButton
    Left = 86
    Top = 327
    Width = 81
    Height = 27
    Cancel = True
    Caption = 'Annulla'
    ModalResult = 2
    TabOrder = 2
  end
end
