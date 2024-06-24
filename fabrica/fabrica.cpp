#include "fabrica.h"

Fabrica* Fabrica::instancia = NULL;

Fabrica::Fabrica(){}

Fabrica* Fabrica::getInstancia(){
    if (instancia == NULL)
        instancia = new Fabrica();
    return instancia;
}

IUsuario* Fabrica::getIUsuario(){
    return CUsuario::getInstancia();
}

IConsulta* Fabrica::getIConsulta(){
    return CConsulta::getInstancia();
}

Fabrica::~Fabrica(){}