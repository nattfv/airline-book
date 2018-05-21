#include"Asiento.h"

Asiento::Asiento() {
	numero = 0;
	letra = ' ';
	ocupado = false;
}
Asiento::Asiento(int _numero, char _letra, bool _ocupado) : 
	numero(_numero), letra(_letra), ocupado(_ocupado)
{
}
Asiento::~Asiento() {}

int Asiento::getNumero() {
	return numero;
}
char Asiento::getLetra() {
	return letra;
}
bool Asiento::getOcupado() {
	return ocupado;
}
void Asiento::setNumero(int _numero) {
	numero = _numero;
}
void Asiento::setLetra(char _letra) {
	letra = _letra;
}
void Asiento::setOcupado(bool _ocupado) {
	ocupado = _ocupado;
}

string Asiento::toString() {
	stringstream s;
	s << "Asiento: " << letra << numero;
	return s.str();
}