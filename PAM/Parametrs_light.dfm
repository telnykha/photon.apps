object FormLight: TFormLight
  Left = 0
  Top = 0
  Caption = 'FormLight'
  ClientHeight = 456
  ClientWidth = 564
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 0
    Top = 256
    Width = 564
    Height = 3
    Cursor = crVSplit
    Align = alTop
    ExplicitLeft = -8
    ExplicitTop = 142
    ExplicitWidth = 336
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 564
    Height = 97
    Align = alTop
    TabOrder = 0
    ExplicitWidth = 474
    object Label3: TLabel
      Left = 1
      Top = 1
      Width = 562
      Height = 16
      Align = alTop
      Caption = #1057#1074#1077#1090#1086#1076#1080#1086#1076#1099
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      ExplicitWidth = 83
    end
    object Splitter5: TSplitter
      Left = 129
      Top = 17
      Height = 79
      ExplicitLeft = 101
      ExplicitTop = 16
    end
    object Panel12: TPanel
      Left = 1
      Top = 17
      Width = 128
      Height = 79
      Align = alLeft
      TabOrder = 0
      object Panel16: TPanel
        Left = 1
        Top = 42
        Width = 126
        Height = 41
        Align = alTop
        Caption = #1048#1085#1090#1077#1085#1089#1080#1074#1085#1086#1089#1090#1100' 660 nm'
        TabOrder = 0
      end
      object Panel17: TPanel
        Left = 1
        Top = 1
        Width = 126
        Height = 41
        Align = alTop
        Caption = #1048#1085#1090#1077#1085#1089#1080#1074#1085#1086#1089#1090#1100' 460 nm'
        TabOrder = 1
      end
    end
    object Panel18: TPanel
      Left = 132
      Top = 17
      Width = 431
      Height = 79
      Align = alClient
      TabOrder = 1
      ExplicitWidth = 341
      object Panel15: TPanel
        Left = 1
        Top = 42
        Width = 429
        Height = 36
        Align = alTop
        TabOrder = 0
        ExplicitWidth = 339
        object TrackBar6: TTrackBar
          Left = 1
          Top = 1
          Width = 366
          Height = 34
          Align = alClient
          Max = 100
          TabOrder = 0
          OnChange = TrackBar6Change
          ExplicitWidth = 276
        end
        object SpinEdit7: TSpinEdit
          Left = 367
          Top = 1
          Width = 61
          Height = 34
          Align = alRight
          MaxValue = 0
          MinValue = -100
          TabOrder = 1
          Value = 0
          OnChange = SpinEdit7Change
          ExplicitLeft = 277
        end
      end
      object Panel19: TPanel
        Left = 1
        Top = 1
        Width = 429
        Height = 41
        Align = alTop
        TabOrder = 1
        ExplicitWidth = 339
        object TrackBar7: TTrackBar
          Left = 1
          Top = 1
          Width = 366
          Height = 39
          Align = alClient
          Max = 100
          TabOrder = 0
          OnChange = TrackBar7Change
          ExplicitLeft = -5
          ExplicitTop = -3
          ExplicitWidth = 276
        end
        object SpinEdit6: TSpinEdit
          Left = 367
          Top = 1
          Width = 61
          Height = 39
          Align = alRight
          MaxValue = 0
          MinValue = -100
          TabOrder = 1
          Value = 0
          OnChange = SpinEdit6Change
          ExplicitLeft = 277
        end
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 97
    Width = 564
    Height = 159
    Align = alTop
    TabOrder = 1
    object LightSetting: TLabel
      Left = 1
      Top = 1
      Width = 562
      Height = 16
      Align = alTop
      Caption = 'LightSetting'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      ExplicitWidth = 79
    end
    object Splitter6: TSplitter
      Left = 345
      Top = 17
      Height = 141
      Align = alRight
      ExplicitLeft = 348
      ExplicitHeight = 144
    end
    object Splitter2: TSplitter
      Left = 216
      Top = 17
      Height = 141
      ExplicitLeft = 223
      ExplicitTop = 15
      ExplicitHeight = 126
    end
    object Panel5: TPanel
      Left = 348
      Top = 17
      Width = 215
      Height = 141
      Align = alRight
      TabOrder = 0
      ExplicitHeight = 126
      object Label2: TLabel
        Left = 1
        Top = 1
        Width = 213
        Height = 13
        Align = alTop
        Alignment = taCenter
        Caption = #1048#1085#1090#1077#1085#1089#1080#1074#1085#1086#1089#1090#1100' '#1089#1074#1077#1095#1077#1085#1080#1103
        ExplicitWidth = 127
      end
      object Panel6: TPanel
        Left = 1
        Top = 55
        Width = 213
        Height = 41
        Align = alTop
        TabOrder = 0
        ExplicitTop = 42
        ExplicitWidth = 339
        object TrackBar1: TTrackBar
          Left = 1
          Top = 1
          Width = 150
          Height = 39
          Align = alClient
          TabOrder = 0
          OnChange = TrackBar1Change
          ExplicitWidth = 276
        end
        object SpinEdit1: TSpinEdit
          Left = 151
          Top = 1
          Width = 61
          Height = 39
          Align = alRight
          Increment = 10
          MaxValue = 100
          MinValue = 0
          TabOrder = 1
          Value = 0
          OnChange = SpinEdit1Change
          ExplicitLeft = 277
        end
      end
      object Panel7: TPanel
        Left = 1
        Top = 14
        Width = 213
        Height = 41
        Align = alTop
        TabOrder = 1
        ExplicitTop = 1
        ExplicitWidth = 339
        object SpinEdit2: TSpinEdit
          Left = 151
          Top = 1
          Width = 61
          Height = 39
          Align = alRight
          Increment = 10
          MaxValue = 100
          MinValue = 0
          TabOrder = 0
          Value = 0
          OnChange = SpinEdit2Change
          ExplicitLeft = 277
        end
        object TrackBar2: TTrackBar
          Left = 1
          Top = 1
          Width = 150
          Height = 39
          Align = alClient
          TabOrder = 1
          OnChange = TrackBar2Change
          ExplicitWidth = 276
        end
      end
      object Panel14: TPanel
        Left = 1
        Top = 96
        Width = 213
        Height = 41
        Align = alTop
        TabOrder = 2
        ExplicitTop = 83
        ExplicitWidth = 339
        object TrackBar5: TTrackBar
          Left = 1
          Top = 1
          Width = 150
          Height = 39
          Align = alClient
          TabOrder = 0
          OnChange = TrackBar5Change
          ExplicitWidth = 276
        end
        object SpinEdit5: TSpinEdit
          Left = 151
          Top = 1
          Width = 61
          Height = 39
          Align = alRight
          Increment = 10
          MaxValue = 100
          MinValue = 0
          TabOrder = 1
          Value = 0
          OnChange = SpinEdit5Change
          ExplicitLeft = 277
        end
      end
    end
    object Panel4: TPanel
      Left = 219
      Top = 17
      Width = 126
      Height = 141
      Align = alClient
      TabOrder = 1
      ExplicitLeft = 196
      ExplicitWidth = 132
      ExplicitHeight = 126
      object Label10: TLabel
        Left = 1
        Top = 1
        Width = 124
        Height = 13
        Align = alTop
        Alignment = taCenter
        Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077
        ExplicitWidth = 73
      end
      object Panel9: TPanel
        Left = 1
        Top = 55
        Width = 124
        Height = 41
        Align = alTop
        Caption = #1053#1072#1089#1099#1097#1072#1102#1097#1080#1081' '#1089#1074#1077#1090
        TabOrder = 0
        ExplicitTop = 42
        ExplicitWidth = 126
      end
      object Panel13: TPanel
        Left = 1
        Top = 96
        Width = 124
        Height = 41
        Align = alTop
        Caption = #1044#1086#1087'. '#1089#1074#1077#1090
        TabOrder = 1
        ExplicitTop = 83
        ExplicitWidth = 126
      end
      object Panel8: TPanel
        Left = 1
        Top = 14
        Width = 124
        Height = 41
        Align = alTop
        Caption = #1040#1082#1090#1080#1085#1080#1095#1085#1099#1081' '#1089#1074#1077#1090
        TabOrder = 2
        ExplicitTop = 1
        ExplicitWidth = 128
      end
    end
    object Panel20: TPanel
      Left = 1
      Top = 17
      Width = 215
      Height = 141
      Align = alLeft
      TabOrder = 2
      ExplicitLeft = 60
      ExplicitTop = 23
      ExplicitHeight = 126
      object Label1: TLabel
        Left = 1
        Top = 1
        Width = 213
        Height = 13
        Align = alTop
        Alignment = taCenter
        Caption = #1044#1083#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100' '#1089#1074#1077#1095#1077#1085#1080#1103
        ExplicitWidth = 123
      end
      object Panel21: TPanel
        Left = 1
        Top = 14
        Width = 213
        Height = 41
        Align = alTop
        TabOrder = 0
        ExplicitTop = 40
        ExplicitWidth = 185
        object TrackBar8: TTrackBar
          Left = 65
          Top = 1
          Width = 147
          Height = 39
          Align = alClient
          Max = 10000
          TabOrder = 0
          OnChange = TrackBar8Change
          ExplicitLeft = 76
          ExplicitTop = -4
          ExplicitWidth = 150
          ExplicitHeight = 45
        end
        object SpinEdit8: TSpinEdit
          Left = 1
          Top = 1
          Width = 64
          Height = 39
          Align = alLeft
          MaxValue = 0
          MinValue = 0
          TabOrder = 1
          Value = 0
          OnChange = SpinEdit8Change
        end
      end
      object Panel22: TPanel
        Left = 1
        Top = 55
        Width = 213
        Height = 41
        Align = alTop
        TabOrder = 1
        ExplicitLeft = 43
        ExplicitTop = 85
        ExplicitWidth = 185
        object TrackBar9: TTrackBar
          Left = 65
          Top = 1
          Width = 147
          Height = 39
          Align = alClient
          Max = 10000
          TabOrder = 0
          OnChange = TrackBar9Change
          ExplicitLeft = 76
          ExplicitTop = -4
          ExplicitWidth = 150
          ExplicitHeight = 45
        end
        object SpinEdit9: TSpinEdit
          Left = 1
          Top = 1
          Width = 64
          Height = 39
          Align = alLeft
          MaxValue = 0
          MinValue = 0
          TabOrder = 1
          Value = 0
          OnChange = SpinEdit9Change
        end
      end
      object Panel23: TPanel
        Left = 1
        Top = 96
        Width = 213
        Height = 42
        Align = alTop
        TabOrder = 2
        ExplicitLeft = 43
        ExplicitTop = 24
        ExplicitWidth = 185
        ExplicitHeight = 41
        object TrackBar10: TTrackBar
          Left = 65
          Top = 1
          Width = 147
          Height = 40
          Align = alClient
          Max = 10000
          TabOrder = 0
          OnChange = TrackBar10Change
          ExplicitLeft = 112
          ExplicitWidth = 113
        end
        object SpinEdit10: TSpinEdit
          Left = 1
          Top = 1
          Width = 64
          Height = 40
          Align = alLeft
          MaxValue = 0
          MinValue = 0
          TabOrder = 1
          Value = 0
          OnChange = SpinEdit10Change
        end
      end
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 259
    Width = 564
    Height = 198
    Align = alTop
    TabOrder = 2
    object Splitter4: TSplitter
      Left = 281
      Top = 1
      Height = 196
      Align = alRight
      ExplicitLeft = 256
      ExplicitTop = 80
      ExplicitHeight = 100
    end
    object Panel11: TPanel
      Left = 284
      Top = 1
      Width = 279
      Height = 196
      Align = alRight
      TabOrder = 0
      ExplicitHeight = 212
      object Label4: TLabel
        Left = 1
        Top = 1
        Width = 277
        Height = 16
        Align = alTop
        Alignment = taCenter
        Caption = #1048#1079#1084#1077#1088#1080#1090#1077#1083#1100#1085#1099#1081' '#1080#1084#1087#1091#1083#1100#1089
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        ExplicitWidth = 165
      end
      object GroupBox4: TGroupBox
        Left = 1
        Top = 111
        Width = 277
        Height = 78
        Align = alTop
        Caption = #1044#1083#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100' (mks)'
        TabOrder = 0
        ExplicitTop = 107
        ExplicitWidth = 238
        object Label8: TLabel
          Left = 71
          Top = 34
          Width = 11
          Height = 13
          Caption = '%'
        end
        object Label9: TLabel
          Left = 130
          Top = 34
          Width = 73
          Height = 16
          Caption = '3350 (mks)'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object SpinEdit4: TSpinEdit
          Left = 3
          Top = 33
          Width = 62
          Height = 22
          MaxValue = 50
          MinValue = 1
          TabOrder = 0
          Value = 1
          OnChange = SpinEdit4Change
        end
      end
      object GroupBox3: TGroupBox
        Left = 1
        Top = 17
        Width = 277
        Height = 94
        Align = alTop
        Caption = #1047#1072#1076#1077#1088#1078#1082#1072
        TabOrder = 1
        object Label6: TLabel
          Left = 71
          Top = 40
          Width = 11
          Height = 13
          Caption = '%'
        end
        object Label7: TLabel
          Left = 128
          Top = 40
          Width = 61
          Height = 16
          Caption = '2111 mks'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object SpinEdit3: TSpinEdit
          Left = 4
          Top = 35
          Width = 61
          Height = 22
          MaxValue = 50
          MinValue = 1
          TabOrder = 0
          Value = 1
          OnChange = SpinEdit3Change
        end
      end
    end
    object Panel10: TPanel
      Left = 1
      Top = 1
      Width = 280
      Height = 196
      Align = alClient
      TabOrder = 1
      ExplicitTop = 4
      ExplicitHeight = 222
      object Label5: TLabel
        Left = 1
        Top = 1
        Width = 278
        Height = 16
        Align = alTop
        Alignment = taCenter
        Caption = #1042#1080#1076#1077#1086#1082#1072#1084#1077#1088#1072' Mightex'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        Layout = tlCenter
        ExplicitWidth = 145
      end
      object GroupBox1: TGroupBox
        Left = 1
        Top = 38
        Width = 278
        Height = 78
        Align = alTop
        Anchors = [akLeft, akTop, akRight, akBottom]
        Caption = #1069#1082#1089#1087#1086#1079#1080#1094#1080#1103' 6700 mks'
        TabOrder = 0
        object TrackBar3: TTrackBar
          AlignWithMargins = True
          Left = 5
          Top = 18
          Width = 268
          Height = 55
          Align = alClient
          Max = 100
          Min = 1
          Frequency = 4
          Position = 10
          TabOrder = 0
          OnChange = TrackBar3Change
          ExplicitHeight = 45
        end
      end
      object GroupBox2: TGroupBox
        Left = 1
        Top = 116
        Width = 278
        Height = 77
        Align = alTop
        Caption = #1059#1089#1080#1083#1077#1085#1080#1077' 10 db'
        TabOrder = 1
        object TrackBar4: TTrackBar
          AlignWithMargins = True
          Left = 5
          Top = 18
          Width = 268
          Height = 54
          Align = alClient
          Max = 41
          Min = 6
          Position = 6
          TabOrder = 0
          OnChange = TrackBar4Change
          ExplicitWidth = 217
          ExplicitHeight = 55
        end
      end
      object ComboBox1: TComboBox
        Left = 1
        Top = 17
        Width = 278
        Height = 21
        Align = alTop
        TabOrder = 2
        Text = '5, ms'
        OnChange = ComboBox1Change
        Items.Strings = (
          '5 ms'
          '10 ms'
          '100 ms')
        ExplicitWidth = 227
      end
    end
  end
end
