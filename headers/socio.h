#ifndef SOCIO_H
#define SOCIO_H

#include "categoriaUsuario.h"
#include "../dataTypes/dtConsulta.h"
#include "../dataTypes/dtReserva.h"
#include "../dataTypes/dtEmergencia.h"
#include "../headers/consulta.h"
#include "../headers/reserva.h"
#include "../headers/emergencia.h"
#include <vector>

class Socio: public CategoriaUsuario{
    private:
        vector<Consulta*> consultas; 
    public:
        Socio();
        vector<DtConsulta> getConsultas();
        vector<DtReserva> getReservas();
        void setConsultas(vector<Consulta*>);
        void borrarReserva(DtReserva reserva);
        void agregarReserva(DtReserva reserva);
        void agregarEmergencia(DtEmergencia emergencia);
        ~Socio();
};

#endif