#include "dtConsulta.h"

DtConsulta::DtConsulta(Fecha f, Hora h, Usuario* pac, Usuario* med){
    this->fecha = f;
    this->hora = h;
    this->paciente = pac;
    this->medico = med;
}

DtConsulta::DtConsulta(){
    Usuario* pac = new Usuario();    
    Usuario* med = new Usuario();

    this->fecha = Fecha::Fecha();
    this->hora = Hora::Hora();
    this->paciente = pac;
    this->medico = med;
}

Fecha DtConsulta::getFecha(){
    return this->fecha;
}

Hora DtConsulta::getHora(){
    return this->hora;
}

Usuario* DtConsulta::getSocio(){
    return this->paciente;
}

Usuario* DtConsulta::getMedico(){
    return this->medico;
}