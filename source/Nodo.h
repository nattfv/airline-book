#pragma once

template<class T>
class Nodo
{
private:
	Nodo<T>* siguiente;
	T* info;
public:
	Nodo(Nodo<T>*, T&); // por costumbre se envia una referencia
	~Nodo();
	void setSiguiente(Nodo<T>*);
	Nodo<T>* getSiguiente();
	T* getInfo();
	void setInfo(T*);
};

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
