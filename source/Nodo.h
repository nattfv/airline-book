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

