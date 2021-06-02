object pam2ExperimentForm: Tpam2ExperimentForm
  Left = 0
  Top = 0
  BorderStyle = bsToolWindow
  Caption = #1069#1082#1089#1087#1077#1088#1080#1084#1077#1085#1090
  ClientHeight = 308
  ClientWidth = 217
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
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 217
    Height = 289
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    ExplicitTop = -6
    object Gauge1: TGauge
      AlignWithMargins = True
      Left = 3
      Top = 250
      Width = 211
      Height = 36
      Align = alBottom
      Progress = 0
      ExplicitLeft = 0
      ExplicitTop = 136
      ExplicitWidth = 217
    end
    object Button1: TButton
      AlignWithMargins = True
      Left = 3
      Top = 208
      Width = 211
      Height = 36
      Action = pamMainForm.toolsStopExperimentAction
      Align = alBottom
      TabOrder = 0
      ExplicitLeft = 0
      ExplicitTop = 136
      ExplicitWidth = 217
    end
    object Button2: TButton
      AlignWithMargins = True
      Left = 3
      Top = 168
      Width = 211
      Height = 34
      Action = pamMainForm.toolsStartExperimetAction
      Align = alBottom
      TabOrder = 1
      ExplicitLeft = 0
      ExplicitTop = 96
      ExplicitWidth = 217
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
      ExplicitLeft = 4
      ExplicitTop = 20
      ExplicitWidth = 208
      object PhTrackBar1: TPhTrackBar
        AlignWithMargins = True
        Left = 5
        Top = 18
        Width = 131
        Height = 46
        Align = alClient
        Max = 9
        ShowSelRange = False
        TabOrder = 0
        TickMarks = tmBoth
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
          MaxValue = 32000
          MinValue = 1
          TabOrder = 0
          Value = 30000
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
      ExplicitLeft = 4
      ExplicitTop = 20
      ExplicitWidth = 208
      object PhTrackBar2: TPhTrackBar
        AlignWithMargins = True
        Left = 5
        Top = 18
        Width = 131
        Height = 46
        Align = alClient
        Max = 9
        ShowSelRange = False
        TabOrder = 0
        TickMarks = tmBoth
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
          MaxValue = 32000
          MinValue = 1
          TabOrder = 0
          Value = 30000
        end
      end
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 289
    Width = 217
    Height = 19
    Panels = <>
    ExplicitTop = 166
    ExplicitWidth = 236
  end
end
