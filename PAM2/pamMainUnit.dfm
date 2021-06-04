object pamMainForm: TpamMainForm
  Left = 0
  Top = 0
  Caption = '[/|\] Photon PAM Fluorescence Analyser  '
  ClientHeight = 484
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
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 763
    Height = 465
    Align = alClient
    Caption = 'Panel1'
    TabOrder = 0
    object Splitter1: TSplitter
      Left = 6
      Top = 33
      Height = 421
      ExplicitLeft = 272
      ExplicitTop = 152
      ExplicitHeight = 100
    end
    object Splitter2: TSplitter
      Left = 671
      Top = 33
      Height = 421
      Align = alRight
      ExplicitLeft = 384
      ExplicitTop = 152
      ExplicitHeight = 100
    end
    object Splitter3: TSplitter
      Left = 1
      Top = 454
      Width = 761
      Height = 2
      Cursor = crVSplit
      Align = alBottom
      ExplicitTop = 448
    end
    object ToolBar1: TToolBar
      AlignWithMargins = True
      Left = 4
      Top = 4
      Width = 755
      Height = 26
      Caption = 'ToolBar1'
      TabOrder = 0
      object ToolButton16: TToolButton
        AlignWithMargins = True
        Left = 0
        Top = 0
        Action = tuningFlashAction
      end
      object ToolButton15: TToolButton
        AlignWithMargins = True
        Left = 23
        Top = 0
        Caption = 'ToolButton15'
        ImageIndex = 12
      end
      object ToolButton14: TToolButton
        AlignWithMargins = True
        Left = 46
        Top = 0
        Caption = 'ToolButton14'
        ImageIndex = 11
      end
      object ToolButton12: TToolButton
        Left = 69
        Top = 0
        Width = 8
        Caption = 'ToolButton12'
        ImageIndex = 11
        Style = tbsSeparator
      end
      object ToolButton1: TToolButton
        AlignWithMargins = True
        Left = 77
        Top = 0
        Action = viewFrameAction
      end
      object ToolButton2: TToolButton
        AlignWithMargins = True
        Left = 100
        Top = 0
        Caption = 'ToolButton2'
        ImageIndex = 1
      end
      object ToolButton3: TToolButton
        AlignWithMargins = True
        Left = 123
        Top = 0
        Caption = 'ToolButton3'
        ImageIndex = 2
      end
      object ToolButton4: TToolButton
        AlignWithMargins = True
        Left = 146
        Top = 0
        Caption = 'ToolButton4'
        ImageIndex = 3
      end
      object ToolButton5: TToolButton
        AlignWithMargins = True
        Left = 169
        Top = 0
        Caption = 'ToolButton5'
        ImageIndex = 4
      end
      object ToolButton6: TToolButton
        AlignWithMargins = True
        Left = 192
        Top = 0
        Caption = 'ToolButton6'
        ImageIndex = 5
      end
      object ToolButton7: TToolButton
        AlignWithMargins = True
        Left = 215
        Top = 0
        Caption = 'ToolButton7'
        ImageIndex = 6
      end
      object ToolButton8: TToolButton
        AlignWithMargins = True
        Left = 238
        Top = 0
        Caption = 'ToolButton8'
        ImageIndex = 7
      end
      object ToolButton9: TToolButton
        AlignWithMargins = True
        Left = 261
        Top = 0
        Caption = 'ToolButton9'
        ImageIndex = 8
      end
      object ToolButton10: TToolButton
        AlignWithMargins = True
        Left = 284
        Top = 0
        Caption = 'ToolButton10'
        ImageIndex = 9
      end
      object ToolButton11: TToolButton
        AlignWithMargins = True
        Left = 307
        Top = 0
        Caption = 'ToolButton11'
        ImageIndex = 10
      end
      object ToolButton13: TToolButton
        Left = 330
        Top = 0
        Width = 8
        Caption = 'ToolButton13'
        ImageIndex = 11
        Style = tbsSeparator
      end
    end
    object LeftDocPanel: TPanel
      Left = 1
      Top = 33
      Width = 5
      Height = 421
      Align = alLeft
      DockSite = True
      TabOrder = 1
      OnDockDrop = LeftDocPanelDockDrop
      OnDockOver = LeftDocPanelDockOver
      OnUnDock = LeftDocPanelUnDock
    end
    object PhImage1: TPhImage
      Left = 9
      Top = 33
      Width = 662
      Height = 421
      AutoMosaic = True
      ThumbWidht = 128
      ThumbHeight = 128
      SlideShowInterval = 500
      Align = alClient
      ParentColor = False
      OnMouseMove = PhImage1MouseMove
    end
    object RightDocPanel: TPanel
      Left = 674
      Top = 33
      Width = 5
      Height = 421
      Align = alRight
      DockSite = True
      TabOrder = 3
      OnDockDrop = RightDocPanelDockDrop
      OnDockOver = RightDocPanelDockOver
      OnUnDock = RightDocPanelUnDock
    end
    object BottomDocPanel: TPanel
      Left = 1
      Top = 456
      Width = 761
      Height = 8
      Align = alBottom
      DockSite = True
      TabOrder = 4
      OnDockDrop = BottomDocPanelDockDrop
      OnDockOver = BottomDocPanelDockOver
      OnUnDock = BottomDocPanelUnDock
    end
    object PhPalette1: TPhPalette
      Left = 679
      Top = 33
      Width = 83
      Height = 421
      Align = alRight
      PopupMenu = PopupMenu1
      Color = clGray
      MaxValue = 4096.000000000000000000
      TicksVisible = True
      PaletteType = phpalGrayscale
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 465
    Width = 763
    Height = 19
    Panels = <
      item
        Text = #1056#1077#1078#1080#1084':'
        Width = 150
      end
      item
        Text = #1042#1080#1079#1091#1072#1083#1080#1079#1072#1094#1080#1103':'
        Width = 150
      end
      item
        Alignment = taCenter
        Bevel = pbRaised
        Text = 'x=0 y=0 v=255'
        Width = 150
      end
      item
        Alignment = taCenter
        Bevel = pbRaised
        Width = 50
      end>
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
        Visible = False
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
    object N41: TMenuItem
      Caption = #1042#1080#1079#1091#1072#1083#1080#1079#1072#1094#1080#1103
      object N45: TMenuItem
        Action = viewFrameAction
      end
      object N46: TMenuItem
        Caption = '-'
      end
      object Fo1: TMenuItem
        Action = viewFoAction
      end
      object Fm1: TMenuItem
        Action = viewFmAction
      end
      object Ft1: TMenuItem
        Action = viewFtAction
      end
      object Fm2: TMenuItem
        Action = viewFm1Action
      end
      object Fv1: TMenuItem
        Action = viewFvAction
      end
      object Fv2: TMenuItem
        Action = viewFv1Action
      end
      object Fq1: TMenuItem
        Action = viewFq1Action
      end
      object Fo2: TMenuItem
        Action = viewFo1Action
      end
      object FvFm1: TMenuItem
        Action = viewFvFm1Action
      end
      object YII1: TMenuItem
        Action = viewYII1Action
      end
      object NPQ1: TMenuItem
        Action = viewNPQ1Action
      end
      object qN1: TMenuItem
        Action = viewqN1Action
      end
    end
    object N28: TMenuItem
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072
      object N29: TMenuItem
        Action = tuningLiveVideo
      end
      object N31: TMenuItem
        Action = tuningCommandsAction
      end
      object N42: TMenuItem
        Caption = '-'
      end
      object N30: TMenuItem
        Action = tuningFlashAction
      end
      object N43: TMenuItem
        Action = tuningDarkAction
      end
      object FoFm1: TMenuItem
        Action = tuningFoFmAction
      end
      object FtFm1: TMenuItem
        Action = tuningFtTm1Action
      end
      object N110: TMenuItem
        Caption = '-'
      end
      object N44: TMenuItem
        Action = windowHardwareAction
      end
    end
    object N5: TMenuItem
      Caption = #1048#1079#1084#1077#1088#1077#1085#1080#1103
      object N16: TMenuItem
        Action = toolsStartExperimetAction
      end
      object N15: TMenuItem
        Action = toolsStopExperimentAction
      end
      object N19: TMenuItem
        Caption = '-'
      end
      object N8: TMenuItem
        Action = windowScriptAction
      end
      object N14: TMenuItem
        Action = toolsExecuteAction
      end
      object N18: TMenuItem
        Caption = '-'
      end
      object N17: TMenuItem
        Action = toolsOptionsAction
      end
      object N50: TMenuItem
        Action = windowExperimentAction
      end
    end
    object Fyfkb1: TMenuItem
      Caption = #1040#1085#1072#1083#1080#1079
      object N47: TMenuItem
        Action = windowTimeLineAction
      end
      object N48: TMenuItem
        Action = windowDistributionAction
      end
      object N49: TMenuItem
        Action = windowResultAction
      end
    end
    object N4: TMenuItem
      Caption = #1057#1077#1088#1074#1080#1089
      object N7: TMenuItem
        Action = windowConsoleAction
      end
      object N9: TMenuItem
        Action = toolsOptionsAction
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
      ShortCut = 16499
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
      Caption = #1053#1072#1095#1072#1090#1100' '#1080#1079#1084#1077#1088#1077#1085#1080#1103
      OnExecute = toolsStartExperimetActionExecute
      OnUpdate = toolsStartExperimetActionUpdate
    end
    object toolsStopExperimentAction: TAction
      Category = 'tools'
      Caption = #1047#1072#1074#1077#1088#1096#1080#1090#1100' '#1080#1079#1084#1077#1088#1077#1085#1080#1103
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
      Caption = #1053#1086#1074#1099#1081' '#1076#1086#1082#1091#1084#1077#1085#1090
      ShortCut = 16462
      OnExecute = fileNewActionExecute
      OnUpdate = fileNewActionUpdate
    end
    object fileOpenAction: TAction
      Category = 'Files'
      Caption = #1054#1090#1082#1088#1099#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090'...'
      ShortCut = 16463
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
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090'... '
      ShortCut = 16467
      OnExecute = fileSaveExperimentActionExecute
      OnUpdate = fileSaveExperimentActionUpdate
    end
    object tuningLiveVideo: TAction
      Category = 'tuning'
      Caption = #1057#1080#1075#1085#1072#1083' '#1089' '#1074#1080#1076#1077#1086#1082#1072#1084#1077#1088#1099
      OnExecute = tuningLiveVideoExecute
      OnUpdate = tuningLiveVideoUpdate
    end
    object tuningFlashAction: TAction
      Category = 'tuning'
      Caption = #1048#1079#1084#1077#1088#1080#1090#1077#1083#1100#1085#1072#1103' '#1074#1089#1087#1099#1096#1082#1072
      OnExecute = tuningFlashActionExecute
      OnUpdate = tuningFlashActionUpdate
    end
    object tuningCommandsAction: TAction
      Category = 'tuning'
      Caption = #1050#1086#1084#1072#1085#1076#1085#1099#1081' '#1088#1077#1078#1080#1084
      OnExecute = tuningCommandsActionExecute
      OnUpdate = tuningCommandsActionUpdate
    end
    object paletteScaleAction: TAction
      Category = 'palette'
      Caption = #1064#1082#1072#1083#1072
      OnExecute = paletteScaleActionExecute
      OnUpdate = paletteScaleActionUpdate
    end
    object plaetteGrayscaleAction: TAction
      Category = 'palette'
      Caption = #1057#1077#1088#1072#1103
      OnExecute = plaetteGrayscaleActionExecute
      OnUpdate = plaetteGrayscaleActionUpdate
    end
    object paletteOceanAction: TAction
      Category = 'palette'
      Caption = #1054#1082#1077#1072#1085
      OnExecute = paletteOceanActionExecute
      OnUpdate = paletteOceanActionUpdate
    end
    object paletteGlowAction: TAction
      Category = 'palette'
      Caption = #1057#1086#1083#1085#1094#1077
      OnExecute = paletteGlowActionExecute
      OnUpdate = paletteGlowActionUpdate
    end
    object paletteRedBlueAction: TAction
      Category = 'palette'
      Caption = #1050#1088#1072#1089#1085#1086'-'#1089#1080#1085#1103#1103
      OnExecute = paletteRedBlueActionExecute
      OnUpdate = paletteRedBlueActionUpdate
    end
    object paletteTrafficAction: TAction
      Category = 'palette'
      Caption = #1057#1074#1077#1090#1086#1092#1086#1088
      OnExecute = paletteTrafficActionExecute
      OnUpdate = paletteTrafficActionUpdate
    end
    object paletteSpecturmAction: TAction
      Category = 'palette'
      Caption = #1057#1087#1077#1082#1090#1088
      OnExecute = paletteSpecturmActionExecute
      OnUpdate = paletteSpecturmActionUpdate
    end
    object paletteSpectrum2Action: TAction
      Category = 'palette'
      Caption = #1057#1087#1077#1082#1090#1088' 2'
      OnExecute = paletteSpectrum2ActionExecute
      OnUpdate = paletteSpectrum2ActionUpdate
    end
    object paletteFalseColorsAction: TAction
      Category = 'palette'
      Caption = #1059#1089#1083'. '#1094#1074#1077#1090#1072
      OnExecute = paletteFalseColorsActionExecute
      OnUpdate = paletteFalseColorsActionUpdate
    end
    object windowHardwareAction: TAction
      Category = 'Window'
      Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1103
      OnExecute = windowHardwareActionExecute
      OnUpdate = windowHardwareActionUpdate
    end
    object tuningDarkAction: TAction
      Category = 'tuning'
      Caption = #1058#1077#1084#1085#1086#1074#1086#1081' '#1082#1072#1076#1088
      OnExecute = tuningDarkActionExecute
      OnUpdate = tuningDarkActionUpdate
    end
    object tuningFoFmAction: TAction
      Category = 'tuning'
      Caption = #1048#1079#1084#1077#1088#1077#1085#1080#1077' Fo + Fm'
      ShortCut = 16463
      OnExecute = tuningFoFmActionExecute
      OnUpdate = tuningFoFmActionUpdate
    end
    object tuningFtTm1Action: TAction
      Category = 'tuning'
      Caption = #1048#1079#1084#1077#1088#1077#1085#1080#1077' Ft + Fm`'
      ShortCut = 16468
      OnExecute = tuningFtTm1ActionExecute
      OnUpdate = tuningFtTm1ActionUpdate
    end
    object viewFrameAction: TAction
      Category = 'view'
      Caption = #1058#1077#1082#1091#1097#1080#1081' '#1082#1072#1076#1088
      OnExecute = viewFrameActionExecute
      OnUpdate = viewFrameActionUpdate
    end
    object viewFoAction: TAction
      Category = 'view'
      Caption = 'Fo'
      OnExecute = viewFoActionExecute
      OnUpdate = viewFoActionUpdate
    end
    object viewFmAction: TAction
      Category = 'view'
      Caption = 'Fm'
      OnExecute = viewFmActionExecute
      OnUpdate = viewFmActionUpdate
    end
    object viewFtAction: TAction
      Category = 'view'
      Caption = 'Ft'
      OnExecute = viewFtActionExecute
      OnUpdate = viewFtActionUpdate
    end
    object viewFm1Action: TAction
      Category = 'view'
      Caption = 'Fm'#39
      OnExecute = viewFm1ActionExecute
      OnUpdate = viewFm1ActionUpdate
    end
    object viewFvAction: TAction
      Category = 'view'
      Caption = 'Fv'
      OnExecute = viewFvActionExecute
      OnUpdate = viewFvActionUpdate
    end
    object viewFv1Action: TAction
      Category = 'view'
      Caption = 'Fv'#39
      OnExecute = viewFv1ActionExecute
      OnUpdate = viewFv1ActionUpdate
    end
    object viewFq1Action: TAction
      Category = 'view'
      Caption = 'Fq'#39
      OnExecute = viewFq1ActionExecute
      OnUpdate = viewFq1ActionUpdate
    end
    object viewFo1Action: TAction
      Category = 'view'
      Caption = 'Fo'#39
      OnExecute = viewFo1ActionExecute
      OnUpdate = viewFo1ActionUpdate
    end
    object viewFvFm1Action: TAction
      Category = 'view'
      Caption = 'Fv/Fm'#39
      OnExecute = viewFvFm1ActionExecute
      OnUpdate = viewFvFm1ActionUpdate
    end
    object viewYII1Action: TAction
      Category = 'view'
      Caption = 'YII'#39
      OnExecute = viewYII1ActionExecute
      OnUpdate = viewYII1ActionUpdate
    end
    object viewNPQ1Action: TAction
      Category = 'view'
      Caption = 'NPQ'#39
      OnExecute = viewNPQ1ActionExecute
      OnUpdate = viewNPQ1ActionUpdate
    end
    object viewqN1Action: TAction
      Category = 'view'
      Caption = 'qN'#39
      OnExecute = viewqN1ActionExecute
      OnUpdate = viewqN1ActionUpdate
    end
  end
  object Comm1: TComm
    DeviceName = 'Com2'
    MonitorEvents = [evBreak, evCts, evDsr, evError, evRing, evRlsd, evRxChar, evRxFlag, evTxEmpty]
    OnRxChar = Comm1RxChar
    Left = 224
    Top = 192
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 488
    Top = 40
  end
  object PopupMenu1: TPopupMenu
    Left = 592
    Top = 88
    object N32: TMenuItem
      Action = paletteScaleAction
    end
    object N33: TMenuItem
      Caption = '-'
    end
    object N34: TMenuItem
      Action = plaetteGrayscaleAction
    end
    object N35: TMenuItem
      Action = paletteOceanAction
    end
    object N36: TMenuItem
      Action = paletteGlowAction
    end
    object N37: TMenuItem
      Action = paletteRedBlueAction
    end
    object N38: TMenuItem
      Action = paletteTrafficAction
    end
    object N39: TMenuItem
      Action = paletteSpecturmAction
    end
    object N210: TMenuItem
      Action = paletteSpectrum2Action
    end
    object N40: TMenuItem
      Action = paletteFalseColorsAction
    end
  end
end
