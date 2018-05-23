#include "Cliente.h"

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
	s << "Identificacion del cliente: " << identificacion << "\n"
		<< "Nombre: " << nombre << "\n"
		<< "Apellidos: " << primerApellido << " " << segundoApellido << "\n";
	return s.str();
}
