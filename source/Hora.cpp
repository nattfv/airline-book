#include "Hora.h"
#include"utiles.h"

Hora::Hora() : horas(0), minutos(0)
{
}

Hora::Hora(int _horas, int _minutos) :
	horas(_horas), minutos(_minutos)
{
}

Hora::~Hora()
{
}

string Hora::mostrarHora()
{
	stringstream s;
	s << horas << ":" << minutos << "";
	return s.str();
}

ostream & operator<<(ostream & out, Hora & h)
{
	out << h.mostrarHora();
	return out;
}

ofstream & operator<<(ofstream & archivo, Hora & h)
{
	archivo << h.horas << "\t";
	archivo << h.minutos << "\n";
	return archivo;
}

ifstream & operator>>(ifstream & archivo, Hora & h)
{
	string hilera = procesarHilera(archivo);
	stringstream particion(hilera);
	h.horas = procesarInt(particion, '\t');
	h.minutos = procesarInt(particion, '\n');
	return archivo;
}
