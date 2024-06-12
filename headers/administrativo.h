#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H
#include "categoriaUsuario.h"
#include "registroUsuario.h"
#include "usuarioAdministrativo.h"
#include <vector>

class Administrativo: public CategoriaUsuario{
    private:
        UsuarioAdministrativo* userA;
        vector<RegistroUsuario*> registros;
    public:
        Administrativo();
        Administrativo(vector<RegistroUsuario*> reg);
        vector<RegistroUsuario*> getRegistros();
        void setRegistros(vector<RegistroUsuario*> reg);
        ~Administrativo();
};

#endif