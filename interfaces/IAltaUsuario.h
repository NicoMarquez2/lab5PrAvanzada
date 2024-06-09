#ifndef IALTAUSUARIO_H
#define IALTAUSUARIO_H

#include <string.h>
#include "../dataTypes/fecha.h"
#include <iostream>
#include "stdio.h"

using namespace std;

class IAltaUsuario
{
public:
    virtual void ingresarCedula(string ci) = 0;
    virtual void ingresarDatos(string nombre, string apellido, string sexo, Fecha fechaNacimiento, string categoria) = 0;
    virtual void activarUsuario(string ci) = 0;
    virtual void salir() = 0;
};

#endif