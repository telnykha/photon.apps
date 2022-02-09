object experimentTableForm: TexperimentTableForm
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsSizeToolWin
  Caption = 'experimentTableForm'
  ClientHeight = 456
  ClientWidth = 421
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 416
    Width = 421
    Height = 40
    Align = alBottom
    TabOrder = 0
    object Gauge1: TGauge
      Left = 8
      Top = 8
      Width = 322
      Height = 25
      Progress = 0
    end
    object Button1: TButton
      Left = 336
      Top = 8
      Width = 75
      Height = 25
      Caption = #1054#1090#1084#1077#1085#1080#1090#1100
      TabOrder = 0
    end
  end
  object StringGrid1: TStringGrid
    Left = 0
    Top = 0
    Width = 421
    Height = 416
    Align = alClient
    TabOrder = 1
    ExplicitLeft = 224
    ExplicitTop = 256
    ExplicitWidth = 320
    ExplicitHeight = 120
  end
end
