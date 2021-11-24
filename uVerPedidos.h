//---------------------------------------------------------------------------

#ifndef uVerPedidosH
#define uVerPedidosH
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
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfVerPedidos : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TSQLConnection *SQLConnection1;
	TClientDataSet *ClientDataSet3;
	TWideStringField *ClientDataSet3repartidor;
	TWideStringField *ClientDataSet3cliente;
	TFMTBCDField *ClientDataSet3cantViandas;
	TWideStringField *ClientDataSet3complemento;
	TDataSetProvider *DataSetProvider3;
	TSQLQuery *QueryCantidad;
	TDataSource *DataSource3;
	TMonthCalendar *MC;
	TButton *Button1;
	TEdit *Edit1;
	TLabel *Label1;
	TButton *Button2;
	TButton *Button3;
	TPanel *Panel1;
	TClientDataSet *ClientDataSet1;
	TDataSetProvider *DataSetProvider1;
	TSQLQuery *QueryClientes;
	TDataSource *DataSource1;
	TDBGrid *DBGrid2;
	TWideStringField *ClientDataSet1calle;
	TWideStringField *ClientDataSet1numero;
	TIntegerField *ClientDataSet1idCliente;
	TWideStringField *ClientDataSet1repLV;
	TWideStringField *ClientDataSet1repSab;
	TButton *Button4;
	TIntegerField *ClientDataSet3idCantidad;
	TIntegerField *ClientDataSet3bandGrand;
	TSQLQuery *QueryAux;
	TIntegerField *ClientDataSet3reparto;
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall DBGrid1DblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfVerPedidos(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfVerPedidos *fVerPedidos;
//---------------------------------------------------------------------------
#endif
