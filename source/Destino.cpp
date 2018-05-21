#include "Destino.h"

Destino::Destino()
{
	origen = "";
	destino = "";
	partida = NULL;
	regreso = NULL;
}

/*
	_partida y _regreso son punteros creados por new
*/
Destino::Destino(string _origen, string _destino, Fecha * _partida, Fecha * _regreso) : 
	origen(_origen), destino(_destino), partida(_partida), regreso(_regreso)
{
}

/*
	como Destino tiene "huesos" tengo que aprovechar el operador=
	y el constructor copia
*/
Destino::Destino(const Destino & _d)
{
	origen = _d.origen;
	destino = _d.destino;
	partida = new Fecha(*_d.partida);
	regreso = new Fecha(*_d.regreso);
}

Destino::~Destino()
{
	delete partida;
	delete regreso;
}

Destino & Destino::operator=(const Destino & _d)
{
	if (this != &_d)
	{
		delete partida;
		delete regreso;
		origen = _d.origen;
		destino = _d.destino;
		partida = new Fecha(*_d.partida);
		regreso = new Fecha(*_d.regreso);
	}
	return *this;
}

string Destino::mostrarDestino()
{
	stringstream s;
	s << "Origen: " << origen << "\n"
		<< "Destino: " << destino << "\n"
		<< "Fecha de partida: " << partida->mostrarFormatoFecha() << "\n"
		<< "Fecha de regreso: " << regreso->mostrarFormatoFecha() << "\n";
	return s.str();
}
