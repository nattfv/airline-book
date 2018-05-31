#pragma once
#include"ExcepcionEntrada.h"

class ExcepcionCaracter : public ExcepcionEntrada
{
private:
	char valor;
	char minimoC;
	char maximoC;
public:
	ExcepcionCaracter(char _minimo, char _maximo);
	~ExcepcionCaracter();
	string notificarError();
};
