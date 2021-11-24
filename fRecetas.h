//---------------------------------------------------------------------------

#ifndef fRecetasH
#define fRecetasH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Data.DB.hpp>
#include <Data.DBXMySQL.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
//---------------------------------------------------------------------------
class TffRecetas : public TForm
{
__published:	// IDE-managed Components
	TRichEdit *REMemo;
	TSQLConnection *SQLConnection1;
	TSQLQuery *QueryAux;
	TSQLQuery *QueryReceta;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
private:	// User declarations
public:		// User declarations
	__fastcall TffRecetas(TComponent* Owner);

	int idComida;
	int idReceta;

};
//---------------------------------------------------------------------------
extern PACKAGE TffRecetas *ffRecetas;
//---------------------------------------------------------------------------
#endif
