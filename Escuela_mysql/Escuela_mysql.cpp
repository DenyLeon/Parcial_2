#include <iostream>
#include "Estudiante.h"
using namespace std;


void crear();
void leer();
void actualizar();
void eliminar();
int main() {
    int menu;
    do {

        cout << "\n 1. Nuevo";
        cout << "\n 2. Leer";
        cout << "\n 3. Actualizar";
        cout << "\n 4. Borrar";
        cout << "\n 5. Salir ";
        cout << "\n Operacion a ejecutar: ";

        cin >> menu;
        system("cls");

        switch (menu) {
        case 1: crear(); break;
        case 2: leer(); break;
        case 3: actualizar(); break;
        case 4: eliminar(); break;

        }

    } while (menu <= 4);
    return 0;

}

void crear(){
    
    string carnet, nombres, apellidos, direccion, email, fecha_nacimiento, genero ;
    int telefono=0;  
    cout << "ingrese Carnet: ";
    getline(cin, carnet);
    cout << "ingrese Nombre: ";
    getline(cin, nombres); 
    cout << "ingrese Apellidos: ";
    getline(cin, apellidos);
    cout << "ingrese Direccion: ";
    getline(cin, direccion);
    cout << "ingrese Telefono: ";
    cin >> telefono;
    cin.ignore();
    cout << "ingrese genero: ";
    getline(cin, genero);
    cout << "ingrese E-mail: ";
    getline(cin, email);
    cout << "ingrese Fecha de Nacimiento: ";
    getline(cin, fecha_nacimiento);
    

    Estudiante c = Estudiante(carnet, nombres, apellidos, direccion, telefono, email, genero, fecha_nacimiento);
    c.crear();
    system("pause");
}
void leer(){
    string carnet, nombres, apellidos, direccion, email, fecha_nacimiento, genero;
    int telefono=0;
    Estudiante c = Estudiante(carnet, nombres, apellidos, direccion, telefono, email, genero, fecha_nacimiento);
    c.leer();
}
void actualizar() {
    string carnet, nombres, apellidos, direccion, email, fecha_nacimiento, genero;
    int telefono=0;
   
        Estudiante c = Estudiante(carnet, nombres, apellidos, direccion, telefono, email, genero, fecha_nacimiento);
        c.actualizar();

    system("pause");
}
void eliminar() {
    string carnet, nombres, apellidos, direccion, email, fecha_nacimiento, genero;
    int telefono = 0;
    Estudiante c = Estudiante(carnet, nombres, apellidos, direccion, telefono, email, genero, fecha_nacimiento);
    c.eliminar();
}