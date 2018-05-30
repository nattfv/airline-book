#pragma once
#include"ExcepcionEntrada.h"

class ExcepcionCadena : public ExcepcionEntrada
{
private:
	string mensaje;
public:
	ExcepcionCadena(string _mensaje);
	~ExcepcionCadena();
	string notificarError();
};