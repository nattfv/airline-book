#pragma once
#include<string>
using namespace std;

class ExcepcionExistencia
{
private:
	string clase;
	string accion;
public:
	ExcepcionExistencia(string _clase, string _accion);
	~ExcepcionExistencia();
	string notificarError();
};