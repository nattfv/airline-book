#pragma once
#include"Aerolinea.h"
#include"Interfaz.h"
#include<iostream>
#include<iomanip>

class InterfazPiloto
{
public:
	static void encabezadoPiloto();
	static void mostrarTodosPilotos(Aerolinea* aerolinea);
	static int seleccionarPiloto(Aerolinea* aerolinea, string clase, string accion);
};
