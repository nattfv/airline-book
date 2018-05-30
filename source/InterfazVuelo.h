#pragma once
#include"Aerolinea.h"
#include"Interfaz.h"

class InterfazVuelo
{
public:
	static void encabezadoVuelo();
	static void mostrarTodosVuelos(Aerolinea* aerolinea);
	static int seleccionarVuelo(Aerolinea* aerolinea, string clase, string accion);
};