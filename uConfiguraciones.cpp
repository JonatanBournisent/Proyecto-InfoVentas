//---------------------------------------------------------------------------

#include <vcl.h>
#include <IniFiles.hpp>
#pragma hdrstop

#include "uConfiguraciones.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfConfiguraciones *fConfiguraciones;
//---------------------------------------------------------------------------
__fastcall TfConfiguraciones::TfConfiguraciones(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfConfiguraciones::FormShow(TObject *Sender)
{
   TIniFile *Configuraciones;
   String Dir = GetCurrentDir()+"//Config.ini";
   Configuraciones = new TIniFile(Dir);

   Edit1->Text = Configuraciones->ReadString("MySQLServer","Servidor", "127.0.0.1");

   delete Configuraciones;
}
//---------------------------------------------------------------------------
void __fastcall TfConfiguraciones::Button2Click(TObject *Sender)
{
   TIniFile *Configuraciones;
   String Dir = GetCurrentDir()+"//Config.ini";
   Configuraciones = new TIniFile(Dir);

   Configuraciones->WriteString("MySQLServer","Servidor",Edit1->Text);

   delete Configuraciones;

   Close();
}
//---------------------------------------------------------------------------
