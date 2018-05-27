#include "InterfazDestino.h"
#include"ExcepcionExistencia.h"
#include"utiles.h"

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
	//cin.clear();
	//cin.ignore(255, '\n');
	cout << "Digite la provincia y pais de origen: ";
	getline(cin, origen);
	return origen;
}

string InterfazDestino::ingresarLugarDestino()
{
	string destino;
	//cin.clear();
	//cin.ignore(255, '\n');
	cout << "Digite la provincia y pais de destino: ";
	getline(cin, destino);
	return destino;
}

void InterfazDestino::encabezadoDestino()
{
	system("cls");
	cout << "+------------------------------------------+\n";
	cout << "|" << setw(25) << ">>DESTINOS<<" << setw(19) << "|\n";
	cout << "+------------------------------------------+\n";
}

void InterfazDestino::encabezadoFechaPartida()
{
	system("cls");
	cout << "+------------------------------------------+\n";
	cout << "|" << setw(30) << ">>FECHA DE PARTIDA<<" << setw(14) << "|\n";
	cout << "+------------------------------------------+\n";
}

void InterfazDestino::encabezadoFechaRegreso()
{
	system("cls");
	cout << "+------------------------------------------+\n";
	cout << "|" << setw(30) << ">>FECHA DE REGRESO<<" << setw(14) << "|\n";
	cout << "+------------------------------------------+\n";
}

void InterfazDestino::mostrarTodosDestinos(Aerolinea * aerolinea)
{
	Lista<Destino>* listaDestinos = aerolinea->obtenerDestinos();
	encabezadoDestino();
	cout << listaDestinos->toString();
	system("pause");
}

int InterfazDestino::seleccionarDestino(Aerolinea * aerolinea, string clase, string accion)
{
	bool correcto = false;
	int valor = 0;
	Lista<Destino>* listaDestinos = aerolinea->obtenerDestinos();
	int cantidadElementos = listaDestinos->cantidadElementos();
	while (!correcto)
	{
		try
		{
			mostrarTodosDestinos(aerolinea);
			if (cantidadElementos > 0)
			{
				Interfaz::seleccionarElemento(clase, accion);
				valor = obtenerValorEntero(1, cantidadElementos);
			}
			else
				throw ExcepcionExistencia("destinos", accion);
			correcto = true;
		}
		catch (ExcepcionEntrada& e)
		{
			cout << e.notificarError();
		}
	}
	return valor;
}
