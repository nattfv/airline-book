#include "ExcepcionMinimo.h"

ExcepcionMinimo::ExcepcionMinimo(int _minimo, int _maximo, int _valor) :
	ExcepcionEntrada(_minimo, _maximo), valor(_valor)
{
}

ExcepcionMinimo::~ExcepcionMinimo()
{
}

string ExcepcionMinimo::notificarError()
{
	stringstream s;
	s << "El valor " << valor << " es muy chico\n";
	s << ExcepcionEntrada::errorRango();
	return s.str();
}
