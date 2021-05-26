object pam2ResultForm: Tpam2ResultForm
  Left = 0
  Top = 0
  BorderStyle = bsSizeToolWin
  Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090#1099
  ClientHeight = 160
  ClientWidth = 575
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
  object Splitter1: TSplitter
    Left = 185
    Top = 33
    Height = 127
    ExplicitLeft = 224
    ExplicitTop = 104
    ExplicitHeight = 100
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 575
    Height = 33
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
  end
  object Panel2: TPanel
    Left = 0
    Top = 33
    Width = 185
    Height = 127
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 1
    Visible = False
    object CheckListBox1: TCheckListBox
      AlignWithMargins = True
      Left = 3
      Top = 3
      Width = 179
      Height = 121
      Align = alClient
      ItemHeight = 13
      TabOrder = 0
      Visible = False
    end
  end
  object Panel3: TPanel
    Left = 188
    Top = 33
    Width = 387
    Height = 127
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 2
    object Chart1: TChart
      AlignWithMargins = True
      Left = 3
      Top = 3
      Width = 381
      Height = 121
      Legend.Visible = False
      Title.Text.Strings = (
        'TChart')
      View3D = False
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 0
      DefaultCanvas = 'TGDIPlusCanvas'
      ColorPaletteIndex = 13
      object Series1: TLineSeries
        Brush.BackColor = clDefault
        Pointer.InflateMargins = True
        Pointer.Style = psRectangle
        XValues.Name = 'X'
        XValues.Order = loAscending
        YValues.Name = 'Y'
        YValues.Order = loNone
      end
    end
  end
end
