#pragma once
#include"Nodo.h"
#include<iostream>
using namespace std;

template<class T>
class IteradorLista
{
public:
	IteradorLista(Nodo<T>*);
	bool masElementos();
	T* proximoElemento();
private:
	Nodo<T> * actual;
};

template<class T>
IteradorLista<T>::IteradorLista(Nodo<T>* _actual)
{
	actual = _actual;
}

template<class T>
bool IteradorLista<T>::masElementos()
{
	return actual != NULL;
}

template<class T>
T* IteradorLista<T>::proximoElemento()
{
	T* objeto = NULL;
	if (masElementos()) {
		objeto = actual->getInfo();
		actual = actual->getSiguiente();
	}
	return objeto;
}