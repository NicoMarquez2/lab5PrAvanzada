#ifndef CDEVOLUCIONRESERVA_H
#define CDEVOLUCIONRESERVA_H

#include "../interfaces/IDevolucionReserva.h"

class CDevolucionReserva: public IDevolucionReserva
{
private:
    static CDevolucionReserva* instancia;
    CDevolucionReserva();
public:
    static CDevolucionReserva* getInstancia();
    virtual set<DtReserva> obtenerReservas();
    virtual void cancelarReserva(DtReserva reserva);
};

#endif