#ifndef DTRESERVA_H
#define DTRESERVA_H

#include <string>
#include <iostream>
#include "../dataTypes/fecha.h"
#include "../dataTypes/hora.h"
#include "../headers/usuario.h"

using namespace std;

class DtReserva
{
private:
    Fecha fecha;
    Hora hora;
    Fecha fechaReserva;
    Usuario* paciente;
    Usuario* medico;
public:
    DtReserva(Fecha f, Hora h, Fecha fechaRes, Usuario* pac, Usuario* med);
    DtReserva();
    Fecha getFecha();
    Hora getHora();
    Fecha getFechaReserva();
    Usuario* getSocio();
    Usuario* getMedico();
    ~DtReserva();
};

#endif