#pragma once
#include "Escuela.h"
#include <iostream>
#include <mysql.h>
#include "Conector.h"
#include <string>
class Estudiante : Escuela {
private: string carnet;
       string email;
       string fecha_nacimiento;
       string genero;

public:
    Estudiante() {
    }
    Estudiante (string car, string nom, string ape, string dir, int tel, string em, string gen, string fn) : Escuela(nom, ape, dir, tel) {
        carnet = car;
        email = em;
        genero = gen;
        fecha_nacimiento = fn;
    }


    void setcarnet(string car) { carnet = car; }
    void setnombres(string nom) { nombres = nom; }
    void setapellidos(string ape) { apellidos = ape; }
    void setdireccion(string dir) { direccion = dir; }
    void settelefono(int tel) { telefono = tel; }
    void setemail(string em) { email = em; }
    void setgenero(string gen) { genero = gen; }
    void setfecha_nacimiento(string fn) { fecha_nacimiento = fn; }

    string getcarnet() { return carnet; }
    string getnombres() { return nombres; }
    string getapellidos() { return apellidos; }
    string getdireccion() { return direccion; }
    int gettelefono() { return telefono; }
    string getemail() { return email; }
    string getgenero() { return genero; }
    string getfecha_nacimiento() { return fecha_nacimiento; }


    void crear() {
        int q_estado;
        Conector cn = Conector();
        cn.abrir_conexion();
        if (cn.getConectar()) {
            string t = to_string(telefono);           
            string insert = "INSERT INTO estudiantes (carnet, nombres, apellidos, direccion, telefono, genero, email, fecha_nacimiento)VALUES('" + carnet + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + t + ",'" + genero + "','" + email + "','" + fecha_nacimiento + "'); ";
            const char* i = insert.c_str();
            q_estado = mysql_query(cn.getConectar(), i);
            if (!q_estado) {
                cout << "Ingreso exitoso" << endl;
            }
            else {
                cout << "Fallo ingreso" << endl;
            }
        }
        else {
            cout << "Error en conectar" << endl;
        }
        cn.cerrar_conexion();
    };

    void leer() {
        int q_estado;
        Conector cn = Conector();
        MYSQL_ROW fila;
        MYSQL_RES* resultado;
        cn.abrir_conexion();
        if (cn.getConectar()) {
            string consulta = "select * from estudiantes;";
            const char* c = consulta.c_str();
            q_estado = mysql_query(cn.getConectar(), c);
            if (!q_estado) {
                resultado = mysql_store_result(cn.getConectar());
                while (fila = mysql_fetch_row(resultado))
                {
                    cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << "," << fila[8] << endl;
                }
            }
            else {
                cout << "Fallo informacion" << endl;
            }
        }
        else {
            cout << "error" << endl;
        }
        cn.cerrar_conexion();
    };

        void actualizar() {
            int q_estado;          
            Conector cn = Conector();
            string carnet0, nombres0, apellidos0, direccion0, email0, fecha_nacimiento0, genero0, telefono0, id;           
            cout << "Ingresar ID a modificar: ";
            cin >> id;
            cin.ignore();
            cout << "Ingrese Carnet: ";
            getline(cin, carnet0);
            cout << "Ingrese Nombre: ";
            getline(cin, nombres0);
            cout << "Ingrese Apellidos: ";
            getline(cin, apellidos0);
            cout << "Ingrese Direccion: ";
            getline(cin, direccion0);
            cout << "Ingrese Telefono: ";
            getline(cin, direccion0);
            cout << "Ingrese genero: ";
            getline(cin, genero0);
            cout << "Ingrese E-mail: ";
            getline(cin, email0);
            cout << "Ingrese Fecha de Nacimiento: ";
            getline(cin, fecha_nacimiento0);
            cn.abrir_conexion();
            if (cn.getConectar()) {
                            
                string update = "UPDATE `estudiantes` SET `carnet` = '" + carnet0 + "', `nombres` = '" + nombres0 + "', `apellidos` = '" + apellidos0 + "', `direccion` = '" + direccion0 + "', `telefono` = '" + telefono0 + "', `genero` = '" + genero0 + "', `email` = '" + email0 + "', `fecha_nacimiento` = '" + fecha_nacimiento0 + "' WHERE(`id_estudiante` = '"+ id +"');";
                const char* i = update.c_str();
                q_estado = mysql_query(cn.getConectar(), i);
                if (!q_estado) {
                    cout << "Modificacion exitoso" << endl;
                }
                else {
                    cout << "Fallo Modificacion" << endl;
                }
            }
            else {
                cout << "Error en conectar" << endl;
            }
            cn.cerrar_conexion();
        }

        void eliminar(){
        int q_estado;
        Conector cn = Conector();
        string id;
        cout << "Ingrese ID a eliminar: ";
        cin >> id;
        cn.abrir_conexion();
        if (cn.getConectar()) {
            string eliminar = "DELETE FROM estudiantes WHERE (id_estudiante = '" + id + "')";
            const char* i = eliminar.c_str();
            q_estado = mysql_query(cn.getConectar(), i);
            if (!q_estado) {
                cout << "Eliminacion exitosa" << endl;
            }
            else {
                cout << "Fallo Eliminacion" << endl;
            }
        }
        else {
            cout << "Error en conectar" << endl;
        }
        cn.cerrar_conexion();
            }
        };