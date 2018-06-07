#pragma once
#include<string>
#include<sstream>
#include<fstream>
using namespace std;

class Motor
{
private:
	string tipo;
	string codigo;
	int cantidad;
public:
	Motor();
	Motor(string _tipo, string _codigo, int _cantidad);
	~Motor();
	Motor(const Motor& m);
	Motor& operator=(const Motor& m);
	string mostrarMotor();
	friend ofstream& operator<<(ofstream& archivo, Motor& m);
	friend ifstream& operator>>(ifstream& archivo, Motor& m);
};