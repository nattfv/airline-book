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
	Reservacion();
	Reservacion(Vuelo* _vuelo, Vendedor* _vendedor, Cliente* _cliente);
	Reservacion(const Reservacion& r);
	~Reservacion();
	Reservacion& operator=(const Reservacion& r);
	string mostrarReservacion();
	bool puedoReservar(int _fila, int _columna, Vuelo* a); //ignorar
	friend ostream& operator<<(ostream& out, Reservacion& _d);
	bool compararVendedor(Vendedor* v);
	friend ofstream& operator<<(ofstream& archivo, Reservacion& d);
	friend ifstream& operator>>(ifstream& archivo, Reservacion& d);
};