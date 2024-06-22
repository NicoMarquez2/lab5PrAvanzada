#include "dtReserva.h"

DtReserva::DtReserva(Fecha f, Hora h, Fecha fechaRes, Usuario* pac, Usuario* med, bool a){
    this->fecha = f;
    this->hora = h;
    this->fechaReserva = fechaRes;
    this->paciente = pac;
    this->medico = med;
    this->asiste = a;
}

DtReserva::DtReserva(){
    /*Usuario* pac = new Usuario();
    Usuario* med = new Usuario();

    this->fecha = Fecha();
    this->hora = Hora();
    this->fechaReserva = Fecha();
    this->paciente = pac;
    this->medico = med;*/
}

DtReserva::~DtReserva(){}

Fecha DtReserva::getFecha(){
    return this->fecha;
}

Hora DtReserva::getHora(){
    return this->hora;
}

bool DtReserva::getAsiste(){
    return this->asiste;
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