#pragma once
#include"Nodo.h"
#include<string>
#include<iostream>
using namespace std;

template<class T>
class Lista
{
private:
	Nodo<T>* ppio;
public:
	Lista();
	Lista(Lista<T>& lista);
	~Lista();
	Lista<T> operator=(const Lista<T>&);
	string toString();
	void agregarElemento(T* elemento);
	bool eliminarElemento(int lug);
	bool eliminarPrimero();
	bool eliminarUltimo();
	void eliminarTodos();
	Nodo<T>* getPrimerNodo();
	int cantidadElementos();
	T& devolverElemento(int _posicion);
	void guardarTodos(ofstream& archivo);
	void recuperarTodos(ifstream& archivo);
};

template<class T>
Lista<T>::Lista()
{
	ppio = NULL;
}

template<class T>
Lista<T>::Lista(Lista<T>& lista)
{
	T* elemento = NULL;
	ppio = NULL;
	Nodo<T>* corre = lista.ppio;
	while (corre != NULL)
	{
		elemento = new T(*(corre->getInfo()));
		agregarElemento(elemento);
		corre = corre->getSiguiente();
	}
}

template<class T>
Lista<T>::~Lista()
{
	eliminarTodos();
}

template<class T>
Lista<T> Lista<T>::operator=(const Lista<T>& l)
{
	if (this != &l)
	{
		eliminarTodos();
		Nodo<T>* corre = l.ppio;
		while (corre)
		{
			agregarElemento(new T(*corre->getInfo()));
			corre = corre->getSiguiente();
		}
	}
	return *this;
}

template<class T>
string Lista<T>::toString()
{
	int num = 0;
	stringstream ss;
	Nodo<T>* corre = ppio;
	if (ppio == NULL)
		ss << "No hay elementos\n";
	while (corre)
	{
		ss << "No. " << ++num << "\n" << *(corre->getInfo()) << endl;
		corre = corre->getSiguiente();
	}
	return ss.str();
}

template<class T>
void Lista<T>::agregarElemento(T* elemento)
{
	Nodo<T>* nuevo = new Nodo<T>(NULL, *elemento);
	if (ppio == NULL)
		ppio = new Nodo<T>(ppio, *elemento);
	else
	{
		Nodo<T>* actual = NULL;
		actual = ppio;
		while (actual->getSiguiente() != NULL)
			actual = actual->getSiguiente();
		actual->setSiguiente(nuevo);
	}
}

template<class T>
bool Lista<T>::eliminarElemento(int lug)
{
	if (lug == 0 || cantidadElementos() < lug)
		return false;
	else if (lug == 1)
		return eliminarPrimero();
	else if (lug == cantidadElementos())
		return eliminarUltimo();
	else
	{
		int contador = 0;
		Nodo<T>* muere = ppio;
		Nodo<T>* anterior = ppio;
		while (contador + 1 != lug)
		{
			anterior = muere;
			muere = muere->getSiguiente();
			contador++;
		}
		anterior->setSiguiente(muere->getSiguiente());
		delete muere;
		return true;
	}
}

template<class T>
bool Lista<T>::eliminarPrimero()
{
	if (ppio != NULL)
	{
		Nodo<T>* muere = ppio;
		ppio = muere->getSiguiente();
		delete muere;
		return true;
	}
	return false;
}

template<class T>
bool Lista<T>::eliminarUltimo()
{
	if (ppio != NULL)
	{
		Nodo<T>* corre = ppio;
		while (corre->getSiguiente()->getSiguiente() != NULL) //me fijo en el 4 dedo
			corre = corre->getSiguiente();
		delete corre->getSiguiente();
		corre->setSiguiente(NULL);
		return true;
	}
	else
		return false;
}

template<class T>
void Lista<T>::eliminarTodos()
{
	while (eliminarPrimero());
}

template<class T>
Nodo<T>* Lista<T>::getPrimerNodo() { return ppio; }

template<class T>
int Lista<T>::cantidadElementos()
{
	int contador = 0;
	Nodo<T>* corre = ppio;
	while (corre)
	{
		contador++;
		corre = corre->getSiguiente();
	}
	return contador;
}

template<class T>
T & Lista<T>::devolverElemento(int _posicion)
{
	int posicionInicio = 1;
	Nodo<T>* corre = ppio;
	while (posicionInicio < _posicion)
	{
		posicionInicio++;
		corre = corre->getSiguiente();
	}
	return *corre->getInfo();
}

template<class T>
void Lista<T>::guardarTodos(ofstream & archivo)
{
	Nodo<T>* corre = ppio;
	while (corre)
	{
		archivo << *corre->getInfo();
		corre = corre->getSiguiente();
	}
}

template<class T>
void Lista<T>::recuperarTodos(ifstream & archivo)
{
	T elementoEstatico;
	archivo >> elementoEstatico;
	while (!archivo.eof())
	{
		T* elementoDinamico = new T();
		*elementoDinamico = elementoEstatico;
		agregarElemento(elementoDinamico);
		archivo >> elementoEstatico;
	}
}
