#pragma once
#include"InterfazDestino.h"
#include"InterfazPiloto.h"
#include"InterfazAvion.h"
#include"InterfazVendedor.h"
#include"InterfazVuelo.h"
#include"InterfazReservacion.h"
#include"ExcepcionExistencia.h"
#include"InterfazMotor.h"
#include"ExcepcionFecha.h"

class Controlador
{
private:
	Aerolinea* aerolinea;
public:
	Controlador();
	~Controlador();
	void controlPrincipal();
	bool controlSecundario();
	bool controlAdministracion();
	bool controlDestinos();
	bool controlPilotos();
	bool controlAviones();
	bool controlVuelos();
	bool controlVendedores();
	bool controlReservacion();
	void controlFlujoEntrada();
	void controlFlujoSalida();
};
