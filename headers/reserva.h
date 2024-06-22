#ifndef RESERVA_H
#define RESERVA_H

#include "consulta.h"

class Reserva: public Consulta
{
private:
    Fecha fechaReserva;
    bool asiste;
public:
    Reserva();
    Reserva(Fecha f, Hora h, Usuario* soc, Usuario* med, Fecha fechaRes);

    Fecha getFechaReserva();

    void setAsiste(bool a);
    void setFechaReserva(Fecha f);

    virtual ~Reserva() override = default;
};

#endif