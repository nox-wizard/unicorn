object MainForm: TMainForm
  Left = 237
  Top = 109
  BorderStyle = bsSingle
  Caption = 'Unicorn'#39's Rainbow'
  ClientHeight = 574
  ClientWidth = 606
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDefaultPosOnly
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object ColorPalette: TImage
    Left = 0
    Top = 69
    Width = 600
    Height = 500
    OnMouseDown = ColorPaletteMouseDown
  end
  object ColorCode: TLabel
    Left = 344
    Top = 40
    Width = 3
    Height = 13
  end
  object GroupBox1: TGroupBox
    Left = 0
    Top = 8
    Width = 337
    Height = 57
    Caption = 'Hue Gradient'
    TabOrder = 0
    object HueColors: TImage
      Left = 8
      Top = 16
      Width = 320
      Height = 30
      OnMouseDown = HueColorsMouseDown
    end
  end
  object GradientIndex: TTrackBar
    Left = 344
    Top = 8
    Width = 257
    Height = 25
    Max = 31
    Orientation = trHorizontal
    PageSize = 5
    Frequency = 1
    Position = 5
    SelEnd = 0
    SelStart = 0
    TabOrder = 1
    TickMarks = tmBottomRight
    TickStyle = tsAuto
    OnChange = GradientIndexChange
  end
  object ColorName: TEdit
    Left = 440
    Top = 40
    Width = 101
    Height = 21
    MaxLength = 19
    TabOrder = 2
  end
  object SaveBtn: TButton
    Left = 544
    Top = 40
    Width = 51
    Height = 25
    Caption = 'Salva'
    TabOrder = 3
    OnClick = SaveBtnClick
  end
  object Colors: TColorDialog
    Ctl3D = True
    Left = 576
  end
end
