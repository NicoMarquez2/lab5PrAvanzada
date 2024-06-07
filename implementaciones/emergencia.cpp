#include "emergencia.h"

Emergencia::Emergencia() : Consulta(), motivo("motivo"){}

Emergencia::Emergencia(Fecha f, Hora h, string mot) : Consulta(f, h), motivo(mot){}

string Emergencia::getMotivo(){
    return this->motivo;
}

void Emergencia::setMotivo(string mot){
    this->motivo = mot;
}