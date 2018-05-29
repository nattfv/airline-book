#pragma once
#include"Aerolinea.h"
#include"Interfaz.h"

class InterfazReservacion
{
public:
	static void encabezadoReservacion();
	static void mostrarTodosVuelosPasajeros(Aerolinea* aerolinea);
	static int seleccionarVueloPasajeros(Aerolinea* aerolinea, string clase, string accion);
	static void desplegarAsientos(Vuelo* vuelo);
	static int seleccionarFilaPasajeros(Vuelo* vuelo);
};