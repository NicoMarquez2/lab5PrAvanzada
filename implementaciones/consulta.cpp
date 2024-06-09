#include "../headers/consulta.h"

Consulta::Consulta(){
    this->fecha = Fecha::Fecha();
    this->hora = Hora::Hora();
}

Consulta::Consulta(Fecha f, Hora h){
    this->fecha = f;
    this->hora = h;
}

Fecha Consulta::getFecha(){
    return this->fecha;
}

Hora Consulta::getHora(){
    return this->hora;
}

void Consulta::setFecha(Fecha f){
    this->fecha = f;
}

void Consulta::setHora(Hora h){
    this->hora = h;
}