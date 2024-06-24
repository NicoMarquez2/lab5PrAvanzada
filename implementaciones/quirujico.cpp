#include "../headers/quirurgico.h"

Quirurgico::Quirurgico(){
    this->fechaIntervencion = Fecha();
}

Quirurgico::Quirurgico(string desc, Fecha fecha): 
    Tratamiento(desc), fechaIntervencion(fecha){}
    

Fecha Quirurgico::getFechaintervencion(){
    return this->fechaIntervencion;
}

void Quirurgico::setFechaIntervencion(Fecha fecha){
    this->fechaIntervencion = fecha;
}
Quirurgico::~Quirurgico(){}
