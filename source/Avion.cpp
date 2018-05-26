#include "Avion.h"
#include"utiles.h"

Avion::Avion() : codigo(""), transporte(""), tamanio(""), pesoCarga(0.0), disponible(true), pasajeros(NULL)
{
}

//Avion::Avion(string _codigo, string _transporte, string _tamanio) :
//	codigo(_codigo), transporte(_transporte), tamanio(_tamanio), pesoCarga(0.0), disponible(true), pasajeros(NULL)
//{
//}

//Avion::Avion(string _codigo, string _transporte, string _tamanio, double _pesoCarga) :
//	codigo(_codigo), transporte(_transporte), tamanio(_tamanio), pesoCarga(_pesoCarga), disponible(true), pasajeros(NULL)
//{
//}

Avion::Avion(string _codigo, string _transporte, string _tamanio, double _pesoCarga, bool _disponible) : 
	codigo(_codigo), transporte(_transporte), tamanio(_tamanio), pesoCarga(_pesoCarga), disponible(_disponible), pasajeros(NULL)
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
	disponible = _a.disponible;
	pasajeros = NULL;
}

Avion::~Avion()
{
	if (pasajeros)
		delete pasajeros;
}

Avion & Avion::operator=(const Avion & a)
{
	if (this != &a)
	{
		if (pasajeros)
			delete pasajeros;
		codigo = a.codigo;
		transporte = a.transporte;
		tamanio = a.tamanio;
		pesoCarga = a.pesoCarga;
		disponible = a.disponible;
		pasajeros = NULL;
	}
	return *this;
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
			pasajeros = new  MatrizAsiento(4, 6);
		else
			pasajeros = new MatrizAsiento(7, 6);
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

ostream & operator<<(ostream & out, Avion & _a)
{
	out << _a.codigo << "\t" << _a.transporte << "\t" << _a.tamanio << "\n";
	return out;
}

ofstream & operator<<(ofstream & archivo, Avion & d)
{
	archivo << d.codigo << "\t";
	archivo << d.transporte << "\t";
	archivo << d.tamanio << "\t";
	archivo << d.pesoCarga << "\t";
	archivo << d.disponible << "\n";
	return archivo;
}

ifstream & operator>>(ifstream & archivo, Avion & d)
{
	string hilera = procesarHilera(archivo);
	stringstream particion(hilera);
	string codigo, transporte, tamanio;
	double pesoCarga;
	bool disponible;
	getline(particion, codigo, '\t');
	getline(particion, transporte, '\t');
	getline(particion, tamanio, '\t');
	pesoCarga = procesarDouble(particion, '\t');
	disponible = procesarBoolean(particion, '\n');
	d.codigo = codigo;
	d.transporte = transporte;
	d.tamanio = tamanio;
	d.pesoCarga = pesoCarga;
	d.disponible = disponible;
	return archivo;
}
