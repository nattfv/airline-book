#pragma once
#include<sstream>
using namespace std;

class Asiento {
private:
	int numero; //fila
	char letra; //columna
	bool disponible;
public:
	Asiento();
	Asiento(int _numero, char _letra, bool _disponible = true);
	Asiento(const Asiento& _a);
	~Asiento();
	Asiento& operator=(const Asiento& _a);
	int getNumero();
	char getLetra();
	bool getDisponible();
	void setNumero(int _numero);
	void setLetra(char _letra);
	void setDisponible(bool _disponible);
	string mostrarAsiento();
	friend ostream& operator<<(ostream& out, Asiento& _a);
};