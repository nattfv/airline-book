#include<iostream>
#include"Fecha.h"
#include"Destino.h"
#include"Piloto.h"
#include"Vendedor.h"
#include"MatrizAsiento.h"
#include"Avion.h"
#include"Vuelo.h"
#include"Reservacion.h"
#include"Lista.h"
#include"Interfaz.h"
using namespace std;

int main()
{
	//Control para el menu
	bool menuPrincipal = false;
	bool menuAdministracion = false;
	bool menuEspecifica = false;

	//Control para la opcion a elegir
	int opcionMenuPrincipal = 0;
	int opcionMenuAdministracion = 0;
	int opcionMenuEspecifica = 0;

	//Control para las listas
	Lista<Destino>* listaDestinos = new Lista<Destino>();
	Lista<Piloto>* listaPilotos = new Lista<Piloto>();
	Lista<Avion>* listaAviones = new Lista<Avion>();
	Lista<Vuelo>* listaVuelos = new Lista<Vuelo>();
	Lista<Vendedor>* listaVendedor = new Lista<Vendedor>();
	Lista<Reservacion>* listaReservacion = new Lista<Reservacion>();

	while (!menuPrincipal)
	{
		opcionMenuPrincipal = Interfaz::menuPrincipal();
		switch (opcionMenuPrincipal)
		{
		case 1: //Administracion

			while (!menuAdministracion)
			{
				opcionMenuAdministracion = Interfaz::menuAdministracion();
				switch (opcionMenuAdministracion)
				{
				case 1: //Destinos
					while (!menuEspecifica)
					{
						opcionMenuEspecifica = Interfaz::menuAdministracionDe("destinos");
						if (opcionMenuEspecifica == 1)
							cout << "Agregar\n";
						else if (opcionMenuEspecifica == 2)
							cout << "Mostrar\n";
						else if (opcionMenuEspecifica == 3)
							cout << "Actualizar\n";
						else if (opcionMenuEspecifica == 4)
							cout << "Eliminar\n";
						else if (opcionMenuEspecifica == 5)
							menuEspecifica = true;
					}//FIN WHILE
					menuEspecifica = false;
					break;
				case 2: //Pilotos
					while (!menuEspecifica)
					{
						opcionMenuEspecifica = Interfaz::menuAdministracionDe("pilotos");
						if (opcionMenuEspecifica == 1)
							cout << "Agregar\n";
						else if (opcionMenuEspecifica == 2)
							cout << "Mostrar\n";
						else if (opcionMenuEspecifica == 3)
							cout << "Actualizar\n";
						else if (opcionMenuEspecifica == 4)
							cout << "Eliminar\n";
						else if (opcionMenuEspecifica == 5)
							menuEspecifica = true;
					}//FIN WHILE
					menuEspecifica = false;
					break;
				case 3: //Aviones
					while (!menuEspecifica)
					{
						opcionMenuEspecifica = Interfaz::menuAdministracionDe("aviones");
						if (opcionMenuEspecifica == 1)
							cout << "Agregar\n";
						else if (opcionMenuEspecifica == 2)
							cout << "Mostrar\n";
						else if (opcionMenuEspecifica == 3)
							cout << "Actualizar\n";
						else if (opcionMenuEspecifica == 4)
							cout << "Eliminar\n";
						else if (opcionMenuEspecifica == 5)
							menuEspecifica = true;
					}//FIN WHILE
					menuEspecifica = false;
					break;
				case 4: //Vuelos
					while (!menuEspecifica)
					{
						opcionMenuEspecifica = Interfaz::menuAdministracionDe("vuelos");
						if (opcionMenuEspecifica == 1)
							cout << "Agregar\n";
						else if (opcionMenuEspecifica == 2)
							cout << "Mostrar\n";
						else if (opcionMenuEspecifica == 3)
							cout << "Actualizar\n";
						else if (opcionMenuEspecifica == 4)
							cout << "Eliminar\n";
						else if (opcionMenuEspecifica == 5)
							menuEspecifica = true;
					}//FIN WHILE
					menuEspecifica = false;
					break;
				case 5: //Vendedores
					while (!menuEspecifica)
					{
						opcionMenuEspecifica = Interfaz::menuAdministracionDe("vendedores");
						if (opcionMenuEspecifica == 1)
							cout << "Agregar\n";
						else if (opcionMenuEspecifica == 2)
							cout << "Mostrar\n";
						else if (opcionMenuEspecifica == 3)
							cout << "Actualizar\n";
						else if (opcionMenuEspecifica == 4)
							cout << "Eliminar\n";
						else if (opcionMenuEspecifica == 5)
							menuEspecifica = true;
					}//FIN WHILE
					menuEspecifica = false;
					break;
				case 6:
					menuAdministracion = true;
					break;
				}//FIN SWITCH
			}//FIN WHILE
			menuAdministracion = false;
			break;
		case 2: //Reservacion
			break;
		case 3: //Salir
			menuPrincipal = true;
			break;
		} //FIN SWITCH
	}//FIN WHILE
	system("pause");
	return 0;
}