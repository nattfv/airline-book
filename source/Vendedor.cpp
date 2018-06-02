#include "Vendedor.h"
#include"utiles.h"

Vendedor::Vendedor() : 
	Persona("","","","")
{
}

Vendedor::Vendedor(string _nombre, string _primer, string _segundo, string _identificacion) :
	Persona(_nombre, _primer, _segundo, _identificacion)
{
}

Vendedor::Vendedor(const Vendedor & _p) :
	Persona(_p.nombre, _p.primerApellido, _p.segundoApellido, _p.identificacion)
{
}

Vendedor::~Vendedor()
{
}

Vendedor & Vendedor::operator=(const Vendedor & _p)
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

string Vendedor::mostrarVendedor()
{
	stringstream s;
	s << nombre << " " << primerApellido << " " << segundoApellido << "\n";
	s << "Identificacion: " << identificacion;
	return s.str();
}

bool Vendedor::operator==(const Vendedor & v)
{
	return (identificacion == v.identificacion) &&
		(primerApellido == v.primerApellido) &&
		(segundoApellido == v.segundoApellido) &&
		(nombre == v.nombre);
}

ostream & operator<<(ostream & out, Vendedor & _p)
{
	out << _p.identificacion << "\t" << _p.nombre << "\t"
		<< _p.primerApellido << "\t" << _p.segundoApellido << "\n";
	return out;
}

ofstream & operator<<(ofstream & archivo, Vendedor & p)
{
	archivo << p.identificacion << "\t"
		<< p.nombre << "\t"
		<< p.primerApellido << "\t"
		<< p.segundoApellido << "\n";
	return archivo;
}

ifstream & operator>>(ifstream & archivo, Vendedor & p)
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
