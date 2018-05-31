#include"InterfazReservacion.h"
#include"ExcepcionExistencia.h"
#include"ExcepcionCadena.h"
#include"Iterador.h"
#include"utiles.h"

void InterfazReservacion::encabezadoReservacion()
{
	system("cls");
	cout << "+------------------------------------------+\n";
	cout << "|" << setw(25) << ">>RESERVACIONES<<" << setw(19) << "|\n";
	cout << "+------------------------------------------+\n";
}


/*
	Perfecto para mostrar todos los vuelos de pasajeros
	sin importar que un vuelo ya se encuentre lleno
*/
void InterfazReservacion::mostrarTodosVuelosPasajeros(Aerolinea * aerolinea)
{
	Lista<Vuelo>* listaVuelos = aerolinea->obtenerVuelos();
	IteradorLista<Vuelo>* iterador = listaVuelos->crearIterador();
	int contador = 0;
	while (iterador->masElementos())
	{
		Vuelo* vuelo = iterador->proximoElemento();
		if (vuelo->esVueloPasajeros()) // y todos los asientos estan libre
		{
			cout << "No. " << ++contador << "\n"
				<< vuelo->mostrarVuelo() << endl;
		}
	}
	delete iterador;
}

/*
	Puedo seleccionar entre todos los vuelos con pasajeros,
	el problema es cuando deseo reservar, no debo mostrar
	los vuelos que se encuentren llenos
*/
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
		if (vuelo->esVueloPasajeros()) // y todos los asientos estan libre
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

/*
	Despliega la matriz para que se puedea ver en orden los
	asientos y su disponiblidad
*/
void InterfazReservacion::desplegarAsientos(Vuelo * vuelo)
{
	Avion* avion = vuelo->obtenerAvion();
	MatrizAsiento* asientos = avion->obtenerPasajeros();
	system("cls");
	cout << "+------------------------------------------+\n";
	cout << "|" << setw(25) << ">>ASIENTOS<<" << setw(19) << "|\n";
	cout << "+------------------------------------------+\n";
	cout << asientos->formarAsientos();
	system("pause");
}

/*
	Seleccionar la fila que desea reservar
*/
int InterfazReservacion::seleccionarFilaPasajeros(Vuelo* vuelo)
{
	Avion* avion = vuelo->obtenerAvion();
	MatrizAsiento* asientos = avion->obtenerPasajeros();
	int maximoFila = asientos->getFila();
	bool correcto = false;
	int valor = 0;
	while (!correcto)
	{
		try
		{
			cout << "Seleccione la fila por su numero: ";
			valor = obtenerValorEntero(1, maximoFila);
			correcto = true;
		}
		catch (ExcepcionEntrada& e)
		{
			cout << e.notificarError();
		}
	}
	return valor;
}

/*
	Seleccionar la columna que desea reservar
*/
int InterfazReservacion::seleccionarColumnaPasajeros(Vuelo * vuelo)
{
	Avion* avion = vuelo->obtenerAvion();
	MatrizAsiento* asientos = avion->obtenerPasajeros();
	int maximoColumna = asientos->getColumna();
	bool correcto = false;
	char dato = ' ';
	int valor = 0;
	while (!correcto)
	{
		try
		{
			cout << "Seleccione la columna por su letra: ";
			dato = obternerValorChar('A', 'F'); //esto deberia hacerlo en ControlAsiento
			valor = dato - 65;
			correcto = true;
		}
		catch (ExcepcionEntrada& e)
		{
			cout << e.notificarError();
		}
	}
	return valor;
}

/*
	Muetras la matriz de asientos y despliega la cantidad
	de asientos reservados y dispoinibles
*/
void InterfazReservacion::mostrarDetallesPasajeros(Vuelo * vuelo)
{
	Avion* avion = vuelo->obtenerAvion();
	MatrizAsiento* asientos = avion->obtenerPasajeros();
	int cantidadCamposReservados = asientos->cantidadAsientosVendidos();
	int cantidadCamposDisponibles = asientos->cantidadAsientosDisponibles();
	desplegarAsientos(vuelo);
	cout << "Campos reservados: " << cantidadCamposReservados << "\n";
	cout << "Campos disponibles: " << cantidadCamposDisponibles << "\n";
	system("pause");
}

/*
	Muestra la informacion de las reservaciones hechas
	por un vendedor especifico, si no tiene muestra
	que no ha hecho ninguna
*/
void InterfazReservacion::mostrarReservasVendedor(Aerolinea * aerolinea, Vendedor* vendedor)
{
	encabezadoReservacion();
	Lista<Reservacion>* reservaciones = aerolinea->obtenerReservaciones();
	IteradorLista<Reservacion>* iterador = reservaciones->crearIterador();
	bool existe = false;
	while (iterador->masElementos())
	{
		Reservacion* reserva = iterador->proximoElemento();
		if (reserva->compararVendedor(vendedor))
		{
			cout << reserva->mostrarReservacion();
			cout << "<----------------------------------------->\n";
			existe = true;
		}
	}
	if (!existe)
	{
		cout << vendedor->mostrarVendedor() <<
			"\nNo ha realizado reservaciones\n";
 	}
	system("pause");
}

string InterfazReservacion::reservaExitosa()
{
	system("cls");
	cout << "+-----------------------------------------------+\n";
	cout << "|" << setw(34) << ">>RESERVA EXITOSA<<" << setw(15) << "|\n";
	cout << "+-----------------------------------------------+\n";
	system("pause");
	return continuarReservando();
}

string InterfazReservacion::asientoReservado()
{
	system("cls");
	cout << "+-----------------------------------------------+\n";
	cout << "|" << setw(34) << ">>ASIENTO OCUPADO<<" << setw(15) << "|\n";
	cout << "+-----------------------------------------------+\n";
	system("pause");
	return continuarReservando();
}

void InterfazReservacion::limiteReservaciones()
{
	system("cls");
	cout << "Solamente puede reservar 10 asientos\n";
	system("pause");
}

string InterfazReservacion::continuarReservando()
{
	string opcion;
	bool correcto = false;
	while (!correcto)
	{
		try
		{
			cout << "Desea continuar[Y/n] ";
			getline(cin, opcion);
			if (opcion != "Y")
				if(opcion != "n")
					throw ExcepcionCadena("Y o n");
			correcto = true;
		}
		catch (ExcepcionEntrada& e)
		{
			cout << e.notificarError();
		}
	}
	return opcion;
}

void InterfazReservacion::encabezadoCliente()
{
	system("cls");
	cout << "+-----------------------------------------------+\n";
	cout << "|" << setw(34) << ">>CLIENTE<<" << setw(15) << "|\n";
	cout << "+-----------------------------------------------+\n";
	system("pause");
}
