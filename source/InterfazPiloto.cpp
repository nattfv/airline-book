#include "InterfazPiloto.h"
#include"ExcepcionExistencia.h"
#include"utiles.h"

void InterfazPiloto::encabezadoPiloto()
{
	system("cls");
	cout << "+------------------------------------------+\n";
	cout << "|" << setw(25) << ">>PILOTOS<<" << setw(19) << "|\n";
	cout << "+------------------------------------------+\n";
}

void InterfazPiloto::mostrarTodosPilotos(Aerolinea * aerolinea)
{
	Lista<Piloto>* listaPilotos = aerolinea->obtenerPilotos();
	encabezadoPiloto();
	cout << listaPilotos->toString();
	system("pause");
}

int InterfazPiloto::seleccionarPiloto(Aerolinea * aerolinea, string clase, string accion)
{
	bool correcto = false;
	int valor = 0;
	Lista<Piloto>* listaPilotos = aerolinea->obtenerPilotos();
	int cantidadElementos = listaPilotos->cantidadElementos();
	while (!correcto)
	{
		try
		{
			
			if (cantidadElementos > 0)
			{
				mostrarTodosPilotos(aerolinea);
				Interfaz::seleccionarElemento(clase, accion);
				valor = obtenerValorEntero(1, cantidadElementos);
			}
			else
				throw ExcepcionExistencia("pilotos", accion);
			correcto = true;
		}
		catch (ExcepcionEntrada& e)
		{
			cout << e.notificarError();
		}
	}
	return valor;
}
