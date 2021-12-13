object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 444
  ClientWidth = 737
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Unit1: TPageControl
    Left = 0
    Top = 0
    Width = 737
    Height = 444
    ActivePage = Индексы
    Align = alClient
    MultiLine = True
    TabOrder = 0
    TabPosition = tpBottom
    ExplicitWidth = 759
    ExplicitHeight = 362
    object Индексы: TTabSheet
      Caption = #1048#1085#1076#1077#1082#1089#1099
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 729
        Height = 418
        Align = alClient
        TabOrder = 0
        ExplicitWidth = 751
        ExplicitHeight = 336
      end
    end
    object Результаты: TTabSheet
      Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090#1099
      ImageIndex = 6
      object StringGrid3: TStringGrid
        Left = 0
        Top = 0
        Width = 751
        Height = 336
        Align = alClient
        TabOrder = 0
      end
    end
    object График_CI1: TTabSheet
      Caption = #1043#1088#1072#1092#1080#1082#1080
      ImageIndex = 1
    end
    object График_CI: TTabSheet
      Caption = #1043#1088#1072#1092#1080#1082'_CI'
      ImageIndex = 2
      object Chart1: TChart
        Left = 0
        Top = 0
        Width = 751
        Height = 336
        Title.Text.Strings = (
          #1043#1088#1072#1092#1080#1082' CI')
        Align = alClient
        TabOrder = 0
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
        object Series1: TBarSeries
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Bar'
          YValues.Order = loNone
        end
      end
    end
    object График_DsA: TTabSheet
      Caption = #1043#1088#1072#1092#1080#1082'_DsA'
      ImageIndex = 3
      object Chart2: TChart
        Left = 0
        Top = 0
        Width = 751
        Height = 336
        Title.Text.Strings = (
          #1043#1088#1072#1092#1080#1082' DsA')
        Align = alClient
        TabOrder = 0
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
        object Series2: TBarSeries
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Bar'
          YValues.Order = loNone
        end
        object Series3: TLineSeries
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
        Width = 751
        Height = 336
        Title.Text.Strings = (
          #1043#1088#1072#1092#1080#1082' HI')
        Align = alClient
        TabOrder = 0
        DefaultCanvas = 'TGDIPlusCanvas'
        ColorPaletteIndex = 13
        object Series4: TBarSeries
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Bar'
          YValues.Order = loNone
        end
        object Series5: TLineSeries
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
      object StringGrid2: TStringGrid
        Left = 0
        Top = 0
        Width = 751
        Height = 336
        Align = alClient
        TabOrder = 0
      end
    end
  end
end
