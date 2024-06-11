#ifndef MEDICO_H
#define MEDICO_H

#include "categoriaUsuario.h"
#include <vector>
#include "../headers/consulta.h"

class Medico: public CategoriaUsuario{
    private:
        vector<Consulta*> consultas;
    public:
        Medico();
        ~Medico();
};

#endif