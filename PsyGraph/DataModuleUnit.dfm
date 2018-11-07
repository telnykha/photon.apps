object DataModule1: TDataModule1
  OldCreateOrder = False
  Height = 416
  Width = 198
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.Jet.OLEDB.4.0;User ID=Admin;Data Source=C:\Us' +
      'ers\ALT\Documents\test.mdb;Mode=Share Deny None;Persist Security' +
      ' Info=False;Jet OLEDB:System database="";Jet OLEDB:Registry Path' +
      '="";Jet OLEDB:Database Password="";Jet OLEDB:Engine Type=5;Jet O' +
      'LEDB:Database Locking Mode=1;Jet OLEDB:Global Partial Bulk Ops=2' +
      ';Jet OLEDB:Global Bulk Transactions=1;Jet OLEDB:New Database Pas' +
      'sword="";Jet OLEDB:Create System Database=False;Jet OLEDB:Encryp' +
      't Database=False;Jet OLEDB:Don'#39't Copy Locale on Compact=False;Je' +
      't OLEDB:Compact Without Replica Repair=False;Jet OLEDB:SFP=False'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 36
    Top = 16
  end
  object DataSource1: TDataSource
    DataSet = ADOTable1
    OnDataChange = DataSource1DataChange
    Left = 39
    Top = 72
  end
  object ADOTable10: TADOTable
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'queryTests'
    Left = 111
    Top = 72
    object ADOTable10FirstName: TWideStringField
      DisplayLabel = #1048#1084#1103
      FieldName = 'FirstName'
      Size = 10
    end
    object ADOTable10LastName: TWideStringField
      DisplayLabel = #1060#1072#1084#1080#1083#1080#1103
      FieldName = 'LastName'
      Size = 10
    end
    object ADOTable10Gender: TWideStringField
      DisplayLabel = #1055#1086#1083
      FieldName = 'Gender'
      Size = 8
    end
    object ADOTable10Age: TIntegerField
      DisplayLabel = #1042#1086#1079#1088#1072#1089#1090
      FieldName = 'Age'
    end
    object ADOTable10WorkType: TWideStringField
      DisplayLabel = #1055#1088#1086#1092#1077#1089#1089#1080#1103
      FieldName = 'WorkType'
      Size = 10
    end
    object ADOTable10PsyTestType: TWideStringField
      DisplayLabel = #1058#1077#1089#1090
      FieldName = 'PsyTestType'
      Size = 10
    end
    object ADOTable10ImageName: TWideStringField
      FieldName = 'ImageName'
      Visible = False
      Size = 255
    end
    object ADOTable10left_top_x: TIntegerField
      FieldName = 'left_top_x'
      Visible = False
    end
    object ADOTable10left_top_y: TIntegerField
      FieldName = 'left_top_y'
      Visible = False
    end
    object ADOTable10right_top_x: TIntegerField
      FieldName = 'right_top_x'
      Visible = False
    end
    object ADOTable10right_top_y: TIntegerField
      FieldName = 'right_top_y'
      Visible = False
    end
    object ADOTable10right_bottom_x: TIntegerField
      FieldName = 'right_bottom_x'
      Visible = False
    end
    object ADOTable10right_bottom_y: TIntegerField
      FieldName = 'right_bottom_y'
      Visible = False
    end
    object ADOTable10left_bottom_x: TIntegerField
      FieldName = 'left_bottom_x'
      Visible = False
    end
    object ADOTable10left_bottom_y: TIntegerField
      FieldName = 'left_bottom_y'
      Visible = False
    end
    object ADOTable10point3_x: TIntegerField
      FieldName = 'point3_x'
      Visible = False
    end
    object ADOTable10point2_x: TIntegerField
      FieldName = 'point2_x'
      Visible = False
    end
    object ADOTable10point2_y: TIntegerField
      FieldName = 'point2_y'
      Visible = False
    end
    object ADOTable10point3_y: TIntegerField
      FieldName = 'point3_y'
      Visible = False
    end
    object ADOTable10point1_y: TIntegerField
      FieldName = 'point1_y'
      Visible = False
    end
    object ADOTable10point1_x: TIntegerField
      FieldName = 'point1_x'
      Visible = False
    end
    object ADOTable10PsyTestId: TAutoIncField
      FieldName = 'PsyTestId'
      ReadOnly = True
    end
  end
  object ADOTable2: TADOTable
    Connection = ADOConnection1
    CursorType = ctStatic
    AfterOpen = ADOTable2AfterOpen
    TableName = 'Users'
    Left = 104
    Top = 128
    object ADOTable2UserId: TAutoIncField
      DisplayWidth = 4
      FieldName = 'UserId'
      ReadOnly = True
    end
    object ADOTable2FirstName: TWideStringField
      DisplayWidth = 11
      FieldName = 'FirstName'
      Size = 255
    end
    object ADOTable2LastName: TWideStringField
      DisplayWidth = 13
      FieldName = 'LastName'
      Size = 255
    end
    object ADOTable2Age: TIntegerField
      DisplayWidth = 6
      FieldName = 'Age'
    end
    object ADOTable2WorkTypeId: TIntegerField
      DisplayWidth = 15
      FieldName = 'WorkTypeId'
    end
    object ADOTable2GenderId: TIntegerField
      DisplayWidth = 15
      FieldName = 'GenderId'
    end
  end
  object DataSource2: TDataSource
    DataSet = ADOTable2
    Left = 40
    Top = 128
  end
  object DataSource3: TDataSource
    DataSet = ADOTable3
    Left = 40
    Top = 184
  end
  object ADOTable3: TADOTable
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'Gender'
    Left = 104
    Top = 184
    object ADOTable3GenderId: TAutoIncField
      DisplayWidth = 10
      FieldName = 'GenderId'
      ReadOnly = True
    end
    object ADOTable3Gender: TWideStringField
      DisplayWidth = 306
      FieldName = 'Gender'
      Size = 255
    end
  end
  object DataSource4: TDataSource
    DataSet = ADOTable4
    Left = 40
    Top = 232
  end
  object ADOTable4: TADOTable
    Connection = ADOConnection1
    CursorType = ctStatic
    AfterOpen = ADOTable4AfterOpen
    AfterPost = ADOTable4AfterPost
    TableName = 'WorkType'
    Left = 104
    Top = 232
    object ADOTable4WorkTypeId: TAutoIncField
      FieldName = 'WorkTypeId'
      ReadOnly = True
      Visible = False
    end
    object ADOTable4WorkType: TWideStringField
      FieldName = 'WorkType'
      Size = 255
    end
  end
  object DataSource5: TDataSource
    DataSet = ADOTable5
    Left = 40
    Top = 280
  end
  object ADOTable5: TADOTable
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'PsyTests'
    Left = 104
    Top = 280
    object ADOTable5PsyTestId: TAutoIncField
      FieldName = 'PsyTestId'
      ReadOnly = True
    end
    object ADOTable5ImageName: TWideStringField
      FieldName = 'ImageName'
      Size = 255
    end
    object ADOTable5UserId: TIntegerField
      FieldName = 'UserId'
    end
    object ADOTable5TestId: TIntegerField
      FieldName = 'TestId'
    end
    object ADOTable5left_top_x: TIntegerField
      FieldName = 'left_top_x'
    end
    object ADOTable5left_top_y: TIntegerField
      FieldName = 'left_top_y'
    end
    object ADOTable5right_top_x: TIntegerField
      FieldName = 'right_top_x'
    end
    object ADOTable5right_top_y: TIntegerField
      FieldName = 'right_top_y'
    end
    object ADOTable5right_bottom_x: TIntegerField
      FieldName = 'right_bottom_x'
    end
    object ADOTable5right_bottom_y: TIntegerField
      FieldName = 'right_bottom_y'
    end
    object ADOTable5left_bottom_x: TIntegerField
      FieldName = 'left_bottom_x'
    end
    object ADOTable5left_bottom_y: TIntegerField
      FieldName = 'left_bottom_y'
    end
    object ADOTable5point1_x: TIntegerField
      FieldName = 'point1_x'
    end
    object ADOTable5point1_y: TIntegerField
      FieldName = 'point1_y'
    end
    object ADOTable5point2_x: TIntegerField
      FieldName = 'point2_x'
    end
    object ADOTable5point2_y: TIntegerField
      FieldName = 'point2_y'
    end
    object ADOTable5point3_x: TIntegerField
      FieldName = 'point3_x'
    end
    object ADOTable5point3_y: TIntegerField
      FieldName = 'point3_y'
    end
  end
  object DataSource6: TDataSource
    DataSet = ADOTable6
    Left = 40
    Top = 328
  end
  object ADOTable6: TADOTable
    Connection = ADOConnection1
    CursorType = ctStatic
    AfterOpen = ADOTable6AfterOpen
    AfterPost = ADOTable6AfterPost
    TableName = 'PsyTestTypes'
    Left = 104
    Top = 328
    object ADOTable6PsyTestTypesId: TAutoIncField
      FieldName = 'PsyTestTypesId'
      ReadOnly = True
      Visible = False
    end
    object ADOTable6PsyTestType: TWideStringField
      FieldName = 'PsyTestType'
      Size = 255
    end
  end
  object ADOTable1: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select * from queryTests')
    Left = 120
    Top = 16
    object ADOTable1LastName: TWideStringField
      DisplayLabel = #1060#1072#1084#1080#1083#1080#1103
      FieldName = 'LastName'
      Size = 10
    end
    object ADOTable1FirstName: TWideStringField
      DisplayLabel = #1048#1084#1103
      FieldName = 'FirstName'
      Size = 10
    end
    object ADOTable1Gender: TWideStringField
      DisplayLabel = #1055#1086#1083
      FieldName = 'Gender'
      Size = 8
    end
    object ADOTable1Age: TIntegerField
      DisplayLabel = #1042#1086#1079#1088#1072#1089#1090
      FieldName = 'Age'
    end
    object ADOTable1WorkType: TWideStringField
      DisplayLabel = #1057#1087#1077#1094#1080#1072#1083#1080#1079#1072#1094#1080#1103
      FieldName = 'WorkType'
      Size = 10
    end
    object ADOTable1PsyTestType: TWideStringField
      DisplayLabel = #1052#1086#1090#1080#1074
      FieldName = 'PsyTestType'
      Size = 10
    end
    object ADOTable1ImageName: TWideStringField
      FieldName = 'ImageName'
      Visible = False
      Size = 255
    end
    object ADOTable1left_top_x: TIntegerField
      FieldName = 'left_top_x'
      Visible = False
    end
    object ADOTable1left_top_y: TIntegerField
      FieldName = 'left_top_y'
      Visible = False
    end
    object ADOTable1right_top_x: TIntegerField
      FieldName = 'right_top_x'
      Visible = False
    end
    object ADOTable1right_top_y: TIntegerField
      FieldName = 'right_top_y'
      Visible = False
    end
    object ADOTable1right_bottom_x: TIntegerField
      FieldName = 'right_bottom_x'
      Visible = False
    end
    object ADOTable1right_bottom_y: TIntegerField
      FieldName = 'right_bottom_y'
      Visible = False
    end
    object ADOTable1left_bottom_x: TIntegerField
      FieldName = 'left_bottom_x'
      Visible = False
    end
    object ADOTable1left_bottom_y: TIntegerField
      FieldName = 'left_bottom_y'
      Visible = False
    end
    object ADOTable1point3_x: TIntegerField
      FieldName = 'point3_x'
      Visible = False
    end
    object ADOTable1point2_x: TIntegerField
      FieldName = 'point2_x'
      Visible = False
    end
    object ADOTable1point2_y: TIntegerField
      FieldName = 'point2_y'
      Visible = False
    end
    object ADOTable1point3_y: TIntegerField
      FieldName = 'point3_y'
      Visible = False
    end
    object ADOTable1point1_y: TIntegerField
      FieldName = 'point1_y'
      Visible = False
    end
    object ADOTable1point1_x: TIntegerField
      FieldName = 'point1_x'
      Visible = False
    end
    object ADOTable1PsyTestId: TAutoIncField
      FieldName = 'PsyTestId'
      ReadOnly = True
      Visible = False
    end
  end
end
