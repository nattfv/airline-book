#include "Interfaz.h"
#include"ExcepcionEntrada.h"
#include"utiles.h"

int Interfaz::menuPrincipal()
{
	try
	{
		system("cls");
		int op = 0;
		cout << "+-----------------------------------------------+\n";
		cout << "|" << setw(32) << ">>MENU PRINCIPAL<<" << setw(17) << "|\n";
		cout << "+-----------------------------------------------+\n";
		cout << "[1]->Administracion\n";
		cout << "[2]->Reservacion\n";
		cout << "[3]->Salir\n";
		cout << "[+]->Digite una opcion: ";
		op = obtenerValorEntero(1, 3);
		return op;
	}
	catch (ExcepcionEntrada& e)
	{
		cout << e.notificarError();
	}
}

int Interfaz::menuAdministracion()
{
	try
	{
		system("cls");
		int op;
		cout << "+-----------------------------------------------+\n";
		cout << "|" << setw(34) << ">>MENU ADMINISTRACION<<" << setw(15) << "|\n";
		cout << "+-----------------------------------------------+\n";
		cout << "[1]->Control Destinos\n";
		cout << "[2]->Control Pilotos\n";
		cout << "[3]->Control Aviones\n";
		//cout << "[4]->Control Vuelos\n";
		cout << "[4]->Control Vendedores\n";
		cout << "[5]->Control Vuelos\n";
		cout << "[6]->Salir\n";
		cout << "[+]->Digite una opcion: ";
		op = obtenerValorEntero(1, 6);
		return op;
	}
	catch (ExcepcionEntrada& e)
	{
		cout << e.notificarError();
	}
}

int Interfaz::menuAdministracionDe(string clase)
{
	try
	{
		system("cls");
		int op;
		cout << "+-------------------------------------+\n";
		cout << "|" << setw(15) << ">>Menu " << clase << setw(12 + (12 - clase.length())) << "|\n";
		cout << "+-------------------------------------+\n";
		cout << "[1]->Agregar " << clase << "\n";
		cout << "[2]->Mostrar " << clase << "\n";
		//cout << "[3]->Actualizar " << clase << "\n";
		cout << "[3]->Eliminar " << clase << "\n";
		cout << "[4]->Salir\n";
		cout << "[+]->Digite una opcion: ";
		op = obtenerValorEntero(1, 4);
		return op;
	}
	catch (ExcepcionEntrada& e)
	{
		cout << e.notificarError();
	}
}

int Interfaz::menuReservacion()
{
	try
	{
		system("cls");
		int op;
		cout << "+-----------------------------------------------+\n";
		cout << "|" << setw(32) << ">>MENU RESERVACION<<" << setw(17) << "|\n";
		cout << "+-----------------------------------------------+\n";
		cout << "[1]->Realizar reservacion\n";
		cout << "[2]->Mostrar campos reservados por vuelo\n";
		cout << "[3]->Mostrar reservas por vendedor\n";
		cout << "[4]->Salir\n";
		cout << "[+]->Digite una opcion: ";
		op = obtenerValorEntero(1, 4);
		return op;
	}
	catch (ExcepcionEntrada& e)
	{
		cout << e.notificarError();
	}
}

void Interfaz::opcionIncorrecta()
{
	system("cls");
	cout << "+-----------------------------------------------+\n";
	cout << "|" << setw(34) << ">>OPCION INCORRECTA<<" << setw(15) << "|\n";
	cout << "+-----------------------------------------------+\n";
	system("pause");
}

void Interfaz::ingresoExitoso()
{
	system("cls");
	cout << "+-----------------------------------------------+\n";
	cout << "|" << setw(34) << ">>INGRESO EXITOSO<<" << setw(15) << "|\n";
	cout << "+-----------------------------------------------+\n";
	system("pause");
}

void Interfaz::eliminacionExitosa()
{
	system("cls");
	cout << "+-----------------------------------------------+\n";
	cout << "|" << setw(34) << ">>ELIMINACION EXITOSA<<" << setw(15) << "|\n";
	cout << "+-----------------------------------------------+\n";
	system("pause");
}

void Interfaz::eliminacionFracasada()
{
	system("cls");
	cout << "+-----------------------------------------------+\n";
	cout << "|" << setw(34) << ">>ELIMINACION FRACASADA<<" << setw(15) << "|\n";
	cout << "+-----------------------------------------------+\n";
	system("pause");
}

/*
	Usado para mostrar un error que es controlado
	en la parte de la controladora y no en interfaz
*/
void Interfaz::mostrarError(string notificacion)
{
	system("cls");
	cout << "|" << setw(20) << ">>ERROR<<" << setw(15) << "|\n";
	cout << notificacion << endl;
	system("pause");
}

void Interfaz::seleccionarElemento(string clase, string accion)
{
	cout  << "Seleccione el " << clase  << " que desea " << accion << ": "; 
}

string Interfaz::ingresarDatoCadena(string dato, string clase)
{
	string info;
	cout << "Ingrese "<< dato <<" del " << clase << ": ";
	getline(cin, info);
	return info;
}
