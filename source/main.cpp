#include"Controlador.h"
#include<exception>
using namespace std;

int main()
{
	Controlador* control = new Controlador();
	delete control;
	system("pause");
	return 0;
}