#pragma once
#include"Aerolinea.h"
#include"Interfaz.h"

class InterfazAvion
{
public:
	static void encabezadoAvion();	
	static int menuTransporteAvion();
	static int menuAsientosAvion();
	static double ingresarPesoAvion();
	static void mostrarTodosAviones(Aerolinea* aerolinea);
	static int seleccionarAvion(Aerolinea* aerolinea, string clase, string accion);
};