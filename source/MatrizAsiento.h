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
	MatrizAsiento(const MatrizAsiento& _ma);
	MatrizAsiento& operator=(const MatrizAsiento& _ma); //pendiente: definicion
	int getFila();
	int getColumna();
	Asiento* getAsiento(int _fila, int _columna);
	string toString();
	void darFormatoTodosAsientos();
	int totalAsientos();
	int cantidadAsientosVendidos();
	int cantidadAsientosDisponibles();
};
