object priMainForm: TpriMainForm
  Left = 0
  Top = 0
  Caption = 'pri '
  ClientHeight = 442
  ClientWidth = 725
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  WindowState = wsMaximized
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object StatusBar1: TStatusBar
    Left = 0
    Top = 423
    Width = 725
    Height = 19
    Panels = <
      item
        Width = 100
      end
      item
        Width = 100
      end>
  end
  object PhImage1: TPhImage
    Left = 0
    Top = 0
    Width = 725
    Height = 423
    AutoMosaic = True
    ThumbWidht = 128
    ThumbHeight = 128
    SlideShowInterval = 500
    Align = alClient
    ParentColor = False
  end
  object ActionList1: TActionList
    Left = 624
    Top = 64
    object fileCloseAction: TAction
      Caption = #1042#1099#1093#1086#1076
      OnExecute = fileCloseActionExecute
    end
    object startAction: TAction
      Caption = 'Start'
      OnExecute = startActionExecute
    end
    object stopAction: TAction
      Caption = 'Stop'
      OnExecute = stopActionExecute
    end
    object modeTuningAction: TAction
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1103
      OnExecute = modeTuningActionExecute
      OnUpdate = modeTuningActionUpdate
    end
    object modeExperimentAction: TAction
      Caption = #1069#1082#1089#1087#1077#1088#1080#1084#1077#1085#1090
      OnExecute = modeExperimentActionExecute
      OnUpdate = modeExperimentActionUpdate
    end
  end
  object MainMenu1: TMainMenu
    Left = 624
    Top = 120
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083#1099
      object Start1: TMenuItem
        Action = startAction
        Visible = False
      end
      object Stop1: TMenuItem
        Action = stopAction
        Visible = False
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object N2: TMenuItem
        Action = fileCloseAction
      end
    end
    object N4: TMenuItem
      Caption = #1056#1077#1078#1080#1084
      object N5: TMenuItem
        Action = modeTuningAction
      end
      object N6: TMenuItem
        Action = modeExperimentAction
      end
    end
  end
  object Comm1: TComm
    DeviceName = 'Com2'
    MonitorEvents = [evBreak, evCts, evDsr, evError, evRing, evRlsd, evRxChar, evRxFlag, evTxEmpty]
    OnRxChar = Comm1RxChar
    Left = 624
    Top = 184
  end
  object Comm2: TComm
    DeviceName = 'Com2'
    MonitorEvents = [evBreak, evCts, evDsr, evError, evRing, evRlsd, evRxChar, evRxFlag, evTxEmpty]
    BaudRate = br38400
    OnRxChar = Comm2RxChar
    Left = 624
    Top = 240
  end
end
