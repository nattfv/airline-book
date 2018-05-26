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
		cin.clear();
		cin.ignore(255, '\n');
	}
	else
	{
		cin.clear();
		cin.ignore(255, '\n');
		throw ExcepcionCadena("un numero entero");
	}
	return evaluar;
}

string procesarHilera(ifstream& archivo)
{
	string hilera;
	getline(archivo, hilera, '\n');
	return hilera;
}

int procesarInt(stringstream & particion, char delimitador)
{
	string cadenaStr;
	int cadenaInt;
	getline(particion, cadenaStr, delimitador);
	cadenaInt = atoi(cadenaStr.c_str());
	return cadenaInt;
}

bool procesarBoolean(stringstream & particion, char delimitador)
{
	string cadenaStr;
	getline(particion, cadenaStr, delimitador);
	return cadenaStr == "1";
}

double procesarDouble(stringstream & particion, char delimitador)
{
	string cadenaStr;
	double cadenaDouble;
	getline(particion, cadenaStr, delimitador);
	cadenaDouble = atof(cadenaStr.c_str());
	return cadenaDouble;
}
