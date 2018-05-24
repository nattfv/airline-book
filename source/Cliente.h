#pragma once
#include"Persona.h"

class Cliente : public Persona
{
public:
	Cliente(string _nombre, string _primer, string _segundo, string _identificacion);
	Cliente(const Cliente& _p);
	~Cliente();
	Cliente& operator=(const Cliente& _p);
	string mostrarCliente();
	friend ostream& operator<<(ostream& out, Cliente& _p);
};