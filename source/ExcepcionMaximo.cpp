#include "ExcepcionMaximo.h"

ExcepcionMaximo::ExcepcionMaximo(int _minimo, int _maximo, int _valor) : 
	ExcepcionEntrada(_minimo, _maximo), valor(_valor)
{
}

ExcepcionMaximo::~ExcepcionMaximo()
{
}

string ExcepcionMaximo::notificarError()
{
	stringstream s;
	s << "El valor " << valor << " es muy grande\n";
	s << ExcepcionEntrada::errorRango();
	return s.str();
}
