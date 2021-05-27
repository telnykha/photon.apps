object pam2HardwareForm: Tpam2HardwareForm
  Left = 0
  Top = 0
  BorderStyle = bsToolWindow
  Caption = #1054#1073#1086#1088#1091#1076#1086#1074#1072#1085#1080#1077
  ClientHeight = 494
  ClientWidth = 219
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel6: TPanel
    Left = 0
    Top = 0
    Width = 220
    Height = 494
    Align = alLeft
    BorderStyle = bsSingle
    DragKind = dkDock
    DragMode = dmAutomatic
    TabOrder = 0
    ExplicitTop = -8
    ExplicitHeight = 513
    object Label1: TLabel
      AlignWithMargins = True
      Left = 4
      Top = 261
      Width = 208
      Height = 16
      Align = alTop
      Alignment = taCenter
      Caption = #1054#1089#1074#1077#1097#1077#1085#1080#1077
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      ExplicitLeft = 1
      ExplicitTop = 258
      ExplicitWidth = 75
    end
    object Label2: TLabel
      Left = 1
      Top = 1
      Width = 214
      Height = 16
      Align = alTop
      Alignment = taCenter
      Caption = #1042#1080#1076#1077#1086#1082#1072#1084#1077#1088#1072' Mightex'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      Layout = tlBottom
      ExplicitWidth = 145
    end
    object Label3: TLabel
      Left = 1
      Top = 167
      Width = 214
      Height = 16
      Align = alTop
      Alignment = taCenter
      Caption = #1048#1079#1084#1077#1088#1080#1090#1077#1083#1100#1085#1099#1081' '#1080#1084#1087#1091#1083#1100#1089
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      ExplicitWidth = 165
    end
    object GroupBox1: TGroupBox
      AlignWithMargins = True
      Left = 4
      Top = 20
      Width = 208
      Height = 69
      Align = alTop
      Caption = #1069#1082#1089#1087#1086#1079#1080#1094#1080#1103
      TabOrder = 0
      object PhTrackBar1: TPhTrackBar
        AlignWithMargins = True
        Left = 5
        Top = 18
        Width = 128
        Height = 46
        Align = alClient
        Max = 9
        ShowSelRange = False
        TabOrder = 0
        TickMarks = tmBoth
        OnChange = PhTrackBar1Change
        OnMouseUp = PhTrackBar1MouseUp
      end
      object Panel1: TPanel
        Left = 136
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
          OnChange = SpinEdit3Change
          OnExit = SpinEdit3Exit
        end
      end
    end
    object GroupBox5: TGroupBox
      AlignWithMargins = True
      Left = 4
      Top = 95
      Width = 208
      Height = 69
      Align = alTop
      Caption = #1059#1089#1080#1083#1077#1085#1080#1077
      TabOrder = 1
      object Panel2: TPanel
        Left = 136
        Top = 15
        Width = 70
        Height = 52
        Align = alRight
        BevelOuter = bvNone
        TabOrder = 0
        object SpinEdit2: TSpinEdit
          Left = 6
          Top = 16
          Width = 53
          Height = 22
          MaxValue = 41
          MinValue = 6
          TabOrder = 0
          Value = 10
          OnChange = SpinEdit2Change
        end
      end
      object PhTrackBar2: TPhTrackBar
        AlignWithMargins = True
        Left = 5
        Top = 18
        Width = 128
        Height = 46
        Align = alClient
        Max = 41
        Min = 6
        Frequency = 5
        Position = 6
        ShowSelRange = False
        TabOrder = 1
        TickMarks = tmBoth
        OnChange = PhTrackBar2Change
        OnMouseUp = PhTrackBar2MouseUp
      end
    end
    object GroupBox6: TGroupBox
      AlignWithMargins = True
      Left = 4
      Top = 186
      Width = 208
      Height = 69
      Align = alTop
      Caption = #1044#1083#1080#1090#1077#1083#1100#1085#1086#1089#1090#1100' (mks)'
      TabOrder = 2
      object Panel3: TPanel
        Left = 136
        Top = 15
        Width = 70
        Height = 52
        Align = alRight
        BevelOuter = bvNone
        TabOrder = 0
        object SpinEdit1: TSpinEdit
          Left = 6
          Top = 16
          Width = 53
          Height = 22
          MaxValue = 50
          MinValue = 20
          TabOrder = 0
          Value = 20
          OnChange = SpinEdit1Change
        end
      end
      object PhTrackBar3: TPhTrackBar
        AlignWithMargins = True
        Left = 5
        Top = 18
        Width = 128
        Height = 46
        Align = alClient
        Max = 50
        Min = 20
        Frequency = 5
        Position = 20
        ShowSelRange = False
        TabOrder = 1
        TickMarks = tmBoth
        OnChange = PhTrackBar3Change
        OnMouseUp = PhTrackBar3MouseUp
      end
    end
    object GroupBox2: TGroupBox
      Left = 1
      Top = 280
      Width = 214
      Height = 209
      Align = alClient
      TabOrder = 3
      ExplicitLeft = 14
      ExplicitTop = 328
      ExplicitWidth = 185
      ExplicitHeight = 105
      object SpeedButton1: TSpeedButton
        Left = 150
        Top = 25
        Width = 48
        Height = 48
        Action = hardwareSATAction
        AllowAllUp = True
        GroupIndex = 1
        Glyph.Data = {
          76020000424D7602000000000000760000002800000040000000100000000100
          04000000000000020000120B0000120B00001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
          3333333333FFFFF3333333333FFFFF3333333333333333333333333330000033
          33333333F777773FF333333FF377777F33333333330000033333333008877700
          33333337733FFF773F3333F377FFF33773333333007778800333330887000777
          033333733F777FFF73F33F37FFF777F337333330777000788033308800000007
          703337F37777777FF7F33F7FF77333773F73330770FCFCF08803308000000000
          7033373777777777F73FF37F73377733737333070F00000F0803087000777000
          77037F3777333777FF7FF7FF7373337373F73077F0077C00F780080007777700
          07037F777F3333777F7FF7F7373333F737F73070C077C7C0C0800F0007777700
          07037F777F3333777F7FF7F7373333F737F73070F07CCCC0F0F00F0008777700
          08037F777FF33377737FF73737333FF737F73080C0C7CCF0C0F00F7000887000
          780373F777FFF777F373373F737FFF737F373087F00CFF00F7F0308000000000
          803337F77777777737F33F73733777337F7333080F00000F080330F800000008
          8033373F777777733733337337733377F373330880FCFCF08F03330F87000788
          03333373FF77733F73333337F33777FF3733333088700078F03333300FFF8800
          3333333773FFFF773333333377FFFF37733333330088FFF00333333330000033
          3333333337777733333333333377777333333333330000033333}
        Layout = blGlyphTop
        NumGlyphs = 4
      end
      object Label4: TLabel
        Left = 16
        Top = 8
        Width = 97
        Height = 13
        Caption = #1053#1072#1089#1099#1097#1072#1102#1097#1080#1081' '#1089#1074#1077#1090
      end
      object SpeedButton2: TSpeedButton
        Left = 150
        Top = 89
        Width = 48
        Height = 48
        Action = hardwareACTAction
        AllowAllUp = True
        GroupIndex = 1
        Glyph.Data = {
          76020000424D7602000000000000760000002800000040000000100000000100
          04000000000000020000120B0000120B00001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
          3333333333FFFFF3333333333FFFFF3333333333333333333333333330000033
          33333333F777773FF333333FF377777F33333333330000033333333008877700
          33333337733FFF773F3333F377FFF33773333333007778800333330887000777
          033333733F777FFF73F33F37FFF777F337333330777000788033308800000007
          703337F37777777FF7F33F7FF77333773F73330770FCFCF08803308000000000
          7033373777777777F73FF37F73377733737333070F00000F0803087000777000
          77037F3777333777FF7FF7FF7373337373F73077F0077C00F780080007777700
          07037F777F3333777F7FF7F7373333F737F73070C077C7C0C0800F0007777700
          07037F777F3333777F7FF7F7373333F737F73070F07CCCC0F0F00F0008777700
          08037F777FF33377737FF73737333FF737F73080C0C7CCF0C0F00F7000887000
          780373F777FFF777F373373F737FFF737F373087F00CFF00F7F0308000000000
          803337F77777777737F33F73733777337F7333080F00000F080330F800000008
          8033373F777777733733337337733377F373330880FCFCF08F03330F87000788
          03333373FF77733F73333337F33777FF3733333088700078F03333300FFF8800
          3333333773FFFF773333333377FFFF37733333330088FFF00333333330000033
          3333333337777733333333333377777333333333330000033333}
        Layout = blGlyphTop
        NumGlyphs = 4
      end
      object Label5: TLabel
        Left = 16
        Top = 72
        Width = 89
        Height = 13
        Caption = #1040#1082#1090#1080#1085#1080#1095#1085#1099#1081' '#1089#1074#1077#1090
      end
      object Label6: TLabel
        Left = 16
        Top = 136
        Width = 120
        Height = 13
        Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1080#1077#1083#1100#1085#1099#1081' '#1089#1074#1077#1090
      end
      object SpeedButton3: TSpeedButton
        Left = 150
        Top = 153
        Width = 48
        Height = 48
        AllowAllUp = True
        GroupIndex = 2
        Caption = '50%'
        Glyph.Data = {
          76020000424D7602000000000000760000002800000040000000100000000100
          04000000000000020000120B0000120B00001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
          3333333333FFFFF3333333333FFFFF3333333333333333333333333330000033
          33333333F777773FF333333FF377777F33333333330000033333333008877700
          33333337733FFF773F3333F377FFF33773333333007778800333330887000777
          033333733F777FFF73F33F37FFF777F337333330777000788033308800000007
          703337F37777777FF7F33F7FF77333773F73330770F9F9F08803308000000000
          7033373777777777F73FF37F73377733737333070F00000F0803087000111000
          77037F3777333777FF7FF7FF7373337373F73077F0011900F780080001111100
          07037F777F3333777F7FF7F7373333F737F730709011919090800F0001111100
          07037F777F3333777F7FF7F7373333F737F73070F0199990F0F00F0008111100
          08037F777FF33377737FF73737333FF737F73080909199F090F00F7000881000
          780373F777FFF777F373373F737FFF737F373087F009FF00F7F0308000000000
          803337F77777777737F33F73733777337F7333080F00000F080330F800000008
          8033373F777777733733337337733377F373330880F9F9F08F03330F87000788
          03333373FF77733F73333337F33777FF3733333088700078F03333300FFF8800
          3333333773FFFF773333333377FFFF37733333330088FFF00333333330000033
          3333333337777733333333333377777333333333330000033333}
        Layout = blGlyphTop
        NumGlyphs = 4
        OnClick = SpeedButton3Click
      end
      object PhTrackBar5: TPhTrackBar
        AlignWithMargins = True
        Left = 3
        Top = 91
        Width = 128
        Height = 46
        Max = 100
        Frequency = 10
        Position = 50
        ShowSelRange = False
        TabOrder = 0
        TickMarks = tmBoth
        OnChange = PhTrackBar5Change
        OnMouseUp = PhTrackBar5MouseUp
      end
      object PhTrackBar6: TPhTrackBar
        AlignWithMargins = True
        Left = 3
        Top = 155
        Width = 128
        Height = 46
        Max = 100
        Frequency = 10
        Position = 50
        ShowSelRange = False
        TabOrder = 1
        TickMarks = tmBoth
        OnChange = PhTrackBar6Change
        OnMouseUp = PhTrackBar6MouseUp
      end
    end
  end
  object PhTrackBar4: TPhTrackBar
    AlignWithMargins = True
    Left = 8
    Top = 309
    Width = 128
    Height = 46
    Max = 100
    Frequency = 10
    Position = 50
    ShowSelRange = False
    TabOrder = 1
    TickMarks = tmBoth
    OnChange = PhTrackBar4Change
    OnMouseUp = PhTrackBar4MouseUp
  end
  object ActionList1: TActionList
    Left = 164
    Top = 87
    object hardwareSATAction: TAction
      Caption = '50%'
      GroupIndex = 1
      OnExecute = hardwareSATActionExecute
    end
    object hardwareACTAction: TAction
      Caption = '50%'
      GroupIndex = 1
      OnExecute = hardwareACTActionExecute
    end
  end
end
