object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'PsyGraph 2.0 '
  ClientHeight = 655
  ClientWidth = 1097
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poScreenCenter
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 466
    Top = 0
    Height = 636
    Align = alRight
    ExplicitLeft = 549
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 636
    Width = 1097
    Height = 19
    Panels = <
      item
        Width = 300
      end
      item
        Alignment = taCenter
        Width = 150
      end
      item
        Text = 'PsyGraph (c) Copyright 2016-2017 Adaptive Neurosystems. Ltd'
        Width = 50
      end>
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 466
    Height = 636
    Align = alClient
    TabOrder = 1
    object Panel3: TPanel
      Left = 1
      Top = 476
      Width = 464
      Height = 159
      Align = alBottom
      TabOrder = 0
      object GroupBox1: TGroupBox
        Left = 311
        Top = 25
        Width = 152
        Height = 133
        Align = alRight
        Caption = #1048#1079#1084#1077#1088#1103#1077#1084#1099#1077' '#1079#1085#1072#1095#1077#1085#1080#1103
        TabOrder = 0
        object Label2: TLabel
          Left = 13
          Top = 96
          Width = 50
          Height = 13
          Caption = #1050#1074#1072#1076#1088#1072#1085#1090
        end
        object Label3: TLabel
          Left = 13
          Top = 39
          Width = 6
          Height = 13
          Caption = 'X'
        end
        object Label4: TLabel
          Left = 13
          Top = 24
          Width = 19
          Height = 13
          Caption = 'Alfa'
        end
        object Label5: TLabel
          Left = 13
          Top = 54
          Width = 6
          Height = 13
          Caption = 'Y'
        end
        object Label6: TLabel
          Left = 13
          Top = 82
          Width = 11
          Height = 13
          Caption = 'Jn'
        end
        object Label1: TLabel
          Left = 13
          Top = 68
          Width = 11
          Height = 13
          Caption = 'J0'
        end
        object Label7: TLabel
          Left = 92
          Top = 96
          Width = 42
          Height = 13
          Caption = 'xxxxxx'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label8: TLabel
          Left = 92
          Top = 82
          Width = 42
          Height = 13
          Caption = 'xxxxxx'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label9: TLabel
          Left = 92
          Top = 68
          Width = 42
          Height = 13
          Caption = 'xxxxxx'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label10: TLabel
          Left = 92
          Top = 54
          Width = 42
          Height = 13
          Caption = 'xxxxxx'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label11: TLabel
          Left = 92
          Top = 39
          Width = 42
          Height = 13
          Caption = 'xxxxxx'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label12: TLabel
          Left = 92
          Top = 24
          Width = 42
          Height = 13
          Caption = 'xxxxxx'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
      end
      object GroupBox2: TGroupBox
        Left = 1
        Top = 25
        Width = 310
        Height = 133
        Align = alClient
        Caption = #1058#1077#1089#1090#1080#1088#1091#1077#1084#1099#1081
        TabOrder = 1
        object Label17: TLabel
          Left = 8
          Top = 46
          Width = 19
          Height = 13
          Caption = #1048#1084#1103
        end
        object Label18: TLabel
          Left = 8
          Top = 32
          Width = 44
          Height = 13
          Caption = #1060#1072#1084#1080#1083#1080#1103
        end
        object Label19: TLabel
          Left = 8
          Top = 60
          Width = 19
          Height = 13
          Caption = #1055#1086#1083
        end
        object Label20: TLabel
          Left = 8
          Top = 75
          Width = 40
          Height = 13
          Caption = #1042#1086#1079#1088#1072#1089#1090
        end
        object Label21: TLabel
          Left = 8
          Top = 91
          Width = 78
          Height = 13
          Caption = #1057#1087#1077#1094#1080#1072#1083#1080#1079#1072#1094#1080#1103
        end
        object Label22: TLabel
          Left = 8
          Top = 108
          Width = 32
          Height = 13
          Caption = #1052#1086#1090#1080#1074
        end
        object Label23: TLabel
          Left = 8
          Top = 16
          Width = 10
          Height = 13
          Caption = 'Id'
        end
        object DBText1: TDBText
          Left = 136
          Top = 16
          Width = 48
          Height = 13
          AutoSize = True
          DataField = 'PsyTestId'
          DataSource = DataModule1.DataSource1
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object DBText2: TDBText
          Left = 136
          Top = 46
          Width = 48
          Height = 13
          AutoSize = True
          DataField = 'FirstName'
          DataSource = DataModule1.DataSource1
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object DBText3: TDBText
          Left = 136
          Top = 32
          Width = 48
          Height = 13
          AutoSize = True
          DataField = 'LastName'
          DataSource = DataModule1.DataSource1
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object DBText4: TDBText
          Left = 136
          Top = 60
          Width = 48
          Height = 13
          AutoSize = True
          DataField = 'Gender'
          DataSource = DataModule1.DataSource1
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object DBText5: TDBText
          Left = 136
          Top = 75
          Width = 48
          Height = 13
          AutoSize = True
          DataField = 'Age'
          DataSource = DataModule1.DataSource1
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object DBText6: TDBText
          Left = 136
          Top = 91
          Width = 48
          Height = 13
          AutoSize = True
          DataField = 'WorkType'
          DataSource = DataModule1.DataSource1
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object DBText7: TDBText
          Left = 136
          Top = 108
          Width = 48
          Height = 13
          AutoSize = True
          DataField = 'PsyTestType'
          DataSource = DataModule1.DataSource1
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
      end
      object Panel4: TPanel
        Left = 1
        Top = 1
        Width = 462
        Height = 24
        Align = alTop
        BevelOuter = bvNone
        TabOrder = 2
        object Label24: TLabel
          AlignWithMargins = True
          Left = 33
          Top = 3
          Width = 91
          Height = 18
          Align = alLeft
          Caption = '  '#1053#1072#1095#1072#1083#1086' '#1074#1077#1082#1090#1086#1088#1072' '
          Color = clBtnFace
          ParentColor = False
          Layout = tlCenter
          ExplicitHeight = 13
        end
        object Label25: TLabel
          Left = 157
          Top = 0
          Width = 78
          Height = 24
          Align = alLeft
          Caption = '  '#1058#1086#1095#1082#1072' '#1084#1086#1090#1080#1074#1072' '
          Layout = tlCenter
          ExplicitHeight = 13
        end
        object Label26: TLabel
          Left = 268
          Top = 0
          Width = 82
          Height = 24
          Align = alLeft
          Caption = '  '#1050#1086#1085#1077#1094' '#1074#1077#1082#1090#1086#1088#1072
          Layout = tlCenter
          ExplicitHeight = 13
        end
        object Panel7: TPanel
          AlignWithMargins = True
          Left = 3
          Top = 3
          Width = 24
          Height = 18
          Align = alLeft
          Color = clBlue
          ParentBackground = False
          TabOrder = 0
        end
        object Panel8: TPanel
          AlignWithMargins = True
          Left = 130
          Top = 3
          Width = 24
          Height = 18
          Align = alLeft
          Color = clAqua
          ParentBackground = False
          TabOrder = 1
        end
        object Panel9: TPanel
          AlignWithMargins = True
          Left = 241
          Top = 3
          Width = 24
          Height = 18
          Margins.Left = 6
          Align = alLeft
          Color = clRed
          ParentBackground = False
          TabOrder = 2
        end
      end
    end
    object Panel6: TPanel
      Left = 1
      Top = 1
      Width = 464
      Height = 56
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 1
      object Label35: TLabel
        Left = 258
        Top = 0
        Width = 75
        Height = 13
        Caption = #1056#1072#1079#1084#1077#1088#1099' '#1083#1080#1089#1090#1072
      end
      object Label36: TLabel
        Left = 360
        Top = 37
        Width = 37
        Height = 13
        Caption = #1042#1099#1089#1086#1090#1072
      end
      object Label37: TLabel
        Left = 255
        Top = 37
        Width = 40
        Height = 13
        Caption = #1064#1080#1088#1080#1085#1072
      end
      object Button1: TButton
        Left = 1
        Top = 0
        Width = 76
        Height = 53
        Hint = #1054#1090#1082#1088#1099#1090#1100' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077' '#1080' '#1074#1099#1087#1086#1083#1085#1080#1090#1100' '#1085#1086#1074#1086#1077' '#1080#1079#1084#1077#1088#1077#1085#1080#1077' '
        Action = fileOpenAction
        Caption = #1053#1086#1074#1086#1077' '#1080#1079#1084#1077#1088#1077#1085#1080#1077
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        WordWrap = True
      end
      object Button3: TButton
        Left = 83
        Top = 0
        Width = 76
        Height = 53
        Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1087#1086#1083#1091#1095#1077#1085#1085#1099#1077' '#1079#1085#1072#1095#1077#1085#1080#1103' '#1074' '#1073#1072#1079#1077' '#1076#1072#1085#1085#1099#1093
        Action = dbInsertAction
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1074' '#1073#1072#1079#1077' '#1076#1072#1085#1085#1099#1093
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        WordWrap = True
      end
      object Button4: TButton
        Left = 165
        Top = 0
        Width = 76
        Height = 53
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1085#1086#1074#1086#1075#1086' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103' '#1074' '#1073#1072#1079#1091' '#1076#1072#1085#1085#1099#1093
        Action = dbAddUserAction
        Caption = #1054#1090#1084#1077#1085#1080#1090#1100' '#1080#1079#1084#1077#1088#1077#1085#1080#1077
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
        WordWrap = True
      end
      object SpinEdit1: TSpinEdit
        Left = 406
        Top = 28
        Width = 53
        Height = 22
        MaxValue = 300
        MinValue = 50
        TabOrder = 3
        Value = 50
        OnChange = SpinEdit1Change
      end
      object SpinEdit2: TSpinEdit
        Left = 301
        Top = 28
        Width = 53
        Height = 22
        MaxValue = 300
        MinValue = 50
        TabOrder = 4
        Value = 50
        OnChange = SpinEdit2Change
      end
    end
    object FImage1: TFImage
      Left = 1
      Top = 57
      Width = 464
      Height = 419
      Cursor = 1
      BorderStyle = bsFSingle
      Align = alClient
      Color = clWhite
      ParentColor = False
      OnMouseMove = FImage1MouseMove
      OnResize = FImage1Resize
      AfterOpen = FImage1AfterOpen
      OnChange = FImage1Change
    end
  end
  object Panel2: TPanel
    Left = 469
    Top = 0
    Width = 628
    Height = 636
    Align = alRight
    TabOrder = 2
    object DBGrid1: TDBGrid
      Left = 1
      Top = 61
      Width = 626
      Height = 319
      Align = alClient
      BorderStyle = bsNone
      DataSource = DataModule1.DataSource1
      DrawingStyle = gdsGradient
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
    end
    object Panel5: TPanel
      Left = 1
      Top = 1
      Width = 626
      Height = 60
      Align = alTop
      BevelOuter = bvNone
      TabOrder = 1
      object Label13: TLabel
        Left = 144
        Top = 12
        Width = 19
        Height = 13
        Caption = #1055#1086#1083
      end
      object Label14: TLabel
        Left = 208
        Top = 12
        Width = 40
        Height = 13
        Caption = #1042#1086#1079#1088#1072#1089#1090
      end
      object Label15: TLabel
        Left = 271
        Top = 12
        Width = 78
        Height = 13
        Caption = #1057#1087#1077#1094#1080#1072#1083#1080#1079#1072#1094#1080#1103
      end
      object Label16: TLabel
        Left = 371
        Top = 12
        Width = 32
        Height = 13
        Caption = #1052#1086#1090#1080#1074
      end
      object Label34: TLabel
        Left = 9
        Top = 12
        Width = 44
        Height = 13
        Caption = #1060#1072#1084#1080#1083#1080#1103
      end
      object ComboBoxGender: TComboBox
        Left = 144
        Top = 32
        Width = 57
        Height = 21
        Style = csDropDownList
        ItemIndex = 0
        TabOrder = 0
        Text = #1051#1102#1073#1086#1081
        Items.Strings = (
          #1051#1102#1073#1086#1081
          #1052#1091#1078#1089#1082#1086#1081
          #1046#1077#1085#1089#1082#1080#1081)
      end
      object ComboBoxAge: TComboBox
        Left = 208
        Top = 32
        Width = 57
        Height = 21
        Style = csDropDownList
        ItemIndex = 0
        TabOrder = 1
        Text = #1051#1102#1073#1086#1081
        Items.Strings = (
          #1051#1102#1073#1086#1081
          '10-15'
          '16-20'
          '21-25'
          '26-30'
          '31-35'
          '36-40'
          '41-45'
          '46-50'
          '51-55'
          '56-60'
          '>60'
          '')
      end
      object ComboBoxWorkType: TComboBox
        Left = 271
        Top = 32
        Width = 97
        Height = 21
        Style = csDropDownList
        TabOrder = 2
      end
      object ComboBoxPsyTestType: TComboBox
        Left = 370
        Top = 32
        Width = 90
        Height = 21
        Style = csDropDownList
        TabOrder = 3
      end
      object Button2: TButton
        Left = 463
        Top = 11
        Width = 63
        Height = 41
        Hint = #1042#1099#1073#1088#1072#1090#1100' '#1079#1072#1087#1080#1089#1080' '#1080#1079' '#1073#1072#1079#1099' '#1076#1072#1085#1085#1099#1093
        Action = dbSelectAction
        ParentShowHint = False
        ShowHint = True
        TabOrder = 4
      end
      object ComboBoxNames: TComboBox
        Left = 8
        Top = 32
        Width = 130
        Height = 21
        Style = csDropDownList
        TabOrder = 5
        OnChange = ComboBoxNamesChange
      end
      object Button5: TButton
        Left = 528
        Top = 11
        Width = 97
        Height = 41
        Action = DbExportAction
        ParentShowHint = False
        ShowHint = True
        TabOrder = 6
        WordWrap = True
      end
    end
    object Panel10: TPanel
      Left = 1
      Top = 517
      Width = 626
      Height = 118
      Align = alBottom
      TabOrder = 2
      object GroupBox3: TGroupBox
        Left = 1
        Top = 1
        Width = 624
        Height = 116
        Align = alClient
        Caption = #1050#1072#1095#1077#1089#1090#1074#1077#1085#1085#1099#1081' '#1072#1085#1072#1083#1080#1079' '#1084#1086#1090#1080#1074#1072#1094#1080#1080
        TabOrder = 0
        object Label33: TLabel
          AlignWithMargins = True
          Left = 5
          Top = 18
          Width = 614
          Height = 93
          Align = alClient
          AutoSize = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          WordWrap = True
          ExplicitWidth = 3
          ExplicitHeight = 13
        end
      end
    end
    object Panel11: TPanel
      Left = 1
      Top = 380
      Width = 626
      Height = 137
      Align = alBottom
      TabOrder = 3
      object GroupBox4: TGroupBox
        Left = 1
        Top = 1
        Width = 624
        Height = 135
        Align = alClient
        Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1077#1085#1085#1099#1081' '#1072#1085#1072#1083#1080#1079' '#1084#1086#1090#1080#1074#1072#1094#1080#1080
        TabOrder = 0
        object Label27: TLabel
          Left = 20
          Top = 37
          Width = 65
          Height = 26
          Caption = #1054#1073#1097#1080#1081' '#1073#1072#1083#1083' '#1084#1086#1090#1080#1074#1072#1094#1080#1080
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          WordWrap = True
        end
        object Label28: TLabel
          Left = 131
          Top = 25
          Width = 78
          Height = 39
          Caption = #1059#1088#1086#1074#1077#1085#1100' '#1074#1099#1088#1072#1078#1077#1085#1085#1086#1089#1090#1080' '#1084#1086#1090#1080#1074#1072#1094#1080#1080
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          WordWrap = True
        end
        object Label29: TLabel
          Left = 239
          Top = 24
          Width = 135
          Height = 39
          Caption = #1061#1072#1088#1072#1082#1090#1077#1088#1080#1089#1090#1080#1082#1072' '#1084#1086#1090#1080#1074#1072#1094#1080#1080' '#1085#1072' '#1086#1089#1085#1086#1074#1077' '#1082#1086#1083#1080#1095#1077#1089#1090#1074#1077#1085#1085#1086#1075#1086' '#1072#1085#1072#1083#1080#1079#1072' '
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = []
          ParentFont = False
          WordWrap = True
        end
        object Label30: TLabel
          Left = 28
          Top = 82
          Width = 22
          Height = 42
          Caption = '0'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -35
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label31: TLabel
          Left = 140
          Top = 82
          Width = 22
          Height = 42
          Caption = '0'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlue
          Font.Height = -35
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object Label32: TLabel
          Left = 239
          Top = 74
          Width = 237
          Height = 50
          AutoSize = False
          Caption = 'Label32'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
          WordWrap = True
        end
      end
    end
  end
  object ActionList1: TActionList
    Left = 40
    Top = 88
    object fileOpenAction: TAction
      Category = 'File'
      Caption = #1053#1086#1074#1086#1077' '#1080#1079#1084#1077#1088#1077#1085#1080#1077'... '
      Hint = #1053#1086#1074#1086#1077' '#1080#1079#1084#1077#1088#1077#1085#1080#1077
      OnExecute = fileOpenActionExecute
      OnUpdate = fileOpenActionUpdate
    end
    object fileExitAction: TAction
      Category = 'File'
      Caption = #1047#1072#1074#1077#1088#1096#1077#1085#1080#1077' '#1088#1072#1073#1086#1090#1099
      Hint = #1047#1072#1074#1077#1088#1096#1080#1090#1100' '#1088#1072#1073#1086#1090#1091
      OnExecute = fileExitActionExecute
    end
    object dbInsertAction: TAction
      Category = 'db'
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1074' '#1073#1072#1079#1077' '#1076#1072#1085#1085#1099#1093'...'
      Hint = #1054#1090#1082#1088#1099#1090#1100' '#1080#1079#1086#1073#1088#1072#1078#1077#1085#1080#1077' '#1080' '#1074#1099#1087#1086#1083#1085#1080#1090#1100' '#1085#1086#1074#1086#1077' '#1080#1079#1084#1077#1088#1077#1085#1080#1077' '
      OnExecute = dbInsertActionExecute
      OnUpdate = dbInsertActionUpdate
    end
    object dbCreateAction: TAction
      Category = 'db'
      Caption = #1057#1086#1079#1076#1072#1090#1100' '#1073#1072#1079#1091' '#1076#1072#1085#1085#1099#1093'...'
      Hint = #1057#1086#1079#1076#1072#1090#1100' '#1085#1086#1074#1091#1102' '#1073#1072#1079#1091' '#1076#1072#1085#1085#1099#1093' '
      OnExecute = dbCreateActionExecute
      OnUpdate = dbCreateActionUpdate
    end
    object dbOpenAction: TAction
      Category = 'db'
      Caption = #1054#1090#1082#1088#1099#1090#1100' '#1073#1072#1079#1091' '#1076#1072#1085#1085#1099#1093'...'
      Hint = #1054#1090#1082#1088#1099#1090#1100' '#1073#1072#1079#1091' '#1076#1072#1085#1085#1099#1093' '#1080#1079#1084#1077#1088#1077#1085#1080#1081
      OnExecute = dbOpenActionExecute
      OnUpdate = dbOpenActionUpdate
    end
    object dbCloseAction: TAction
      Category = 'db'
      Caption = #1047#1072#1082#1088#1099#1090#1100' '#1073#1072#1079#1091' '#1076#1072#1085#1085#1099#1093
      Hint = #1047#1072#1082#1088#1099#1090#1100' '#1073#1072#1079#1091' '#1076#1072#1085#1085#1099#1093
      OnExecute = dbCloseActionExecute
      OnUpdate = dbCloseActionUpdate
    end
    object viewLifeLineAction: TAction
      Category = 'view'
      Caption = #1051#1080#1085#1080#1102' '#1078#1080#1079#1085#1080
      Hint = #1054#1090#1086#1073#1088#1072#1078#1072#1090#1100' '#1083#1080#1085#1080#1102' '#1078#1080#1079#1085#1080
      OnExecute = viewLifeLineActionExecute
      OnUpdate = viewLifeLineActionUpdate
    end
    object viewFrameAction: TAction
      Category = 'view'
      Caption = #1056#1072#1084#1082#1091
      Hint = #1054#1090#1086#1073#1088#1072#1078#1072#1090#1100' '#1088#1072#1084#1082#1091
      OnExecute = viewFrameActionExecute
      OnUpdate = viewFrameActionUpdate
    end
    object modelCreateAction: TAction
      Category = 'model'
      Caption = #1057#1086#1079#1076#1072#1090#1100' '#1084#1086#1076#1077#1083#1100'...'
    end
    object modelEditAction: TAction
      Category = 'model'
      Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1090#1100' '#1084#1086#1076#1077#1083#1100
    end
    object modelDeleteAction: TAction
      Category = 'model'
      Caption = #1059#1076#1072#1083#1080#1090#1100' '#1084#1086#1076#1077#1083#1100
    end
    object modelSaveAction: TAction
      Category = 'model'
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1084#1086#1076#1077#1083#1100'... '
    end
    object toolsOptionsAction: TAction
      Category = 'tools'
      Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099'...'
      Hint = #1053#1072#1089#1090#1088#1086#1080#1090#1100' '#1087#1072#1088#1072#1084#1077#1090#1088#1099
      OnExecute = toolsOptionsActionExecute
    end
    object helpAboutAction: TAction
      Category = 'help'
      Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077'...'
      Hint = #1054' '#1087#1088#1075#1088#1072#1084#1084#1077
      OnExecute = helpAboutActionExecute
    end
    object helpContentsAction: TAction
      Category = 'help'
      Caption = #1055#1086#1076#1089#1082#1072#1079#1082#1072'... '
      Hint = #1055#1086#1082#1072#1079#1072#1090#1100' '#1089#1087#1088#1072#1074#1086#1095#1085#1091#1102' '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1102
      OnExecute = helpContentsActionExecute
    end
    object DbExportAction: TAction
      Category = 'db'
      Caption = #1069#1082#1089#1087#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100' '#1074' Excel...'
      Hint = #1069#1082#1089#1087#1086#1088#1090#1080#1088#1086#1074#1072#1090#1100' '#1076#1072#1085#1085#1099#1077' '#1074' Excel'
      OnExecute = DbExportActionExecute
      OnUpdate = DbExportActionUpdate
    end
    object dbAddUserAction: TAction
      Category = 'db'
      Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1090#1077#1089#1090#1080#1088#1091#1077#1084#1086#1075#1086' ...'
      Hint = #1054#1090#1084#1077#1085#1080#1090#1100' '#1080#1079#1084#1077#1088#1077#1085#1080#1077
      OnExecute = dbAddUserActionExecute
      OnUpdate = dbAddUserActionUpdate
    end
    object dbSelectAction: TAction
      Category = 'db'
      Caption = #1042#1099#1073#1088#1072#1090#1100
      Hint = #1042#1099#1073#1088#1072#1090#1100' '#1076#1072#1085#1085#1099#1077' '#1074' '#1089#1086#1086#1090#1074#1077#1090#1089#1090#1074#1080#1080' '#1089' '#1092#1080#1083#1100#1090#1088#1086#1084
      OnExecute = dbSelectActionExecute
      OnUpdate = dbSelectActionUpdate
    end
    object viewCoordsAction: TAction
      Category = 'view'
      Caption = #1057#1080#1089#1090#1077#1084#1091' '#1082#1086#1086#1088#1076#1080#1085#1072#1090
      OnExecute = viewCoordsActionExecute
      OnUpdate = viewCoordsActionUpdate
    end
    object dbEditUserAction: TAction
      Category = 'db'
      Caption = #1048#1079#1084#1077#1085#1080#1090#1100' '#1076#1072#1085#1085#1099#1077' '#1090#1077#1089#1090#1080#1088#1091#1077#1084#1086#1075#1086
      OnExecute = dbEditUserActionExecute
      OnUpdate = dbEditUserActionUpdate
    end
  end
  object MainMenu1: TMainMenu
    Left = 104
    Top = 88
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083#1099
      object N2: TMenuItem
        Action = fileOpenAction
        Visible = False
      end
      object N26: TMenuItem
        Action = dbAddUserAction
      end
      object N5: TMenuItem
        Action = dbEditUserAction
      end
      object N24: TMenuItem
        Action = dbInsertAction
      end
      object N23: TMenuItem
        Caption = '-'
      end
      object dbCreateAction1: TMenuItem
        Action = dbCreateAction
      end
      object N6: TMenuItem
        Action = dbOpenAction
      end
      object N7: TMenuItem
        Action = dbCloseAction
      end
      object Excel1: TMenuItem
        Action = DbExportAction
      end
      object N3: TMenuItem
        Caption = '-'
      end
      object N4: TMenuItem
        Action = fileExitAction
      end
    end
    object N11: TMenuItem
      Caption = #1052#1086#1076#1077#1083#1100
      Visible = False
      object N12: TMenuItem
        Action = modelCreateAction
      end
      object N14: TMenuItem
        Action = modelEditAction
      end
      object N15: TMenuItem
        Action = modelSaveAction
      end
      object N21: TMenuItem
        Caption = '-'
      end
      object N13: TMenuItem
        Action = modelDeleteAction
      end
    end
    object N16: TMenuItem
      Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072
      object N17: TMenuItem
        Action = toolsOptionsAction
      end
      object N8: TMenuItem
        Caption = #1054#1090#1086#1073#1088#1072#1078#1072#1090#1100
        object N10: TMenuItem
          Action = viewFrameAction
        end
        object N27: TMenuItem
          Action = viewCoordsAction
        end
        object N9: TMenuItem
          Action = viewLifeLineAction
        end
      end
    end
    object N18: TMenuItem
      Caption = #1055#1086#1084#1086#1097#1100
      object N19: TMenuItem
        Action = helpContentsAction
      end
      object N20: TMenuItem
        Action = helpAboutAction
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Filter = #1048#1079#1086#1073#1088#1072#1078#1077#1085#1080#1103' JPEG (*.jpg)|*.jpg'
    Left = 296
    Top = 88
  end
end
