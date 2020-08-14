object ParamsDlg: TParamsDlg
  Left = 227
  Top = 108
  BorderStyle = bsDialog
  Caption = 'Dialog'
  ClientHeight = 179
  ClientWidth = 384
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 281
    Height = 161
    Shape = bsFrame
  end
  object Label1: TLabel
    Left = 16
    Top = 16
    Width = 110
    Height = 13
    Caption = 'Gaussian kernel radius '
  end
  object Label2: TLabel
    Left = 16
    Top = 96
    Width = 103
    Height = 13
    Caption = 'Binarization threshold'
  end
  object Label3: TLabel
    Left = 144
    Top = 14
    Width = 20
    Height = 16
    Caption = '1.5'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 144
    Top = 93
    Width = 24
    Height = 16
    Caption = '120'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object OKBtn: TButton
    Left = 300
    Top = 8
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
  object CancelBtn: TButton
    Left = 300
    Top = 38
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object TrackBar1: TTrackBar
    Left = 16
    Top = 38
    Width = 257
    Height = 45
    Max = 100
    Frequency = 10
    ShowSelRange = False
    TabOrder = 2
    TickMarks = tmBoth
    OnChange = TrackBar1Change
  end
  object TrackBar2: TTrackBar
    Left = 16
    Top = 115
    Width = 257
    Height = 45
    Max = 100
    Frequency = 10
    ShowSelRange = False
    TabOrder = 3
    TickMarks = tmBoth
    OnChange = TrackBar2Change
  end
end
