#ifndef CINICIARSESION_H
#define CINICIARSESION_H

#include "../interfaces/IIniciarSesion.h"
#include "../dataTypes/Fecha.h"

class CIniciarSesion : public IIniciarSesion
{
private:
    static CIniciarSesion* instancia;
    CIniciarSesion();
public:
    static CIniciarSesion* getInstancia();
    void ingresarCedula(string ci);
    bool registrarContrasena(string pass);
    bool ingresarContrasena(string pass);
    void cancelar();
};

#endif