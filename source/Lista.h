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
};