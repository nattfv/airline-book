#include "Destino.h"
#include"utiles.h"

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
		
		if(partida) //porque si uso un predeterminado viene en null
			delete partida;
		if(regreso) //porque si uso un predeterminado viene en null
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

ostream & operator<<(ostream & out, Destino & _d)
{
	out << "Partida: " << _d.origen << "\t" << *_d.partida << "\n";
	out << "Regreso: " << _d.destino << "\t" << *_d.regreso << "\n";
	return out;
}

ofstream & operator<<(ofstream & archivo, Destino & _d)
{
	archivo << _d.origen << "\t";
	archivo << _d.destino << "\n";
	archivo << *_d.partida;
	archivo << *_d.regreso;
	return archivo;
}

ifstream & operator>>(ifstream & archivo, Destino & d)
{
	string hilera = procesarHilera(archivo);
	stringstream particion(hilera);
	string origen, destino;
	Fecha partida, regreso;
	getline(particion, origen, '\t');
	getline(particion, destino, '\n');
	archivo >> partida;
	archivo >> regreso;
	d.origen = origen;
	d.destino = destino;
	d.partida = new Fecha(partida);
	d.regreso = new Fecha(regreso);
	return archivo;
}
