object PagesDlg: TPagesDlg
  Left = 527
  Top = 121
  BorderStyle = bsDialog
  Caption = 'Tabbed Notebook Dialog'
  ClientHeight = 308
  ClientWidth = 417
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 417
    Height = 274
    Align = alClient
    BevelOuter = bvNone
    BorderWidth = 5
    ParentColor = True
    TabOrder = 0
    object PageControl1: TPageControl
      Left = 5
      Top = 5
      Width = 407
      Height = 264
      ActivePage = TabSheet3
      Align = alClient
      TabOrder = 0
      object Scanner: TTabSheet
        Caption = 'Internal Scanner'
        OnShow = ScannerShow
        object Label5: TLabel
          Left = 16
          Top = 20
          Width = 54
          Height = 13
          Caption = 'Base Width'
        end
        object Label6: TLabel
          Left = 16
          Top = 48
          Width = 57
          Height = 13
          Caption = 'Base Height'
        end
        object GroupBox2: TGroupBox
          Left = 208
          Top = 92
          Width = 185
          Height = 89
          Caption = ' Image Size '
          TabOrder = 0
          object Label1: TLabel
            Left = 8
            Top = 28
            Width = 28
            Height = 13
            Caption = 'Width'
          end
          object Label2: TLabel
            Left = 8
            Top = 58
            Width = 31
            Height = 13
            Caption = 'Height'
          end
          object CSpinEdit1: TCSpinEdit
            Left = 48
            Top = 24
            Width = 121
            Height = 22
            MaxValue = 640
            MinValue = 80
            TabOrder = 0
            Value = 320
          end
          object CSpinEdit2: TCSpinEdit
            Left = 48
            Top = 56
            Width = 121
            Height = 22
            MaxValue = 480
            MinValue = 60
            TabOrder = 1
            Value = 240
          end
        end
        object GroupBox3: TGroupBox
          Left = 208
          Top = 184
          Width = 185
          Height = 41
          Caption = ' Fragments Count '
          TabOrder = 1
          object Label3: TLabel
            Left = 76
            Top = 16
            Width = 31
            Height = 13
            Caption = 'xxxxx'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
        end
        object ValueListEditor1: TValueListEditor
          Left = 8
          Top = 96
          Width = 193
          Height = 128
          GridLineWidth = 0
          TabOrder = 2
          ColWidths = (
            89
            98)
        end
        object Edit2: TEdit
          Left = 88
          Top = 16
          Width = 105
          Height = 21
          TabOrder = 3
          Text = '24'
          OnExit = Edit2Exit
        end
        object Edit3: TEdit
          Left = 88
          Top = 48
          Width = 105
          Height = 21
          TabOrder = 4
          Text = '24'
          OnExit = Edit3Exit
        end
      end
      object TabSheet2: TTabSheet
        Caption = 'Object detector'
        object ValueListEditor2: TValueListEditor
          Left = 9
          Top = 91
          Width = 193
          Height = 86
          GridLineWidth = 0
          TabOrder = 0
          ColWidths = (
            89
            98)
        end
        object GroupBox4: TGroupBox
          Left = 208
          Top = 184
          Width = 185
          Height = 41
          Caption = ' Fragments Count '
          TabOrder = 1
          object Label4: TLabel
            Left = 76
            Top = 16
            Width = 31
            Height = 13
            Caption = 'xxxxx'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -11
            Font.Name = 'MS Sans Serif'
            Font.Style = [fsBold]
            ParentFont = False
          end
        end
        object GroupBox5: TGroupBox
          Left = 208
          Top = 8
          Width = 185
          Height = 105
          Caption = 'Engine'
          TabOrder = 2
          object Label11: TLabel
            Left = 9
            Top = 64
            Width = 61
            Height = 13
            Caption = 'Image Width'
          end
          object Label7: TLabel
            Left = 9
            Top = 84
            Width = 91
            Height = 13
            Caption = 'Image Height (4:3)'
          end
          object Label10: TLabel
            Left = 104
            Top = 84
            Width = 30
            Height = 13
            Caption = 'xxxxx'
          end
          object CheckBox2: TCheckBox
            Left = 8
            Top = 16
            Width = 137
            Height = 17
            Caption = 'Cluster overlaped results'
            TabOrder = 0
          end
          object CheckBox3: TCheckBox
            Left = 8
            Top = 40
            Width = 161
            Height = 17
            Caption = 'Resize image when detect '
            TabOrder = 1
            OnClick = CheckBox3Click
          end
          object Edit4: TEdit
            Left = 72
            Top = 61
            Width = 81
            Height = 21
            TabOrder = 2
            Text = '320'
            OnExit = Edit4Exit
          end
        end
        object GroupBox6: TGroupBox
          Left = 8
          Top = 8
          Width = 193
          Height = 77
          Caption = 'Scanner'
          TabOrder = 3
          object Label8: TLabel
            Left = 8
            Top = 24
            Width = 83
            Height = 13
            Caption = 'Base Width = 24 '
          end
          object Label9: TLabel
            Left = 8
            Top = 43
            Width = 86
            Height = 13
            Caption = 'Base Height =  24'
          end
        end
        object GroupBox7: TGroupBox
          Left = 208
          Top = 120
          Width = 185
          Height = 57
          Caption = 'Detector'
          TabOrder = 4
          object CheckBox4: TCheckBox
            Left = 8
            Top = 24
            Width = 153
            Height = 17
            Caption = 'Tilt image when detect'
            TabOrder = 0
            OnClick = CheckBox4Click
          end
        end
        object GroupBox8: TGroupBox
          Left = 9
          Top = 183
          Width = 193
          Height = 43
          Caption = ' Mode '
          TabOrder = 5
          object CheckBox5: TCheckBox
            Left = 7
            Top = 16
            Width = 153
            Height = 17
            Caption = 'Detect  in rect '
            TabOrder = 0
            OnClick = CheckBox4Click
          end
        end
      end
      object TabSheet1: TTabSheet
        Caption = 'Overlaps'
        ImageIndex = 2
        object GroupBox1: TGroupBox
          Left = 3
          Top = 3
          Width = 185
          Height = 230
          Caption = 'Scanner Overlaps '
          TabOrder = 0
          object Label12: TLabel
            Left = 8
            Top = 24
            Width = 132
            Height = 13
            Caption = 'Nearlest overlaps threshold'
          end
          object Label13: TLabel
            Left = 8
            Top = 98
            Width = 133
            Height = 13
            Caption = 'Farthest overlaps threholds'
          end
          object Edit1: TEdit
            Left = 8
            Top = 40
            Width = 164
            Height = 21
            TabOrder = 0
            Text = '0,7'
          end
          object CheckBox1: TCheckBox
            Left = 8
            Top = 67
            Width = 169
            Height = 17
            Caption = 'Nearlest overlaps'
            TabOrder = 1
          end
          object LabeledEdit1: TLabeledEdit
            Left = 8
            Top = 133
            Width = 121
            Height = 21
            EditLabel.Width = 45
            EditLabel.Height = 13
            EditLabel.Caption = 'min value'
            TabOrder = 2
            Text = '0,4'
          end
          object LabeledEdit2: TLabeledEdit
            Left = 8
            Top = 176
            Width = 121
            Height = 21
            EditLabel.Width = 49
            EditLabel.Height = 13
            EditLabel.Caption = 'max value'
            TabOrder = 3
            Text = '0,6'
          end
        end
      end
      object TabSheet3: TTabSheet
        Caption = 'TabSheet3'
        ImageIndex = 3
        object Button1: TButton
          Left = 312
          Top = 40
          Width = 75
          Height = 25
          Caption = 'Button1'
          TabOrder = 0
          OnClick = Button1Click
        end
        object Button2: TButton
          Left = 312
          Top = 72
          Width = 75
          Height = 25
          Caption = 'Button2'
          TabOrder = 1
          OnClick = Button2Click
        end
        object Chart1: TChart
          Left = 3
          Top = 17
          Width = 288
          Height = 182
          BackWall.Brush.Gradient.Direction = gdBottomTop
          BackWall.Brush.Gradient.EndColor = clWhite
          BackWall.Brush.Gradient.StartColor = 15395562
          BackWall.Brush.Gradient.Visible = True
          BackWall.Transparent = False
          Foot.Font.Color = clBlue
          Foot.Font.Name = 'Verdana'
          Gradient.Direction = gdBottomTop
          Gradient.EndColor = clWhite
          Gradient.MidColor = 15395562
          Gradient.StartColor = 15395562
          Gradient.Visible = True
          LeftWall.Color = 14745599
          Legend.Font.Name = 'Verdana'
          Legend.Shadow.Transparency = 0
          RightWall.Color = 14745599
          Title.Font.Name = 'Verdana'
          Title.Text.Strings = (
            'TChart')
          BottomAxis.Axis.Color = 4210752
          BottomAxis.Grid.Color = 11119017
          BottomAxis.LabelsFormat.Font.Name = 'Verdana'
          BottomAxis.TicksInner.Color = 11119017
          BottomAxis.Title.Font.Name = 'Verdana'
          DepthAxis.Axis.Color = 4210752
          DepthAxis.Grid.Color = 11119017
          DepthAxis.LabelsFormat.Font.Name = 'Verdana'
          DepthAxis.TicksInner.Color = 11119017
          DepthAxis.Title.Font.Name = 'Verdana'
          DepthTopAxis.Axis.Color = 4210752
          DepthTopAxis.Grid.Color = 11119017
          DepthTopAxis.LabelsFormat.Font.Name = 'Verdana'
          DepthTopAxis.TicksInner.Color = 11119017
          DepthTopAxis.Title.Font.Name = 'Verdana'
          LeftAxis.Axis.Color = 4210752
          LeftAxis.Grid.Color = 11119017
          LeftAxis.LabelsFormat.Font.Name = 'Verdana'
          LeftAxis.TicksInner.Color = 11119017
          LeftAxis.Title.Font.Name = 'Verdana'
          RightAxis.Axis.Color = 4210752
          RightAxis.Grid.Color = 11119017
          RightAxis.LabelsFormat.Font.Name = 'Verdana'
          RightAxis.TicksInner.Color = 11119017
          RightAxis.Title.Font.Name = 'Verdana'
          TopAxis.Axis.Color = 4210752
          TopAxis.Grid.Color = 11119017
          TopAxis.LabelsFormat.Font.Name = 'Verdana'
          TopAxis.TicksInner.Color = 11119017
          TopAxis.Title.Font.Name = 'Verdana'
          TabOrder = 2
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
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 274
    Width = 417
    Height = 34
    Align = alBottom
    BevelOuter = bvNone
    ParentColor = True
    TabOrder = 1
    object OKBtn: TButton
      Left = 241
      Top = 2
      Width = 75
      Height = 25
      Caption = 'OK'
      Default = True
      ModalResult = 1
      TabOrder = 0
    end
    object CancelBtn: TButton
      Left = 321
      Top = 2
      Width = 75
      Height = 25
      Cancel = True
      Caption = 'Cancel'
      ModalResult = 2
      TabOrder = 1
    end
  end
end
