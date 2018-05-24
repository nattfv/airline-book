#pragma once
#include"ExcepcionEntrada.h"

class ExcepcionMinimo : public ExcepcionEntrada
{
private:
	int valor;
public:
	ExcepcionMinimo(int _minimo, int _maximo, int _valor);
	~ExcepcionMinimo();
	string notificarError();
};
