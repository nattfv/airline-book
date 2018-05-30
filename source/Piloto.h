#pragma once
#include"Persona.h"
#include<fstream>

class Piloto : public Persona
{
public:
	//supongamos que la identificacion dentro de la aerolinea, tiene formato P-XXX;
	Piloto();
	Piloto(string _nombre, string _primer, string _segundo, string _identificacion);
	Piloto(const Piloto& _p);
	~Piloto();
	Piloto& operator=(const Piloto& _p);
	string mostrarPiloto();
	friend ostream& operator<<(ostream& out, Piloto& _p);
	friend ofstream& operator<<(ofstream& archivo, Piloto& p);
	friend ifstream& operator>>(ifstream& archivo, Piloto& p);
};