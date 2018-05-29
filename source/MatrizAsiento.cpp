#include "MatrizAsiento.h"

MatrizAsiento::MatrizAsiento(int _fila, int _columna) :
	fila(_fila), columna(_columna)
{
	matriz = new Asiento**[fila]; //Columna inicial
	for (int i = 0; i < fila; i++)
		matriz[i] = new Asiento*[columna]; //En cada fila, hay un vector que representa las columnas
	for (int i = 0; i < fila; i++)
		for (int j = 0; j < columna; j++)
			matriz[i][j] = new Asiento();
}

MatrizAsiento::~MatrizAsiento()
{
	for (int i = 0; i < fila; i++)
		for (int j = 0; j < columna; j++)
			delete matriz[i][j]; //Cada elemento de la matriz
	for (int i = 0; i < fila; i++)
		delete[] matriz[i]; //Elimina cada columna
	delete[] matriz;
}

MatrizAsiento::MatrizAsiento(const MatrizAsiento & _ma)
{
	fila = _ma.fila;
	columna = _ma.columna;

	matriz = new Asiento**[fila];
	for (int i = 0; i < fila; i++)
		matriz[i] = new Asiento*[columna];
	for (int i = 0; i < fila; i++)
		for (int j = 0; j < columna; j++)
			matriz[i][j] = new Asiento(*_ma.matriz[i][j]);
}

MatrizAsiento & MatrizAsiento::operator=(const MatrizAsiento & ma)
{
	if (this != &ma)
	{
		//Elimino todo el contenido
		if (matriz)
		{
			for (int i = 0; i < fila; i++)
				for (int j = 0; j < columna; j++)
					delete matriz[i][j]; //Cada elemento de la matriz
			for (int i = 0; i < fila; i++)
				delete[] matriz[i]; //Elimina cada columna
			delete[] matriz;
		}
		//Creo uno nuevo
		fila = ma.fila;
		columna = ma.columna;
		matriz = new Asiento**[fila];
		for (int i = 0; i < fila; i++)
			matriz[i] = new Asiento*[columna];
		for (int i = 0; i < fila; i++)
			for (int j = 0; j < columna; j++)
				matriz[i][j] = new Asiento(*ma.matriz[i][j]);
	}
	return *this;
}

int MatrizAsiento::getFila()
{
	return fila;
}

int MatrizAsiento::getColumna()
{
	return columna;
}

Asiento * MatrizAsiento::obtenerAsiento(int _fila, int _columna)
{
	return matriz[_fila][_columna];
}

string MatrizAsiento::toString()
{
	stringstream s;
	for (int i = 0; i < fila; i++)
		for (int j = 0; j < columna; j++)
			s << matriz[i][j]->mostrarAsiento() << endl;
	return s.str();
}

void MatrizAsiento::darFormatoTodosAsientos()
{
	ControlAsiento control(columna);
	for (int i = 0; i < fila; i++)
		for (int j = 0; j < columna; j++)
			control.darFormatoAsiento(*matriz[i][j], i, i);
}

int MatrizAsiento::totalAsientos()
{
	return fila*columna;
}

int MatrizAsiento::cantidadAsientosVendidos()
{
	int contador = 0;
	for (int i = 0; i < fila; i++)
		for (int j = 0; j < columna; j++)
			if (!matriz[i][j]->asientoDisponible())
				contador++;
	return contador;
}

int MatrizAsiento::cantidadAsientosDisponibles()
{
	return totalAsientos() - cantidadAsientosVendidos();
}

void MatrizAsiento::cambiarDisponiblidadAsiento(int _fila, int _columna, bool _disponible)
{
	matriz[_fila][_columna]->cambiarDisponiblidad(_disponible);
}

bool MatrizAsiento::disponibilidadAsiento(int fila, int columna)
{
	return matriz[fila][columna]->asientoDisponible();
}

string MatrizAsiento::formarAsientos()
{
	ControlAsiento control(columna);
	stringstream s;
	s << "     " <<control.formarHileraLetras() << "\n";
	for (int i = 0; i < fila; i++)
	{
		s <<i + 1 << "  ";
		for (int j = 0; j < columna; j++)
		{
			s << "[ "
				<< ((disponibilidadAsiento(i, j) ? "D" : "X"))
				<< " ]"
				<< (((j + 1) % 3 == 0 && j != 0) ? "  " : ""); //mitad de las columnas
		}
		s << i + 1 << "\n";
	}
	return s.str();
}

//guarda solamente los que no estan disponibles
ofstream & operator<<(ofstream & archivo, MatrizAsiento & ma) 
{
	archivo << ma.fila << "\t";
	archivo << ma.columna << "\t";
	archivo << ma.cantidadAsientosVendidos() << "\n";
	for(int i = 0; i < ma.fila; i++)
		for(int j = 0; j < ma.columna; j++)
			if (!ma.matriz[i][j]->asientoDisponible())
			{
				archivo << i << "\t"
					<< j << "\n";
			}
	return archivo;
}
