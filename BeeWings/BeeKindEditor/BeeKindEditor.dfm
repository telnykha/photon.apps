object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 330
  ClientWidth = 595
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 16
  object Label1: TLabel
    Left = 151
    Top = 8
    Width = 144
    Height = 16
    Cursor = crDrag
    Caption = #1054#1087#1088#1077#1076#1077#1083#1077#1085#1080#1077' '#1087#1088#1080#1079#1085#1072#1082#1086#1074
    Color = clBackground
    ParentColor = False
  end
  object SpeedButton1: TSpeedButton
    Left = 183
    Top = 92
    Width = 66
    Height = 33
    Caption = 'Calculate'
    OnClick = SpeedButton1Click
  end
  object Label2: TLabel
    Left = 32
    Top = 40
    Width = 11
    Height = 16
    Caption = 'Ci'
    StyleName = 'strong'
  end
  object Label3: TLabel
    Left = 159
    Top = 40
    Width = 22
    Height = 16
    Caption = 'DsA'
  end
  object Label4: TLabel
    Left = 286
    Top = 40
    Width = 11
    Height = 16
    Caption = 'Hi'
  end
  object SpeedButton2: TSpeedButton
    Left = 476
    Top = 147
    Width = 104
    Height = 33
    Caption = 'Add Kind'
    OnClick = SpeedButton2Click
  end
  object SpeedButton3: TSpeedButton
    Left = 476
    Top = 186
    Width = 104
    Height = 33
    Caption = 'Delete Kind'
    OnClick = SpeedButton3Click
  end
  object Edit1: TEdit
    Left = 32
    Top = 62
    Width = 121
    Height = 24
    HelpType = htKeyword
    Ctl3D = True
    ParentCtl3D = False
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 159
    Top = 62
    Width = 121
    Height = 24
    TabOrder = 1
  end
  object Edit3: TEdit
    Left = 286
    Top = 62
    Width = 121
    Height = 24
    TabOrder = 2
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 147
    Width = 449
    Height = 142
    DefaultColWidth = 80
    FixedCols = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSelect, goFixedRowDefAlign]
    TabOrder = 3
  end
  object Button1: TButton
    Left = 476
    Top = 225
    Width = 104
    Height = 32
    Caption = 'Edit'
    TabOrder = 4
    OnClick = Button1Click
  end
end
