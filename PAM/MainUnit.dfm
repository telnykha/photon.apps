object mainPAM: TmainPAM
  Left = 0
  Top = 0
  Caption = 'P.A.M.'
  ClientHeight = 684
  ClientWidth = 1031
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  WindowState = wsMaximized
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter4: TSplitter
    Left = 0
    Top = 558
    Width = 1031
    Height = 3
    Cursor = crVSplit
    Align = alBottom
    ExplicitTop = 81
    ExplicitWidth = 338
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1031
    Height = 81
    Align = alTop
    TabOrder = 0
    object SpeedButton1: TSpeedButton
      Left = 2
      Top = 3
      Width = 72
      Height = 72
      Action = fileNewAction
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000130B0000130B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF0033333333B333
        333B33FF33337F3333F73BB3777BB7777BB3377FFFF77FFFF77333B000000000
        0B3333777777777777333330FFFFFFFF07333337F33333337F333330FFFFFFFF
        07333337F33333337F333330FFFFFFFF07333337F33333337F333330FFFFFFFF
        07333FF7F33333337FFFBBB0FFFFFFFF0BB37777F3333333777F3BB0FFFFFFFF
        0BBB3777F3333FFF77773330FFFF000003333337F333777773333330FFFF0FF0
        33333337F3337F37F3333330FFFF0F0B33333337F3337F77FF333330FFFF003B
        B3333337FFFF77377FF333B000000333BB33337777777F3377FF3BB3333BB333
        3BB33773333773333773B333333B3333333B7333333733333337}
      Layout = blGlyphTop
      NumGlyphs = 2
      ParentShowHint = False
      ShowHint = True
    end
    object SpeedButton2: TSpeedButton
      Left = 76
      Top = 3
      Width = 72
      Height = 72
      Action = fileOpenAction
      Caption = #1054#1090#1082#1088#1099#1090#1100
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000120B0000120B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00555555555555
        55555555FFFFFFFFFF55555000000000055555577777777775F55500B8B8B8B8
        B05555775F555555575F550F0B8B8B8B8B05557F75F555555575550BF0B8B8B8
        B8B0557F575FFFFFFFF7550FBF0000000000557F557777777777500BFBFBFBFB
        0555577F555555557F550B0FBFBFBFBF05557F7F555555FF75550F0BFBFBF000
        55557F75F555577755550BF0BFBF0B0555557F575FFF757F55550FB700007F05
        55557F557777557F55550BFBFBFBFB0555557F555555557F55550FBFBFBFBF05
        55557FFFFFFFFF7555550000000000555555777777777755555550FBFB055555
        5555575FFF755555555557000075555555555577775555555555}
      Layout = blGlyphTop
      NumGlyphs = 2
    end
    object SpeedButton3: TSpeedButton
      Left = 148
      Top = 3
      Width = 72
      Height = 72
      Action = fileSaveAction
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000120B0000120B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        333333FFFFFFFFFFFFF33000077777770033377777777777773F000007888888
        00037F3337F3FF37F37F00000780088800037F3337F77F37F37F000007800888
        00037F3337F77FF7F37F00000788888800037F3337777777337F000000000000
        00037F3FFFFFFFFFFF7F00000000000000037F77777777777F7F000FFFFFFFFF
        00037F7F333333337F7F000FFFFFFFFF00037F7F333333337F7F000FFFFFFFFF
        00037F7F333333337F7F000FFFFFFFFF00037F7F333333337F7F000FFFFFFFFF
        00037F7F333333337F7F000FFFFFFFFF07037F7F33333333777F000FFFFFFFFF
        0003737FFFFFFFFF7F7330099999999900333777777777777733}
      Layout = blGlyphTop
      NumGlyphs = 2
    end
    object SpeedButton4: TSpeedButton
      Left = 226
      Top = 3
      Width = 72
      Height = 72
      Action = deviceCheckAction
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000120B0000120B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00555555555555
        555555555555555555555555555555555555555555FF55555555555559055555
        55555555577FF5555555555599905555555555557777F5555555555599905555
        555555557777FF5555555559999905555555555777777F555555559999990555
        5555557777777FF5555557990599905555555777757777F55555790555599055
        55557775555777FF5555555555599905555555555557777F5555555555559905
        555555555555777FF5555555555559905555555555555777FF55555555555579
        05555555555555777FF5555555555557905555555555555777FF555555555555
        5990555555555555577755555555555555555555555555555555}
      Layout = blGlyphTop
      NumGlyphs = 2
    end
    object SpeedButton5: TSpeedButton
      Left = 298
      Top = 3
      Width = 72
      Height = 72
      Action = device460nmAction
      AllowAllUp = True
      GroupIndex = 1
      Caption = ' 460 nm'
      Glyph.Data = {
        76020000424D7602000000000000760000002800000040000000100000000100
        04000000000000020000120B0000120B00001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333FFFFF3333333333FFFFF3333333333333333333333333330000033
        33333333F777773FF333333FF377777F33333333330000033333333008877700
        33333337733FFF773F3333F377FFF33773333333007778800333330887000777
        033333733F777FFF73F33F37FFF777F337333330777000788033308800000007
        703337F37777777FF7F33F7FF77333773F73330770FCFCF08803308000000000
        7033373777777777F73FF37F73377733737333070F00000F0803087000777000
        77037F3777333777FF7FF7FF7373337373F73077F0077C00F780080007777700
        07037F777F3333777F7FF7F7373333F737F73070C077C7C0C0800F0007777700
        07037F777F3333777F7FF7F7373333F737F73070F07CCCC0F0F00F0008777700
        08037F777FF33377737FF73737333FF737F73080C0C7CCF0C0F00F7000887000
        780373F777FFF777F373373F737FFF737F373087F00CFF00F7F0308000000000
        803337F77777777737F33F73733777337F7333080F00000F080330F800000008
        8033373F777777733733337337733377F373330880FCFCF08F03330F87000788
        03333373FF77733F73333337F33777FF3733333088700078F03333300FFF8800
        3333333773FFFF773333333377FFFF37733333330088FFF00333333330000033
        3333333337777733333333333377777333333333330000033333}
      Layout = blGlyphTop
      NumGlyphs = 4
    end
    object SpeedButton6: TSpeedButton
      Left = 370
      Top = 3
      Width = 72
      Height = 72
      Action = device660nmAction
      AllowAllUp = True
      GroupIndex = 2
      Caption = '660 nm'
      Glyph.Data = {
        76020000424D7602000000000000760000002800000040000000100000000100
        04000000000000020000120B0000120B00001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333FFFFF3333333333FFFFF3333333333333333333333333330000033
        33333333F777773FF333333FF377777F33333333330000033333333008877700
        33333337733FFF773F3333F377FFF33773333333007778800333330887000777
        033333733F777FFF73F33F37FFF777F337333330777000788033308800000007
        703337F37777777FF7F33F7FF77333773F73330770F9F9F08803308000000000
        7033373777777777F73FF37F73377733737333070F00000F0803087000111000
        77037F3777333777FF7FF7FF7373337373F73077F0011900F780080001111100
        07037F777F3333777F7FF7F7373333F737F730709011919090800F0001111100
        07037F777F3333777F7FF7F7373333F737F73070F0199990F0F00F0008111100
        08037F777FF33377737FF73737333FF737F73080909199F090F00F7000881000
        780373F777FFF777F373373F737FFF737F373087F009FF00F7F0308000000000
        803337F77777777737F33F73733777337F7333080F00000F080330F800000008
        8033373F777777733733337337733377F373330880F9F9F08F03330F87000788
        03333373FF77733F73333337F33777FF3733333088700078F03333300FFF8800
        3333333773FFFF773333333377FFFF37733333330088FFF00333333330000033
        3333333337777733333333333377777333333333330000033333}
      Layout = blGlyphTop
      NumGlyphs = 4
    end
    object SpeedButton7: TSpeedButton
      Left = 442
      Top = 3
      Width = 72
      Height = 72
      Action = deviceVideocamAction
      AllowAllUp = True
      GroupIndex = 3
      Caption = #1042#1080#1076#1077#1086
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000120B0000120B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333000000
        033333FFFF77777773F330000077777770333777773FFFFFF733077777000000
        03337F3F3F777777733F0797A770003333007F737337773F3377077777778803
        30807F333333337FF73707888887880007707F3FFFF333777F37070000878807
        07807F777733337F7F3707888887880808807F333333337F7F37077777778800
        08807F333FFF337773F7088800088803308073FF777FFF733737300008000033
        33003777737777333377333080333333333333F7373333333333300803333333
        33333773733333333333088033333333333373F7F33333333333308033333333
        3333373733333333333333033333333333333373333333333333}
      Layout = blGlyphTop
      NumGlyphs = 2
    end
    object SpeedButton8: TSpeedButton
      Left = 514
      Top = 3
      Width = 72
      Height = 72
      Action = deviceExperimentAction
      Caption = #1048#1079#1084#1077#1088#1077#1085#1080#1077
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000130B0000130B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        33333333333333333333EEEEEEEEEEEEEEE333FFFFFFFFFFFFF3E00000000000
        00E337777777777777F3E0F77777777770E337F33333333337F3E0F333333333
        70E337F3333F333337F3E0F33303333370E337F3337FF33337F3E0F333003333
        70E337F33377FF3337F3E0F33300033370E337F333777FF337F3E0F333000033
        70E337F33377773337F3E0F33300033370E337F33377733337F3E0F333003333
        70E337F33377333337F3E0F33303333370E337F33373333337F3E0F333333333
        70E337F33333333337F3E0FFFFFFFFFFF0E337FFFFFFFFFFF7F3E00000000000
        00E33777777777777733EEEEEEEEEEEEEEE33333333333333333}
      Layout = blGlyphTop
      NumGlyphs = 2
    end
    object SpeedButton9: TSpeedButton
      Left = 592
      Top = 3
      Width = 72
      Height = 72
      Action = helpContextAction
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000120B0000120B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333FFFFF3333333333F797F3333333333F737373FF333333BFB999BFB
        33333337737773773F3333BFBF797FBFB33333733337333373F33BFBFBFBFBFB
        FB3337F33333F33337F33FBFBFB9BFBFBF3337333337F333373FFBFBFBF97BFB
        FBF37F333337FF33337FBFBFBFB99FBFBFB37F3333377FF3337FFBFBFBFB99FB
        FBF37F33333377FF337FBFBF77BF799FBFB37F333FF3377F337FFBFB99FB799B
        FBF373F377F3377F33733FBF997F799FBF3337F377FFF77337F33BFBF99999FB
        FB33373F37777733373333BFBF999FBFB3333373FF77733F7333333BFBFBFBFB
        3333333773FFFF77333333333FBFBF3333333333377777333333}
      Layout = blGlyphTop
      NumGlyphs = 2
    end
    object SpeedButton13: TSpeedButton
      Left = 670
      Top = 3
      Width = 72
      Height = 72
      OnClick = Add_diff_comm
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 665
    Width = 1031
    Height = 19
    Panels = <
      item
        Text = 'qq'
        Width = 500
      end
      item
        Width = 50
      end>
  end
  object Memo2: TMemo
    Left = 0
    Top = 561
    Width = 1031
    Height = 104
    Align = alBottom
    Color = clBlack
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clLime
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 2
  end
  object PageControl1: TPageControl
    Left = 220
    Top = 81
    Width = 811
    Height = 477
    ActivePage = TabSheet1
    Align = alClient
    TabOrder = 3
    OnChange = PageControl1Change
    object TabSheet1: TTabSheet
      Caption = #1054#1087#1080#1089#1072#1085#1080#1077' '#1101#1082#1089#1087#1077#1088#1080#1084#1077#1085#1090#1072
      object StringGrid1: TStringGrid
        Left = 0
        Top = 41
        Width = 803
        Height = 408
        Align = alClient
        ColCount = 6
        FixedCols = 0
        RowCount = 1
        FixedRows = 0
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goRowSelect]
        PopupMenu = PopupMenu1
        TabOrder = 0
        OnDblClick = StringGrid1DblClick
        ColWidths = (
          498
          108
          84
          440
          64
          64)
      end
      object Panel4: TPanel
        Left = 0
        Top = 0
        Width = 803
        Height = 41
        Align = alTop
        ParentBackground = False
        TabOrder = 1
        object SpeedButton10: TSpeedButton
          Left = 8
          Top = 3
          Width = 32
          Height = 32
          Action = editInsertAction
          Flat = True
          Glyph.Data = {
            76010000424D7601000000000000760000002800000020000000100000000100
            04000000000000010000130B0000130B00001000000000000000000000000000
            800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
            33333333FF33333333FF333993333333300033377F3333333777333993333333
            300033F77FFF3333377739999993333333333777777F3333333F399999933333
            33003777777333333377333993333333330033377F3333333377333993333333
            3333333773333333333F333333333333330033333333F33333773333333C3333
            330033333337FF3333773333333CC333333333FFFFF77FFF3FF33CCCCCCCCCC3
            993337777777777F77F33CCCCCCCCCC3993337777777777377333333333CC333
            333333333337733333FF3333333C333330003333333733333777333333333333
            3000333333333333377733333333333333333333333333333333}
          Layout = blGlyphBottom
          NumGlyphs = 2
        end
        object SpeedButton11: TSpeedButton
          Left = 40
          Top = 3
          Width = 32
          Height = 32
          Action = editDeleteAction
          Flat = True
          Glyph.Data = {
            76010000424D7601000000000000760000002800000020000000100000000100
            04000000000000010000130B0000130B00001000000000000000000000000000
            800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
            333333333333333333FF33333333333330003333333333333777333333333333
            300033FFFFFF3333377739999993333333333777777F3333333F399999933333
            3300377777733333337733333333333333003333333333333377333333333333
            3333333333333333333F333333333333330033333F33333333773333C3333333
            330033337F3333333377333CC3333333333333F77FFFFFFF3FF33CCCCCCCCCC3
            993337777777777F77F33CCCCCCCCCC399333777777777737733333CC3333333
            333333377F33333333FF3333C333333330003333733333333777333333333333
            3000333333333333377733333333333333333333333333333333}
          NumGlyphs = 2
        end
        object SpeedButton12: TSpeedButton
          Left = 72
          Top = 3
          Width = 32
          Height = 32
          Action = editEditAction
          Flat = True
          Glyph.Data = {
            76010000424D7601000000000000760000002800000020000000100000000100
            04000000000000010000130B0000130B00001000000000000000000000000000
            800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
            333333333333333333FF33333333333330003FF3FFFFF3333777003000003333
            300077F777773F333777E00BFBFB033333337773333F7F33333FE0BFBF000333
            330077F3337773F33377E0FBFBFBF033330077F3333FF7FFF377E0BFBF000000
            333377F3337777773F3FE0FBFBFBFBFB039977F33FFFFFFF7377E0BF00000000
            339977FF777777773377000BFB03333333337773FF733333333F333000333333
            3300333777333333337733333333333333003333333333333377333333333333
            333333333333333333FF33333333333330003333333333333777333333333333
            3000333333333333377733333333333333333333333333333333}
          NumGlyphs = 2
        end
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1048#1089#1093#1086#1076#1085#1099#1081' '#1082#1086#1076' Arduino'
      ImageIndex = 1
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 803
        Height = 449
        Align = alClient
        Color = clNavy
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clYellow
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Lines.Strings = (
          'Memo1')
        ParentFont = False
        ReadOnly = True
        ScrollBars = ssBoth
        TabOrder = 0
      end
    end
    object TabSheet3: TTabSheet
      Caption = #1042#1080#1076#1077#1086#1082#1072#1084#1077#1088#1072
      ImageIndex = 2
      OnShow = TabSheet3Show
      object PhImage1: TPhImage
        Left = 0
        Top = 0
        Width = 803
        Height = 400
        AutoMosaic = True
        ThumbWidht = 128
        ThumbHeight = 128
        SlideShowInterval = 500
        Align = alClient
        ParentColor = False
      end
      object Panel3: TPanel
        Left = 0
        Top = 400
        Width = 803
        Height = 49
        Align = alBottom
        TabOrder = 1
        object Button1: TButton
          AlignWithMargins = True
          Left = 4
          Top = 4
          Width = 117
          Height = 41
          Align = alLeft
          Caption = #1057#1076#1077#1083#1072#1090#1100' '#1089#1085#1080#1084#1086#1082
          TabOrder = 0
          OnClick = Button1Click
        end
      end
    end
    object Архив: TTabSheet
      Caption = #1040#1088#1093#1080#1074
      ImageIndex = 3
      object Splitter3: TSplitter
        Left = 179
        Top = 0
        Height = 449
        ExplicitLeft = 192
        ExplicitTop = 144
        ExplicitHeight = 100
      end
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 179
        Height = 449
        Align = alLeft
        TabOrder = 0
        object Splitter1: TSplitter
          Left = 1
          Top = 193
          Width = 177
          Height = 3
          Cursor = crVSplit
          Align = alTop
          ExplicitTop = 121
          ExplicitWidth = 188
        end
        object DirectoryListBox1: TDirectoryListBox
          Left = 1
          Top = 1
          Width = 177
          Height = 192
          Align = alTop
          FileList = FileListBox1
          TabOrder = 0
          OnChange = DirectoryListBox1Change
        end
        object FileListBox1: TFileListBox
          Left = 1
          Top = 196
          Width = 177
          Height = 233
          Align = alClient
          ItemHeight = 13
          Mask = '*.raw'
          TabOrder = 1
          OnChange = FileListBox1Change
        end
        object DriveComboBox1: TDriveComboBox
          Left = 1
          Top = 429
          Width = 177
          Height = 19
          Align = alBottom
          DirList = DirectoryListBox1
          TabOrder = 2
        end
      end
      object Panel5: TPanel
        Left = 182
        Top = 0
        Width = 621
        Height = 449
        Align = alClient
        BevelOuter = bvNone
        Caption = 'Panel5'
        TabOrder = 1
        object Splitter2: TSplitter
          Left = 357
          Top = 0
          Width = 4
          Height = 449
          Align = alRight
          ExplicitLeft = 422
          ExplicitTop = -2
        end
        object PhImage2: TPhImage
          Left = 0
          Top = 0
          Width = 357
          Height = 449
          AutoMosaic = True
          ThumbWidht = 128
          ThumbHeight = 128
          SlideShowInterval = 500
          Align = alClient
          ParentColor = False
        end
        object Panel7: TPanel
          Left = 361
          Top = 0
          Width = 260
          Height = 449
          Align = alRight
          Caption = 'Panel7'
          TabOrder = 1
          object StringGrid2: TStringGrid
            Left = 1
            Top = 121
            Width = 258
            Height = 327
            Align = alClient
            ColCount = 6
            DefaultColWidth = 32
            DefaultRowHeight = 18
            FixedCols = 0
            RowCount = 2
            Font.Charset = RUSSIAN_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'Tahoma'
            Font.Style = []
            Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing, goRowSelect]
            ParentFont = False
            TabOrder = 0
            OnClick = StringGrid2Click
            ColWidths = (
              228
              47
              33
              100
              32
              32)
          end
          object Panel8: TPanel
            Left = 1
            Top = 1
            Width = 258
            Height = 120
            Align = alTop
            TabOrder = 1
            object Label8: TLabel
              Left = 5
              Top = 37
              Width = 66
              Height = 13
              Caption = #1069#1082#1089#1087#1086#1079#1080#1094#1080#1103': '
            end
            object Label9: TLabel
              Left = 5
              Top = 56
              Width = 52
              Height = 13
              Caption = #1059#1089#1080#1083#1077#1085#1080#1077':'
            end
            object Label10: TLabel
              Left = 5
              Top = 74
              Width = 55
              Height = 13
              Caption = #1047#1072#1076#1077#1088#1078#1082#1072':'
            end
            object Label11: TLabel
              Left = 5
              Top = 92
              Width = 80
              Height = 13
              Caption = #1044#1083#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100': '
            end
            object Label12: TLabel
              Left = 93
              Top = 37
              Width = 52
              Height = 13
              Caption = '-------------'
            end
            object Label13: TLabel
              Left = 93
              Top = 56
              Width = 52
              Height = 13
              Caption = '-------------'
            end
            object Label14: TLabel
              Left = 93
              Top = 74
              Width = 52
              Height = 13
              Caption = '-------------'
            end
            object Label15: TLabel
              Left = 93
              Top = 92
              Width = 52
              Height = 13
              Caption = '-------------'
            end
            object Label16: TLabel
              Left = 189
              Top = 37
              Width = 17
              Height = 13
              Caption = #1084#1082#1089
            end
            object Label17: TLabel
              Left = 189
              Top = 56
              Width = 12
              Height = 13
              Caption = 'dB'
            end
            object Label18: TLabel
              Left = 189
              Top = 74
              Width = 17
              Height = 13
              Caption = #1084#1082#1089
            end
            object Label19: TLabel
              Left = 189
              Top = 92
              Width = 17
              Height = 13
              Caption = #1084#1082#1089
            end
            object Button2: TButton
              Left = 5
              Top = 8
              Width = 244
              Height = 25
              Caption = #1054#1090#1082#1088#1099#1090#1100' '#1074' '#1088#1077#1076#1072#1082#1090#1086#1088#1077
              TabOrder = 0
              OnClick = Button2Click
            end
          end
        end
      end
    end
  end
  object Panel6: TPanel
    Left = 0
    Top = 81
    Width = 220
    Height = 477
    Align = alLeft
    TabOrder = 4
    object Label1: TLabel
      Left = 1
      Top = 335
      Width = 218
      Height = 16
      Align = alTop
      Alignment = taCenter
      Caption = #1057#1074#1077#1090#1086#1076#1080#1086#1076#1099
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      ExplicitWidth = 83
    end
    object Label2: TLabel
      Left = 1
      Top = 1
      Width = 218
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
      ExplicitWidth = 145
    end
    object Label3: TLabel
      Left = 1
      Top = 201
      Width = 218
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
    object GroupBox3: TGroupBox
      AlignWithMargins = True
      Left = 4
      Top = 354
      Width = 212
      Height = 71
      Align = alTop
      Caption = #1048#1085#1090#1077#1085#1089#1080#1074#1085#1086#1089#1090#1100' 460 nm'
      TabOrder = 0
      object TrackBar3: TTrackBar
        AlignWithMargins = True
        Left = 5
        Top = 18
        Width = 202
        Height = 48
        Align = alClient
        Max = 100
        Frequency = 10
        Position = 25
        ShowSelRange = False
        TabOrder = 0
        TickMarks = tmBoth
        OnChange = TrackBar3Change
      end
    end
    object GroupBox4: TGroupBox
      AlignWithMargins = True
      Left = 4
      Top = 220
      Width = 212
      Height = 53
      Align = alTop
      Caption = #1047#1072#1076#1077#1088#1078#1082#1072
      TabOrder = 1
      object Label4: TLabel
        Left = 72
        Top = 24
        Width = 11
        Height = 13
        Caption = '%'
      end
      object Label5: TLabel
        Left = 113
        Top = 24
        Width = 55
        Height = 13
        Caption = 'xxxx mks'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object SpinEdit2: TSpinEdit
        Left = 5
        Top = 20
        Width = 65
        Height = 22
        MaxValue = 50
        MinValue = 1
        TabOrder = 0
        Value = 10
        OnChange = SpinEdit2Change
      end
    end
    object GroupBox2: TGroupBox
      AlignWithMargins = True
      Left = 4
      Top = 431
      Width = 212
      Height = 74
      Align = alTop
      Caption = #1048#1085#1090#1077#1085#1089#1080#1074#1085#1086#1089#1090#1100' 660 nm'
      TabOrder = 2
      object TrackBar2: TTrackBar
        AlignWithMargins = True
        Left = 5
        Top = 20
        Width = 202
        Height = 49
        Align = alBottom
        Max = 100
        Frequency = 10
        Position = 25
        ShowSelRange = False
        TabOrder = 0
        TickMarks = tmBoth
        OnChange = TrackBar2Change
      end
    end
    object GroupBox1: TGroupBox
      AlignWithMargins = True
      Left = 4
      Top = 20
      Width = 212
      Height = 101
      Align = alTop
      Caption = #1069#1082#1089#1087#1086#1079#1080#1094#1080#1103
      TabOrder = 3
      object TrackBar1: TTrackBar
        AlignWithMargins = True
        Left = 5
        Top = 47
        Width = 202
        Height = 49
        Align = alBottom
        Max = 100
        Min = 1
        Frequency = 4
        Position = 25
        ShowSelRange = False
        TabOrder = 0
        TickMarks = tmBoth
        OnChange = TrackBar1Change
      end
      object ComboBox1: TComboBox
        AlignWithMargins = True
        Left = 5
        Top = 18
        Width = 200
        Height = 21
        Align = alLeft
        Style = csDropDownList
        ItemIndex = 0
        TabOrder = 1
        Text = '5 ms'
        OnChange = ComboBox1Change
        Items.Strings = (
          '5 ms'
          '10 ms'
          '100 ms')
      end
    end
    object GroupBox5: TGroupBox
      AlignWithMargins = True
      Left = 4
      Top = 127
      Width = 212
      Height = 71
      Align = alTop
      Caption = #1059#1089#1080#1083#1077#1085#1080#1077
      TabOrder = 4
      object TrackBar5: TTrackBar
        AlignWithMargins = True
        Left = 5
        Top = 18
        Width = 202
        Height = 48
        Align = alClient
        Max = 41
        Min = 6
        Frequency = 2
        Position = 25
        ShowSelRange = False
        TabOrder = 0
        TickMarks = tmBoth
        OnChange = TrackBar5Change
      end
    end
    object GroupBox6: TGroupBox
      AlignWithMargins = True
      Left = 4
      Top = 279
      Width = 212
      Height = 53
      Align = alTop
      Caption = #1044#1083#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100' (mks)'
      TabOrder = 5
      object Label6: TLabel
        Left = 73
        Top = 24
        Width = 11
        Height = 13
        Caption = '%'
      end
      object Label7: TLabel
        Left = 113
        Top = 24
        Width = 55
        Height = 13
        Caption = 'xxxx mks'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object SpinEdit1: TSpinEdit
        Left = 5
        Top = 20
        Width = 65
        Height = 22
        MaxValue = 50
        MinValue = 1
        TabOrder = 0
        Value = 25
        OnChange = SpinEdit1Change
      end
    end
  end
  object MainMenu1: TMainMenu
    Left = 240
    Top = 496
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083#1099
      object N3: TMenuItem
        Action = fileNewAction
      end
      object N4: TMenuItem
        Action = fileOpenAction
      end
      object N5: TMenuItem
        Action = fileSaveAction
      end
      object N6: TMenuItem
        Action = fileSaveAsAction
      end
      object N7: TMenuItem
        Caption = '-'
      end
      object N2: TMenuItem
        Action = FileExit1
      end
    end
    object N18: TMenuItem
      Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077
      object N19: TMenuItem
        Action = editInsertAction
      end
      object N25: TMenuItem
        Action = editAddAction
      end
      object N20: TMenuItem
        Action = editDeleteAction
      end
      object N21: TMenuItem
        Action = editEditAction
      end
      object N33: TMenuItem
        Caption = '-'
      end
      object N34: TMenuItem
        Action = editCopyAction
      end
      object N35: TMenuItem
        Action = editPasteAction
      end
    end
    object N8: TMenuItem
      Caption = #1059#1089#1090#1088#1086#1081#1089#1090#1074#1086
      object N9: TMenuItem
        Action = deviceCheckAction
      end
      object N10: TMenuItem
        Caption = '-'
      end
      object N460nm1: TMenuItem
        Action = device460nmAction
      end
      object N660nm1: TMenuItem
        Action = device660nmAction
      end
      object N11: TMenuItem
        Action = deviceVideocamAction
      end
      object N12: TMenuItem
        Caption = '-'
      end
      object deviceExperimentAction1: TMenuItem
        Action = deviceExperimentAction
      end
    end
    object N13: TMenuItem
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072
      object N14: TMenuItem
        Action = toolsOptionsAction
      end
    end
    object N15: TMenuItem
      Caption = #1055#1086#1084#1086#1097#1100
      object N16: TMenuItem
        Action = helpContextAction
      end
      object N17: TMenuItem
        Action = helpAboutAction
      end
    end
  end
  object ActionList1: TActionList
    Left = 280
    Top = 496
    object FileExit1: TFileExit
      Category = 'File'
      Caption = #1042#1099#1093#1086#1076
      Hint = #1042#1099#1093#1086#1076'|'#1047#1072#1082#1088#1099#1090#1100' '#1087#1088#1080#1083#1086#1078#1077#1085#1080#1077
      ImageIndex = 43
    end
    object fileNewAction: TAction
      Category = 'File'
      Caption = '&'#1057#1086#1079#1076#1072#1090#1100
      Hint = #1057#1086#1079#1076#1072#1090#1100' '#1085#1086#1074#1099#1081' '#1101#1082#1089#1087#1077#1088#1080#1084#1077#1085#1090'|'#1057#1086#1079#1076#1072#1090#1100' '#1085#1086#1074#1099#1081' '#1101#1082#1089#1087#1077#1088#1080#1084#1077#1085#1090
      ShortCut = 16462
      OnExecute = fileNewActionExecute
    end
    object fileOpenAction: TAction
      Category = 'File'
      Caption = #1054#1090#1082#1088#1099#1090#1100'.... '
      ShortCut = 16463
      OnExecute = fileOpenActionExecute
      OnUpdate = fileOpenActionUpdate
    end
    object fileSaveAction: TAction
      Category = 'File'
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      ShortCut = 16467
      OnExecute = fileSaveActionExecute
      OnUpdate = fileSaveActionUpdate
    end
    object fileSaveAsAction: TAction
      Category = 'File'
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082'...'
      OnExecute = fileSaveAsActionExecute
      OnUpdate = fileSaveAsActionUpdate
    end
    object deviceCheckAction: TAction
      Category = 'Device'
      Caption = #1055#1088#1086#1074#1077#1088#1080#1090#1100
      OnExecute = deviceCheckActionExecute
      OnUpdate = deviceCheckActionUpdate
    end
    object device460nmAction: TAction
      Category = 'Device'
      Caption = #1055#1088#1086#1078#1077#1082#1090#1086#1088' 460 nm'
      GroupIndex = 1
      OnExecute = device460nmActionExecute
      OnUpdate = device460nmActionUpdate
    end
    object device660nmAction: TAction
      Category = 'Device'
      Caption = #1055#1088#1086#1078#1077#1082#1090#1086#1088' 660 nm'
      GroupIndex = 2
      OnExecute = device660nmActionExecute
      OnUpdate = device660nmActionUpdate
    end
    object deviceVideocamAction: TAction
      Category = 'Device'
      Caption = #1042#1080#1076#1077#1086#1082#1072#1084#1077#1088#1072
      GroupIndex = 3
      OnExecute = deviceVideocamActionExecute
      OnUpdate = deviceVideocamActionUpdate
    end
    object deviceExperimentAction: TAction
      Category = 'Device'
      Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100' '#1080#1079#1084#1077#1088#1077#1085#1080#1103
      OnExecute = deviceExperimentActionExecute
      OnUpdate = deviceExperimentActionUpdate
    end
    object toolsOptionsAction: TAction
      Category = 'Tools'
      Caption = #1054#1087#1094#1080#1080'... '
      OnExecute = toolsOptionsActionExecute
      OnUpdate = toolsOptionsActionUpdate
    end
    object helpAboutAction: TAction
      Category = 'Help'
      Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077'...'
      OnExecute = helpAboutActionExecute
    end
    object helpContextAction: TAction
      Category = 'Help'
      Caption = #1055#1086#1076#1089#1082#1072#1079#1082#1072
      OnExecute = helpContextActionExecute
    end
    object editInsertAction: TAction
      Category = 'Edit'
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
      ShortCut = 8237
      OnExecute = editInsertActionExecute
      OnUpdate = editInsertActionUpdate
    end
    object editDeleteAction: TAction
      Category = 'Edit'
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
      ShortCut = 16430
      OnExecute = editDeleteActionExecute
      OnUpdate = editDeleteActionUpdate
    end
    object editEditAction: TAction
      Category = 'Edit'
      Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
      ShortCut = 8205
      OnExecute = editEditActionExecute
      OnUpdate = editEditActionUpdate
    end
    object editAddAction: TAction
      Category = 'Edit'
      Caption = #1042#1089#1090#1072#1074#1080#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
      ShortCut = 16429
      OnExecute = editAddActionExecute
      OnUpdate = editAddActionUpdate
    end
    object editUpAction: TAction
      Category = 'Edit'
      Caption = #1055#1086#1076#1085#1103#1090#1100' '#1074#1074#1077#1088#1093
      OnExecute = editUpActionExecute
      OnUpdate = editUpActionUpdate
    end
    object editDownAction: TAction
      Category = 'Edit'
      Caption = #1054#1087#1091#1089#1090#1080#1090#1100' '#1074#1085#1080#1079
      OnExecute = editDownActionExecute
      OnUpdate = editDownActionUpdate
    end
    object editCopyAction: TAction
      Category = 'Edit'
      Caption = #1057#1082#1086#1087#1080#1088#1086#1074#1072#1090#1100' '#1074' '#1073#1091#1092#1077#1088
      ShortCut = 16451
      OnExecute = editCopyActionExecute
      OnUpdate = editCopyActionUpdate
    end
    object editPasteAction: TAction
      Category = 'Edit'
      Caption = #1042#1089#1090#1072#1074#1080#1090#1100' '#1080#1079' '#1073#1091#1092#1077#1088#1072
      ShortCut = 16470
      OnExecute = editPasteActionExecute
      OnUpdate = editPasteActionUpdate
    end
  end
  object ApplicationEvents1: TApplicationEvents
    OnIdle = ApplicationEvents1Idle
    OnHint = ApplicationEvents1Hint
    Left = 320
    Top = 496
  end
  object PopupMenu1: TPopupMenu
    Left = 444
    Top = 497
    object N22: TMenuItem
      Action = editInsertAction
    end
    object N26: TMenuItem
      Action = editAddAction
    end
    object N23: TMenuItem
      Action = editDeleteAction
    end
    object N24: TMenuItem
      Action = editEditAction
    end
    object N30: TMenuItem
      Caption = '-'
    end
    object N31: TMenuItem
      Action = editCopyAction
    end
    object N32: TMenuItem
      Action = editPasteAction
    end
    object N27: TMenuItem
      Caption = '-'
    end
    object N28: TMenuItem
      Action = editUpAction
    end
    object N29: TMenuItem
      Action = editDownAction
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 360
    Top = 496
  end
  object SaveDialog1: TSaveDialog
    Filter = #1060#1072#1081#1083#1099' PAM|*.pam'
    Left = 400
    Top = 496
  end
  object PhPaneTool1: TPhPaneTool
    PhImage = PhImage2
    Left = 485
    Top = 497
  end
end
