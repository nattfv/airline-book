#include<iostream>
#include"Fecha.h"
#include"Destino.h"
#include"Piloto.h"
#include"Vendedor.h"
#include"MatrizAsiento.h"
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
	//Prueba de Destino
	Destino* destino1 = new Destino("Alajuela, Costa Rica", "New Jersey, Estados Unidos", fecha1, fecha2);
	cout << destino1->mostrarDestino();
	Destino* destino2 = new Destino(*destino1);
	cout << destino2->mostrarDestino();
	Destino* destino3 = new Destino("Alajuela, Costa Rica", "Berlin, Alemania", new Fecha(*fecha1), new Fecha(*fecha2));
	cout << destino3->mostrarDestino();
	*destino1 = *destino3;
	cout << destino1->mostrarDestino();
	cout << destino3->mostrarDestino();
	//-------------------------------------------------------------------------------------------------
	//Prueba de Piloto
	Piloto* piloto1 = new Piloto("Andres", "Jimenez", "Elizondo", "P-001");
	cout << piloto1->mostrarPiloto() << endl;
	Vendedor* vendedor1 = new Vendedor("Paulo", "Barrantes", "Aguilar", "V-001");
	cout << vendedor1->mostrarVendedor() << endl;
	//-------------------------------------------------------------------------------------------------
	//Prueba de MatrizAsiento
	MatrizAsiento* MAP = new MatrizAsiento(12, 4);
	MAP->darFormatoTodosAsientos();
	cout << MAP->toString();
	//-------------------------------------------------------------------------------------------------
	//Eliminacion
	delete MAP;
	delete vendedor1;
	delete piloto1;
	delete destino3;
	delete destino2;
	delete destino1;
	//delete fecha1;
	//delete fecha2;
	delete fecha3;
	system("pause");
	return 0;
}