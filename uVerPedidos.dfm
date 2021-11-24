object fVerPedidos: TfVerPedidos
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = ' Ver pedidos de clientes'
  ClientHeight = 551
  ClientWidth = 976
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 13
    Width = 109
    Height = 14
    Caption = 'Buscar por cliente'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 71
    Width = 962
    Height = 441
    DataSource = DataSource3
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    ParentFont = False
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    OnDblClick = DBGrid1DblClick
    Columns = <
      item
        Expanded = False
        FieldName = 'repartidor'
        Title.Alignment = taCenter
        Title.Caption = 'Repartidor'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 138
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'reparto'
        Title.Alignment = taCenter
        Title.Caption = 'Reparto'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 66
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'cliente'
        Title.Alignment = taCenter
        Title.Caption = 'Cliente'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 248
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'bandGrand'
        Title.Alignment = taCenter
        Title.Caption = 'Nro bandejas'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 94
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'cantViandas'
        Title.Alignment = taCenter
        Title.Caption = 'Nro Viandas'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 99
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'complemento'
        Title.Alignment = taCenter
        Title.Caption = 'Complementos'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 277
        Visible = True
      end>
  end
  object MC: TMonthCalendar
    Left = 711
    Top = 375
    Width = 191
    Height = 160
    Date = 43981.785068113420000000
    TabOrder = 2
    Visible = False
  end
  object Button1: TButton
    Left = 384
    Top = 518
    Width = 225
    Height = 25
    Caption = 'Cerrar esta ventana'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 8
    Top = 32
    Width = 265
    Height = 33
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    MaxLength = 7
    ParentFont = False
    TabOrder = 0
    OnChange = Edit1Change
  end
  object Button2: TButton
    Left = 288
    Top = 31
    Width = 193
    Height = 35
    Caption = 'Ver todos los pedidos de hoy'
    TabOrder = 4
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 496
    Top = 31
    Width = 193
    Height = 35
    Caption = 'Buscar clientes'
    TabOrder = 5
    OnClick = Button3Click
  end
  object Panel1: TPanel
    Left = 8
    Top = 72
    Width = 962
    Height = 471
    Caption = 'Panel1'
    ShowCaption = False
    TabOrder = 6
    object DBGrid2: TDBGrid
      Left = 107
      Top = 12
      Width = 750
      Height = 421
      DataSource = DataSource1
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
      ParentFont = False
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
      Columns = <
        item
          Expanded = False
          FieldName = 'calle'
          Title.Alignment = taCenter
          Title.Caption = 'Calle'
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -12
          Title.Font.Name = 'Tahoma'
          Title.Font.Style = [fsBold]
          Width = 196
          Visible = True
        end
        item
          Alignment = taRightJustify
          Expanded = False
          FieldName = 'numero'
          Title.Alignment = taCenter
          Title.Caption = 'N'#250'mero'
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -12
          Title.Font.Name = 'Tahoma'
          Title.Font.Style = [fsBold]
          Width = 107
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'repLV'
          Title.Alignment = taCenter
          Title.Caption = 'Reparto Lunes a Viernes'
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -12
          Title.Font.Name = 'Tahoma'
          Title.Font.Style = [fsBold]
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'repSab'
          Title.Alignment = taCenter
          Title.Caption = 'Reparto S'#225'bados'
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -12
          Title.Font.Name = 'Tahoma'
          Title.Font.Style = [fsBold]
          Visible = True
        end>
    end
    object Button4: TButton
      Left = 376
      Top = 439
      Width = 201
      Height = 25
      Caption = 'Cerrar'
      TabOrder = 1
      OnClick = Button4Click
    end
  end
  object SQLConnection1: TSQLConnection
    ConnectionName = 'MySQLConnection'
    DriverName = 'MySQL'
    KeepConnection = False
    LoginPrompt = False
    Params.Strings = (
      'DriverName=MySQL'
      'HostName=localhost'
      'Database=dbes'
      'User_Name=root'
      'Password=CBR900rr'
      'ServerCharSet=utf8'
      'BlobSize=-1'
      'ErrorResourceFile='
      'LocaleCode=0000'
      'Compressed=False'
      'Encrypted=False'
      'ConnectTimeout=60')
    Left = 60
    Top = 115
  end
  object ClientDataSet3: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider3'
    ReadOnly = True
    Left = 60
    Top = 203
    object ClientDataSet3repartidor: TWideStringField
      FieldName = 'repartidor'
    end
    object ClientDataSet3cliente: TWideStringField
      FieldName = 'cliente'
    end
    object ClientDataSet3cantViandas: TFMTBCDField
      FieldName = 'cantViandas'
      DisplayFormat = '0.00'
    end
    object ClientDataSet3complemento: TWideStringField
      FieldName = 'complemento'
    end
    object ClientDataSet3idCantidad: TIntegerField
      FieldName = 'idCantidad'
    end
    object ClientDataSet3bandGrand: TIntegerField
      FieldName = 'bandGrand'
    end
    object ClientDataSet3reparto: TIntegerField
      FieldName = 'reparto'
    end
  end
  object DataSetProvider3: TDataSetProvider
    DataSet = QueryCantidad
    Left = 60
    Top = 275
  end
  object QueryCantidad: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 52
    Top = 363
  end
  object DataSource3: TDataSource
    DataSet = ClientDataSet3
    Left = 52
    Top = 427
  end
  object ClientDataSet1: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider1'
    ReadOnly = True
    Left = 140
    Top = 203
    object ClientDataSet1idCliente: TIntegerField
      FieldName = 'idCliente'
    end
    object ClientDataSet1calle: TWideStringField
      FieldName = 'calle'
    end
    object ClientDataSet1numero: TWideStringField
      FieldName = 'numero'
    end
    object ClientDataSet1repLV: TWideStringField
      FieldName = 'repLV'
    end
    object ClientDataSet1repSab: TWideStringField
      FieldName = 'repSab'
    end
  end
  object DataSetProvider1: TDataSetProvider
    DataSet = QueryClientes
    Left = 108
    Top = 251
  end
  object QueryClientes: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 140
    Top = 371
  end
  object DataSource1: TDataSource
    DataSet = ClientDataSet1
    Left = 140
    Top = 427
  end
  object QueryAux: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 732
    Top = 11
  end
end
