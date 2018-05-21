#pragma once
#include<sstream>
using namespace std;

class Asiento {
private:
	int numero; //fila
	char letra; //columna
	bool ocupado;
public:
	Asiento();
	Asiento(int _numero, char _letra, bool _ocupado = false);
	~Asiento();
	int getNumero();
	char getLetra();
	bool getOcupado();
	void setNumero(int _numero);
	void setLetra(char _letra);
	void setOcupado(bool _ocupado);
	string toString();
};