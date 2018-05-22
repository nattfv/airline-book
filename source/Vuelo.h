#pragma once
#include"Avion.h"
#include"Destino.h"
#include"Piloto.h"

class Vuelo
{
private:
	string identificacion; //formato V-XXX
	Avion* avion; //creado por el constructor copia
	Destino* destino; //creado por el constructor copia
	Piloto* piloto; //creado por el constructor copia
public:
};
