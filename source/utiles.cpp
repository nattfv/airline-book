#include "utiles.h"

int obtenerValorEntero(int minimo, int maximo)
{
	int evaluar;

	if (cin >> evaluar)
	{
		if (evaluar < minimo)
			throw ExcepcionMinimo(minimo, maximo, evaluar);
		if (evaluar > maximo && maximo != 0) // max != 0; cuando no se sabe el maximo aun
			throw ExcepcionMinimo(minimo, maximo, evaluar);
	}
	else
	{
		cin.clear();
		cin.ignore(255, '\n');
		throw ExcepcionCadena("un numero entero");
	}
	return evaluar;
}
