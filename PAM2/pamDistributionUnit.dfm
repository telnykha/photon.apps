object pam2ROIForm: Tpam2ROIForm
  Left = 0
  Top = 0
  BorderStyle = bsSizeToolWin
  Caption = #1054#1073#1083#1072#1089#1090#1080' '#1080#1085#1090#1077#1088#1077#1089#1072
  ClientHeight = 354
  ClientWidth = 461
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
    Width = 461
    Height = 33
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    Visible = False
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 335
    Width = 461
    Height = 19
    Panels = <>
  end
  object StringGrid1: TStringGrid
    Left = 0
    Top = 33
    Width = 461
    Height = 302
    Align = alClient
    BevelInner = bvNone
    BevelOuter = bvNone
    ColCount = 7
    Ctl3D = True
    DefaultColWidth = 32
    DefaultRowHeight = 22
    RowCount = 2
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goRowSelect, goFixedRowClick]
    ParentCtl3D = False
    PopupMenu = PopupMenu1
    TabOrder = 2
    OnClick = StringGrid1Click
  end
  object PopupMenu1: TPopupMenu
    Left = 360
    Top = 72
    object N1: TMenuItem
      Action = pamMainForm.imageZoomPaneAction
    end
    object N2: TMenuItem
      Caption = '-'
    end
    object N3: TMenuItem
      Action = pamMainForm.imageAddRectAction
    end
    object N4: TMenuItem
      Action = pamMainForm.imageAddCircleAction
    end
    object N5: TMenuItem
      Action = pamMainForm.imageAddPolygonAction
    end
    object N6: TMenuItem
      Caption = '-'
    end
    object N7: TMenuItem
      Action = roiDeleteAction
    end
    object N8: TMenuItem
      Action = roiClearAction
    end
  end
  object ActionList1: TActionList
    Left = 400
    Top = 72
    object roiDeleteAction: TAction
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1086#1073#1098#1077#1082#1090
      ShortCut = 8238
      OnExecute = roiDeleteActionExecute
      OnUpdate = roiDeleteActionUpdate
    end
    object roiClearAction: TAction
      Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1086#1073#1083#1072#1089#1090#1080' '#1080#1085#1090#1077#1088#1089#1072
      ShortCut = 16430
      OnExecute = roiClearActionExecute
      OnUpdate = roiClearActionUpdate
    end
  end
end
