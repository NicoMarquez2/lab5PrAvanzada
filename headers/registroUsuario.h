#ifndef REGISTROUSUARIO_H
#define REGISTROUSUARIO_H

#include <iostream>
#include <string>
#include "../headers/usuario.h"
#include "../headers/administrativo.h"

using namespace std;

class RegistroUsuario
{
private:
    Usuario* usuario;
public:
    RegistroUsuario();
    RegistroUsuario(Usuario* u);
    Usuario* getUsuario();
    void setUsuario(Usuario* u);
    ~RegistroUsuario();
};

#endif
