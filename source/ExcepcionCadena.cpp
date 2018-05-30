#include "ExcepcionCadena.h"

ExcepcionCadena::ExcepcionCadena(string _mensaje) :
	ExcepcionEntrada(0, 0)
{
	mensaje = _mensaje;
}

ExcepcionCadena::~ExcepcionCadena()
{
}

string ExcepcionCadena::notificarError()
{
	return "Deberia digitar " + mensaje + "\n";
}
