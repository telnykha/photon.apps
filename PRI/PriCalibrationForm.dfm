object CalibrationDlg: TCalibrationDlg
  Left = 227
  Top = 108
  BorderStyle = bsDialog
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072' '#1103#1088#1082#1086#1089#1090#1085#1086#1081' '#1082#1072#1083#1080#1073#1088#1086#1074#1082#1080
  ClientHeight = 298
  ClientWidth = 428
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 273
    Height = 282
    Shape = bsFrame
  end
  object SpeedButton1: TSpeedButton
    Left = 16
    Top = 18
    Width = 61
    Height = 42
    GroupIndex = 1
    Caption = '531'
  end
  object SpeedButton2: TSpeedButton
    Left = 77
    Top = 18
    Width = 61
    Height = 42
    GroupIndex = 1
    Caption = '531f'
  end
  object SpeedButton3: TSpeedButton
    Left = 138
    Top = 18
    Width = 61
    Height = 42
    GroupIndex = 1
    Caption = '570'
  end
  object SpeedButton4: TSpeedButton
    Left = 199
    Top = 18
    Width = 61
    Height = 42
    GroupIndex = 1
    Caption = '570f'
  end
  object OKBtn: TButton
    Left = 287
    Top = 234
    Width = 135
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1080' '#1074#1099#1081#1090#1080
    Default = True
    ModalResult = 1
    TabOrder = 0
    OnClick = OKBtnClick
  end
  object CancelBtn: TButton
    Left = 287
    Top = 265
    Width = 135
    Height = 25
    Cancel = True
    Caption = #1054#1090#1084#1077#1085#1080#1090#1100
    ModalResult = 2
    TabOrder = 1
  end
  object Button1: TButton
    Left = 287
    Top = 8
    Width = 135
    Height = 25
    Caption = #1054#1090#1082#1088#1099#1090#1100' '#1072#1088#1093#1080#1074
    TabOrder = 2
    OnClick = Button1Click
  end
  object PhImage1: TPhImage
    Left = 16
    Top = 72
    Width = 244
    Height = 209
    AutoMosaic = True
    ThumbWidht = 128
    ThumbHeight = 128
    SlideShowInterval = 500
    ParentColor = False
  end
end
