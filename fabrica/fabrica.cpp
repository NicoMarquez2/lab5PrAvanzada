#include "fabrica.h"

Fabrica* Fabrica::instancia = NULL;

Fabrica::Fabrica(){}

Fabrica* Fabrica::getInstancia(){
    if (instancia == NULL)
        instancia = new Fabrica();
    return instancia;
}

IIniciarSesion* Fabrica::getIIniciarSesion(){
    return CIniciarSesion::getInstancia();
}

Fabrica::~Fabrica(){}