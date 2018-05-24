#include "AsientoReservado.h"

AsientoReservado::AsientoReservado() : cantidad(0), tamanio(10)
{
	for (int i = 0; i < tamanio; i++)
		asientos[i] = NULL;
}

AsientoReservado::~AsientoReservado()
{
	for (int i = 0; i < cantidad; i++)
		delete asientos[i];
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
		s << asientos[i]->mostrarAsiento() << "\n";
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
