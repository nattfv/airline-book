#pragma once
#include<string>
#include<sstream>
#include"MatrizAsiento.h"
using namespace std;

class Avion
{
private:
	string codigo; //formato AP-XXX o AC-XXX
	string transporte; //pasajero o carga
	string tamanio; //pequenio(4) o grande(7)
	double pesoCarga; //unicamente para carga
	bool disponible; //todos empiezan true
	MatrizAsiento* pasajeros; //se crea en en un metodo
public:
	Avion();
	Avion(string _codigo, string _transporte, string _tamanio); //avion pasajero
	Avion(string _codigo, string _transporte, string _tamanio, double _pesoCarga); //avion carga
	Avion(const Avion& _a);
	~Avion();
	void crearAsientos(); //pendiente: probar para que sea bool
	string mostrarAvion();
	MatrizAsiento* obtenerPasajeros();
};
