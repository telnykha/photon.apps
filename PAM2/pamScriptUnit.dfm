object pam2ScriptForm: Tpam2ScriptForm
  Left = 0
  Top = 0
  BorderStyle = bsSizeToolWin
  Caption = #1057#1082#1088#1080#1087#1090
  ClientHeight = 365
  ClientWidth = 427
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
    Width = 427
    Height = 33
    Align = alTop
    TabOrder = 0
    Visible = False
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 346
    Width = 427
    Height = 19
    Panels = <
      item
        Width = 400
      end
      item
        Width = 100
      end>
  end
  object RichEdit1: TRichEdit
    Left = 0
    Top = 33
    Width = 427
    Height = 313
    Align = alClient
    BevelInner = bvNone
    BevelOuter = bvNone
    Color = clNone
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clCream
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    HideSelection = False
    ParentFont = False
    PopupMenu = PopupMenu1
    ScrollBars = ssVertical
    TabOrder = 2
    WordWrap = False
    Zoom = 100
    OnChange = RichEdit1Change
  end
  object ActionList1: TActionList
    Left = 368
    Top = 40
    object scriptNewAction: TAction
      Caption = #1053#1086#1074#1099#1081' '#1089#1082#1088#1080#1087#1090
      ImageIndex = 0
      OnExecute = scriptNewActionExecute
      OnUpdate = scriptNewActionUpdate
    end
    object scriptOpenAction: TAction
      Caption = #1054#1090#1082#1088#1099#1090#1100' '#1089#1082#1088#1080#1087#1090'... '
      ImageIndex = 1
      OnExecute = scriptOpenActionExecute
      OnUpdate = scriptOpenActionUpdate
    end
    object scriptSaveAction: TAction
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      ImageIndex = 2
      OnExecute = scriptSaveActionExecute
      OnUpdate = scriptSaveActionUpdate
    end
    object scriptSaveAsAction: TAction
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1085#1072' '#1076#1080#1089#1082'...'
      OnExecute = scriptSaveAsActionExecute
      OnUpdate = scriptSaveAsActionUpdate
    end
    object scriptCheckAction: TAction
      Caption = #1055#1088#1086#1074#1077#1088#1080#1090#1100
      ImageIndex = 3
      ShortCut = 116
      OnExecute = scriptCheckActionExecute
      OnUpdate = scriptCheckActionUpdate
    end
    object scriptExecuteAction: TAction
      Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100
      ImageIndex = 4
      ShortCut = 120
      OnExecute = scriptExecuteActionExecute
      OnUpdate = scriptExecuteActionUpdate
    end
    object scriptClearAction: TAction
      Caption = #1054#1095#1080#1089#1090#1080#1090#1100
    end
    object scriptEditCopyAction: TEditCopy
      Caption = #1057#1082#1086#1087#1080#1088#1086#1074#1072#1090#1100
      Hint = 'Copy|Copies the selection and puts it on the Clipboard'
      ImageIndex = 1
      ShortCut = 16451
    end
    object scriptEditSelectAllAction: TEditSelectAll
      Caption = #1042#1099#1073#1088#1072#1090#1100' '#1074#1089#1077
      Hint = 'Select All|Selects the entire document'
      ShortCut = 16449
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 368
    Top = 96
    object scriptNewAction1: TMenuItem
      Action = scriptNewAction
    end
    object N4: TMenuItem
      Caption = '-'
    end
    object N1: TMenuItem
      Action = scriptOpenAction
    end
    object N2: TMenuItem
      Action = scriptSaveAsAction
    end
    object N3: TMenuItem
      Action = scriptSaveAction
    end
    object N5: TMenuItem
      Caption = '-'
    end
    object N8: TMenuItem
      Action = scriptEditSelectAllAction
    end
    object N6: TMenuItem
      Action = scriptEditCopyAction
    end
    object scriptClearAction1: TMenuItem
      Action = scriptClearAction
    end
    object N7: TMenuItem
      Caption = '-'
    end
    object scriptCheckAction1: TMenuItem
      Action = scriptCheckAction
    end
    object scriptExecuteAction1: TMenuItem
      Action = scriptExecuteAction
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = #1057#1082#1088#1080#1087#1090' pam2|*.pam2s'
    Left = 376
    Top = 152
  end
  object SaveDialog1: TSaveDialog
    Filter = #1057#1082#1088#1080#1087#1090' pam2|*.pam2s'
    Left = 376
    Top = 200
  end
end
