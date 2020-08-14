object Form3DView: TForm3DView
  Left = 0
  Top = 0
  BorderStyle = bsSizeToolWin
  Caption = 'Form3DView'
  ClientHeight = 352
  ClientWidth = 388
  Color = clBtnFace
  DragKind = dkDock
  DragMode = dmAutomatic
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnHide = FormHide
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object PaintBox1: TPaintBox
    Left = 0
    Top = 41
    Width = 388
    Height = 311
    Align = alClient
    OnMouseDown = PaintBox1MouseDown
    OnMouseMove = PaintBox1MouseMove
    OnMouseUp = PaintBox1MouseUp
    OnPaint = PaintBox1Paint
    ExplicitLeft = 200
    ExplicitTop = 192
    ExplicitWidth = 105
    ExplicitHeight = 105
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 388
    Height = 41
    Align = alTop
    TabOrder = 0
    ExplicitLeft = 200
    ExplicitTop = 48
    ExplicitWidth = 185
    object CSpinEdit1: TCSpinEdit
      Left = 8
      Top = 13
      Width = 49
      Height = 22
      MaxValue = 32
      MinValue = 1
      TabOrder = 0
      Value = 8
      OnChange = CSpinEdit1Change
    end
    object CheckBox1: TCheckBox
      Left = 72
      Top = 16
      Width = 97
      Height = 17
      Caption = '3D Cube'
      TabOrder = 1
      OnClick = CheckBox1Click
    end
  end
end
