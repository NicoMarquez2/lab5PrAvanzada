#include "dtConsulta.h"

DtConsulta::DtConsulta(Fecha f, Hora h, Usuario* pac, Usuario* med, map<string, DtDiagnostico> diag){
    this->fecha = f;
    this->hora = h;
    this->paciente = pac;
    this->medico = med;
    this->diagnosticos = diag;
}

DtConsulta::DtConsulta(){
    /*Usuario* pac = new Usuario();    
    Usuario* med = new Usuario();

    this->fecha = Fecha();
    this->hora = Hora();
    this->paciente = pac;
    this->medico = med;*/
}

DtConsulta::~DtConsulta(){}

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
map<string, DtDiagnostico> DtConsulta::getDiagnosticos(){
    return this->diagnosticos;
}


