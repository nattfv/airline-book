#include"Asiento.h"
#include"utiles.h"

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

string Asiento::mostrarAsiento() {
	stringstream s;
	s << "Asiento: " << letra << numero;
	return s.str();
}

bool Asiento::asientoDisponible()
{
	return disponible == true;
}

void Asiento::cambiarDisponiblidad(bool _disponible)
{
	disponible = _disponible;
}

string Asiento::mostrarVentanaPasillo()
{
	string valor = "";
	if (letra == 'A' || letra == 'F')
		valor = "(Ventana)";
	if (letra == 'C' || letra == 'D')
		valor = "(Pasillo)";
	return valor;
}

ostream & operator<<(ostream & out, Asiento & _a)
{
	out << _a.numero << _a.letra;
	return out;
}

ofstream & operator<<(ofstream& archivo, Asiento & a)
{
	archivo << a.numero << "\t"
		<< a.letra << "\n";
	return archivo;
}

ifstream & operator>>(ifstream& archivo, Asiento & a)
{
	int numero;
	char letra;
	string hilera = procesarHilera(archivo);
	stringstream particion(hilera);
	numero = procesarInt(particion, '\t');
	letra = procesarChar(particion, '\n');
	a.numero = numero;
	a.letra = letra;
	a.disponible = false; //se utiliza solamente para leer asientos de la reservacion, por lo que no estan disponibles
	return archivo;
}
