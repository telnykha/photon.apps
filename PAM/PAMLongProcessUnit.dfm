object PAMLongProcessForm: TPAMLongProcessForm
  Left = 0
  Top = 0
  BorderStyle = bsNone
  Caption = 'PAMLongProcessForm'
  ClientHeight = 117
  ClientWidth = 487
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Gauge1: TGauge
    Left = 8
    Top = 32
    Width = 471
    Height = 41
    Progress = 0
  end
  object Label1: TLabel
    Left = 13
    Top = 8
    Width = 31
    Height = 13
    Caption = 'Label1'
  end
  object Button1: TButton
    Left = 404
    Top = 84
    Width = 75
    Height = 25
    Caption = #1054#1089#1090#1072#1085#1086#1074#1080#1090#1100
    TabOrder = 0
    OnClick = Button1Click
  end
end
