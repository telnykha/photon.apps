object TestTypesForm: TTestTypesForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1042#1080#1076#1099' '#1087#1089#1080#1093#1086#1075#1088#1072#1092#1080#1095#1077#1089#1082#1080#1093' '#1090#1077#1089#1090#1086#1074
  ClientHeight = 264
  ClientWidth = 284
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poOwnerFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 284
    Height = 41
    Align = alTop
    TabOrder = 0
    ExplicitLeft = 56
    ExplicitTop = 80
    ExplicitWidth = 185
    object DBNavigator1: TDBNavigator
      Left = 14
      Top = 8
      Width = 240
      Height = 25
      DataSource = DataModule1.DataSource6
      TabOrder = 0
    end
  end
  object DBGrid1: TDBGrid
    Left = 0
    Top = 41
    Width = 284
    Height = 223
    Align = alClient
    DataSource = DataModule1.DataSource6
    Options = [dgEditing, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
end
