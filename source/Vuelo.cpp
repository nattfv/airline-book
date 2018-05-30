#include "Vuelo.h"
#include"utiles.h"

Vuelo::Vuelo() :
	identificacion(""), avion(NULL), destino(NULL), piloto(NULL)
{
}

Vuelo::Vuelo(string _identificacion, Avion * _avion, Destino* _destino, Piloto * _piloto)
{
	identificacion = _identificacion;
	avion = new Avion(*_avion); // constructor copia
	destino = new Destino(*_destino); // constructor copia
	piloto = new Piloto(*_piloto); // constructor copia
}

Vuelo::Vuelo(const Vuelo & _v)
{
	identificacion = _v.identificacion;
	avion = new Avion(*_v.avion);
	destino = new Destino(*_v.destino);
	piloto = new Piloto(*_v.piloto);
}

Vuelo::~Vuelo()
{
	delete avion;
	delete destino;
	delete piloto;
}

Vuelo & Vuelo::operator=(const Vuelo & v)
{
	if (this != &v)
	{
		if (avion)
			delete avion;
		if(destino)
			delete destino;
		if (piloto)
			delete piloto;
		identificacion = v.identificacion;
		avion = new Avion(*v.avion);
		destino = new Destino(*v.destino);
		piloto = new Piloto(*v.piloto);
	}
	return *this;
}

void Vuelo::prepararAvion()
{
	avion->crearAsientos();
}

string Vuelo::mostrarVuelo()
{
	stringstream s;
	s << "Identificacion del vuelo: " << identificacion << "\n";
	s << destino->mostrarDestino();
		//<< avion->mostrarAvion()
		//<< piloto->mostrarPiloto();
	return s.str();
}

Avion * Vuelo::obtenerAvion()
{
	return avion;
}

Destino * Vuelo::obtenerDestino()
{
	return destino;
}

Piloto * Vuelo::obtenerPiloto()
{
	return piloto;
}

/*
	Verifica si el asiento seleccionado esta disponible
*/
bool Vuelo::estaDisponibleAsiento(int _fila, int _columna)
{
	//Avion* avion = vuelo->obtenerAvion(); //avion asignado al vuelo
	//MatrizAsiento* asientos = avion->obtenerPasajeros(); //los asientos actualizados del avion
	//Asiento* posibleAsiento = asientos->obtenerAsiento(_fila, _columna); //el asiento que quiero reservar
	//return posibleAsiento->getDisponible(); //responsablidad unica
	return avion->estaDisponibleAsiento(_fila, _columna);
}

bool Vuelo::esVueloPasajeros()
{
	return avion->llevaPasajeros();
}

void Vuelo::actualizarPasajero(int fila, int columna)
{
	 Avion* avion = obtenerAvion(); //avion asignado al vuelo
	 MatrizAsiento* asientos = avion->obtenerPasajeros(); //los asientos actualizados del avion
	 Asiento* posibleAsiento = asientos->obtenerAsiento(fila, columna); //el asiento que quiero reservar
	 posibleAsiento->setDisponible(false); //importante, para no volver a comprar el mismo
}

//int Vuelo::capacidadVuelo()
//{
//	return avion->cantidadPasajeros();
//}

ostream & operator<<(ostream & out, Vuelo & _v)
{
	out << _v.identificacion << "\n"
		<< *_v.destino;
	//out << *_v.piloto;
	out << *_v.avion;
	return out;
}

ofstream & operator<<(ofstream & archivo, Vuelo & v)
{
	archivo << v.identificacion << "\n";
	archivo << *v.destino;
	archivo << *v.piloto;
	archivo << *v.avion;
	return archivo;
}

ifstream & operator>>(ifstream & archivo, Vuelo & v)
{
	string hilera = procesarHilera(archivo);
	stringstream particion(hilera);
	string identificacion;
	Destino destino;
	Piloto piloto;
	Avion avion;
	getline(particion, identificacion, '\n');
	archivo >> destino;
	archivo >> piloto;
	archivo >> avion;
	v.identificacion = identificacion;
	v.destino = new Destino(destino);
	v.piloto = new Piloto(piloto);
	v.avion = new Avion(avion);
	return archivo;
}
