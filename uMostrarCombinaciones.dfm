object fMostrarCombinaciones: TfMostrarCombinaciones
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = ' Combinaciones de bandejas'
  ClientHeight = 726
  ClientWidth = 1389
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poOwnerFormCenter
  OnClose = FormClose
  OnCreate = FormCreate
  OnDestroy = FormDestroy
  OnKeyDown = FormKeyDown
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object DTP: TDateTimePicker
    Left = 635
    Top = 35
    Width = 186
    Height = 21
    Date = 43967.398598784720000000
    Time = 43967.398598784720000000
    TabOrder = 0
    Visible = False
  end
  object Button2: TButton
    Left = 603
    Top = 671
    Width = 184
    Height = 34
    Caption = 'Salir'
    TabOrder = 1
    OnClick = Button2Click
  end
  object RG1: TRadioGroup
    Left = 8
    Top = 653
    Width = 241
    Height = 69
    ItemIndex = 0
    Items.Strings = (
      'Mostrar bandejas del primer reparto'
      'Mostrar bandejas del segundo reparto')
    TabOrder = 2
    OnClick = RG1Click
  end
  object RG2: TRadioGroup
    Left = 1163
    Top = 653
    Width = 218
    Height = 69
    ItemIndex = 0
    Items.Strings = (
      'Dos o mas bandejas iguales'
      'Combinaciones '#250'nicas')
    TabOrder = 3
    OnClick = RG2Click
  end
  object ScrollBox1: TScrollBox
    Left = 8
    Top = 8
    Width = 1373
    Height = 640
    HorzScrollBar.Increment = 200
    HorzScrollBar.Range = 2000
    HorzScrollBar.Tracking = True
    VertScrollBar.Increment = 100
    VertScrollBar.Range = 1500
    VertScrollBar.Tracking = True
    AutoScroll = False
    TabOrder = 4
    OnMouseWheel = ScrollBox1MouseWheel
    object lbCombCom: TListBox
      Left = 3
      Top = -2
      Width = 1346
      Height = 1500
      Style = lbOwnerDrawFixed
      ExtendedSelect = False
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -37
      Font.Name = 'Calibri'
      Font.Style = [fsBold]
      ItemHeight = 45
      Items.Strings = (
        'texto'
        'de'
        'prueba')
      ParentFont = False
      PopupMenu = PopupMenu1
      TabOrder = 0
      OnDrawItem = lbCombComDrawItem
      OnExit = lbCombComExit
      OnKeyDown = lbCombComKeyDown
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
    Left = 88
    Top = 40
  end
  object QueryInfo: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 176
    Top = 40
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 60000
    OnTimer = Timer1Timer
    Left = 16
    Top = 112
  end
  object PopupMenu1: TPopupMenu
    Left = 280
    Top = 144
    object Guardarcantidaddereferencia1: TMenuItem
      Caption = 'Guardar marca de cantidad realizada'
      OnClick = Guardarcantidaddereferencia1Click
    end
  end
end
