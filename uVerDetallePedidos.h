//---------------------------------------------------------------------------

#ifndef uVerDetallePedidosH
#define uVerDetallePedidosH
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
//---------------------------------------------------------------------------
class TfVerDetallePedidos : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TDBGrid *DBGrid1;
	TButton *Button1;
	TButton *Button2;
	TSQLConnection *SQLConnection1;
	TSQLQuery *Query1;
	TDataSetProvider *DataSetProvider1;
	TClientDataSet *CDS1;
	TIntegerField *CDS1idPedido;
	TWideStringField *CDS1opcion1;
	TWideStringField *CDS1opcion2;
	TWideStringField *CDS1opcion3;
	TWideStringField *CDS1complemento;
	TSQLTimeStampField *CDS1fecha;
	TDataSource *DataSource1;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall CDS1fechaGetText(TField *Sender, UnicodeString &Text, bool DisplayText);
	void __fastcall DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);

private:	// User declarations
public:		// User declarations
	__fastcall TfVerDetallePedidos(TComponent* Owner);

	int periodo;
	int idCliente;
};
//---------------------------------------------------------------------------
extern PACKAGE TfVerDetallePedidos *fVerDetallePedidos;
//---------------------------------------------------------------------------
#endif
