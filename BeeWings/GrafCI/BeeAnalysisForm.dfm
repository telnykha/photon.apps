object AnalysisForm: TAnalysisForm
  Left = 0
  Top = 0
  BorderStyle = bsSizeToolWin
  Caption = 'AnalysisForm'
  ClientHeight = 452
  ClientWidth = 517
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Unit1: TPageControl
    Left = 0
    Top = 0
    Width = 517
    Height = 452
    ActivePage = Результаты
    Align = alClient
    MultiLine = True
    TabOrder = 0
    TabPosition = tpBottom
    ExplicitWidth = 854
    ExplicitHeight = 450
    object Индексы: TTabSheet
      Caption = #1048#1085#1076#1077#1082#1089#1099
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 846
        Height = 424
        Align = alClient
        ColCount = 4
        FixedCols = 0
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goRowSelect, goFixedRowDefAlign]
        PopupMenu = PopupMenu1
        TabOrder = 0
      end
    end
    object Результаты: TTabSheet
      Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090#1099
      ImageIndex = 6
      object StringGrid3: TStringGrid
        Left = 0
        Top = 0
        Width = 509
        Height = 426
        Align = alClient
        FixedCols = 0
        RowCount = 4
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goRowSelect, goFixedRowDefAlign]
        TabOrder = 0
        ExplicitWidth = 846
        ExplicitHeight = 424
      end
    end
    object График_CI1: TTabSheet
      Caption = #1043#1088#1072#1092#1080#1082#1080
      ImageIndex = 1
      object Splitter2: TSplitter
        Left = 0
        Top = 265
        Width = 846
        Height = 3
        Cursor = crVSplit
        Align = alTop
        ExplicitWidth = 225
      end
      object Splitter3: TSplitter
        Left = 419
        Top = 268
        Height = 156
        ExplicitLeft = 440
        ExplicitTop = 336
        ExplicitHeight = 100
      end
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 846
        Height = 265
        Align = alTop
        Caption = 'Panel1'
        TabOrder = 0
        object Splitter1: TSplitter
          Left = 421
          Top = 1
          Height = 263
          ExplicitLeft = 432
          ExplicitTop = 144
          ExplicitHeight = 100
        end
        object Panel2: TPanel
          Left = 1
          Top = 1
          Width = 420
          Height = 263
          Align = alLeft
          Caption = 'Panel2'
          TabOrder = 0
          object Chart5: TChart
            Left = 1
            Top = 1
            Width = 418
            Height = 261
            Legend.Visible = False
            Title.Text.Strings = (
              'TChart')
            View3D = False
            View3DOptions.Orthogonal = False
            Align = alClient
            TabOrder = 0
            DefaultCanvas = 'TGDIPlusCanvas'
            ColorPaletteIndex = 13
            object Series16: TPointSeries
              SeriesColor = 44444
              ClickableLine = False
              Pointer.InflateMargins = True
              Pointer.Style = psRectangle
              XValues.Name = 'X'
              XValues.Order = loAscending
              YValues.Name = 'Y'
              YValues.Order = loNone
            end
          end
        end
        object Panel3: TPanel
          Left = 424
          Top = 1
          Width = 421
          Height = 263
          Align = alClient
          Caption = 'Panel3'
          TabOrder = 1
          object Chart6: TChart
            Left = 1
            Top = 1
            Width = 419
            Height = 261
            Legend.Visible = False
            Title.Text.Strings = (
              'TChart')
            View3D = False
            View3DOptions.Orthogonal = False
            Align = alClient
            TabOrder = 0
            DefaultCanvas = 'TGDIPlusCanvas'
            ColorPaletteIndex = 13
            object Series8: TPointSeries
              SeriesColor = clFuchsia
              ClickableLine = False
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
      object Panel4: TPanel
        Left = 0
        Top = 268
        Width = 419
        Height = 156
        Align = alLeft
        Caption = 'Panel4'
        TabOrder = 1
        object Chart4: TChart
          Left = 1
          Top = 1
          Width = 417
          Height = 154
          Legend.Visible = False
          Title.Text.Strings = (
            'TChart')
          View3D = False
          View3DOptions.Orthogonal = False
          Align = alClient
          TabOrder = 0
          DefaultCanvas = 'TGDIPlusCanvas'
          ColorPaletteIndex = 13
          object Series9: TPointSeries
            ClickableLine = False
            Pointer.InflateMargins = True
            Pointer.Style = psRectangle
            XValues.Name = 'X'
            XValues.Order = loAscending
            YValues.Name = 'Y'
            YValues.Order = loNone
          end
        end
      end
      object Panel5: TPanel
        Left = 422
        Top = 268
        Width = 424
        Height = 156
        Align = alClient
        Caption = 'Panel5'
        TabOrder = 2
      end
    end
    object График_CI: TTabSheet
      Caption = #1043#1088#1072#1092#1080#1082'_CI'
      ImageIndex = 2
      object Chart1: TChart
        Left = 0
        Top = 0
        Width = 846
        Height = 424
        Legend.Visible = False
        Title.Text.Strings = (
          #1043#1088#1072#1092#1080#1082' CI')
        LeftAxis.Increment = 1.000000000000000000
        TopAxis.Automatic = False
        TopAxis.AutomaticMaximum = False
        TopAxis.Maximum = 10.000000000000000000
        View3D = False
        Align = alClient
        TabOrder = 0
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
        object Series1: TBarSeries
          Marks.Visible = False
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Bar'
          YValues.Order = loNone
        end
        object Series6: TLineSeries
          SeriesColor = clRed
          Brush.BackColor = clDefault
          DrawStyle = dsAll
          Pointer.InflateMargins = True
          Pointer.Style = psRectangle
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
          object TSmoothingFunction
            CalcByValue = False
            Period = 1.000000000000000000
            Factor = 8
          end
        end
      end
    end
    object График_DsA: TTabSheet
      Caption = #1043#1088#1072#1092#1080#1082'_DsA'
      ImageIndex = 3
      object Chart2: TChart
        Left = 0
        Top = 0
        Width = 846
        Height = 424
        LeftWall.Visible = False
        Title.Text.Strings = (
          #1043#1088#1072#1092#1080#1082' DsA')
        Chart3DPercent = 1
        ClipPoints = False
        LeftAxis.Increment = 1.000000000000000000
        View3D = False
        View3DOptions.Orthogonal = False
        View3DOptions.Perspective = 0
        Align = alClient
        TabOrder = 0
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
        object Series2: TBarSeries
          Legend.Visible = False
          Marks.Visible = False
          ShowInLegend = False
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Bar'
          YValues.Order = loNone
        end
        object Series3: TLineSeries
          Legend.Visible = False
          SeriesColor = clRed
          ShowInLegend = False
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
    object График_HI: TTabSheet
      Caption = #1043#1088#1072#1092#1080#1082'_HI'
      ImageIndex = 4
      object Chart3: TChart
        Left = 0
        Top = 0
        Width = 846
        Height = 424
        Title.Text.Strings = (
          #1043#1088#1072#1092#1080#1082' HI')
        LeftAxis.ExactDateTime = False
        LeftAxis.Increment = 1.000000000000000000
        View3D = False
        View3DOptions.Orthogonal = False
        Align = alClient
        TabOrder = 0
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
        object Series4: TBarSeries
          Legend.Visible = False
          Marks.Visible = False
          ShowInLegend = False
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Bar'
          YValues.Order = loNone
        end
        object Series5: TLineSeries
          Legend.Visible = False
          SeriesColor = clRed
          ShowInLegend = False
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
    object Анализ: TTabSheet
      Caption = #1040#1085#1072#1083#1080#1079
      ImageIndex = 5
      object WebBrowser1: TWebBrowser
        Left = 0
        Top = 0
        Width = 846
        Height = 424
        Align = alClient
        TabOrder = 0
        ExplicitLeft = 280
        ExplicitTop = 160
        ExplicitWidth = 300
        ExplicitHeight = 150
        ControlData = {
          4C00000070570000D22B00000000000000000000000000000000000000000000
          000000004C000000000000000000000001000000E0D057007335CF11AE690800
          2B2E126208000000000000004C0000000114020000000000C000000000000046
          8000000000000000000000000000000000000000000000000000000000000000
          00000000000000000100000000000000000000000000000000000000}
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = 'xml files|*.xml'
    Left = 396
    Top = 68
  end
  object PopupMenu1: TPopupMenu
    Left = 444
    Top = 68
    object PopupMenu11: TMenuItem
      Caption = #1054#1090#1082#1088#1099#1090#1100' '#1092#1072#1081#1083'...'
      OnClick = PopupMenu11Click
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object N2: TMenuItem
      Caption = #1042#1099#1093#1086#1076
      OnClick = N2Click
    end
  end
end
