#ifndef MEDICO_H
#define MEDICO_H

#include "categoriaUsuario.h"
#include <vector>
#include "../headers/consulta.h"
#include "../dataTypes/dtConsulta.h"

class Medico: public CategoriaUsuario{
    private:
        Consulta* consulta;
        vector<Consulta*> consultas;
    public:
        Medico();
        ~Medico();
};

#endif