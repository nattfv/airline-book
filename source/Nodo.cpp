#include"Nodo.h"

template<class T>
Nodo<T>::Nodo(Nodo<T>* s, T& i) : siguiente(s), info(&i) {}

template<class T>
Nodo<T>::~Nodo() { delete info; }

template<class T>
void Nodo<T>::setSiguiente(Nodo<T>* s) {
	siguiente = s;
}

template<class T>
Nodo<T>* Nodo<T>::getSiguiente() { return siguiente; }

template<class T>
T* Nodo<T>::getInfo() { return info; }

template<class T>
void Nodo<T>::setInfo(T* i) {
	info = i;
}