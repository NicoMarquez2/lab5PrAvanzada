#ifndef DtMedico_H
#define DtMedico_H

#include <vector>
#include <string>
#include <iostream>
#include "../dataTypes/dtFecha.h"
#include "../headers/categoriaUsuario.h"

using namespace std;
class DtEmergencia;
class DtReserva;

class DtMedico
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
    string categoria;
public:
    DtMedico(string cont, string nom, string ap, string ced,
                string s, Fecha fechaNac, bool activo, string cat);
    DtMedico();
    string getContrasena();
    string getNombre();
    string getApellido();
    string getCedula();
    string getSexo();
    Fecha getFechaNacimiento();
    int getEdad();
    bool getActivo();
    string getCategoria();
    ~DtMedico();
};

#endif