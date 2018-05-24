#pragma once
#include"ExcepcionEntrada.h"

class ExcepcionMaximo : public ExcepcionEntrada
{
private:
	int valor;
public:
	ExcepcionMaximo(int _minimo, int _maximo, int _valor);
	~ExcepcionMaximo();
	string notificarError();
};
