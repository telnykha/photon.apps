object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'PRI'
  ClientHeight = 634
  ClientWidth = 886
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel3: TPanel
    Left = 0
    Top = 0
    Width = 886
    Height = 634
    Align = alClient
    Caption = 'Panel3'
    TabOrder = 0
    object PageControl1: TPageControl
      Left = 1
      Top = 1
      Width = 884
      Height = 632
      ActivePage = TabSheet3
      Align = alClient
      TabOrder = 0
      OnChange = PageControl1Change
      object TabSheet2: TTabSheet
        Caption = #1042#1080#1076#1077#1086#1082#1072#1084#1077#1088#1072
        ImageIndex = 1
        object Panel2: TPanel
          Left = 0
          Top = 0
          Width = 200
          Height = 604
          Align = alLeft
          TabOrder = 0
          object GroupBox2: TGroupBox
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 192
            Height = 149
            Align = alTop
            Caption = #1050#1072#1083#1080#1073#1088#1086#1074#1082#1072
            TabOrder = 0
            Visible = False
            object Label1: TLabel
              Left = 28
              Top = 106
              Width = 45
              Height = 13
              Caption = #1052#1072#1089#1096#1090#1072#1073
            end
            object Label2: TLabel
              Left = 28
              Top = 74
              Width = 12
              Height = 13
              Caption = 'dY'
            end
            object Label3: TLabel
              Left = 28
              Top = 42
              Width = 12
              Height = 13
              Caption = 'dX'
            end
            object SpinEdit1: TSpinEdit
              Left = 79
              Top = 41
              Width = 72
              Height = 22
              EditorEnabled = False
              MaxValue = 10
              MinValue = -10
              TabOrder = 0
              Value = 0
            end
            object SpinEdit2: TSpinEdit
              Left = 79
              Top = 69
              Width = 72
              Height = 22
              EditorEnabled = False
              MaxValue = 10
              MinValue = -10
              TabOrder = 1
              Value = 0
            end
            object SpinEdit3: TSpinEdit
              Left = 79
              Top = 97
              Width = 72
              Height = 22
              EditorEnabled = False
              MaxValue = 1050
              MinValue = 950
              TabOrder = 2
              Value = 1000
            end
          end
          object GroupBox1: TGroupBox
            AlignWithMargins = True
            Left = 4
            Top = 159
            Width = 192
            Height = 114
            Align = alTop
            Caption = #1069#1082#1089#1087#1086#1079#1080#1094#1080#1103
            TabOrder = 1
            object ComboBox1: TComboBox
              AlignWithMargins = True
              Left = 28
              Top = 18
              Width = 145
              Height = 21
              Style = csDropDownList
              ItemIndex = 1
              TabOrder = 0
              Text = '10 ms'
              OnChange = ComboBox1Change
              Items.Strings = (
                '5 ms'
                '10 ms'
                '100 ms')
            end
            object TrackBar1: TTrackBar
              AlignWithMargins = True
              Left = 25
              Top = 62
              Width = 148
              Height = 33
              Max = 100
              Frequency = 5
              Position = 25
              ShowSelRange = False
              TabOrder = 1
              TickMarks = tmBoth
              OnChange = TrackBar1Change
            end
          end
          object CheckBox1: TCheckBox
            AlignWithMargins = True
            Left = 4
            Top = 279
            Width = 192
            Height = 17
            Align = alTop
            Caption = #1042#1082#1083#1102#1095#1080#1090#1100' '#1089#1074#1077#1090#1086#1076#1080#1086#1076#1099
            TabOrder = 2
            OnClick = CheckBox1Click
          end
        end
        object Panel8: TPanel
          Left = 200
          Top = 0
          Width = 676
          Height = 604
          Align = alClient
          Caption = 'Panel8'
          TabOrder = 1
          object PhImage1: TPhImage
            AlignWithMargins = True
            Left = 4
            Top = 4
            Width = 668
            Height = 449
            AutoMosaic = True
            ThumbWidht = 128
            ThumbHeight = 128
            SlideShowInterval = 500
            Align = alClient
            ParentColor = False
          end
          object Panel9: TPanel
            Left = 1
            Top = 456
            Width = 674
            Height = 147
            Align = alBottom
            TabOrder = 1
            object PhImage2: TPhImage
              AlignWithMargins = True
              Left = 186
              Top = 4
              Width = 176
              Height = 139
              AutoMosaic = True
              ThumbWidht = 128
              ThumbHeight = 128
              SlideShowInterval = 500
              Align = alLeft
              ParentColor = False
              OnMouseUp = PhImage2MouseUp
            end
            object PhImage3: TPhImage
              AlignWithMargins = True
              Left = 4
              Top = 4
              Width = 176
              Height = 139
              AutoMosaic = True
              ThumbWidht = 128
              ThumbHeight = 128
              SlideShowInterval = 500
              Align = alLeft
              ParentColor = False
              OnMouseUp = PhImage3MouseUp
            end
          end
        end
      end
      object TabSheet3: TTabSheet
        Caption = #1040#1088#1093#1080#1074
        ImageIndex = 2
        OnShow = TabSheet3Show
        object Splitter2: TSplitter
          Left = 185
          Top = 0
          Height = 604
          ExplicitLeft = 328
          ExplicitTop = 208
          ExplicitHeight = 100
        end
        object Panel4: TPanel
          Left = 0
          Top = 0
          Width = 185
          Height = 604
          Align = alLeft
          TabOrder = 0
          object Splitter1: TSplitter
            Left = 1
            Top = 393
            Width = 183
            Height = 3
            Cursor = crVSplit
            Align = alTop
            ExplicitTop = 193
            ExplicitWidth = 300
          end
          object Panel5: TPanel
            Left = 1
            Top = 1
            Width = 183
            Height = 392
            Align = alTop
            TabOrder = 0
            object Label4: TLabel
              Left = 1
              Top = 1
              Width = 181
              Height = 13
              Align = alTop
              Alignment = taCenter
              Caption = #1069#1082#1089#1087#1077#1088#1080#1084#1077#1085#1090#1099' PRI'
              ExplicitWidth = 94
            end
            object ListBox1: TListBox
              AlignWithMargins = True
              Left = 4
              Top = 29
              Width = 175
              Height = 359
              Align = alClient
              ItemHeight = 13
              TabOrder = 0
              OnClick = ListBox1Click
            end
            object Panel15: TPanel
              Left = 1
              Top = 14
              Width = 181
              Height = 12
              Align = alTop
              TabOrder = 1
            end
          end
          object Panel6: TPanel
            Left = 1
            Top = 396
            Width = 183
            Height = 207
            Align = alClient
            TabOrder = 1
            object Label5: TLabel
              Left = 1
              Top = 1
              Width = 181
              Height = 13
              Align = alTop
              Alignment = taCenter
              Caption = #1057#1087#1080#1089#1086#1082' '#1080#1079#1084#1077#1088#1077#1085#1080#1081
              ExplicitWidth = 92
            end
            object ListBox2: TListBox
              AlignWithMargins = True
              Left = 4
              Top = 17
              Width = 175
              Height = 186
              Align = alClient
              ItemHeight = 13
              TabOrder = 0
              OnClick = ListBox2Click
            end
          end
        end
        object Panel7: TPanel
          Left = 188
          Top = 0
          Width = 688
          Height = 604
          Align = alClient
          TabOrder = 1
          object Splitter3: TSplitter
            Left = 1
            Top = 293
            Width = 686
            Height = 3
            Cursor = crVSplit
            Align = alBottom
            ExplicitLeft = -2
            ExplicitTop = 330
          end
          object Panel10: TPanel
            Left = 1
            Top = 1
            Width = 686
            Height = 292
            Align = alClient
            TabOrder = 0
            object Splitter4: TSplitter
              Left = 497
              Top = 1
              Height = 290
              Align = alRight
              ExplicitLeft = 40
              ExplicitTop = 152
              ExplicitHeight = 100
            end
            object Panel12: TPanel
              Left = 500
              Top = 1
              Width = 185
              Height = 290
              Align = alRight
              TabOrder = 0
              object Label6: TLabel
                Left = 1
                Top = 1
                Width = 183
                Height = 13
                Align = alTop
                Alignment = taCenter
                Caption = #1042#1099#1073#1088#1072#1085#1085#1099#1077' '#1086#1073#1083#1072#1089#1090#1080' (ROI)'
                ExplicitWidth = 132
              end
              object Panel14: TPanel
                Left = 1
                Top = 14
                Width = 183
                Height = 11
                Align = alTop
                TabOrder = 0
              end
              object CheckListBox1: TCheckListBox
                AlignWithMargins = True
                Left = 4
                Top = 28
                Width = 177
                Height = 66
                Align = alClient
                ItemHeight = 13
                PopupMenu = PopupMenu1
                TabOrder = 1
                OnClick = CheckListBox1Click
              end
              object Button1: TButton
                AlignWithMargins = True
                Left = 4
                Top = 261
                Width = 177
                Height = 25
                Action = roisCalcAction
                Align = alBottom
                TabOrder = 2
              end
              object Panel16: TPanel
                AlignWithMargins = True
                Left = 4
                Top = 100
                Width = 177
                Height = 155
                Align = alBottom
                BevelOuter = bvNone
                TabOrder = 3
                object Gauge1: TGauge
                  AlignWithMargins = True
                  Left = 3
                  Top = 126
                  Width = 171
                  Height = 26
                  Align = alBottom
                  Progress = 0
                  ExplicitLeft = 2
                  ExplicitTop = 129
                  ExplicitWidth = 100
                end
                object GroupBox3: TGroupBox
                  AlignWithMargins = True
                  Left = 3
                  Top = 3
                  Width = 171
                  Height = 117
                  Align = alClient
                  Caption = #1056#1077#1076#1072#1082#1090#1086#1088' ROI'
                  Enabled = False
                  TabOrder = 0
                  object Label7: TLabel
                    Left = 8
                    Top = 31
                    Width = 17
                    Height = 13
                    Caption = 'x ='
                  end
                  object Label8: TLabel
                    Left = 8
                    Top = 57
                    Width = 20
                    Height = 13
                    Caption = 'y = '
                  end
                  object Label9: TLabel
                    Left = 8
                    Top = 83
                    Width = 18
                    Height = 13
                    Caption = 'r = '
                  end
                  object SpinEdit4: TSpinEdit
                    Left = 31
                    Top = 28
                    Width = 121
                    Height = 22
                    EditorEnabled = False
                    MaxValue = 0
                    MinValue = 0
                    TabOrder = 0
                    Value = 0
                    OnChange = SpinEdit4Change
                  end
                  object SpinEdit5: TSpinEdit
                    Left = 31
                    Top = 53
                    Width = 121
                    Height = 22
                    EditorEnabled = False
                    MaxValue = 0
                    MinValue = 0
                    TabOrder = 1
                    Value = 0
                    OnChange = SpinEdit5Change
                  end
                  object SpinEdit6: TSpinEdit
                    Left = 31
                    Top = 80
                    Width = 121
                    Height = 22
                    EditorEnabled = False
                    MaxValue = 0
                    MinValue = 0
                    TabOrder = 2
                    Value = 0
                    OnChange = SpinEdit6Change
                  end
                end
              end
            end
            object Panel13: TPanel
              Left = 1
              Top = 1
              Width = 496
              Height = 290
              Align = alClient
              TabOrder = 1
              object Panel1: TPanel
                Left = 1
                Top = 1
                Width = 494
                Height = 42
                Align = alTop
                TabOrder = 0
                object SpeedButton1: TSpeedButton
                  Left = 36
                  Top = 4
                  Width = 48
                  Height = 32
                  Action = viewPRI3x3Action
                  AllowAllUp = True
                  GroupIndex = 1
                end
                object SpeedButton2: TSpeedButton
                  Left = 130
                  Top = 4
                  Width = 32
                  Height = 32
                  Action = view531Action
                  AllowAllUp = True
                  GroupIndex = 1
                  Caption = '531'
                end
                object SpeedButton3: TSpeedButton
                  Left = 161
                  Top = 4
                  Width = 32
                  Height = 32
                  Action = view570Action
                  AllowAllUp = True
                  GroupIndex = 1
                  Caption = '570'
                end
                object SpeedButton4: TSpeedButton
                  Left = 192
                  Top = 4
                  Width = 32
                  Height = 32
                  Action = view531fAction
                  AllowAllUp = True
                  GroupIndex = 1
                  Caption = '531f'
                end
                object SpeedButton5: TSpeedButton
                  Left = 223
                  Top = 4
                  Width = 32
                  Height = 32
                  Action = view570fAction
                  AllowAllUp = True
                  GroupIndex = 1
                  Caption = '570f'
                end
                object SpeedButton6: TSpeedButton
                  Left = 4
                  Top = 4
                  Width = 33
                  Height = 32
                  Action = viewPRIAction
                  AllowAllUp = True
                  GroupIndex = 1
                  Down = True
                end
                object SpeedButton7: TSpeedButton
                  Left = 83
                  Top = 4
                  Width = 48
                  Height = 32
                  Action = viewPRI5x5Action
                  AllowAllUp = True
                  GroupIndex = 1
                end
                object SpeedButton8: TSpeedButton
                  Left = 261
                  Top = 4
                  Width = 32
                  Height = 32
                  Action = viewBestFitAction
                  Glyph.Data = {
                    36040000424D3604000000000000360000002800000010000000100000000100
                    2000000000000004000000000000000000000000000000000000FF00FF00FF00
                    FF00FF00FF000000000000FFFF0000FFFF0000FFFF000000000084848400FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF000000000000FFFF0000000000000000000000000084848400FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF000000000000FFFF0000FFFF0000FFFF000000000084848400FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF000000000000FFFF0000FFFF00000000000000000084848400FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF000000000000FFFF0000FFFF0000FFFF000000000084848400FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF000000000000FFFF0000000000000000000000000084848400FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00848484008484
                    8400848484000000000000FFFF0000FFFF0000FFFF0000000000848484008484
                    8400848484008484840084848400848484008484840084848400000000000000
                    0000000000000000000000000000000000000000000000000000000000000000
                    00000000000000000000000000000000000000000000000000000000000000FF
                    FF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FF
                    FF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF0000FFFF000000000000FF
                    FF000000000000FFFF0000FFFF0000FFFF000000000000FFFF0000FFFF0000FF
                    FF000000000000FFFF0000FFFF0000FFFF000000000000FFFF000000000000FF
                    FF000000000000FFFF000000000000FFFF000000000000FFFF000000000000FF
                    FF000000000000FFFF000000000000FFFF000000000000FFFF00000000000000
                    0000000000000000000000000000000000000000000000000000000000000000
                    0000000000000000000000000000000000000000000000000000FF00FF00FF00
                    FF00FF00FF000000000000FFFF0000FFFF0000FFFF000000000084848400FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF000000000000FFFF0000000000000000000000000084848400FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF000000000000FFFF0000FFFF0000FFFF000000000084848400FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF00000000000000000000000000000000000000000084848400FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
                  Layout = blGlyphBottom
                  Spacing = 10
                end
                object SpeedButton9: TSpeedButton
                  Left = 292
                  Top = 4
                  Width = 32
                  Height = 32
                  Action = viewActualSizeAction
                  Glyph.Data = {
                    36040000424D3604000000000000360000002800000010000000100000000100
                    2000000000000004000000000000000000000000000000000000FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF0000000000FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF000000
                    0000FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF000000
                    0000FFFFFF000000000000000000FFFFFF0000000000FF00FF0000000000FFFF
                    FF000000000000000000FFFFFF0000000000FF00FF00FF00FF00FF00FF000000
                    0000FFFFFF000000000000000000FFFFFF0000000000FF00FF0000000000FFFF
                    FF000000000000000000FFFFFF0000000000FF00FF00FF00FF00FF00FF000000
                    0000FFFFFF000000000000000000FFFFFF0000000000FF00FF0000000000FFFF
                    FF000000000000000000FFFFFF0000000000FF00FF00FF00FF00FF00FF000000
                    0000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF0000000000FFFF
                    FF00FFFFFF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00
                    FF0000000000FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF000000
                    0000FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000
                    0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF0000000000FF00FF00FF00FF00FF00FF00FF00
                    FF0000000000000000000000000000000000FF00FF00FF00FF00FF00FF000000
                    0000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
                end
                object SpeedButton10: TSpeedButton
                  Left = 330
                  Top = 4
                  Width = 32
                  Height = 32
                  Action = viewPaneAction
                  GroupIndex = 2
                  Down = True
                  Glyph.Data = {
                    36040000424D3604000000000000360000002800000010000000100000000100
                    2000000000000004000000000000000000000000000000000000FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF00848484008484840084848400848484008484
                    8400848484008484840084848400FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF008484840084848400848484008484
                    84008484840084848400FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF008484840084848400848484008484
                    84008484840084848400FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF008484840084848400848484008484
                    84008484840084848400FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF00848484008484840084848400848484008484
                    8400848484008484840084848400FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF0084848400848484008484840084848400848484008484
                    8400848484008484840084848400FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF008484840084848400848484008484840084848400848484008484
                    840084848400848484008484840084848400FF00FF00FF00FF00FF00FF00FF00
                    FF00848484008484840084848400848484008484840084848400848484008484
                    840084848400848484008484840084848400FF00FF00FF00FF00FF00FF008484
                    84008484840084848400FF00FF00848484008484840084848400848484008484
                    840084848400848484008484840084848400FF00FF00FF00FF00FF00FF008484
                    840084848400FF00FF00FF00FF00848484008484840084848400848484008484
                    84008484840084848400848484008484840084848400FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF00848484008484840084848400848484008484
                    84008484840084848400FF00FF008484840084848400FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF008484840084848400FF00FF008484840084848400FF00
                    FF008484840084848400FF00FF008484840084848400FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF008484840084848400FF00FF008484840084848400FF00
                    FF008484840084848400FF00FF00FF00FF0084848400FF00FF00FF00FF00FF00
                    FF00FF00FF008484840084848400FF00FF00FF00FF008484840084848400FF00
                    FF008484840084848400FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF008484840084848400FF00FF00FF00FF008484840084848400FF00
                    FF008484840084848400FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF008484840084848400FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
                end
                object SpeedButton11: TSpeedButton
                  Left = 361
                  Top = 4
                  Width = 32
                  Height = 32
                  Action = viewZoomAction
                  GroupIndex = 2
                  Glyph.Data = {
                    36040000424D3604000000000000360000002800000010000000100000000100
                    2000000000000004000000000000000000000000000000000000FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF008484000084000000C6C6C600FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF0084840000C6C6C600FF00000084848400FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF0084840000C6C6C600FF00000084000000FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF0084840000C6C6C600FF00000084000000FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF008484
                    8400C6C6C600FF00000084000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF00C6C6C6008484840000000000000000008484840084848400FF00
                    FF008484840084000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00C6C6C600C6C6C60084848400848400008484000084840000000000000000
                    000084848400FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00C6C6
                    C600C6C6C60084840000FFFF0000C6C6C600C6C6C600C6C6C600C6C6C6008484
                    000084848400FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF0084840000FFFF0000C6C6C600FF00FF00C6C6C600C6C6C600C6C6C600FFFF
                    000084848400FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00C6C6C600C6C6
                    C60084840000C6C6C600FF00FF00FF00FF00C6C6C600C6C6C600C6C6C600FFFF
                    000084848400FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00C6C6C6008484
                    8400FFFF0000FF00FF00FF00FF00C6C6C600C6C6C600C6C6C600C6C6C600FFFF
                    000084848400FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00C6C6C6008484
                    8400FFFF0000FF00FF00FF00FF00C6C6C600C6C6C600C6C6C600C6C6C600C6C6
                    C60084848400FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF000000
                    0000FFFF0000C6C6C600FF00FF00C6C6C600C6C6C600C6C6C600C6C6C600FF00
                    FF0084848400FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF0000000000FFFF0000C6C6C600C6C6C600FFFF000084848400C6C6C6008484
                    8400FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00C6C6C600000000008484000084840000848484008484840084848400FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
                    FF00FF00FF00FF00FF00848484008484840084848400C6C6C600FF00FF00FF00
                    FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
                end
                object SpeedButton12: TSpeedButton
                  Left = 392
                  Top = 4
                  Width = 32
                  Height = 32
                  Action = viewEditRoiAction
                  GroupIndex = 2
                  Glyph.Data = {
                    76030000424D7603000000000000360000002800000011000000100000000100
                    1800000000004003000000000000000000000000000000000000F800F8F800F8
                    F800F8F800F8F800F8F800F8F800F8F800F8F800F8F800F8F800F8F800F8F800
                    F8000000F800F8F800F8F800F800F800F8000000000000F800F8000000000000
                    F800F8000000000000F800F8000000F800F8000000F8F8F8000000F800F8F800
                    F800F800F8000000000000F800F8000000000000F800F8000000000000F800F8
                    000000000000F8F8F8F8F8F8F8F8F8F800F8F800F800F800F8F800F8F800F8F8
                    00F8F800F8F800F8F800F8F800F8F800F8F800F8000000F8F8F8F8F8F8F8F8F8
                    000000F800F8F800F800F800F8000000000000F800F8F800F8F800F8F800F8F8
                    00F8F800F8F800F8000000F8F8F8F8F8F8000000F800F8F800F800000000F800
                    F8000000000000F800F8F800F8F800F8F800F8F800F8F800F8F800F800000000
                    0000000000000000000000F800F8F800F800F800F8F800F8F800F8F800F8F800
                    F8F800F8F800F8F800F8F800F8F800F8F800F8F800F8F800F8F800F8F800F8F8
                    00F8F800F800F800F8000000000000F800F8F800F8F800F8F800F8F800F8F800
                    F8F800F8F800F8F800F8F800F8000000000000F800F8F800F800F800F8000000
                    000000F800F8F800F8F800F8F800F8F800F8F800F8F800F8F800F8F800F8F800
                    F8000000000000F800F8F800F800F800F8F800F8F800F8F800F8F800F8F800F8
                    F800F8F800F8F800F8F800F8F800F8F800F8F800F8F800F8F800F8F800F8F800
                    F800F800F8000000000000F800F8F800F8F800F8F800F8F800F8F800F8F800F8
                    F800F8F800F8F800F8000000000000F800F8F800F800F800F8000000000000F8
                    00F8F800F8F800F8F800F8F800F8F800F8F800F8F800F8F800F8F800F8000000
                    000000F800F8F800F800F800F8F800F8F800F8F800F8F800F8F800F8F800F8F8
                    00F8F800F8F800F8F800F8F800F8F800F8F800F8F800F8F800F8F800F800F800
                    F8000000000000F800F8000000000000F800F8000000000000F800F800000000
                    0000F800F8000000000000F800F8F800F800F800F8000000000000F800F80000
                    00000000F800F8000000000000F800F8000000000000F800F8000000000000F8
                    00F8F800F800F800F8F800F8F800F8F800F8F800F8F800F8F800F8F800F8F800
                    F8F800F8F800F8F800F8F800F8F800F8F800F8F800F8F800F800}
                end
                object SpeedButton13: TSpeedButton
                  Left = 430
                  Top = 4
                  Width = 59
                  Height = 32
                  AllowAllUp = True
                  GroupIndex = 8
                  Caption = #1050#1072#1083#1080#1073#1088'.'
                  OnClick = SpeedButton13Click
                end
              end
              object PhImage4: TPhImage
                Left = 1
                Top = 43
                Width = 494
                Height = 227
                AutoMosaic = True
                ThumbWidht = 128
                ThumbHeight = 128
                SlideShowInterval = 500
                Align = alClient
                ParentColor = False
                OnMouseMove = PhImage4MouseMove
                OnPaint = PhImage4Paint
                OnScaleChange = PhImage4ScaleChange
                OnToolChange = PhImage4ToolChange
              end
              object StatusBar1: TStatusBar
                Left = 1
                Top = 270
                Width = 494
                Height = 19
                Panels = <
                  item
                    Alignment = taCenter
                    Width = 150
                  end
                  item
                    Alignment = taCenter
                    Width = 100
                  end
                  item
                    Width = 50
                  end>
              end
            end
          end
          object Panel11: TPanel
            Left = 1
            Top = 296
            Width = 686
            Height = 307
            Align = alBottom
            TabOrder = 1
            object PageControl3: TPageControl
              Left = 1
              Top = 1
              Width = 684
              Height = 305
              ActivePage = TabSheet9
              Align = alClient
              TabOrder = 0
              object TabSheet8: TTabSheet
                Caption = #1043#1088#1072#1092#1080#1082
                object StatusBar2: TStatusBar
                  Left = 0
                  Top = 258
                  Width = 676
                  Height = 19
                  Panels = <>
                end
                object Chart1: TChart
                  Left = 0
                  Top = 0
                  Width = 676
                  Height = 258
                  Legend.Visible = False
                  Title.Text.Strings = (
                    'TChart')
                  View3D = False
                  Align = alClient
                  TabOrder = 1
                  DefaultCanvas = 'TGDIPlusCanvas'
                  ColorPaletteIndex = 13
                  object Series1: TLineSeries
                    Brush.BackColor = clDefault
                    LinePen.Width = 2
                    Pointer.InflateMargins = True
                    Pointer.Style = psRectangle
                    XValues.Name = 'X'
                    XValues.Order = loAscending
                    YValues.Name = 'Y'
                    YValues.Order = loNone
                  end
                  object Series2: TLineSeries
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
              object TabSheet9: TTabSheet
                Caption = #1058#1072#1073#1083#1080#1094#1072
                ImageIndex = 1
                object StringGrid1: TStringGrid
                  Left = 0
                  Top = 0
                  Width = 676
                  Height = 277
                  Align = alClient
                  TabOrder = 0
                end
              end
            end
          end
        end
      end
    end
  end
  object MainMenu1: TMainMenu
    Left = 208
    Top = 80
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083#1099
      object N13: TMenuItem
        Action = fileExportTableAction
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1090#1072#1073#1083#1080#1094#1091'...'
      end
      object N14: TMenuItem
        Action = fileExportImageAction
      end
      object N41: TMenuItem
        Action = fileExportDataAction
      end
      object PRI2: TMenuItem
        Action = fileExportPRIAction
      end
      object N25: TMenuItem
        Caption = '-'
      end
      object N24: TMenuItem
        Action = filePrintAction
      end
      object N12: TMenuItem
        Caption = '-'
      end
      object N2: TMenuItem
        Action = fileCloseAction
      end
    end
    object N4: TMenuItem
      Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077
      object N16: TMenuItem
        Action = editCopyImageAction
      end
      object N17: TMenuItem
        Action = editCopyChartAction
      end
      object N18: TMenuItem
        Action = editCopyTableAction
      end
    end
    object N15: TMenuItem
      Caption = #1042#1080#1079#1091#1072#1083#1080#1079#1072#1094#1080#1103
      object N19: TMenuItem
        Action = viewBestFitAction
      end
      object N20: TMenuItem
        Action = viewActualSizeAction
      end
      object N21: TMenuItem
        Caption = '-'
      end
      object PRI1: TMenuItem
        Action = viewPRIAction
        Caption = #1042#1080#1079#1091#1072#1083#1080#1079#1072#1094#1080#1103' PRI 1'#1093'1'
      end
      object PRI3x31: TMenuItem
        Action = viewPRI3x3Action
        Caption = #1042#1080#1079#1091#1072#1083#1080#1079#1072#1094#1080#1103' PRI 3'#1093'3 '
      end
      object viewPRI5x5Action1: TMenuItem
        Action = viewPRI5x5Action
        Caption = #1042#1080#1079#1091#1072#1083#1080#1079#1072#1094#1080#1103' PRI 5x5'
      end
      object N22: TMenuItem
        Caption = '-'
      end
      object view531Action1: TMenuItem
        Action = view531Action
        Caption = #1048#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077' 531 nm '
      end
      object view531fAction1: TMenuItem
        Action = view531fAction
        Caption = #1048#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077' '#1092#1086#1085#1072' 531 nm '
      end
      object view570Action1: TMenuItem
        Action = view570Action
        Caption = #1048#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077' 570 nm '
      end
      object view570fAction1: TMenuItem
        Action = view570fAction
        Caption = #1048#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077' '#1092#1086#1085#1072' 570 nm '
      end
      object N23: TMenuItem
        Caption = '-'
      end
      object N26: TMenuItem
        Action = viewEditRoiAction
      end
      object N27: TMenuItem
        Action = viewZoomAction
      end
      object ROI1: TMenuItem
        Action = viewEditRoiAction
      end
      object N43: TMenuItem
        Caption = '-'
      end
      object N44: TMenuItem
        Action = viewBrightnessCalibrationAction
      end
      object N45: TMenuItem
        Action = viewSpatialCalibrationAction
      end
    end
    object N28: TMenuItem
      Caption = #1054#1073#1083#1072#1089#1090#1080
      object ROI3: TMenuItem
        Action = roisDeleteAction
      end
      object N30: TMenuItem
        Action = roisClearAction
      end
      object N31: TMenuItem
        Caption = '-'
      end
      object N32: TMenuItem
        Action = roisCalcAction
      end
      object N33: TMenuItem
        Caption = '-'
      end
      object N39: TMenuItem
        Action = roiViewAverageAction
      end
      object N40: TMenuItem
        Action = roiViewStddevAction
      end
    end
    object N3: TMenuItem
      Caption = #1055#1088#1080#1073#1086#1088
      object N7: TMenuItem
        Action = deviceCalibrationAction
      end
      object N42: TMenuItem
        Action = deviceSpatialCalibrationAction
      end
      object N8: TMenuItem
        Action = deviceExperimentAction
      end
    end
    object N5: TMenuItem
      Caption = #1048#1085#1089#1090#1088#1091#1084#1077#1085#1090#1099
      object N9: TMenuItem
        Action = toolsOptionsAction
      end
    end
    object N6: TMenuItem
      Caption = #1055#1086#1084#1086#1097#1100
      object N10: TMenuItem
        Action = helpContestsAction
      end
      object N11: TMenuItem
        Action = helpAboutAction
      end
    end
  end
  object ActionList1: TActionList
    Left = 264
    Top = 80
    object fileCloseAction: TAction
      Category = 'File'
      Caption = #1047#1072#1074#1077#1088#1096#1077#1085#1080#1077' '#1088#1072#1073#1086#1090#1099
      OnExecute = fileCloseActionExecute
    end
    object deviceCalibrationAction: TAction
      Category = 'Device'
      Caption = #1071#1088#1082#1086#1089#1090#1085#1072#1103' '#1082#1072#1083#1080#1073#1088#1086#1074#1082#1072'...'
      OnExecute = deviceCalibrationActionExecute
      OnUpdate = deviceCalibrationActionUpdate
    end
    object deviceExperimentAction: TAction
      Category = 'Device'
      Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100' '#1080#1079#1084#1077#1088#1077#1085#1080#1077'... '
      OnExecute = deviceExperimentActionExecute
      OnUpdate = deviceExperimentActionUpdate
    end
    object toolsOptionsAction: TAction
      Category = 'tools'
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072'...'
      OnExecute = toolsOptionsActionExecute
    end
    object helpAboutAction: TAction
      Category = 'help'
      Caption = #1054' '#1055#1088#1086#1075#1088#1072#1084#1084#1077'... '
      OnExecute = helpAboutActionExecute
    end
    object helpContestsAction: TAction
      Category = 'help'
      Caption = #1044#1086#1082#1091#1084#1077#1085#1090#1072#1094#1080#1103'... '
      OnExecute = helpContestsActionExecute
    end
    object viewPRIAction: TAction
      Category = 'View'
      Caption = 'PRI '
      Checked = True
      GroupIndex = 1
      OnExecute = viewPRIActionExecute
      OnUpdate = viewPRIActionUpdate
    end
    object view531Action: TAction
      Category = 'View'
      Caption = 'view531Action'
      GroupIndex = 1
      OnExecute = view531ActionExecute
      OnUpdate = view531ActionUpdate
    end
    object view570Action: TAction
      Category = 'View'
      Caption = 'view570Action'
      GroupIndex = 1
      OnExecute = view570ActionExecute
      OnUpdate = view570ActionUpdate
    end
    object view531fAction: TAction
      Category = 'View'
      Caption = 'view531fAction'
      GroupIndex = 1
      OnExecute = view531fActionExecute
      OnUpdate = view531fActionUpdate
    end
    object view570fAction: TAction
      Category = 'View'
      Caption = 'view570fAction'
      GroupIndex = 1
      OnExecute = view570fActionExecute
      OnUpdate = view570fActionUpdate
    end
    object fileExportTableAction: TAction
      Category = 'File'
      Caption = #1069#1082#1087#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100' '#1090#1072#1073#1083#1080#1094#1091'...'
      OnExecute = fileExportTableActionExecute
      OnUpdate = fileExportTableActionUpdate
    end
    object fileExportImageAction: TAction
      Category = 'File'
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077'... '
      OnExecute = fileExportImageActionExecute
      OnUpdate = fileExportImageActionUpdate
    end
    object filePrintAction: TAction
      Category = 'File'
      Caption = #1056#1072#1089#1087#1077#1095#1072#1090#1072#1090#1100' '#1075#1088#1072#1092#1080#1082'... '
      OnExecute = filePrintActionExecute
      OnUpdate = filePrintActionUpdate
    end
    object editCopyImageAction: TAction
      Category = 'Edit'
      Caption = #1057#1082#1086#1087#1080#1088#1086#1074#1072#1090#1100' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077
      OnExecute = editCopyImageActionExecute
      OnUpdate = editCopyImageActionUpdate
    end
    object editCopyChartAction: TAction
      Category = 'Edit'
      Caption = #1057#1082#1086#1087#1080#1088#1086#1074#1072#1090#1100' '#1075#1088#1072#1092#1080#1082
      OnExecute = editCopyChartActionExecute
      OnUpdate = editCopyChartActionUpdate
    end
    object editCopyTableAction: TAction
      Category = 'Edit'
      Caption = #1057#1082#1086#1087#1080#1088#1086#1074#1072#1090#1100' '#1090#1072#1073#1083#1080#1094#1091
      OnExecute = editCopyTableActionExecute
      OnUpdate = editCopyTableActionUpdate
    end
    object viewBestFitAction: TAction
      Category = 'View'
      Caption = #1042#1087#1080#1089#1072#1090#1100' '#1074' '#1086#1082#1085#1086
      OnExecute = viewBestFitActionExecute
      OnUpdate = viewBestFitActionUpdate
    end
    object viewActualSizeAction: TAction
      Category = 'View'
      Caption = #1048#1089#1093#1086#1076#1085#1099#1081' '#1088#1072#1079#1084#1077#1088
      OnExecute = viewActualSizeActionExecute
      OnUpdate = viewActualSizeActionUpdate
    end
    object viewPRI3x3Action: TAction
      Category = 'View'
      Caption = 'PRI 3x3'
      GroupIndex = 1
      OnExecute = viewPRI3x3ActionExecute
      OnUpdate = viewPRI3x3ActionUpdate
    end
    object viewPRI5x5Action: TAction
      Category = 'View'
      Caption = 'PRI 5x5'
      GroupIndex = 1
      OnExecute = viewPRI5x5ActionExecute
      OnUpdate = viewPRI5x5ActionUpdate
    end
    object viewPaneAction: TAction
      Category = 'View'
      Caption = #1055#1077#1088#1077#1090#1072#1089#1082#1080#1074#1072#1085#1080#1077
      GroupIndex = 2
      OnExecute = viewPaneActionExecute
      OnUpdate = viewPaneActionUpdate
    end
    object viewZoomAction: TAction
      Category = 'View'
      Caption = #1059#1074#1077#1083#1080#1095#1077#1085#1080#1077
      GroupIndex = 2
      OnExecute = viewZoomActionExecute
      OnUpdate = viewZoomActionUpdate
    end
    object viewEditRoiAction: TAction
      Category = 'View'
      Caption = #1056#1077#1076#1072#1082#1090#1086#1088' ROI'
      GroupIndex = 2
      OnExecute = viewEditRoiActionExecute
      OnUpdate = viewEditRoiActionUpdate
    end
    object roisDeleteAction: TAction
      Category = 'rois'
      Caption = #1059#1076#1072#1083#1080#1090#1100' ROI'
      OnExecute = roisDeleteActionExecute
      OnUpdate = roisDeleteActionUpdate
    end
    object roisClearAction: TAction
      Category = 'rois'
      Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1074#1089#1077
      OnExecute = roisClearActionExecute
      OnUpdate = roisClearActionUpdate
    end
    object roisCalcAction: TAction
      Category = 'rois'
      Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100' '#1088#1072#1089#1095#1077#1090
      OnExecute = roisCalcActionExecute
      OnUpdate = roisCalcActionUpdate
    end
    object roiViewAverageAction: TAction
      Category = 'rois'
      Caption = #1054#1090#1086#1073#1088#1072#1078#1072#1090#1100' '#1089#1088#1077#1076#1085#1077#1077
      Checked = True
      GroupIndex = 4
      OnExecute = roiViewAverageActionExecute
      OnUpdate = roiViewAverageActionUpdate
    end
    object roiViewStddevAction: TAction
      Category = 'rois'
      Caption = #1054#1090#1086#1073#1088#1072#1078#1072#1090#1100' '#1089#1090#1085#1076#1072#1088#1090#1085#1086#1077' '#1086#1090#1082#1083#1086#1085#1077#1085#1080#1077
      GroupIndex = 4
      OnExecute = roiViewStddevActionExecute
      OnUpdate = roiViewStddevActionUpdate
    end
    object deviceSpatialCalibration: TAction
      Category = 'Device'
      Caption = 'deviceSpatialCalibration'
      OnExecute = deviceSpatialCalibrationExecute
      OnUpdate = deviceSpatialCalibrationUpdate
    end
    object fileExportDataAction: TAction
      Category = 'File'
      Caption = #1069#1082#1089#1087#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100' '#1076#1072#1085#1085#1099#1077'... '
      OnExecute = fileExportDataActionExecute
      OnUpdate = fileExportDataActionUpdate
    end
    object fileExportPRIAction: TAction
      Category = 'File'
      Caption = #1069#1082#1089#1087#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100' PRI...'
      OnExecute = fileExportPRIActionExecute
      OnUpdate = fileExportPRIActionUpdate
    end
    object deviceSpatialCalibrationAction: TAction
      Category = 'Device'
      Caption = #1055#1088#1086#1089#1090#1088#1072#1085#1089#1090#1074#1077#1085#1085#1072#1103' '#1082#1072#1083#1080#1073#1088#1086#1074#1082#1072'...'
      OnExecute = deviceSpatialCalibrationActionExecute
      OnUpdate = deviceSpatialCalibrationActionUpdate
    end
    object viewBrightnessCalibrationAction: TAction
      Category = 'View'
      Caption = #1071#1088#1082#1086#1089#1090#1085#1072#1103' '#1082#1072#1083#1080#1073#1088#1086#1074#1082#1072' '
      OnExecute = viewBrightnessCalibrationActionExecute
      OnUpdate = viewBrightnessCalibrationActionUpdate
    end
    object viewSpatialCalibrationAction: TAction
      Category = 'View'
      Caption = #1055#1088#1086#1089#1090#1088#1072#1085#1089#1090#1074#1077#1085#1085#1072#1103' '#1082#1072#1083#1080#1073#1088#1086#1074#1082#1072
      OnExecute = viewSpatialCalibrationActionExecute
      OnUpdate = viewSpatialCalibrationActionUpdate
    end
  end
  object PhPaneTool1: TPhPaneTool
    PhImage = PhImage4
    Left = 211
    Top = 278
  end
  object PhZoomToRectTool1: TPhZoomToRectTool
    PhImage = PhImage4
    Left = 275
    Top = 278
  end
  object PopupMenu1: TPopupMenu
    Left = 726
    Top = 99
    object ROI2: TMenuItem
      Action = roisDeleteAction
    end
    object N29: TMenuItem
      Action = roisClearAction
    end
    object N34: TMenuItem
      Caption = '-'
    end
    object N35: TMenuItem
      Action = roisCalcAction
    end
    object N36: TMenuItem
      Caption = '-'
    end
    object N37: TMenuItem
      Action = roiViewAverageAction
    end
    object N38: TMenuItem
      Action = roiViewStddevAction
    end
  end
  object SaveDialog1: TSaveDialog
    Filter = #1058#1077#1082#1089#1090#1086#1074#1099#1077' '#1092#1072#1081#1083#1099'|*.txt'
    Left = 211
    Top = 139
  end
  object SaveDialog2: TSaveDialog
    Filter = #1060#1072#1081#1083#1099' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1081'|*.jpg'
    Left = 211
    Top = 195
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 267
    Top = 147
  end
end
