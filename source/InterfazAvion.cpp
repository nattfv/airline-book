#include "InterfazAvion.h"
#include"ExcepcionExistencia.h"
#include"utiles.h"

void InterfazAvion::encabezadoAvion()
{
	system("cls");
	cout << "+------------------------------------------+\n";
	cout << "|" << setw(25) << ">>AVIONES<<" << setw(19) << "|\n";
	cout << "+------------------------------------------+\n";
}

int InterfazAvion::menuTransporteAvion()
{
	bool correcto = false;
	int valor = 0;
	while (!correcto)
	{
		try
		{
			encabezadoAvion();
			cout << "Seleccione el tipo de avion\n";
			cout << "[1]->Para transporte de pasajeros\n";
			cout << "[2]->Para transporte de carga\n";
			cout << "[+]->Digite una opcion: ";
			valor = obtenerValorEntero(1, 2);
			correcto = true;
		}
		catch (ExcepcionEntrada& e)
		{
			cout << e.notificarError();
		}
	}
	return valor;
}

int InterfazAvion::menuAsientosAvion()
{
	bool correcto = false;
	int valor = 0;
	while (!correcto)
	{
		try
		{
			encabezadoAvion();
			cout << "Seleccione el tamanio de avion\n";
			cout << "[1]->Pequenio(4 asientos por fila)\n";
			cout << "[2]->Grande(7 asientos por fila)\n";
			cout << "[+]->Digite una opcion: ";
			valor = obtenerValorEntero(1, 2);
			correcto = true;
		}
		catch (ExcepcionEntrada& e)
		{
			cout << e.notificarError();
		}
	}
	return valor;
}

double InterfazAvion::ingresarPesoAvion()
{
	double peso = 0.0;
	bool correcto = false;
	while (!correcto)
	{
		try
		{
			encabezadoAvion();
			cout << "Ingrese el peso en kilogramos que puede transportar: ";
			peso = (double)obtenerValorEntero(40000, 150000);
			correcto = true;
		}
		catch (ExcepcionEntrada& e)
		{
			cout << e.notificarError();
		}
	}
	return peso;
}

void InterfazAvion::mostrarTodosAviones(Aerolinea * aerolinea)
{
	Lista<Avion>* listaAviones = aerolinea->obtenerAviones();
	encabezadoAvion();
	cout << listaAviones->toString();
	system("pause");
}

int InterfazAvion::seleccionarAvion(Aerolinea * aerolinea, string clase, string accion)
{
	bool correcto = false;
	int valor = 0;
	Lista<Avion>* listaAviones = aerolinea->obtenerAviones();
	int cantidadElementos = listaAviones->cantidadElementos();
	while (!correcto)
	{
		try
		{
			if (cantidadElementos > 0)
			{
				mostrarTodosAviones(aerolinea);
				Interfaz::seleccionarElemento(clase, accion);
				valor = obtenerValorEntero(1, cantidadElementos);
			}
			else
				throw ExcepcionExistencia("aviones", accion);
			correcto = true;
		}
		catch (ExcepcionEntrada& e)
		{
			cout << e.notificarError();
		}
	}
	return valor;
}
