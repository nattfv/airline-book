#pragma once
#include"Persona.h"

class Piloto : public Persona
{
public:
	//supongamos que la identificacion dentro de la aerolinea, tiene formato P-XXX;
	Piloto(string _nombre, string _primer, string _segundo, string _identificacion);
	Piloto(const Piloto& _p);
	~Piloto();
	Piloto& operator=(const Piloto& _p);
	string mostrarPiloto();
};