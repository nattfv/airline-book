#include "InterfazVendedor.h"
#include"utiles.h"

void InterfazVendedor::encabezadoVendedor()
{
	system("cls");
	cout << "+------------------------------------------+\n";
	cout << "|" << setw(25) << ">>VENDEDORES<<" << setw(19) << "|\n";
	cout << "+------------------------------------------+\n";
}

void InterfazVendedor::mostrarTodosVendedores(Aerolinea * aerolinea)
{
	Lista<Vendedor>* listaVendedores = aerolinea->obtenerVendedores();
	encabezadoVendedor();
	cout << listaVendedores->toString();
	system("pause");
}

int InterfazVendedor::seleccionarVendedor(Aerolinea * aerolinea, string clase, string accion)
{
	bool correcto = false;
	int valor = 0;
	Lista<Vendedor>* listaVendedores = aerolinea->obtenerVendedores();
	int cantidadElementos = listaVendedores->cantidadElementos();
	while (!correcto)
	{
		try
		{
			mostrarTodosVendedores(aerolinea);
			if (cantidadElementos > 0)
			{
				Interfaz::seleccionarElemento(clase, accion);
				valor = obtenerValorEntero(1, cantidadElementos);
			}
			correcto = true;
		}
		catch (ExcepcionEntrada& e)
		{
			cout << e.notificarError();
		}
	}
	return valor;

}
