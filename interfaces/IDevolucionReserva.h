#ifndef IDEVOLUCIONRESERVA_H
#define IDEVOLUCIONRESERVA_H

#include "../dataTypes/dtReserva.h"
#include <set>
#include <string>
#include <iostream>
#include "stdio.h"

class IDevolucionReserva
{
public:
    virtual set<DtReserva> obtenerReservas() = 0;
    virtual void cancelarReserva(DtReserva reserva) = 0;
};

#endif