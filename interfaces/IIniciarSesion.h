#ifndef IINICIARSESION_H
#define IINICIARSESION_H

#include <string.h>
#include "fecha.h"

using namespace std;

class IIniciarSesion
{
public:
    virtual void ingresarCedula(string ci) = 0;
    virtual void ingresarDatos(string nombre, string apellido, string sexo, Fecha fechaNacimiento ,string categoria)= 0;
    virtual void activarUsuario(string ci) = 0;
    virtual void salir() = 0;
};

#endif