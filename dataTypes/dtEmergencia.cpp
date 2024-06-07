#include "dtEmergencia.h"

DtEmergencia::DtEmergencia(Fecha f, Hora h, string mot, Usuario* pac, Usuario* med){
    this->fecha = f;
    this->hora = h;
    this->motivo = mot;
    this->paciente = pac;
    this->medico = med;
}

Fecha DtEmergencia::getFecha(){
    return this->fecha;
}

Hora DtEmergencia::getHora(){
    return this->hora;
}

string DtEmergencia::getMotivo(){
    return this->motivo;
}

Usuario* DtEmergencia::getSocio(){
    return this->paciente;
}

Usuario* DtEmergencia::getMedico(){
    return this->medico;
}