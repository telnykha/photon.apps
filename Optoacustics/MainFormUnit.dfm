object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'Optoacustic data processor'
  ClientHeight = 550
  ClientWidth = 693
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter2: TSplitter
    Left = 5
    Top = 58
    Height = 473
    ExplicitLeft = 112
    ExplicitTop = 360
    ExplicitHeight = 100
  end
  object Splitter3: TSplitter
    Left = 677
    Top = 58
    Height = 473
    Align = alRight
    ExplicitLeft = 648
    ExplicitTop = 392
    ExplicitHeight = 100
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 531
    Width = 693
    Height = 19
    Panels = <>
  end
  object PhImage1: TPhImage
    Left = 8
    Top = 58
    Width = 669
    Height = 473
    AutoMosaic = True
    ThumbWidht = 256
    ThumbHeight = 256
    SlideShowInterval = 500
    Align = alClient
    ParentColor = False
    OnMouseWheel = PhImage1MouseWheel
    OnPaint = PhImage1Paint
    AfterOpen = PhImage1AfterOpen
    OnProgress = PhImage1Progress
    OnFinish = PhImage1Finish
    OnFrameData = PhImage1FrameData
    ExplicitLeft = 88
    ExplicitTop = 61
  end
  object ToolBar1: TToolBar
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 687
    Height = 52
    ButtonHeight = 48
    ButtonWidth = 64
    Caption = 'ToolBar1'
    Images = ImageList1
    TabOrder = 2
    object ToolButton3: TToolButton
      Left = 0
      Top = 0
      Width = 8
      Caption = 'ToolButton3'
      ImageIndex = 2
      Style = tbsSeparator
    end
    object ToolButton1: TToolButton
      Left = 8
      Top = 0
      Action = viewFirstAction
    end
    object ToolButton2: TToolButton
      Left = 72
      Top = 0
      Action = viewPrevAction
    end
    object ToolButton4: TToolButton
      Left = 136
      Top = 0
      Action = viewNextAction
    end
    object ToolButton5: TToolButton
      Left = 200
      Top = 0
      Action = viewLastAction
    end
    object ToolButton6: TToolButton
      Left = 264
      Top = 0
      Action = viewPlayAction
    end
  end
  object LeftDocPanel: TPanel
    Left = 0
    Top = 58
    Width = 5
    Height = 473
    Align = alLeft
    DockSite = True
    TabOrder = 3
    OnDockDrop = LeftDocPanelDockDrop
    OnDockOver = LeftDocPanelDockOver
    OnUnDock = LeftDocPanelUnDock
  end
  object RightDocPanel: TPanel
    Left = 680
    Top = 58
    Width = 13
    Height = 473
    Align = alRight
    DockSite = True
    TabOrder = 4
    OnDockDrop = RightDocPanelDockDrop
    OnDockOver = RightDocPanelDockOver
    OnUnDock = RightDocPanelUnDock
  end
  object MainMenu1: TMainMenu
    Left = 512
    Top = 144
    object File1: TMenuItem
      Caption = 'File'
      object OpenImage1: TMenuItem
        Action = fileOpenAction
      end
      object CloseImage1: TMenuItem
        Action = fileCloseImageAction
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Exit1: TMenuItem
        Action = fileCloseAction
      end
    end
    object Edit1: TMenuItem
      Caption = 'Edit'
      object CopyToClipboard1: TMenuItem
        Caption = 'Copy To Clipboard '
      end
    end
    object View1: TMenuItem
      Caption = 'View'
      object ResultWindow1: TMenuItem
        Action = viewResultAction
      end
      object BinaryWindow1: TMenuItem
        Action = viewBinaryAction
      end
      object N3Dwindow1: TMenuItem
        Action = view3DReconstructionAction
      end
      object ClustersTable1: TMenuItem
        Action = viewClustersTableAction
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object Firstimage1: TMenuItem
        Action = viewFirstAction
      end
      object Previousimage1: TMenuItem
        Action = viewPrevAction
      end
      object Nextimage1: TMenuItem
        Action = viewNextAction
      end
      object Lastimage1: TMenuItem
        Action = viewLastAction
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object Play1: TMenuItem
        Action = viewPlayAction
      end
      object viewMosaicAction1: TMenuItem
        Action = viewMosaicAction
      end
    end
    object Run1: TMenuItem
      Caption = 'Run'
      object MakeClusters1: TMenuItem
        Action = MakeClustersAction
      end
    end
    object Help1: TMenuItem
      Caption = 'Help'
    end
  end
  object ActionList1: TActionList
    Left = 544
    Top = 144
    object fileCloseAction: TAction
      Category = 'File'
      Caption = 'Exit'
      OnExecute = fileCloseActionExecute
    end
    object fileCloseImageAction: TAction
      Category = 'File'
      Caption = 'Close Image'
      OnExecute = fileCloseImageActionExecute
      OnUpdate = fileCloseImageActionUpdate
    end
    object fileOpenAction: TAction
      Category = 'File'
      Caption = 'Open Image...'
      OnExecute = fileOpenActionExecute
    end
    object view3DReconstructionAction: TAction
      Category = 'View'
      Caption = '3D window'
      OnExecute = view3DReconstructionActionExecute
      OnUpdate = view3DReconstructionActionUpdate
    end
    object viewResultAction: TAction
      Category = 'View'
      Caption = 'Result Window'
      OnExecute = viewResultActionExecute
      OnUpdate = viewResultActionUpdate
    end
    object viewBinaryAction: TAction
      Category = 'View'
      Caption = 'Binary Window'
      OnExecute = viewBinaryActionExecute
      OnUpdate = viewBinaryActionUpdate
    end
    object viewClustersTableAction: TAction
      Category = 'View'
      Caption = 'Clusters Table'
      OnExecute = viewClustersTableActionExecute
      OnUpdate = viewClustersTableActionUpdate
    end
    object viewFirstAction: TAction
      Category = 'View'
      Caption = 'First image'
      ImageIndex = 0
      OnExecute = viewFirstActionExecute
      OnUpdate = viewFirstActionUpdate
    end
    object viewPrevAction: TAction
      Category = 'View'
      Caption = 'Previous image'
      ImageIndex = 1
      OnExecute = viewPrevActionExecute
      OnUpdate = viewPrevActionUpdate
    end
    object viewNextAction: TAction
      Category = 'View'
      Caption = 'Next image'
      ImageIndex = 2
      OnExecute = viewNextActionExecute
      OnUpdate = viewNextActionUpdate
    end
    object viewLastAction: TAction
      Category = 'View'
      Caption = 'Last image'
      ImageIndex = 3
      OnExecute = viewLastActionExecute
      OnUpdate = viewLastActionUpdate
    end
    object viewPlayAction: TAction
      Category = 'View'
      Caption = 'Play'
      ImageIndex = 4
      OnExecute = viewPlayActionExecute
      OnUpdate = viewPlayActionUpdate
    end
    object MakeClustersAction: TAction
      Category = 'Run'
      Caption = 'Make Clusters...'
      OnExecute = MakeClustersActionExecute
      OnUpdate = MakeClustersActionUpdate
    end
    object viewMosaicAction: TAction
      Category = 'View'
      Caption = 'viewMosaicAction'
      OnExecute = viewMosaicActionExecute
      OnUpdate = viewMosaicActionUpdate
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = 'TIFF files|*tiff;*tif'
    Left = 40
    Top = 96
  end
  object PhPaneTool1: TPhPaneTool
    PhImage = PhImage1
    Left = 504
    Top = 200
  end
  object ImageList1: TImageList
    Left = 56
    Top = 176
    Bitmap = {
      494C010105000800040010001000FFFFFFFFFF10FFFFFFFFFFFFFFFF424D3600
      0000000000003600000028000000400000002000000001002000000000000020
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF0000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF00000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF000000FF00000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF000000FF000000FF000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF000000FF000000FF000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF000000FF00000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF0000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF00000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
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
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FF000000FF000000000000000000000000000000FF00
      0000FF0000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      0000FF000000FF000000000000000000000000000000FF000000FF0000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FF000000FF000000FF0000000000000000000000FF000000FF00
      0000FF0000000000000000000000000000000000000000000000FF000000FF00
      0000000000000000000000000000FF000000FF00000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      0000FF000000FF0000000000000000000000FF000000FF000000FF0000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF00000000000000FF000000FF000000FF00
      0000FF0000000000000000000000000000000000000000000000FF000000FF00
      0000FF0000000000000000000000FF000000FF000000FF000000000000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      0000FF000000000000000000000000000000FF000000FF000000FF0000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      0000FF000000FF00000000000000FF000000FF000000FF000000FF0000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000FF0000000000000000000000000000000000000000000000FF000000FF00
      0000FF000000FF00000000000000FF000000FF000000FF000000FF0000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      0000FF000000FF0000000000000000000000FF000000FF000000FF0000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF0000000000
      0000000000000000000000000000000000000000000000000000FF000000FF00
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000FF0000000000000000000000000000000000000000000000FF000000FF00
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      000000000000000000000000000000000000000000000000000000000000FF00
      0000FF000000FF000000FF00000000000000FF000000FF000000FF0000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF0000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000FF0000000000000000000000000000000000000000000000FF000000FF00
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      0000FF000000000000000000000000000000000000000000000000000000FF00
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF0000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      0000FF000000FF00000000000000FF000000FF000000FF000000FF0000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000FF000000FF000000FF000000FF00000000000000FF000000FF000000FF00
      0000FF0000000000000000000000000000000000000000000000FF000000FF00
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF000000FF00
      000000000000000000000000000000000000000000000000000000000000FF00
      0000FF000000FF000000FF000000FF000000FF000000FF000000FF0000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      0000FF000000FF0000000000000000000000FF000000FF000000FF0000000000
      0000000000000000000000000000000000000000000000000000000000000000
      000000000000FF000000FF000000FF0000000000000000000000FF000000FF00
      0000FF0000000000000000000000000000000000000000000000FF000000FF00
      0000FF000000FF00000000000000FF000000FF000000FF000000FF0000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      0000FF000000FF000000FF00000000000000FF000000FF000000FF0000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      0000FF000000FF000000000000000000000000000000FF000000FF0000000000
      0000000000000000000000000000000000000000000000000000000000000000
      00000000000000000000FF000000FF000000000000000000000000000000FF00
      0000FF0000000000000000000000000000000000000000000000FF000000FF00
      0000FF0000000000000000000000FF000000FF000000FF000000000000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      0000FF000000FF0000000000000000000000FF000000FF000000FF0000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000FF000000FF00
      0000000000000000000000000000FF000000FF00000000000000000000000000
      000000000000000000000000000000000000000000000000000000000000FF00
      0000FF000000000000000000000000000000FF000000FF000000FF0000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
      0000000000000000000000000000000000000000000000000000000000000000
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
      2800000040000000200000000100010000000000000100000000000000000000
      000000000000000000000000FFFFFF00FFFF000000000000FFFF000000000000
      FFFF000000000000F7FF000000000000F3FF000000000000F1FF000000000000
      F0FF000000000000F07F000000000000F03F000000000000F03F000000000000
      F07F000000000000F0FF000000000000F1FF000000000000F3FF000000000000
      F7FF000000000000FFFF000000000000FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFCE7FFFFFFFFE39FF8C7CE7FFFFFE31FF087C63FE71F
      E21FE007C21FE31FE01FC007C00FE11FE01FE007C007E01FE21FF087C00FE01F
      E31FF8C7C21FE11FE39FFCE7C63FE31FFFFFFFFFCE7FE71FFFFFFFFFFFFFFFFF
      FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000000000000000000000000000
      000000000000}
  end
end
