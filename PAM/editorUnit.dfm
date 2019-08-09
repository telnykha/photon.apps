object editorDlg: TeditorDlg
  Left = 227
  Top = 108
  BorderStyle = bsDialog
  Caption = 'Dialog'
  ClientHeight = 217
  ClientWidth = 384
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 281
    Height = 201
    Shape = bsFrame
  end
  object Label1: TLabel
    Left = 16
    Top = 16
    Width = 47
    Height = 13
    Caption = #1050#1086#1084#1072#1085#1076#1072' '
  end
  object Label2: TLabel
    Left = 16
    Top = 59
    Width = 130
    Height = 13
    Caption = #1048#1085#1090#1077#1085#1089#1080#1074#1085#1086#1089#1090#1100' '#1089#1074#1077#1095#1077#1085#1080#1103' '
  end
  object Label3: TLabel
    Left = 16
    Top = 109
    Width = 100
    Height = 13
    Caption = #1044#1083#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100' (ms) '
  end
  object Label4: TLabel
    Left = 16
    Top = 160
    Width = 67
    Height = 13
    Caption = #1050#1086#1084#1084#1077#1085#1090#1072#1088#1080#1081
  end
  object OKBtn: TButton
    Left = 300
    Top = 8
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
  object CancelBtn: TButton
    Left = 300
    Top = 38
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object ComboBox1: TComboBox
    Left = 16
    Top = 32
    Width = 265
    Height = 21
    Style = csDropDownList
    ItemIndex = 4
    TabOrder = 2
    Text = #1042#1099#1082#1083#1102#1095#1080#1090#1100' '#1074#1089#1077
    OnChange = ComboBox1Change
    Items.Strings = (
      #1042#1082#1083#1102#1095#1080#1090#1100' '#1087#1088#1086#1078#1077#1082#1090#1086#1088' 460 nm'
      #1042#1082#1083#1102#1095#1080#1090#1100' '#1087#1088#1086#1078#1077#1082#1090#1086#1088' 660 nm '
      #1042#1082#1083#1102#1095#1080#1090#1100' '#1087#1088#1086#1078#1077#1082#1090#1086#1088' 660 nm '#1080' '#1092#1086#1090#1086
      #1055#1086#1083#1091#1095#1080#1090#1100' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077
      #1042#1099#1082#1083#1102#1095#1080#1090#1100' '#1074#1089#1077
      #1042#1082#1083#1102#1095#1080#1090#1100' '#1087#1088#1086#1078#1077#1082#1090#1086#1088' 460 nm '#1080' '#1092#1086#1090#1086)
  end
  object ComboBox2: TComboBox
    Left = 16
    Top = 80
    Width = 265
    Height = 21
    Style = csDropDownList
    ItemIndex = 0
    TabOrder = 3
    Text = #1042#1099#1089#1086#1082#1072#1103
    Items.Strings = (
      #1042#1099#1089#1086#1082#1072#1103
      #1057#1088#1077#1076#1085#1103#1103
      #1053#1080#1079#1082#1072#1103)
  end
  object SpinEdit1: TSpinEdit
    Left = 16
    Top = 128
    Width = 100
    Height = 22
    MaxValue = 10000
    MinValue = 1
    TabOrder = 4
    Value = 10
  end
  object Edit1: TEdit
    Left = 16
    Top = 176
    Width = 265
    Height = 21
    TabOrder = 5
  end
end
