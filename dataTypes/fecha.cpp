#include "fecha.h"

Fecha::Fecha(int a, int m, int d){
    this->anio = a;    
    this->mes = m;
    this->dia = d;
}

Fecha::Fecha(const Fecha& f){
    this->anio = f.getAnio();
    this->mes = f.getMes();
    this->dia = f.getDia();
}

Fecha::Fecha(){
    this->anio = 1900;    
    this->mes = 1;
    this->dia = 1;
}

Fecha::~Fecha(){}

int Fecha::getAnio() const{
    return this->anio;
}
int Fecha::getMes() const{
    return this->mes;
}
int Fecha::getDia() const{
    return this->dia;
}