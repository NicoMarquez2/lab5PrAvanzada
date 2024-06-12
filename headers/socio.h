#ifndef SOCIO_H
#define SOCIO_H

#include "categoriaUsuario.h"
#include "../dataTypes/dtConsulta.h"
#include "../dataTypes/dtReserva.h"
#include "../dataTypes/dtEmergencia.h"
#include "../headers/consulta.h"
#include "../headers/reserva.h"
#include "../headers/emergencia.h"
#include "../headers/usuarioSocio.h"
#include <vector>

class Socio: public CategoriaUsuario{
    private:
        UsuarioSocio* userS;
    public:
        Socio();
        ~Socio();
};

#endif