#pragma once
#include"Avion.h"
#include"Destino.h"
#include"Piloto.h"

class Vuelo
{
private:
	string identificacion; //formato V-XXX
	Avion* avion; //creado por el constructor copia
	Destino* destino; //creado por el constructor copia
	Piloto* piloto; //creado por el constructor copia
public:
	Vuelo();
	Vuelo(string _identificacion, Avion* _avion, Destino* _destino, Piloto* _piloto);
	Vuelo(const Vuelo& _v);
	~Vuelo();
	Vuelo& operator=(const Vuelo& v);
	void prepararAvion();
	string mostrarVuelo();
	Avion* obtenerAvion();
	Destino* obtenerDestino();
	Piloto* obtenerPiloto();
	//la responsabilidad de disponibilidad la tiene el vuelo
	bool estaDisponibleAsiento(int _fila, int _columna);
	friend ostream& operator<<(ostream& out, Vuelo& _v);
	friend ofstream& operator<<(ofstream& out, Vuelo& v);
};
