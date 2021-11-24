//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uGestionarAlarmas.h"
#include "uConfigurarAlarma.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfGestionarAlarmas *fGestionarAlarmas;
//---------------------------------------------------------------------------
__fastcall TfGestionarAlarmas::TfGestionarAlarmas(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfGestionarAlarmas::SalirClick(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------
void __fastcall TfGestionarAlarmas::Eliminar1Click(TObject *Sender)
{
   if(!CDS1->Active)
	  return;

   QueryDelete->Close();
   QueryDelete->SQL->Clear();
   String q;
   q = "DELETE FROM alarmas WHERE idAlarma = :idAlarma LIMIT 1";
   QueryDelete->SQL->Add(q);
   QueryDelete->ParamByName("idAlarma")->AsInteger = CDS1->FieldByName("idAlarma")->AsInteger;
   QueryDelete->ExecSQL();
}
//---------------------------------------------------------------------------
void __fastcall TfGestionarAlarmas::Modificarestaalarma1Click(TObject *Sender)
{
   if(!CDS1->Active)
	  return;

   fConfigurarAlarma->llamador = 1;
   fConfigurarAlarma->idAlarma = CDS1->FieldByName("idAlarma")->AsInteger;
   fConfigurarAlarma->ShowModal();
   CDS1->Refresh();

   ShowScrollBar(DBGrid1->Handle, SB_VERT, true);
}
//---------------------------------------------------------------------------
void __fastcall TfGestionarAlarmas::FormShow(TObject *Sender)
{
   TIniFile *Configuraciones;
   String Dir = GetCurrentDir()+"//Config.ini";
   Configuraciones = new TIniFile(Dir);

   SQLConnection1->Params->Values["HostName"] = Configuraciones->ReadString("MySQLServer","Servidor", "127.0.0.1");
   SQLConnection1->Params->Values["User_Name"] = "elsembrador";
   SQLConnection1->Params->Values["Password"] = "*-elsembrador63/*";

   delete Configuraciones;

   CDS1->Active = false;

   Query1->Close();
   Query1->SQL->Clear();
   String q;
   q = "SELECT *, ELT(frecuenciaRepeticion + 1, 'No repetir', 'Diariamente', 'Semanalmente') AS frec FROM alarmas WHERE vista = 0 AND paraCocina = 1";

   Query1->SQL->Add(q);
   Query1->Open();

   if(Query1->IsEmpty())
   {
	  Query1->Close();
	  return;
   }

   CDS1->Active = true;

   ShowScrollBar(DBGrid1->Handle, SB_VERT, true);
}
//---------------------------------------------------------------------------
void __fastcall TfGestionarAlarmas::FormClose(TObject *Sender, TCloseAction &Action)

{
   CDS1->Active = false;
   Query1->Close();
   SQLConnection1->Close();
}
//---------------------------------------------------------------------------
