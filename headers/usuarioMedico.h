#ifndef USUARIOMEDICO_H
#define USUARIOMEDICO_H

#include "categoriaUsuario.h"
#include "usuario.h"

class UsuarioMedico
{
private:
    Usuario* usuario;
public:
    UsuarioMedico();
    UsuarioMedico(Usuario* u);
    Usuario* getUsuario();
    void setUsuario(Usuario* u);
    ~UsuarioMedico();
};

#endif