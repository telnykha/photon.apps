object SelectDirDlg: TSelectDirDlg
  Left = 227
  Top = 108
  BorderStyle = bsDialog
  Caption = #1042#1099#1073#1086#1088' '#1087#1072#1087#1082#1080
  ClientHeight = 206
  ClientWidth = 305
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object OKBtn: TButton
    Left = 223
    Top = 8
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
  object CancelBtn: TButton
    Left = 223
    Top = 38
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object DirectoryListBox1: TDirectoryListBox
    Left = 8
    Top = 8
    Width = 209
    Height = 163
    TabOrder = 2
  end
  object DriveComboBox1: TDriveComboBox
    Left = 8
    Top = 176
    Width = 209
    Height = 19
    DirList = DirectoryListBox1
    TabOrder = 3
  end
  object Button1: TButton
    Left = 223
    Top = 174
    Width = 75
    Height = 25
    Caption = #1057#1086#1079#1076#1072#1090#1100
    TabOrder = 4
    Visible = False
    OnClick = Button1Click
  end
end
