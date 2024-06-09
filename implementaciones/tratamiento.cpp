#include "../headers/tratamiento.h"

using namespace std;

Tratamiento::Tratamiento(string desc){
    this->descripcion = desc;
}

Tratamiento::Tratamiento(){
    this->descripcion = "Descripcion vacia";
}

Tratamiento::~Tratamiento(){}

void Tratamiento::setDescripcion(string desc){
    this->descripcion = desc;
}

string Tratamiento::getDescripcion(){
    return this->descripcion;
}