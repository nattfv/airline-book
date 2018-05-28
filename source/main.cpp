#include"InterfazDestino.h"
#include"InterfazPiloto.h"
#include"InterfazAvion.h"
#include"InterfazVendedor.h"
#include"InterfazVuelo.h"
#include"InterfazReservacion.h"
#include"Aerolinea.h"
#include"ExcepcionExistencia.h"
#include<exception>
using namespace std;

int main()
{
	//Control para el menu
	bool menuPrincipal = false;
	bool menuAdministracion = false;
	bool menuEspecifica = false;
	bool menuReservacion = false;

	//Control para la opcion a elegir
	int opcionMenuPrincipal = 0;
	int opcionMenuAdministracion = 0;
	int opcionMenuEspecifica = 0;
	int opcionMenuReservacion = 0;

	//Aerolinea
	Aerolinea* aerolinea = new Aerolinea();
	Lista<Destino>* listaDestinos = aerolinea->obtenerDestinos();
	Lista<Piloto>* listaPilotos = aerolinea->obtenerPilotos();
	Lista<Avion>* listaAviones = aerolinea->obtenerAviones();
	Lista<Vendedor>* listaVendedores = aerolinea->obtenerVendedores();
	Lista<Vuelo>* listaVuelos = aerolinea->obtenerVuelos();

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
	ifstream flujoEntradaVendedores;
	flujoEntradaVendedores.open("../vendedores.txt", ios::in);
	listaVendedores->recuperarTodos(flujoEntradaVendedores);
	flujoEntradaVendedores.close();
	ifstream flujoEntradaVuelos;
	flujoEntradaVuelos.open("../vuelos.txt", ios::in);
	listaVuelos->recuperarTodos(flujoEntradaVuelos);
	flujoEntradaVuelos.close();

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
							try
							{
								int seleccionDestino = InterfazDestino::seleccionarDestino(aerolinea, "destino", "eliminar");
								if (listaDestinos->eliminarElemento(seleccionDestino))
									Interfaz::eliminacionExitosa();
							}
							catch (ExcepcionExistencia& e)
							{
								Interfaz::mostrarError(e.notificarError());
							}
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
							try
							{
								int seleccionPiloto = InterfazPiloto::seleccionarPiloto(aerolinea, "piloto", "eliminar");
								if (listaPilotos->eliminarElemento(seleccionPiloto))
									Interfaz::eliminacionExitosa();
							}
							catch (ExcepcionExistencia & e)
							{
								Interfaz::mostrarError(e.notificarError());
							}
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
							/*
								Se podria implementar un patron para evitar
								tanto control de flujo
							*/
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
							try
							{
								int seleccionAvion = InterfazAvion::seleccionarAvion(aerolinea, "avion", "eliminar");
								if (listaAviones->eliminarElemento(seleccionAvion))
									Interfaz::eliminacionExitosa();
							}
							catch (ExcepcionExistencia & e)
							{
								Interfaz::mostrarError(e.notificarError());
							}
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
						if (opcionMenuEspecifica == 1) //Agregar vuelos
						{
							try
							{
								int seleccionAvion = InterfazAvion::seleccionarAvion(aerolinea, "avion", "asignar");
								int seleccionPiloto = InterfazPiloto::seleccionarPiloto(aerolinea, "piloto", "asignar");
								int seleccionDestino = InterfazDestino::seleccionarDestino(aerolinea, "destino", "asignar");
								string identificacion = Interfaz::ingresarDatoCadena("la identificacion", "vuelo");
								Avion* avion = &listaAviones->devolverElemento(seleccionAvion);
								Piloto* piloto = &listaPilotos->devolverElemento(seleccionPiloto);
								Destino* destino = &listaDestinos->devolverElemento(seleccionDestino);
								Vuelo* vuelo = new Vuelo(identificacion, avion, destino, piloto);
								vuelo->prepararAvion();
								listaVuelos->agregarElemento(vuelo);
							}
							catch (ExcepcionExistencia& e)
							{
								Interfaz::mostrarError(e.notificarError());
							}
						}
						else if (opcionMenuEspecifica == 2)
							InterfazVuelo::mostrarTodosVuelos(aerolinea);
						else if (opcionMenuEspecifica == 3)
							cout << "Actualizar\n";
						else if (opcionMenuEspecifica == 4)
						{
							try
							{
								int seleccionVuelo = InterfazVuelo::seleccionarVuelo(aerolinea, "vuelo", "eliminar");
								if (listaVuelos->eliminarElemento(seleccionVuelo))
									Interfaz::eliminacionExitosa();
							}
							catch (ExcepcionExistencia & e)
							{
								Interfaz::mostrarError(e.notificarError());
							}
						}
						else if (opcionMenuEspecifica == 5)
							menuEspecifica = true;
					}//FIN WHILE
					menuEspecifica = false;
					break;
				case 5: //Vendedores
					while (!menuEspecifica)
					{
						opcionMenuEspecifica = Interfaz::menuAdministracionDe("vendedores");
						if (opcionMenuEspecifica == 1) //Agregar Vendedores
						{
							InterfazVendedor::encabezadoVendedor();
							string nombre = Interfaz::ingresarDatoCadena("el nombre", "vendedor");
							string primerApellido = Interfaz::ingresarDatoCadena("el primer apellido", "vendedor");
							string segundoApellido = Interfaz::ingresarDatoCadena("el segundo apellido", "vendedor");
							string identificacion = Interfaz::ingresarDatoCadena("la identificacion", "vendedor");
							listaVendedores->agregarElemento(new Vendedor(nombre, primerApellido, segundoApellido, identificacion));
						}
						else if (opcionMenuEspecifica == 2) //Mostrar Vendedores
							InterfazVendedor::mostrarTodosVendedores(aerolinea);
						else if (opcionMenuEspecifica == 3) //Actualizar Vendedores
							cout << "Actualizar\n";
						else if (opcionMenuEspecifica == 4) //Eliminar Vendedores
						{
							try
							{
								int seleccionCliente = InterfazVendedor::seleccionarVendedor(aerolinea, "vendedor", "eliminar");
								if (listaVendedores->eliminarElemento(seleccionCliente))
									Interfaz::eliminacionExitosa();
							}
							catch (ExcepcionExistencia & e)
							{
								Interfaz::mostrarError(e.notificarError());
							}
						}
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
			while (!menuReservacion)
			{
				opcionMenuReservacion = Interfaz::menuReservacion();
				if (opcionMenuReservacion == 1)
				{
					try
					{
						int seleccionVuelo = InterfazReservacion::seleccionarVueloPasajeros(aerolinea, "vuelo", "reservar");
						Vuelo* vuelo = &listaVuelos->devolverElemento(seleccionVuelo);
						InterfazReservacion::desplegarAsientos(vuelo);
					}
					catch (ExcepcionExistencia& e)
					{
						Interfaz::mostrarError(e.notificarError());
					}
				}
				else if (opcionMenuReservacion == 2) //Reservaciones por vuelo
					cout << "Reservaciones por vuelo\n";
				else if (opcionMenuReservacion == 3) //Reservaciones por vendedor
					cout << "Reservaciones por vendedor\n";
				else if (opcionMenuReservacion == 4)
					menuReservacion = true;
			}//FIN WHILE
			menuReservacion = false;
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
	ofstream flujoSalidaVendedores("../vendedores.txt", ios::out);
	ofstream flujoSalidaVuelos("../vuelos.txt", ios::out);
	listaDestinos->guardarTodos(flujoSalidaDestinos);
	listaPilotos->guardarTodos(flujoSalidaPilotos);
	listaAviones->guardarTodos(flujoSalidaAviones);
	listaVendedores->guardarTodos(flujoSalidaVendedores);
	listaVuelos->guardarTodos(flujoSalidaVuelos);
	flujoSalidaDestinos.close();
	flujoSalidaPilotos.close();
	flujoSalidaAviones.close();
	flujoSalidaVendedores.close();
	flujoSalidaVuelos.close();

	delete aerolinea;

	system("pause");
	return 0;
}