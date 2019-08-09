object OptionsDlg: TOptionsDlg
  Left = 227
  Top = 108
  BorderStyle = bsDialog
  Caption = #1054#1087#1094#1080#1080
  ClientHeight = 248
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
    Height = 233
    Shape = bsFrame
  end
  object Label2: TLabel
    Left = 24
    Top = 19
    Width = 171
    Height = 13
    Caption = #1056#1072#1089#1087#1086#1083#1086#1078#1077#1085#1080#1077' '#1072#1088#1093#1080#1074#1072' '#1076#1083#1103' '#1079#1072#1087#1080#1089#1080
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
  object DirectoryListBox1: TDirectoryListBox
    Left = 24
    Top = 40
    Width = 241
    Height = 129
    TabOrder = 2
  end
  object DriveComboBox1: TDriveComboBox
    Left = 24
    Top = 184
    Width = 241
    Height = 19
    DirList = DirectoryListBox1
    TabOrder = 3
  end
  object CheckBox1: TCheckBox
    Left = 24
    Top = 211
    Width = 249
    Height = 17
    Caption = #1054#1090#1082#1088#1099#1074#1072#1090#1100' '#1072#1088#1093#1080#1074' '#1087#1088#1080' '#1079#1072#1074#1077#1088#1096#1077#1085#1080#1080' '#1080#1079#1084#1077#1088#1077#1085#1080#1081
    TabOrder = 4
  end
end
