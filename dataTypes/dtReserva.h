#ifndef DTRESERVA_H
#define DTRESERVA_H

#include <string>
#include <iostream>
#include "fecha.h"
#include "hora.h"
#include "usuario.h"

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
    DtReserva(Fecha f, Hora h, Fecha fechaReserva, Usuario* pac, Usuario* med);
    Fecha getFecha();
    Hora getHora();
    Fecha getFechaReserva();
    Usuario* getSocio();
    Usuario* getMedico();
    ~DtReserva();
};

#endif