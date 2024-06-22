#ifndef DTRESERVA_H
#define DTRESERVA_H

#include <string>
#include <iostream>
#include "../dataTypes/dtFecha.h"
#include "../dataTypes/hora.h"
#include "../headers/usuario.h"

using namespace std;

class DtReserva
{
private:
    Fecha fecha;
    Hora hora;
    Fecha fechaReserva;
    bool asiste;
    Usuario* paciente;
    Usuario* medico;
public:
    DtReserva(Fecha f, Hora h, Fecha fechaRes, Usuario* pac, Usuario* med, bool a);
    DtReserva();
    Fecha getFecha();
    Hora getHora();
    Fecha getFechaReserva();
    bool getAsiste();
    Usuario* getSocio();
    Usuario* getMedico();
    ~DtReserva();
};

#endif