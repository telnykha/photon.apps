object dictinaryEditDlg: TdictinaryEditDlg
  Left = 227
  Top = 108
  BorderStyle = bsDialog
  Caption = #1056#1077#1076#1072#1082#1090#1086#1088' '#1103#1088#1083#1099#1082#1086#1074
  ClientHeight = 202
  ClientWidth = 379
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object OKBtn: TButton
    Left = 199
    Top = 167
    Width = 172
    Height = 25
    Caption = #1047#1072#1082#1088#1099#1090#1100
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
  object Button1: TButton
    Left = 199
    Top = 8
    Width = 172
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100'...'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 199
    Top = 43
    Width = 172
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100'...'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 199
    Top = 74
    Width = 172
    Height = 25
    Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100'...'
    TabOrder = 3
    OnClick = Button3Click
  end
  object ListBox1: TListBox
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 185
    Height = 196
    Align = alLeft
    ItemHeight = 13
    TabOrder = 4
  end
  object Button4: TButton
    Left = 199
    Top = 105
    Width = 172
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1089#1086#1083#1086#1074#1072#1088#1100'...'
    Enabled = False
    TabOrder = 5
    Visible = False
  end
  object Button5: TButton
    Left = 199
    Top = 136
    Width = 172
    Height = 25
    Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1089#1086#1083#1086#1074#1072#1088#1100'...'
    Enabled = False
    TabOrder = 6
    Visible = False
  end
end
