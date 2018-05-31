#pragma once
#include<string>
#include<sstream>
using namespace std;

class ExcepcionFecha
{
private:
	string mensaje;
public:
	ExcepcionFecha(string _mensaje);
	~ExcepcionFecha();
	string notificarError();
};