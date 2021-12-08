object kindEditorForm: TkindEditorForm
  Left = 0
  Top = 0
  Caption = #1056#1077#1076#1072#1082#1090#1086#1088' '#1087#1086#1088#1086#1076
  ClientHeight = 328
  ClientWidth = 590
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 16
  object Label1: TLabel
    Left = 175
    Top = 8
    Width = 89
    Height = 16
    Cursor = crDrag
    Caption = #1058#1072#1073#1083#1080#1094#1072' '#1087#1086#1088#1086#1076
    Color = clBackground
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object Panel1: TPanel
    Left = 448
    Top = 0
    Width = 142
    Height = 328
    Margins.Bottom = 10
    Align = alRight
    TabOrder = 0
    object SpeedButton3: TSpeedButton
      Left = 6
      Top = 47
      Width = 125
      Height = 33
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1087#1086#1088#1086#1076#1091
      OnClick = SpeedButton3Click
    end
    object SpeedButton2: TSpeedButton
      Left = 6
      Top = 8
      Width = 125
      Height = 33
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1087#1086#1088#1086#1076#1091
      OnClick = SpeedButton2Click
    end
    object Button1: TButton
      Left = 6
      Top = 86
      Width = 125
      Height = 32
      Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      AlignWithMargins = True
      Left = 4
      Top = 292
      Width = 134
      Height = 25
      Margins.Bottom = 10
      Align = alBottom
      Caption = #1047#1072#1082#1088#1099#1090#1100
      ModalResult = 2
      TabOrder = 1
    end
    object Ci: TEdit
      Left = 6
      Top = 124
      Width = 121
      Height = 24
      TabOrder = 2
    end
    object DsA: TEdit
      Left = 5
      Top = 154
      Width = 121
      Height = 24
      TabOrder = 3
    end
    object Hi: TEdit
      Left = 6
      Top = 184
      Width = 121
      Height = 24
      TabOrder = 4
    end
    object Порода: TButton
      Left = 24
      Top = 214
      Width = 75
      Height = 25
      Caption = #1055#1086#1088#1086#1076#1072
      TabOrder = 5
      OnClick = ПородаClick
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 448
    Height = 328
    Align = alClient
    Caption = 'Panel2'
    TabOrder = 1
    object Label2: TLabel
      Left = 40
      Top = 152
      Width = 37
      Height = 16
      Caption = 'Label2'
    end
    object StringGrid1: TStringGrid
      Left = 1
      Top = 1
      Width = 446
      Height = 326
      Align = alClient
      DefaultColWidth = 80
      FixedCols = 0
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goRowSelect]
      ParentFont = False
      TabOrder = 0
    end
  end
end
