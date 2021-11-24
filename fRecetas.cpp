//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "fRecetas.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TffRecetas *ffRecetas;
//---------------------------------------------------------------------------
__fastcall TffRecetas::TffRecetas(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TffRecetas::FormShow(TObject *Sender)
{
   QueryAux->Close();
   QueryAux->SQL->Clear();
   QueryAux->SQL->Add("SELECT nombre FROM comidas WHERE idComida = :id LIMIT 1");
   QueryAux->ParamByName("id")->AsInteger = idComida;
   QueryAux->Open();
   ffRecetas->Caption = "Receta de: " + QueryAux->FieldByName("nombre")->AsString;
   QueryAux->Close();

   QueryReceta->Close();
   QueryReceta->SQL->Clear();
   QueryReceta->SQL->Add("SELECT idReceta, descripcion FROM recetas WHERE refComida = :id LIMIT 1");
   QueryReceta->ParamByName("id")->AsInteger = idComida;
   QueryReceta->Open();
   idReceta = QueryReceta->FieldByName("idReceta")->AsInteger;
   TStringStream *Stream;
   Stream = new TStringStream(QueryReceta->FieldByName("descripcion")->AsString);
   REMemo->Lines->LoadFromStream(Stream);
   QueryReceta->Close();

   delete Stream;
}
//---------------------------------------------------------------------------

void __fastcall TffRecetas::FormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
   REMemo->SetFocus();
}
//---------------------------------------------------------------------------

