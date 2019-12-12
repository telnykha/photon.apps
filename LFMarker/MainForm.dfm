object Form1: TForm1
  Left = 615
  Top = 173
  Caption = 'Image Marker'
  ClientHeight = 612
  ClientWidth = 800
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  OnKeyPress = FormKeyPress
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object ToolBar1: TToolBar
    Left = 0
    Top = 0
    Width = 800
    Height = 34
    AutoSize = True
    ButtonHeight = 34
    ButtonWidth = 53
    Caption = 'ToolBar1'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -9
    Font.Name = 'Small Fonts'
    Font.Style = []
    Images = ImageList1
    ParentFont = False
    ShowCaptions = True
    TabOrder = 0
    object ToolButton6: TToolButton
      Left = 0
      Top = 0
      Action = ModePaneAction
      Caption = 'Pane'
      ParentShowHint = False
      ShowHint = True
      Style = tbsCheck
    end
    object ToolButton10: TToolButton
      Left = 53
      Top = 0
      Action = ModeZoomAction
      Caption = 'Zoom'
      ParentShowHint = False
      ShowHint = True
      Style = tbsCheck
    end
    object ToolButton2: TToolButton
      Left = 106
      Top = 0
      Action = ModeSelectRectAction
    end
    object ToolButton4: TToolButton
      Left = 159
      Top = 0
      Action = ModeMarkRectAction
      Caption = 'Mark'
      Style = tbsCheck
    end
    object ToolButton12: TToolButton
      Left = 212
      Top = 0
      Width = 8
      Caption = 'ToolButton12'
      ImageIndex = 0
      Style = tbsSeparator
    end
    object ToolButton11: TToolButton
      Left = 220
      Top = 0
      Action = ModeBestFitAction
      Grouped = True
      ParentShowHint = False
      ShowHint = True
      Style = tbsCheck
    end
    object ToolButton9: TToolButton
      Left = 273
      Top = 0
      Action = ModeActualSizeAction
      Caption = 'Actual Size'
      Grouped = True
      ParentShowHint = False
      ShowHint = True
      Style = tbsCheck
    end
    object ToolButton1: TToolButton
      Left = 326
      Top = 0
      Action = ImageDelImageAction
      Caption = 'Delete'
      ParentShowHint = False
      ShowHint = True
    end
    object ToolButton14: TToolButton
      Left = 379
      Top = 0
      Width = 8
      Caption = 'ToolButton14'
      ImageIndex = 0
      Style = tbsSeparator
    end
    object ToolButton8: TToolButton
      Left = 387
      Top = 0
      Action = DtDetectAction
      Caption = 'Objects'
      Style = tbsCheck
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 593
    Width = 800
    Height = 19
    Panels = <
      item
        Width = 300
      end
      item
        Alignment = taCenter
        Width = 80
      end
      item
        Alignment = taCenter
        Width = 120
      end
      item
        Alignment = taCenter
        Width = 200
      end
      item
        Width = 50
      end>
    OnResize = StatusBar1Resize
  end
  object Panel5: TPanel
    Left = 0
    Top = 34
    Width = 800
    Height = 559
    Align = alClient
    Caption = 'Panel5'
    TabOrder = 2
    object Splitter4: TSplitter
      Left = 1
      Top = 498
      Width = 798
      Height = 3
      Cursor = crVSplit
      Align = alBottom
      ExplicitTop = 1
      ExplicitWidth = 335
    end
    object Splitter2: TSplitter
      Left = 249
      Top = 1
      Width = 4
      Height = 497
      Beveled = True
      ExplicitLeft = 9
      ExplicitTop = 9
    end
    object Panel7: TPanel
      Left = 1
      Top = 501
      Width = 798
      Height = 57
      Align = alBottom
      Caption = 'Panel7'
      TabOrder = 0
      object Memo1: TMemo
        Left = 1
        Top = 1
        Width = 796
        Height = 55
        Align = alClient
        TabOrder = 0
      end
    end
    object Panel1: TPanel
      Left = 1
      Top = 1
      Width = 248
      Height = 497
      Align = alLeft
      TabOrder = 1
      OnResize = Panel1Resize
      object PageControl1: TPageControl
        Left = 1
        Top = 1
        Width = 246
        Height = 495
        ActivePage = TabSheet1
        Align = alClient
        TabOrder = 0
        TabPosition = tpBottom
        object TabSheet1: TTabSheet
          Caption = 'File System'
          ExplicitLeft = 0
          ExplicitTop = 0
          ExplicitWidth = 281
          ExplicitHeight = 291
          object Splitter5: TSplitter
            Left = 0
            Top = 227
            Width = 238
            Height = 10
            Cursor = crVSplit
            Align = alTop
            Beveled = True
            ExplicitTop = 223
            ExplicitWidth = 281
          end
          object DirectoryListBox1: TDirectoryListBox
            Left = 0
            Top = 0
            Width = 238
            Height = 227
            Align = alTop
            FileList = FileListBox1
            TabOrder = 0
            OnChange = DirectoryListBox1Change
            ExplicitWidth = 297
          end
          object Panel9: TPanel
            Left = 0
            Top = 442
            Width = 238
            Height = 27
            Align = alBottom
            TabOrder = 1
            ExplicitLeft = -4
            ExplicitTop = 264
            ExplicitWidth = 175
            object DriveComboBox1: TDriveComboBox
              Left = 1
              Top = 1
              Width = 236
              Height = 19
              Align = alTop
              DirList = DirectoryListBox1
              TabOrder = 0
              ExplicitWidth = 173
            end
          end
          object FilterComboBox1: TFilterComboBox
            Left = 25
            Top = 273
            Width = 145
            Height = 21
            FileList = FileListBox1
            Filter = 'Image files|*.awp'
            TabOrder = 2
            Visible = False
          end
          object FileListBox1: TFileListBox
            Left = 0
            Top = 237
            Width = 238
            Height = 205
            Align = alClient
            Mask = '*.jpg;*awp;*.png;*.bmp'
            MultiSelect = True
            PopupMenu = PopupMenu1
            ShowGlyphs = True
            TabOrder = 3
            OnChange = FileListBox1Change
            OnKeyUp = FileListBox1KeyUp
            ExplicitLeft = 48
            ExplicitTop = 239
            ExplicitWidth = 136
            ExplicitHeight = 82
          end
          object FImage2: TFImage
            Left = 0
            Top = 237
            Width = 238
            Height = 205
            Cursor = 1
            BorderStyle = bsFSingle
            Align = alClient
            ParentColor = False
            Visible = False
            ExplicitLeft = 41
            ExplicitTop = 251
            ExplicitWidth = 104
            ExplicitHeight = 103
          end
        end
        object TabSheet2: TTabSheet
          Caption = 'Project'
          ImageIndex = 1
          ExplicitWidth = 281
          ExplicitHeight = 167
          object Splitter1: TSplitter
            Left = 0
            Top = 257
            Width = 238
            Height = 3
            Cursor = crVSplit
            Align = alTop
            ExplicitTop = 177
            ExplicitWidth = 292
          end
          object TreeView1: TTreeView
            Left = 0
            Top = 0
            Width = 238
            Height = 257
            Align = alTop
            Indent = 19
            TabOrder = 0
          end
          object Panel2: TPanel
            Left = 0
            Top = 260
            Width = 238
            Height = 41
            Align = alTop
            TabOrder = 1
            ExplicitLeft = 96
            ExplicitTop = 296
            ExplicitWidth = 185
          end
          object ListView1: TListView
            Left = 0
            Top = 301
            Width = 238
            Height = 168
            Align = alClient
            Columns = <>
            TabOrder = 2
            ExplicitLeft = 72
            ExplicitTop = 344
            ExplicitWidth = 250
            ExplicitHeight = 150
          end
        end
        object TabSheet3: TTabSheet
          Caption = 'Database'
          ImageIndex = 2
          object Panel3: TPanel
            Left = 0
            Top = 0
            Width = 238
            Height = 33
            Align = alTop
            TabOrder = 0
          end
        end
      end
    end
    object Panel6: TPanel
      Left = 253
      Top = 1
      Width = 546
      Height = 497
      Align = alClient
      Caption = 'Panel2'
      TabOrder = 2
      ExplicitLeft = 182
      ExplicitWidth = 617
      object Panel11: TPanel
        Left = 1
        Top = 1
        Width = 544
        Height = 495
        Align = alClient
        TabOrder = 0
        ExplicitWidth = 615
        object HSplitter: TSplitter
          Left = 1
          Top = 486
          Width = 542
          Height = 3
          Cursor = crVSplit
          Align = alBottom
          ExplicitTop = 540
          ExplicitWidth = 557
        end
        object Splitter7: TSplitter
          Left = 535
          Top = 1
          Height = 485
          Align = alRight
          ExplicitLeft = 550
          ExplicitHeight = 539
        end
        object BottomDocPanel: TPanel
          Left = 1
          Top = 489
          Width = 542
          Height = 5
          Align = alBottom
          DockSite = True
          DragKind = dkDock
          TabOrder = 0
          OnDockDrop = BottomDocPanelDockDrop
          OnDockOver = BottomDocPanelDockOver
          OnGetSiteInfo = BottomDocPanelGetSiteInfo
          OnUnDock = BottomDocPanelUnDock
          ExplicitWidth = 613
        end
        object Panel13: TPanel
          Left = 538
          Top = 1
          Width = 5
          Height = 485
          Align = alRight
          Caption = 'Panel3'
          DockSite = True
          DragKind = dkDock
          TabOrder = 1
          ExplicitLeft = 609
        end
        object FImage1: TFImage
          Left = 1
          Top = 1
          Width = 534
          Height = 485
          BorderStyle = bsFSingle
          Align = alClient
          ParentColor = False
          OnMouseMove = FImage1MouseMove
          OnMouseUp = FFaceEditor1MouseUp
          AfterOpen = FFaceEditor1AfterOpen
          ExplicitWidth = 605
        end
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = 'XML files|*.xml'
    Left = 376
    Top = 56
  end
  object MainMenu1: TMainMenu
    Images = ImageList1
    Left = 280
    Top = 56
    object File1: TMenuItem
      Caption = 'Files'
      object N11: TMenuItem
        Caption = '-'
      end
      object Close1: TMenuItem
        Action = CloseAction
      end
    end
    object View1: TMenuItem
      Caption = 'View'
      object Actualsize1: TMenuItem
        Action = ModeActualSizeAction
      end
      object BestFit1: TMenuItem
        Action = ModeBestFitAction
      end
      object N14: TMenuItem
        Caption = '-'
      end
      object Toolbar2: TMenuItem
        Action = ViewToolbarAction
      end
      object StatusBar2: TMenuItem
        Action = ViewStatusbarAction
      end
      object DirectoryPane1: TMenuItem
        Action = ViewDirectoryAction
      end
      object N15: TMenuItem
        Caption = '-'
      end
      object ViewSemanticOutput1: TMenuItem
        Action = ViewSemanticOutputAction
      end
      object Overlaps1: TMenuItem
        Action = ViewOlerlapsAction
      end
      object ViewFarthestOverlaps1: TMenuItem
        Action = ViewFarthestOverlapsAction
      end
      object N13: TMenuItem
        Action = ViewSubsetAction
        Visible = False
      end
      object ViewTable1: TMenuItem
        Action = ViewTableAction
      end
      object ViewSemanticEditorAction1: TMenuItem
        Action = ViewSemanticEditorAction
      end
      object N17: TMenuItem
        Caption = '-'
      end
      object ViewSemanticThumbnail1: TMenuItem
        Action = ViewSemanticThumbinalsAction
      end
    end
    object Tool1: TMenuItem
      Caption = 'Mouse Mode'
      object N4: TMenuItem
        Action = ModePaneAction
      end
      object N5: TMenuItem
        Action = ModeZoomAction
      end
      object SetRect1: TMenuItem
        Action = ModeMarkRectAction
      end
      object ModeLenzAction1: TMenuItem
        Action = ModeLenzAction
      end
      object SelectROI1: TMenuItem
        Action = ModeSelectRectAction
      end
    end
    object I1: TMenuItem
      Caption = 'Image processing'
      object Invert1: TMenuItem
        Action = ImageInvertAction
        ShortCut = 16457
      end
      object Grayscale1: TMenuItem
        Action = ImageGrayscaleAction
      end
      object Mirror1: TMenuItem
        Action = ImageMirrorAction
      end
      object FlipVertical1: TMenuItem
        Action = ImageFlipAction
      end
      object FlipLeft1: TMenuItem
        Action = ImageFlipLeftAction
        OnClick = FlipLeft1Click
      end
      object FlipRight1: TMenuItem
        Action = ImageFlipRightAction
      end
      object Rotate2: TMenuItem
        Action = ImageRotateAction
      end
      object Crop1: TMenuItem
        Action = ImageCropAction
      end
      object SobelFilter1: TMenuItem
        Action = ImageSobelAction
      end
      object ImageFilterAction1: TMenuItem
        Action = ImageFilterAction
      end
      object GaussFilter1: TMenuItem
        Action = ImageGaussFilterAction
      end
      object MedianFilter1: TMenuItem
        Action = ImageMedianFilterAction
      end
      object Resize1: TMenuItem
        Action = ImageResizeAction
      end
      object N12: TMenuItem
        Caption = '-'
      end
      object N16: TMenuItem
        Action = ImageDelImageAction
        ShortCut = 16430
      end
      object Copyfiles1: TMenuItem
        Action = ImageCopyImageAction
      end
    end
    object N1: TMenuItem
      Caption = 'Database'
      object DatabaseInfo1: TMenuItem
        Action = DbInfoAction
      end
      object Dictionary1: TMenuItem
        Action = dbDictionaryAction
      end
      object N18: TMenuItem
        Caption = '-'
      end
      object CopyDatabase1: TMenuItem
        Action = DbCopyAction
      end
      object Exportimages1: TMenuItem
        Action = DbExportFragmentsAction
      end
      object Exportawpimages1: TMenuItem
        Action = DbConvertDatabaseAction
      end
      object DoAnalysis1: TMenuItem
        Action = DbMarkingAction
      end
      object SplitDatabase1: TMenuItem
        Action = DbSplitDatabase
      end
      object N10: TMenuItem
        Caption = '-'
      end
      object SelectAll1: TMenuItem
        Action = DbSelectAllAction
        Visible = False
      end
      object ClearSelection1: TMenuItem
        Action = DbClearSelectionAction
        Visible = False
      end
      object InvertSelection1: TMenuItem
        Action = DbInvertSelectionAction
        Visible = False
      end
      object DeleteSelected1: TMenuItem
        Action = DbDeleteSelectedAction
        Visible = False
      end
      object CopySelectedTo1: TMenuItem
        Action = DbCopySelectedToAction
        Visible = False
      end
      object DbMoveSelectedTo1: TMenuItem
        Action = DbMoveSelectedToAction
        Visible = False
      end
    end
    object N2: TMenuItem
      Caption = 'Detector'
      object N9: TMenuItem
        Action = FileOpenDetectorAction
      end
      object N19: TMenuItem
        Caption = '-'
      end
      object Detectorinfo1: TMenuItem
        Action = DtInfoAction
      end
      object Viewdetector1: TMenuItem
        Action = DtViewAction
      end
      object N23: TMenuItem
        Action = DtDetectAction
      end
      object Engineerrors1: TMenuItem
        Action = DtErrorsAction
      end
    end
    object Tools1: TMenuItem
      Caption = 'Tools'
      object Options1: TMenuItem
        Caption = 'Options...'
        OnClick = Options1Click
      end
    end
    object N3: TMenuItem
      Caption = 'Help'
      object N25: TMenuItem
        Action = AboutAction
      end
    end
  end
  object ActionList2: TActionList
    Images = ImageList1
    Left = 312
    Top = 56
    object CloseAction: TAction
      Category = 'File'
      Caption = 'Exit'
      Hint = 'Exit from program'
      OnExecute = CloseActionExecute
    end
    object SaveAction: TAction
      Category = 'File'
      Caption = 'Save eyes position'
      ImageIndex = 0
    end
    object FileOpenDetectorAction: TAction
      Category = 'File'
      Caption = 'Load  object detector...'
      Hint = '|Load file detector'
      OnExecute = FileOpenDetectorActionExecute
    end
    object ModePaneAction: TAction
      Category = 'Mode'
      Caption = 'Pane Tool'
      GroupIndex = 1
      Hint = 'pane|pane'
      ImageIndex = 5
      OnExecute = ModePaneActionExecute
      OnUpdate = ModePaneActionUpdate
    end
    object ModeZoomAction: TAction
      Category = 'Mode'
      Caption = 'Zoom Tool'
      GroupIndex = 1
      Hint = 'Zoom|Zoom'
      ImageIndex = 3
      OnExecute = ModeZoomActionExecute
      OnUpdate = ModeZoomActionUpdate
    end
    object ModeBestFitAction: TAction
      Category = 'Mode'
      Caption = 'Best Fit'
      Hint = 'Best Fit|Best Fit'
      ImageIndex = 4
      ShortCut = 16450
      OnExecute = ModeBestFitActionExecute
      OnUpdate = ModeBestFitActionUpdate
    end
    object ModeActualSizeAction: TAction
      Category = 'Mode'
      Caption = 'Actual size'
      Hint = 'Actual size|Actual size of  image'
      ImageIndex = 8
      ShortCut = 16449
      OnExecute = ModeActualSizeActionExecute
      OnUpdate = ModeActualSizeActionUpdate
    end
    object ImageDelImageAction: TAction
      Category = 'Image'
      Caption = 'Delete Image'
      Hint = 'Delete image|Delete image from database'
      ImageIndex = 12
      OnExecute = ImageDelImageActionExecute
      OnUpdate = ImageDelImageActionUpdate
    end
    object DtDetectAction: TAction
      Category = 'Detector'
      Caption = 'Find Objects'
      Hint = 'Find faces|Find faces'
      ImageIndex = 1
      OnExecute = DtDetectActionExecute
      OnUpdate = DtDetectActionUpdate
    end
    object AboutAction: TAction
      Category = 'Help'
      Caption = 'About...'
      Hint = '| About'
      OnExecute = AboutActionExecute
    end
    object ModeMarkRectAction: TAction
      Category = 'Mode'
      Caption = 'Mark Tool'
      GroupIndex = 1
      ImageIndex = 6
      OnExecute = ModeMarkRectActionExecute
      OnUpdate = ModeMarkRectActionUpdate
    end
    object ViewToolbarAction: TAction
      Category = 'View'
      Caption = 'Tool Bar '
      Hint = 'View Toolbar '
      OnExecute = ViewToolbarActionExecute
      OnUpdate = ViewToolbarActionUpdate
    end
    object ViewStatusbarAction: TAction
      Category = 'View'
      Caption = 'Status Bar'
      Hint = 'View status bar'
      OnExecute = ViewStatusbarActionExecute
      OnUpdate = ViewStatusbarActionUpdate
    end
    object ViewDirectoryAction: TAction
      Category = 'View'
      Caption = 'Directory Pane'
      Hint = 'View Directory Pane'
      OnExecute = ViewDirectoryActionExecute
      OnUpdate = ViewDirectoryActionUpdate
    end
    object ViewTableAction: TAction
      Category = 'View'
      Caption = 'Sematic Table'
      Hint = 'View Table'
      OnExecute = ViewTableActionExecute
      OnUpdate = ViewTableActionUpdate
    end
    object DbInfoAction: TAction
      Category = 'Database'
      Caption = 'Database Info...'
      OnExecute = DbInfoActionExecute
      OnUpdate = DbInfoActionUpdate
    end
    object ViewOlerlapsAction: TAction
      Category = 'View'
      Caption = 'View Nearest Overlaps '
      OnExecute = ViewOlerlapsActionExecute
      OnUpdate = ViewOlerlapsActionUpdate
    end
    object DbExportFragmentsAction: TAction
      Category = 'Database'
      Caption = 'Export Image Fragments...'
      OnExecute = DbExportFragmentsActionExecute
      OnUpdate = DbExportFragmentsActionUpdate
    end
    object DtErrorsAction: TAction
      Category = 'Detector'
      Caption = 'Engine errors...'
      OnExecute = DtErrorsActionExecute
    end
    object ViewSubsetAction: TAction
      Category = 'View'
      Caption = 'Database Subset'
    end
    object ViewSemanticOutputAction: TAction
      Category = 'View'
      Caption = 'View Semantic Output'
      OnExecute = ViewSemanticOutputActionExecute
      OnUpdate = ViewSemanticOutputActionUpdate
    end
    object DbConvertDatabaseAction: TAction
      Category = 'Database'
      Caption = 'Convert Database....'
      OnExecute = DbConvertDatabaseActionExecute
    end
    object DbCopyAction: TAction
      Category = 'Database'
      Caption = 'Copy Database...'
      OnExecute = DbCopyActionExecute
      OnUpdate = DbCopyActionUpdate
    end
    object ImageCopyImageAction: TAction
      Category = 'Image'
      Caption = 'Copy file(s)...'
      ShortCut = 16465
      OnExecute = ImageCopyImageActionExecute
      OnUpdate = ImageCopyImageActionUpdate
    end
    object ViewDbTubinalsAction: TAction
      Category = 'View'
      Caption = 'View Database Thumbnail'
    end
    object EditCopy1: TEditCopy
      Category = 'Edit'
      Caption = '&Copy'
      Hint = 'Copy|Copies the selection and puts it on the Clipboard'
      ImageIndex = 15
      ShortCut = 16451
      OnExecute = EditCopy1Execute
      OnUpdate = EditCopy1Update
    end
    object ModeLenzAction: TAction
      Category = 'Mode'
      Caption = 'Lenz Tool'
      ImageIndex = 8
      OnExecute = ModeLenzActionExecute
      OnUpdate = ModeLenzActionUpdate
    end
    object ModeFaceAction: TAction
      Category = 'Mode'
      Caption = 'Face Tool'
      ImageIndex = 2
    end
    object ViewSemanticThumbinalsAction: TAction
      Category = 'View'
      Caption = 'View Semantic Thumbnail'
      OnExecute = ViewSemanticThumbinalsActionExecute
      OnUpdate = ViewSemanticThumbinalsActionUpdate
    end
    object ViewListAction: TAction
      Category = 'View'
      Caption = 'View File List'
      OnExecute = ViewListActionExecute
      OnUpdate = ViewListActionUpdate
    end
    object DbClearSelectionAction: TAction
      Category = 'Database'
      Caption = 'Clear Selection'
      OnExecute = DbClearSelectionActionExecute
      OnUpdate = DbClearSelectionActionUpdate
    end
    object DbInvertSelectionAction: TAction
      Category = 'Database'
      Caption = 'Invert Selection'
      OnExecute = DbInvertSelectionActionExecute
      OnUpdate = DbInvertSelectionActionUpdate
    end
    object DbDeleteSelectedAction: TAction
      Category = 'Database'
      Caption = 'Delete Selected'
      OnExecute = DbDeleteSelectedActionExecute
      OnUpdate = DbDeleteSelectedActionUpdate
    end
    object DbCopySelectedToAction: TAction
      Category = 'Database'
      Caption = 'Copy Selected To...'
      OnExecute = DbCopySelectedToActionExecute
      OnUpdate = DbCopySelectedToActionUpdate
    end
    object DbMoveSelectedToAction: TAction
      Category = 'Database'
      Caption = 'Db Move Selected To...'
      OnExecute = DbMoveSelectedToActionExecute
      OnUpdate = DbMoveSelectedToActionUpdate
    end
    object DbSelectAllAction: TAction
      Category = 'Database'
      Caption = 'Select All'
      OnExecute = DbSelectAllActionExecute
      OnUpdate = DbSelectAllActionUpdate
    end
    object DtInfoAction: TAction
      Category = 'Detector'
      Caption = 'Detector info...'
      OnExecute = DtInfoActionExecute
      OnUpdate = DtInfoActionUpdate
    end
    object ViewFarthestOverlapsAction: TAction
      Category = 'View'
      Caption = 'View Farthest Overlaps '
      OnExecute = ViewFarthestOverlapsActionExecute
      OnUpdate = ViewFarthestOverlapsActionUpdate
    end
    object DbMarkingAction: TAction
      Category = 'Database'
      Caption = 'Do Analysis '
      OnExecute = DbMarkingActionExecute
      OnUpdate = DbMarkingActionUpdate
    end
    object DtViewAction: TAction
      Category = 'Detector'
      Caption = 'View detector...'
      OnExecute = DtViewActionExecute
      OnUpdate = DtViewActionUpdate
    end
    object ViewSemanticEditorAction: TAction
      Category = 'View'
      Caption = 'Semantic  Items Editor'
      OnExecute = ViewSemanticEditorActionExecute
      OnUpdate = ViewSemanticEditorActionUpdate
    end
    object dbDictionaryAction: TAction
      Category = 'Database'
      Caption = 'Dictionary...'
      OnExecute = dbDictionaryActionExecute
      OnUpdate = dbDictionaryActionUpdate
    end
    object DbSplitDatabase: TAction
      Category = 'Database'
      Caption = 'Split Database...'
      OnExecute = DbSplitDatabaseExecute
    end
    object ModeSelectRectAction: TAction
      Category = 'Mode'
      Caption = 'Select ROI'
      ImageIndex = 7
      OnExecute = ModeSelectRectActionExecute
      OnUpdate = ModeSelectRectActionUpdate
    end
    object ImageCropAction: TAction
      Category = 'Image'
      Caption = 'Crop'
      ShortCut = 16464
      OnExecute = ImageCropActionExecute
      OnUpdate = ImageCropActionUpdate
    end
    object ImageInvertAction: TAction
      Category = 'Image'
      Caption = '&Invert'
      OnExecute = ImageInvertActionExecute
      OnUpdate = ImageInvertActionUpdate
    end
    object ImageGrayscaleAction: TAction
      Category = 'Image'
      Caption = '&Grayscale'
      ShortCut = 16455
      OnExecute = ImageGrayscaleActionExecute
      OnUpdate = ImageGrayscaleActionUpdate
    end
    object ImageMirrorAction: TAction
      Category = 'Image'
      Caption = '&Mirror '
      ShortCut = 16461
      OnExecute = ImageMirrorActionExecute
      OnUpdate = ImageMirrorActionUpdate
    end
    object ImageFlipAction: TAction
      Category = 'Image'
      Caption = '&Flip Vertical'
      ShortCut = 16454
      OnExecute = ImageFlipActionExecute
      OnUpdate = ImageFlipActionUpdate
    end
    object ImageFlipLeftAction: TAction
      Category = 'Image'
      Caption = 'Flip &Left '
      ShortCut = 16460
      OnUpdate = ImageFlipLeftActionUpdate
    end
    object ImageFlipRightAction: TAction
      Category = 'Image'
      Caption = 'Flip &Right'
      ShortCut = 16466
      OnExecute = ImageFlipRightActionExecute
      OnUpdate = ImageFlipRightActionUpdate
    end
    object ImageRotateAction: TAction
      Category = 'Image'
      Caption = 'R&otate...'
      ShortCut = 16463
      OnExecute = ImageRotateActionExecute
      OnUpdate = ImageRotateActionUpdate
    end
    object ImageSobelAction: TAction
      Category = 'Image'
      Caption = '&Sobel Filter'
      ShortCut = 16467
      OnExecute = ImageSobelActionExecute
      OnUpdate = ImageSobelActionUpdate
    end
    object ImageFilterAction: TAction
      Category = 'Image'
      Caption = 'Lienar Filters...'
      ShortCut = 16469
      OnExecute = ImageFilterActionExecute
      OnUpdate = ImageFilterActionUpdate
    end
    object ImageGaussFilterAction: TAction
      Category = 'Image'
      Caption = 'Gauss Fil&ter...'
      ShortCut = 16468
      OnExecute = ImageGaussFilterActionExecute
      OnUpdate = ImageGaussFilterActionUpdate
    end
    object ImageMedianFilterAction: TAction
      Category = 'Image'
      Caption = 'Media&n Filter...'
      ShortCut = 16462
      OnExecute = ImageMedianFilterActionExecute
      OnUpdate = ImageMedianFilterActionUpdate
    end
    object ImageResizeAction: TAction
      Category = 'Image'
      Caption = 'Resize...'
      ShortCut = 16474
      OnExecute = ImageResizeActionExecute
      OnUpdate = ImageResizeActionUpdate
    end
  end
  object ImageList1: TImageList
    Left = 408
    Top = 56
    Bitmap = {
      494C010110001300F80110001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000005000000001002000000000000050
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000C0C0C000808080000000000000000000C0C0C00080808000C0C0C0008080
      8000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000808080000000000000000000000000000000000000000000808080008080
      8000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000C0C0C00000000000808080008080
      8000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000800000008000000080000000800000008000
      0000800000008000000080000000800000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008080
      80000000000000000000C0C0C00000000000C0C0C00000000000808080008080
      8000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000808080000000000080808000000000000000000000000000000000000000
      000000000000000000000000000080000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00800000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008080
      800000000000000000000000000000000000C0C0C00000000000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      000080808000808080008080800080808000808080008080800080808000C0C0
      C000000000000000000080808000808080000000000000000000000000000000
      000000000000000000000000000080000000FFFFFF0000000000000000000000
      00000000000000000000FFFFFF00800000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008080800000000000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00008080800000000000C0C0C000000000000000000000000000000000000000
      000000000000000000000000000080000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00800000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0C0
      C000000000008080800000000000000000008080800000000000000000008080
      8000808080000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000808080000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0080000000FFFFFF0000000000000000000000
      00000000000000000000FFFFFF00800000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C0C0
      C000000000000000000080808000C0C0C0008080800000000000000000008080
      8000808080000000000000000000000000008080800000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000C0C0C0000000000000000000FFFFFF000000
      000000000000000000000000000080000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00800000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00008080800000000000C0C0C00000000000C0C0C00000000000000000008080
      800080808000000000000000000000000000C0C0C00000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000080808000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0080000000FFFFFF000000000000000000FFFF
      FF00800000008000000080000000800000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008080800000000000000000008080
      800000000000000000000000000000000000C0C0C00000000000000000000000
      0000000000000000000080000000808080008080800080808000C0C0C000C0C0
      C00000000000C0C0C00000000000000000000000000000000000FFFFFF000000
      000000000000000000000000000080000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0080000000FFFFFF0080000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000080808000000000008080
      8000000000000000000000000000000000000000000000000000000000008080
      8000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF0080000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00800000008000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000808080000000000000000000000000000000
      00000000000000000000000000000000000000000000C0C0C000808080000000
      0000000000000000000000000000000000000000000080808000808080000000
      0000000000000000000000000000000000000000000000000000FFFFFF000000
      000000000000FFFFFF0000000000800000008000000080000000800000008000
      0000800000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000C0C0C0000000000000000000000000000000
      0000C0C0C0000000000000000000000000000000000000000000C0C0C0000000
      0000808080008080800080808000808080008080800000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF0000000000FFFFFF000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000808080000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF00FFFF
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
      000000000000000000000000000000000000000000000000000000000000C6C6
      C600C6C6C6000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
      7F007F7F7F007F7F7F007F7F7F007F7F7F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C6C6
      C600C6C6C60000000000000000000000000000000000FFFFFF00848484000000
      000000000000C6C6C60000000000000000000000000000000000000000000000
      0000000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF000000000000000000FFFFFF00FFFFFF000000
      0000FFFFFF00FFFFFF007F7F7F00FFFFFF00FFFFFF000000000000000000FFFF
      FF0000000000FFFFFF00FFFFFF007F7F7F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C6C6
      C600C6C6C600000000000000000000000000FFFFFF008484840084848400C6C6
      C600848484000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000FFFFFF00FFFFFF0000000000FFFF
      FF000000000000000000FFFFFF00000000007F7F7F007F7F7F00FFFFFF007F7F
      7F007F7F7F007F7F7F007F7F7F007F7F7F0000000000FFFFFF007F7F7F000000
      00007F7F7F007F7F7F00000000007F7F7F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF008484
      840084848400C6C6C600FFFFFF00FFFFFF008484840084848400C6C6C600C6C6
      C600C6C6C600C6C6C6000000000000000000FFFF0000000000000000000000FF
      FF00FFFFFF0000FFFF00FFFFFF0000FFFF0000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000007F7F7F007F7F7F007F7F7F000000
      0000000000000000000000000000FFFFFF007F7F7F00FFFFFF00000000000000
      00000000000000000000FFFFFF007F7F7F000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C6C6C600848484008484
      8400840000008400000084848400848484000000000000000000C6C6C600C6C6
      C600C6C6C600000000000000000000000000FFFF00000000000000FFFF00FFFF
      FF0000FFFF00FFFFFF00000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF0000000000FFFFFF00000000007F7F7F007F7F7F00FFFFFF000000
      000000000000000000007F7F7F007F7F7F007F7F7F0000000000FFFFFF000000
      0000FFFFFF007F7F7F00000000007F7F7F0000000000000000000000000000FF
      FF00C0C0C00000FFFF00C0C0C00000FFFF00C0C0C00000FFFF00000000000000
      000000000000000000000000000000000000C6C6C60084848400FF000000C6C6
      C600C6C6C600C6C6C600FFFFFF00FFFFFF00000000000000000000000000C6C6
      C60000000000000000000000000000000000FFFF000000000000FFFFFF0000FF
      FF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000000000FFFFFF000000
      000000000000FFFFFF00FFFFFF00000000007F7F7F007F7F7F00FFFFFF000000
      0000000000000000000000000000FFFFFF00FFFFFF007F7F7F00FFFFFF007F7F
      7F007F7F7F00FFFFFF00000000007F7F7F00000000000000000000FFFF000000
      000000FFFF00C0C0C00000FFFF00C0C0C00000FFFF00C0C0C00000FFFF000000
      0000000000000000000000000000000000008484840084848400C6C6C600C6C6
      C600C6C6C600C6C6C600FFFFFF00FFFFFF00FFFFFF0000000000848484000000
      000000000000000000000000000000000000FFFF00000000000000FFFF00FFFF
      FF0000FFFF00FFFFFF00000000000000000000000000000000000000000000FF
      FF0000000000FFFFFF00FFFFFF00000000007F7F7F007F7F7F00FFFFFF000000
      000000000000000000007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F000000
      00007F7F7F0000000000000000007F7F7F00000000000000000000FFFF0000FF
      FF000000000000FFFF00C0C0C00000FFFF00C0C0C00000FFFF00C0C0C00000FF
      FF000000000000000000000000000000000000008400C6C6C600C6C6C600C6C6
      C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600848484000000
      000000000000000000000000000000000000FFFF000000000000FFFFFF0000FF
      FF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF000000
      0000FFFFFF00FFFFFF00FFFFFF00000000007F7F7F007F7F7F00FFFFFF000000
      000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF007F7F
      7F000000000000000000000000007F7F7F000000000000000000FFFFFF0000FF
      FF0000FFFF000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000840084008400C6C6C600C6C6
      C600C6C6C600840084000000FF000000FF000000FF000000FF00000084000000
      FF000000FF000000FF000000FF000000FF00FFFF00000000000000FFFF00FFFF
      FF0000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000007F7F7F007F7F7F00FFFFFF00FFFF
      FF007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F000000
      000000000000FFFFFF00FFFFFF007F7F7F00000000000000000000FFFF00FFFF
      FF0000FFFF000000000000FFFF000000000000FFFF000000000000FFFF000000
      00000000000000000000000000000000000000008400C6C6C600C6C6C600C6C6
      C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600848484000000
      00000000000000000000000000000000000000000000000000000000000000FF
      FF00FFFFFF0000FFFF00000000000000000000FFFF0000000000FFFFFF00FFFF
      FF000000000000000000FFFFFF00000000007F7F7F007F7F7F007F7F7F000000
      0000FFFFFF00FFFFFF007F7F7F007F7F7F00000000007F7F7F00000000000000
      00007F7F7F007F7F7F00000000007F7F7F000000000000000000FFFFFF0000FF
      FF00FFFFFF0000FFFF00FFFFFF0000FFFF00FFFFFF0000FFFF00000000000000
      00000000000000000000000000000000000084848400C6C6C600C6C6C600C6C6
      C600C6C6C600C6C6C600FFFFFF00FFFFFF00C6C6C600C6C6C600C6C6C6000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000FFFF0000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00000000000000000000000000000000007F7F
      7F007F7F7F007F7F7F007F7F7F00000000007F7F7F0000000000000000000000
      000000000000FFFFFF00FFFFFF007F7F7F00000000000000000000FFFF00FFFF
      FF0000FFFF00FFFFFF0000FFFF00FFFFFF000000000000000000000000000000
      000000000000000000000000000000000000C6C6C60084848400C6C6C600C6C6
      C600C6C6C600C6C6C600C6C6C600C6C6C600FFFFFF0084848400000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000FFFF0000000000FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000007F7F7F00000000007F7F7F000000000000000000FFFFFF00FFFF
      FF007F7F7F007F7F7F007F7F7F007F7F7F0000000000000000000000000000FF
      FF00FFFFFF0000FFFF00FFFFFF00000000000000000000000000000000000000
      00000000000000000000000000000000000000000000C6C6C600FF000000C6C6
      C600C6C6C600C6C6C600FFFFFF00FFFFFF0084848400FFFFFF00000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000FFFF0000000000FFFFFF00FFFFFF000000000000000000FFFF
      FF0000000000FFFFFF00FFFFFF00000000000000000000000000000000000000
      00007F7F7F00000000007F7F7F00FFFFFF00000000007F7F7F007F7F7F000000
      00007F7F7F00FFFFFF00000000007F7F7F000000000000000000808080000000
      0000000000000000000000000000808080000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000C6C6C6008400
      000084000000840000008484840084848400FFFFFF0000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000FFFF000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000FFFFFF0000000000000000000000000000000000000000007F7F
      7F00FFFFFF007F7F7F007F7F7F00FFFFFF000000000000000000000000000000
      00007F7F7F00FFFFFF007F7F7F00000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C6C6
      C600C6C6C600FFFFFF0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      FF00000000000000000000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF000000000000000000000000000000000000000000000000007F7F7F007F7F
      7F007F7F7F00000000007F7F7F00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF007F7F7F007F7F7F0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C6C6
      C600C6C6C6000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000007F7F
      7F0000000000000000007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
      7F007F7F7F000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000FFFF0000FFFF0000FFFF00000000008484840000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000008484840084848400848484008484840084848400848484008484
      8400848484000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000FFFF000000000000000000000000008484840000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000084848400848484008484840084848400848484008484
      8400000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000F8F8F80000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000100
      0100000000000100010001000100000000000000000000000000000000000000
      000000FFFF0000FFFF0000FFFF00000000008484840000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000084848400848484008484840084848400848484008484
      8400000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000F8F8F800F8F8F800F8F8F800000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000100010001000100000000000000000000000000000000000000
      000000FFFF0000FFFF0000000000000000008484840000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000084848400848484008484840084848400848484008484
      8400000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000F8F8
      F800F8F8F800F8F8F80000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000FFFF0000FFFF0000FFFF00000000008484840000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000008484840084848400848484008484840084848400848484008484
      8400848484000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000F8F8
      F800F8F8F8000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000001000100000000000000000000000000000000000000
      000000FFFF000000000000000000000000008484840000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000848484008484840084848400848484008484840084848400848484008484
      8400848484000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008484840084848400848484000000
      000000FFFF0000FFFF0000FFFF00000000008484840084848400848484008484
      8400848484008484840084848400848484000000000000000000000000008484
      8400848484008484840084848400848484008484840084848400848484008484
      8400848484008484840000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000848484008484
      8400848484008484840084848400848484008484840084848400848484008484
      8400848484008484840000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FF
      FF0000FFFF0000FFFF0000FFFF0000FFFF000000000084848400848484008484
      8400000000008484840084848400848484008484840084848400848484008484
      8400848484008484840000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000FFFF000000000000FF
      FF0000FFFF0000FFFF000000000000FFFF0000FFFF0000FFFF000000000000FF
      FF0000FFFF0000FFFF000000000000FFFF000000000084848400848484000000
      0000000000008484840084848400848484008484840084848400848484008484
      8400848484008484840084848400000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000FFFF000000000000FF
      FF000000000000FFFF000000000000FFFF000000000000FFFF000000000000FF
      FF000000000000FFFF000000000000FFFF000000000000000000000000000000
      0000000000008484840084848400848484008484840084848400848484008484
      8400000000008484840084848400000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000848484008484840000000000848484008484840000000000848484008484
      8400000000008484840084848400000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000FFFF0000FFFF0000FFFF00000000008484840000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000848484008484840000000000848484008484840000000000848484008484
      8400000000000000000084848400000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000FFFF000000000000000000000000008484840000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008484
      8400848484000000000000000000848484008484840000000000848484008484
      8400000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000FFFF0000FFFF0000FFFF00000000008484840000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008484
      8400848484000000000000000000848484008484840000000000848484008484
      8400000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000008484840000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000848484008484840000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000008484000084000000C6C6C6000000000000000000000000000000
      0000000000007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F7F007F7F
      7F00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000084848400848484000000
      0000848484008484840000000000848484008484840000000000848484008484
      8400000000008484840084848400000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000084840000C6C6C600FF000000848484000000000000000000000000000000
      0000000000007F7F7F00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBF
      BF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008400
      8400840084008400840000000000848484000000000084008400840084008400
      8400000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000008484
      0000C6C6C600FF00000084000000000000000000000000000000000000000000
      0000000000007F7F7F00BFBFBF000000000000000000BFBFBF00BFBFBF00BFBF
      BF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000084848400000000000000
      0000000000008400840084008400848484008400840084008400000000000000
      0000000000000000000084848400000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000084840000C6C6
      C600FF0000008400000000000000000000000000000000000000000000000000
      0000000000007F7F7F00BFBFBF000000000000000000BFBFBF00BFBFBF00BFBF
      BF0000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000084848400000000000000
      0000000000008484840084848400848484008484840084848400000000000000
      0000000000000000000084848400000000000000000000000000000000000000
      0000000000000000000000000000000000000000000084848400C6C6C600FF00
      0000840000000000000000000000000000000000000000000000000000000000
      0000000000007F7F7F00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBFBF00BFBF
      BF00000000000000000000000000000000000000000000000000FFFFFF000000
      000000000000FFFFFF00000000000000000000000000FFFFFF00000000000000
      0000FFFFFF000000000000000000000000000000000084848400000000000000
      00000000000084848400C6C6C600C6C6C600C6C6C60084848400000000000000
      000000000000000000000000000000000000000000000000000000000000C6C6
      C600848484000000000000000000848484008484840000000000848484008400
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF000000
      000000000000FFFFFF00000000000000000000000000FFFFFF00000000000000
      0000FFFFFF000000000000000000000000000000000000000000000000000000
      000084848400C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600848484000000
      0000000000000000000084848400000000000000000000000000C6C6C600C6C6
      C600848484008484000084840000848400000000000000000000848484000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FFFFFF000000
      000000000000FFFFFF00000000000000000000000000FFFFFF00000000000000
      0000FFFFFF00000000000000000000000000000000008484840000000000C6C6
      C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6
      C6000000000000000000848484000000000000000000C6C6C600C6C6C6008484
      0000FFFF0000C6C6C600C6C6C600C6C6C600C6C6C60084840000848484000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00FFFFFF00FFFFFF00000000000000000000000000FFFFFF00FFFFFF00FFFF
      FF00FFFFFF000000000000000000000000000000000084848400000000000000
      0000C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C6000000
      000000000000000000000000000000000000000000000000000084840000FFFF
      0000C6C6C60000000000C6C6C600C6C6C600C6C6C600FFFF0000848484000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF0000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF000000000000000000000000000000000000000000FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000C6C6C6008484840084848400C6C6C6008484840084848400C6C6C6000000
      000000000000000000008484840000000000C6C6C600C6C6C60084840000C6C6
      C6000000000000000000C6C6C600C6C6C600C6C6C600FFFF0000848484000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000084848400000000000000
      0000C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600C6C6C6000000
      000000000000000000008484840000000000C6C6C60084848400FFFF00000000
      000000000000C6C6C600C6C6C600C6C6C600C6C6C600FFFF0000848484000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000084848400000000000000
      000000000000C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600000000000000
      000000000000000000000000000000000000C6C6C60084848400FFFF00000000
      000000000000C6C6C600C6C6C600C6C6C600C6C6C600C6C6C600848484000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000C6C6
      C60000000000000000000000000000000000000000000000000000000000C6C6
      C600000000000000000084848400000000000000000000000000FFFF0000C6C6
      C60000000000C6C6C600C6C6C600C6C6C600C6C6C60000000000848484000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000007F7F7F0000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000084848400000000000000
      0000848484000000000000000000000000000000000000000000848484000000
      000000000000000000008484840000000000000000000000000000000000FFFF
      0000C6C6C600C6C6C600FFFF000084848400C6C6C60084848400000000000000
      000000000000000000000000000000000000000000000000000000000000FFFF
      FF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000848484008484
      8400000000008484840084848400000000008484840084848400000000008484
      8400848484000000000084848400000000000000000000000000C6C6C6000000
      0000848400008484000084848400848484008484840000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF000000
      FF00000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000848484008484840084848400C6C6C6000000000000000000000000000000
      000000000000000000000000000000000000424D3E000000000000003E000000
      2800000040000000500000000100010000000000800200000000000000000000
      000000000000000000000000FFFFFF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000000000000000FFFFF30FFFFFFFFFEFFDF38FFFFFFFFF
      C7FFF30FFFFFFE00C3FBE10F9FF1FE00E3F7E30F6004FE00F1E7E30F60048000
      F8CFE10700008000FC1FE40700008000FE3FF40700018000FC1FFE0700038001
      F8CFFE078FEF8003E1E7FE078F9F8007C3F3FE07C07F807FC7FDFF9FFFFF80FF
      FFFFFF9FFFFF81FFFFFFFF9FFFFFFFFFE7CFFC00FC00FFFFE783FC009068FFFF
      E70320000092FFFFC00300001E3CC03F800700001C52801F000F00001E02800F
      001F00001C168007001F0000180E8007000000000018800F001F000010B2800F
      001FE000E178801F003FF800FAC0C0FF803FF000F492C0FFC07FE001E0F1FFFF
      E3FFC403C403FFFFE7FFEC07EC07FFFFE07FF807FFFBFFFFE07FFC0F92519249
      E07FFC0F92419249E07FFC0FFFC1FFFFE07FF8079FC39FF9E07FF0079FC19FF9
      0000E003FFFFFFFF0000C0039FF99FF9000088039FF99FF900009801FFFFFFFF
      0000F8099FF99FF90000F2499FF99FF9E07FF24DFFFFFFFFE07FE64F92499249
      E07FE64F92499249E07FFE7FFFFFFFFFFFFFFFFFFFFFFFF88003FFFF9249FFF0
      0001FFFFC287FFE10001E7CFA00DFFC30001C387B83DFF8700018103B83FE04F
      00018103F01DC01F00018103A00D801F00018103A00FC41F0001C387E00D0C1F
      0001E7CFA00D181F0001BFFBA00F181F0001C387E00D885F0001FFFFB01DC03F
      0001FFFFC925C07F8003FFFFFFFFF0FF00000000000000000000000000000000
      000000000000}
  end
  object ApplicationEvents1: TApplicationEvents
    OnIdle = ApplicationEvents1Idle
    OnHint = ApplicationEvents1Hint
    Left = 472
    Top = 56
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '.xml'
    Filter = 'XML files|*.xml'
    Options = [ofOverwritePrompt, ofHideReadOnly, ofEnableSizing]
    Left = 504
    Top = 56
  end
  object PopupMenu1: TPopupMenu
    Images = ImageList1
    Left = 344
    Top = 56
    object Copy1: TMenuItem
      Action = EditCopy1
    end
    object CopyImage1: TMenuItem
      Action = ImageCopyImageAction
    end
    object N8: TMenuItem
      Caption = '-'
    end
    object DeleteImage1: TMenuItem
      Action = ImageDelImageAction
    end
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 100
    OnTimer = Timer1Timer
    Left = 536
    Top = 56
  end
end
