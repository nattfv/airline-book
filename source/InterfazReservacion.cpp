#include "InterfazReservacion.h"
#include"ExcepcionExistencia.h"
#include"Iterador.h"
#include"utiles.h"

void InterfazReservacion::encabezadoReservacion()
{
	system("cls");
	cout << "+------------------------------------------+\n";
	cout << "|" << setw(25) << ">>RESERVACIONES<<" << setw(19) << "|\n";
	cout << "+------------------------------------------+\n";
}

void InterfazReservacion::mostrarTodosVuelosPasajeros(Aerolinea * aerolinea)
{
	Lista<Vuelo>* listaVuelos = aerolinea->obtenerVuelos();
	IteradorLista<Vuelo>* iterador = listaVuelos->crearIterador();
	int contador = 0;
	while (iterador->masElementos())
	{
		Vuelo* vuelo = iterador->proximoElemento();
		if (vuelo->esVueloPasajeros())
		{
			cout << "No. " << ++contador << "\n"
				<< vuelo->mostrarVuelo() << endl;
		}
	}
	delete iterador;
}

int InterfazReservacion::seleccionarVueloPasajeros(Aerolinea * aerolinea, string clase, string accion)
{
	bool correcto = false;
	int valor = 0;
	Lista<Vuelo>* listaVuelos = aerolinea->obtenerVuelos();
	int cantidadElementos = 0;

	IteradorLista<Vuelo>* iterador = listaVuelos->crearIterador();
	while (iterador->masElementos())
	{
		Vuelo* vuelo = iterador->proximoElemento();
		if (vuelo->esVueloPasajeros())
			cantidadElementos++;
	}
	delete iterador;

	while (!correcto)
	{
		try
		{
			if (cantidadElementos > 0)
			{
				encabezadoReservacion();
				mostrarTodosVuelosPasajeros(aerolinea);
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

void InterfazReservacion::desplegarAsientos(Vuelo * vuelo)
{
	Avion* avion = vuelo->obtenerAvion();
	MatrizAsiento* asientos = avion->obtenerPasajeros();
	int fila = asientos->getFila();
	int columna = asientos->getColumna();
	system("cls");
	cout << "+------------------------------------------+\n";
	cout << "|" << setw(25) << ">>ASIENTOS<<" << setw(19) << "|\n";
	cout << "+------------------------------------------+\n";
	for (int i = 0; i < fila; i++)
	{
		for (int j = 0; j < columna; j++)
		{
			cout << "[ "
				<< ((asientos->disponibilidadAsiento(i, j) ? "D" : "X"))
				<< " ]"
				<< (((j+1) % 3 == 0 && j != 0) ? "  " : "");
		}
		cout << "\n";
	}
	system("pause");
}
