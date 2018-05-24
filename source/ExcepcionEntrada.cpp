#include "ExcepcionEntrada.h"

ExcepcionEntrada::ExcepcionEntrada(int _minimo, int _maximo) :
	 minimo(_minimo), maximo(_maximo)
{
}

ExcepcionEntrada::~ExcepcionEntrada()
{
}

string ExcepcionEntrada::errorRango()
{
	stringstream s;
	if (maximo == 0)
		s << "Datos validos mayores a " << minimo << "\n";
	else
		s << "Datos validos entre " << minimo << " y " << maximo << "\n";


	return s.str();
}
