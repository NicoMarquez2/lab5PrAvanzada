#include "../headers/emergencia.h"

Emergencia::Emergencia() : Consulta(), motivo("motivo"){}

Emergencia::Emergencia(Fecha f, Hora h, Usuario* soc, Usuario* med, string mot) : 
            Consulta(f, h, soc, med), motivo(mot){}

string Emergencia::getMotivo(){
    return this->motivo;
}

void Emergencia::setMotivo(string mot){
    this->motivo = mot;
}