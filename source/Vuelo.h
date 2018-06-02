#pragma once
#include"Avion.h"
#include"Destino.h"
#include"Piloto.h"
#include"Hora.h"

class Vuelo
{
private:
	string identificacion; //formato V-XXX
	Avion* avion; //creado por el constructor copia
	Destino* destino; //creado por el constructor copia
	Piloto* piloto; //creado por el constructor copia
	Hora* salida;
	Hora* llegada;

public:
	Vuelo();
	Vuelo(string _identificacion, Avion* _avion, Destino* _destino, Piloto* _piloto);
	Vuelo(string _identificacion, Avion* _avion, Destino* _destino, Piloto* _piloto, Hora* _salida, Hora* _llegada);
	Vuelo(const Vuelo& _v);
	~Vuelo();
	Vuelo& operator=(const Vuelo& v);
	void prepararAvion();
	string mostrarVuelo();
	Avion* obtenerAvion();
	Destino* obtenerDestino();
	Piloto* obtenerPiloto();
	bool estaDisponibleAsiento(int _fila, int _columna);
	friend ostream& operator<<(ostream& out, Vuelo& _v);
	friend ofstream& operator<<(ofstream& archivo, Vuelo& v);
	friend ifstream& operator>>(ifstream& archivo, Vuelo& v);
	bool esVueloPasajeros();
	void actualizarPasajero(int fila, int columna);
	bool tieneEspacioAvion();
	bool esVueloDiponibleReserva();
};
