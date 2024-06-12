#include "../headers/socio.h"

Socio::Socio(){
    this->consultas = {};
}

void Socio::setConsultas(vector<Consulta*> cons){
    this->consultas = cons;
}

void::Socio::agregarReserva(DtReserva res){
    Reserva* r = new Reserva(res.getFecha(), res.getHora(), res.getSocio(), res.getMedico(), res.getFechaReserva());
    this->consultas.push_back(r);
}

void::Socio::agregarEmergencia(DtEmergencia em){
    Emergencia* e = new Emergencia(em.getFecha(), em.getHora(), em.getSocio(), em.getMedico(), em.getMotivo());
    this->consultas.push_back(e);
}

void Socio::borrarReserva(DtReserva reserva){

}

Socio::~Socio(){}