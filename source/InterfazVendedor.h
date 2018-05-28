#pragma once
#include"Aerolinea.h"
#include"Interfaz.h"

class InterfazVendedor
{
public:
	static void encabezadoVendedor();
	static void mostrarTodosVendedores(Aerolinea* aerolinea);
	static int seleccionarVendedor(Aerolinea* aerolinea, string clase, string accion);
};
