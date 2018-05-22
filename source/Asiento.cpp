#include"Asiento.h"

Asiento::Asiento() {
	numero = 0;
	letra = ' ';
	disponible = true;
}
Asiento::Asiento(int _numero, char _letra, bool _disponible) :
	numero(_numero), letra(_letra), disponible(_disponible)
{
}
Asiento::Asiento(const Asiento & _a)
{
	numero = _a.numero;
	letra = _a.letra;
	disponible = _a.disponible;
}
Asiento::~Asiento() {}

Asiento & Asiento::operator=(const Asiento & _a)
{
	if (this != &_a)
	{
		numero = _a.numero;
		letra = _a.letra;
		disponible = _a.disponible;
	}
	return *this;
}

int Asiento::getNumero() {
	return numero;
}
char Asiento::getLetra() {
	return letra;
}
bool Asiento::getDisponible() {
	return disponible;
}
void Asiento::setNumero(int _numero) {
	numero = _numero;
}
void Asiento::setLetra(char _letra) {
	letra = _letra;
}
void Asiento::setDisponible(bool _disponible) {
	disponible = _disponible;
}

string Asiento::toString() {
	stringstream s;
	s << "Asiento: " << letra << numero;
	return s.str();
}