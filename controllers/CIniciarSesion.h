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
    void ingresarDatos(string nombre, string apellido, string sexo, Fecha fechaNacimiento ,string categoria);
    void activarUsuario(string ci);
    void salir();
};

#endif