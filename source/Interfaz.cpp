#include "Interfaz.h"

int Interfaz::menuPrincipal()
{
	system("cls");
	int op;
	cout << "+-----------------------------------------------+\n";
	cout << "|" << setw(32) << ">>MENU PRINCIPAL<<" << setw(17) << "|\n";
	cout << "+-----------------------------------------------+\n";
	cout << "(1)->Administracion\n";
	cout << "(2)->Venta\n";
	cout << "(3)->Salir\n";
	cout << "Digite una opcion: "; /*cin >> op;*/
	cin >> op;
	return op;
}
