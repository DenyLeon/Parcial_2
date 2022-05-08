#pragma once
#include <iostream>
using namespace std;
class Escuela
{
protected: string nombres, apellidos, direccion;
		 int telefono=0;
		 int telefono1 = 0;

protected:
	Escuela() {
	}
	Escuela(string nom, string ape, string dir, int tel) {
		nombres = nom;
		apellidos = ape;
		direccion = dir;
		telefono = tel;
	}


	/*void mostrar(); */
};

