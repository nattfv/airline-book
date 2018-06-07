#pragma once
#include<string>
#include<sstream>
#include<fstream>
#include"Motor.h"
#include"MatrizAsiento.h"
#include"Motor.h"
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
	Motor* motor;
public:
	Avion();
	//Avion(string _codigo, string _transporte, string _tamanio); //avion pasajero
	//Avion(string _codigo, string _transporte, string _tamanio, double _pesoCarga); //avion carga
	Avion(string _codigo, string _transporte, string _tamanio, double _pesoCarga, Motor* _motor, bool _disponible = true, MatrizAsiento* = NULL);
	Avion(const Avion& _a);
	~Avion();
	Avion& operator=(const Avion& a);
	void crearAsientos(); //pendiente: probar para que sea bool
	string mostrarAvion();
	MatrizAsiento* obtenerPasajeros();
	friend ostream& operator<<(ostream& out, Avion& _a);
	friend ofstream& operator<<(ofstream& archivo, Avion& d);
	friend ifstream& operator>>(ifstream& archivo, Avion& d);
	bool llevaPasajeros();
	bool estaDisponibleAsiento(int fila, int columna);
	bool quedaCampoPasajeros();
};
