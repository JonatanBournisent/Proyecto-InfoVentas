//---------------------------------------------------------------------------

#ifndef uConfigurarAlarmaH
#define uConfigurarAlarmaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.DBXMySQL.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfConfigurarAlarma : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TMonthCalendar *MC;
	TDateTimePicker *DTP;
	TMemo *Memo1;
	TButton *Button1;
	TButton *Button2;
	TRadioGroup *RadioGroup1;
	TCheckBox *CheckBox1;
	TSQLConnection *SQLConnection1;
	TSQLQuery *Query1;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
	__fastcall TfConfigurarAlarma(TComponent* Owner);

	int llamador;  //0 - alarma nueva / 1 - reconfigurar alarma
	int idAlarma;
};
//---------------------------------------------------------------------------
extern PACKAGE TfConfigurarAlarma *fConfigurarAlarma;
//---------------------------------------------------------------------------
#endif
