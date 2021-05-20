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
    Height = 437
    ExplicitLeft = 272
    ExplicitTop = 152
    ExplicitHeight = 100
  end
  object Splitter2: TSplitter
    Left = 755
    Top = 29
    Height = 437
    Align = alRight
    ExplicitLeft = 384
    ExplicitTop = 152
    ExplicitHeight = 100
  end
  object Splitter3: TSplitter
    Left = 0
    Top = 466
    Width = 763
    Height = 3
    Cursor = crVSplit
    Align = alBottom
    ExplicitTop = 447
  end
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 763
    Height = 29
    Caption = 'ToolBar1'
    TabOrder = 0
    Visible = False
  end
  object LeftDocPanel: TPanel
    Left = 0
    Top = 29
    Width = 5
    Height = 437
    Align = alLeft
    DockSite = True
    TabOrder = 1
    OnDockDrop = LeftDocPanelDockDrop
    OnDockOver = LeftDocPanelDockOver
    OnUnDock = LeftDocPanelUnDock
    ExplicitHeight = 418
  end
  object PhImage1: TPhImage
    Left = 8
    Top = 29
    Width = 747
    Height = 437
    AutoMosaic = True
    ThumbWidht = 128
    ThumbHeight = 128
    SlideShowInterval = 500
    Align = alClient
    ParentColor = False
    ExplicitHeight = 418
  end
  object RightDocPanel: TPanel
    Left = 758
    Top = 29
    Width = 5
    Height = 437
    Align = alRight
    DockSite = True
    TabOrder = 3
    OnDockDrop = RightDocPanelDockDrop
    OnDockOver = RightDocPanelDockOver
    OnUnDock = RightDocPanelUnDock
    ExplicitHeight = 418
  end
  object BottomDocPanel: TPanel
    Left = 0
    Top = 469
    Width = 763
    Height = 8
    Align = alBottom
    DockSite = True
    TabOrder = 4
    OnDockDrop = BottomDocPanelDockDrop
    OnDockOver = BottomDocPanelDockOver
    OnUnDock = BottomDocPanelUnDock
    ExplicitTop = 450
  end
  object MainMenu1: TMainMenu
    Left = 528
    Top = 40
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083#1099
      object N23: TMenuItem
        Action = fileNewAction
      end
      object N27: TMenuItem
        Caption = '-'
      end
      object N24: TMenuItem
        Action = fileOpenAction
      end
      object N26: TMenuItem
        Action = fileSaveExperimentAction
      end
      object N22: TMenuItem
        Action = fileCloseExperimentAction
      end
      object N25: TMenuItem
        Caption = '-'
      end
      object N2: TMenuItem
        Action = filesCloseAction
      end
    end
    object N3: TMenuItem
      Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077
      object N13: TMenuItem
        Action = editCopyAction
      end
    end
    object N5: TMenuItem
      Caption = #1048#1085#1089#1090#1088#1091#1084#1077#1085#1090#1099
      object N14: TMenuItem
        Action = toolsExecuteAction
      end
      object N19: TMenuItem
        Caption = '-'
      end
      object N15: TMenuItem
        Action = toolsStopExperimentAction
      end
      object N16: TMenuItem
        Action = toolsStartExperimetAction
      end
      object N18: TMenuItem
        Caption = '-'
      end
      object N17: TMenuItem
        Action = toolsOptionsAction
      end
    end
    object N4: TMenuItem
      Caption = #1054#1082#1085#1072
      object N7: TMenuItem
        Action = windowConsoleAction
      end
      object N8: TMenuItem
        Action = windowExperimentAction
      end
      object N9: TMenuItem
        Action = windowScriptAction
      end
      object N10: TMenuItem
        Action = windowResultAction
      end
      object N11: TMenuItem
        Action = windowDistributionAction
      end
      object N12: TMenuItem
        Action = windowTimeLineAction
      end
    end
    object N6: TMenuItem
      Caption = #1055#1086#1084#1086#1097#1100
      object N20: TMenuItem
        Action = helpContentAction
      end
      object N21: TMenuItem
        Action = helpAboutAction
      end
    end
  end
  object ActionList1: TActionList
    Left = 592
    Top = 40
    object filesCloseAction: TAction
      Category = 'Files'
      Caption = #1042#1099#1093#1086#1076
      OnExecute = filesCloseActionExecute
    end
    object windowConsoleAction: TAction
      Category = 'Window'
      Caption = #1050#1086#1085#1089#1086#1083#1100
      OnExecute = windowConsoleActionExecute
      OnUpdate = windowConsoleActionUpdate
    end
    object windowExperimentAction: TAction
      Category = 'Window'
      Caption = #1069#1082#1089#1087#1077#1088#1080#1084#1077#1085#1090
      OnExecute = windowExperimentActionExecute
      OnUpdate = windowExperimentActionUpdate
    end
    object windowScriptAction: TAction
      Category = 'Window'
      Caption = #1057#1082#1088#1080#1087#1090
      OnExecute = windowScriptActionExecute
      OnUpdate = windowScriptActionUpdate
    end
    object windowResultAction: TAction
      Category = 'Window'
      Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090
      OnExecute = windowResultActionExecute
      OnUpdate = windowResultActionUpdate
    end
    object windowDistributionAction: TAction
      Category = 'Window'
      Caption = #1056#1072#1089#1087#1088#1077#1076#1077#1083#1077#1085#1080#1077
      OnExecute = windowDistributionActionExecute
      OnUpdate = windowDistributionActionUpdate
    end
    object windowTimeLineAction: TAction
      Category = 'Window'
      Caption = #1042#1088#1077#1084#1077#1085#1085#1072#1103' '#1096#1082#1072#1083#1072
      OnExecute = windowTimeLineActionExecute
      OnUpdate = windowTimeLineActionUpdate
    end
    object editCopyAction: TAction
      Category = 'edit'
      Caption = #1057#1082#1086#1087#1080#1088#1086#1072#1090#1100' '#1074' '#1073#1091#1092#1077#1088
      OnExecute = editCopyActionExecute
      OnUpdate = editCopyActionUpdate
    end
    object toolsOptionsAction: TAction
      Category = 'tools'
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072'...'
      OnExecute = toolsOptionsActionExecute
    end
    object toolsExecuteAction: TAction
      Category = 'tools'
      Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100' '#1089#1082#1088#1080#1087#1090
      OnExecute = toolsExecuteActionExecute
      OnUpdate = toolsExecuteActionUpdate
    end
    object toolsStartExperimetAction: TAction
      Category = 'tools'
      Caption = #1053#1072#1095#1072#1083#1086' '#1101#1082#1089#1087#1077#1088#1080#1084#1077#1085#1090#1072
      OnExecute = toolsStartExperimetActionExecute
      OnUpdate = toolsStartExperimetActionUpdate
    end
    object toolsStopExperimentAction: TAction
      Category = 'tools'
      Caption = #1047#1072#1074#1077#1088#1096#1077#1085#1080#1077' '#1101#1082#1089#1087#1077#1088#1080#1084#1077#1085#1090#1072
      OnExecute = toolsStopExperimentActionExecute
      OnUpdate = toolsStopExperimentActionUpdate
    end
    object helpContentAction: TAction
      Category = 'help'
      Caption = #1057#1087#1088#1072#1074#1082#1072'...'
      OnExecute = helpContentActionExecute
      OnUpdate = helpContentActionUpdate
    end
    object helpAboutAction: TAction
      Category = 'help'
      Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077'...'
      OnExecute = helpAboutActionExecute
      OnUpdate = helpAboutActionUpdate
    end
    object fileNewAction: TAction
      Category = 'Files'
      Caption = #1053#1086#1074#1099#1081' '#1101#1082#1089#1087#1077#1088#1080#1084#1077#1085#1090
      OnExecute = fileNewActionExecute
      OnUpdate = fileNewActionUpdate
    end
    object fileOpenAction: TAction
      Category = 'Files'
      Caption = #1054#1090#1082#1088#1099#1090#1100' '#1101#1082#1089#1087#1077#1088#1080#1084#1077#1085#1090'...'
      OnExecute = fileOpenActionExecute
      OnUpdate = fileOpenActionUpdate
    end
    object fileCloseExperimentAction: TAction
      Category = 'Files'
      Caption = #1047#1072#1082#1088#1099#1090#1100' '#1101#1082#1089#1087#1077#1088#1080#1084#1077#1085#1090
      OnExecute = fileCloseExperimentActionExecute
      OnUpdate = fileCloseExperimentActionUpdate
    end
    object fileSaveExperimentAction: TAction
      Category = 'Files'
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1101#1082#1089#1087#1077#1088#1080#1084#1077#1085#1090'... '
      OnExecute = fileSaveExperimentActionExecute
      OnUpdate = fileSaveExperimentActionUpdate
    end
  end
  object Comm1: TComm
    DeviceName = 'Com2'
    MonitorEvents = [evBreak, evCts, evDsr, evError, evRing, evRlsd, evRxChar, evRxFlag, evTxEmpty]
    OnRxChar = Comm1RxChar
    Left = 560
    Top = 40
  end
end
