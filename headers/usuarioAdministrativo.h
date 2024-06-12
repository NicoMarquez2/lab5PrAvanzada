#ifndef USUARIOADMINISTRATIVO_H
#define USUARIOADMINISTRATIVO_H

#include "categoriaUsuario.h"
#include "usuario.h"

class UsuarioAdministrativo
{
private:
    Usuario* usuario;
public:
    UsuarioAdministrativo();
    UsuarioAdministrativo(Usuario* u);
    Usuario* getUsuario();
    void setUsuario(Usuario* u);
    ~UsuarioAdministrativo();
};

#endif