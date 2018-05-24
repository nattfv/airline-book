#include "ControlAsiento.h"

ControlAsiento::ControlAsiento(int _tamanio)
{
	tamanio = _tamanio;
	letrasAsiento = new char[tamanio];
	//inicializar vector
	/*
		Si el tamanio es de 4, genera un vector = {A,B,C,D}
		Si el tamanio es de n, genera un vector = {A,B,C,D,...}
	*/
	char letra = 'A';
	for (int i = 0; i < tamanio; i++) 
		letrasAsiento[i] = letra++;
}

ControlAsiento::~ControlAsiento()
{
	delete[] letrasAsiento;
}

void ControlAsiento::darFormatoAsiento(Asiento & _a, int _columna, int _fila)
{
	//Modifico la letra que le corresponde segun la columna;
	/*
		_columna(0) -> letrasAsiento[0] = A
		_columna(1) -> letrasAsiento[1] = B
		...
	*/
	_a.setLetra(letrasAsiento[_columna]);
	//Modifica el numero segun la fila
	/*
		_fila(0)  -> _fila + 1 = 1
		_fila(1)  -> _fila + 1 = 2
	*/
	_a.setNumero(_fila + 1);
}
