#include "Controlador.h"

Controlador::Controlador()
{
	aerolinea = new Aerolinea();
	controlFlujoEntrada();
	controlPrincipal();
	controlFlujoSalida();
}

Controlador::~Controlador()
{
	delete aerolinea;
}

void Controlador::controlPrincipal()
{
	bool menuPrincipal = false;
	while (!menuPrincipal)
		menuPrincipal = controlSecundario();
}

bool Controlador::controlSecundario()
{
	int opcionMenuPrincipal = Interfaz::menuPrincipal();
	bool menuPrincipal = false;
	bool menuAdministracion = false;
	bool menuReservacion = false;
	switch (opcionMenuPrincipal)
	{
	case 1: //Administracion
		while (!menuAdministracion)
			menuAdministracion = controlAdministracion();
		break;
	case 2: //Reservacion
		while (!menuReservacion)
			menuReservacion = controlReservacion();
		break;
	case 3: //Salir
		menuPrincipal = true;
		break;
	} //FIN SWITCH
	return menuPrincipal;
}

bool Controlador::controlAdministracion()
{
	bool menuAdministracion = false;
	bool menuDestinos = false;
	bool menuPilotos = false;
	bool menuAviones = false;
	bool menuVuelos = false;
	bool menuVendedores = false;
	int opcionMenuAdministracion = Interfaz::menuAdministracion();
	switch (opcionMenuAdministracion)
	{
	case 1: //Destinos
		while (!menuDestinos)
			menuDestinos = controlDestinos();
		break;
	case 2: //Pilotos
		while (!menuPilotos)
			menuPilotos = controlPilotos();
		break;
	case 3: //Aviones
		while (!menuAviones)
			menuAviones = controlAviones();
		break;
	case 5: //Vuelos
		while (!menuVuelos)
			menuVuelos = controlVuelos();
		break;
	case 4: //Vendedores
		while (!menuVendedores)
			menuVendedores = controlVendedores();
		break;
	case 6:
		menuAdministracion = true;
		break;
	}//FIN SWITCH
	return menuAdministracion;
}

bool Controlador::controlDestinos()
{
	Lista<Destino>* listaDestinos = aerolinea->obtenerDestinos();
	int opcionMenuEspecifica = Interfaz::menuAdministracionDe("destinos");
	bool menuEspecifica = false;
	if (opcionMenuEspecifica == 1) //Agregar Destinos
	{
		/*
		Esta parte necesita una excepcion, porque la fecha
		de partida tiene que ser menos a la fecha de regreso
		*/
		try
		{
			InterfazDestino::encabezadoFechaPartida();
			int dia = InterfazDestino::ingresarDia();
			int mes = InterfazDestino::ingresarMes();
			int anio = InterfazDestino::ingresarAnio();
			Fecha fechaPartida(dia, mes, anio);
			InterfazDestino::encabezadoFechaRegreso();
			int dia1 = InterfazDestino::ingresarDia();
			int mes1 = InterfazDestino::ingresarMes();
			int anio1 = InterfazDestino::ingresarAnio();
			Fecha fechaRegreso(dia1, mes1, anio1);
			InterfazDestino::encabezadoDestino();
			string origen = InterfazDestino::ingresarLugarOrigen();
			string destino = InterfazDestino::ingresarLugarDestino();
			listaDestinos->agregarElemento(new Destino(origen, destino, new Fecha(fechaPartida), new Fecha(fechaRegreso)));
		}
		catch (ExcepcionFecha & e)
		{
			Interfaz::mostrarError(e.notificarError());
		}
	}
	else if (opcionMenuEspecifica == 2) //Mostrar Destinos
		InterfazDestino::mostrarTodosDestinos(aerolinea);
	//else if (opcionMenuEspecifica == 3) //Actualizar Destinos
	//	cout << "Actualizar\n";
	else if (opcionMenuEspecifica == 3) //Eliminar Destinos
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
	else if (opcionMenuEspecifica == 4)
		menuEspecifica = true;
	return menuEspecifica;
}

bool Controlador::controlPilotos()
{
	Lista<Piloto>* listaPilotos = aerolinea->obtenerPilotos();
	int opcionMenuEspecifica = Interfaz::menuAdministracionDe("pilotos");
	bool menuEspecifica = false;
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
	//else if (opcionMenuEspecifica == 3) //Actualizar Pilotos
	//	cout << "Actualizar\n";
	else if (opcionMenuEspecifica == 3) //Eliminar Pilotos
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
	else if (opcionMenuEspecifica == 4)
		menuEspecifica = true;
	return menuEspecifica;
}

bool Controlador::controlAviones()
{
	Lista<Avion>* listaAviones = aerolinea->obtenerAviones();
	int opcionMenuEspecifica = Interfaz::menuAdministracionDe("aviones");
	bool menuEspecifica = false;
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
			tamanio = (InterfazAvion::menuAsientosAvion() == 1) ? "pequenio" : "grande";
		}
		else //carga
		{
			transporte = "carga";
			tamanio = ((pesoCarga = InterfazAvion::ingresarPesoAvion()) < 95000) ? "pequenio" : "grande";
		}
		listaAviones->agregarElemento(new Avion(codigo, transporte, tamanio, pesoCarga));
	}
	else if (opcionMenuEspecifica == 2) //Mostrar aviones
		InterfazAvion::mostrarTodosAviones(aerolinea);
	//else if (opcionMenuEspecifica == 3) //Actualizar aviones
	//	cout << "Actualizar\n";
	else if (opcionMenuEspecifica == 3) //Eliminar aviones
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
	else if (opcionMenuEspecifica == 4)
		menuEspecifica = true;
	return menuEspecifica;
}

bool Controlador::controlVuelos()
{
	Lista<Avion>* listaAviones = aerolinea->obtenerAviones();
	Lista<Piloto>* listaPilotos = aerolinea->obtenerPilotos();
	Lista<Destino>* listaDestinos = aerolinea->obtenerDestinos();
	Lista<Vuelo>* listaVuelos = aerolinea->obtenerVuelos();
	int opcionMenuEspecifica = Interfaz::menuAdministracionDe("vuelos");
	bool menuEspecifica = false;
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
			InterfazVuelo::encabezadoHoraSalida();
			int hora1 = InterfazVuelo::ingresarHora();
			int minuto1 = InterfazVuelo::ingresarMinuto();
			InterfazVuelo::encabezadoHoraLlegada();
			int hora2 = InterfazVuelo::ingresarHora();
			int minuto2 = InterfazVuelo::ingresarMinuto();
			Vuelo* vuelo = new Vuelo(identificacion, avion, destino, piloto, new Hora(hora1, minuto1), new Hora(hora2, minuto2));
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
	//else if (opcionMenuEspecifica == 3)
	//	cout << "Actualizar\n";
	else if (opcionMenuEspecifica == 3)
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
	else if (opcionMenuEspecifica == 4)
		menuEspecifica = true;
	return menuEspecifica;
}

bool Controlador::controlVendedores()
{
	Lista<Vendedor>* listaVendedores = aerolinea->obtenerVendedores();
	int opcionMenuEspecifica = Interfaz::menuAdministracionDe("vendedores");
	bool menuEspecifica = false;
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
	//else if (opcionMenuEspecifica == 3) //Actualizar Vendedores
	//	cout << "Actualizar\n";
	else if (opcionMenuEspecifica == 3) //Eliminar Vendedores
	{
		try
		{
			int seleccionVendedor = InterfazVendedor::seleccionarVendedor(aerolinea, "vendedor", "eliminar");
			if (listaVendedores->eliminarElemento(seleccionVendedor))
				Interfaz::eliminacionExitosa();
		}
		catch (ExcepcionExistencia & e)
		{
			Interfaz::mostrarError(e.notificarError());
		}
	}
	else if (opcionMenuEspecifica == 4)
		menuEspecifica = true;
	return menuEspecifica;
}

bool Controlador::controlReservacion()
{
	Lista<Vendedor>* listaVendedores = aerolinea->obtenerVendedores();
	Lista<Vuelo>* listaVuelos = aerolinea->obtenerVuelos();
	Lista<Reservacion>* listaReservaciones = aerolinea->obtenerReservaciones();
	bool menuReservacion = false;
	int opcionMenuReservacion = Interfaz::menuReservacion();
	if (opcionMenuReservacion == 1)
	{
		try
		{
			Reservacion* reserva = NULL;
			int seleccionVuelo = InterfazReservacion::seleccionarVueloPasajeros(aerolinea, "vuelo", "reservar");
			Vuelo* vuelo = &listaVuelos->devolverElemento(seleccionVuelo);
			int seleccionVendedor = InterfazVendedor::seleccionarVendedorReservacion(aerolinea);
			Vendedor* vendedor = &listaVendedores->devolverElemento(seleccionVendedor);
			string nombre = Interfaz::ingresarDatoCadena("el nombre", "cliente");
			//aqui seria bonito un encabezado
			string apellido1 = Interfaz::ingresarDatoCadena("el primer apellido", "cliente");
			string apellido2 = Interfaz::ingresarDatoCadena("el segundo apellido", "cliente");
			string identificacion = Interfaz::ingresarDatoCadena("la identificacion", "cliente");
			Cliente* cliente = new Cliente(nombre, apellido1, apellido2, identificacion);
			bool proseguir = true;
			while (proseguir)
			{
				InterfazReservacion::desplegarAsientos(vuelo);
				int seleccionFila = InterfazReservacion::seleccionarFilaPasajeros(vuelo);
				int seleccionColumna = InterfazReservacion::seleccionarColumnaPasajeros(vuelo);
				if (vuelo->estaDisponibleAsiento(seleccionFila - 1, seleccionColumna))
				{
					if (!reserva)
					{
						reserva = new Reservacion(vuelo, vendedor, cliente);
						listaReservaciones->agregarElemento(reserva); //guardando en la lista la reservacion
					}

					if (reserva->puedoReservar(seleccionFila - 1, seleccionColumna, vuelo))
						proseguir = (InterfazReservacion::reservaExitosa() == "n") ? false : true;
					else
					{
						InterfazReservacion::limiteReservaciones();
						proseguir = false;
					}
				}
				else
				{
					proseguir = (InterfazReservacion::asientoReservado() == "n") ? false : true;
				}
			}
		}
		catch (ExcepcionExistencia& e)
		{
			Interfaz::mostrarError(e.notificarError());
		}
	}
	else if (opcionMenuReservacion == 2) //Reservaciones por vuelo
	{
		try
		{
			int seleccionVuelo = InterfazReservacion::seleccionarVueloPasajeros(aerolinea, "vuelo", "revisar");
			Vuelo* vuelo = &listaVuelos->devolverElemento(seleccionVuelo);
			//InterfazReservacion::desplegarAsientos(vuelo);
			InterfazReservacion::mostrarDetallesPasajeros(vuelo);
		}
		catch (ExcepcionExistencia& e)
		{
			Interfaz::mostrarError(e.notificarError());
		}
	}
	else if (opcionMenuReservacion == 3) //Reservaciones por vendedor
	{
		try
		{
			int seleccionVendedor = InterfazVendedor::seleccionarVendedor(aerolinea, "vendedor", "revisar");
			Vendedor* vendedor = &listaVendedores->devolverElemento(seleccionVendedor);
			InterfazReservacion::mostrarReservasVendedor(aerolinea, vendedor);
		}
		catch (ExcepcionExistencia& e)
		{
			Interfaz::mostrarError(e.notificarError());
		}
	}
	else if (opcionMenuReservacion == 4)
		menuReservacion = true;
	return menuReservacion;
}

void Controlador::controlFlujoEntrada()
{
	Lista<Destino>* listaDestinos = aerolinea->obtenerDestinos();
	Lista<Piloto>* listaPilotos = aerolinea->obtenerPilotos();
	Lista<Avion>* listaAviones = aerolinea->obtenerAviones();
	Lista<Vendedor>* listaVendedores = aerolinea->obtenerVendedores();
	Lista<Vuelo>* listaVuelos = aerolinea->obtenerVuelos();
	Lista<Reservacion>* listaReservaciones = aerolinea->obtenerReservaciones();

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
	ifstream flujoEntradaReservaciones;
	flujoEntradaReservaciones.open("../reservaciones.txt", ios::in);
	listaReservaciones->recuperarTodos(flujoEntradaReservaciones);
	flujoEntradaReservaciones.close();
}

void Controlador::controlFlujoSalida()
{
	Lista<Destino>* listaDestinos = aerolinea->obtenerDestinos();
	Lista<Piloto>* listaPilotos = aerolinea->obtenerPilotos();
	Lista<Avion>* listaAviones = aerolinea->obtenerAviones();
	Lista<Vendedor>* listaVendedores = aerolinea->obtenerVendedores();
	Lista<Vuelo>* listaVuelos = aerolinea->obtenerVuelos();
	Lista<Reservacion>* listaReservaciones = aerolinea->obtenerReservaciones();

	ofstream flujoSalidaDestinos("../destinos.txt", ios::out);
	ofstream flujoSalidaPilotos("../pilotos.txt", ios::out);
	ofstream flujoSalidaAviones("../aviones.txt", ios::out);
	ofstream flujoSalidaVendedores("../vendedores.txt", ios::out);
	ofstream flujoSalidaVuelos("../vuelos.txt", ios::out);
	ofstream flujoSalidaReservaciones("../reservaciones.txt", ios::out);

	listaDestinos->guardarTodos(flujoSalidaDestinos);
	listaPilotos->guardarTodos(flujoSalidaPilotos);
	listaAviones->guardarTodos(flujoSalidaAviones);
	listaVendedores->guardarTodos(flujoSalidaVendedores);
	listaVuelos->guardarTodos(flujoSalidaVuelos);
	listaReservaciones->guardarTodos(flujoSalidaReservaciones);

	flujoSalidaDestinos.close();
	flujoSalidaPilotos.close();
	flujoSalidaAviones.close();
	flujoSalidaVendedores.close();
	flujoSalidaVuelos.close();
	flujoSalidaReservaciones.close();
}
