#include "AsientoReservado.h"
#include"utiles.h"

AsientoReservado::AsientoReservado() : cantidad(0), tamanio(5)
{
	for (int i = 0; i < tamanio; i++)
		asientos[i] = NULL;
}

AsientoReservado::~AsientoReservado()
{
	for (int i = 0; i < cantidad; i++)
		delete asientos[i];
}

AsientoReservado::AsientoReservado(const AsientoReservado & a)
{
	tamanio = a.tamanio;
	cantidad = a.cantidad;
	for (int i = 0; i < tamanio; i++)
		asientos[i] = NULL;
	for (int i = 0; i < cantidad; i++)
		asientos[i] = new Asiento(*a.asientos[i]);
}

AsientoReservado & AsientoReservado::operator=(const AsientoReservado & a)
{
	if (this != &a)
	{
		for (int i = 0; i < cantidad; i++)
			delete asientos[i];
		tamanio = a.tamanio;
		cantidad = a.cantidad;
		for (int i = 0; i < tamanio; i++)
			asientos[i] = NULL;
		for (int i = 0; i < cantidad; i++)
			asientos[i] = new Asiento(*a.asientos[i]);
	}
	return *this;
}

/*
	El asiento es creado a partir del constructor copia
*/
bool AsientoReservado::agregar(Asiento * _asiento)
{
	if (cantidad < tamanio)
	{
		asientos[cantidad++] = new Asiento(*_asiento);
		return true;
	}
	return false;
}

string AsientoReservado::mostrarAsientosReservados()
{
	stringstream s;
	for (int i = 0; i < cantidad; i++)
	{
		s << asientos[i]->mostrarAsiento()
			<< asientos[i]->mostrarVentanaPasillo() << "\n";
	}
	return s.str();
}

int AsientoReservado::getCantidad()
{
	return cantidad;
}

int AsientoReservado::getTamanio()
{
	return tamanio;
}

ostream & operator<<(ostream & out, AsientoReservado & _a)
{
	for (int i = 0; i < _a.cantidad; i++)
		out << *_a.asientos[i] << " ";
	out << "\n";
	return out;
}

ofstream & operator<<(ofstream & archivo, AsientoReservado & a)
{
	archivo << a.cantidad << "\n";
	for (int i = 0; i < a.cantidad; i++)
		archivo << * a.asientos[i];
	return archivo;
}

ifstream & operator>>(ifstream & archivo, AsientoReservado & a)
{
	string hilera = procesarHilera(archivo);
	stringstream particion(hilera);
	Asiento asiento;
	int cantidad = procesarInt(particion, '\n');
	a.cantidad = cantidad;
	for (int i = 0; i < cantidad; i++)
	{
		archivo >> asiento;
		a.asientos[i] = new Asiento(asiento);
	}

	return archivo;
}
