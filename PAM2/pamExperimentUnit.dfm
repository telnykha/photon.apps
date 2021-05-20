object pam2ExperimentForm: Tpam2ExperimentForm
  Left = 0
  Top = 0
  BorderStyle = bsSizeToolWin
  Caption = #1069#1082#1089#1087#1077#1088#1080#1084#1077#1085#1090
  ClientHeight = 299
  ClientWidth = 329
  Color = clBtnFace
  DragKind = dkDock
  DragMode = dmAutomatic
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 329
    Height = 41
    Align = alTop
    TabOrder = 0
    ExplicitLeft = 48
    ExplicitTop = 56
    ExplicitWidth = 185
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 280
    Width = 329
    Height = 19
    Panels = <>
    ExplicitLeft = 192
    ExplicitTop = 264
    ExplicitWidth = 0
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 41
    Width = 329
    Height = 239
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 2
    object TabSheet1: TTabSheet
      Caption = #1057#1090#1088#1091#1082#1090#1091#1088#1072
      object TreeView1: TTreeView
        Left = 0
        Top = 0
        Width = 321
        Height = 211
        Align = alClient
        Indent = 19
        TabOrder = 0
        ExplicitLeft = 96
        ExplicitTop = 56
        ExplicitWidth = 121
        ExplicitHeight = 97
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1058#1072#1073#1083#1080#1094#1072
      ImageIndex = 1
    end
  end
end
