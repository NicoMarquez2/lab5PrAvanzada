#include "../headers/quirurgico.h"

Quirurgico::Quirurgico(){
    this->fechaIntervencion = Fecha();
}

Quirurgico::Quirurgico(Fecha fecha){
    this->fechaIntervencion = fecha;
}

Fecha Quirurgico::getFechaintervencion(){
    return this->fechaIntervencion;
}

void Quirurgico::setFechaIntervencion(Fecha fecha){
    this->fechaIntervencion = fecha;
}
