#include "Avion.h"
#include"utiles.h"

Avion::Avion() : codigo(""), transporte(""), tamanio(""), pesoCarga(0.0), disponible(true), pasajeros(NULL), motor(NULL)
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

Avion::Avion(string _codigo, string _transporte, string _tamanio, double _pesoCarga, Motor* _motor, bool _disponible, MatrizAsiento* _pasajeros) :
	codigo(_codigo), transporte(_transporte), tamanio(_tamanio), pesoCarga(_pesoCarga), disponible(_disponible), pasajeros(_pasajeros), motor(_motor)
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
	if (_a.pasajeros)
		pasajeros = new MatrizAsiento(*_a.pasajeros);
	else
		pasajeros = NULL;
	motor = new Motor(*_a.motor);
}

Avion::~Avion()
{
	if (pasajeros)
		delete pasajeros;
	delete motor;
}

Avion & Avion::operator=(const Avion & a)
{
	if (this != &a)
	{
		if (pasajeros)
			delete pasajeros;
		delete motor;
		codigo = a.codigo;
		transporte = a.transporte;
		tamanio = a.tamanio;
		pesoCarga = a.pesoCarga;
		disponible = a.disponible;
		if (a.pasajeros)
			pasajeros = new MatrizAsiento(*a.pasajeros);
		else
			pasajeros = NULL;
		motor = new Motor(*a.motor);
	}
	return *this;
}

/*
	Crea la matriz dependiento del tamanio del 
	avion y le da el formato a los asientos
*/
void Avion::crearAsientos()
{
	if (transporte == "pasajeros")
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
		<< "Tamanio: " << tamanio;
	if (transporte == "carga")
		s << "\nCapacidad maxima: " << pesoCarga << " kg";
	s << "\n" <<motor->mostrarMotor() << "\n";
	return s.str();
}

MatrizAsiento * Avion::obtenerPasajeros()
{
	return pasajeros;
}

bool Avion::llevaPasajeros()
{
	return transporte == "pasajeros";
}

bool Avion::estaDisponibleAsiento(int fila, int columna)
{
	return pasajeros->disponibilidadAsiento(fila, columna);
}

bool Avion::quedaCampoPasajeros()
{
	return pasajeros->cantidadAsientosDisponibles() != 0;
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
	archivo << d.disponible << "\t";
	if (d.pasajeros) //si el avion es para pasajeros y esta preparado para viajar
	{
		archivo << true << "\n"; //si tiene que leer asientos
		archivo << *d.pasajeros;
	}
	else
		archivo << false << "\n"; //no tiene que leer asientos
	archivo << *d.motor;
	return archivo;
}

ifstream & operator>>(ifstream & archivo, Avion & d)
{
	string hilera = procesarHilera(archivo);
	MatrizAsiento* pasajeros = NULL;
	Motor motor;
	stringstream particion(hilera);
	string codigo, transporte, tamanio;
	double pesoCarga;
	bool disponible;
	bool leerAsientos;
	getline(particion, codigo, '\t');
	getline(particion, transporte, '\t');
	getline(particion, tamanio, '\t');
	pesoCarga = procesarDouble(particion, '\t');
	disponible = procesarBoolean(particion, '\t');
	leerAsientos = procesarBoolean(particion, '\n');
	d.codigo = codigo;
	d.transporte = transporte;
	d.tamanio = tamanio;
	d.pesoCarga = pesoCarga;
	d.disponible = disponible;
	//no encuentro la manera de separarlo(hacerlo en la matriz)
	if (leerAsientos) //leer la hilera de la matriz
	{
		string hileraMatriz = procesarHilera(archivo);
		stringstream particionMatriz(hileraMatriz);
		int filas = procesarInt(particionMatriz, '\t');
		int columnas = procesarInt(particionMatriz, '\t');
		int cantidadAsientosOcupados = procesarInt(particionMatriz, '\n');
		pasajeros = new MatrizAsiento(filas, columnas);
		pasajeros->darFormatoTodosAsientos(); //porque ahora el avion no se va a prepara, ya debe venir preparado
		for (int i = 0; i < cantidadAsientosOcupados; i++)
		{
			string hileraAsiento = procesarHilera(archivo);
			stringstream particionAsiento(hileraAsiento);
			int fila = procesarInt(particionAsiento, '\t');
			int columna = procesarInt(particionAsiento, '\n');
			pasajeros->cambiarDisponiblidadAsiento(fila, columna, false);
		}
	}
	d.pasajeros = pasajeros;
	archivo >> motor;
	d.motor = new Motor(motor);
	return archivo;
}
