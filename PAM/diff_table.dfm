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
    Top = 0
    Width = 832
    Height = 513
    Align = alClient
    ColCount = 6
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    PopupMenu = PopupMenu1
    TabOrder = 0
    ExplicitTop = 58
    ExplicitHeight = 455
  end
  object PopupMenu1: TPopupMenu
    Left = 552
    Top = 48
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
    object EditCopyToFile1: TMenuItem
      Action = FileSaveAsAction
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1074' '#1092#1072#1081#1083
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
    Left = 632
    Top = 48
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
    object EditCopyToFile: TAction
      Caption = 'EditCopyToFile'
      OnExecute = EditCopyToFileExecute
      OnUpdate = EditCopyToFileUpdate
    end
    object FileSaveAsAction: TAction
      Caption = 'FileSaveAsAction'
      OnExecute = FileSaveAsActionExecute
      OnUpdate = FileSaveAsActionUpdate
    end
  end
  object SaveDialog1: TSaveDialog
    Filter = #1060#1072#1081#1083#1099' PAM|*.pam'
    Left = 704
    Top = 48
  end
end
