object fAlarma: TfAlarma
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = 'Alarma'
  ClientHeight = 160
  ClientWidth = 385
  Color = clRed
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 19
    Top = 19
    Width = 345
    Height = 89
    Lines.Strings = (
      'Memo1')
    ReadOnly = True
    TabOrder = 0
  end
  object Button1: TButton
    Left = 19
    Top = 121
    Width = 154
    Height = 25
    Caption = 'Reprogramar'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 211
    Top = 121
    Width = 153
    Height = 25
    Caption = 'Marcar como vista y salir'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 500
    OnTimer = Timer1Timer
    Left = 160
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
    Left = 353
    Top = 10
  end
  object Query1: TSQLQuery
    MaxBlobSize = -1
    Params = <>
    SQLConnection = SQLConnection1
    Left = 353
    Top = 8
  end
  object Timer2: TTimer
    Enabled = False
    Interval = 15000
    OnTimer = Timer2Timer
    Left = 8
    Top = 8
  end
end
