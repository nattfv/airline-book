#include "MatrizAsiento.h"

MatrizAsiento::MatrizAsiento(int _fila, int _columna) :
	fila(_fila), columna(_columna)
{
	matriz = new Asiento**[fila]; //Columna inicial
	for (int i = 0; i < fila; i++)
		matriz[i] = new Asiento*[columna]; //En cada fila, hay un vector que representa las columnas
	for (int i = 0; i < fila; i++)
		for (int j = 0; j < columna; j++)
			matriz[i][j] = new Asiento();
}

MatrizAsiento::~MatrizAsiento()
{
	for (int i = 0; i < fila; i++)
		for (int j = 0; j < columna; j++)
			delete matriz[i][j]; //Cada elemento de la matriz
	for (int i = 0; i < fila; i++)
		delete[] matriz[i]; //Elimina cada columna
	delete[] matriz;
}

int MatrizAsiento::getFila()
{
	return fila;
}

int MatrizAsiento::getColumna()
{
	return columna;
}

Asiento * MatrizAsiento::getAsiento(int _fila, int _columna)
{
	return matriz[_fila][_columna];
}

string MatrizAsiento::toString()
{
	stringstream s;
	for (int i = 0; i < fila; i++)
		for (int j = 0; j < columna; j++)
			s << matriz[i][j]->toString() << endl;
	return s.str();
}