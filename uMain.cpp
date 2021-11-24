//---------------------------------------------------------------------------

#include <vcl.h>
#include <DateUtils.hpp>
#pragma hdrstop

#include "uMain.h"
#include "uAlarma.h"
#include "fRecetas.h"
#include "uMostrarCombinaciones.h"
#include "uGestionarAlarmas.h"
#include "uConfigurarAlarma.h"
#include "uVerPedidos.h"
#include "uConfiguraciones.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfMain *fMain;
//---------------------------------------------------------------------------
__fastcall TfMain::TfMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfMain::DTPChange(TObject *Sender)
{
   lbCodigo->Clear();
   lbPorcPrim->Clear();
   lbPorcSeg->Clear();
   lbPorcTotal->Clear();

   Query1->Close();
   Query1->SQL->Clear();
   String q = "SELECT *, "
			  "(SELECT codigo FROM comidas WHERE idComida = refComida1) AS c1, "
			  "(SELECT codigo FROM comidas WHERE idComida = refComida2) AS c2, "
			  "(SELECT codigo FROM comidas WHERE idComida = refComida3) AS c3, "
			  "(SELECT codigo FROM comidas WHERE idComida = refComida4) AS c4, "
			  "(SELECT codigo FROM comidas WHERE idComida = refComida5) AS c5, "
			  "(SELECT codigo FROM comidas WHERE idComida = refComida6) AS c6, "
			  "(SELECT codigo FROM comidas WHERE idComida = refComida7) AS c7, "
			  "(SELECT codigo FROM comidas WHERE idComida = refComida8) AS c8 "
			  "FROM menudeldia WHERE (fecha = :f) LIMIT 1";
   Query1->SQL->Add(q);
   Query1->ParamByName("f")->AsDate = DTP->Date;
   Query1->Open();

   for(int i = 0; i < 9; i++)
      arrIdComida[i] = 1;

   if(Query1->IsEmpty())
   {
	  Query1->Close();
	  return;
   }
   else
   {
	  int iID = 0;
	  lbCodigo->Items->Add(Query1->FieldByName("c1")->AsString);
	  lbPorcPrim->Items->Add("0");
	  lbPorcSeg->Items->Add("0");
	  lbPorcTotal->Items->Add("0");

	  //opciones[iID] = Query1->FieldByName("c1")->AsString;
	  arrIdComida[iID] = Query1->FieldByName("refComida1")->AsInteger;
	  iID++;


	  if(Query1->FieldByName("refComida2")->AsInteger != 1)
	  {
		 lbCodigo->Items->Add(Query1->FieldByName("c2")->AsString);
		 lbPorcPrim->Items->Add("0");
		 lbPorcSeg->Items->Add("0");
		 lbPorcTotal->Items->Add("0");
		 //opciones[iID] = Query1->FieldByName("c2")->AsString;
		 arrIdComida[iID] = Query1->FieldByName("refComida2")->AsInteger;
		 iID++;
	  }
	  if(Query1->FieldByName("refComida3")->AsInteger != 1)
	  {
		 lbCodigo->Items->Add(Query1->FieldByName("c3")->AsString);
		 lbPorcPrim->Items->Add("0");
		 lbPorcSeg->Items->Add("0");
		 lbPorcTotal->Items->Add("0");
		 //opciones[iID] = Query1->FieldByName("c3")->AsString;
		 arrIdComida[iID] = Query1->FieldByName("refComida3")->AsInteger;
		 iID++;
	  }
	  if(Query1->FieldByName("refComida4")->AsInteger != 1)
	  {
		 lbCodigo->Items->Add(Query1->FieldByName("c4")->AsString);
		 lbPorcPrim->Items->Add("0");
		 lbPorcSeg->Items->Add("0");
		 lbPorcTotal->Items->Add("0");
		 //opciones[iID] = Query1->FieldByName("c4")->AsString;
		 arrIdComida[iID] = Query1->FieldByName("refComida4")->AsInteger;
		 iID++;
	  }
	  if(Query1->FieldByName("refComida5")->AsInteger != 1)
	  {
		 lbCodigo->Items->Add(Query1->FieldByName("c5")->AsString);
		 lbPorcPrim->Items->Add("0");
		 lbPorcSeg->Items->Add("0");
		 lbPorcTotal->Items->Add("0");
		 //opciones[iID] = Query1->FieldByName("c5")->AsString;
		 arrIdComida[iID] = Query1->FieldByName("refComida5")->AsInteger;
		 iID++;
	  }
	  if(Query1->FieldByName("refComida6")->AsInteger != 1)
	  {
		 lbCodigo->Items->Add(Query1->FieldByName("c6")->AsString);
		 lbPorcPrim->Items->Add("0");
		 lbPorcSeg->Items->Add("0");
		 lbPorcTotal->Items->Add("0");
		 //opciones[iID] = Query1->FieldByName("c6")->AsString;
		 arrIdComida[iID] = Query1->FieldByName("refComida6")->AsInteger;
		 iID++;
	  }
	  if(Query1->FieldByName("refComida7")->AsInteger != 1)
	  {
		 lbCodigo->Items->Add("1"); //Query1->FieldByName("c7")->AsString
		 lbPorcPrim->Items->Add("0");
		 lbPorcSeg->Items->Add("0");
		 lbPorcTotal->Items->Add("0");
		 //opciones[iID] = Query1->FieldByName("c7")->AsString;
		 arrIdComida[iID] = Query1->FieldByName("refComida7")->AsInteger;
		 iID++;
	  }
	  if(Query1->FieldByName("refComida8")->AsInteger != 1)
	  {
		 lbCodigo->Items->Add("ENS"); //Query1->FieldByName("c8")->AsString
		 lbPorcPrim->Items->Add("0");
		 lbPorcSeg->Items->Add("0");
		 lbPorcTotal->Items->Add("0");
		 //opciones[iID] = Query1->FieldByName("c8")->AsString;
		 arrIdComida[iID] = Query1->FieldByName("refComida8")->AsInteger;
		 iID++;
	  }

	  Query1->Close();
   }
}
//---------------------------------------------------------------------------

void __fastcall TfMain::lbCodigoDrawItem(TWinControl *Control, int Index, TRect &Rect,
		  TOwnerDrawState State)
{
//   if(Index % 2 == 0)
//	  lbCodigo->Canvas->Brush->Color = TColor(0x00FFE1DF);

   if((arrCantPorciones[Index] - StrToInt(lbPorcTotal->Items->Strings[Index])) > 15)
	  lbCodigo->Canvas->Brush->Color = TColor(0x0076DC7B);
   else if((arrCantPorciones[Index] - StrToInt(lbPorcTotal->Items->Strings[Index])) > 5)
	  lbCodigo->Canvas->Brush->Color = TColor(0x00B3FFFF);
   else if((arrCantPorciones[Index] - StrToInt(lbPorcTotal->Items->Strings[Index])) > 0)
	  lbCodigo->Canvas->Brush->Color = TColor(0x009595FF);   //00B3FFFF 004F4FFF
   else if((arrCantPorciones[Index] - StrToInt(lbPorcTotal->Items->Strings[Index])) <= 0)
	  lbCodigo->Canvas->Brush->Color = TColor(0x004F4FFF);


   String s = lbCodigo->Items->Strings[Index];
   int l;
   if(Index <= lbCodigo->Items->Count - 3)
   {
	  lbCodigo->Canvas->Font->Color = clBlack;
	  l = Rect.Left + 1;
   }
   else
   {
	  if((arrCantPorciones[Index] - StrToInt(lbPorcTotal->Items->Strings[Index])) <= 5)
		 lbCodigo->Canvas->Font->Color = clWhite;
	  else
	     lbCodigo->Canvas->Font->Color = TColor(0x00C07000); //clRed;
	  l = Rect.Left + (Rect.Width() - lbCodigo->Canvas->TextWidth(s)) / 2;
   }

   lbCodigo->Canvas->FillRect(Rect);
   lbCodigo->Canvas->TextOutW(l, Rect.Top, s);
}
//---------------------------------------------------------------------------

void __fastcall TfMain::lbPorcPrimDrawItem(TWinControl *Control, int Index, TRect &Rect,
		  TOwnerDrawState State)
{
   if(Index % 2 == 0)
	  lbPorcPrim->Canvas->Brush->Color = TColor(0x00F2F2F2);
   else
	  lbPorcPrim->Canvas->Brush->Color = TColor(0x00D9D9D9);

   if(Index <= lbPorcPrim->Items->Count - 3)
	  lbPorcPrim->Canvas->Font->Color = clBlack;
   else
	  lbPorcPrim->Canvas->Font->Color = TColor(0x00C07000); //clRed;

   String s = lbPorcPrim->Items->Strings[Index];
   int l = Rect.Left + (Rect.Width() - lbPorcPrim->Canvas->TextWidth(s)) / 2;

   lbPorcPrim->Canvas->FillRect(Rect);
   lbPorcPrim->Canvas->TextOutW(l, Rect.Top, s);
}
//---------------------------------------------------------------------------

void __fastcall TfMain::lbPorcSegDrawItem(TWinControl *Control, int Index, TRect &Rect,
		  TOwnerDrawState State)
{
   if(Index % 2 == 0)
	  lbPorcSeg->Canvas->Brush->Color = TColor(0x00F2F2F2);
   else
	  lbPorcSeg->Canvas->Brush->Color = TColor(0x00D9D9D9);

   if(Index <= lbPorcSeg->Items->Count - 3)
	  lbPorcSeg->Canvas->Font->Color = clBlack;
   else
	  lbPorcSeg->Canvas->Font->Color = TColor(0x00C07000); //clRed;

   String s = lbPorcSeg->Items->Strings[Index];
   int l = Rect.Left + (Rect.Width() - lbPorcSeg->Canvas->TextWidth(s)) / 2;

   lbPorcSeg->Canvas->FillRect(Rect);
   lbPorcSeg->Canvas->TextOutW(l, Rect.Top, s);
}
//---------------------------------------------------------------------------

void __fastcall TfMain::lbPorcTotalDrawItem(TWinControl *Control, int Index, TRect &Rect,
		  TOwnerDrawState State)
{

   if(Index % 2 == 0)
	  lbPorcTotal->Canvas->Brush->Color = TColor(0x00F2F2F2);
   else
	  lbPorcTotal->Canvas->Brush->Color = TColor(0x00D9D9D9);

   if(Index <= lbPorcTotal->Items->Count - 3)
	  lbPorcTotal->Canvas->Font->Color = clBlack;
   else
	  lbPorcTotal->Canvas->Font->Color = TColor(0x00C07000); //clRed;

   String s = lbPorcTotal->Items->Strings[Index];
   int l = Rect.Left + (Rect.Width() - lbPorcTotal->Canvas->TextWidth(s)) / 2;

   lbPorcTotal->Canvas->FillRect(Rect);
   lbPorcTotal->Canvas->TextOutW(l, Rect.Top, s);
}
//---------------------------------------------------------------------------

void __fastcall TfMain::DBGrid2DblClick(TObject *Sender)
{
   if(!CDS3->Active)
      return;

   String q;
   CDS4->Active = false;
   Query4->Close();
   Query4->SQL->Clear();
   q = "SELECT idComidaEspecial, refPedido, refComida, refEstadoPedido, marcaTiempo, (ordenReparto + 1) AS ordenReparto, "
	   "(SELECT nombre FROM comidas WHERE comidas.idComida = comidasespeciales.refComida LIMIT 1) AS nombre, "

	   "(SELECT nombreCorto FROM repartidores WHERE idRepartidor = "
	   "(SELECT refRepartidor FROM cantidades WHERE "
		 "(SELECT refCantidad FROM pedidos WHERE "
		   "DATE(momento) = :f AND pedidos.idPedido = comidasespeciales.refPedido LIMIT 1) "
		   "= cantidades.idCantidad LIMIT 1) LIMIT 1) AS rep, "


	   "(SELECT numero FROM clientes WHERE clientes.idCliente = (SELECT refCliente FROM pedidos WHERE pedidos.idPedido = comidasespeciales.refPedido LIMIT 1) LIMIT 1) AS cliente "
	   "FROM comidasespeciales WHERE idComidaEspecial = :id ORDER BY ordenReparto";
   Query4->SQL->Add(q);
   Query4->ParamByName("f")->AsDate = DTP->Date;
   Query4->ParamByName("id")->AsInteger = CDS3->FieldByName("idComidaEspecial")->AsInteger;
   Query4->Open();
   CDS4->Active = true;

   Panel2->Top = (fMain->Height - Panel2->Height) / 2;
   Panel2->Left = (fMain->Width - Panel2->Width) / 2;
   Panel2->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TfMain::DBGrid3DrawColumnCell(TObject *Sender, const TRect &Rect,
          int DataCol, TColumn *Column, TGridDrawState State)
{
   int DrawState;
   if(State.Contains(gdFocused))
   {
	  if(Column->Field == CB->Field)
      {
		 CB->Left = Rect.Left + DBGrid3->Left + 2;
		 CB->Top = Rect.Top + DBGrid3->Top + 2;
		 CB->Width = Rect.Right - Rect.Left;
		 CB->Height = Rect.Bottom - Rect.Top;

		 CB->Visible = true;
	  }
   }
   else if(Column->Field == CB->Field)
   {
      DrawRect = new TRect(Rect);
	  InflateRect(DrawRect,-1,-1);

	  if(Column->Field->AsInteger == 1)
         DrawState = DFCS_BUTTONCHECK;
	  else
         DrawState = DFCS_BUTTONCHECK | DFCS_CHECKED;

	  DBGrid3->Canvas->FillRect(Rect);
	  DrawFrameControl(DBGrid3->Canvas->Handle , DrawRect, DFC_BUTTON, DrawState);
      delete DrawRect;
   }
}
//---------------------------------------------------------------------------

void __fastcall TfMain::DBGrid3ColExit(TObject *Sender)
{
   if(DBGrid3->SelectedField == CB->Field)
      CB->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TfMain::IntegerField4Change(TField *Sender)
{
   QueryUpdate->Close();
   QueryUpdate->SQL->Clear();
   QueryUpdate->SQL->Add("UPDATE comidasespeciales SET refEstadoPedido = :ep WHERE idComidaEspecial = :id LIMIT 1");
   QueryUpdate->ParamByName("ep")->AsInteger = CDS4->FieldByName("refEstadoPedido")->AsInteger;
   QueryUpdate->ParamByName("id")->AsInteger = CDS4->FieldByName("idComidaEspecial")->AsInteger;
   QueryUpdate->ExecSQL();
}
//---------------------------------------------------------------------------


void __fastcall TfMain::FormShow(TObject *Sender)
{
   TIniFile *Configuraciones;
   String Dir = GetCurrentDir()+"//Config.ini";
   Configuraciones = new TIniFile(Dir);

   SQLConnection1->Params->Values["HostName"] = Configuraciones->ReadString("MySQLServer","Servidor", "127.0.0.1");
   SQLConnection1->Params->Values["User_Name"] = "elsembrador";
   SQLConnection1->Params->Values["Password"] = "*-elsembrador63/*";

   delete Configuraciones;

   DTP->DateTime = Now();

   Panel2->Visible = false;
   Panel4->Visible = false;
   Label5->Caption = FormatDateTime("dddd dd 'de' mmmm 'de' yyyy",Now());
   ocultarFinalizadas = true;
//   ordenarPorHoraIngreso = true;
//   DBGrid1->Columns->Items[0]->Width = 73;
   ordenarPorHoraIngreso = false;
   DBGrid1->Columns->Items[0]->Width = 0;
   contadorAlarma = 0;

   try
   {
	   QueryAlarma->Close();
	   QueryAlarma->SQL->Clear();
	   QueryAlarma->SQL->Add("SELECT IFNULL(idAlarma,0) AS idAlarma, marcaTiempo FROM alarmas WHERE vista = 0 AND paraCocina = 1 ORDER BY marcaTiempo LIMIT 1");
	   QueryAlarma->Open();
	   idProximaAlarma = QueryAlarma->FieldByName("idAlarma")->AsInteger;
	   proximaAlarma = QueryAlarma->FieldByName("marcaTiempo")->AsDateTime;
	   QueryAlarma->Close();

	   QueryUpdate->Close();
	   QueryUpdate->SQL->Clear();
	   QueryUpdate->SQL->Add("DELETE FROM porcionesrealizadas WHERE fecha < DATE_SUB(NOW(), INTERVAL 30 DAY)");
	   QueryUpdate->ExecSQL();

	   DTPChange(fMain);

	   Timer2->Enabled = true;
	   Timer2Timer(Timer2);
   }
   catch(...)
   {
	  Alarmas->Enabled = false;
	  Timer2->Enabled = false;
	  Application->MessageBox(L"Al parecer hubo un problema al intentar conectar con el servidor. Solucione el problema y reinicie el programa." ,L"Posible error de conexión...",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
   }
}
//---------------------------------------------------------------------------

void __fastcall TfMain::Timer1Timer(TObject *Sender)
{
   String s = FormatDateTime("hh:mm", Now());
   if(Reloj->Caption != s)
      Reloj->Caption = s;
}
//---------------------------------------------------------------------------


void __fastcall TfMain::Button2Click(TObject *Sender)
{
   fMostrarCombinaciones->DTP->Date = DTP->Date;
   Timer2->Enabled = false;
   fMostrarCombinaciones->ShowModal();
   Timer2->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfMain::Button3Click(TObject *Sender)
{
   fVerPedidos->MC->Date = DTP->Date;
   Timer2->Enabled = false;
   fVerPedidos->ShowModal();
   Timer2->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfMain::Timer2Timer(TObject *Sender)
{
   Timer2->Enabled = false;
   String q = "SELECT todas AS idComida, COUNT(*) AS cantidad, (SELECT nombre FROM comidas WHERE t.todas = comidas.idComida) AS nComida "
			  "FROM ((SELECT refComida1 AS todas FROM pedidos WHERE DATE(momento) = :f AND refComida1 > 1) "
			  "UNION ALL (SELECT refComida2 AS todas FROM pedidos WHERE DATE(momento) = :f AND refComida2 > 1) "
			  "UNION ALL (SELECT refComida3 AS todas FROM pedidos WHERE DATE(momento) = :f AND refComida3 > 1) "
			  "UNION ALL (SELECT refComida4 AS todas FROM pedidos WHERE DATE(momento) = :f AND refComida4 > 1)) t GROUP BY todas ";

   try
   {
	  QueryInfo->Close();
	  QueryInfo->SQL->Clear();
	  QueryInfo->SQL->Add(q);
	  QueryInfo->ParamByName("f")->AsDate = DTP->Date;
	  QueryInfo->Open();
   }
   catch(...)
   {
	  Alarmas->Enabled = false;
	  Timer2->Enabled = false;
	  Application->MessageBox(L"Al parecer hubo un problema al intentar conectar con el servidor. Solucione el problema y reinicie el programa." ,L"Posible error de conexión...",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
	  TimerError->Enabled = true;
	  return;
   }


   int id;
   int i;
   while(!QueryInfo->Eof)
   {
	  id = QueryInfo->FieldByName("idComida")->AsInteger;

	  for(i = 0; i< lbCodigo->Items->Count; i++)
	  {
		 if(id == arrIdComida[i])
		 {
			lbPorcTotal->Items->Strings[i] = QueryInfo->FieldByName("cantidad")->AsString;
			i = 100; //si o si sale del for
		 }
	  }

	  QueryInfo->Next();
   }

   QueryInfo->Close();


   q = "SELECT todas AS idComida, COUNT(*) AS cantidad "
			  "FROM ((SELECT refComida1 AS todas FROM pedidos WHERE DATE(momento) = :f AND refComida1 > 1 AND (SELECT sectorReparto FROM cantidades WHERE cantidades.idCantidad = pedidos.refCantidad LIMIT 1) = 0 ) "
			  "UNION ALL (SELECT refComida2 AS todas FROM pedidos WHERE DATE(momento) = :f AND refComida2 > 1 AND (SELECT sectorReparto FROM cantidades WHERE cantidades.idCantidad = pedidos.refCantidad LIMIT 1) = 0 ) "
			  "UNION ALL (SELECT refComida3 AS todas FROM pedidos WHERE DATE(momento) = :f AND refComida3 > 1 AND (SELECT sectorReparto FROM cantidades WHERE cantidades.idCantidad = pedidos.refCantidad LIMIT 1) = 0 ) "
			  "UNION ALL (SELECT refComida4 AS todas FROM pedidos WHERE DATE(momento) = :f AND refComida4 > 1 AND (SELECT sectorReparto FROM cantidades WHERE cantidades.idCantidad = pedidos.refCantidad LIMIT 1) = 0 )) t GROUP BY todas ";

   QueryInfo->Close();
   QueryInfo->SQL->Clear();
   QueryInfo->SQL->Add(q);
   QueryInfo->ParamByName("f")->AsDate = DTP->Date;
   QueryInfo->Open();


   while(!QueryInfo->Eof)
   {
	  id = QueryInfo->FieldByName("idComida")->AsInteger;

	  for(i = 0; i< lbCodigo->Items->Count; i++)
	  {
		 if(id == arrIdComida[i])
		 {
			lbPorcPrim->Items->Strings[i] = QueryInfo->FieldByName("cantidad")->AsString;
			i = 100; //si o si sale del for
		 }
	  }

	  QueryInfo->Next();
   }

   QueryInfo->Close();

   for(i = 0; i < lbPorcPrim->Items->Count ; i++)
	  lbPorcSeg->Items->Strings[i] = IntToStr(StrToInt(lbPorcTotal->Items->Strings[i]) - StrToInt(lbPorcPrim->Items->Strings[i]));


   CDS3->Active = false;
   Query3->Close();
   Query3->SQL->Clear();

   if(ocultarFinalizadas)
   {
	  q = "SELECT *, (tabla.cant1 + tabla.cant2) AS total FROM (SELECT refComida r, refComida, idComidaEspecial, "
				 "(IFNULL((SELECT COUNT(*) FROM comidasespeciales a WHERE ordenReparto = 0 AND refEstadoPedido < 4 AND DATE(marcaTiempo) = :f AND a.refComida = r), 0)) AS cant1, "
				 "(IFNULL((SELECT COUNT(*) FROM comidasespeciales b WHERE ordenReparto = 1 AND refEstadoPedido < 4 AND DATE(marcaTiempo) = :f AND b.refComida = r), 0)) AS cant2, "
				 "(SELECT nombre FROM comidas WHERE comidas.idComida = comidasespeciales.refComida LIMIT 1) AS nombre "
				 "FROM comidasespeciales WHERE DATE(marcaTiempo) = :f AND refEstadoPedido < 4 GROUP BY nombre) tabla";
   }
   else
   {
	  q = "SELECT *, (tabla.cant1 + tabla.cant2) AS total FROM (SELECT refComida r, refComida, idComidaEspecial, "
				 "(IFNULL((SELECT COUNT(*) FROM comidasespeciales a WHERE ordenReparto = 0 AND refEstadoPedido < 4 AND DATE(marcaTiempo) = :f AND a.refComida = r), 0)) AS cant1, "
				 "(IFNULL((SELECT COUNT(*) FROM comidasespeciales b WHERE ordenReparto = 1 AND refEstadoPedido < 4 AND DATE(marcaTiempo) = :f AND b.refComida = r), 0)) AS cant2, "
				 "(SELECT nombre FROM comidas WHERE comidas.idComida = comidasespeciales.refComida LIMIT 1) AS nombre "
				 "FROM comidasespeciales WHERE DATE(marcaTiempo) = :f GROUP BY nombre) tabla";
   }
//   q = "SELECT * FROM comidasespeciales WHERE DATE(marcaTiempo) = :f";

   Query3->SQL->Add(q);
   Query3->ParamByName("f")->AsDate = DTP->Date;
   Query3->Open();
   CDS3->Active = true;


   CDS2->Active = false;
   Query2->Close();
   Query2->SQL->Clear();

   if(ordenarPorHoraIngreso)
   {
	  q = "SELECT * FROM (SELECT idComidaEspecial, marcaTiempo, (ordenReparto + 1) AS reparto, "
		  "(SELECT refRepartidor FROM cantidades WHERE idCantidad = (SELECT refCantidad FROM pedidos WHERE idPedido = refPedido LIMIT 1) LIMIT 1) AS refRep, "
		  "(SELECT codigo FROM comidas WHERE idComida = comidasespeciales.refComida LIMIT 1) AS nombre, "

		  "(SELECT "
			 "IF(ordenReparto = 0, "
				"TIMESTAMPDIFF(MINUTE, TIME(NOW()), TIME((SELECT horario1 FROM repartidores WHERE idRepartidor = refRep LIMIT 1))), "
				"TIMESTAMPDIFF(MINUTE, TIME(NOW()), TIME((SELECT horario2 FROM repartidores WHERE idRepartidor = refRep LIMIT 1))) "
			 ")"
		  ") AS tiempoRestante "

		  "FROM comidasespeciales WHERE DATE(marcaTiempo) = :f AND refEstadoPedido < 4)t ORDER BY marcaTiempo DESC";

   }
   else
   {
	  q = "SELECT * FROM (SELECT idComidaEspecial, marcaTiempo, (ordenReparto + 1) AS reparto, "
		  "(SELECT refRepartidor FROM cantidades WHERE idCantidad = (SELECT refCantidad FROM pedidos WHERE idPedido = refPedido LIMIT 1) LIMIT 1) AS refRep, "
		  "(SELECT codigo FROM comidas WHERE idComida = comidasespeciales.refComida LIMIT 1) AS nombre, "

		  "(SELECT "
			 "IF(ordenReparto = 0, "
				"TIMESTAMPDIFF(MINUTE, TIME(NOW()), TIME((SELECT horario1 FROM repartidores WHERE idRepartidor = refRep LIMIT 1))), "
				"TIMESTAMPDIFF(MINUTE, TIME(NOW()), TIME((SELECT horario2 FROM repartidores WHERE idRepartidor = refRep LIMIT 1))) "
			 ")"
		  ") AS tiempoRestante "

		  "FROM comidasespeciales WHERE DATE(marcaTiempo) = :f AND refEstadoPedido < 4)t WHERE tiempoRestante > -15 ORDER BY tiempoRestante";
   }

   Query2->SQL->Add(q);
   Query2->ParamByName("f")->AsDate = DTP->Date;
   Query2->Open();
   CDS2->Active = true;

   if(CDS3->IsEmpty())
   {
	  CDS3->Active = false;
	  Query3->Close();
   }
   if(CDS2->IsEmpty())
   {
	  CDS2->Active = false;
	  Query2->Close();
   }

   QueryInfo->Close();
   QueryInfo->SQL->Clear();
   QueryInfo->SQL->Add("SELECT * FROM porcionesrealizadas WHERE fecha = :fecha");
   QueryInfo->ParamByName("fecha")->AsDate = DTP->Date;
   QueryInfo->Open();

   if(QueryInfo->IsEmpty())
   {
	  QueryInfo->Close();
	  QueryInfo->SQL->Clear();
	  QueryInfo->SQL->Add("INSERT INTO porcionesrealizadas (fecha, refComida, cantidad) "
						  "(SELECT t.f, t.refCom, t.cant FROM ("

						  "(SELECT (SELECT :fecha) AS f, refComida1 AS refCom, (SELECT 0) AS cant FROM menudeldia WHERE fecha = :fecha LIMIT 1) "
						  "UNION ALL (SELECT (SELECT :fecha) AS f, refComida2 AS refCom, (SELECT 0) AS cant FROM menudeldia WHERE fecha = :fecha LIMIT 1) "
						  "UNION ALL (SELECT (SELECT :fecha) AS f, refComida3 AS refCom, (SELECT 0) AS cant FROM menudeldia WHERE fecha = :fecha LIMIT 1) "
						  "UNION ALL (SELECT (SELECT :fecha) AS f, refComida4 AS refCom, (SELECT 0) AS cant FROM menudeldia WHERE fecha = :fecha LIMIT 1) "
						  "UNION ALL (SELECT (SELECT :fecha) AS f, refComida5 AS refCom, (SELECT 0) AS cant FROM menudeldia WHERE fecha = :fecha LIMIT 1) "
						  "UNION ALL (SELECT (SELECT :fecha) AS f, refComida6 AS refCom, (SELECT 0) AS cant FROM menudeldia WHERE fecha = :fecha LIMIT 1) "
						  "UNION ALL (SELECT (SELECT :fecha) AS f, refComida7 AS refCom, (SELECT 0) AS cant FROM menudeldia WHERE fecha = :fecha LIMIT 1) "
						  "UNION ALL (SELECT (SELECT :fecha) AS f, refComida8 AS refCom, (SELECT 0) AS cant FROM menudeldia WHERE fecha = :fecha LIMIT 1) "
						  ")t )");
	  QueryInfo->ParamByName("fecha")->AsDate = DTP->Date;
	  QueryInfo->ExecSQL();

	  for(int i = 0; i < 9; i++)
		 arrCantPorciones[i] = 0;
   }
   else
   {
	  int i;
	  for(i = 0; i < 9; i++)
		 arrCantPorciones[i] = 0;
	  QueryInfo->First();
	  while(!QueryInfo->Eof)
	  {
		 for(i = 0; i < 9; i++)
		 {
			if(arrIdComida[i] == QueryInfo->FieldByName("refComida")->AsInteger)
			{
			   arrCantPorciones[i] = QueryInfo->FieldByName("cantidad")->AsInteger;
			   i = 10;
			}
		 }
		 QueryInfo->Next();
	  }
	  QueryInfo->Close();
   }

   lbCodigo->Refresh();

   Timer2->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TfMain::Button1Click(TObject *Sender)
{
	Timer2Timer(Timer2);
}
//---------------------------------------------------------------------------

void __fastcall TfMain::AlarmasTimer(TObject *Sender)
{
   contadorAlarma++;
   if(CompareDateTime(Now(),proximaAlarma) == GreaterThanValue && idProximaAlarma != 0)
   {
	  Alarmas->Enabled = false;
	  fAlarma->idAlarma = idProximaAlarma;
	  fAlarma->ShowModal();

	  try
	  {
		  Query1->Close();
		  Query1->SQL->Clear();
		  Query1->SQL->Add("SELECT IFNULL(idAlarma,0) AS idAlarma, marcaTiempo FROM alarmas WHERE vista = 0 AND paraCocina = 1 ORDER BY marcaTiempo LIMIT 1");
		  Query1->Open();
		  idProximaAlarma = Query1->FieldByName("idAlarma")->AsInteger;
		  proximaAlarma = Query1->FieldByName("marcaTiempo")->AsDateTime;
		  Query1->Close();
	  }
	  catch(...)
	  {
		  Alarmas->Enabled = false;
		  Timer2->Enabled = false;
		  Application->MessageBox(L"Al parecer hubo un problema al intentar conectar con el servidor. Solucione el problema y reinicie el programa." ,L"Posible error de conexión...",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
		  TimerError->Enabled = true;
		  return;
	  }

	  Alarmas->Enabled = true;
	  contadorAlarma = 0;
   }
   else
   {
	  if(contadorAlarma >= 200)
	  {
		 try
		 {
			 Alarmas->Enabled = false;
			 Query1->Close();
			 Query1->SQL->Clear();
			 Query1->SQL->Add("SELECT IFNULL(idAlarma,0) AS idAlarma, marcaTiempo FROM alarmas WHERE vista = 0 AND paraCocina = 1 ORDER BY marcaTiempo LIMIT 1");
			 Query1->Open();
			 idProximaAlarma = Query1->FieldByName("idAlarma")->AsInteger;
			 proximaAlarma = Query1->FieldByName("marcaTiempo")->AsDateTime;
			 Query1->Close();
			 contadorAlarma = 0;
			 Alarmas->Enabled = true;
		 }
		 catch(...)
		 {
			  Alarmas->Enabled = false;
			  Timer2->Enabled = false;
			  Application->MessageBox(L"Al parecer hubo un problema al intentar conectar con el servidor. Solucione el problema y reinicie el programa." ,L"Posible error de conexión...",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
			  TimerError->Enabled = true;
			  return;
		 }
	  }
   }

}
//---------------------------------------------------------------------------

void __fastcall TfMain::Button4Click(TObject *Sender)
{
   fGestionarAlarmas->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfMain::Button5Click(TObject *Sender)
{
   fConfigurarAlarma->llamador = 0;
   fConfigurarAlarma->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfMain::lbCodigoDblClick(TObject *Sender)
{
   QueryInfo->Close();
   QueryInfo->SQL->Clear();
   QueryInfo->SQL->Add("SELECT cantidad FROM porcionesRealizadas WHERE fecha = :fecha AND refComida = :id LIMIT 1");
   QueryInfo->ParamByName("id")->AsInteger = arrIdComida[lbCodigo->ItemIndex];
   QueryInfo->ParamByName("fecha")->AsDate = DTP->Date;
   QueryInfo->Open();
   Edit1->Text = QueryInfo->FieldByName("cantidad")->AsString;
   QueryInfo->Close();

   Label6->Caption = "Cantidad de porciones de: " + lbCodigo->Items->Strings[lbCodigo->ItemIndex];
   Panel4->Visible = true;
   Edit1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TfMain::Button6Click(TObject *Sender)
{
   QueryInfo->Close();
   QueryInfo->SQL->Clear();
   QueryInfo->SQL->Add("UPDATE porcionesRealizadas SET cantidad = :cantidad WHERE fecha = :fecha AND refComida = :id LIMIT 1");
   QueryInfo->ParamByName("id")->AsInteger = arrIdComida[lbCodigo->ItemIndex];
   QueryInfo->ParamByName("fecha")->AsDate = DTP->Date;
   QueryInfo->ParamByName("cantidad")->AsString = Edit1->Text;
   QueryInfo->ExecSQL();

   Panel4->Visible = false;

   arrCantPorciones[lbCodigo->ItemIndex] = StrToInt(Edit1->Text);
   lbCodigo->Repaint();
}
//---------------------------------------------------------------------------


void __fastcall TfMain::Mostrartodas1Click(TObject *Sender)
{
   ocultarFinalizadas = false;
   Timer2Timer(Timer2);
}
//---------------------------------------------------------------------------

void __fastcall TfMain::Ocultarfinalizadas1Click(TObject *Sender)
{
   ocultarFinalizadas = true;
   Timer2Timer(Timer2);
}
//---------------------------------------------------------------------------

void __fastcall TfMain::Ordenarporhoradeingreso1Click(TObject *Sender)
{
   ordenarPorHoraIngreso = true;
   DBGrid1->Columns->Items[0]->Width = 73;
   Timer2Timer(Timer2);
}
//---------------------------------------------------------------------------

void __fastcall TfMain::Ordenarporminutosrestantes1Click(TObject *Sender)
{
   ordenarPorHoraIngreso = false;
   DBGrid1->Columns->Items[0]->Width = 0;
   Timer2Timer(Timer2);
}
//---------------------------------------------------------------------------

void __fastcall TfMain::Button7Click(TObject *Sender)
{
   fConfiguraciones->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfMain::FormClose(TObject *Sender, TCloseAction &Action)
{
   Alarmas->Enabled = false;
   Timer1->Enabled = false;
   Timer2->Enabled = false;

   CDS2->Active = false;
   CDS3->Active = false;
   CDS4->Active = false;

   Query1->Close();
   Query2->Close();
   Query3->Close();
   Query4->Close();
   QueryAlarma->Close();
   QueryInfo->Close();
   QueryUpdate->Close();

   SQLConnection1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfMain::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(Shift.Contains(ssCtrl) && Shift.Contains(ssShift) && Key == VK_RIGHT)
   {
	  fMain->Left = 1367;
	  fMain->Top = 0;
   }
   else if(Shift.Contains(ssCtrl) && Shift.Contains(ssShift) && Key == VK_LEFT)
   {
	  fMain->Left = 0;
	  fMain->Top = 0;
   }
   else if(Shift.Contains(ssCtrl) && Shift.Contains(ssShift) && Key == VK_UP)
   {
	  Button2Click(fMain);
   }
}
//---------------------------------------------------------------------------

void __fastcall TfMain::Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(Key == VK_RETURN)
      Button6Click(Edit1);
}
//---------------------------------------------------------------------------


void __fastcall TfMain::Vertodaslasopcionesdeestepedido1Click(TObject *Sender)
{
   QueryAux->Close();
   QueryAux->SQL->Clear();
   String q = "SELECT idPedido, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida1 LIMIT 1) AS opcion1, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida2 LIMIT 1) AS opcion2, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida3 LIMIT 1) AS opcion3, "
	   "(SELECT nombre FROM comidas WHERE idComida = refComida4 LIMIT 1) AS complemento "
	   "FROM pedidos WHERE idPedido = :idPedido";

   QueryAux->SQL->Add(q);
   QueryAux->ParamByName("idPedido")->AsInteger = CDS4->FieldByName("refPedido")->AsInteger;
   QueryAux->Open();

   String msg = "Este pedido se compone de: ";

   msg = msg + '\n' + '\n' +"Bandeja grande:" + '\n';
   msg = msg + "   ->" + QueryAux->FieldByName("opcion1")->AsString + '\n';
   if(QueryAux->FieldByName("opcion2")->AsString != "Ninguna")
	  msg = msg +  "   ->" + QueryAux->FieldByName("opcion2")->AsString + '\n';
   if(QueryAux->FieldByName("opcion3")->AsString != "Ninguna")
	  msg = msg +  "   ->" + QueryAux->FieldByName("opcion3")->AsString + '\n';
   msg = msg + "Complemento:" + '\n';
   if(QueryAux->FieldByName("opcion2")->AsString != "Ninguna")
	  msg = msg +  "   ->" + QueryAux->FieldByName("complemento")->AsString;
   else
	  msg = msg +  "   ->No contiene complemento";

   QueryAux->Close();

   Application->MessageBox(msg.w_str() ,L"Detalle del pedido seleccionado...",MB_OK | MB_ICONINFORMATION | MB_DEFBUTTON1);
}
//---------------------------------------------------------------------------

void __fastcall TfMain::DBGrid1DblClick(TObject *Sender)
{
   if(!CDS2->Active)
	  return;

   QueryAux->Close();
   QueryAux->SQL->Clear();
   String q = "SELECT nombre, descripcion FROM comidas WHERE codigo = :codigo LIMIT 1";

   QueryAux->SQL->Add(q);
   QueryAux->ParamByName("codigo")->AsString = CDS2->FieldByName("nombre")->AsString;
   QueryAux->Open();

   String msg = QueryAux->FieldByName("nombre")->AsString;
   msg = msg + '\n' + '\n' + "Descripción: ";
   msg = msg + '\n' + QueryAux->FieldByName("descripcion")->AsString;

   QueryAux->Close();

   Application->MessageBox(msg.w_str() ,L"Detalle de la comida seleccionada",MB_OK | MB_ICONINFORMATION| MB_DEFBUTTON1);
}
//---------------------------------------------------------------------------

void __fastcall TfMain::DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect,
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
		 dynamic_cast <TDBGrid *>(Sender)->Canvas->Brush->Color = TColor(0x00D9D9D9);     //0x00FFD9B3
	  else
		 dynamic_cast <TDBGrid *>(Sender)->Canvas->Brush->Color = TColor(0x00F2F2F2);     //0x00FFF0E1
   }


   dynamic_cast <TDBGrid *>(Sender)->DefaultDrawColumnCell(Rect, DataCol, Column, State);
}
//---------------------------------------------------------------------------

void __fastcall TfMain::DBGrid2DrawColumnCell(TObject *Sender, const TRect &Rect,
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

void __fastcall TfMain::Button8Click(TObject *Sender)
{
   CDS4->Active = false;
   Query4->Close();
   Panel2->Visible = false;
   CDS3->Refresh();
}
//---------------------------------------------------------------------------



void __fastcall TfMain::TimerErrorTimer(TObject *Sender)
{
   TimerError->Enabled = false;
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TfMain::Verreceta1Click(TObject *Sender)
{
   if(lbCodigo->ItemIndex < 0 || arrIdComida[lbCodigo->ItemIndex] <= 1)
	  return;

   ffRecetas->idComida = arrIdComida[lbCodigo->ItemIndex];
   ffRecetas->ShowModal();
}
//---------------------------------------------------------------------------

