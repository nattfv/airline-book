#include "Vendedor.h"

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
	s << "Identificacion del vendedor: " << identificacion << "\n"
		<< "Nombre: " << nombre << "\n"
		<< "Apellidos: " << primerApellido << " " << segundoApellido;
	return s.str();
}
