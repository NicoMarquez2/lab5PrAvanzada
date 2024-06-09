#include "dtQuir.h"

DtQuir::DtQuir(string desc, Fecha fechaInt){
    this->descripcion = desc;
    this->fechaIntervencion = fechaInt;
}

DtQuir::~DtQuir(){}

string DtQuir::getDescripcion(){
    return this->descripcion;
}

Fecha DtQuir::getFechaIntervencion(){
    return this->fechaIntervencion;
}