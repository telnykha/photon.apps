object ProfForm: TProfForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1055#1088#1086#1092#1077#1089#1089#1080#1080
  ClientHeight = 206
  ClientWidth = 267
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
    Width = 267
    Height = 41
    Align = alTop
    TabOrder = 0
    ExplicitWidth = 281
    object DBNavigator1: TDBNavigator
      Left = 11
      Top = 8
      Width = 240
      Height = 25
      DataSource = DataModule1.DataSource4
      TabOrder = 0
    end
  end
  object DBGrid1: TDBGrid
    Left = 0
    Top = 41
    Width = 267
    Height = 165
    Align = alClient
    DataSource = DataModule1.DataSource4
    DrawingStyle = gdsGradient
    Options = [dgEditing, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
end
