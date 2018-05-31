#include "ExcepcionCaracter.h"

ExcepcionCaracter::ExcepcionCaracter(char _minimo, char _maximo) :
	ExcepcionEntrada(0, 0), minimoC(_minimo), maximoC(_maximo)
{
}

ExcepcionCaracter::~ExcepcionCaracter()
{
}

string ExcepcionCaracter::notificarError()
{
	stringstream s;
	s << "Caracteres aceptados " << minimoC << "-" << maximoC << "\n";
	return s.str();
}
