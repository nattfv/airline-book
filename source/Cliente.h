#pragma once
#include"Persona.h"

class Cliente : public Persona
{
public:
	Cliente();
	Cliente(string _nombre, string _primer, string _segundo, string _identificacion);
	Cliente(const Cliente& _p);
	~Cliente();
	Cliente& operator=(const Cliente& _p);
	string mostrarCliente();
	friend ostream& operator<<(ostream& out, Cliente& _p);
	friend ofstream& operator<<(ofstream& archivo, Cliente& c);
	friend ifstream& operator>>(ifstream& archivo, Cliente& c);
};