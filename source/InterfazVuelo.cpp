#include "InterfazVuelo.h"
#include"utiles.h"
#include"ExcepcionExistencia.h"

void InterfazVuelo::encabezadoVuelo()
{
	system("cls");
	cout << "+------------------------------------------+\n";
	cout << "|" << setw(25) << ">>VUELOS<<" << setw(19) << "|\n";
	cout << "+------------------------------------------+\n";
}

void InterfazVuelo::mostrarTodosVuelos(Aerolinea* aerolinea)
{
	Lista<Vuelo>* listaVuelos = aerolinea->obtenerVuelos();
	encabezadoVuelo();
	cout << listaVuelos->toString();
	system("pause");
}

int InterfazVuelo::seleccionarVuelo(Aerolinea * aerolinea, string clase, string accion)
{
	bool correcto = false;
	int valor = 0;
	Lista<Vuelo>* listaVuelos = aerolinea->obtenerVuelos();
	int cantidadElementos = listaVuelos->cantidadElementos();
	while (!correcto)
	{
		try
		{
			if (cantidadElementos > 0)
			{
				mostrarTodosVuelos(aerolinea);
				Interfaz::seleccionarElemento(clase, accion);
				valor = obtenerValorEntero(1, cantidadElementos);
			}
			else
				throw ExcepcionExistencia("vuelos", accion);
			correcto = true;
		}
		catch (ExcepcionEntrada& e)
		{
			cout << e.notificarError();
		}
	}
	return valor;
}
