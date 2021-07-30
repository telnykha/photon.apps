object Form9: TForm9
  Left = 0
  Top = 0
  Caption = 'Landmarks editor (research version)'
  ClientHeight = 503
  ClientWidth = 816
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 209
    Height = 503
    Align = alLeft
    TabOrder = 0
    object Splitter1: TSplitter
      Left = 1
      Top = 177
      Width = 207
      Height = 3
      Cursor = crVSplit
      Align = alTop
      ExplicitWidth = 325
    end
    object DirectoryListBox1: TDirectoryListBox
      Left = 1
      Top = 1
      Width = 207
      Height = 176
      Align = alTop
      FileList = FileListBox1
      TabOrder = 0
      OnChange = DirectoryListBox1Change
    end
    object Panel3: TPanel
      Left = 1
      Top = 478
      Width = 207
      Height = 24
      Align = alBottom
      TabOrder = 1
      object DriveComboBox1: TDriveComboBox
        Left = 1
        Top = 1
        Width = 205
        Height = 19
        Align = alClient
        DirList = DirectoryListBox1
        TabOrder = 0
      end
    end
    object FileListBox1: TFileListBox
      Left = 1
      Top = 180
      Width = 207
      Height = 298
      Align = alClient
      ItemHeight = 13
      Mask = '*.jpg;*awp;*.png;*.bmp;*.tif;*.tiff'
      TabOrder = 2
      OnChange = FileListBox1Change
      ExplicitHeight = 292
    end
  end
  object Panel2: TPanel
    Left = 209
    Top = 0
    Width = 607
    Height = 503
    Align = alClient
    Caption = 'Panel2'
    TabOrder = 1
    object Splitter2: TSplitter
      Left = 1
      Top = 1
      Height = 501
      ExplicitLeft = 24
      ExplicitTop = 272
      ExplicitHeight = 100
    end
    object PhImage1: TPhImage
      Left = 4
      Top = 1
      Width = 602
      Height = 501
      AutoMosaic = True
      ThumbWidht = 128
      ThumbHeight = 128
      SlideShowInterval = 500
      Align = alClient
      ParentColor = False
      OnPaint = PhImage1Paint
      AfterOpen = PhImage1AfterOpen
      ExplicitLeft = 5
    end
  end
end
