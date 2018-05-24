#pragma once
#include"Asiento.h"

class AsientoReservado
{
private:
	int tamanio;
	int cantidad;
	Asiento* asientos[10];
public:
	AsientoReservado();
	~AsientoReservado();
	bool agregar(Asiento* _asiento);
	string mostrarAsientosReservados();
	int getCantidad();
	int getTamanio();
	friend ostream& operator<<(ostream& out, AsientoReservado& _a);
};