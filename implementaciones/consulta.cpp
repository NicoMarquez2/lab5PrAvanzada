#include "../headers/consulta.h"
#include "../headers/usuario.h"

Consulta::Consulta(){
    this->fecha = Fecha();
    this->hora = Hora();
    this->medico = new Usuario();
    this->socio = new Usuario();
}

Consulta::Consulta(Fecha f, Hora h, Usuario* soc, Usuario* med){
    this->fecha = f;
    this->hora = h;
    this->socio = soc;
    this->medico = med;
}

Consulta::~Consulta(){}

Fecha Consulta::getFecha(){
    return this->fecha;
}

Hora Consulta::getHora(){
    return this->hora;
}

Usuario* Consulta::getSocio(){
    return this->socio;
}

Usuario* Consulta::getMedico(){
    return this->medico;
}

map<string, Diagnostico*> Consulta::getDiagnosticos(){
    return this->Diagnosticos;
}

void Consulta::setFecha(Fecha f){
    this->fecha = f;
}

void Consulta::setHora(Hora h){
    this->hora = h;
}

void Consulta::setMedico(Usuario* med){
    this->medico = med;
}

void Consulta::setSocio(Usuario* soc){
    this->socio = soc;
}

void Consulta::setDiagnosticos(map<string, Diagnostico*> diag){
    this->Diagnosticos = diag;
}

void Consulta::agregarDiagnostico(Diagnostico* diag){
    Diagnostico* diagnostico = diag;
    string codDiag = diag->getCodDiagnostico()->getCodigoDiagnostico();
    this->Diagnosticos.insert({codDiag, diag});
}