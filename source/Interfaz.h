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
	//OPCIONES: 4
	static int menuReservacion();
	//MENSAJES DE RESULTADOS
	static void opcionIncorrecta();
	static void ingresoExitoso();
	static void eliminacionExitosa();
	static void eliminacionFracasada();
	static void mostrarError(string notificacion); 
	//se repite mucho
	static void seleccionarElemento(string clase, string accion);
	static string ingresarDatoCadena(string dato, string clase);
	//mucho codigo
	//static string ingresarNombre(string clase);
	//static string ingresarPrimerApellido(string clase);
	//static string ingresarSegundoApellido(string clase);
	//static string ingresarIdentificacion(string clase);
};