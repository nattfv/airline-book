#include "InterfazMotor.h"
#include"utiles.h"

void InterfazMotor::encabezadoMotor()
{
	system("cls");
	cout << "+------------------------------------------+\n";
	cout << "|" << setw(25) << ">>MOTORES<<" << setw(19) << "|\n";
	cout << "+------------------------------------------+\n";
}

int InterfazMotor::ingresarCantidadMotores()
{
	bool correcto = false;
	int valor = 0;
	while (!correcto)
	{
		try
		{
			encabezadoMotor();
			cout << "Seleccione cuantos motores tiene el avion\n";
			cout << "[1]->1 motor\n";
			cout << "[2]->2 motores\n";
			cout << "[3]->4 motores\n";
			cout << "[+]->Digite una opcion: ";
			valor = obtenerValorEntero(1, 3);
			correcto = true;
		}
		catch (ExcepcionEntrada& e)
		{
			cout << e.notificarError();
		}
	}
	return valor;
}
