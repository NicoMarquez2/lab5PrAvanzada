#include "dtReserva.h"

DtReserva::DtReserva(Fecha f, Hora h, Fecha fechaRes, Usuario* pac, Usuario* med){
    this->fecha = f;
    this->hora = h;
    this->fechaReserva = fechaRes;
    this->paciente = pac;
    this->medico = med;
}

Fecha DtReserva::getFecha(){
    return this->fecha;
}

Hora DtReserva::getHora(){
    return this->hora;
}

Fecha DtReserva::getFechaReserva(){
    return this->fechaReserva;
}

Usuario* DtReserva::getSocio(){
    return this->paciente;
}

Usuario* DtReserva::getMedico(){
    return this->medico;
}