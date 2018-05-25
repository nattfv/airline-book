#include"InterfazDestino.h"
#include"Aerolinea.h"
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

	//Aerolinea
	Aerolinea* aerolinea = new Aerolinea();
	Lista<Destino>* listaDestinos = aerolinea->obtenerDestinos();

	//Archivos
	ofstream archivoDestinos("../destinos.txt", ios::out);

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
						if (opcionMenuEspecifica == 1) //Agregar Destinos
						{
							InterfazDestino::encabezadoFechaPartida();
							int dia = InterfazDestino::ingresarDia();
							int mes = InterfazDestino::ingresarMes();
							int anio = InterfazDestino::ingresarAnio();
							InterfazDestino::encabezadoFechaRegreso();
							int dia1 = InterfazDestino::ingresarDia();
							int mes1 = InterfazDestino::ingresarMes();
							int anio1 = InterfazDestino::ingresarAnio();
							InterfazDestino::encabezadoDestino();
							string origen = InterfazDestino::ingresarLugarOrigen();
							string destino = InterfazDestino::ingresarLugarDestino();
							listaDestinos->agregarElemento(new Destino(origen, destino, new Fecha(dia, mes, anio), new Fecha(dia1, mes1, anio1)));
						}
						else if (opcionMenuEspecifica == 2) //Mostrar Destinos
							InterfazDestino::mostrarTodosDestinos(aerolinea);
						else if (opcionMenuEspecifica == 3) //Actualizar Destinos
							cout << "Actualizar\n";
						else if (opcionMenuEspecifica == 4)
						{
							int seleccionDestino = InterfazDestino::seleccionarDestino(aerolinea, "destino", "eliminar");
							if (listaDestinos->eliminarElemento(seleccionDestino))
								cout << "Eliminacion exitosa\n";
							else
								cout << "Eliminacion fracasada\n";
						}
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

	listaDestinos->guardarTodos(archivoDestinos);
	archivoDestinos.close();

	delete aerolinea;

	system("pause");
	return 0;
}