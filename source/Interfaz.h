#pragma once
#include<iomanip>
#include<iostream>
#include<string>
using namespace std;
class Interfaz
{
public:
	//OPCIONES: 3
	static int menuPrincipal();
	//OPCIONES:6
	static int menuAdministracion();
	//OPCIONES: 5
	static int menuAdministracionDe(string clase);
	static void opcionIncorrecta();
	static void seleccionarElemento(string clase , string accion);
};