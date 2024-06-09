#ifndef CINICIARSESION_H
#define CINICIARSESION_H

#include "IIniciarSesion.h"

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