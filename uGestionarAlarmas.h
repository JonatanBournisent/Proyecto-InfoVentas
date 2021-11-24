//---------------------------------------------------------------------------

#ifndef uGestionarAlarmasH
#define uGestionarAlarmasH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.DBXMySQL.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Datasnap.DBClient.hpp>
#include <Datasnap.Provider.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TfGestionarAlarmas : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TButton *Salir;
	TSQLConnection *SQLConnection1;
	TSQLQuery *Query1;
	TDataSetProvider *DataSetProvider1;
	TClientDataSet *CDS1;
	TIntegerField *CDS1idAlarma;
	TWideStringField *CDS1mensaje;
	TSQLTimeStampField *CDS1marcaTiempo;
	TWideStringField *CDS1frec;
	TDataSource *DataSource1;
	TPopupMenu *PopupMenu1;
	TMenuItem *Modificarestaalarma1;
	TMenuItem *Eliminar1;
	TSQLQuery *QueryDelete;
	void __fastcall SalirClick(TObject *Sender);
	void __fastcall Eliminar1Click(TObject *Sender);
	void __fastcall Modificarestaalarma1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TfGestionarAlarmas(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfGestionarAlarmas *fGestionarAlarmas;
//---------------------------------------------------------------------------
#endif
