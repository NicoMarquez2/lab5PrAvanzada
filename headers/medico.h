#ifndef MEDICO_H
#define MEDICO_H

#include "categoriaUsuario.h"
#include <vector>
#include "../headers/consulta.h"
#include "../headers/usuarioMedico.h"

class Medico: public CategoriaUsuario{
    private:
        UsuarioMedico* userM;
        vector<Consulta*> consultas;
    public:
        Medico();
        ~Medico();
};

#endif