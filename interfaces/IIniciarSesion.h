#ifndef IINICIARSESION_H
#define IINICIARSESION_H

#include <string.h>
#include "../dataTypes/fecha.h"

using namespace std;

class IIniciarSesion
{
public:
    virtual void ingresarCedula(string ci) = 0;
    virtual bool registrarContrasena(string pass) = 0;
    virtual bool ingresarContrasena(string pass) = 0;
    virtual void cancelar() = 0;
};

#endif