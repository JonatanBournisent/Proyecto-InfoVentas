object fConfiguraciones: TfConfiguraciones
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = ' Configuraciones'
  ClientHeight = 121
  ClientWidth = 201
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label12: TLabel
    Left = 20
    Top = 21
    Width = 162
    Height = 13
    Caption = 'IP o nombre del servidor de datos'
  end
  object Button2: TButton
    Left = 20
    Top = 81
    Width = 162
    Height = 25
    Caption = 'Guardar configuraciones y salir'
    TabOrder = 0
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 20
    Top = 40
    Width = 162
    Height = 21
    TabOrder = 1
    Text = '127.0.0.1'
  end
end
