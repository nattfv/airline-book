#include "Reservacion.h"
#include"utiles.h"

Reservacion::Reservacion() : 
	cantidadReservados(0), vuelo(NULL), vendedor(NULL), cliente(NULL)
{
}

Reservacion::Reservacion(Vuelo * _vuelo, Vendedor * _vendedor, Cliente* _cliente)
{
	cantidadReservados = 0;
	vuelo = new Vuelo(*_vuelo);
	vendedor = new Vendedor(*_vendedor);
	cliente = _cliente;
	asientosReservados = new AsientoReservado();
}

Reservacion::Reservacion(const Reservacion & r)
{
	cantidadReservados = r.cantidadReservados;
	vuelo = new Vuelo(*r.vuelo);
	vendedor = new Vendedor(*r.vendedor);
	cliente = new Cliente(*r.cliente);
	asientosReservados = new AsientoReservado(*r.asientosReservados);
}

Reservacion::~Reservacion()
{
	delete vendedor;
	delete asientosReservados;
	delete cliente;
	delete vuelo;
}

Reservacion & Reservacion::operator=(const Reservacion & r)
{
	if (this != &r)
	{
		if (vuelo)
			delete vuelo;
		if (vendedor)
			delete vendedor;
		if (cliente)
			delete cliente;
		cantidadReservados = r.cantidadReservados;
		vuelo = new Vuelo(*r.vuelo);
		vendedor = new Vendedor(*r.vendedor);
		cliente = new Cliente(*r.cliente);
		asientosReservados = new AsientoReservado(*r.asientosReservados);
	}
	return *this;
}

string Reservacion::mostrarReservacion()
{
	stringstream s;
	s << "Reservados: " << cantidadReservados << " asientos\n"
		<< asientosReservados->mostrarAsientosReservados()
		/*<< "Vendedor\n" << vendedor->mostrarVendedor() << "\n"*/
		<< "Cliente\n" << cliente->mostrarCliente() << "\n"
		<< "Vuelo\n" << vuelo->mostrarVuelo();
	return s.str();
}

/*
	Verifica si no ha excedido la cantida de asiento para reservar
*/
bool Reservacion::puedoReservar(int _fila, int _columna, Vuelo* a) //mejor que le caiga el avion por parametro
{
	Avion* avion = vuelo->obtenerAvion(); //avion asignado al vuelo
	MatrizAsiento* asientos = avion->obtenerPasajeros(); //los asientos actualizados del avion
	Asiento* posibleAsiento = asientos->obtenerAsiento(_fila, _columna); //el asiento que quiero reservar
	if (asientosReservados->agregar(posibleAsiento))
	{
		cantidadReservados++;
		a->actualizarPasajero(_fila, _columna);
		return true;
	}
	else
		return false;
}

bool Reservacion::compararVendedor(Vendedor * v)
{
	return *vendedor == *v;
}

ostream & operator<<(ostream & out, Reservacion & _d)
{
	return out <<_d.mostrarReservacion();
}

ofstream & operator<<(ofstream & archivo, Reservacion & d)
{
	archivo << d.cantidadReservados << "\n";
	archivo << *d.vuelo;
	archivo << *d.vendedor;
	archivo << *d.cliente;
	archivo << *d.asientosReservados;
	return archivo;
}

ifstream & operator>>(ifstream & archivo, Reservacion & d)
{
	// TODO: insertar una instrucción return aquí
	string hilera = procesarHilera(archivo);
	stringstream particion(hilera);
	Vuelo vuelo;
	Vendedor vendedor;
	Cliente cliente;
	AsientoReservado asientosReservados;
	int cantidadReservados = procesarInt(particion, '\n');
	archivo >> vuelo;
	archivo >> vendedor;
	archivo >> cliente;
	archivo >> asientosReservados;
	d.cantidadReservados = cantidadReservados;
	d.vuelo = new Vuelo(vuelo);
	d.vendedor = new Vendedor(vendedor);
	d.cliente = new Cliente(cliente);
	d.asientosReservados = new AsientoReservado(asientosReservados);
	return archivo;
}
