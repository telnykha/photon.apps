object pri2EquipmentForm: Tpri2EquipmentForm
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsToolWindow
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1072' '#1086#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1103
  ClientHeight = 309
  ClientWidth = 446
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 201
    Height = 145
    Caption = #1042#1080#1076#1077#1086#1082#1072#1084#1077#1088#1072
    TabOrder = 0
    object Label1: TLabel
      Left = 9
      Top = 64
      Width = 59
      Height = 13
      Caption = #1069#1082#1089#1087#1086#1079#1080#1094#1080#1103
    end
    object Label2: TLabel
      Left = 9
      Top = 16
      Width = 32
      Height = 13
      Caption = #1056#1077#1078#1080#1084
    end
    object SpeedButton1: TSpeedButton
      Left = 9
      Top = 36
      Width = 59
      Height = 22
      GroupIndex = 1
      Down = True
      Caption = #1042#1080#1076#1077#1086
      OnClick = SpeedButton1Click
    end
    object SpeedButton2: TSpeedButton
      Left = 65
      Top = 36
      Width = 59
      Height = 22
      GroupIndex = 1
      Caption = #1058#1088#1080#1075#1075#1077#1088
      OnClick = SpeedButton2Click
    end
    object Label3: TLabel
      Left = 74
      Top = 64
      Width = 30
      Height = 13
      Caption = 'XXXXX'
    end
    object TrackBar1: TTrackBar
      Left = 3
      Top = 83
      Width = 182
      Height = 46
      Max = 200
      Min = 1
      Frequency = 10
      Position = 1
      ShowSelRange = False
      TabOrder = 0
      TickMarks = tmBoth
      OnChange = TrackBar1Change
    end
  end
  object GroupBox2: TGroupBox
    Left = 216
    Top = 8
    Width = 222
    Height = 145
    Caption = #1052#1080#1082#1088#1086#1082#1086#1085#1090#1088#1086#1083#1083#1077#1088
    TabOrder = 1
    object Label4: TLabel
      Left = 10
      Top = 22
      Width = 29
      Height = 13
      Caption = #1055#1086#1088#1090':'
    end
    object Label5: TLabel
      Left = 10
      Top = 40
      Width = 40
      Height = 13
      Caption = #1057#1090#1072#1090#1091#1089':'
    end
    object Label6: TLabel
      Left = 10
      Top = 60
      Width = 17
      Height = 13
      Caption = 'SN:'
    end
    object Label7: TLabel
      Left = 10
      Top = 85
      Width = 42
      Height = 13
      Caption = #1060#1086#1085#1072#1088#1100':'
    end
    object Label8: TLabel
      Left = 67
      Top = 22
      Width = 36
      Height = 13
      Caption = '---------'
    end
    object Label9: TLabel
      Left = 67
      Top = 40
      Width = 36
      Height = 13
      Caption = '---------'
    end
    object Label10: TLabel
      Left = 33
      Top = 61
      Width = 36
      Height = 13
      Caption = '---------'
    end
    object Button1: TButton
      Left = 24
      Top = 112
      Width = 177
      Height = 26
      Caption = #1057#1076#1077#1083#1072#1090#1100' '#1092#1086#1090#1086
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 64
      Top = 80
      Width = 137
      Height = 25
      Caption = #1042#1067#1050#1051
      TabOrder = 1
      OnClick = Button2Click
    end
  end
  object GroupBox3: TGroupBox
    Left = 8
    Top = 159
    Width = 202
    Height = 145
    Caption = #1060#1080#1083#1100#1090#1088#1099
    TabOrder = 2
    object Label17: TLabel
      Left = 9
      Top = 24
      Width = 40
      Height = 13
      Caption = #1057#1090#1072#1090#1091#1089':'
    end
    object Label18: TLabel
      Left = 87
      Top = 24
      Width = 48
      Height = 13
      Caption = '------------'
    end
    object Label19: TLabel
      Left = 9
      Top = 45
      Width = 58
      Height = 13
      Caption = #1057#1086#1089#1090#1086#1103#1085#1080#1077':'
    end
    object Label20: TLabel
      Left = 87
      Top = 45
      Width = 48
      Height = 13
      Caption = '------------'
    end
    object Label21: TLabel
      Left = 9
      Top = 64
      Width = 42
      Height = 13
      Caption = #1060#1080#1083#1100#1090#1088':'
    end
    object ComboBox2: TComboBox
      Left = 9
      Top = 83
      Width = 176
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 0
      Text = '1- BP448'
      OnChange = ComboBox2Change
      Items.Strings = (
        '1- BP448'
        '2- BP510'
        '3- BP532'
        '4- BP546'
        '5- BP572'
        '6- BP685'
        '7- '#1085#1077' '#1091#1089#1090#1072#1085#1086#1074#1083#1077#1085
        '8- '#1085#1077' '#1091#1089#1090#1072#1085#1086#1074#1083#1077#1085' ')
    end
  end
  object GroupBox4: TGroupBox
    Left = 217
    Top = 159
    Width = 221
    Height = 145
    Caption = #1054#1073#1098#1077#1082#1090#1080#1074
    TabOrder = 3
    object Label11: TLabel
      Left = 12
      Top = 24
      Width = 40
      Height = 13
      Caption = #1057#1090#1072#1090#1091#1089':'
    end
    object Label12: TLabel
      Left = 64
      Top = 24
      Width = 37
      Height = 13
      Caption = 'Label12'
    end
    object Label13: TLabel
      Left = 12
      Top = 43
      Width = 43
      Height = 13
      Caption = #1052#1086#1076#1077#1083#1100':'
    end
    object Label14: TLabel
      Left = 64
      Top = 43
      Width = 143
      Height = 13
      Caption = 'Sigma 30mm F1.4 DC HSM Art'
    end
    object Label15: TLabel
      Left = 12
      Top = 64
      Width = 35
      Height = 13
      Caption = #1060#1086#1082#1091#1089':'
    end
    object Label16: TLabel
      Left = 16
      Top = 121
      Width = 53
      Height = 13
      Caption = #1040#1087#1077#1088#1090#1091#1088#1072':'
    end
    object Button3: TButton
      Left = 12
      Top = 87
      Width = 33
      Height = 25
      Caption = '-100'
      TabOrder = 0
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 43
      Top = 87
      Width = 33
      Height = 25
      Caption = '-10'
      TabOrder = 1
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 74
      Top = 87
      Width = 33
      Height = 25
      Caption = '-1'
      TabOrder = 2
      OnClick = Button5Click
    end
    object Button6: TButton
      Left = 105
      Top = 87
      Width = 33
      Height = 25
      Caption = '+1'
      TabOrder = 3
      OnClick = Button6Click
    end
    object Button7: TButton
      Left = 136
      Top = 87
      Width = 33
      Height = 25
      Caption = '+10'
      TabOrder = 4
      OnClick = Button7Click
    end
    object Button8: TButton
      Left = 167
      Top = 87
      Width = 33
      Height = 25
      Caption = '+100'
      TabOrder = 5
      OnClick = Button8Click
    end
    object Edit1: TEdit
      Left = 63
      Top = 60
      Width = 103
      Height = 21
      TabOrder = 6
      Text = 'Edit1'
    end
    object Button9: TButton
      Left = 172
      Top = 56
      Width = 33
      Height = 25
      Caption = '>>'
      TabOrder = 7
      OnClick = Button9Click
    end
    object ComboBox1: TComboBox
      Left = 75
      Top = 118
      Width = 126
      Height = 21
      Style = csDropDownList
      ItemIndex = 0
      TabOrder = 8
      Text = '1.4 '
      OnChange = ComboBox1Change
      Items.Strings = (
        '1.4 '
        '1.6 '
        '1.8 '
        '2.0 '
        '2.2 '
        '2.5 '
        '2.8 '
        '3.2 '
        '3.5 '
        '4.0 '
        '4.5 '
        '5.0 '
        '5.6 '
        '6.3 '
        '7.1 '
        '8 9 '
        '10 '
        '11 '
        '13 '
        '14'
        '16')
    end
  end
end
