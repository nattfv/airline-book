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
using namespace std;

int main()
{
	//-------------------------------------------------------------------------------------------------
	//Prueba de Fecha
	Fecha* fecha1 = new Fecha();
	cout << fecha1->mostrarFormatoFecha() << endl;
	Fecha* fecha2 = new Fecha(20, 6, 2018);
	cout << fecha2->mostrarFormatoFecha() << endl;
	Fecha* fecha3 = new Fecha(*fecha2);
	cout << fecha3->mostrarFormatoFecha() << endl;
	*fecha3 = *fecha1;
	cout << fecha3->mostrarFormatoFecha() << endl;
	try
	{
		Fecha fecha(12, 45, 2006);
		cout << fecha.mostrarFormatoFecha() << endl;
	}
	catch (int x)
	{
		cout << "Error tipo: " << x << endl;
	}
	//-------------------------------------------------------------------------------------------------
	//Prueba de Destino
	Destino* destino1 = new Destino("Alajuela, Costa Rica", "New Jersey, Estados Unidos", fecha1, fecha2);
	cout << destino1->mostrarDestino();
	Destino* destino2 = new Destino(*destino1);
	cout << destino2->mostrarDestino();
	Destino* destino3 = new Destino("Alajuela, Costa Rica", "Berlin, Alemania", new Fecha(*fecha1), new Fecha(*fecha2));
	cout << destino3->mostrarDestino();
	*destino1 = *destino3;
	cout << destino1->mostrarDestino();
	cout << destino3->mostrarDestino();
	//-------------------------------------------------------------------------------------------------
	//Prueba de Piloto
	Piloto* piloto1 = new Piloto("Andres", "Jimenez", "Elizondo", "P-001");
	cout << piloto1->mostrarPiloto() << endl;
	Piloto* piloto2 = new Piloto("Juan", "Mora", "Elizondo", "P-002");
	cout << piloto2->mostrarPiloto() << endl;
	//-------------------------------------------------------------------------------------------------
	//Prueba de Vendedor
	Vendedor* vendedor1 = new Vendedor("Paulo", "Barrantes", "Aguilar", "V-001");
	cout << vendedor1->mostrarVendedor() << endl;
	//-------------------------------------------------------------------------------------------------
	//Prueba de Cliente
	Cliente* cliente1 = new Cliente("Andres", "Jimenez", "Elizondo", "116930775");
	cout << cliente1->mostrarCliente() << endl;
	//-------------------------------------------------------------------------------------------------
	//Prueba de MatrizAsiento
	MatrizAsiento* MAP1 = new MatrizAsiento(12, 4);
	MAP1->darFormatoTodosAsientos();
	cout << MAP1->toString();
	MatrizAsiento* MAP2 = new MatrizAsiento(12, 7);
	MAP2->darFormatoTodosAsientos();
	cout << MAP2->toString();
	//-------------------------------------------------------------------------------------------------
	//Prueba de Avion
	Avion* avion1 = new Avion("AP-001", "pasajero", "pequenio");
	cout << avion1->mostrarAvion();
	avion1->crearAsientos();
	cout << avion1->obtenerPasajeros()->toString();
	Avion* avion2 = new Avion("AC-001", "carga", "grande", 90000);
	cout << avion2->mostrarAvion();
	//-------------------------------------------------------------------------------------------------
	//Prueba de vuelo
	Vuelo* vuelo1 = new Vuelo("V-001", avion1, destino3, piloto1);
	vuelo1->prepararAvion();
	cout << vuelo1->mostrarVuelo();
	Vuelo* vuelo2 = new Vuelo("V-002", avion2, destino2, piloto1);
	vuelo2->prepararAvion();
	cout << vuelo2->mostrarVuelo();
	//-------------------------------------------------------------------------------------------------
	//Prueba de Reservacion
	Reservacion* reserva1 = new Reservacion(vuelo1, vendedor1, new Cliente(*cliente1));
	if (vuelo1->estaDisponibleAsiento(0, 0)) //Primera reserva
	{
		if (reserva1->puedoReservar(0, 0))
			cout << "Reservacion Exitosa\n";
		else
			cout << "Ha excedido su limite de reservas\n";
	}
	else
		cout << "Este asiento ya se encuentra ocupado\n";
	if (vuelo1->estaDisponibleAsiento(0, 1)) //Segunda reserva
	{
		if (reserva1->puedoReservar(0, 1))
			cout << "Reservacion Exitosa\n";
		else
			cout << "Ha excedido su limite de reservas\n";
	}
	else
		cout << "Este asiento ya se encuentra ocupado\n";
	Reservacion* reserva2 = new Reservacion(vuelo1, vendedor1, new Cliente(*cliente1));
	if (vuelo1->estaDisponibleAsiento(0, 0)) //Tercera reserva, pero repetida
	{
		if (reserva2->puedoReservar(0, 0))
			cout << "Reservacion Exitosa\n";
		else
			cout << "Ha excedido su limite de reservas\n";
	}
	else
		cout << "Este asiento ya se encuentra ocupado\n";
	cout << reserva1->mostrarReservacion();
	cout << reserva2->mostrarReservacion();
	//-------------------------------------------------------------------------------------------------
	//Prueba de Plantillas
	Lista<Destino>* listaDestinos = new Lista<Destino>();
	listaDestinos->agregarElemento(destino1);
	listaDestinos->agregarElemento(destino2);
	listaDestinos->agregarElemento(destino3);
	cout << listaDestinos->toString();
	Lista<Piloto>* listaPilotos = new Lista<Piloto>();
	listaPilotos->agregarElemento(piloto1);
	listaPilotos->agregarElemento(piloto2);
	cout << listaPilotos->toString();
	Lista<Avion>* listaAviones = new Lista<Avion>();
	listaAviones->agregarElemento(avion1);
	listaAviones->agregarElemento(avion2);
	cout << listaAviones->toString();
	Lista<Vuelo>* listaVuelos = new Lista<Vuelo>();
	listaVuelos->agregarElemento(vuelo1);
	listaVuelos->agregarElemento(vuelo2);
	cout << listaVuelos->toString();
	Lista<Cliente>* listaCliente = new Lista<Cliente>();
	listaCliente->agregarElemento(cliente1);
	cout << listaCliente->toString();
	Lista<Vendedor>* listaVendedor = new Lista<Vendedor>();
	listaVendedor->agregarElemento(vendedor1);
	cout << listaVendedor->toString();
	Lista<Reservacion>* listaReservacion = new Lista<Reservacion>();
	listaReservacion->agregarElemento(reserva1);
	listaReservacion->agregarElemento(reserva2);
	cout << listaReservacion->toString();
	//-------------------------------------------------------------------------------------------------
	//Eliminacion
	delete listaPilotos;
	delete listaDestinos;
	delete listaAviones;
	delete listaVuelos;
	delete listaCliente;
	delete listaVendedor;
	delete listaReservacion;
	delete MAP2;
	delete MAP1;
	system("pause");
	return 0;
}