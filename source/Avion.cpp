#include "Avion.h"

Avion::Avion() : codigo(""), transporte(""), tamanio(""), pesoCarga(0.0), disponible(true), pasajeros(NULL)
{
}

Avion::Avion(string _codigo, string _transporte, string _tamanio) :
	codigo(_codigo), transporte(_transporte), tamanio(_tamanio), pesoCarga(0.0), disponible(true), pasajeros(NULL)
{
}

Avion::Avion(string _codigo, string _transporte, string _tamanio, double _pesoCarga) :
	codigo(_codigo), transporte(_transporte), tamanio(_tamanio), pesoCarga(_pesoCarga), disponible(true), pasajeros(NULL)
{
}

/*
	Recordar inicializar los pasajeros con la ayuda
	del metodo crearAsientos()
*/
Avion::Avion(const Avion & _a)
{
	codigo = _a.codigo;
	transporte = _a.transporte;
	tamanio = _a.tamanio;
	pesoCarga = _a.pesoCarga;
	codigo = _a.codigo;
	pasajeros = NULL;
}

Avion::~Avion()
{
	if (pasajeros)
		delete pasajeros;
}

/*
	Crea la matriz dependiento del tamanio del 
	avion y le da el formato a los asientos
*/
void Avion::crearAsientos()
{
	if (transporte == "pasajero")
	{
		if (tamanio == "pequenio")
			pasajeros = new  MatrizAsiento(12, 4);
		else
			pasajeros = new MatrizAsiento(12, 7);
		pasajeros->darFormatoTodosAsientos();
	}
}

string Avion::mostrarAvion()
{
	stringstream s;
	s << "Codigo del avion: " << codigo << "\n"
		<< "Tipo transporte: " << transporte << "\n"
		<< "Tamanio: " << tamanio << "\n";
	if (transporte == "carga")
		s << "Capacidad maxima: " << pesoCarga << " kg\n";
	return s.str();
}

MatrizAsiento * Avion::obtenerPasajeros()
{
	return pasajeros;
}
