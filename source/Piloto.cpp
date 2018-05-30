#include "Piloto.h"
#include"utiles.h"

Piloto::Piloto() : Persona("","","","")
{
}

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

ofstream & operator<<(ofstream& archivo, Piloto & p)
{
	archivo << p.identificacion << "\t"
		<< p.nombre << "\t"
		<< p.primerApellido << "\t"
		<< p.segundoApellido << "\n";
	return archivo;
}

ifstream & operator>>(ifstream & archivo, Piloto & p)
{
	string hilera = procesarHilera(archivo);
	stringstream particion(hilera);
	string nombre, primerApellido, segundoApellido, identificacion;
	getline(particion, identificacion, '\t');
	getline(particion, nombre, '\t');
	getline(particion, primerApellido, '\t');
	getline(particion, segundoApellido, '\n');
	p.identificacion = identificacion;
	p.nombre = nombre;
	p.primerApellido = primerApellido;
	p.segundoApellido = segundoApellido;
	return archivo;
}
