#ifndef IDEVOLUCIONRESERVA_H
#define IDEVOLUCIONRESERVA_H

#include "dtReserva.h"
#include <set>

class IDevolucionReserva
{
public:
    virtual set<DtReserva> obtenerReservas() = 0;
    virtual void cancelarReserva(DtReserva reserva) = 0;
};

#endif