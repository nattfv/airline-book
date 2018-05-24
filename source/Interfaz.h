#pragma once
#include<iomanip>
#include<iostream>
using namespace std;
class Interfaz
{
public:
	//OPCIONES: 3
	static int menuPrincipal();
	//OPCIONES:4
	static int menuAdministracion();
	//OPCIONES: 4
	static int menuReporte();
	//OPCIONES: 4
	static int menuReporteArchivo();

	static void escrituraExitosa();

	static void opcionIncorrecta();
};