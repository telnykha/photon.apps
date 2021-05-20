object pam2DistributionForm: Tpam2DistributionForm
  Left = 0
  Top = 0
  BorderStyle = bsSizeToolWin
  Caption = #1056#1072#1089#1087#1088#1077#1076#1077#1083#1077#1085#1080#1077' '#1080#1085#1090#1077#1085#1089#1080#1074#1085#1086#1089#1090#1080
  ClientHeight = 187
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
  object Splitter1: TSplitter
    Left = 185
    Top = 33
    Height = 154
    ExplicitLeft = 224
    ExplicitTop = 104
    ExplicitHeight = 100
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 527
    Height = 33
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    ExplicitLeft = -48
    ExplicitWidth = 575
  end
  object Panel2: TPanel
    Left = 0
    Top = 33
    Width = 185
    Height = 154
    Align = alLeft
    BevelOuter = bvNone
    TabOrder = 1
    ExplicitLeft = 192
    ExplicitTop = 96
    ExplicitHeight = 41
    object CheckListBox1: TCheckListBox
      AlignWithMargins = True
      Left = 3
      Top = 3
      Width = 179
      Height = 148
      Align = alClient
      ItemHeight = 13
      TabOrder = 0
      ExplicitHeight = 121
    end
  end
  object Panel3: TPanel
    Left = 188
    Top = 33
    Width = 339
    Height = 154
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 2
    ExplicitLeft = 140
    ExplicitWidth = 387
    ExplicitHeight = 127
    object Chart1: TChart
      AlignWithMargins = True
      Left = 3
      Top = 3
      Width = 333
      Height = 148
      Legend.Visible = False
      Title.Text.Strings = (
        'TChart')
      View3D = False
      Align = alClient
      BevelOuter = bvNone
      TabOrder = 0
      ExplicitWidth = 381
      ExplicitHeight = 121
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
