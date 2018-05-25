#include "Interfaz.h"

int Interfaz::menuPrincipal()
{
	system("cls");
	int op;
	cout << "+-----------------------------------------------+\n";
	cout << "|" << setw(32) << ">>MENU PRINCIPAL<<" << setw(17) << "|\n";
	cout << "+-----------------------------------------------+\n";
	cout << "[1]->Administracion\n";
	cout << "[2]->Venta\n";
	cout << "[3]->Salir\n";
	cout << "[+]->Digite una opcion: "; /*cin >> op;*/
	cin >> op;
	return op;
}

int Interfaz::menuAdministracion()
{
	system("cls");
	int op;
	cout << "+-----------------------------------------------+\n";
	cout << "|" << setw(34) << ">>MENU ADMINISTRACION<<" << setw(15) << "|\n";
	cout << "+-----------------------------------------------+\n";
	cout << "[1]->Control Destinos\n";
	cout << "[2]->Control Pilotos\n";
	cout << "[3]->Control Aviones\n";
	cout << "[4]->Control Vuelos\n";
	cout << "[5]->Control Vendedores\n";
	cout << "[6]->Salir\n";
	cout << "[+]->Digite una opcion: ";
	cin >> op;
	return op;
}

int Interfaz::menuAdministracionDe(string clase)
{
	system("cls");
	int op;
	cout << "+-------------------------------------+\n";
	cout << "|" << setw(15) << ">>Menu " << clase << setw(12 + (12 - clase.length())) << "|\n";
	cout << "+-------------------------------------+\n";
	cout << "[1]->Agregar " << clase << "\n";
	cout << "[2]->Mostrar " << clase << "\n";
	cout << "[3]->Actualizar " << clase << "\n";
	cout << "[4]->Eliminar " << clase << "\n";
	cout << "[5]->Salir\n";
	cin >> op;
	return op;
}

void Interfaz::opcionIncorrecta()
{
	system("cls");
	cout << "+-----------------------------------------------+\n";
	cout << "|" << setw(34) << ">>OPCION INCORRECTA<<" << setw(15) << "|\n";
	cout << "+-----------------------------------------------+\n";
	system("pause");
}

void Interfaz::seleccionarElemento(string clase, string accion)
{
	cout  << "Seleccione el " << clase  << " que desea " << accion << ": "; //...pendiente
}
