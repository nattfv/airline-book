#include "ExcepcionExistencia.h"

ExcepcionExistencia::ExcepcionExistencia(string _clase, string _accion) :
	clase(_clase), accion(_accion)
{
}

ExcepcionExistencia::~ExcepcionExistencia()
{
}

string ExcepcionExistencia::notificarError()
{
	return "No existen " + clase + " para " + accion;
}