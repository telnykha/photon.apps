object pam2TimeLineForm: Tpam2TimeLineForm
  Left = 0
  Top = 0
  BorderStyle = bsSizeToolWin
  Caption = #1042#1088#1077#1084#1077#1085#1085#1072#1103' '#1096#1082#1072#1083#1072
  ClientHeight = 242
  ClientWidth = 527
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
    Width = 527
    Height = 28
    Align = alTop
    TabOrder = 0
    object SpeedButton1: TSpeedButton
      AlignWithMargins = True
      Left = 4
      Top = 4
      Width = 23
      Height = 20
      Align = alLeft
      ExplicitLeft = 54
      ExplicitTop = 3
      ExplicitHeight = 22
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 223
    Width = 527
    Height = 19
    Panels = <>
    ExplicitLeft = 232
    ExplicitTop = 184
    ExplicitWidth = 0
  end
  object Chart1: TChart
    Left = 0
    Top = 28
    Width = 527
    Height = 195
    Legend.Visible = False
    MarginBottom = 0
    MarginLeft = 0
    MarginRight = 1
    MarginTop = 2
    View3D = False
    Align = alClient
    TabOrder = 2
    ExplicitLeft = 184
    ExplicitTop = 104
    ExplicitWidth = 400
    ExplicitHeight = 250
    DefaultCanvas = 'TGDIPlusCanvas'
    ColorPaletteIndex = 13
    object Series1: TFastLineSeries
      Selected.Hover.Visible = True
      LinePen.Color = 10708548
      TreatNulls = tnDontPaint
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
    object Series2: TFastLineSeries
      Selected.Hover.Visible = True
      LinePen.Color = 3513587
      TreatNulls = tnDontPaint
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Y'
      YValues.Order = loNone
    end
  end
end
