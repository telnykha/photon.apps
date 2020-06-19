object CalibrationDlg: TCalibrationDlg
  Left = 227
  Top = 108
  BorderStyle = bsDialog
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072' '#1103#1088#1082#1086#1089#1090#1085#1086#1081' '#1082#1072#1083#1080#1073#1088#1086#1074#1082#1080
  ClientHeight = 322
  ClientWidth = 428
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 273
    Height = 306
    Shape = bsFrame
  end
  object SpeedButton1: TSpeedButton
    Left = 16
    Top = 18
    Width = 61
    Height = 42
    GroupIndex = 1
    Down = True
    Caption = '531'
    OnClick = SpeedButton1Click
  end
  object SpeedButton2: TSpeedButton
    Left = 77
    Top = 18
    Width = 61
    Height = 42
    GroupIndex = 1
    Caption = '531f'
    OnClick = SpeedButton2Click
  end
  object SpeedButton3: TSpeedButton
    Left = 138
    Top = 18
    Width = 61
    Height = 42
    GroupIndex = 1
    Caption = '570'
    OnClick = SpeedButton3Click
  end
  object SpeedButton4: TSpeedButton
    Left = 199
    Top = 18
    Width = 61
    Height = 42
    GroupIndex = 1
    Caption = '570f'
    OnClick = SpeedButton4Click
  end
  object Label1: TLabel
    Left = 16
    Top = 288
    Width = 71
    Height = 13
    Caption = #1054#1090#1086#1073#1088#1072#1078#1072#1090#1100': '
  end
  object OKBtn: TButton
    Left = 287
    Top = 39
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
    Top = 70
    Width = 135
    Height = 25
    Cancel = True
    Caption = #1042#1099#1093#1086#1076' '#1073#1077#1079' '#1089#1086#1093#1088#1072#1085#1077#1085#1080#1103
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
    Top = 66
    Width = 244
    Height = 209
    AutoMosaic = True
    ThumbWidht = 128
    ThumbHeight = 128
    SlideShowInterval = 500
    ParentColor = False
    OnMouseMove = PhImage1MouseMove
    OnMouseUp = PhImage1MouseUp
  end
  object ComboBox1: TComboBox
    Left = 93
    Top = 285
    Width = 167
    Height = 21
    Style = csDropDownList
    ItemIndex = 0
    TabOrder = 4
    Text = #1048#1089#1093#1086#1076#1085#1099#1077' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1103
    OnChange = ComboBox1Change
    Items.Strings = (
      #1048#1089#1093#1086#1076#1085#1099#1077' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1103
      #1050#1072#1083#1080#1073#1088#1086#1074#1086#1095#1085#1099#1077' '#1079#1085#1072#1095#1077#1085#1080#1103)
  end
  object GroupBox1: TGroupBox
    Left = 287
    Top = 234
    Width = 133
    Height = 80
    Caption = #1047#1085#1072#1095#1077#1085#1080#1103
    TabOrder = 5
    object Label2: TLabel
      Left = 6
      Top = 22
      Width = 31
      Height = 13
      Caption = 'Label2'
    end
    object Label3: TLabel
      Left = 6
      Top = 41
      Width = 31
      Height = 13
      Caption = 'Label3'
    end
    object Label4: TLabel
      Left = 6
      Top = 59
      Width = 31
      Height = 13
      Caption = 'Label4'
    end
  end
  object GroupBox2: TGroupBox
    Left = 287
    Top = 120
    Width = 133
    Height = 108
    Caption = #1054#1073#1083#1072#1089#1090#1100' '#1082#1072#1083#1080#1073#1088#1086#1074#1082#1080
    TabOrder = 6
    object Label5: TLabel
      Left = 6
      Top = 22
      Width = 35
      Height = 13
      Caption = #1083#1077#1074#1099#1081' '
    end
    object Label6: TLabel
      Left = 6
      Top = 41
      Width = 42
      Height = 13
      Caption = #1074#1077#1088#1093#1085#1080#1081
    end
    object Label7: TLabel
      Left = 6
      Top = 59
      Width = 38
      Height = 14
      Caption = #1096#1080#1088#1080#1085#1072
    end
    object Label8: TLabel
      Left = 6
      Top = 78
      Width = 37
      Height = 13
      Caption = #1074#1099#1089#1086#1090#1072
    end
  end
  object PhSelRectTool1: TPhSelRectTool
    PhImage = PhImage1
    Left = 32
    Top = 80
  end
end
