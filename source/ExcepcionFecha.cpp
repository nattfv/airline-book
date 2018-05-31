#include "ExcepcionFecha.h"

ExcepcionFecha::ExcepcionFecha(string _mensaje) : mensaje(_mensaje)
{
}

ExcepcionFecha::~ExcepcionFecha()
{
}

string ExcepcionFecha::notificarError()
{
	stringstream s;
	s << "El " << mensaje << " se ingreso incorrectamente\n";
	return s.str();
}
