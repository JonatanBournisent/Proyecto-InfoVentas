//---------------------------------------------------------------------------

#ifndef uMainH
#define uMainH
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
#include <Vcl.ComCtrls.hpp>
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdIPWatch.hpp>
#include <Datasnap.DBClient.hpp>
#include <Datasnap.Provider.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TfMain : public TForm
{
__published:	// IDE-managed Components
	TPanel *Panel1;
	TListBox *lbCodigo;
	TListBox *lbPorcPrim;
	TListBox *lbPorcSeg;
	TListBox *lbPorcTotal;
	TSQLConnection *SQLConnection1;
	TSQLQuery *QueryInfo;
	TButton *Button1;
	TDateTimePicker *DTP;
	TSQLQuery *Query1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TDataSource *DataSource2;
	TSQLQuery *Query2;
	TDataSetProvider *DataSetProvider2;
	TClientDataSet *CDS2;
	TDBGrid *DBGrid1;
	TIntegerField *CDS2idComidaEspecial;
	TWideStringField *CDS2nombre;
	TSQLTimeStampField *CDS2marcaTiempo;
	TDataSource *DataSource3;
	TSQLQuery *Query3;
	TDataSetProvider *DataSetProvider3;
	TClientDataSet *CDS3;
	TWideStringField *WideStringField1;
	TDBGrid *DBGrid2;
	TLargeintField *CDS3cant1;
	TLargeintField *CDS3cant2;
	TPanel *Panel2;
	TDataSource *DataSource4;
	TSQLQuery *Query4;
	TDataSetProvider *DataSetProvider4;
	TClientDataSet *CDS4;
	TIntegerField *IntegerField1;
	TIntegerField *IntegerField2;
	TIntegerField *IntegerField3;
	TWideStringField *WideStringField2;
	TIntegerField *IntegerField4;
	TSQLTimeStampField *SQLTimeStampField1;
	TDBGrid *DBGrid3;
	TIntegerField *CDS3refComida;
	TDBCheckBox *CB;
	TSQLQuery *QueryUpdate;
	TTimer *Timer1;
	TTimer *Timer2;
	TButton *Button2;
	TLargeintField *CDS3total;
	TWideStringField *CDS4rep;
	TWideStringField *CDS4cliente;
	TButton *Button3;
	TLabel *Label5;
	TPanel *Panel3;
	TTimer *Alarmas;
	TSQLQuery *QueryAlarma;
	TButton *Button4;
	TButton *Button5;
	TPanel *Panel4;
	TButton *Button6;
	TEdit *Edit1;
	TLabel *Label6;
	TLargeintField *CDS4ordenReparto;
	TLargeintField *CDS2tiempoRestante;
	TPopupMenu *PopupMenu1;
	TMenuItem *Mostrartodas1;
	TMenuItem *Ocultarfinalizadas1;
	TPopupMenu *PopupMenu2;
	TMenuItem *Ordenarporhoradeingreso1;
	TMenuItem *Ordenarporminutosrestantes1;
	TButton *Button7;
	TLabel *Reloj;
	TIntegerField *CDS2reparto;
	TLabel *Label7;
	TLabel *Label8;
	TSQLQuery *QueryAux;
	TPopupMenu *PopupMenu3;
	TMenuItem *Vertodaslasopcionesdeestepedido1;
	TPanel *Panel5;
	TPanel *Panel6;
	TButton *Button8;
	TIntegerField *CDS3idComidaEspecial;
	TTimer *TimerError;
	TPopupMenu *PopupMenu4;
	TMenuItem *Verreceta1;
	void __fastcall DTPChange(TObject *Sender);
	void __fastcall lbCodigoDrawItem(TWinControl *Control, int Index, TRect &Rect, TOwnerDrawState State);
	void __fastcall lbPorcPrimDrawItem(TWinControl *Control, int Index, TRect &Rect,
          TOwnerDrawState State);
	void __fastcall lbPorcSegDrawItem(TWinControl *Control, int Index, TRect &Rect,
          TOwnerDrawState State);
	void __fastcall lbPorcTotalDrawItem(TWinControl *Control, int Index, TRect &Rect,
          TOwnerDrawState State);
	void __fastcall DBGrid2DblClick(TObject *Sender);
	void __fastcall DBGrid3DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);
	void __fastcall DBGrid3ColExit(TObject *Sender);
	void __fastcall IntegerField4Change(TField *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall AlarmasTimer(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall lbCodigoDblClick(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Mostrartodas1Click(TObject *Sender);
	void __fastcall Ocultarfinalizadas1Click(TObject *Sender);
	void __fastcall Ordenarporhoradeingreso1Click(TObject *Sender);
	void __fastcall Ordenarporminutosrestantes1Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Edit1KeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Vertodaslasopcionesdeestepedido1Click(TObject *Sender);
	void __fastcall DBGrid1DblClick(TObject *Sender);
	void __fastcall DBGrid1DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);
	void __fastcall DBGrid2DrawColumnCell(TObject *Sender, const TRect &Rect, int DataCol,
          TColumn *Column, TGridDrawState State);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall TimerErrorTimer(TObject *Sender);
	void __fastcall Verreceta1Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TfMain(TComponent* Owner);

	int arrIdComida[9];
	int arrCantPorciones[9];
	TRect *DrawRect;

	int idProximaAlarma;
	TDateTime proximaAlarma;
	bool ocultarFinalizadas;
	bool ordenarPorHoraIngreso;
	int contadorAlarma;
};
//---------------------------------------------------------------------------
extern PACKAGE TfMain *fMain;
//---------------------------------------------------------------------------
#endif
