//---------------------------------------------------------------------------

#ifndef uAlarmaH
#define uAlarmaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Data.DB.hpp>
#include <Data.DBXMySQL.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
//---------------------------------------------------------------------------
class TfAlarma : public TForm
{
__published:	// IDE-managed Components
	TMemo *Memo1;
	TButton *Button1;
	TButton *Button2;
	TTimer *Timer1;
	TSQLConnection *SQLConnection1;
	TSQLQuery *Query1;
	TTimer *Timer2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Timer2Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfAlarma(TComponent* Owner);

	int idAlarma;
	int frecuenciaRepeticion;
};
//---------------------------------------------------------------------------
extern PACKAGE TfAlarma *fAlarma;
//---------------------------------------------------------------------------
#endif
