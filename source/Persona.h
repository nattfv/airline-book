#pragma once
#include<string>
#include<sstream>
using namespace std;

class Persona
{
protected:
	string nombre;
	string primerApellido;
	string segundoApellido;
	string identificacion;
public:
	Persona(string _nombre, string _primer, string _segundo, string _identificacion);
	~Persona();
};

