#include "InterfazDestino.h"

int InterfazDestino::ingresarDia()
{
	int valor;
	bool correcto = false;
	while (!correcto)
	{
		try
		{
			cout << "Digite el dia: ";
			valor = obtenerValorEntero(1, 31);
			correcto = true;
		}
		catch (ExcepcionEntrada& e)
		{
			cout << e.notificarError();
		}
	}
	return valor;
}

int InterfazDestino::ingresarMes()
{
	int valor;
	bool correcto = false;
	while (!correcto)
	{
		try
		{
			cout << "Digite el mes: ";
			valor = obtenerValorEntero(1, 12);
			correcto = true;
		}
		catch (ExcepcionEntrada& e)
		{
			cout << e.notificarError();
		}
	}
	return valor;
}

int InterfazDestino::ingresarAnio()
{
	int valor;
	bool correcto = false;
	while (!correcto)
	{
		try
		{
			cout << "Digite el anio: ";
			valor = obtenerValorEntero(2000, 2030);
			correcto = true;
		}
		catch (ExcepcionEntrada& e)
		{
			cout << e.notificarError();
		}
	}
	return valor;
}

string InterfazDestino::ingresarLugarOrigen()
{
	string origen;
	cout << "Digite la provincia y pais de origen: ";
	cin >> origen;
	return origen;
}

string InterfazDestino::ingresarLugarDestino()
{
	string destino;
	cout << "Digite la provincia y pais de destino: ";
	cin >> destino;
	return destino;
}

void InterfazDestino::encabezadoDestino()
{
	system("cls");
	cout << "+----------------------------------------------+\n";
	cout << "|" << setw(40) << ">>DESTINO<<" << setw(33) << "|\n";
	cout << "+----------------------------------------------+\n";
}

void InterfazDestino::encabezadoFecha()
{
	system("cls");
	cout << "+----------------------------------------------+\n";
	cout << "|" << setw(40) << ">>FECHA<<" << setw(33) << "|\n";
	cout << "+----------------------------------------------+\n";
}
