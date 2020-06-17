object ExportPriDlg: TExportPriDlg
  Left = 227
  Top = 108
  BorderStyle = bsDialog
  Caption = #1069#1082#1089#1087#1086#1088#1090' PRI '
  ClientHeight = 256
  ClientWidth = 509
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 412
    Height = 241
    Shape = bsFrame
  end
  object OKBtn: TButton
    Left = 426
    Top = 8
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
  object CancelBtn: TButton
    Left = 426
    Top = 38
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object DriveComboBox1: TDriveComboBox
    Left = 16
    Top = 217
    Width = 209
    Height = 19
    DirList = DirectoryListBox1
    TabOrder = 2
  end
  object DirectoryListBox1: TDirectoryListBox
    Left = 16
    Top = 48
    Width = 209
    Height = 163
    TabOrder = 3
  end
  object Button1: TButton
    Left = 16
    Top = 17
    Width = 209
    Height = 25
    Caption = #1057#1086#1079#1076#1072#1090#1100' '#1087#1072#1087#1082#1091
    TabOrder = 4
    OnClick = Button1Click
  end
  object RadioGroup1: TRadioGroup
    Left = 231
    Top = 17
    Width = 170
    Height = 121
    Caption = #1060#1080#1083#1100#1090#1088#1072#1094#1080#1103
    ItemIndex = 0
    Items.Strings = (
      #1041#1077#1079' '#1091#1089#1088#1077#1076#1085#1077#1085#1080#1103' '
      #1059#1089#1088#1077#1076#1085#1077#1085#1080#1077' 3x3 '#1087#1080#1082#1089#1077#1083#1103' '
      #1059#1089#1088#1077#1076#1085#1077#1085#1080#1077' 5'#1093'5 '#1087#1080#1082#1089#1077#1083#1077#1081)
    TabOrder = 5
  end
  object CheckBox1: TCheckBox
    Left = 231
    Top = 144
    Width = 169
    Height = 34
    BiDiMode = bdLeftToRight
    Caption = #1048#1089#1087#1086#1083#1100#1079#1086#1074#1072#1090#1100' '#1103#1088#1082#1086#1089#1090#1085#1091#1102' '#1082#1072#1083#1080#1073#1088#1086#1074#1082#1091
    ParentBiDiMode = False
    TabOrder = 6
    WordWrap = True
  end
  object CheckBox2: TCheckBox
    Left = 231
    Top = 184
    Width = 137
    Height = 41
    Caption = #1054#1090#1082#1088#1099#1090#1100' '#1076#1072#1085#1085#1099#1077' '#1074' '#1087#1088#1086#1074#1086#1076#1085#1080#1082#1077
    Checked = True
    State = cbChecked
    TabOrder = 7
    WordWrap = True
  end
end
