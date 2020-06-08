object Form3: TForm3
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072' '#1087#1072#1088#1072#1084#1077#1090#1088#1086#1074' '#1087#1088#1086#1075#1088#1072#1084#1084#1099
  ClientHeight = 312
  ClientWidth = 501
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 169
    Height = 89
    Caption = #1050#1088#1072#1077#1074#1072#1103' '#1086#1073#1083#1072#1089#1090#1100
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 27
      Width = 46
      Height = 13
      Caption = #1056#1072#1079#1084#1077#1088#1099' '
    end
    object borderCB: TCheckBox
      Left = 16
      Top = 61
      Width = 97
      Height = 17
      Caption = #1054#1090#1086#1073#1088#1072#1078#1072#1090#1100' '
      TabOrder = 0
    end
    object borderSizeSE: TSpinEdit
      Left = 80
      Top = 24
      Width = 73
      Height = 22
      MaxValue = 100
      MinValue = 20
      TabOrder = 1
      Value = 20
    end
  end
  object outRG: TRadioGroup
    Left = 183
    Top = 9
    Width = 161
    Height = 89
    Caption = #1060#1086#1088#1084#1072#1090' '#1074#1099#1093#1086#1076#1085#1099#1093' '#1076#1072#1085#1085#1099#1093
    Enabled = False
    ItemIndex = 0
    Items.Strings = (
      'RAW '
      'TIFF')
    TabOrder = 1
  end
  object inputRG: TRadioGroup
    Left = 350
    Top = 8
    Width = 145
    Height = 89
    Caption = #1060#1086#1088#1084#1072#1090' '#1074#1093#1086#1076#1085#1099#1093' '#1076#1072#1085#1085#1099#1093
    ItemIndex = 0
    Items.Strings = (
      '8 '#1073#1080#1090
      '12 '#1073#1080#1090)
    TabOrder = 2
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 104
    Width = 169
    Height = 89
    Caption = #1057#1098#1077#1084#1082#1072' '#1089#1077#1088#1080#1081
    TabOrder = 3
    object Интервал: TLabel
      Left = 12
      Top = 24
      Width = 49
      Height = 13
      Caption = #1048#1085#1090#1077#1088#1074#1072#1083
    end
    object Label2: TLabel
      Left = 12
      Top = 59
      Width = 25
      Height = 13
      Caption = #1063#1080#1083#1086
    end
    object seriesIntervalSE: TSpinEdit
      Left = 80
      Top = 21
      Width = 73
      Height = 22
      MaxValue = 300
      MinValue = 5
      TabOrder = 0
      Value = 20
    end
    object seriesTotalSE: TSpinEdit
      Left = 80
      Top = 56
      Width = 73
      Height = 22
      MaxValue = 9000
      MinValue = 10
      TabOrder = 1
      Value = 20
    end
  end
  object priRG: TRadioGroup
    Left = 184
    Top = 104
    Width = 160
    Height = 89
    Caption = #1054#1090#1086#1073#1088#1072#1078#1077#1085#1080#1077' PRI'
    ItemIndex = 0
    Items.Strings = (
      #1054#1090#1090#1077#1085#1082#1080' '#1089#1077#1088#1086#1075#1086
      #1055#1072#1083#1080#1090#1088#1072)
    TabOrder = 4
  end
  object GroupBox3: TGroupBox
    Left = 350
    Top = 104
    Width = 145
    Height = 90
    Caption = 'Arduino'
    Enabled = False
    TabOrder = 5
    object Label3: TLabel
      Left = 13
      Top = 24
      Width = 29
      Height = 13
      Caption = #1055#1086#1088#1090':'
    end
    object arduinoCombo: TComboBox
      Left = 13
      Top = 48
      Width = 118
      Height = 21
      Style = csDropDownList
      ItemIndex = 3
      TabOrder = 0
      Text = 'COM 4'
      Items.Strings = (
        'COM 1'
        'COM 2'
        'COM 3'
        'COM 4'
        'COM 5'
        'COM 6'
        'COM 7'
        ''
        '')
    end
  end
  object Button1: TButton
    Left = 351
    Top = 279
    Width = 145
    Height = 25
    Caption = #1042#1099#1093#1086#1076' '#1073#1077#1079' '#1089#1086#1093#1088#1072#1085#1077#1085#1080#1103
    TabOrder = 6
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 184
    Top = 279
    Width = 161
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1080' '#1074#1099#1081#1090#1080
    TabOrder = 7
    OnClick = Button2Click
  end
  object GroupBox4: TGroupBox
    Left = 8
    Top = 199
    Width = 487
    Height = 74
    Caption = #1040#1088#1093#1080#1074
    TabOrder = 8
    object CheckBox1: TCheckBox
      Left = 8
      Top = 42
      Width = 181
      Height = 26
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1080#1089#1093#1086#1076#1085#1099#1077' '#1076#1072#1085#1085#1099#1077
      Checked = True
      State = cbChecked
      TabOrder = 0
    end
    object Edit1: TEdit
      Left = 8
      Top = 19
      Width = 425
      Height = 21
      ReadOnly = True
      TabOrder = 1
      Text = 'Edit1'
    end
    object Button3: TButton
      Left = 439
      Top = 16
      Width = 43
      Height = 25
      Caption = '...'
      TabOrder = 2
      OnClick = Button3Click
    end
  end
end
