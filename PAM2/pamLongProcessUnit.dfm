object LongProcessForm: TLongProcessForm
  Left = 0
  Top = 0
  BorderStyle = bsNone
  Caption = 'LongProcessForm'
  ClientHeight = 140
  ClientWidth = 447
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Gauge1: TGauge
    AlignWithMargins = True
    Left = 8
    Top = 24
    Width = 425
    Height = 22
    BackColor = clBlack
    BorderStyle = bsNone
    ForeColor = clBlue
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    Progress = 25
  end
  object Gauge2: TGauge
    AlignWithMargins = True
    Left = 8
    Top = 72
    Width = 425
    Height = 22
    BackColor = clBlack
    BorderStyle = bsNone
    ForeColor = clBlue
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    Progress = 25
  end
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 88
    Height = 13
    Caption = #1050#1086#1084#1072#1085#1076#1072' '#1093#1093' '#1080#1079' '#1091#1091
  end
  object Label2: TLabel
    Left = 8
    Top = 56
    Width = 143
    Height = 13
    Caption = #1042#1088#1077#1084#1103' '#1074#1099#1087#1086#1083#1085#1077#1085#1080#1103' '#1082#1086#1084#1072#1085#1076#1099
  end
  object Label3: TLabel
    Left = 8
    Top = 119
    Width = 109
    Height = 13
    Caption = #1042#1099#1087#1086#1083#1085#1103#1077#1090#1089#1103' '#1089#1082#1088#1080#1087#1090'.'
  end
  object Button1: TButton
    Left = 312
    Top = 107
    Width = 121
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1080#1090#1100
    TabOrder = 0
    OnClick = Button1Click
  end
end
