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
	AsientoReservado(const AsientoReservado& a);
	AsientoReservado& operator=(const AsientoReservado& a);
	bool agregar(Asiento* _asiento);
	string mostrarAsientosReservados();
	int getCantidad();
	int getTamanio();
	friend ostream& operator<<(ostream& out, AsientoReservado& _a);
	friend ofstream& operator<<(ofstream& archivo, AsientoReservado& a);
	friend ifstream& operator>>(ifstream& archivo, AsientoReservado& a);
};