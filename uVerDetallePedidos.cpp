//---------------------------------------------------------------------------

#include <vcl.h>
#include <DateUtils.hpp>
#pragma hdrstop

#include "uVerDetallePedidos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfVerDetallePedidos *fVerDetallePedidos;
//---------------------------------------------------------------------------
__fastcall TfVerDetallePedidos::TfVerDetallePedidos(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfVerDetallePedidos::FormShow(TObject *Sender)
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
   q = "SELECT CONCAT(calle,' ',numero) AS cliente "
	   "FROM clientes WHERE idCliente = :idCliente LIMIT 1";

   Query1->SQL->Add(q);
   Query1->ParamByName("idCliente")->AsInteger = idCliente;
   Query1->Open();
   Label1->Caption = "Cliente: " + Query1->FieldByName("cliente")->AsString;
   Query1->Close();

   periodo = 0;

   Query1->Close();
   Query1->SQL->Clear();
   q = "SELECT idPedido, momento AS fecha, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida1 LIMIT 1) AS opcion1, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida2 LIMIT 1) AS opcion2, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida3 LIMIT 1) AS opcion3, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida4 LIMIT 1) AS complemento "
	   "FROM pedidos WHERE refCliente = :refCliente AND DATE(momento) >= :fi AND DATE(momento) <= :ff";

   Query1->SQL->Add(q);
   Query1->ParamByName("refCliente")->AsInteger = idCliente;
   Query1->ParamByName("fi")->AsDate = IncWeek(StartOfTheWeek(Now()), periodo);
   Query1->ParamByName("ff")->AsDate = IncWeek(EndOfTheWeek(Now()), periodo);
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
void __fastcall TfVerDetallePedidos::Button1Click(TObject *Sender)
{
   periodo--;
   CDS1->Active = false;
   Query1->Close();
   Query1->SQL->Clear();
   String q;
   q = "SELECT idPedido, momento AS fecha, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida1 LIMIT 1) AS opcion1, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida2 LIMIT 1) AS opcion2, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida3 LIMIT 1) AS opcion3, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida4 LIMIT 1) AS complemento "
	   "FROM pedidos WHERE refCliente = :refCliente AND DATE(momento) >= :fi AND DATE(momento) <= :ff";

   Query1->SQL->Add(q);
   Query1->ParamByName("refCliente")->AsInteger = idCliente;
   Query1->ParamByName("fi")->AsDate = IncWeek(StartOfTheWeek(Now()), periodo);
   Query1->ParamByName("ff")->AsDate = IncWeek(EndOfTheWeek(Now()), periodo);
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
void __fastcall TfVerDetallePedidos::Button2Click(TObject *Sender)
{
   periodo++;
   CDS1->Active = false;
   Query1->Close();
   Query1->SQL->Clear();
   String q;
   q = "SELECT idPedido, momento AS fecha, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida1 LIMIT 1) AS opcion1, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida2 LIMIT 1) AS opcion2, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida3 LIMIT 1) AS opcion3, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida4 LIMIT 1) AS complemento "
	   "FROM pedidos WHERE refCliente = :refCliente AND DATE(momento) >= :fi AND DATE(momento) <= :ff";

   Query1->SQL->Add(q);
   Query1->ParamByName("refCliente")->AsInteger = idCliente;
   Query1->ParamByName("fi")->AsDate = IncWeek(StartOfTheWeek(Now()), periodo);
   Query1->ParamByName("ff")->AsDate = IncWeek(EndOfTheWeek(Now()), periodo);
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
void __fastcall TfVerDetallePedidos::FormClose(TObject *Sender, TCloseAction &Action)

{
   CDS1->Active = false;
   Query1->Close();

   SQLConnection1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TfVerDetallePedidos::CDS1fechaGetText(TField *Sender, UnicodeString &Text,
          bool DisplayText)
{
   if(DateOf(Sender->AsDateTime) == DateOf(Now()))
	  Text = "Hoy";
   else if(DateOf(Sender->AsDateTime) == IncDay(DateOf(Now()), -1))
	  Text = "Ayer";
   else
      Text = FormatDateTime("dd/mm/yyyy", Sender->AsString);
}
//---------------------------------------------------------------------------
void __fastcall TfVerDetallePedidos::DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State)
{
   if(State.Contains(gdSelected))
   {
	  dynamic_cast <TDBGrid *>(Sender)->Canvas->Font->Color = clWhite;
	  dynamic_cast <TDBGrid *>(Sender)->Canvas->Brush->Color = TColor(0x00C07000); //TColor(0x005E5EFF);
   }
   else
   {
	  if(dynamic_cast <TDBGrid *>(Sender)->DataSource->DataSet->RecNo % 2)
		 dynamic_cast <TDBGrid *>(Sender)->Canvas->Brush->Color = TColor(0x00F2F2F2);
	  else
		 dynamic_cast <TDBGrid *>(Sender)->Canvas->Brush->Color = TColor(0x00D9D9D9);
   }
   dynamic_cast <TDBGrid *>(Sender)->DefaultDrawColumnCell(Rect, DataCol, Column, State);
}
//---------------------------------------------------------------------------

