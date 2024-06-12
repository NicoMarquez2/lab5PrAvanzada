#include "../headers/reserva.h"

Reserva::Reserva() : Consulta(), fechaReserva(Fecha()){}

Reserva::Reserva(Fecha f, Hora h, Usuario* soc, Usuario*med, Fecha fechaRes) : 
                Consulta(f, h, soc, med), fechaReserva(fechaRes){}

Fecha Reserva::getFechaReserva(){
    return this->fechaReserva;
}

void Reserva::setFechaReserva(Fecha f){
    this->fechaReserva = f;
}