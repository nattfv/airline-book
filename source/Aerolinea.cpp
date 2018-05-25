#include "Aerolinea.h"

Aerolinea::Aerolinea()
{
	listaDestinos = new Lista<Destino>();
	listaPilotos = new Lista<Piloto>();
	listaAviones = new Lista<Avion>();
	listaVuelos = new Lista<Vuelo>();
	listaVendedor = new Lista<Vendedor>();
	listaReservacion = new Lista<Reservacion>();
}

Aerolinea::~Aerolinea()
{
	delete listaPilotos;
	delete listaDestinos;
	delete listaAviones;
	delete listaVuelos;
	delete listaVendedor;
	delete listaReservacion;
}

Lista<Destino>* Aerolinea::obtenerDestinos()
{
	return listaDestinos;
}

Lista<Piloto>* Aerolinea::obtenerPilotos()
{
	return listaPilotos;
}

Lista<Avion>* Aerolinea::obtenerAviones()
{
	return listaAviones;
}

Lista<Vuelo>* Aerolinea::obtenerVuelos()
{
	return listaVuelos;
}

Lista<Vendedor>* Aerolinea::obtenerVendedores()
{
	return listaVendedor;
}

Lista<Reservacion>* Aerolinea::obtenerReservaciones()
{
	return listaReservacion;
}
