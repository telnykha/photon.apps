object dictinaryItemDlg: TdictinaryItemDlg
  Left = 227
  Top = 108
  BorderStyle = bsDialog
  Caption = #1056#1077#1076#1072#1082#1090#1086#1088' '#1103#1088#1083#1099#1082#1072
  ClientHeight = 219
  ClientWidth = 319
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poOwnerFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 225
    Height = 203
    Shape = bsFrame
  end
  object Label1: TLabel
    Left = 16
    Top = 19
    Width = 33
    Height = 13
    Caption = #1071#1088#1083#1099#1082
  end
  object Label2: TLabel
    Left = 18
    Top = 56
    Width = 93
    Height = 13
    Caption = #1064#1080#1088#1080#1085#1072' '#1072#1087#1077#1088#1090#1091#1088#1099
  end
  object Label3: TLabel
    Left = 18
    Top = 88
    Width = 90
    Height = 13
    Caption = #1042#1099#1089#1086#1090#1072' '#1072#1087#1077#1088#1090#1091#1088#1099
  end
  object Label4: TLabel
    Left = 18
    Top = 110
    Width = 67
    Height = 13
    Caption = #1062#1074#1077#1090' '#1103#1088#1083#1099#1082#1072
  end
  object OKBtn: TButton
    Left = 239
    Top = 8
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
  object CancelBtn: TButton
    Left = 239
    Top = 38
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object Edit1: TEdit
    Left = 96
    Top = 16
    Width = 121
    Height = 21
    TabOrder = 2
    Text = 'new item'
  end
  object SpinEdit1: TSpinEdit
    Left = 155
    Top = 46
    Width = 62
    Height = 22
    Enabled = False
    Increment = 2
    MaxValue = 64
    MinValue = 8
    TabOrder = 3
    Value = 24
  end
  object SpinEdit2: TSpinEdit
    Left = 155
    Top = 78
    Width = 62
    Height = 22
    Enabled = False
    Increment = 2
    MaxValue = 64
    MinValue = 8
    TabOrder = 4
    Value = 24
  end
  object ColorGrid1: TColorGrid
    Left = 113
    Top = 110
    Width = 104
    Height = 88
    ClickEnablesColor = True
    ForegroundIndex = 2
    BackgroundIndex = 3
    BackgroundEnabled = False
    TabOrder = 5
    OnClick = ColorGrid1Click
  end
  object Panel1: TPanel
    Left = 24
    Top = 136
    Width = 70
    Height = 62
    Color = clRed
    ParentBackground = False
    ShowCaption = False
    TabOrder = 6
  end
end
