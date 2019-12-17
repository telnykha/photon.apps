object dictinaryEditDlg: TdictinaryEditDlg
  Left = 227
  Top = 108
  BorderStyle = bsDialog
  Caption = 'Dictionary editor '
  ClientHeight = 202
  ClientWidth = 379
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object OKBtn: TButton
    Left = 199
    Top = 167
    Width = 172
    Height = 25
    Caption = 'Close'
    Default = True
    ModalResult = 1
    TabOrder = 0
  end
  object Button1: TButton
    Left = 199
    Top = 8
    Width = 172
    Height = 25
    Caption = 'Add Class Label...'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 199
    Top = 43
    Width = 172
    Height = 25
    Caption = 'Delete Class Label...'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 199
    Top = 74
    Width = 172
    Height = 25
    Caption = 'Edit Class Label...'
    TabOrder = 3
    OnClick = Button3Click
  end
  object ListBox1: TListBox
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 185
    Height = 196
    Align = alLeft
    ItemHeight = 13
    TabOrder = 4
  end
  object Button4: TButton
    Left = 199
    Top = 105
    Width = 172
    Height = 25
    Caption = 'Save Dictionary...'
    Enabled = False
    TabOrder = 5
    Visible = False
  end
end
