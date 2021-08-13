object Form10: TForm10
  Left = 0
  Top = 0
  Caption = 'Bee Landmarks'
  ClientHeight = 561
  ClientWidth = 784
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
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 209
    Top = 49
    Height = 493
    ExplicitLeft = 264
    ExplicitTop = 424
    ExplicitHeight = 100
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 542
    Width = 784
    Height = 19
    Panels = <
      item
        Text = #1063#1080#1089#1083#1086' '#1092#1072#1081#1083#1086#1074':'
        Width = 150
      end
      item
        Text = #1056#1072#1079#1084#1077#1088':'
        Width = 150
      end
      item
        Text = #1059#1074#1077#1083#1080#1095':'
        Width = 100
      end
      item
        Width = 100
      end
      item
        Text = #1048#1085#1089#1090#1088#1091#1084#1077#1085#1090':'
        Width = 200
      end>
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 784
    Height = 49
    Align = alTop
    TabOrder = 1
    object SpeedButton1: TSpeedButton
      Left = 193
      Top = 1
      Width = 64
      Height = 47
      Action = fileLastAction
      Align = alLeft
      Caption = ' '
      Flat = True
      Glyph.Data = {
        B6020000424DB602000000000000760000002800000030000000180000000100
        0400000000004002000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCCFF
        FCCCFFFFFFFFFFFFFFFF77FFF777FFFFFFFFFFFFFFFFCCCFFCCCFFFFFFFFFFFF
        FFFF777FF777FFFFFFFFFFFFFFFFCCCCFCCCFFFFFFFFFFFFFFFF7777F777FFFF
        FFFFFFFFFFFFCCCCCCCCFFFFFFFFFFFFFFFF77777777FFFFFFFFFFFFFFFFCCCC
        CCCCFFFFFFFFFFFFFFFF77777777FFFFFFFFFFFFFFFFCCCCFCCCFFFFFFFFFFFF
        FFFF7777F777FFFFFFFFFFFFFFFFCCCFFCCCFFFFFFFFFFFFFFFF777FF777FFFF
        FFFFFFFFFFFFCCFFFCCCFFFFFFFFFFFFFFFF77FFF777FFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      Layout = blGlyphTop
      NumGlyphs = 2
      Spacing = 0
      Transparent = False
      ExplicitLeft = 218
      ExplicitTop = -3
      ExplicitHeight = 39
    end
    object SpeedButton4: TSpeedButton
      Left = 129
      Top = 1
      Width = 64
      Height = 47
      Action = fileNextAction
      Align = alLeft
      Flat = True
      Glyph.Data = {
        B6020000424DB602000000000000760000002800000030000000180000000100
        0400000000004002000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFCCFFFCCFFFFFFFFFFFFFFFFFFF77FFF77FFFFFFFFFFFFFFFCCCFFC
        CCFFFFFFFFFFFFFFFFFF777FF777FFFFFFFFFFFFFFCCCCFCCCCFFFFFFFFFFFFF
        FFFF7777F7777FFFFFFFFFFFFFCCCCCCCCCCFFFFFFFFFFFFFFFF7777777777FF
        FFFFFFFFFFCCCCCCCCCCCFFFFFFFFFFFFFFF77777777777FFFFFFFFFFFCCCCCC
        CCCCFFFFFFFFFFFFFFFF7777777777FFFFFFFFFFFFCCCCFCCCCFFFFFFFFFFFFF
        FFFF7777F7777FFFFFFFFFFFFFCCCFFCCCFFFFFFFFFFFFFFFFFF777FF777FFFF
        FFFFFFFFFFCCFFFCCFFFFFFFFFFFFFFFFFFF77FFF77FFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      Layout = blGlyphTop
      NumGlyphs = 2
      ExplicitLeft = 241
      ExplicitTop = -2
      ExplicitHeight = 39
    end
    object SpeedButton3: TSpeedButton
      Left = 65
      Top = 1
      Width = 64
      Height = 47
      Action = filePrevAction
      Align = alLeft
      Flat = True
      Glyph.Data = {
        B6020000424DB602000000000000760000002800000030000000180000000100
        0400000000004002000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFCCFFFCCFFFFFFFFFFFFFFFFFFF77FFF77FFFFFFFFFFFFFFCCCF
        FCCCFFFFFFFFFFFFFFFFFF777FF777FFFFFFFFFFFFFCCCCFCCCCFFFFFFFFFFFF
        FFFFF7777F7777FFFFFFFFFFFFCCCCCCCCCCFFFFFFFFFFFFFFFF7777777777FF
        FFFFFFFFFCCCCCCCCCCCFFFFFFFFFFFFFFF77777777777FFFFFFFFFFFFCCCCCC
        CCCCFFFFFFFFFFFFFFFF7777777777FFFFFFFFFFFFFCCCCFCCCCFFFFFFFFFFFF
        FFFFF7777F7777FFFFFFFFFFFFFFCCCFFCCCFFFFFFFFFFFFFFFFFF777FF777FF
        FFFFFFFFFFFFFCCFFFCCFFFFFFFFFFFFFFFFFFF77FFF77FFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      Layout = blGlyphTop
      NumGlyphs = 2
      ExplicitLeft = 177
      ExplicitTop = -2
      ExplicitHeight = 39
    end
    object SpeedButton2: TSpeedButton
      Left = 1
      Top = 1
      Width = 64
      Height = 47
      Action = fileFirstAction
      Align = alLeft
      Flat = True
      Glyph.Data = {
        B6020000424DB602000000000000760000002800000030000000180000000100
        0400000000004002000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCCCF
        FFCCFFFFFFFFFFFFFFFF777FFF77FFFFFFFFFFFFFFFFCCCFFCCCFFFFFFFFFFFF
        FFFF777FF777FFFFFFFFFFFFFFFFCCCFCCCCFFFFFFFFFFFFFFFF777F7777FFFF
        FFFFFFFFFFFFCCCCCCCCFFFFFFFFFFFFFFFF77777777FFFFFFFFFFFFFFFFCCCC
        CCCCFFFFFFFFFFFFFFFF77777777FFFFFFFFFFFFFFFFCCCFCCCCFFFFFFFFFFFF
        FFFF777F7777FFFFFFFFFFFFFFFFCCCFFCCCFFFFFFFFFFFFFFFF777FF777FFFF
        FFFFFFFFFFFFCCCFFFCCFFFFFFFFFFFFFFFF777FFF77FFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      Layout = blGlyphTop
      NumGlyphs = 2
      ExplicitLeft = 49
      ExplicitTop = -2
      ExplicitHeight = 39
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 49
    Width = 209
    Height = 493
    Align = alLeft
    TabOrder = 2
    object Splitter2: TSplitter
      Left = 1
      Top = 233
      Width = 207
      Height = 3
      Cursor = crVSplit
      Align = alTop
      ExplicitWidth = 231
    end
    object Panel4: TPanel
      Left = 1
      Top = 1
      Width = 207
      Height = 232
      Align = alTop
      TabOrder = 0
      object DirectoryListBox1: TDirectoryListBox
        Left = 1
        Top = 1
        Width = 205
        Height = 230
        Align = alClient
        FileList = FileListBox1
        TabOrder = 0
        OnChange = DirectoryListBox1Change
      end
    end
    object Panel5: TPanel
      AlignWithMargins = True
      Left = 4
      Top = 461
      Width = 201
      Height = 28
      Align = alBottom
      TabOrder = 1
      object DriveComboBox1: TDriveComboBox
        Left = 1
        Top = 1
        Width = 199
        Height = 19
        Align = alClient
        DirList = DirectoryListBox1
        TabOrder = 0
      end
    end
    object Panel6: TPanel
      Left = 1
      Top = 236
      Width = 207
      Height = 222
      Align = alClient
      TabOrder = 2
      object FileListBox1: TFileListBox
        Left = 1
        Top = 1
        Width = 205
        Height = 220
        Align = alClient
        ItemHeight = 13
        Mask = '*.jpg'
        TabOrder = 0
        OnChange = FileListBox1Change
      end
    end
  end
  object Panel3: TPanel
    Left = 212
    Top = 49
    Width = 572
    Height = 493
    Align = alClient
    TabOrder = 3
    object PageControl1: TPageControl
      Left = 1
      Top = 1
      Width = 570
      Height = 491
      ActivePage = TabSheet1
      Align = alClient
      TabOrder = 0
      object TabSheet1: TTabSheet
        Caption = #1048#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077
        object PhImage1: TPhImage
          Left = 0
          Top = 0
          Width = 562
          Height = 463
          AutoMosaic = True
          ThumbWidht = 128
          ThumbHeight = 128
          SlideShowInterval = 500
          Align = alClient
          ParentColor = False
          OnMouseMove = PhImage1MouseMove
          OnPaint = PhImage1Paint
          AfterOpen = PhImage1AfterOpen
          OnScaleChange = PhImage1ScaleChange
          OnToolChange = PhImage1ToolChange
        end
      end
    end
  end
  object ActionList1: TActionList
    Left = 596
    Top = 89
    object fileExitAction: TAction
      Category = 'File'
      Caption = #1047#1072#1074#1077#1088#1096#1077#1085#1080#1077' '#1088#1072#1073#1086#1090#1099
      OnExecute = fileExitActionExecute
    end
    object fileFirstAction: TAction
      Category = 'File'
      Caption = #1055#1077#1088#1074#1099#1081' '#1092#1072#1081#1083
      OnExecute = fileFirstActionExecute
      OnUpdate = fileFirstActionUpdate
    end
    object fileLastAction: TAction
      Category = 'File'
      Caption = #1055#1086#1089#1083#1077#1076#1085#1080#1081' '#1092#1072#1081#1083
      OnExecute = fileLastActionExecute
      OnUpdate = fileLastActionUpdate
    end
    object fileNextAction: TAction
      Category = 'File'
      Caption = #1057#1083#1077#1076#1091#1102#1097#1080#1081' '#1092#1072#1081#1083
      OnExecute = fileNextActionExecute
      OnUpdate = fileNextActionUpdate
    end
    object filePrevAction: TAction
      Category = 'File'
      Caption = #1055#1088#1077#1076#1099#1076#1091#1097#1080#1081' '#1092#1072#1081#1083
      OnExecute = filePrevActionExecute
      OnUpdate = filePrevActionUpdate
    end
    object fileExportTPSAction: TAction
      Category = 'File'
      Caption = #1069#1082#1089#1087#1086#1088#1090' TPS...'
      OnExecute = fileExportTPSActionExecute
      OnUpdate = fileExportTPSActionUpdate
    end
    object fileAnalysisAction: TAction
      Category = 'File'
      Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100' '#1072#1085#1072#1083#1080#1079'...'
      OnExecute = fileAnalysisActionExecute
      OnUpdate = fileAnalysisActionUpdate
    end
    object viewToolbarAction: TAction
      Category = 'View'
      Caption = #1055#1072#1085#1077#1083#1100' '#1080#1085#1089#1090#1088#1091#1084#1077#1085#1090#1086#1074
      OnExecute = viewToolbarActionExecute
      OnUpdate = viewToolbarActionUpdate
    end
    object viewFilePanelAction: TAction
      Category = 'View'
      Caption = #1055#1072#1085#1077#1083#1100' '#1092#1072#1081#1083#1086#1074
      OnExecute = viewFilePanelActionExecute
      OnUpdate = viewFilePanelActionUpdate
    end
    object viewStatusBarAction: TAction
      Category = 'View'
      Caption = #1057#1090#1088#1086#1082#1072' '#1089#1086#1089#1090#1086#1103#1085#1080#1103
      OnExecute = viewStatusBarActionExecute
      OnUpdate = viewStatusBarActionUpdate
    end
    object viewBestFitAction: TAction
      Category = 'View'
      Caption = #1042#1087#1080#1089#1072#1090#1100' '#1074' '#1086#1082#1085#1086
      OnExecute = viewBestFitActionExecute
    end
    object toolsZoomPaneAction: TAction
      Category = 'Tools'
      Caption = #1059#1074#1077#1083#1080#1095' - '#1055#1077#1088#1077#1084#1077#1097#1077#1085#1080#1077
      OnExecute = toolsZoomPaneActionExecute
      OnUpdate = toolsZoomPaneActionUpdate
    end
    object toolsZoomToRectAction: TAction
      Category = 'Tools'
      Caption = #1059#1074#1077#1083#1080#1095'. '#1087#1088#1103#1084#1086#1075#1086#1083#1100#1085#1080#1082
      OnExecute = toolsZoomToRectActionExecute
      OnUpdate = toolsZoomToRectActionUpdate
    end
    object toolsRulerAction: TAction
      Category = 'Tools'
      Caption = #1048#1079#1084#1077#1088#1080#1090#1100' '#1088#1072#1089#1089#1090#1086#1103#1085#1080#1077
      OnExecute = toolsRulerActionExecute
      OnUpdate = toolsRulerActionUpdate
    end
    object toolsAngleAction: TAction
      Category = 'Tools'
      Caption = #1048#1079#1084#1077#1088#1080#1090#1100' '#1091#1075#1086#1083
      OnExecute = toolsAngleActionExecute
      OnUpdate = toolsAngleActionUpdate
    end
    object toolsBeeLandmarksAction: TAction
      Category = 'Tools'
      Caption = #1054#1089#1086#1073#1099#1077' '#1090#1086#1095#1082#1080
      OnExecute = toolsBeeLandmarksActionExecute
      OnUpdate = toolsBeeLandmarksActionUpdate
    end
    object toolsEditROIAction: TAction
      Category = 'Tools'
      Caption = #1054#1073#1083#1072#1089#1090#1080' '#1087#1086#1080#1089#1082#1072
      OnExecute = toolsEditROIActionExecute
      OnUpdate = toolsEditROIActionUpdate
    end
  end
  object MainMenu1: TMainMenu
    Left = 545
    Top = 90
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083#1099
      object N9: TMenuItem
        Action = fileAnalysisAction
      end
      object PS1: TMenuItem
        Action = fileExportTPSAction
      end
      object N8: TMenuItem
        Caption = '-'
      end
      object N7: TMenuItem
        Action = fileFirstAction
      end
      object N6: TMenuItem
        Action = filePrevAction
      end
      object N5: TMenuItem
        Action = fileNextAction
      end
      object N4: TMenuItem
        Action = fileLastAction
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object N2: TMenuItem
        Action = fileExitAction
      end
    end
    object N10: TMenuItem
      Caption = #1042#1080#1079#1091#1072#1083#1080#1079#1072#1094#1080#1103
      object N15: TMenuItem
        Action = viewBestFitAction
      end
      object N14: TMenuItem
        Caption = '-'
      end
      object N11: TMenuItem
        Action = viewFilePanelAction
      end
      object N12: TMenuItem
        Action = viewToolbarAction
      end
      object N13: TMenuItem
        Action = viewStatusBarAction
      end
    end
    object N16: TMenuItem
      Caption = #1048#1085#1089#1090#1088#1091#1084#1077#1085#1090#1099
      object N17: TMenuItem
        Action = toolsZoomPaneAction
      end
      object N18: TMenuItem
        Action = toolsZoomToRectAction
      end
      object N19: TMenuItem
        Action = toolsRulerAction
      end
      object N20: TMenuItem
        Action = toolsAngleAction
      end
      object N21: TMenuItem
        Action = toolsBeeLandmarksAction
      end
      object N22: TMenuItem
        Action = toolsEditROIAction
      end
      object N23: TMenuItem
        Caption = '-'
      end
    end
  end
  object PhPaneTool1: TPhPaneTool
    PhImage = PhImage1
    Left = 713
    Top = 90
  end
  object PhRulerTool1: TPhRulerTool
    PhImage = PhImage1
    Left = 713
    Top = 146
  end
  object PhZoomToRectTool1: TPhZoomToRectTool
    PhImage = PhImage1
    Left = 713
    Top = 194
  end
  object PhTriangleTool1: TPhTriangleTool
    PhImage = PhImage1
    Left = 713
    Top = 250
  end
  object PhZonesTool1: TPhZonesTool
    PhImage = PhImage1
    Left = 713
    Top = 306
  end
  object PhLandmarksTool1: TPhLandmarksTool
    PhImage = PhImage1
    Left = 713
    Top = 362
  end
  object SaveDialog1: TSaveDialog
    Filter = #1060#1072#1081#1083#1099' TPS|*.tps'
    Left = 721
    Top = 418
  end
end
