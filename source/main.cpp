#include<iostream>
#include"Fecha.h"
using namespace std;

int main()
{
	//-------------------------------------------------------------------------------------------------
	//Prueba de Fecha
	Fecha* fecha1 = new Fecha();
	cout << fecha1->mostrarFormatoFecha() << endl;
	Fecha* fecha2 = new Fecha(20, 6, 2018);
	cout << fecha2->mostrarFormatoFecha() << endl;
	Fecha* fecha3 = new Fecha(*fecha2);
	cout << fecha3->mostrarFormatoFecha() << endl;
	*fecha3 = *fecha1;
	cout << fecha3->mostrarFormatoFecha() << endl;
	try
	{
		Fecha fecha(12, 45, 2006);
		cout << fecha.mostrarFormatoFecha() << endl;
	}
	catch (int x)
	{
		cout << "Error tipo: " <<x << endl;
	}
	//-------------------------------------------------------------------------------------------------
	//Eliminacion
	delete fecha1;
	delete fecha2;
	delete fecha3;
	system("pause");
	return 0;
}