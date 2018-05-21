#pragma once
#include"Asiento.h"
#include"ControlAsiento.h"

class MatrizAsiento {
private:
	Asiento * ** matriz;
	int fila;
	int columna;
public:
	MatrizAsiento(int _fila, int _columna);
	~MatrizAsiento();
	int getFila();
	int getColumna();
	Asiento* getAsiento(int _fila, int _columna);
	string toString();
	void darFormatoTodosAsientos();
};
