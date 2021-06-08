object pam2ExperimentForm: Tpam2ExperimentForm
  Left = 0
  Top = 0
  BorderStyle = bsToolWindow
  Caption = #1069#1082#1089#1087#1077#1088#1080#1084#1077#1085#1090
  ClientHeight = 277
  ClientWidth = 217
  Color = clBtnFace
  DragMode = dmAutomatic
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
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 217
    Height = 258
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    object Gauge1: TGauge
      AlignWithMargins = True
      Left = 3
      Top = 233
      Width = 211
      Height = 22
      Align = alBottom
      BackColor = clBlack
      BorderStyle = bsNone
      ForeColor = clBlue
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      Progress = 25
      ExplicitTop = 264
    end
    object Button1: TButton
      AlignWithMargins = True
      Left = 3
      Top = 191
      Width = 211
      Height = 36
      Action = pamMainForm.toolsStopExperimentAction
      Align = alBottom
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      AlignWithMargins = True
      Left = 3
      Top = 151
      Width = 211
      Height = 34
      Action = pamMainForm.toolsStartExperimetAction
      Align = alBottom
      TabOrder = 1
    end
    object GroupBox1: TGroupBox
      AlignWithMargins = True
      Left = 3
      Top = 3
      Width = 211
      Height = 69
      Align = alTop
      Caption = #1063#1080#1089#1083#1086' '#1080#1079#1084#1077#1088#1080#1090#1077#1083#1100#1085#1099#1093' '#1074#1089#1087#1099#1096#1077#1082
      TabOrder = 2
      object PhTrackBar1: TPhTrackBar
        AlignWithMargins = True
        Left = 5
        Top = 18
        Width = 131
        Height = 46
        Align = alClient
        Max = 256
        Min = 10
        Frequency = 25
        Position = 20
        ShowSelRange = False
        TabOrder = 0
        TickMarks = tmBoth
        OnChange = PhTrackBar1Change
        OnMouseUp = PhTrackBar1MouseUp
      end
      object Panel2: TPanel
        Left = 139
        Top = 15
        Width = 70
        Height = 52
        Align = alRight
        BevelOuter = bvNone
        TabOrder = 1
        object SpinEdit3: TSpinEdit
          Left = 6
          Top = 16
          Width = 53
          Height = 22
          MaxValue = 256
          MinValue = 10
          TabOrder = 0
          Value = 20
          OnChange = SpinEdit3Change
        end
      end
    end
    object GroupBox2: TGroupBox
      AlignWithMargins = True
      Left = 3
      Top = 78
      Width = 211
      Height = 69
      Align = alTop
      Caption = #1057#1082#1074#1072#1078#1085#1086#1089#1090#1100' ('#1089#1077#1082')'
      TabOrder = 3
      object PhTrackBar2: TPhTrackBar
        AlignWithMargins = True
        Left = 5
        Top = 18
        Width = 131
        Height = 46
        Align = alClient
        Max = 30
        Min = 2
        Frequency = 5
        Position = 2
        ShowSelRange = False
        TabOrder = 0
        TickMarks = tmBoth
        OnChange = PhTrackBar2Change
        OnMouseUp = PhTrackBar2MouseUp
      end
      object Panel3: TPanel
        Left = 139
        Top = 15
        Width = 70
        Height = 52
        Align = alRight
        BevelOuter = bvNone
        TabOrder = 1
        object SpinEdit1: TSpinEdit
          Left = 6
          Top = 16
          Width = 53
          Height = 22
          MaxValue = 30
          MinValue = 2
          TabOrder = 0
          Value = 2
          OnChange = SpinEdit1Change
        end
      end
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 258
    Width = 217
    Height = 19
    Panels = <
      item
        Text = #1042#1088#1077#1084#1103': 3:15:45 '
        Width = 100
      end
      item
        Text = #1054#1089#1090#1072#1083#1086#1089#1100': 2:12:34'
        Width = 50
      end>
  end
end
