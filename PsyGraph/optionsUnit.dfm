object OptionsDlg: TOptionsDlg
  Left = 227
  Top = 108
  BorderStyle = bsDialog
  Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099
  ClientHeight = 213
  ClientWidth = 434
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 337
    Height = 196
    Shape = bsFrame
  end
  object OKBtn: TButton
    Left = 351
    Top = 8
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
  object CancelBtn: TButton
    Left = 351
    Top = 38
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object CheckBox1: TCheckBox
    Left = 16
    Top = 16
    Width = 313
    Height = 17
    Caption = #1054#1090#1082#1088#1099#1074#1072#1090#1100' '#1073#1072#1079#1091' '#1076#1072#1085#1085#1099#1093' '#1080#1089#1089#1083#1077#1076#1086#1074#1072#1085#1080#1103' '#1087#1088#1080' '#1079#1072#1087#1091#1089#1082#1077
    TabOrder = 2
  end
  object GroupBox1: TGroupBox
    Left = 16
    Top = 40
    Width = 281
    Height = 89
    Caption = #1056#1072#1079#1084#1077#1088#1099' '#1083#1080#1089#1090#1072
    TabOrder = 3
    object Label1: TLabel
      Left = 8
      Top = 32
      Width = 72
      Height = 13
      Caption = #1064#1080#1088#1080#1085#1072' '#1083#1080#1089#1090#1072
    end
    object Label2: TLabel
      Left = 8
      Top = 61
      Width = 69
      Height = 13
      Caption = #1042#1099#1089#1086#1090#1072' '#1083#1080#1089#1090#1072
    end
    object Label3: TLabel
      Left = 256
      Top = 32
      Width = 12
      Height = 13
      Caption = #1084#1084
    end
    object Label4: TLabel
      Left = 256
      Top = 56
      Width = 12
      Height = 13
      Caption = #1084#1084
    end
    object SpinEdit1: TSpinEdit
      Left = 128
      Top = 24
      Width = 121
      Height = 22
      MaxValue = 500
      MinValue = 10
      TabOrder = 0
      Value = 10
    end
    object SpinEdit2: TSpinEdit
      Left = 128
      Top = 52
      Width = 121
      Height = 22
      MaxValue = 500
      MinValue = 10
      TabOrder = 1
      Value = 10
    end
  end
  object GroupBox2: TGroupBox
    Left = 16
    Top = 136
    Width = 281
    Height = 57
    Caption = #1063#1091#1074#1089#1090#1074#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100' '#1076#1077#1090#1077#1082#1090#1086#1088#1072
    TabOrder = 4
    object Label5: TLabel
      Left = 239
      Top = 24
      Width = 26
      Height = 13
      Caption = 'xx %'
    end
    object TrackBar1: TTrackBar
      Left = 16
      Top = 17
      Width = 209
      Height = 37
      Max = 100
      Frequency = 5
      TabOrder = 0
      ThumbLength = 10
      TickMarks = tmBoth
      OnChange = TrackBar1Change
    end
  end
end
