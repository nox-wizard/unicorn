object MainForm: TMainForm
  Left = 192
  Top = 107
  BorderStyle = bsSingle
  Caption = 'Unicorn'#39's Herald'
  ClientHeight = 513
  ClientWidth = 775
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Title: TLabel
    Left = 8
    Top = 32
    Width = 20
    Height = 13
    Caption = 'Title'
  end
  object Author: TLabel
    Left = 96
    Top = 32
    Width = 31
    Height = 13
    Caption = 'Author'
  end
  object Date: TLabel
    Left = 8
    Top = 48
    Width = 23
    Height = 13
    Caption = 'Date'
  end
  object Description: TMemo
    Left = 8
    Top = 64
    Width = 185
    Height = 89
    TabOrder = 0
  end
  object RSSFeed: TXMLDocument
    FileName = 'http://sourceforge.net/export/rss2_projnews.php?group_id=30584'
    Options = [doAttrNull]
    Left = 8
    DOMVendorDesc = 'MSXML'
  end
end
