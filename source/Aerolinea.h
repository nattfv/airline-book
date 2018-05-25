#pragma once
#include"Destino.h"
#include"Piloto.h"
#include"Vendedor.h"
#include"Avion.h"
#include"Vuelo.h"
#include"Reservacion.h"
#include"Lista.h"

class Aerolinea
{
private:
	Lista<Destino>* listaDestinos;
	Lista<Piloto>* listaPilotos;
	Lista<Avion>* listaAviones;
	Lista<Vuelo>* listaVuelos;
	Lista<Vendedor>* listaVendedor;
	Lista<Reservacion>* listaReservacion;
public:
	Aerolinea();
	~Aerolinea();
	Lista<Destino>* obtenerDestinos();
	Lista<Piloto>* obtenerPilotos();
	Lista<Avion>* obtenerAviones();
	Lista<Vuelo>* obtenerVuelos();
	Lista<Vendedor>* obtenerVendedores();
	Lista<Reservacion>* obtenerReservaciones();
};
