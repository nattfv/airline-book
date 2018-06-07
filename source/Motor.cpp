#include "Motor.h"
#include"utiles.h"

Motor::Motor() : tipo(""), codigo(""),  cantidad(0)
{
}

Motor::Motor(string _tipo, string _codigo, int _cantidad) :
	tipo(_tipo), codigo(_codigo), cantidad(_cantidad)
{
}

Motor::~Motor()
{
}

Motor::Motor(const Motor & m)
{
	tipo = m.tipo;
	codigo = m.codigo;
	cantidad = m.cantidad;
}

Motor & Motor::operator=(const Motor & m)
{
	tipo = m.tipo;
	codigo = m.codigo;
	cantidad = m.cantidad;
	return *this;
}

string Motor::mostrarMotor()
{
	stringstream s;
	s << "Codigo del motor: " << codigo << "\n"
		<< "Tipo de motor: " << tipo << "\n"
		<< "Cantidad de motores: " << cantidad;
	return s.str();
}

ofstream & operator<<(ofstream & archivo, Motor & m)
{
	archivo << m.tipo << "\t";
	archivo << m.codigo << "\t";
	archivo << m.cantidad << "\n";
	return archivo;
}

ifstream & operator>>(ifstream & archivo, Motor & m)
{
	string hilera = procesarHilera(archivo);
	stringstream particion(hilera);
	getline(particion, m.tipo, '\t');
	getline(particion, m.codigo, '\t');
	m.cantidad = procesarInt(particion, '\n');
	return archivo;
}
