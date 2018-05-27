#include "Cliente.h"
#include"utiles.h"

Cliente::Cliente() : 
	Persona("","","","")
{
}

Cliente::Cliente(string _nombre, string _primer, string _segundo, string _identificacion) :
	Persona(_nombre, _primer, _segundo, _identificacion)
{
}

Cliente::Cliente(const Cliente & _p) :
	Persona(_p.nombre, _p.primerApellido, _p.segundoApellido, _p.identificacion)
{
}

Cliente::~Cliente()
{
}

Cliente & Cliente::operator=(const Cliente & _p)
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

string Cliente::mostrarCliente()
{
	stringstream s;
	s << nombre << " " << primerApellido << " " << segundoApellido << "\n";
	s << "Identificacion: " << identificacion;
	return s.str();
}

ostream & operator<<(ostream & out, Cliente & _p)
{
	out << _p.identificacion << "\t" << _p.nombre << "\t"
		<< _p.primerApellido << "\t" << _p.segundoApellido << "\n";
	return out;
}

ofstream & operator<<(ofstream & archivo, Cliente & c)
{
	archivo << c.identificacion << "\t"
		<< c.nombre << "\t"
		<< c.primerApellido << "\t"
		<< c.segundoApellido << "\n";
	return archivo;
}

ifstream & operator>>(ifstream & archivo, Cliente & c)
{
	string hilera = procesarHilera(archivo);
	stringstream particion(hilera);
	string nombre, primerApellido, segundoApellido, identificacion;
	getline(particion, identificacion, '\t');
	getline(particion, nombre, '\t');
	getline(particion, primerApellido, '\t');
	getline(particion, segundoApellido, '\n');
	c.identificacion = identificacion;
	c.nombre = nombre;
	c.primerApellido = primerApellido;
	c.segundoApellido = segundoApellido;
	return archivo;
}
