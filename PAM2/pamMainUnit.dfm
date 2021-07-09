object pamMainForm: TpamMainForm
  Left = 0
  Top = 0
  Caption = '[/|\] Photon PAM Fluorescence Analyser  '
  ClientHeight = 541
  ClientWidth = 760
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  WindowState = wsMaximized
  OnClose = FormClose
  OnCloseQuery = FormCloseQuery
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 760
    Height = 522
    Align = alClient
    Caption = 'Panel1'
    TabOrder = 0
    object Splitter1: TSplitter
      Left = 6
      Top = 111
      Height = 360
      ExplicitLeft = 272
      ExplicitTop = 152
      ExplicitHeight = 100
    end
    object Splitter2: TSplitter
      Left = 668
      Top = 111
      Height = 360
      Align = alRight
      ExplicitLeft = 384
      ExplicitTop = 152
      ExplicitHeight = 100
    end
    object Splitter3: TSplitter
      Left = 1
      Top = 471
      Width = 758
      Height = 2
      Cursor = crVSplit
      Align = alBottom
      ExplicitTop = 448
      ExplicitWidth = 761
    end
    object ToolBar1: TToolBar
      AlignWithMargins = True
      Left = 4
      Top = 4
      Width = 752
      Height = 104
      AutoSize = True
      ButtonHeight = 46
      ButtonWidth = 47
      Caption = 'ToolBar1'
      DrawingStyle = dsGradient
      EdgeBorders = [ebTop, ebRight, ebBottom]
      Images = ImageList1
      List = True
      TabOrder = 0
      Visible = False
      object ToolButton17: TToolButton
        Left = 0
        Top = 0
        Width = 8
        Caption = 'ToolButton17'
        ImageIndex = 12
        Style = tbsSeparator
      end
      object ToolButton16: TToolButton
        AlignWithMargins = True
        Left = 8
        Top = 0
        Action = fileNewAction
      end
      object ToolButton15: TToolButton
        AlignWithMargins = True
        Left = 55
        Top = 0
        Action = fileOpenAction
      end
      object ToolButton14: TToolButton
        AlignWithMargins = True
        Left = 102
        Top = 0
        Action = fileSaveExperimentAction
      end
      object ToolButton12: TToolButton
        Left = 0
        Top = 0
        Width = 8
        Caption = 'ToolButton12'
        ImageIndex = 11
        Wrap = True
        Style = tbsSeparator
      end
      object ToolButton1: TToolButton
        AlignWithMargins = True
        Left = 0
        Top = 54
        Action = viewFrameAction
      end
      object ToolButton2: TToolButton
        AlignWithMargins = True
        Left = 47
        Top = 54
        Action = viewFoAction
      end
      object ToolButton3: TToolButton
        AlignWithMargins = True
        Left = 94
        Top = 54
        Action = viewFmAction
      end
      object ToolButton4: TToolButton
        AlignWithMargins = True
        Left = 141
        Top = 54
        Action = viewFtAction
      end
      object ToolButton5: TToolButton
        AlignWithMargins = True
        Left = 188
        Top = 54
        Action = viewFm1Action
      end
      object ToolButton6: TToolButton
        AlignWithMargins = True
        Left = 235
        Top = 54
        Action = viewFvAction
      end
      object ToolButton7: TToolButton
        AlignWithMargins = True
        Left = 282
        Top = 54
        Action = viewFv1Action
      end
      object ToolButton8: TToolButton
        AlignWithMargins = True
        Left = 329
        Top = 54
        Action = viewFq1Action
      end
      object ToolButton9: TToolButton
        AlignWithMargins = True
        Left = 376
        Top = 54
        Action = viewFo1Action
      end
      object ToolButton10: TToolButton
        AlignWithMargins = True
        Left = 423
        Top = 54
        Action = viewFvFm1Action
      end
      object ToolButton11: TToolButton
        AlignWithMargins = True
        Left = 470
        Top = 54
        Action = viewYII1Action
      end
      object ToolButton18: TToolButton
        Left = 517
        Top = 54
        Action = viewNPQ1Action
      end
      object ToolButton19: TToolButton
        Left = 564
        Top = 54
        Action = viewqN1Action
      end
      object ToolButton13: TToolButton
        Left = 611
        Top = 54
        Width = 8
        Caption = 'ToolButton13'
        ImageIndex = 11
        Style = tbsSeparator
      end
    end
    object LeftDocPanel: TPanel
      Left = 1
      Top = 111
      Width = 5
      Height = 360
      Align = alLeft
      DockSite = True
      TabOrder = 1
      OnDockDrop = LeftDocPanelDockDrop
      OnDockOver = LeftDocPanelDockOver
      OnUnDock = LeftDocPanelUnDock
    end
    object PhImage1: TPhImage
      Left = 9
      Top = 111
      Width = 659
      Height = 360
      AutoMosaic = True
      ThumbWidht = 128
      ThumbHeight = 128
      SlideShowInterval = 500
      Align = alClient
      ParentColor = False
      PopupMenu = PopupMenu2
      OnMouseMove = PhImage1MouseMove
    end
    object RightDocPanel: TPanel
      Left = 671
      Top = 111
      Width = 5
      Height = 360
      Align = alRight
      DockSite = True
      TabOrder = 3
      OnDockDrop = RightDocPanelDockDrop
      OnDockOver = RightDocPanelDockOver
      OnUnDock = RightDocPanelUnDock
    end
    object BottomDocPanel: TPanel
      Left = 1
      Top = 513
      Width = 758
      Height = 8
      Align = alBottom
      DockSite = True
      TabOrder = 4
      OnDockDrop = BottomDocPanelDockDrop
      OnDockOver = BottomDocPanelDockOver
      OnUnDock = BottomDocPanelUnDock
    end
    object PhPalette1: TPhPalette
      Left = 676
      Top = 111
      Width = 83
      Height = 360
      Align = alRight
      PopupMenu = PopupMenu1
      Color = clGray
      MaxValue = 4096.000000000000000000
      TicksVisible = True
      PaletteType = phpalGrayscale
    end
    object Panel2: TPanel
      Left = 1
      Top = 473
      Width = 758
      Height = 40
      Align = alBottom
      TabOrder = 6
      Visible = False
      object PhTrackBar1: TPhTrackBar
        Left = 1
        Top = 1
        Width = 756
        Height = 38
        Align = alClient
        Position = 4
        ShowSelRange = False
        TabOrder = 0
        TickMarks = tmBoth
        OnChange = PhTrackBar1Change
      end
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 522
    Width = 760
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
        Bevel = pbRaised
        Text = #1082#1072#1076#1088
        Width = 50
      end>
    ExplicitTop = 519
  end
  object MainMenu1: TMainMenu
    Left = 528
    Top = 56
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
      object N10: TMenuItem
        Action = fileSaveAsAction
      end
      object N22: TMenuItem
        Action = fileCloseExperimentAction
        Visible = False
      end
      object N54: TMenuItem
        Caption = '-'
      end
      object ROI1: TMenuItem
        Action = fileSaveRoiAction
      end
      object ROI2: TMenuItem
        Action = fileLoadRoiAction
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
        Visible = False
      end
      object N15: TMenuItem
        Action = toolsStopExperimentAction
        Visible = False
      end
      object N50: TMenuItem
        Action = windowExperimentAction
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
    end
    object Fyfkb1: TMenuItem
      Caption = #1040#1085#1072#1083#1080#1079
      object N48: TMenuItem
        Action = windowROIAction
      end
      object N49: TMenuItem
        Action = windowResultAction
      end
      object N11: TMenuItem
        Caption = '-'
      end
      object N47: TMenuItem
        Action = windowTimeLineAction
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
    Images = ImageList1
    Left = 568
    Top = 56
    object filesCloseAction: TAction
      Category = 'Files'
      Caption = #1042#1099#1093#1086#1076
      ShortCut = 16499
      OnExecute = filesCloseActionExecute
    end
    object windowConsoleAction: TAction
      Category = 'Service'
      Caption = #1050#1086#1085#1089#1086#1083#1100
      OnExecute = windowConsoleActionExecute
      OnUpdate = windowConsoleActionUpdate
    end
    object windowExperimentAction: TAction
      Category = 'Window'
      Caption = #1056#1091#1095#1085#1086#1081' '#1088#1077#1078#1080#1084
      OnExecute = windowExperimentActionExecute
      OnUpdate = windowExperimentActionUpdate
    end
    object windowScriptAction: TAction
      Category = 'Window'
      Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1090#1100' '#1089#1082#1088#1080#1087#1090
      OnExecute = windowScriptActionExecute
      OnUpdate = windowScriptActionUpdate
    end
    object windowResultAction: TAction
      Category = 'Window'
      Caption = #1044#1080#1085#1072#1084#1080#1082#1072' '#1087#1072#1088#1072#1084#1077#1090#1088#1086#1074
      OnExecute = windowResultActionExecute
      OnUpdate = windowResultActionUpdate
    end
    object windowROIAction: TAction
      Category = 'Window'
      Caption = #1054#1073#1083#1072#1089#1090#1080' '#1080#1085#1090#1077#1088#1077#1089#1072
      OnExecute = windowROIActionExecute
      OnUpdate = windowROIActionUpdate
    end
    object windowTimeLineAction: TAction
      Category = 'Window'
      Caption = #1055#1088#1086#1090#1086#1082#1086#1083' '#1089#1086#1073#1099#1090#1080#1081
      Visible = False
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
      Visible = False
      OnExecute = toolsOptionsActionExecute
      OnUpdate = toolsOptionsActionUpdate
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
      ImageIndex = 0
      ShortCut = 16462
      OnExecute = fileNewActionExecute
      OnUpdate = fileNewActionUpdate
    end
    object fileOpenAction: TAction
      Category = 'Files'
      Caption = #1054#1090#1082#1088#1099#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090'...'
      ImageIndex = 1
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
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090
      Enabled = False
      ImageIndex = 2
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
      Category = 'tuning'
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1103
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
      ImageIndex = 3
      OnExecute = viewFoActionExecute
      OnUpdate = viewFoActionUpdate
    end
    object viewFmAction: TAction
      Category = 'view'
      Caption = 'Fm'
      ImageIndex = 4
      OnExecute = viewFmActionExecute
      OnUpdate = viewFmActionUpdate
    end
    object viewFtAction: TAction
      Category = 'view'
      Caption = 'Ft'
      ImageIndex = 5
      OnExecute = viewFtActionExecute
      OnUpdate = viewFtActionUpdate
    end
    object viewFm1Action: TAction
      Category = 'view'
      Caption = 'Fm'#39
      ImageIndex = 6
      OnExecute = viewFm1ActionExecute
      OnUpdate = viewFm1ActionUpdate
    end
    object viewFvAction: TAction
      Category = 'view'
      Caption = 'Fv'
      ImageIndex = 7
      OnExecute = viewFvActionExecute
      OnUpdate = viewFvActionUpdate
    end
    object viewFv1Action: TAction
      Category = 'view'
      Caption = 'Fv'#39
      ImageIndex = 8
      OnExecute = viewFv1ActionExecute
      OnUpdate = viewFv1ActionUpdate
    end
    object viewFq1Action: TAction
      Category = 'view'
      Caption = 'Fq'#39
      ImageIndex = 9
      OnExecute = viewFq1ActionExecute
      OnUpdate = viewFq1ActionUpdate
    end
    object viewFo1Action: TAction
      Category = 'view'
      Caption = 'Fo'#39
      ImageIndex = 10
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
    object fileSaveAsAction: TAction
      Category = 'Files'
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090' '#1082#1072#1082'... '
      OnExecute = fileSaveAsActionExecute
      OnUpdate = fileSaveAsActionUpdate
    end
    object imageBestFitAction: TAction
      Caption = #1042#1087#1080#1089#1072#1090#1100' '#1074' '#1086#1082#1085#1086
      OnExecute = imageBestFitActionExecute
      OnUpdate = imageBestFitActionUpdate
    end
    object imageActualSizeAction: TAction
      Caption = #1048#1089#1093#1086#1076#1085#1099#1081' '#1088#1072#1079#1084#1077#1088
      OnExecute = imageActualSizeActionExecute
      OnUpdate = imageActualSizeActionUpdate
    end
    object imageZoomInAction: TAction
      Caption = #1059#1074#1077#1083#1080#1095#1080#1090#1100
      OnExecute = imageZoomInActionExecute
      OnUpdate = imageZoomInActionUpdate
    end
    object imageZoomOutAction: TAction
      Caption = #1059#1084#1077#1085#1100#1096#1080#1090#1100
      OnExecute = imageZoomOutActionExecute
      OnUpdate = imageZoomOutActionUpdate
    end
    object imageAddRectAction: TAction
      Caption = #1056#1077#1076#1072#1082#1090#1086#1088' '#1087#1088#1103#1084#1086#1091#1075#1086#1083#1100#1085#1080#1082#1086#1074
      OnExecute = imageAddRectActionExecute
      OnUpdate = imageAddRectActionUpdate
    end
    object imageAddCircleAction: TAction
      Caption = #1056#1077#1076#1072#1082#1090#1086#1088' '#1086#1082#1088#1091#1078#1085#1086#1089#1090#1077#1081
      OnExecute = imageAddCircleActionExecute
      OnUpdate = imageAddCircleActionUpdate
    end
    object imageAddPolygonAction: TAction
      Caption = #1056#1077#1076#1072#1082#1090#1086#1088' '#1084#1085#1086#1075#1086#1091#1075#1086#1083#1100#1085#1080#1082#1086#1074
      OnExecute = imageAddPolygonActionExecute
      OnUpdate = imageAddPolygonActionUpdate
    end
    object imageSaveAction: TAction
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077'... '
      OnExecute = imageSaveActionExecute
      OnUpdate = imageSaveActionUpdate
    end
    object imageZoomPaneAction: TAction
      Caption = #1056#1077#1078#1080#1084' '#1087#1088#1086#1089#1084#1086#1090#1088#1072
      OnExecute = imageZoomPaneActionExecute
      OnUpdate = imageZoomPaneActionUpdate
    end
    object fileSaveRoiAction: TAction
      Category = 'Files'
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' ROI...'
      OnExecute = fileSaveRoiActionExecute
      OnUpdate = fileSaveRoiActionUpdate
    end
    object fileLoadRoiAction: TAction
      Category = 'Files'
      Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' ROI...'
      OnExecute = fileLoadRoiActionExecute
      OnUpdate = fileLoadRoiActionUpdate
    end
  end
  object Comm1: TComm
    DeviceName = 'Com2'
    MonitorEvents = [evBreak, evCts, evDsr, evError, evRing, evRlsd, evRxChar, evRxFlag, evTxEmpty]
    OnRxChar = Comm1RxChar
    Left = 528
    Top = 96
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 488
    Top = 56
  end
  object PopupMenu1: TPopupMenu
    Left = 568
    Top = 104
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
  object OpenDialog1: TOpenDialog
    Filter = #1044#1086#1082#1091#1084#1077#1085#1090#1099' pam2|*.pam2'
    Left = 528
    Top = 144
  end
  object SaveDialog1: TSaveDialog
    Filter = #1069#1082#1089#1087#1077#1088#1080#1084#1077#1085#1090#1099' PAM2|*.pam2'
    Left = 568
    Top = 144
  end
  object PhPaneTool1: TPhPaneTool
    PhImage = PhImage1
    Left = 488
    Top = 96
  end
  object ImageList1: TImageList
    DrawingStyle = dsTransparent
    Height = 40
    Width = 40
    Left = 488
    Top = 144
    Bitmap = {
      494C01010B001800040028002800FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000A0000000780000000100200000000000002C
      0100000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000CC483F00CC483F00CC483F00CC483F00000000000000
      0000CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FF000000FF000000FF000000FF000000FF00
      0000FF0000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000CC483F00CC483F00CC483F00CC483F00CC483F00CC483F00CC48
      3F00CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFCE0000FFCE0000FFCE00000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F00CC483F00CC483F00CC483F00CC48
      3F00CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF000000FF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFCE0000FFCE0000FFCE00000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F00000000000000000000000000CC48
      3F00CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF0000000000000000000000000000000000
      0000FF000000FF000000FF000000FF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000CC48
      3F00CC483F00CC483F00CC483F0000000000000000000000000000000000CC48
      3F00CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF0000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      0000FF000000FF000000FF000000FF0000000000000000000000000000000000
      0000FF000000FF000000FF000000FF000000FF00000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000CC48
      3F00CC483F00CC483F00CC483F00000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF0000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      0000FF000000FF000000FF000000000000000000000000000000000000000000
      000000000000FF000000FF000000FF000000FF00000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFCE0000FFCE0000FFCE000000000000FFCE0000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000CC48
      3F00CC483F00CC483F00CC483F00000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF0000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      0000FF000000FF000000FF000000000000000000000000000000000000000000
      000000000000FF000000FF000000FF000000FF00000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      00000000000000000000FFCE0000FFCE0000FFCE000000000000FFCE0000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000CC48
      3F00CC483F00CC483F00CC483F00000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF0000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      0000FF000000FF000000FF000000000000000000000000000000000000000000
      000000000000FF000000FF000000FF000000FF00000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE0000FFCE000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F00CC483F00CC483F00CC483F00CC48
      3F00CC483F00CC483F00CC483F00CC483F00000000000000000000000000CC48
      3F00CC483F00CC483F00CC483F00000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF000000FF000000000000000000000000000000FF00
      0000FF000000FF000000FF000000000000000000000000000000000000000000
      000000000000FF000000FF000000FF000000FF00000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE0000FFCE000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F00CC483F00CC483F00CC483F00CC48
      3F00CC483F00CC483F00CC483F00CC483F00000000000000000000000000CC48
      3F00CC483F00CC483F00CC483F00000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF000000FF000000000000000000000000000000FF00
      0000FF000000FF000000FF000000FF0000000000000000000000000000000000
      0000FF000000FF000000FF000000FF000000FF00000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      0000FFCE0000FFCE0000FFCE0000000000000000000000000000000000000000
      0000FFCE0000FFCE0000FFCE0000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F00CC483F00CC483F00CC483F00CC48
      3F00CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F00000000000000000000000000CC48
      3F00CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF000000FF0000000000000000000000000000000000
      0000FF000000FF000000FF000000FF0000000000000000000000000000000000
      0000FF000000FF000000FF000000FF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      0000FFCE0000FFCE0000FFCE0000000000000000000000000000000000000000
      0000FFCE0000FFCE0000FFCE0000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F00CC483F00CC483F00CC483F00CC48
      3F00CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F00CC483F00CC483F00CC483F00CC48
      3F00CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF000000FF0000000000000000000000000000000000
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF000000FF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE00000000000000000000FFCE0000FFCE000000000000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000000000000000000000000000000000000000
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE00000000000000000000FFCE
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000CC483F00CC483F00CC483F00CC483F00CC483F00CC483F00CC48
      3F00CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000FFCE0000FFCE000000000000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000000000000000000000000000000000000000
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE00000000000000000000FFCE
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000CC483F00CC483F00CC483F00CC483F00CC483F000000
      0000CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FF000000FF000000FF000000FF000000FF00
      0000FF0000000000000000000000000000000000000000000000FF0000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FF0000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F00CC483F00CC483F00CC483F00CC48
      3F00CC483F00CC483F00CC483F00CC483F00CC483F0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000CC483F000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF000000FF000000FF00000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FF0000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F00CC483F00CC483F00CC483F00CC48
      3F00CC483F00CC483F00CC483F00CC483F00CC483F0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000CC483F000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF000000FF000000FF00000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FF0000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F00CC483F00CC483F00CC483F00CC48
      3F00CC483F00CC483F00CC483F00CC483F00CC483F0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000CC483F000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF000000FF000000FF00000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FF0000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000000000000000000000000000000000000000000000000000000000000000
      0000CC483F00CC483F00CC483F00CC483F00CC483F00CC483F00CC483F00CC48
      3F00CC483F00CC483F00CC483F00CC483F00CC483F0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000CC483F000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000FF000000FF000000FF000000FF00000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FF0000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000CC483F000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FF0000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000CC483F000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000CC483F000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE000000000000000000000000000000000000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE000000000000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE000000000000000000000000000000000000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE000000000000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFCE0000FFCE0000FFCE00000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE000000000000000000000000000000000000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE000000000000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE000000000000000000000000000000000000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE000000000000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFCE0000FFCE0000FFCE00000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000000000000000000000000000FFCE0000FFCE0000FFCE
      0000000000000000000000000000FFCE0000FFCE0000FFCE0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFCE0000FFCE0000FFCE000000000000000000000000
      00000000000000000000FFCE0000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000000000000000000000000000FFCE0000FFCE0000FFCE
      0000000000000000000000000000FFCE0000FFCE0000FFCE0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000000000000000000000000000FFCE0000FFCE0000FFCE
      0000000000000000000000000000FFCE0000FFCE0000FFCE0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFCE0000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000000000000000000000000000FFCE0000FFCE0000FFCE
      0000000000000000000000000000FFCE0000FFCE0000FFCE0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000000000000000000000000000FFCE0000FFCE0000FFCE
      0000000000000000000000000000FFCE0000FFCE0000FFCE0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFCE0000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000000000000000000000000000FFCE0000FFCE0000FFCE
      0000000000000000000000000000FFCE0000FFCE0000FFCE0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFCE0000FFCE0000FFCE000000000000FFCE0000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE0000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000000000000000000000000000FFCE0000FFCE0000FFCE
      0000000000000000000000000000FFCE0000FFCE0000FFCE0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      00000000000000000000FFCE0000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE0000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000000000000000000000000000FFCE0000FFCE0000FFCE
      0000000000000000000000000000FFCE0000FFCE0000FFCE0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      00000000000000000000FFCE0000FFCE0000FFCE000000000000FFCE0000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE0000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000000000000000000000000000FFCE0000FFCE0000FFCE
      0000000000000000000000000000FFCE0000FFCE0000FFCE0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      00000000000000000000FFCE0000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE0000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000000000000000000000000000FFCE0000FFCE0000FFCE
      0000000000000000000000000000FFCE0000FFCE0000FFCE0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE0000FFCE000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000000000000000000000000000FFCE0000FFCE0000FFCE
      0000000000000000000000000000FFCE0000FFCE0000FFCE0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      00000000000000000000FFCE0000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000000000000000000000000000FFCE0000FFCE0000FFCE
      0000000000000000000000000000FFCE0000FFCE0000FFCE0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE0000FFCE000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000000000000000000000000000FFCE0000FFCE0000FFCE
      0000000000000000000000000000FFCE0000FFCE0000FFCE0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      00000000000000000000FFCE0000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000000000000000000000000000FFCE0000FFCE0000FFCE
      0000000000000000000000000000FFCE0000FFCE0000FFCE0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      0000FFCE0000FFCE0000FFCE0000000000000000000000000000000000000000
      0000FFCE0000FFCE0000FFCE0000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE0000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE00000000000000000000FFCE0000FFCE0000FFCE
      0000FFCE00000000000000000000FFCE0000FFCE0000FFCE0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      00000000000000000000FFCE0000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE0000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE00000000000000000000FFCE0000FFCE0000FFCE
      0000FFCE00000000000000000000FFCE0000FFCE0000FFCE0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      0000FFCE0000FFCE0000FFCE0000000000000000000000000000000000000000
      0000FFCE0000FFCE0000FFCE0000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE00000000000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE00000000000000000000FFCE0000FFCE000000000000000000000000
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE00000000000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE00000000000000000000FFCE0000FFCE000000000000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000000000000000000000000000000000000000
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE000000000000FFCE0000FFCE0000FFCE0000000000000000
      0000FFCE0000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000FFCE0000FFCE000000000000000000000000
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE000000000000FFCE0000FFCE0000FFCE0000000000000000
      0000FFCE0000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000FFCE0000FFCE000000000000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000000000000000000000000000000000000000
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000FFCE0000FFCE000000000000000000000000
      00000000000000000000FFCE0000FFCE0000FFCE000000000000000000000000
      00000000000000000000000000000000000000000000FFCE0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE000000000000000000000000
      00000000000000000000FFCE0000FFCE0000FFCE000000000000000000000000
      00000000000000000000000000000000000000000000FFCE0000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE000000000000000000000000
      00000000000000000000FFCE0000FFCE0000FFCE000000000000000000000000
      00000000000000000000000000000000000000000000FFCE0000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FFCE0000FFCE0000FFCE000000000000000000000000
      00000000000000000000000000000000000000000000FFCE0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFCE0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFCE0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000FFCE0000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C0DCC000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0DCC0000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000C0C0C0000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA60000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000080A0C0004080C0004080C00080A0
      C000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA60000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000C0DCC000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0DCC000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000080A0C0004080C00000C0E00000C0E0000080
      C00080A0C0000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA60000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0A0
      A000C0A06000C0A06000C0A06000C0A06000C0A06000C0A06000C0A06000C0A0
      6000C0A06000C0A06000C0A06000C0A06000C0A06000C0A06000C0A06000C0A0
      6000C0A06000C0A06000C0A06000C0A06000C0A06000C0A06000C0A06000C0A0
      6000C0A06000C0A06000C0A06000C0A06000C0A06000C0A06000C0A0A0000000
      000000000000FFFFFF00FFFFFF00000000000000000000000000000000000000
      0000C0DCC000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C0004080C0004080C00000C0E00000C0E00000C0E00000C0
      E0000080C0008080C000C0C0C000C0C0C000C0C0C000C0DCC000000000000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA60000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0A0
      6000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A0
      8000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A0
      8000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A0
      8000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A060000000
      000000000000FFFFFF00FFFFFF0000000000000000000000000000000000C0A0
      A000C0A06000C0A06000C0A06000C0A06000C0A06000C0A06000C0A06000C0A0
      6000C0A06000C0A06000C0A06000C0A06000C0A06000C0A06000C0A06000C080
      6000C0806000406080004080C00040C0E00000C0E00000C0E00000C0E00000C0
      E00040C0E0000080C00040608000C0806000C0806000C0A06000C0A0A0000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000F0CAA60000000000F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA60080808000808080008080800080808000808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      8000F0CAA600F0CAA600F0CAA60000000000F0CAA60000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0A0
      8000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A0
      8000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A0
      8000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A0
      8000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A080000000
      000000000000FFFFFF00FFFFFF0000000000000000000000000000000000C0A0
      6000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A0
      8000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A06000C080
      6000406080004080C00040C0E00040C0E00000C0E00000C0E00000C0E00000C0
      E00000C0E00040C0E0000080C00040608000C0806000C0A08000C0A060000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000F0CAA60000000000F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA60000000000F0CAA60000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0A0
      8000F0CAA600C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A0
      8000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A0
      8000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A0
      8000C0A08000C0A08000C0A08000C0A08000C0A08000F0CAA600C0A080000000
      000000000000FFFFFF00FFFFFF0000000000000000000000000000000000C0A0
      8000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A0
      8000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C08060008060
      80004080C00040C0E00040C0E00040C0E00040C0E00000C0E00000C0E00000C0
      E00000C0E00000C0E00040C0E0004080C00040608000C0806000C0A060000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000F0CAA60000000000F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA60080808000808080008080800080808000808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      8000F0CAA600F0CAA600F0CAA60000000000F0CAA60000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF00FFFFFF0000000000000000000000000000000000C0A0
      8000F0CAA600C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A0
      8000C0A08000C0A08000C0A08000C0A08000C0A08000C0806000806080004080
      E00080C0E00080E0E00040E0E00040C0E00040C0E00040C0E00040C0E00040C0
      E00040C0E00040C0E00040C0E00040C0E0004080E00080608000C08060000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000F0CAA60000000000F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA60000000000F0CAA60000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF00FFFFFF0000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600C0A08000C0A08000808080004080E00080E0
      E00080E0E00080E0E00080E0E00080E0E00040E0E00040C0E00040C0E00040C0
      E00040E0E00040E0E00040E0E00080E0E00080C0E0004080E000808080000000
      000000000000FFFFFF000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000F0CAA60000000000F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA60080808000808080008080800080808000808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      8000F0CAA600F0CAA600F0CAA60000000000F0CAA60000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF00FFFFFF0000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600C0A080004080E000C0DCC0000000
      0000000000000000000000000000C0DCC00080E0E00040E0E00040C0E00040E0
      E00080E0E0000000000000000000000000000000000080E0E0004080E0000000
      000000000000FFFFFF000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000F0CAA60000000000F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA60000000000F0CAA60000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF00FFFFFF0000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600C0A08000A4A0A0004080C0004080
      E0004080E0004080E0004080E0004080E00080E0E00040E0E00040E0E00080E0
      E0004080E0004080E0004080E0004080E0004080E0004080C000808080000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFCE0000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000FFCE0000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000F0CAA60000000000F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA60080808000808080008080800080808000808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      8000F0CAA600F0CAA600F0CAA60000000000F0CAA60000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF00FFFFFF0000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600C0A08000C0A08000C0A0
      8000C0A08000C0A08000C08060004080E00080E0E00080E0E00040E0E00080E0
      E0004080E000C0806000C0A08000C0A08000C0A08000C0A08000C0A080000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FFCE0000FFCE0000FFCE0000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000F0CAA60000000000F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA60000000000F0CAA60000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF00FFFFFF0000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600C0A08000C0A080004080E00080E0E00080E0E00080E0E00080E0
      E0004080E000C0A08000C0A08000F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE000000000000000000000000000000000000000000000000
      00000000000000000000FFCE0000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000F0CAA60000000000F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA60080808000808080008080800080808000808080008080
      8000808080008080800080808000808080008080800080808000808080008080
      8000F0CAA600F0CAA600F0CAA60000000000F0CAA60000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF00FFFFFF0000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600C0A080004080E00080E0E00080E0E00080E0E00080E0
      E0004080E000C0A08000F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE0000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE000000000000000000000000000000000000000000000000
      00000000000000000000FFCE0000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000F0CAA60000000000F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA60000000000F0CAA60000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF00FFFFFF0000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600C0A080004080E00080E0E00080E0E00080E0E00080E0
      E0004080E000C0A08000F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE0000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE000000000000000000000000000000000000000000000000
      00000000000000000000FFCE0000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000C0DCC000C0C0C000C0C0C000C0A08000C0C0A000C0C0A000C0C0A000C0C0
      A000C0C0A000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA60000000000F0CAA60000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF00FFFFFF0000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600C0A080004080E000C0DCC00080E0E00080E0E00080E0
      E0004080E000C0A08000F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000000000000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE000000000000000000000000000000000000000000000000
      00000000000000000000FFCE0000FFCE0000FFCE000000000000000000000000
      00000000000000000000000000000000000000000000000000000000000080A0
      C0000060C0000060C0000060C0000060C0000060C0000060C0000060C0000060
      C0000060C0008080C000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA60000000000F0CAA60000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF00FFFFFF0000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600C0A080004080E00000000000C0DCC00080E0E000C0DC
      C0004080E000C0A08000F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      0000FFCE0000FFCE0000FFCE0000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000060
      C00040C0E00000C0E00000C0E00000C0E00000C0E00000C0E00000C0E00000C0
      E00040C0E0000060C000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA60000000000F0CAA60000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF00FFFFFF0000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600C0A080004080E0000000000000000000000000000000
      00004080E000C0A08000F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      0000FFCE0000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000FFCE0000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000080
      C00040C0E00000C0E00000C0E00000C0E00000C0E00000C0E00000C0E00000C0
      E00040C0E0000080C000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA60000000000F0CAA60000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF00FFFFFF0000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA60080A0C0004080E0004080E0004080E0004080
      E0008080C000C0A08000F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000000000000000000000000000FFCE
      0000FFCE00000000000000000000FFCE0000FFCE000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000080
      C00040E0E00000C0E00000C0E00000C0E00000C0E00000C0E00000C0E00000C0
      E00040E0E0000080C000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA60000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF00FFFFFF0000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600C0A08000C0A08000C0A08000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE00000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000080
      E00040E0E00040C0E00040C0E00040C0E00040C0E00040C0E00040C0E00040C0
      E00040E0E0000080E000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA60000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF00FFFFFF0000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      000000000000FFCE0000FFCE0000FFCE00000000000000000000000000000000
      0000000000000000000000000000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000004080
      E00080E0E00040C0E00040C0E00040C0E00040C0E00040C0E00040C0E00040C0
      E00080E0E0004080E000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0000000000F0CAA600F0CAA60000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0A0
      A000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A0
      8000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF00FFFFFF0000000000000000000000000000000000C0A0
      8000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000004080
      E00080E0E00040E0E00040E0E00040E0E00080E0E00080E0E00080E0E00080E0
      E00080E0E0004080E000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0000000000F0CAA600F0CAA6000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000A4A0
      A000C0DCC000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0A000C0A08000F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF00FFFFFF0000000000000000000000000000000000C0A0
      A000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A0
      8000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF000000000000000000000000000000000000000000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE
      0000FFCE0000FFCE0000FFCE0000FFCE0000FFCE000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000004080
      E00080E0E00040E0E00040E0E00080E0E00080E0E00000000000000000000000
      0000000000004080E000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000F0CAA600F0CAA600000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000A4A0
      A0000000000000000000C0DCC000C0DCC000C0DCC000C0DCC000C0DCC000C0DC
      C000C0DCC000C0DCC000C0DCC000C0DCC000C0DCC000C0DCC000F0CAA600C0A0
      800000000000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF00FFFFFF0000000000000000000000000000000000A4A0
      A000C0DCC000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0A000C0A08000F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000004080
      E00080E0E00080E0E00080E0E00080E0E0004080E0004080E0004080E0004080
      E0004080E00080A0E000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600FFFFFF00FFFFFF00FFFFFF00FFFFFF000000
      0000F0CAA600F0CAA60000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0C0
      C000C0C0C0000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0A0
      A000C0A080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C0A080000000
      000000000000FFFFFF00FFFFFF0000000000000000000000000000000000A4A0
      A0000000000000000000C0DCC000C0DCC000C0DCC000C0DCC000C0DCC000C0DC
      C000C0DCC000C0DCC000C0DCC000C0DCC000C0DCC000C0DCC000F0CAA600C0A0
      800000000000F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600C0A080000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000004080
      E000000000000000000000000000000000004080E000F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600FFFFFF00FFFFFF00FFFFFF0000000000F0CA
      A600F0CAA6000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000C0DCC000C0C0C00000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00C0A0A000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A0
      8000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000F0CAA6000000
      000000000000FFFFFF00FFFFFF0000000000000000000000000000000000C0C0
      C000C0C0C0000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0A0
      A000C0A080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C0A080000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000000000000000000080C0
      E0004080E0004080E0004080E0004080E00080C0E000F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600FFFFFF00FFFFFF0000000000F0CAA600F0CA
      A600000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000C0DCC000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C0000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF00FFFFFF00000000000000000000000000000000000000
      0000C0DCC000C0C0C00000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00C0A0A000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000C0A0
      8000C0A08000C0A08000C0A08000C0A08000C0A08000C0A08000F0CAA6000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000F0CAA60000000000F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600FFFFFF0000000000F0CAA600F0CAA6000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF00FFFFFF00000000000000000000000000000000000000
      000000000000C0DCC000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0C000C0C0
      C000C0C0C0000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000F0CAA600FFFFFF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000F0CAA60000000000F0CAA600F0CAA600000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000F0CAA600FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00F0CAA600F0CAA600F0CAA60000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CAA600F0CA
      A600F0CAA600F0CAA600F0CAA600F0CAA6000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      28000000A0000000780000000100010000000000600900000000000000000000
      000000000000000000000000FFFFFF00FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00
      00000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000FFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFF0000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000FFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFF0000000000FFFFFFFFFFFFFFFFF0FFFFFFFFFFFF0000000000FFFFFFFF
      FFFFFFFFF0FFFFFFFFFFFF0000000000FFFFFFFFFFFFFFFFF0FFFFFFFFFFFF00
      00000000FFFFFFFFFFFFFFFFF0FFFFFFFFFFFF0000000000FFFFFFFFFFFFFFFF
      F0FFFFFFFFFFFF0000000000FFFFFFFFFFF0FFFC30FFF0FFFE07FF0000000000
      FFFFFFFFFFF0FFF800FFF0FFF801FF0000000000E007FF1FFFF0FFF000FFF0FF
      F000FF0000000000E007FF1FFFF0FFF0E0FFF0FFF0F0FF0000000000F8FFFE0F
      FFF0FFE1E0FFF0FFE0F07F0000000000F8FFFE0FFFF0FFE1F0FFF0FFE1F87F00
      00000000F8FFFC47FFF0FFE1F0FFF0FFE1F87F0000000000F8E7FC47FFF0FFE1
      F0FFF0FFE1F87F0000000000F8E7F8E3FFF000E1F0FFF000E1F87F0000000000
      F807F8E3FFF000E1F0FFF000E0F07F0000000000F807F1F1FFF000F0E0FFF000
      F0F0FF0000000000F8E7F1F1FFF000F000FFF000F000FF0000000000F8E641F0
      6FF0FFF800FFF0FFF801FF0000000000F8FE41F06FF0FFFC10FFF0FFFE07DF00
      00000000F8FE7FFFEFF0FFFFFFFFF0FFFFFFDF0000000000E0007FFFEFF0007F
      FFDFF0007FFFDF0000000000E0007FFFEFF0007FFFDFF0007FFFDF0000000000
      FFFFFFFFEFF0007FFFDFF0007FFFDF0000000000FFFFFFFFEFF0007FFFDFF000
      7FFFDF0000000000FFFFFFFFEFFFFFFFFFDFFFFFFFFFDF0000000000FFFFFFFF
      FFFFFFFFFFDFFFFFFFFFFF0000000000FFFFFFFFFFFFFFFFFFDFFFFFFFFFFF00
      00000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000FFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFF0000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000FFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFF0000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF0000000000FFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFF0000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE00780820FE007FF03FFE007
      80820FE007FF1FFFE00780820FE007FE007FE00780820FE007FF1FFFF8FFE38E
      3FF8FFFC7C7FF8FFE38E3FF8FFFE0FFFF8FFE38E3FF8FFFC7FFFF8FFE38E3FF8
      FFFE0FFFF8FFE38E3FF8FFFC7FFFF8FFE38E3FF8FFFC47FFF8E7E38E3FF8E7FC
      7FFFF8E7E38E3FF8E7FC47FFF8E7E38E3FF8E7FC7FFFF8E7E38E3FF8E7F8E3FF
      F807E38E3FF807FC7FFFF807E38E3FF807F8E3FFF807E38E3FF807FC7FFFF807
      E38E3FF807F1F1FFF8E7E1863FF8E7FC7FFFF8E7E1863FF8E7F1F1FFF8E60000
      7FF8E67001FFF8E600007FF8E641F07FF8FE0230FFF8FE7001FFF8FE0230EFF8
      FE41F07FF8FE7FFFFFF8FE7C7FBFF8FE7FFFEFF8FE7FFFFFE0007FFFFFE0007C
      7FBFE0007FFFEFE0007FFFFFE0007FFFFFE0007C7FBFE0007FFFEFE0007FFFFF
      FFFFFFFFFFFFFFFC7FBFFFFFFFFFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFFFFF
      FFFFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF000000FFFFFFFFFFFFFFFF
      FF9FFFFFFFFFFFFFFE0000007FFFFFFFFFFFFFFFFF0FFFFFFFFFFFFFFE000000
      7FF00000003FFFFFFE07FBFFFFFFFFFFFE0000007FE000000019F00000003BFF
      FFFFFFFFFE0000007FE000000019E00000001BFFFFFFFFFFFE8000017FE00000
      0019E00000001BFFFFFFFFFFFE8000017FE000000019E00000001BFFFFFFFFFF
      FE8000017FE000000019E00000001BFFFFFFFFFFFE8000017FE000000019E000
      00001BE007FE07FFFE8000017FE000000019E0001E079BE007F801FFFE800001
      7FE000000019E00000001BF8FFF0F0FFFE8000017FE000000019E00000001BF8
      FFF1F8FFFE8000017FE000000019E00000001BF8FFE3FC7FFE8000017FE00000
      0019E00000001BF8E7E3FC7FFE8000017FE000000019E00000001BF8E7E3FC7F
      F00000017FE000000019E00000001BF807E3FC7FE00000017FE000000019E000
      00801BF807F1F8FFE00000017FE000000019E00000F01BF8E7F0F0FFE0000001
      7FE000000019E00000001BF8E67801FFE00000007FE000000019E00000001BF8
      FE7E07FFE00000007FE000000019E00000001BF8FE7FFFFFE00000027FE00000
      0019E00000001BE0007FFFFFE0000004FFE000000019E00000001BE0007FFFFF
      E0780009FFEC00080019E00000001BFFFFFFFFFFE0000013FFE7FFE7FFD9EC00
      08001BFFFFFFFFFFEF000027FFF200000019E7FFE7FFDBFFFFFFFFFFE000004F
      FFF80007FFF9F20000001BFFFFFFFFFFFE80009FFFFFFFFFFFF9F80007FFFBFF
      FFFFFFFFFE7FFD3FFFE000000001FFFFFFFFFBFFFFFFFFFFFE00007FFFE00000
      0001C000000003FFFFFFFFFFFF0000FFFFE000000001C000000003FFFFFFFFFF
      FFFFFFFFFFE000000001C000000003FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFC000
      000003FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000000000
      000000000000}
  end
  object Timer2: TTimer
    Enabled = False
    Interval = 100
    OnTimer = Timer2Timer
    Left = 448
    Top = 56
  end
  object Timer3: TTimer
    Enabled = False
    Interval = 50
    OnTimer = Timer3Timer
    Left = 448
    Top = 104
  end
  object Timer4: TTimer
    Enabled = False
    OnTimer = Timer4Timer
    Left = 448
    Top = 152
  end
  object PopupMenu2: TPopupMenu
    Left = 448
    Top = 208
    object N12: TMenuItem
      Action = imageBestFitAction
    end
    object N17: TMenuItem
      Action = imageActualSizeAction
    end
    object N18: TMenuItem
      Action = imageZoomInAction
    end
    object N51: TMenuItem
      Action = imageZoomOutAction
    end
    object N52: TMenuItem
      Caption = '-'
    end
    object N58: TMenuItem
      Action = imageZoomPaneAction
    end
    object N53: TMenuItem
      Action = windowROIAction
    end
    object N56: TMenuItem
      Caption = '-'
    end
    object N57: TMenuItem
      Action = imageSaveAction
    end
    object N55: TMenuItem
      Caption = '-'
    end
    object ROI3: TMenuItem
      Action = fileLoadRoiAction
    end
    object ROI4: TMenuItem
      Action = fileSaveRoiAction
    end
  end
  object SaveDialog2: TSaveDialog
    Filter = #1054#1073#1083#1072#1089#1090#1080' '#1080#1085#1090#1077#1088#1077#1089#1072'|*.pam2r'
    Left = 496
    Top = 208
  end
  object OpenDialog2: TOpenDialog
    Filter = #1054#1073#1083#1072#1089#1090#1080' '#1080#1085#1090#1077#1088#1077#1089#1072'|*.pam2r'
    Left = 536
    Top = 208
  end
end
