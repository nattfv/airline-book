#include "Reservacion.h"

Reservacion::Reservacion(Vuelo * _vuelo, Vendedor * _vendedor, Cliente* _cliente)
{
	cantidadReservados = 0;
	vuelo = _vuelo;
	vendedor = new Vendedor(*_vendedor);
	cliente = _cliente;
	asientosReservados = new AsientoReservado();
}

Reservacion::~Reservacion()
{
	delete vendedor;
	delete asientosReservados;
	delete cliente;
}

string Reservacion::mostrarReservacion()
{
	stringstream s;
	s << "Reservados: " << cantidadReservados << " asientos\n"
		<< asientosReservados->mostrarAsientosReservados()
		<< "Vendedor\n" << vendedor->mostrarVendedor() << "\n"
		<< "Cliente\n" << cliente->mostrarCliente() << "\n"
		<< "Vuelo\n" << vuelo->mostrarVuelo();
	return s.str();
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
}

ostream & operator<<(ostream & out, Reservacion & _d)
{
	return out <<_d.mostrarReservacion();
}
