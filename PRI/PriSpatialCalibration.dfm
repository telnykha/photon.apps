object SpatialCalibrationDlg: TSpatialCalibrationDlg
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1055#1088#1086#1089#1090#1088#1072#1085#1089#1090#1074#1077#1085#1085#1072#1103' '#1082#1072#1083#1080#1073#1086#1088#1086#1074#1082#1072
  ClientHeight = 551
  ClientWidth = 798
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 13
    Top = 5
    Width = 109
    Height = 13
    Caption = #1048#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077' 531 nm '
  end
  object Label2: TLabel
    Left = 334
    Top = 5
    Width = 109
    Height = 13
    Caption = #1048#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077' 570 nm '
  end
  object Label3: TLabel
    Left = 13
    Top = 270
    Width = 276
    Height = 13
    Caption = #1053#1077#1089#1082#1086#1084#1087#1077#1085#1089#1080#1088#1086#1074#1072#1085#1085#1086#1077' '#1088#1072#1089#1089#1086#1075#1083#1072#1089#1086#1074#1072#1085#1080#1077' '#1080#1079#1086#1073#1088#1072#1102#1077#1085#1080#1081' '
  end
  object Label4: TLabel
    Left = 334
    Top = 270
    Width = 267
    Height = 13
    Caption = #1057#1082#1086#1084#1087#1077#1085#1089#1080#1088#1086#1074#1072#1085#1085#1086#1077' '#1088#1072#1089#1089#1086#1075#1083#1072#1089#1086#1074#1072#1085#1080#1077' '#1080#1079#1086#1073#1072#1088#1072#1078#1077#1085#1080#1081
  end
  object Label5: TLabel
    Left = 13
    Top = 536
    Width = 54
    Height = 13
    Caption = #1054#1096#1080#1073#1082#1072' = '
  end
  object Label6: TLabel
    Left = 334
    Top = 536
    Width = 54
    Height = 13
    Caption = #1054#1096#1080#1073#1082#1072' = '
  end
  object Button1: TButton
    Left = 658
    Top = 86
    Width = 129
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1080' '#1074#1099#1081#1090#1080
    Default = True
    ModalResult = 1
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 658
    Top = 55
    Width = 129
    Height = 25
    Caption = #1042#1099#1093#1086#1076' '#1073#1077#1079' '#1089#1086#1093#1088#1072#1085#1077#1085#1080#1103
    ModalResult = 2
    TabOrder = 1
  end
  object PhImage1: TPhImage
    Left = 8
    Top = 24
    Width = 320
    Height = 240
    AutoMosaic = True
    ThumbWidht = 128
    ThumbHeight = 128
    SlideShowInterval = 500
    ParentColor = False
  end
  object PhImage2: TPhImage
    Left = 334
    Top = 24
    Width = 320
    Height = 240
    AutoMosaic = True
    ThumbWidht = 128
    ThumbHeight = 128
    SlideShowInterval = 500
    ParentColor = False
  end
  object PhImage3: TPhImage
    Left = 8
    Top = 290
    Width = 320
    Height = 240
    AutoMosaic = True
    ThumbWidht = 128
    ThumbHeight = 128
    SlideShowInterval = 500
    ParentColor = False
  end
  object Button3: TButton
    Left = 660
    Top = 24
    Width = 128
    Height = 25
    Caption = #1054#1090#1082#1088#1099#1090#1100' '#1072#1088#1093#1080#1074'...'
    TabOrder = 5
    OnClick = Button3Click
  end
  object PhImage4: TPhImage
    Left = 334
    Top = 290
    Width = 320
    Height = 240
    AutoMosaic = True
    ThumbWidht = 128
    ThumbHeight = 128
    SlideShowInterval = 500
    ParentColor = False
  end
  object PhPaneTool1: TPhPaneTool
    PhImage = PhImage1
    Left = 32
    Top = 48
  end
  object PhPaneTool2: TPhPaneTool
    PhImage = PhImage2
    Left = 360
    Top = 56
  end
  object PhPaneTool3: TPhPaneTool
    PhImage = PhImage3
    Left = 32
    Top = 320
  end
  object PhPaneTool4: TPhPaneTool
    PhImage = PhImage4
    Left = 352
    Top = 312
  end
end
