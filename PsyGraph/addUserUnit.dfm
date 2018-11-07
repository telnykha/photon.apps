object AddUserDialog: TAddUserDialog
  Left = 227
  Top = 108
  BorderStyle = bsDialog
  Caption = #1055#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1080' ('#1080#1089#1087#1099#1090#1091#1077#1084#1099#1077')'
  ClientHeight = 175
  ClientWidth = 384
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 13
    Top = 8
    Width = 281
    Height = 161
    Shape = bsFrame
  end
  object Label1: TLabel
    Left = 32
    Top = 48
    Width = 19
    Height = 13
    Caption = #1048#1084#1103
  end
  object Label2: TLabel
    Left = 32
    Top = 21
    Width = 44
    Height = 13
    Caption = #1060#1072#1084#1080#1083#1080#1103
  end
  object Label3: TLabel
    Left = 32
    Top = 75
    Width = 40
    Height = 13
    Caption = #1042#1086#1079#1088#1072#1089#1090
  end
  object Label4: TLabel
    Left = 32
    Top = 107
    Width = 19
    Height = 13
    Caption = #1055#1086#1083
  end
  object Label5: TLabel
    Left = 32
    Top = 139
    Width = 78
    Height = 13
    Caption = #1057#1087#1077#1094#1080#1072#1083#1080#1079#1072#1094#1080#1103
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
  object DBEdit1: TDBEdit
    Left = 119
    Top = 45
    Width = 162
    Height = 21
    DataField = 'FirstName'
    DataSource = DataModule1.DataSource2
    TabOrder = 3
  end
  object DBEdit2: TDBEdit
    Left = 119
    Top = 18
    Width = 162
    Height = 21
    DataField = 'LastName'
    DataSource = DataModule1.DataSource2
    TabOrder = 2
  end
  object DBEdit3: TDBEdit
    Left = 119
    Top = 72
    Width = 162
    Height = 21
    DataField = 'Age'
    DataSource = DataModule1.DataSource2
    TabOrder = 4
  end
  object DBLookupComboBox1: TDBLookupComboBox
    Left = 119
    Top = 99
    Width = 162
    Height = 21
    DataField = 'GenderId'
    DataSource = DataModule1.DataSource2
    KeyField = 'GenderId'
    ListField = 'Gender'
    ListSource = DataModule1.DataSource3
    TabOrder = 5
  end
  object DBLookupComboBox2: TDBLookupComboBox
    Left = 119
    Top = 131
    Width = 131
    Height = 21
    DataField = 'WorkTypeId'
    DataSource = DataModule1.DataSource2
    KeyField = 'WorkTypeId'
    ListField = 'WorkType'
    ListSource = DataModule1.DataSource4
    TabOrder = 6
  end
  object Button1: TButton
    Left = 256
    Top = 130
    Width = 25
    Height = 25
    Caption = '...'
    TabOrder = 7
    OnClick = Button1Click
  end
end
