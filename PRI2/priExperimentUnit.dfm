object experimentForm: TexperimentForm
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsToolWindow
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072' '#1089#1098#1077#1084#1082#1080' '#1089#1077#1088#1080#1081
  ClientHeight = 199
  ClientWidth = 359
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 169
    Height = 153
    Caption = #1048#1089#1087#1086#1083#1100#1079#1086#1074#1072#1090#1100' '#1092#1080#1083#1100#1090#1088#1099
    TabOrder = 0
    object CheckListBox1: TCheckListBox
      Left = 16
      Top = 24
      Width = 129
      Height = 113
      ItemHeight = 13
      Items.Strings = (
        '- BP448'
        '- BP510'
        '- BP532'
        '- BP546'
        '- BP572'
        '- BP685')
      TabOrder = 0
    end
  end
  object Button1: TButton
    Left = 80
    Top = 167
    Width = 225
    Height = 25
    Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100' '#1089#1098#1077#1084#1082#1091
    TabOrder = 1
    OnClick = Button1Click
  end
  object GroupBox2: TGroupBox
    Left = 183
    Top = 8
    Width = 169
    Height = 153
    Caption = #1057#1098#1077#1084#1082#1072' '#1089#1077#1088#1080#1081
    TabOrder = 2
    object Interval: TLabel
      Left = 12
      Top = 24
      Width = 80
      Height = 13
      Caption = #1048#1085#1090#1077#1088#1074#1072#1083' ('#1089#1077#1082') '
    end
    object Label2: TLabel
      Left = 12
      Top = 59
      Width = 30
      Height = 13
      Caption = #1063#1080#1089#1083#1086
    end
    object seriesIntervalSE: TSpinEdit
      Left = 98
      Top = 21
      Width = 55
      Height = 22
      MaxValue = 300
      MinValue = 1
      TabOrder = 0
      Value = 20
    end
    object seriesTotalSE: TSpinEdit
      Left = 98
      Top = 56
      Width = 55
      Height = 22
      MaxValue = 20
      MinValue = 1
      TabOrder = 1
      Value = 20
    end
  end
end
