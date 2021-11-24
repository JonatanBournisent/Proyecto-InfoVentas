object fConfigurarAlarma: TfConfigurarAlarma
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = ' Configurar alarma'
  ClientHeight = 589
  ClientWidth = 384
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
    Left = 9
    Top = 430
    Width = 44
    Height = 13
    Caption = 'Mensaje:'
  end
  object MC: TMonthCalendar
    Left = 49
    Top = 0
    Width = 273
    Height = 169
    Date = 43982.887391458330000000
    ShowToday = False
    ShowTodayCircle = False
    TabOrder = 0
  end
  object DTP: TDateTimePicker
    Left = 122
    Top = 175
    Width = 127
    Height = 47
    Date = 43982.792124895830000000
    Format = 'HH:mm'
    Time = 43982.792124895830000000
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    Kind = dtkTime
    ParentFont = False
    TabOrder = 1
  end
  object Memo1: TMemo
    Left = 9
    Top = 448
    Width = 369
    Height = 89
    Lines.Strings = (
      'Memo1')
    TabOrder = 2
  end
  object Button1: TButton
    Left = 33
    Top = 552
    Width = 145
    Height = 25
    Caption = 'Guardar esta alarma'
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 205
    Top = 552
    Width = 145
    Height = 25
    Caption = 'Cancelar y salir'
    TabOrder = 4
    OnClick = Button2Click
  end
  object RadioGroup1: TRadioGroup
    Left = 88
    Top = 241
    Width = 186
    Height = 131
    Caption = 'Repetir?'
    ItemIndex = 0
    Items.Strings = (
      'No repetir'
      'Repetir diariamente'
      'Repetir semanalmente')
    TabOrder = 5
  end
  object CheckBox1: TCheckBox
    Left = 122
    Top = 392
    Width = 124
    Height = 17
    Caption = 'Dirigida a la cocina'
    Checked = True
    State = cbChecked
    TabOrder = 6
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
    Left = 30
    Top = 26
  end
  object Query1: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 86
    Top = 24
  end
end
