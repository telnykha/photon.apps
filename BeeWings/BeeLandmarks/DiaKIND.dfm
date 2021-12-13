object KindEdit: TKindEdit
  Left = 227
  Top = 108
  BorderStyle = bsDialog
  Caption = 'Dialog'
  ClientHeight = 337
  ClientWidth = 393
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 8
    Top = 8
    Width = 281
    Height = 321
    Shape = bsFrame
  end
  object Label1: TLabel
    Left = 24
    Top = 27
    Width = 90
    Height = 13
    Caption = #1053#1072#1079#1072#1074#1085#1080#1077' '#1087#1086#1088#1086#1076#1099
  end
  object Label2: TLabel
    Left = 24
    Top = 54
    Width = 25
    Height = 13
    Caption = 'minCi'
  end
  object Label3: TLabel
    Left = 24
    Top = 81
    Width = 29
    Height = 13
    Caption = 'maxCi'
  end
  object Label4: TLabel
    Left = 24
    Top = 108
    Width = 35
    Height = 13
    Caption = 'minDsA'
  end
  object Label5: TLabel
    Left = 24
    Top = 135
    Width = 39
    Height = 13
    Caption = 'maxDsA'
  end
  object Label6: TLabel
    Left = 24
    Top = 162
    Width = 25
    Height = 13
    Caption = 'minHi'
  end
  object Label7: TLabel
    Left = 24
    Top = 189
    Width = 29
    Height = 13
    Caption = 'maxHi'
  end
  object Label8: TLabel
    Left = 24
    Top = 216
    Width = 23
    Height = 13
    Caption = 'color'
  end
  object OKBtn: TButton
    Left = 295
    Top = 8
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
  object CancelBtn: TButton
    Left = 295
    Top = 39
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 1
  end
  object Edit1: TEdit
    Left = 128
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 2
  end
  object Edit2: TEdit
    Left = 127
    Top = 51
    Width = 121
    Height = 21
    TabOrder = 3
  end
  object Edit3: TEdit
    Left = 128
    Top = 78
    Width = 121
    Height = 21
    TabOrder = 4
  end
  object Edit4: TEdit
    Left = 128
    Top = 105
    Width = 121
    Height = 21
    TabOrder = 5
  end
  object Edit5: TEdit
    Left = 128
    Top = 132
    Width = 121
    Height = 21
    TabOrder = 6
  end
  object Edit6: TEdit
    Left = 128
    Top = 159
    Width = 121
    Height = 21
    TabOrder = 7
  end
  object Edit7: TEdit
    Left = 128
    Top = 186
    Width = 121
    Height = 21
    TabOrder = 8
  end
  object Button1: TButton
    Left = 295
    Top = 264
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 9
    OnClick = Button1Click
  end
  object ColorGrid1: TColorGrid
    Left = 128
    Top = 213
    Width = 120
    Height = 100
    TabOrder = 10
  end
end
