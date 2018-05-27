#pragma once
#include"Persona.h"
#include<fstream>

class Vendedor : public Persona
{
public:
	Vendedor();
	//supongamos que la identificacion dentro de la aerolinea, tiene formato V-XXX;
	Vendedor(string _nombre, string _primer, string _segundo, string _identificacion);
	Vendedor(const Vendedor& _p);
	~Vendedor();
	Vendedor& operator=(const Vendedor& _p);
	string mostrarVendedor();
	friend ostream& operator<<(ostream& out, Vendedor& _p);
	friend ofstream& operator<<(ofstream& archivo, Vendedor& p);
	friend ifstream& operator>>(ifstream& archivo, Vendedor& p);
};
