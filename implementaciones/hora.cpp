#include "hora.h"

Hora::Hora(int h, int m){
    this->horas = h;
    this->minutos = m;
}

Hora::Hora(){
    this->horas = 0;
    this->minutos = 0;
}

int Hora::getHoras(){
    return this->horas;
}

int Hora::getMinutos(){
    return this->minutos;
}