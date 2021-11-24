object fMain: TfMain
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = ' Informaci'#243'n de ventas'
  ClientHeight = 704
  ClientWidth = 1389
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label5: TLabel
    Left = 3
    Top = 135
    Width = 90
    Height = 49
    Alignment = taCenter
    Caption = 'fecha'
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlack
    Font.Height = -40
    Font.Name = 'Calibri'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Reloj: TLabel
    Left = 23
    Top = 3
    Width = 279
    Height = 116
    Caption = '12:55'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -96
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label7: TLabel
    Left = 561
    Top = 2
    Width = 246
    Height = 16
    Alignment = taCenter
    AutoSize = False
    Caption = 'Comidas especiales (por horario)'
    Color = 5855577
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    Transparent = False
  end
  object Label8: TLabel
    Left = 813
    Top = 2
    Width = 576
    Height = 16
    Alignment = taCenter
    AutoSize = False
    Caption = 'Lista de comidas especiales ordenadas por nombre'
    Color = 5855577
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentColor = False
    ParentFont = False
    Transparent = False
  end
  object Panel1: TPanel
    Left = 0
    Top = 252
    Width = 550
    Height = 446
    Caption = 'Panel1'
    Color = 5855577
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentBackground = False
    ParentFont = False
    ShowCaption = False
    TabOrder = 0
    object Label1: TLabel
      Left = 7
      Top = 4
      Width = 193
      Height = 41
      AutoSize = False
      Caption = 'Porciones'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWhite
      Font.Height = -35
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 196
      Top = 4
      Width = 117
      Height = 41
      Alignment = taCenter
      AutoSize = False
      Caption = ' 1'#176
      Font.Charset = ANSI_CHARSET
      Font.Color = clWhite
      Font.Height = -35
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 313
      Top = 4
      Width = 117
      Height = 41
      Alignment = taCenter
      AutoSize = False
      Caption = ' 2'#176
      Font.Charset = ANSI_CHARSET
      Font.Color = clWhite
      Font.Height = -35
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 430
      Top = 4
      Width = 117
      Height = 41
      Alignment = taCenter
      AutoSize = False
      Caption = 'Total'
      Color = 16768479
      Font.Charset = ANSI_CHARSET
      Font.Color = clWhite
      Font.Height = -35
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
    end
    object lbCodigo: TListBox
      Left = 3
      Top = 51
      Width = 193
      Height = 386
      Style = lbOwnerDrawFixed
      BorderStyle = bsNone
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -40
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ItemHeight = 48
      Items.Strings = (
        'M CAR'
        'M POLL'
        'ENTRE'
        'CALA GR'
        'TORRE'
        'REVZAP'
        'PIZZA'
        'RZTHAQ')
      ParentFont = False
      PopupMenu = PopupMenu4
      TabOrder = 0
      OnDblClick = lbCodigoDblClick
      OnDrawItem = lbCodigoDrawItem
    end
    object lbPorcPrim: TListBox
      Left = 196
      Top = 51
      Width = 117
      Height = 386
      Style = lbOwnerDrawFixed
      BorderStyle = bsNone
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -40
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ItemHeight = 48
      Items.Strings = (
        '222'
        '222'
        '222'
        '222'
        '222'
        '222'
        '222'
        '222')
      ParentFont = False
      TabOrder = 1
      OnDrawItem = lbPorcPrimDrawItem
    end
    object lbPorcSeg: TListBox
      Left = 313
      Top = 51
      Width = 117
      Height = 386
      Style = lbOwnerDrawFixed
      BorderStyle = bsNone
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -40
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ItemHeight = 48
      Items.Strings = (
        '222'
        '222'
        '222'
        '222'
        '222'
        '222'
        '222'
        '222')
      ParentFont = False
      TabOrder = 2
      OnDrawItem = lbPorcSegDrawItem
    end
    object lbPorcTotal: TListBox
      Left = 430
      Top = 51
      Width = 117
      Height = 386
      Style = lbOwnerDrawFixed
      BorderStyle = bsNone
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -40
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ItemHeight = 48
      Items.Strings = (
        '222'
        '222'
        '222'
        '222'
        '222'
        '222'
        '222'
        '222')
      ParentFont = False
      TabOrder = 3
      OnDrawItem = lbPorcTotalDrawItem
    end
  end
  object Button1: TButton
    Left = 338
    Top = 94
    Width = 167
    Height = 24
    Caption = 'Actualizar'
    TabOrder = 1
    OnClick = Button1Click
  end
  object DTP: TDateTimePicker
    Left = 535
    Top = 24
    Width = 18
    Height = 21
    Date = 43967.398598784720000000
    Time = 43967.398598784720000000
    TabOrder = 2
    OnChange = DTPChange
  end
  object DBGrid1: TDBGrid
    Left = 559
    Top = 20
    Width = 265
    Height = 678
    DataSource = DataSource2
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    Options = [dgTitles, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    ParentFont = False
    PopupMenu = PopupMenu2
    TabOrder = 3
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    OnDrawColumnCell = DBGrid1DrawColumnCell
    OnDblClick = DBGrid1DblClick
    Columns = <
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'marcaTiempo'
        Title.Alignment = taCenter
        Title.Caption = 'Hora'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 73
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'nombre'
        Title.Alignment = taCenter
        Title.Caption = 'Comida'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 130
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'reparto'
        Title.Alignment = taCenter
        Title.Caption = 'Rep'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 38
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'tiempoRestante'
        Title.Alignment = taCenter
        Title.Caption = 'Min. Rest.'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 73
        Visible = True
      end>
  end
  object Button2: TButton
    Left = 0
    Top = 197
    Width = 264
    Height = 49
    Caption = 'Cargar bandejas'
    TabOrder = 6
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 287
    Top = 197
    Width = 263
    Height = 49
    Caption = 'Ver pedidos y clientes'
    TabOrder = 7
    OnClick = Button3Click
  end
  object Panel3: TPanel
    Left = 805
    Top = 20
    Width = 19
    Height = 678
    BevelOuter = bvNone
    Caption = 'Panel3'
    ParentBackground = False
    ShowCaption = False
    TabOrder = 8
  end
  object DBGrid2: TDBGrid
    Left = 813
    Top = 20
    Width = 576
    Height = 678
    DataSource = DataSource3
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    Options = [dgTitles, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    ParentFont = False
    PopupMenu = PopupMenu1
    TabOrder = 4
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    OnDrawColumnCell = DBGrid2DrawColumnCell
    OnDblClick = DBGrid2DblClick
    Columns = <
      item
        Expanded = False
        FieldName = 'nombre'
        Title.Alignment = taCenter
        Title.Caption = 'Comida especial'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 406
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'cant1'
        Title.Alignment = taCenter
        Title.Caption = ' 1'#176
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 40
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'cant2'
        Title.Alignment = taCenter
        Title.Caption = ' 2'#176
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 40
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'total'
        Title.Alignment = taCenter
        Title.Caption = 'Total'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 60
        Visible = True
      end>
  end
  object Panel2: TPanel
    Left = 553
    Top = 62
    Width = 808
    Height = 363
    Caption = 'Panel2'
    Color = 16758924
    ParentBackground = False
    ShowCaption = False
    TabOrder = 5
    object DBGrid3: TDBGrid
      Left = 6
      Top = 11
      Width = 798
      Height = 313
      DataSource = DataSource4
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      PopupMenu = PopupMenu3
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'Tahoma'
      TitleFont.Style = []
      OnColExit = DBGrid3ColExit
      OnDrawColumnCell = DBGrid3DrawColumnCell
      Columns = <
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'marcaTiempo'
          ReadOnly = True
          Title.Alignment = taCenter
          Title.Caption = 'Hora'
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -12
          Title.Font.Name = 'Tahoma'
          Title.Font.Style = [fsBold]
          Width = 93
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'nombre'
          ReadOnly = True
          Title.Alignment = taCenter
          Title.Caption = 'Comida'
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -12
          Title.Font.Name = 'Tahoma'
          Title.Font.Style = [fsBold]
          Width = 417
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'cliente'
          Title.Alignment = taCenter
          Title.Caption = 'Cliente'
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -12
          Title.Font.Name = 'Tahoma'
          Title.Font.Style = [fsBold]
          Width = 93
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'ordenReparto'
          ReadOnly = True
          Title.Alignment = taCenter
          Title.Caption = 'N'#176' Rep.'
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -12
          Title.Font.Name = 'Tahoma'
          Title.Font.Style = [fsBold]
          Width = 56
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'rep'
          ReadOnly = True
          Title.Alignment = taCenter
          Title.Caption = 'Repartidor'
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -12
          Title.Font.Name = 'Tahoma'
          Title.Font.Style = [fsBold]
          Width = 83
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'refEstadoPedido'
          Title.Alignment = taCenter
          Title.Caption = 'F'
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -12
          Title.Font.Name = 'Tahoma'
          Title.Font.Style = [fsBold]
          Width = 17
          Visible = True
        end>
    end
    object CB: TDBCheckBox
      Left = 547
      Top = 111
      Width = 14
      Height = 17
      Color = clWhite
      DataField = 'refEstadoPedido'
      DataSource = DataSource4
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
      TabOrder = 1
      ValueChecked = '4'
      ValueUnchecked = '1'
      Visible = False
    end
    object Button8: TButton
      Left = 328
      Top = 330
      Width = 145
      Height = 25
      Caption = 'Cerrar este cuadro'
      TabOrder = 2
      OnClick = Button8Click
    end
  end
  object Button4: TButton
    Left = 338
    Top = 14
    Width = 167
    Height = 25
    Caption = 'Gestionar alarmas'
    TabOrder = 9
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 338
    Top = 54
    Width = 167
    Height = 25
    Caption = 'Configurar alarmas'
    TabOrder = 10
    OnClick = Button5Click
  end
  object Panel4: TPanel
    Left = 108
    Top = 392
    Width = 330
    Height = 166
    Caption = 'Panel4'
    Color = 16758924
    ParentBackground = False
    ShowCaption = False
    TabOrder = 11
    object Label6: TLabel
      Left = 0
      Top = 24
      Width = 328
      Height = 19
      Alignment = taCenter
      AutoSize = False
      Caption = 'Cantidad de porciones de M  POLL'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Button6: TButton
      Left = 76
      Top = 128
      Width = 182
      Height = 25
      Caption = 'Actualizar y ocultar'
      TabOrder = 0
      OnClick = Button6Click
    end
    object Edit1: TEdit
      Left = 105
      Top = 67
      Width = 124
      Height = 43
      Alignment = taCenter
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -29
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      Text = '0'
      OnKeyDown = Edit1KeyDown
    end
  end
  object Button7: TButton
    Left = 533
    Top = 2
    Width = 23
    Height = 19
    Caption = 'Cfg'
    TabOrder = 12
    OnClick = Button7Click
  end
  object Panel5: TPanel
    Left = 784
    Top = 240
    Width = 185
    Height = 41
    Caption = 'Panel5'
    Color = 12611584
    ParentBackground = False
    TabOrder = 13
    Visible = False
  end
  object Panel6: TPanel
    Left = 784
    Top = 287
    Width = 185
    Height = 41
    Caption = 'Panel6'
    Color = 15921906
    ParentBackground = False
    TabOrder = 14
    Visible = False
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
    Left = 576
    Top = 88
  end
  object QueryInfo: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 616
    Top = 104
  end
  object Query1: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 656
    Top = 104
  end
  object DataSource2: TDataSource
    DataSet = CDS2
    Left = 1216
    Top = 264
  end
  object Query2: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 1053
    Top = 264
  end
  object DataSetProvider2: TDataSetProvider
    DataSet = Query2
    Left = 1120
    Top = 264
  end
  object CDS2: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider2'
    ReadOnly = True
    Left = 1168
    Top = 264
    object CDS2idComidaEspecial: TIntegerField
      FieldName = 'idComidaEspecial'
    end
    object CDS2nombre: TWideStringField
      FieldName = 'nombre'
    end
    object CDS2marcaTiempo: TSQLTimeStampField
      FieldName = 'marcaTiempo'
      DisplayFormat = 'hh:mm'
    end
    object CDS2tiempoRestante: TLargeintField
      FieldName = 'tiempoRestante'
    end
    object CDS2reparto: TIntegerField
      FieldName = 'reparto'
    end
  end
  object DataSource3: TDataSource
    DataSet = CDS3
    Left = 782
    Top = 100
  end
  object Query3: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 635
    Top = 116
  end
  object DataSetProvider3: TDataSetProvider
    DataSet = Query3
    Left = 686
    Top = 116
  end
  object CDS3: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider3'
    ReadOnly = True
    Left = 734
    Top = 105
    object WideStringField1: TWideStringField
      FieldName = 'nombre'
    end
    object CDS3cant1: TLargeintField
      FieldName = 'cant1'
    end
    object CDS3cant2: TLargeintField
      FieldName = 'cant2'
    end
    object CDS3refComida: TIntegerField
      FieldName = 'refComida'
    end
    object CDS3total: TLargeintField
      FieldName = 'total'
    end
    object CDS3idComidaEspecial: TIntegerField
      FieldName = 'idComidaEspecial'
    end
  end
  object DataSource4: TDataSource
    DataSet = CDS4
    Left = 728
    Top = 232
  end
  object Query4: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 581
    Top = 192
  end
  object DataSetProvider4: TDataSetProvider
    DataSet = Query4
    Left = 632
    Top = 232
  end
  object CDS4: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider4'
    Left = 680
    Top = 192
    object IntegerField1: TIntegerField
      FieldName = 'idComidaEspecial'
    end
    object IntegerField2: TIntegerField
      FieldName = 'refPedido'
    end
    object IntegerField3: TIntegerField
      FieldName = 'refComida'
    end
    object WideStringField2: TWideStringField
      FieldName = 'nombre'
    end
    object IntegerField4: TIntegerField
      FieldName = 'refEstadoPedido'
      OnChange = IntegerField4Change
    end
    object SQLTimeStampField1: TSQLTimeStampField
      FieldName = 'marcaTiempo'
      DisplayFormat = 'hh:mm:ss'
    end
    object CDS4rep: TWideStringField
      FieldName = 'rep'
    end
    object CDS4cliente: TWideStringField
      FieldName = 'cliente'
    end
    object CDS4ordenReparto: TLargeintField
      FieldName = 'ordenReparto'
    end
  end
  object QueryUpdate: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 592
    Top = 152
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 376
    Top = 144
  end
  object Timer2: TTimer
    Enabled = False
    Interval = 120000
    OnTimer = Timer2Timer
    Left = 8
    Top = 96
  end
  object Alarmas: TTimer
    OnTimer = AlarmasTimer
    Left = 324
    Top = 144
  end
  object QueryAlarma: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 561
    Top = 240
  end
  object PopupMenu1: TPopupMenu
    Left = 1008
    Top = 160
    object Mostrartodas1: TMenuItem
      Caption = 'Mostrar todas'
      OnClick = Mostrartodas1Click
    end
    object Ocultarfinalizadas1: TMenuItem
      Caption = 'Ocultar finalizadas'
      OnClick = Ocultarfinalizadas1Click
    end
  end
  object PopupMenu2: TPopupMenu
    Left = 744
    Top = 200
    object Ordenarporhoradeingreso1: TMenuItem
      Caption = 'Ordenar por hora de ingreso'
      OnClick = Ordenarporhoradeingreso1Click
    end
    object Ordenarporminutosrestantes1: TMenuItem
      Caption = 'Ordenar por minutos restantes'
      OnClick = Ordenarporminutosrestantes1Click
    end
  end
  object QueryAux: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 513
    Top = 136
  end
  object PopupMenu3: TPopupMenu
    Left = 888
    Top = 166
    object Vertodaslasopcionesdeestepedido1: TMenuItem
      Caption = 'Ver todas las opciones de este pedido'
      OnClick = Vertodaslasopcionesdeestepedido1Click
    end
  end
  object TimerError: TTimer
    Enabled = False
    Interval = 200
    OnTimer = TimerErrorTimer
    Left = 152
    Top = 144
  end
  object PopupMenu4: TPopupMenu
    Left = 176
    Top = 324
    object Verreceta1: TMenuItem
      Caption = 'Ver receta'
      Default = True
      OnClick = Verreceta1Click
    end
  end
end
