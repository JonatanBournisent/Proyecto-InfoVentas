//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("uMain.cpp", fMain);
USEFORM("uGestionarAlarmas.cpp", fGestionarAlarmas);
USEFORM("uMostrarCombinaciones.cpp", fMostrarCombinaciones);
USEFORM("uVerPedidos.cpp", fVerPedidos);
USEFORM("uVerDetallePedidos.cpp", fVerDetallePedidos);
USEFORM("uAlarma.cpp", fAlarma);
USEFORM("uConfigurarAlarma.cpp", fConfigurarAlarma);
USEFORM("uConfiguraciones.cpp", fConfiguraciones);
USEFORM("fRecetas.cpp", ffRecetas);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TfMain), &fMain);
		Application->CreateForm(__classid(TfMostrarCombinaciones), &fMostrarCombinaciones);
		Application->CreateForm(__classid(TfVerPedidos), &fVerPedidos);
		Application->CreateForm(__classid(TfAlarma), &fAlarma);
		Application->CreateForm(__classid(TfGestionarAlarmas), &fGestionarAlarmas);
		Application->CreateForm(__classid(TfConfigurarAlarma), &fConfigurarAlarma);
		Application->CreateForm(__classid(TfConfiguraciones), &fConfiguraciones);
		Application->CreateForm(__classid(TfVerDetallePedidos), &fVerDetallePedidos);
		Application->CreateForm(__classid(TffRecetas), &ffRecetas);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
