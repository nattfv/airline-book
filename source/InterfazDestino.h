#pragma once
#include<iomanip>
#include<iostream>
#include<string>
#include"utiles.h"
using namespace std;

class InterfazDestino
{
public:
	static int ingresarDia();
	static int ingresarMes();
	static int ingresarAnio();
	static string ingresarLugarOrigen();
	static string ingresarLugarDestino();
	static void encabezadoDestino();
	static void encabezadoFecha();
};
