#include "Fecha.h"

int Fecha::finalMes[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Fecha::Fecha()
{
	obtenerFechaSistema();
}

Fecha::Fecha(int _dia, int _mes, int _anio) : 
	dia(_dia), mes(_mes), anio(_anio)
{
	verificarFecha(_dia, _mes, _anio);
}

Fecha::Fecha(const Fecha & _f) //Supongo que _f ya debe de venir verificada
{
	dia = _f.dia;
	mes = _f.mes;
	anio = _f.anio;
}

Fecha::~Fecha()
{
}

Fecha& Fecha::operator=(const Fecha & _f) //Supongo que _f ya debe de venir verificada
{
	dia = _f.dia;
	mes = _f.mes;
	anio = _f.anio;
	return *this;
}

string Fecha::mostrarFormatoFecha()
{
	stringstream s;
	s << dia << "/" << mes << "/" << anio;
	return s.str();
}

void Fecha::obtenerFechaSistema()
{
	time_t time_date = time(&time_date);
	struct tm date;
	localtime_s(&date, &time_date);
	dia = date.tm_mday;
	mes = date.tm_mon + 1;
	anio = date.tm_year + 1900;
}

void Fecha::verificarFecha(int _dia, int _mes, int _anio)
{
	// primera excepcion para el anio
	if (_anio >= 2000 && _anio <= 2030) //supongamos que tiene 12 anios para pagar
		anio = _anio;
	else
		throw (-1)/*AnioError(_dia, _mes, _anio)*/;

	// segunda excepcion para el mes
	if (_mes >= 1 && _mes <= 12)
		mes = _mes;
	else
		throw (-1)/*MesError(_dia, _mes, _anio)*/;

	// tercera excepcion para el dia
	// un || resuelve el problema de otro if para cualquier otro mes si el 
	// anio no es bisiesto, para lanzar una excepcion correctamente
	if ((_mes == 2 && esBisiesto(_anio) && _dia >= 1 && _dia <= 29) ||
		(_dia >= 1 && _dia <= finalMes[_mes - 1]))
		dia = _dia;
	else
		throw (-1)/*DiaError(_dia, nombreMes[_mes - 1], _anio)*/;
}

bool Fecha::esBisiesto(int _anio)
{
	if (_anio % 4 == 0 && (_anio % 100 != 0 || _anio % 400 == 0)) // algoritmo para saber si es bisiesto
		return true;
	else
		return false;
}
