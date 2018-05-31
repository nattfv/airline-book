#pragma once
#include"ExcepcionCadena.h"
#include"ExcepcionMaximo.h"
#include"ExcepcionMinimo.h"
#include"ExcepcionCaracter.h"
#include<iostream>
#include<fstream>

//para excepciones
int obtenerValorEntero(int minimo, int maximo);
char obternerValorChar(char minimo, char maximo);
//para archivos
string procesarHilera(ifstream& archivo);
int procesarInt(stringstream& particion, char delimitador);
bool procesarBoolean(stringstream& particion, char delimitador);
double procesarDouble(stringstream & particion, char delimitador);
char procesarChar(stringstream& particion, char delimitador);
