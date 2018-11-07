object AddItemDialog: TAddItemDialog
  Left = 227
  Top = 108
  BorderStyle = bsDialog
  Caption = #1053#1086#1074#1086#1077' '#1080#1079#1084#1077#1088#1077#1085#1080#1077
  ClientHeight = 232
  ClientWidth = 444
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  OnCloseQuery = FormCloseQuery
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 347
    Height = 217
    Shape = bsFrame
  end
  object Label1: TLabel
    Left = 18
    Top = 20
    Width = 67
    Height = 13
    Caption = #1058#1077#1089#1090#1080#1088#1091#1077#1084#1099#1081
  end
  object Label2: TLabel
    Left = 18
    Top = 194
    Width = 32
    Height = 13
    Caption = #1052#1086#1090#1080#1074
  end
  object OKBtn: TButton
    Left = 361
    Top = 8
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
    OnClick = OKBtnClick
  end
  object CancelBtn: TButton
    Left = 361
    Top = 38
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 1
    OnClick = CancelBtnClick
  end
  object DBGrid1: TDBGrid
    AlignWithMargins = True
    Left = 16
    Top = 46
    Width = 321
    Height = 137
    DataSource = DataModule1.DataSource2
    DrawingStyle = gdsGradient
    Options = [dgIndicator, dgColumnResize, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    TabOrder = 2
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'UserId'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'FirstName'
        Width = 64
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'LastName'
        Width = 64
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Age'
        Width = 64
        Visible = True
      end>
  end
  object Button1: TButton
    Left = 97
    Top = 15
    Width = 240
    Height = 25
    Caption = #1044#1086#1073#1074#1072#1090#1100' '#1085#1086#1074#1086#1075#1086' '#1090#1077#1089#1090#1080#1088#1091#1077#1084#1086#1075#1086'...'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 199
    Top = 189
    Width = 138
    Height = 25
    Caption = #1053#1086#1074#1099#1081' '#1084#1086#1090#1080#1074'...'
    TabOrder = 4
    OnClick = Button2Click
  end
  object DBLookupComboBox1: TDBLookupComboBox
    Left = 56
    Top = 192
    Width = 137
    Height = 21
    DataField = 'TestId'
    DataSource = DataModule1.DataSource5
    KeyField = 'PsyTestTypesId'
    ListField = 'PsyTestType'
    ListSource = DataModule1.DataSource6
    TabOrder = 5
  end
end
