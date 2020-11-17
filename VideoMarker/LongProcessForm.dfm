object LongProcDlg: TLongProcDlg
  Left = 0
  Top = 0
  BorderStyle = bsNone
  Caption = 'LongProcDlg'
  ClientHeight = 83
  ClientWidth = 489
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 120
  TextHeight = 16
  object Label1: TLabel
    Left = 8
    Top = 59
    Width = 4
    Height = 16
  end
  object Label2: TLabel
    Left = 8
    Top = 8
    Width = 240
    Height = 18
    Caption = #1069#1082#1089#1087#1086#1088#1090' '#1088#1072#1079#1084#1077#1095#1077#1085#1085#1099#1093' '#1082#1072#1076#1088#1086#1074': '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object ProgressBar1: TProgressBar
    Left = 8
    Top = 30
    Width = 470
    Height = 21
    TabOrder = 0
  end
  object Button1: TButton
    Left = 403
    Top = 55
    Width = 75
    Height = 25
    Caption = #1057#1090#1086#1087
    TabOrder = 1
    OnClick = Button1Click
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 8
    Top = 32
  end
end
