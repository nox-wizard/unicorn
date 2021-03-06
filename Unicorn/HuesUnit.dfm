object PaletteForm: TPaletteForm
  Left = 255
  Top = 173
  BorderIcons = [biMinimize]
  BorderStyle = bsDialog
  Caption = 'Scegli il colore'
  ClientHeight = 633
  ClientWidth = 745
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 14
  object ColorPalette: TImage
    Left = 0
    Top = 86
    Width = 646
    Height = 539
    OnMouseDown = ColorPaletteMouseDown
  end
  object ColorCode: TLabel
    Left = 382
    Top = 69
    Width = 3
    Height = 14
  end
  object HueBox: TGroupBox
    Left = 9
    Top = 9
    Width = 363
    Height = 52
    Caption = 'HueBox'
    TabOrder = 0
    object HueColors: TImage
      Left = 9
      Top = 17
      Width = 344
      Height = 27
    end
  end
  object ColoredArt: TUOArt
    Left = 551
    Top = 0
    Width = 104
    Height = 78
    TabOrder = 1
    ControlData = {00000100C00A000010080000000000000000000000000000}
  end
  object OKBtn: TButton
    Left = 379
    Top = 34
    Width = 81
    Height = 27
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 2
  end
  object CancelBtn: TButton
    Left = 465
    Top = 34
    Width = 81
    Height = 27
    Cancel = True
    Caption = 'Annulla'
    ModalResult = 2
    TabOrder = 3
  end
  object ColorIndexBar: TTrackBar
    Left = 379
    Top = 0
    Width = 162
    Height = 27
    Max = 31
    Orientation = trHorizontal
    Frequency = 1
    Position = 5
    SelEnd = 0
    SelStart = 0
    TabOrder = 4
    TickMarks = tmBottomRight
    TickStyle = tsAuto
    OnChange = ColorIndexBarChange
  end
end
