object pamMainForm: TpamMainForm
  Left = 0
  Top = 0
  Caption = 'PAM2'
  ClientHeight = 477
  ClientWidth = 763
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 5
    Top = 29
    Height = 418
    ExplicitLeft = 272
    ExplicitTop = 152
    ExplicitHeight = 100
  end
  object Splitter2: TSplitter
    Left = 755
    Top = 29
    Height = 418
    Align = alRight
    ExplicitLeft = 384
    ExplicitTop = 152
    ExplicitHeight = 100
  end
  object Splitter3: TSplitter
    Left = 0
    Top = 447
    Width = 763
    Height = 3
    Cursor = crVSplit
    Align = alBottom
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 458
    Width = 763
    Height = 19
    Panels = <>
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 763
    Height = 29
    Caption = 'ToolBar1'
    TabOrder = 1
  end
  object LeftDocPanel: TPanel
    Left = 0
    Top = 29
    Width = 5
    Height = 418
    Align = alLeft
    DockSite = True
    TabOrder = 2
    OnDockDrop = LeftDocPanelDockDrop
    OnDockOver = LeftDocPanelDockOver
    OnUnDock = LeftDocPanelUnDock
  end
  object PhImage1: TPhImage
    Left = 8
    Top = 29
    Width = 747
    Height = 418
    AutoMosaic = True
    ThumbWidht = 128
    ThumbHeight = 128
    SlideShowInterval = 500
    Align = alClient
    ParentColor = False
  end
  object RightDocPanel: TPanel
    Left = 758
    Top = 29
    Width = 5
    Height = 418
    Align = alRight
    DockSite = True
    TabOrder = 4
    OnDockDrop = RightDocPanelDockDrop
    OnDockOver = RightDocPanelDockOver
    OnUnDock = RightDocPanelUnDock
  end
  object BottomDocPanel: TPanel
    Left = 0
    Top = 450
    Width = 763
    Height = 8
    Align = alBottom
    DockSite = True
    TabOrder = 5
    OnDockDrop = BottomDocPanelDockDrop
    OnDockOver = BottomDocPanelDockOver
    OnUnDock = BottomDocPanelUnDock
  end
  object MainMenu1: TMainMenu
    Left = 496
    Top = 40
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083#1099
      object N2: TMenuItem
        Action = filesClosAction
      end
    end
    object N3: TMenuItem
      Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077
    end
    object N5: TMenuItem
      Caption = #1048#1085#1089#1090#1088#1091#1084#1077#1085#1090#1099
    end
    object N4: TMenuItem
      Caption = #1054#1082#1085#1072
      object N7: TMenuItem
        Action = windowConsoleAction
      end
    end
    object N6: TMenuItem
      Caption = #1055#1086#1084#1086#1097#1100
    end
  end
  object ActionList1: TActionList
    Left = 536
    Top = 40
    object filesClosAction: TAction
      Category = 'Files'
      Caption = #1042#1099#1093#1086#1076
      OnExecute = filesClosActionExecute
    end
    object windowConsoleAction: TAction
      Category = 'Window'
      Caption = #1050#1086#1085#1089#1086#1083#1100
      OnExecute = windowConsoleActionExecute
    end
  end
  object Comm1: TComm
    DeviceName = 'Com2'
    MonitorEvents = [evBreak, evCts, evDsr, evError, evRing, evRlsd, evRxChar, evRxFlag, evTxEmpty]
    OnRxChar = Comm1RxChar
    Left = 584
    Top = 40
  end
end
