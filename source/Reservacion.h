#pragma once
#include"Vendedor.h"
#include"Vuelo.h"
#include"AsientoReservado.h"
#include"Cliente.h"

class Reservacion
{
private:
	int cantidadReservados; //siempre empieza en cero
	Vuelo* vuelo; //Puntero directo
	Vendedor* vendedor; //creado por constructor copia
	AsientoReservado* asientosReservados; //array que guarda los asientos por reservacion
	Cliente* cliente; //creado por el constructor copia, por parametro
public:
	Reservacion(Vuelo* _vuelo, Vendedor* _vendedor, Cliente* _cliente);
	~Reservacion();
	string mostrarReservacion();
	//bool estaDisponibleAsiento(int _fila, int _columna); 
	bool puedoReservar(int _fila, int _columna);
};