//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uMostrarCombinaciones.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfMostrarCombinaciones *fMostrarCombinaciones;
//---------------------------------------------------------------------------
__fastcall TfMostrarCombinaciones::TfMostrarCombinaciones(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfMostrarCombinaciones::Timer1Timer(TObject *Sender)
{
   String q;


   if(RG2->ItemIndex == 0)
   {
	  q = "SELECT * FROM (SELECT refComida1, refComida2, refComida3, IF(comentarioParaCocina = 0, '', comentario) AS texto, COUNT(*) AS repe, "
		  "(SELECT nombre FROM comidas WHERE refComida1 = comidas.idComida LIMIT 1) AS c1, "
		  "(SELECT nombre FROM comidas WHERE refComida2 = comidas.idComida LIMIT 1) AS c2, "
		  "(SELECT nombre FROM comidas WHERE refComida3 = comidas.idComida LIMIT 1) AS c3 "
		  "FROM pedidos WHERE DATE(momento) = :f AND pedidos.refCantidad IN (SELECT idCantidad FROM cantidades WHERE sectorReparto = :sr) "
		  "GROUP BY refComida1, refComida2, refComida3, texto) t "
		  "WHERE (t.refComida1 > 1 OR t.refComida2 > 1 OR t.refComida3 > 1) AND t.repe > 1"
		  " ORDER BY c1, c2, c3, repe DESC";
   }
   else
   {
	  q = "SELECT * FROM (SELECT refComida1, refComida2, refComida3, IF(comentarioParaCocina = 0, '', comentario) AS texto, COUNT(*) AS repe, "
		  "(SELECT nombre FROM comidas WHERE refComida1 = comidas.idComida LIMIT 1) AS c1, "
		  "(SELECT nombre FROM comidas WHERE refComida2 = comidas.idComida LIMIT 1) AS c2, "
		  "(SELECT nombre FROM comidas WHERE refComida3 = comidas.idComida LIMIT 1) AS c3 "
		  "FROM pedidos WHERE DATE(momento) = :f AND pedidos.refCantidad IN (SELECT idCantidad FROM cantidades WHERE sectorReparto = :sr) "
		  "GROUP BY refComida1, refComida2, refComida3, texto) t "
		  "WHERE (t.refComida1 > 1 OR t.refComida2 > 1 OR t.refComida3 > 1) AND t.repe = 1"
		  " ORDER BY c1, c2, c3, repe DESC";
   }

   try
   {
	   QueryInfo->Close();
	   QueryInfo->SQL->Clear();
	   QueryInfo->SQL->Add(q);
	   QueryInfo->ParamByName("f")->AsDate = DTP->Date;
	   QueryInfo->ParamByName("sr")->AsInteger = RG1->ItemIndex;
	//   QueryInfo->ParamByName("una")->AsString = "una";
	//   QueryInfo->ParamByName("ens")->AsString = "ens";
	   QueryInfo->Open();
   }
   catch(...)
   {
	  Timer1->Enabled = false;
	  Application->MessageBox(L"Al parecer hubo un problema al intentar conectar con el servidor. Solucione el problema y reinicie el programa." ,L"Posible error de conexión...",MB_OK | MB_ICONERROR | MB_DEFBUTTON1);
      Close();
   }
   lbCombCom->Clear();
   String s;
   bool paso;
   while(!QueryInfo->Eof)
   {
	  s = "";
	  if(QueryInfo->FieldByName("refComida1")->AsInteger != 1)
		 s = QueryInfo->FieldByName("c1")->AsString;
	  if(QueryInfo->FieldByName("refComida2")->AsInteger != 1)
		 s = s + " / " + QueryInfo->FieldByName("c2")->AsString;
	  if(QueryInfo->FieldByName("refComida3")->AsInteger != 1)
		 s = s + " / " + QueryInfo->FieldByName("c3")->AsString;
	  if(QueryInfo->FieldByName("texto")->AsString != "")
		 s = s + " - \"" + QueryInfo->FieldByName("texto")->AsString + "\" ";
//	  if(QueryInfo->FieldByName("comentarioParaCocina")->AsInteger != 0)
//		 s = s + " / " + QueryInfo->FieldByName("comentario")->AsString;

	  if(s.Pos(", ") == 1)
		 s.Delete(1,2);

	  paso = false;

	  if(RG1->ItemIndex == 0)
	  {
		 for(int i = 0; i < combGuardada1->Count; i++)
		 {
			String a = combGuardada1->Strings[i];
			if(s == a.SubString(1,a.Pos(" x ") - 1))
			{
			   s = s + " x " + QueryInfo->FieldByName("repe")->AsString;
			   int rep = QueryInfo->FieldByName("repe")->AsInteger;
			   int repAnt = StrToInt(a.SubString(a.Pos(" x ") + 3, a.Length()));
			   s = s + " _(" + IntToStr(rep - repAnt) + ")_";
			   i = combGuardada1->Count + 1;
			   paso = true;
			}
		 }
	  }
	  else
	  {
		 for(int i = 0; i < combGuardada2->Count; i++)
		 {
			String a = combGuardada2->Strings[i];
			if(s == a.SubString(1,a.Pos(" x ") - 1))
			{
			   s = s + " x " + QueryInfo->FieldByName("repe")->AsString;
			   int rep = QueryInfo->FieldByName("repe")->AsInteger;
			   int repAnt = StrToInt(a.SubString(a.Pos(" x ") + 3, a.Length()));
			   s = s + " _(" + IntToStr(rep - repAnt) + ")_";
			   i = combGuardada2->Count + 1;
			   paso = true;
			}
		 }
	  }

	  if(!paso)
         s = s + " x " + QueryInfo->FieldByName("repe")->AsString;

	  lbCombCom->Items->Add(s);

	  QueryInfo->Next();
   }

//   esto es para probar a llenar el lbCombCom

//   lbCombCom->Clear();
//   int i = 0;
//   while( i < 14)
//   {
//	  lbCombCom->Items->Add(s);
//	  i++;
//   }


   if(lbCombCom->Items->Count > 14)
	  lbCombCom->Height = lbCombCom->Items->Count * 45.4;
   else
	  lbCombCom->Height = 14 * 45.4;

   ScrollBox1->VertScrollBar->Range = lbCombCom->Height;

   QueryInfo->Close();
}
//---------------------------------------------------------------------------
void __fastcall TfMostrarCombinaciones::FormShow(TObject *Sender)
{
   TIniFile *Configuraciones;
   String Dir = GetCurrentDir()+"//Config.ini";
   Configuraciones = new TIniFile(Dir);

   SQLConnection1->Params->Values["HostName"] = Configuraciones->ReadString("MySQLServer","Servidor", "127.0.0.1");
   SQLConnection1->Params->Values["User_Name"] = "elsembrador";
   SQLConnection1->Params->Values["Password"] = "*-elsembrador63/*";

   delete Configuraciones;

   omitirUnaVez = true;
   RG2->ItemIndex = 0;

   Timer1Timer(Timer1);
   Timer1->Enabled = true;
   anchoLB = 1240;
   ScrollBox1->HorzScrollBar->Range = anchoLB;
}
//---------------------------------------------------------------------------
void __fastcall TfMostrarCombinaciones::FormClose(TObject *Sender, TCloseAction &Action)

{
   QueryInfo->Close();
   SQLConnection1->Close();
   Timer1->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TfMostrarCombinaciones::Button2Click(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------
void __fastcall TfMostrarCombinaciones::Guardarcantidaddereferencia1Click(TObject *Sender)
{
   if(lbCombCom->ItemIndex < 0)
   {
	  Application->MessageBox(L"Debe seleccionar un ítem haciendo click izquierdo sobre el mismo." ,L"No se realizaron cambios!",MB_OK | MB_ICONWARNING | MB_DEFBUTTON1);
	  return;
   }

   if(RG1->ItemIndex == 0)
   {
	   if(combGuardada1->Strings[0] != FormatDateTime("dd/mm/yyy", DTP->DateTime))
	   {
		  if(Application->MessageBox(L"Hay datos guardados de una fecha diferente a la de hoy, desea eliminarlos para poder guardar los de hoy?",L"Eliminar datos de otros días?",MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
			 return;
		  else
		  {
			 combGuardada1->Clear();
			 combGuardada1->Add(FormatDateTime("dd/mm/yyy", DTP->DateTime));
		  }
	   }
   }
   else
   {
	   if(combGuardada2->Strings[0] != FormatDateTime("dd/mm/yyy", DTP->DateTime))
	   {
		  if(Application->MessageBox(L"Hay datos guardados de una fecha diferente a la de hoy, desea eliminarlos para poder guardar los de hoy?",L"Eliminar datos de otros días?",MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
			 return;
		  else
		  {
			 combGuardada2->Clear();
			 combGuardada2->Add(FormatDateTime("dd/mm/yyy", DTP->DateTime));
		  }
	   }
   }
   String s = lbCombCom->Items->Strings[lbCombCom->ItemIndex];

   if(RG1->ItemIndex == 0)
   {
	  if(s.Pos(" _(") > 0)
	  {
		  s = s.SubString(1, s.Pos(" _(") - 1);
		  for(int i = 1; i < combGuardada1->Count ; i++)
		  {
			 if(s.SubString( 1, s.Pos(" x ") - 1) == combGuardada1->Strings[i].SubString( 1,combGuardada1->Strings[i].Pos(" x ") - 1 ))
			 {
				combGuardada1->Delete(i);
				i = combGuardada1->Count;
			 }
		  }
	  }

	  combGuardada1->Add(s);
	  combGuardada1->SaveToFile(GetCurrentDir() +  "\\CombinacionesBandejas\\PrimerReparto");
   }
   else
   {
	  if(s.Pos(" _(") > 0)
	  {
		  s = s.SubString(1, s.Pos(" _(") - 1);
		  for(int i = 1; i < combGuardada2->Count ; i++)
		  {
			 if(s.SubString( 1, s.Pos(" x ") - 1) == combGuardada2->Strings[i].SubString( 1,combGuardada2->Strings[i].Pos(" x ") - 1 ))
			 {
				combGuardada2->Delete(i);
				i = combGuardada2->Count;
			 }
		  }
	  }

	  combGuardada2->Add(s);
	  combGuardada2->SaveToFile(GetCurrentDir() +  "\\CombinacionesBandejas\\SegundoReparto");
   }

   Timer1Timer(Timer1);
}
//---------------------------------------------------------------------------
void __fastcall TfMostrarCombinaciones::FormCreate(TObject *Sender)
{
   combGuardada1 = new TStringList();
   combGuardada2 = new TStringList();
   combGuardada1->LoadFromFile(GetCurrentDir() +  "\\CombinacionesBandejas\\PrimerReparto");
   combGuardada2->LoadFromFile(GetCurrentDir() +  "\\CombinacionesBandejas\\SegundoReparto");
   if(combGuardada1->Count == 0)
	  combGuardada1->Add(FormatDateTime("dd/mm/yyy", Now()));
   if(combGuardada2->Count == 0)
	  combGuardada2->Add(FormatDateTime("dd/mm/yyy", Now()));
}
//---------------------------------------------------------------------------

void __fastcall TfMostrarCombinaciones::FormDestroy(TObject *Sender)
{
   delete combGuardada1;
   delete combGuardada2;
}
//---------------------------------------------------------------------------
void __fastcall TfMostrarCombinaciones::RG1Click(TObject *Sender)
{
   Timer1Timer(Timer1);
}
//---------------------------------------------------------------------------
void __fastcall TfMostrarCombinaciones::RG2Click(TObject *Sender)
{
   if(omitirUnaVez)
   {
	  omitirUnaVez = false;
	  return;
   }
   Timer1Timer(Timer1);
}
//---------------------------------------------------------------------------
void __fastcall TfMostrarCombinaciones::lbCombComDrawItem(TWinControl *Control, int Index,
		  TRect &Rect, TOwnerDrawState State)
{
//   if(Index % 2 == 0)
//	  lbCodigo->Canvas->Brush->Color = TColor(0x00FFE1DF);

   String s = dynamic_cast <TListBox *>(Control)->Items->Strings[Index];

   if(State.Contains(odSelected))
   {
	  dynamic_cast <TListBox *>(Control)->Canvas->Font->Color = clWhite;
	  dynamic_cast <TListBox *>(Control)->Canvas->Brush->Color = TColor(0x00C07000);
   }
   else
   {
	  if(s.Pos(" _(0)_") > 0)
		 dynamic_cast <TListBox *>(Control)->Canvas->Brush->Color = TColor(0x0076DC7B);
	  else if(s.Pos(" _(") > 0)
		 dynamic_cast <TListBox *>(Control)->Canvas->Brush->Color = TColor(0x009595FF);
	  else
		 dynamic_cast <TListBox *>(Control)->Canvas->Brush->Color = TColor(0x00B3FFFF);
   }

   int anchoTexto = dynamic_cast <TListBox *>(Control)->Canvas->TextWidth(s);
   if(anchoTexto > anchoLB)
   {
	  anchoLB = anchoTexto + 10;
	  dynamic_cast <TListBox *>(Control)->Width = anchoLB;
	  ScrollBox1->HorzScrollBar->Range = anchoLB;
   }
   int l;
   l = Rect.Left + 5;
   dynamic_cast <TListBox *>(Control)->Canvas->FillRect(Rect);
   dynamic_cast <TListBox *>(Control)->Canvas->TextOutW(l, Rect.Top, s);
}
//---------------------------------------------------------------------------

void __fastcall TfMostrarCombinaciones::lbCombComExit(TObject *Sender)
{
   lbCombCom->ItemIndex = -1;
}
//---------------------------------------------------------------------------

void __fastcall TfMostrarCombinaciones::ScrollBox1MouseWheel(TObject *Sender, TShiftState Shift,
		  int WheelDelta, TPoint &MousePos, bool &Handled)
{
   ScrollBox1->VertScrollBar->Position = ScrollBox1->VertScrollBar->Position - WheelDelta;
}
//---------------------------------------------------------------------------

void __fastcall TfMostrarCombinaciones::lbCombComKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift)
{
 if(Key == VK_DOWN || Key == VK_RIGHT)
 {
	if(dynamic_cast <TListBox *>(Sender)->ItemIndex > 12)
	   ScrollBox1->VertScrollBar->Position += 46;
 }
 else  if(Key == VK_UP || Key == VK_LEFT)
 {
//	if(dynamic_cast <TListBox *>(Sender)->ItemIndex < 13)
	   ScrollBox1->VertScrollBar->Position -= 46;
 }
}
//---------------------------------------------------------------------------

void __fastcall TfMostrarCombinaciones::FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift)

{
   if(Shift.Contains(ssCtrl) && Shift.Contains(ssShift) && Key == VK_F1)
   {
	  RG1->ItemIndex = 0;
   }
   else if(Shift.Contains(ssCtrl) && Shift.Contains(ssShift) && Key == VK_F2)
   {
	  RG1->ItemIndex = 1;
   }
   else if(Shift.Contains(ssCtrl) && Shift.Contains(ssShift) && Key == VK_F3)
   {
	  fMostrarCombinaciones->Close();
   }
}
//---------------------------------------------------------------------------


