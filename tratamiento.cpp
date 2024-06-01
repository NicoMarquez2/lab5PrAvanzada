#include "tratamiento.h"

Tratamiento::Tratamiento(string desc){
    this->descripcion = desc;
}

Tratamiento::Tratamiento(){
    this->descripcion = "Descripcion vacia";
}

void Tratamiento::setDescripcion(string desc){
    this->descripcion = desc;
}

string Tratamiento::getDescripcion(){
    return this->descripcion;
}