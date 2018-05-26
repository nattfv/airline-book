#pragma once
#include<time.h>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

class Fecha
{
private:
	int dia;
	int mes;
	int anio;
	static int finalMes[12]; // enteros con la cantidad de dias que tiene cada mes
public:
	Fecha();
	Fecha(int _dia, int _mes, int _anio);
	Fecha(const Fecha& _f);
	~Fecha();
	Fecha& operator=(const Fecha& _f);
	string mostrarFormatoFecha();
	void obtenerFechaSistema();
	void verificarFecha(int _dia, int _mes, int _anio);
	bool esBisiesto(int _anio);
	friend ostream& operator<<(ostream& out, Fecha& _f);
	friend ofstream& operator<<(ofstream& archivo, Fecha &_d);
	friend ifstream& operator>>(ifstream& archivo, Fecha &_d);
};