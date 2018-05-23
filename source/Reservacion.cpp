#include "Reservacion.h"

Reservacion::Reservacion(Vuelo * _vuelo, Vendedor * _vendedor)
{
	cantidadReservados = 0;
	vuelo = _vuelo;
	vendedor = new Vendedor(*_vendedor);
	//asientosReservados = new AsientoReservado();
}

Reservacion::~Reservacion()
{
	delete vendedor;
	delete asientosReservados;
}

string Reservacion::mostrarReservacion()
{
	stringstream s;
	s << "Reservados: " << cantidadReservados << " asientos\n"
		<< asientosReservados->mostrarAsientosReservados()
		<< "Vendedor\n" << vendedor->mostrarVendedor() << "\n";
	return s.str();
}

/*
	Verifica si el asiento seleccionado esta disponible
*/
bool Reservacion::estaDisponibleAsiento(int _fila, int _columna)
{
	Avion* avion = vuelo->obtenerAvion(); //avion asignado al vuelo
	MatrizAsiento* asientos = avion->obtenerPasajeros(); //los asientos actualizados del avion
	Asiento* posibleAsiento = asientos->obtenerAsiento(_fila, _columna); //el asiento que quiero reservar
	return posibleAsiento->getDisponible(); //responsablidad unica
}

/*
	Verifica si no ha excedido la cantida de asiento para reservar
*/
bool Reservacion::puedoReservar(int _fila, int _columna)
{
	Avion* avion = vuelo->obtenerAvion(); //avion asignado al vuelo
	MatrizAsiento* asientos = avion->obtenerPasajeros(); //los asientos actualizados del avion
	Asiento* posibleAsiento = asientos->obtenerAsiento(_fila, _columna); //el asiento que quiero reservar
	if (asientosReservados->agregar(posibleAsiento))
	{
		cantidadReservados++;
		posibleAsiento->setDisponible(false); //importante, para no volver a comprar el mismo
		return true;
	}
	else
		return false;
	//return asientosReservados->agregar(posibleAsiento); //responsablidad unica
}
