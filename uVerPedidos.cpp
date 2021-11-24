//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uVerPedidos.h"
#include "uVerDetallePedidos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfVerPedidos *fVerPedidos;
//---------------------------------------------------------------------------
__fastcall TfVerPedidos::TfVerPedidos(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfVerPedidos::Edit1Change(TObject *Sender)
{
   if(!Panel1->Visible)
   {
	  if(Edit1->Text == "")
	  {
		 ClientDataSet3->Active = false;
		 QueryCantidad->Close();
		 return;
	  }

	  ClientDataSet3->Active = false;
	  QueryCantidad->Close();
	  QueryCantidad->SQL->Clear();
	  String q;

	  q = "SELECT idCantidad, nroBandejas AS bandGrand, nroUnidades AS cantViandas, txtComplemento AS complemento, (sectorReparto + 1) AS reparto, "
		  "(SELECT descripcion FROM repartidores WHERE repartidores.idRepartidor = cantidades.refRepartidor LIMIT 1) AS repartidor, "
		  "(SELECT CONCAT(calle, ' ' ,numero) FROM clientes WHERE clientes.idCliente = cantidades.refCliente LIMIT 1) AS cliente "
		  "FROM cantidades WHERE fecha = :fecha AND refCliente IN( "
		  "(SELECT idCliente FROM clientes WHERE UPPER(calle) LIKE :texto OR UPPER(numero) LIKE :texto)) "
		  "ORDER BY repartidor, reparto LIMIT 7";

//	  q = "SELECT idCliente, IFNULL((SELECT nroBandejas FROM cantidades WHERE clientes.idCliente = cantidades.refCliente AND cantidades.fecha = :fecha),0) AS idCantidad, "
//		  "(SELECT IFNULL(idCantidad,0) FROM cantidades WHERE clientes.idCliente = cantidades.refCliente AND cantidades.fecha = :fecha) AS bandGrand, "
//		  "(SELECT IFNULL(nroUnidades,0) FROM cantidades WHERE clientes.idCliente = cantidades.refCliente AND cantidades.fecha = :fecha) AS cantViandas, "
//		  "(SELECT IFNULL(txtComplemento,0) FROM cantidades WHERE clientes.idCliente = cantidades.refCliente AND cantidades.fecha = :fecha) AS complemento, "
//		  "(SELECT IFNULL(sectorReparto + 1,0) FROM cantidades WHERE clientes.idCliente = cantidades.refCliente AND cantidades.fecha = :fecha) AS reparto, "
//		  "(SELECT IFNULL(descripcion, 'N/A') FROM repartidores WHERE repartidores.idRepartidor = "
//		  "(SELECT IFNULL(refRepartidor,0) FROM cantidades WHERE clientes.idCliente = cantidades.refCliente AND cantidades.fecha = :fecha LIMIT 1) "
//		  " LIMIT 1) AS repartidor, "
//		  "CONCAT(calle, ' ', numero) AS cliente "
//		  "FROM clientes WHERE idCliente > 2 AND UPPER(calle) LIKE :texto OR UPPER(numero) LIKE :texto "
//		  "ORDER BY repartidor, reparto LIMIT 10";


	  QueryCantidad->SQL->Add(q);
	  QueryCantidad->ParamByName("fecha")->AsDate = MC->Date;
	  QueryCantidad->ParamByName("texto")->AsString = "%" + Edit1->Text.UpperCase() + "%";
	  QueryCantidad->Open();
	  ClientDataSet3->Active = true;
   }
   else
   {
      if(Edit1->Text == "")
	  {
		 ClientDataSet1->Active = false;
		 QueryClientes->Close();
		 return;
	  }

	  ClientDataSet1->Active = false;
	  QueryClientes->Close();
	  QueryClientes->SQL->Clear();
	  String q;

	  q = "SELECT idCliente, calle, numero, "
		  "IFNULL((SELECT CONCAT(posicion, ' -  ' ,(SELECT descripcion FROM repartidores WHERE repartidores.idRepartidor = repartos.refRepartidor LIMIT 1)) FROM repartos WHERE repartos.refCliente = clientes.idCliente AND esSabado = 0 LIMIT 1), 'N/A') AS repLV, "
		  "IFNULL((SELECT CONCAT(posicion, ' -  ' ,(SELECT descripcion FROM repartidores WHERE repartidores.idRepartidor = repartos.refRepartidor LIMIT 1)) FROM repartos WHERE repartos.refCliente = clientes.idCliente AND esSabado = 1 LIMIT 1), 'N/A') AS repSab "
		  "FROM clientes WHERE UPPER(calle) LIKE :texto OR UPPER(numero) LIKE :texto ORDER BY calle LIMIT 7";

	  QueryClientes->SQL->Add(q);
	  QueryClientes->ParamByName("texto")->AsString = "%" + Edit1->Text.UpperCase() + "%";
	  QueryClientes->Open();
	  ClientDataSet1->Active = true;
   }

   ShowScrollBar(DBGrid2->Handle, SB_VERT, true);
}
//---------------------------------------------------------------------------
void __fastcall TfVerPedidos::FormClose(TObject *Sender, TCloseAction &Action)
{
   Edit1->Text = "";
   ClientDataSet3->Active = false;
   QueryCantidad->Close();
   ClientDataSet1->Active = false;
   QueryClientes->Close();
   SQLConnection1->Close();
   Panel1->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TfVerPedidos::Button1Click(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------
void __fastcall TfVerPedidos::Button2Click(TObject *Sender)
{
   Edit1->Text = "";
   Panel1->Visible = false;

   ClientDataSet3->Active = false;
   QueryCantidad->Close();
   QueryCantidad->SQL->Clear();
   String q;

   q = "SELECT idCantidad, nroBandejas AS bandGrand, nroUnidades AS cantViandas, txtComplemento AS complemento, (sectorReparto + 1) AS reparto, "
	   "(SELECT descripcion FROM repartidores WHERE repartidores.idRepartidor = cantidades.refRepartidor LIMIT 1) AS repartidor, "
	   "(SELECT CONCAT(calle, ' ' ,numero) FROM clientes WHERE clientes.idCliente = cantidades.refCliente LIMIT 1) AS cliente "
	   "FROM cantidades WHERE fecha = :fecha "
	   "ORDER BY repartidor, reparto";

   QueryCantidad->SQL->Add(q);
   QueryCantidad->ParamByName("fecha")->AsDate = MC->Date;
   QueryCantidad->Open();
   ClientDataSet3->Active = true;
   ShowScrollBar(DBGrid1->Handle, SB_VERT, true);
}
//---------------------------------------------------------------------------
void __fastcall TfVerPedidos::FormShow(TObject *Sender)
{
   TIniFile *Configuraciones;
   String Dir = GetCurrentDir()+"//Config.ini";
   Configuraciones = new TIniFile(Dir);

   SQLConnection1->Params->Values["HostName"] = Configuraciones->ReadString("MySQLServer","Servidor", "127.0.0.1");
   SQLConnection1->Params->Values["User_Name"] = "elsembrador";
   SQLConnection1->Params->Values["Password"] = "*-elsembrador63/*";

   delete Configuraciones;
}
//---------------------------------------------------------------------------
void __fastcall TfVerPedidos::Button4Click(TObject *Sender)
{
   Edit1->Text = "";
   ClientDataSet1->Active = false;
   QueryClientes->Close();
   Panel1->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TfVerPedidos::Button3Click(TObject *Sender)
{
   Edit1->Text = "";
   ClientDataSet3->Active = false;
   QueryCantidad->Close();
   Panel1->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TfVerPedidos::DBGrid1DblClick(TObject *Sender)
{
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT refCliente FROM cantidades WHERE idCantidad = :idCantidad LIMIT 1");
   QueryAux->ParamByName("idCantidad")->AsInteger = ClientDataSet3->FieldByName("idCantidad")->AsInteger;
   QueryAux->Open();
   int idC = QueryAux->FieldByName("refCliente")->AsInteger;
   QueryAux->Close();

   if(idC > 2)
   {
	  fVerDetallePedidos->idCliente = idC;
	  fVerDetallePedidos->ShowModal();
   }
}
//---------------------------------------------------------------------------

