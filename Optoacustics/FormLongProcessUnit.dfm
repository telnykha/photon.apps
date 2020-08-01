object LongProcessForm: TLongProcessForm
  Left = 0
  Top = 0
  BorderStyle = bsNone
  Caption = 'LongProcessForm'
  ClientHeight = 85
  ClientWidth = 529
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
  object Label1: TLabel
    Left = 8
    Top = 59
    Width = 31
    Height = 13
    Caption = 'Label1'
  end
  object CGauge1: TCGauge
    Left = 8
    Top = 8
    Width = 505
    Height = 37
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 40
    Top = 24
  end
end
