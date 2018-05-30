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
	static int seleccionarColumnaPasajeros(Vuelo* vuelo);
	static void mostrarDetallesPasajeros(Vuelo* vuelo);
	static void mostrarReservasVendedor(Aerolinea* aerolinea, Vendedor* vendedor);
	static string reservaExitosa();
	static string asientoReservado();
	static void limiteReservaciones();
	static string continuarReservando();
};