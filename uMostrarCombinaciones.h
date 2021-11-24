//---------------------------------------------------------------------------

#ifndef uMostrarCombinacionesH
#define uMostrarCombinacionesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.DBXMySQL.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TfMostrarCombinaciones : public TForm
{
__published:	// IDE-managed Components
	TSQLConnection *SQLConnection1;
	TSQLQuery *QueryInfo;
	TTimer *Timer1;
	TDateTimePicker *DTP;
	TButton *Button2;
	TPopupMenu *PopupMenu1;
	TMenuItem *Guardarcantidaddereferencia1;
	TRadioGroup *RG1;
	TRadioGroup *RG2;
	TScrollBox *ScrollBox1;
	TListBox *lbCombCom;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Guardarcantidaddereferencia1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormDestroy(TObject *Sender);
	void __fastcall RG1Click(TObject *Sender);
	void __fastcall RG2Click(TObject *Sender);
	void __fastcall lbCombComDrawItem(TWinControl *Control, int Index, TRect &Rect,
          TOwnerDrawState State);
	void __fastcall lbCombComExit(TObject *Sender);
	void __fastcall ScrollBox1MouseWheel(TObject *Sender, TShiftState Shift, int WheelDelta,
          TPoint &MousePos, bool &Handled);
	void __fastcall lbCombComKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);

private:	// User declarations
public:		// User declarations
	__fastcall TfMostrarCombinaciones(TComponent* Owner);

	TStringList *combGuardada1;
	TStringList *combGuardada2;
	bool omitirUnaVez;

	int anchoLB;
};
//---------------------------------------------------------------------------
extern PACKAGE TfMostrarCombinaciones *fMostrarCombinaciones;
//---------------------------------------------------------------------------
#endif
