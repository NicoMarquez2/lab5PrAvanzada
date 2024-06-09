#include "../headers/reserva.h"

Reserva::Reserva() : Consulta(), fechaReserva(Fecha::Fecha()){}

Reserva::Reserva(Fecha f, Hora h, Fecha fechaRes) : Consulta(f, h), fechaReserva(fechaRes){}

Fecha Reserva::getFechaReserva(){
    return this->fechaReserva;
}

void Reserva::setFechaReserva(Fecha f){
    this->fechaReserva = f;
}