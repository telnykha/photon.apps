object Form7: TForm7
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'OA TIFF to awp convertor '
  ClientHeight = 416
  ClientWidth = 570
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object PhImage1: TPhImage
    Left = 8
    Top = 8
    Width = 400
    Height = 400
    AutoMosaic = True
    ThumbWidht = 128
    ThumbHeight = 128
    SlideShowInterval = 500
    ParentColor = False
  end
  object Button1: TButton
    Left = 424
    Top = 16
    Width = 138
    Height = 25
    Caption = 'Open Database...'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 424
    Top = 48
    Width = 138
    Height = 25
    Caption = 'Convert'
    TabOrder = 2
  end
  object Button3: TButton
    Left = 424
    Top = 80
    Width = 138
    Height = 25
    Caption = 'Options...'
    TabOrder = 3
  end
end
