#ifndef DtUsuario_H
#define DtUsuario_H

#include <vector>
#include <string>
#include <iostream>
#include "../dataTypes/fecha.h"
#include "../headers/categoriaUsuario.h"

using namespace std;
class DtEmergencia;
class DtReserva;

class DtUsuario
{
private:
    string contrasena;
    string nombre;
    string apellido;
    string cedula;
    string sexo;
    Fecha fechaNacimiento;
    int edad;
    bool activo;
    CategoriaUsuario* categoria;
public:
    DtUsuario(string cont, string nom, string ap, string ced,
                string s, Fecha fechaNac, bool activo, CategoriaUsuario* cat);
    DtUsuario();
    string getContrasena();
    string getNombre();
    string getApellido();
    string getCedula();
    string getSexo();
    Fecha getFechaNacimiento();
    int getEdad();
    bool getActivo();
    CategoriaUsuario* getCategoria();
    ~DtUsuario();
};

#endif