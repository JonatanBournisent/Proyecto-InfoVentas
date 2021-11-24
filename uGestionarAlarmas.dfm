object fGestionarAlarmas: TfGestionarAlarmas
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'fGestionarAlarmas'
  ClientHeight = 473
  ClientWidth = 898
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
  object DBGrid1: TDBGrid
    Left = 7
    Top = 8
    Width = 882
    Height = 425
    DataSource = DataSource1
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
    PopupMenu = PopupMenu1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'marcaTiempo'
        Title.Alignment = taCenter
        Title.Caption = 'Momento'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 129
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'mensaje'
        Title.Alignment = taCenter
        Title.Caption = 'Mensaje'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 572
        Visible = True
      end
      item
        Alignment = taCenter
        Expanded = False
        FieldName = 'frec'
        Title.Alignment = taCenter
        Title.Caption = 'Frecuencia repeticion'
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -12
        Title.Font.Name = 'Tahoma'
        Title.Font.Style = [fsBold]
        Width = 145
        Visible = True
      end>
  end
  object Salir: TButton
    Left = 352
    Top = 440
    Width = 201
    Height = 25
    Caption = 'Salir'
    TabOrder = 1
    OnClick = SalirClick
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
    Left = 70
    Top = 34
  end
  object Query1: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 134
    Top = 32
  end
  object DataSetProvider1: TDataSetProvider
    DataSet = Query1
    Left = 198
    Top = 32
  end
  object CDS1: TClientDataSet
    Aggregates = <>
    Params = <>
    ProviderName = 'DataSetProvider1'
    ReadOnly = True
    Left = 246
    Top = 32
    object CDS1idAlarma: TIntegerField
      FieldName = 'idAlarma'
    end
    object CDS1mensaje: TWideStringField
      FieldName = 'mensaje'
      Size = 0
    end
    object CDS1marcaTiempo: TSQLTimeStampField
      FieldName = 'marcaTiempo'
    end
    object CDS1frec: TWideStringField
      FieldName = 'frec'
      Size = 0
    end
  end
  object DataSource1: TDataSource
    DataSet = CDS1
    Left = 286
    Top = 32
  end
  object PopupMenu1: TPopupMenu
    Left = 286
    Top = 216
    object Modificarestaalarma1: TMenuItem
      Caption = 'Modificar esta alarma'
      OnClick = Modificarestaalarma1Click
    end
    object Eliminar1: TMenuItem
      Caption = 'Eliminar esta alarma'
      OnClick = Eliminar1Click
    end
  end
  object QueryDelete: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 126
    Top = 144
  end
end
