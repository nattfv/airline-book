#pragma once
#include<string>
#include<sstream>	
using namespace std;

class ExcepcionEntrada
{
private:
	int minimo;
	int maximo;
public:
	ExcepcionEntrada(int _minimo, int _maximo);
	virtual ~ExcepcionEntrada();
	string errorRango();
	virtual string notificarError() = 0;
};
