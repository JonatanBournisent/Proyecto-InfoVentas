//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uAlarma.h"
#include "uMain.h"
#include "uConfigurarAlarma.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfAlarma *fAlarma;
//---------------------------------------------------------------------------
__fastcall TfAlarma::TfAlarma(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfAlarma::Button1Click(TObject *Sender)
{
   fConfigurarAlarma->llamador = 1;
   fConfigurarAlarma->idAlarma = idAlarma;
   fConfigurarAlarma->ShowModal();
   fAlarma->Close();
}
//---------------------------------------------------------------------------
void __fastcall TfAlarma::Timer1Timer(TObject *Sender)
{
   if(fAlarma->Color == clRed)
	  fAlarma->Color = clYellow;
   else
      fAlarma->Color = clRed;
}
//---------------------------------------------------------------------------
void __fastcall TfAlarma::Button2Click(TObject *Sender)
{
   Query1->Close();
   Query1->SQL->Clear();
   String q;
   if(frecuenciaRepeticion == 0)
	  q = "UPDATE alarmas SET vista = 1 WHERE idAlarma = :idAlarma LIMIT 1";
   else if(frecuenciaRepeticion == 1)
	  q = "UPDATE alarmas SET marcaTiempo = DATE_ADD(marcaTiempo, INTERVAL 1 DAY) WHERE idAlarma = :idAlarma LIMIT 1";
   else if(frecuenciaRepeticion == 2)
	  q = "UPDATE alarmas SET marcaTiempo = DATE_ADD(marcaTiempo, INTERVAL 7 DAY) WHERE idAlarma = :idAlarma LIMIT 1";

   Query1->SQL->Add(q);
   Query1->ParamByName("idAlarma")->AsInteger = idAlarma;
   Query1->ExecSQL();

   Query1->Close();
   Query1->SQL->Clear();
   Query1->SQL->Add("SELECT IFNULL(idAlarma,0) AS idAlarma, marcaTiempo FROM alarmas WHERE vista = 0 AND paraCocina = 1 ORDER BY marcaTiempo LIMIT 1");
   Query1->Open();
   fMain->idProximaAlarma = Query1->FieldByName("idAlarma")->AsInteger;
   fMain->proximaAlarma = Query1->FieldByName("marcaTiempo")->AsDateTime;
   Query1->Close();

   Close();
}
//---------------------------------------------------------------------------
void __fastcall TfAlarma::FormShow(TObject *Sender)
{
   TIniFile *Configuraciones;
   String Dir = GetCurrentDir()+"//Config.ini";
   Configuraciones = new TIniFile(Dir);

   SQLConnection1->Params->Values["HostName"] = Configuraciones->ReadString("MySQLServer","Servidor", "127.0.0.1");
   SQLConnection1->Params->Values["User_Name"] = "elsembrador";
   SQLConnection1->Params->Values["Password"] = "*-elsembrador63/*";

   delete Configuraciones;

   Query1->Close();
   Query1->SQL->Clear();
   String q;
   q = "SELECT mensaje, frecuenciaRepeticion FROM alarmas WHERE idAlarma = :idAlarma LIMIT 1";
   Query1->SQL->Add(q);
   Query1->ParamByName("idAlarma")->AsInteger = idAlarma;
   Query1->Open();
   Memo1->Text = Query1->FieldByName("mensaje")->AsString;
   frecuenciaRepeticion = Query1->FieldByName("frecuenciaRepeticion")->AsInteger;
   Query1->Close();
   Timer1->Enabled = true;
   Timer2->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TfAlarma::FormClose(TObject *Sender, TCloseAction &Action)
{
   Timer1->Enabled = false;
   Timer2->Enabled = false;
   Query1->Close();
   SQLConnection1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfAlarma::Timer2Timer(TObject *Sender)
{
   Query1->Close();
   Query1->SQL->Clear();
   String q;
   q = "SELECT idAlarma FROM alarmas WHERE idAlarma = :idAlarma AND vista = 0 LIMIT 1";
   Query1->SQL->Add(q);
   Query1->ParamByName("idAlarma")->AsInteger = idAlarma;
   Query1->Open();
   if(Query1->IsEmpty())
   {
      fAlarma->Close();
   }
   Query1->Close();
}
//---------------------------------------------------------------------------

