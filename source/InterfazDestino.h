#pragma once
#include"Aerolinea.h"
#include"Interfaz.h"
using namespace std;

class InterfazDestino
{
public:
	static int ingresarDia();
	static int ingresarMes();
	static int ingresarAnio();
	static string ingresarLugarOrigen();
	static string ingresarLugarDestino();
	static void encabezadoDestino();
	static void encabezadoFechaPartida();
	static void encabezadoFechaRegreso();
	static void mostrarTodosDestinos(Aerolinea* aerolinea);
	static int seleccionarDestino(Aerolinea* aerolinea, string clase, string accion);
};
