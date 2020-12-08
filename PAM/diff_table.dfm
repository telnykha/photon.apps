object Difficult_command: TDifficult_command
  Left = 0
  Top = 0
  Caption = 'Difficult command'
  ClientHeight = 513
  ClientWidth = 832
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
  object PageControl1: TPageControl
    Left = 0
    Top = 64
    Width = 673
    Height = 441
    TabOrder = 1
  end
  object StringGrid1: TStringGrid
    Left = 0
    Top = 58
    Width = 832
    Height = 455
    Align = alClient
    ColCount = 6
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    PopupMenu = PopupMenu1
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 832
    Height = 58
    Align = alTop
    Caption = 'Panel1'
    TabOrder = 2
    object SpeedButton1: TSpeedButton
      Left = 8
      Top = 8
      Width = 105
      Height = 50
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
      OnClick = Add_command
    end
    object SpeedButton2: TSpeedButton
      Left = 119
      Top = 8
      Width = 114
      Height = 50
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
      OnClick = editDeleteAction2
    end
    object SpeedButton3: TSpeedButton
      Left = 239
      Top = 8
      Width = 114
      Height = 50
      Caption = #1042#1089#1090#1072#1074#1080#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
      OnClick = editAddAction2Excute
    end
    object SpeedButton4: TSpeedButton
      Left = 359
      Top = 8
      Width = 146
      Height = 50
      Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
      OnClick = editEditActionExcute
    end
    object SpeedButton5: TSpeedButton
      Left = 511
      Top = 8
      Width = 114
      Height = 50
      Action = EditCopyAction
      Caption = #1057#1082#1086#1087#1080#1088#1086#1074#1072#1090#1100' '#1074' '#1073#1091#1092#1077#1088
    end
    object SpeedButton6: TSpeedButton
      Left = 631
      Top = 8
      Width = 114
      Height = 50
      Action = EditPastAction
      Caption = #1042#1089#1090#1072#1074#1080#1090#1100' '#1080#1079' '#1073#1091#1092#1077#1088#1072
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 112
    Top = 440
    object N1: TMenuItem
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
      OnClick = Add_command
    end
    object N3: TMenuItem
      Caption = #1042#1089#1090#1072#1074#1080#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
      OnClick = editAddAction2Excute
    end
    object N2: TMenuItem
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
      OnClick = editDeleteAction2
    end
    object N4: TMenuItem
      Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100' '#1082#1086#1084#1072#1085#1076#1091
      OnClick = editEditActionExcute
    end
    object N9: TMenuItem
      Caption = '-'
    end
    object N5: TMenuItem
      Action = EditCopyAction
      Caption = #1050#1086#1087#1080#1088#1086#1074#1072#1090#1100' '#1074' '#1073#1091#1092#1077#1088#1072
    end
    object N6: TMenuItem
      Action = EditPastAction
      Caption = #1042#1089#1090#1072#1074#1080#1090#1100' '#1080#1079' '#1073#1091#1092#1077#1088#1072
    end
    object N10: TMenuItem
      Caption = '-'
    end
    object N7: TMenuItem
      Caption = #1055#1086#1076#1085#1103#1090#1100
      OnClick = editUpActionExecute2
    end
    object N8: TMenuItem
      Caption = #1054#1087#1091#1089#1090#1080#1090#1100
      OnClick = editDownActionExecute
    end
  end
  object ActionList1: TActionList
    Left = 200
    Top = 440
    object EditCopyAction: TAction
      Caption = 'Action1'
      OnExecute = EditCopyActionExecute
      OnUpdate = EditCopyActionUpdate
    end
    object EditPastAction: TAction
      Caption = 'EditPast'
      OnExecute = EditPastActionExecute
      OnUpdate = EditPastActionUpdate
    end
  end
end
