//---------------------------------------------------------------------------

#ifndef uConfiguracionesH
#define uConfiguracionesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TfConfiguraciones : public TForm
{
__published:	// IDE-managed Components
	TButton *Button2;
	TEdit *Edit1;
	TLabel *Label12;
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfConfiguraciones(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfConfiguraciones *fConfiguraciones;
//---------------------------------------------------------------------------
#endif
