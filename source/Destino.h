#pragma once
#include<string>
#include<sstream>
#include"Fecha.h"

class Destino
{
private:
	string origen;
	string destino;
	Fecha* partida;
	Fecha* regreso;
public:
	Destino();
	Destino(string _origen, string _destino, Fecha* _partida, Fecha* _regreso);
	Destino(const Destino& _d);
	~Destino();
	Destino& operator=(const Destino& _d);
	string mostrarDestino();
};