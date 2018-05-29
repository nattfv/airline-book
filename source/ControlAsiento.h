#pragma once
#include"Asiento.h"

class ControlAsiento
{
private:
	char* letrasAsiento;
	int tamanio;
public:
	ControlAsiento(int _tamanio); //total de columnas para los asientos
	~ControlAsiento();
	void darFormatoAsiento(Asiento& _a, int _columna, int _fila);
	string formarHileraLetras();
};
