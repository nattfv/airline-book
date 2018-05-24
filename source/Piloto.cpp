#include "Piloto.h"

Piloto::Piloto(string _nombre, string _primer, string _segundo, string _identificacion) :
	Persona(_nombre, _primer, _segundo,_identificacion)
{
}

Piloto::Piloto(const Piloto & _p) : 
	Persona(_p.nombre, _p.primerApellido, _p.segundoApellido, _p.identificacion)
{
}

Piloto::~Piloto()
{
}

Piloto & Piloto::operator=(const Piloto & _p)
{
	if (this != &_p)
	{
		nombre = _p.nombre;
		primerApellido = _p.primerApellido;
		segundoApellido = _p.segundoApellido;
		identificacion = _p.identificacion;
	}
	
	return *this;
}

string Piloto::mostrarPiloto()
{
	stringstream s;
	s << "Identificacion del piloto: " << identificacion << "\n"
		<< "Nombre: " << nombre << "\n"
		<< "Apellidos: " << primerApellido << " " << segundoApellido << "\n";
	return s.str();
}

ostream & operator<<(ostream & out, Piloto & _p)
{
	out << _p.identificacion << "\t" << _p.nombre << "\t" 
		<< _p.primerApellido << "\t" << _p.segundoApellido << "\n";
	return out;
}
