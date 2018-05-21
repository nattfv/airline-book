#pragma once
#include"Persona.h"

class Vendedor : public Persona
{
public:
	//supongamos que la identificacion dentro de la aerolinea, tiene formato V-XXX;
	Vendedor(string _nombre, string _primer, string _segundo, string _identificacion);
	Vendedor(const Vendedor& _p);
	~Vendedor();
	Vendedor& operator=(const Vendedor& _p);
	string mostrarVendedor();
};