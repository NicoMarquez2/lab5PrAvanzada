#include "fecha.h"

Fecha::Fecha(int a, int m, int d){
    this->anio = a;    
    this->mes = m;
    this->dia = d;
}

Fecha::Fecha(){
    this->anio = 1900;    
    this->mes = 1;
    this->dia = 1;
}

int Fecha::getAnio(){
    return this->anio;
}
int Fecha::getMes(){
    return this->mes;
}
int Fecha::getDia(){
    return this->dia;
}