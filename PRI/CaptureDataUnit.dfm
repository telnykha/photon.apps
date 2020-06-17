object CaptureForm: TCaptureForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1047#1072#1087#1080#1089#1100' '#1076#1072#1085#1085#1099#1093
  ClientHeight = 347
  ClientWidth = 467
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 441
    Height = 300
    Shape = bsFrame
  end
  object CGauge1: TCGauge
    Left = 16
    Top = 217
    Width = 418
    Height = 33
  end
  object Label1: TLabel
    Left = 16
    Top = 256
    Width = 112
    Height = 13
    Caption = #1054#1073#1097#1077#1077' '#1074#1088#1077#1084#1103' '#1079#1072#1087#1080#1089#1080': '
  end
  object Label2: TLabel
    Left = 16
    Top = 277
    Width = 54
    Height = 13
    Caption = #1048#1079#1084#1077#1088#1077#1085#1080#1077
  end
  object PhImage1: TPhImage
    Left = 16
    Top = 24
    Width = 206
    Height = 187
    AutoMosaic = True
    ThumbWidht = 128
    ThumbHeight = 128
    SlideShowInterval = 500
    ParentColor = False
  end
  object PhImage3: TPhImage
    Left = 228
    Top = 24
    Width = 206
    Height = 187
    AutoMosaic = True
    ThumbWidht = 128
    ThumbHeight = 128
    SlideShowInterval = 500
    ParentColor = False
  end
  object Button1: TButton
    Left = 8
    Top = 314
    Width = 108
    Height = 25
    Caption = #1053#1072#1095#1072#1090#1100' '#1079#1072#1087#1080#1089#1100
    TabOrder = 2
    OnClick = Button1Click
  end
end
