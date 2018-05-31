#pragma once
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

class Hora 
{
private:
	int horas;
	int minutos;
public:
	Hora();
	Hora(int _horas, int _minutos);
	~Hora();
	string mostrarHora();
	friend ostream& operator<<(ostream& out, Hora& h);
	friend ofstream& operator<<(ofstream& archivo, Hora& h);
	friend ifstream& operator>>(ifstream& archivo, Hora& h);
};