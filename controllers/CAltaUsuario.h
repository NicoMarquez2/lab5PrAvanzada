#ifndef CALTAUSUARIO_H
#define CALTAUSUARIO_H

#include "../interfaces/IAltaUsuario.h"

class CAltaUsuario: public IAltaUsuario
{
private:
    static CAltaUsuario* instancia;
    CAltaUsuario();
public:
    static CAltaUsuario* getInstancia();
    void ingresarCedula(string ci);
    void ingresarDatos(string nombre, string apellido, string sexo, Fecha fechaNacimiento, string categoria);
    void activarUsuario(string ci);
    void salir();
};

#endif