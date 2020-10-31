object exportImagesDlg: TexportImagesDlg
  Left = 227
  Top = 108
  BorderStyle = bsDialog
  Caption = #1069#1082#1089#1087#1086#1088#1090' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1081
  ClientHeight = 238
  ClientWidth = 347
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object OKBtn: TButton
    Left = 263
    Top = 8
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
  object CancelBtn: TButton
    Left = 264
    Top = 39
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object DriveComboBox1: TDriveComboBox
    Left = 8
    Top = 167
    Width = 145
    Height = 19
    DirList = DirectoryListBox1
    TabOrder = 2
  end
  object DirectoryListBox1: TDirectoryListBox
    Left = 8
    Top = 39
    Width = 145
    Height = 122
    TabOrder = 3
    OnChange = DirectoryListBox1Change
  end
  object RadioGroup1: TRadioGroup
    Left = 160
    Top = 39
    Width = 97
    Height = 147
    Caption = #1060#1086#1088#1084#1072#1090
    ItemIndex = 2
    Items.Strings = (
      'JPEG'
      'BMP'
      'PNG'
      'TIFF'
      'AWP (raw) ')
    TabOrder = 4
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 192
    Width = 249
    Height = 40
    TabOrder = 5
    object Label1: TLabel
      Left = 11
      Top = 11
      Width = 131
      Height = 13
      Caption = #1069#1082#1089#1087#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100' '#1082#1072#1078#1076#1099#1081' '
    end
    object Label2: TLabel
      Left = 208
      Top = 11
      Width = 25
      Height = 13
      Caption = #1082#1072#1076#1088
    end
    object Edit1: TEdit
      Left = 152
      Top = 8
      Width = 41
      Height = 21
      TabOrder = 0
      Text = '10'
      OnChange = Edit1Change
      OnEnter = Edit1Enter
      OnExit = Edit1Exit
    end
  end
  object Edit2: TEdit
    Left = 8
    Top = 8
    Width = 249
    Height = 21
    TabOrder = 6
  end
end
