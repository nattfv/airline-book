#include"InterfazDestino.h"
#include"InterfazPiloto.h"
#include"InterfazAvion.h"
#include"Aerolinea.h"
#include<exception>
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
	Lista<Piloto>* listaPilotos = aerolinea->obtenerPilotos();
	Lista<Avion>* listaAviones = aerolinea->obtenerAviones();

	//Recuperar Archivos

	ifstream flujoEntradaDestinos;
	flujoEntradaDestinos.open("../destinos.txt", ios::in);
	listaDestinos->recuperarTodos(flujoEntradaDestinos);
	flujoEntradaDestinos.close();
	ifstream flujoEntradaPilotos;
	flujoEntradaPilotos.open("../pilotos.txt", ios::in);
	listaPilotos->recuperarTodos(flujoEntradaPilotos);
	flujoEntradaPilotos.close();
	ifstream flujoEntradaAviones;
	flujoEntradaAviones.open("../aviones.txt", ios::in);
	listaAviones->recuperarTodos(flujoEntradaAviones);
	flujoEntradaAviones.close();

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
							/*
								Esta parte necesita una excepcion, porque la fecha
								de partida tiene que ser menos a la fecha de regreso
							*/
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
						else if (opcionMenuEspecifica == 4) //Eliminar Destinos
						{
							int seleccionDestino = InterfazDestino::seleccionarDestino(aerolinea, "destino", "eliminar");
							if (listaDestinos->eliminarElemento(seleccionDestino))
								Interfaz::eliminacionExitosa();
							else
								Interfaz::eliminacionFracasada();
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
						if (opcionMenuEspecifica == 1) //Agregar Pilotos
						{
							InterfazPiloto::encabezadoPiloto();
							string nombre = Interfaz::ingresarDatoCadena("el nombre", "piloto");
							string primerApellido = Interfaz::ingresarDatoCadena("el primer apellido", "piloto");
							string segundoApellido = Interfaz::ingresarDatoCadena("el segundo apellido", "piloto");
							string identificacion = Interfaz::ingresarDatoCadena("la identificacion", "piloto");
							listaPilotos->agregarElemento(new Piloto(nombre, primerApellido, segundoApellido, identificacion));
						}
						else if (opcionMenuEspecifica == 2) //Mostrar Pilotos
							InterfazPiloto::mostrarTodosPilotos(aerolinea);
						else if (opcionMenuEspecifica == 3) //Actualizar Pilotos
							cout << "Actualizar\n";
						else if (opcionMenuEspecifica == 4) //Eliminar Pilotos
						{
							int seleccionPiloto = InterfazPiloto::seleccionarPiloto(aerolinea, "piloto", "eliminar");
							if (listaPilotos->eliminarElemento(seleccionPiloto))
								Interfaz::eliminacionExitosa();
							else
								Interfaz::eliminacionFracasada();
						}
						else if (opcionMenuEspecifica == 5)
							menuEspecifica = true;
					}//FIN WHILE
					menuEspecifica = false;
					break;
				case 3: //Aviones
					while (!menuEspecifica)
					{
						opcionMenuEspecifica = Interfaz::menuAdministracionDe("aviones");
						if (opcionMenuEspecifica == 1) //Agreagar pilotos
						{
							string codigo, transporte, tamanio;
							double pesoCarga = 0.0;
							InterfazAvion::encabezadoAvion();
							codigo = Interfaz::ingresarDatoCadena("el codigo", "avion");
							if (InterfazAvion::menuTransporteAvion() == 1) //pasajeros
							{
								transporte = "pasajeros";
								if (InterfazAvion::menuAsientosAvion() == 1)
									tamanio = "pequenio";
								else
									tamanio = "grande";
							}
							else //carga
							{
								transporte = "carga";
								if ((pesoCarga = InterfazAvion::ingresarPesoAvion()) < 95000)
									tamanio = "pequenio";
								else
									tamanio = "grande";
							}
							listaAviones->agregarElemento(new Avion(codigo, transporte, tamanio, pesoCarga));
						}
						else if (opcionMenuEspecifica == 2) //Mostrar aviones
							InterfazAvion::mostrarTodosAviones(aerolinea);
						else if (opcionMenuEspecifica == 3) //Actualizar aviones
							cout << "Actualizar\n";
						else if (opcionMenuEspecifica == 4) //Eliminar aviones
						{
							int seleccionAvion = InterfazAvion::seleccionarAvion(aerolinea, "avion", "eliminar");
							if (listaAviones->eliminarElemento(seleccionAvion))
								Interfaz::eliminacionExitosa();
							else
								Interfaz::eliminacionFracasada();
						}
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

	//Guardar Archivos
	ofstream flujoSalidaDestinos("../destinos.txt", ios::out);
	ofstream flujoSalidaPilotos("../pilotos.txt", ios::out);
	ofstream flujoSalidaAviones("../aviones.txt", ios::out);
	listaDestinos->guardarTodos(flujoSalidaDestinos);
	listaPilotos->guardarTodos(flujoSalidaPilotos);
	listaAviones->guardarTodos(flujoSalidaAviones);
	flujoSalidaDestinos.close();
	flujoSalidaPilotos.close();
	flujoSalidaAviones.close();

	delete aerolinea;

	system("pause");
	return 0;
}