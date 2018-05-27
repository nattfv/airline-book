#pragma once
#include"ExcepcionCadena.h"
#include"ExcepcionMaximo.h"
#include"ExcepcionMinimo.h"
#include<iostream>
#include<fstream>

//para validaciones
int obtenerValorEntero(int minimo, int maximo);
//para archivos
string procesarHilera(ifstream& archivo);
int procesarInt(stringstream& particion, char delimitador);
bool procesarBoolean(stringstream& particion, char delimitador);
double procesarDouble(stringstream & particion, char delimitador);
char procesarChar(stringstream& particion, char delimitador);
