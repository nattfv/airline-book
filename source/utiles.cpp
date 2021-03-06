#include "utiles.h"

int obtenerValorEntero(int minimo, int maximo)
{
	int evaluar;

	if (cin >> evaluar)
	{
		if (evaluar < minimo)
			throw ExcepcionMinimo(minimo, maximo, evaluar);
		if (evaluar > maximo && maximo != 0) // max != 0; cuando no se sabe el maximo aun
			throw ExcepcionMaximo(minimo, maximo, evaluar);
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

char obternerValorChar(char minimo, char maximo)
{
	char evaluar;
	string evaluarInicial;
	cin >> evaluarInicial;
	if (evaluarInicial.length() > 1)
		throw - 1;
	evaluar = evaluarInicial[0];
	if (isdigit(evaluar))
		throw 0;
	if (evaluar < minimo)
		throw 1;
	if (evaluar > maximo)
		throw 2;
	cin.clear();
	cin.ignore(255, '\n');
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

char procesarChar(stringstream & particion, char delimitador)
{
	char cadenaChar;
	string cadenaStr;
	getline(particion, cadenaStr, delimitador);
	stringstream convertidor(cadenaStr);
	convertidor >> cadenaChar;
	return cadenaChar;
}
