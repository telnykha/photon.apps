object DetectorForm: TDetectorForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Detector info'
  ClientHeight = 529
  ClientWidth = 355
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Chart1: TChart
    Left = 0
    Top = 89
    Width = 355
    Height = 194
    AllowPanning = pmNone
    Legend.GlobalTransparency = 16
    Legend.Symbol.Gradient.EndColor = 10708548
    Legend.TextStyle = ltsValue
    Title.Text.Strings = (
      'TChart')
    Panning.MouseWheel = pmwNone
    View3D = False
    Zoom.Allow = False
    Align = alTop
    TabOrder = 0
    ExplicitTop = 73
    DefaultCanvas = 'TGDIPlusCanvas'
    PrintMargins = (
      15
      22
      15
      22)
    ColorPaletteIndex = 13
    object Series1: TBarSeries
      Legend.Text = 'qq'
      Legend.Visible = False
      LegendTitle = 'qq'
      BarBrush.Gradient.EndColor = 10708548
      Marks.ChildLayout = slLeftRight
      Marks.Frame.Visible = False
      Marks.Margins.Left = 0
      Marks.Margins.Top = 0
      Marks.Margins.Right = 0
      Marks.Margins.Bottom = 0
      Marks.Style = smsValue
      Marks.Arrow.Visible = False
      Marks.Callout.Arrow.Visible = False
      Marks.Symbol.Frame.EndStyle = esSquare
      Marks.Symbol.Pen.EndStyle = esSquare
      Marks.UseSeriesTransparency = False
      ShowInLegend = False
      Transparency = 15
      Gradient.EndColor = 10708548
      MarksLocation = mlCenter
      XValues.Name = 'X'
      XValues.Order = loAscending
      YValues.Name = 'Bar'
      YValues.Order = loNone
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 355
    Height = 89
    Align = alTop
    TabOrder = 1
    ExplicitTop = -6
    object Label1: TLabel
      Left = 16
      Top = 64
      Width = 25
      Height = 13
      Caption = 'View '
    end
    object Label3: TLabel
      Left = 16
      Top = 8
      Width = 27
      Height = 13
      Caption = 'Name'
    end
    object Label4: TLabel
      Left = 16
      Top = 27
      Width = 56
      Height = 13
      Caption = 'Num stages'
    end
    object Label5: TLabel
      Left = 93
      Top = 8
      Width = 76
      Height = 13
      Caption = '-------------------'
    end
    object Label6: TLabel
      Left = 93
      Top = 27
      Width = 76
      Height = 13
      Caption = '-------------------'
    end
    object Label7: TLabel
      Left = 93
      Top = 45
      Width = 76
      Height = 13
      Caption = '-------------------'
    end
    object Label8: TLabel
      Left = 16
      Top = 45
      Width = 61
      Height = 13
      Caption = 'Num sensors'
    end
    object ComboBox1: TComboBox
      Left = 80
      Top = 62
      Width = 249
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 0
      Text = 'Num sensors in the stage'
      OnChange = ComboBox1Change
      Items.Strings = (
        'Num sensors in the stage'
        'Stages threshold'
        'Srages weight ')
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 283
    Width = 355
    Height = 86
    Align = alTop
    TabOrder = 2
    ExplicitTop = 267
    object Label2: TLabel
      Left = 16
      Top = 53
      Width = 28
      Height = 13
      Caption = 'Stage'
    end
    object ComboBox2: TComboBox
      Left = 50
      Top = 51
      Width = 279
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 0
      Text = 'All'
      OnChange = ComboBox2Change
      Items.Strings = (
        'All')
    end
    object CheckBox1: TCheckBox
      Left = 16
      Top = 30
      Width = 153
      Height = 17
      Caption = 'Use weight of engine sensors '
      TabOrder = 1
      OnClick = CheckBox1Click
    end
    object CheckBox2: TCheckBox
      Left = 16
      Top = 8
      Width = 97
      Height = 17
      Caption = 'Fill sensors area'
      TabOrder = 2
      OnClick = CheckBox2Click
    end
  end
  object FImage1: TFImage
    Left = 0
    Top = 369
    Width = 355
    Height = 160
    Cursor = 1
    BorderStyle = bsFSingle
    Align = alClient
    ParentColor = False
    ExplicitTop = 353
    ExplicitHeight = 176
  end
end
