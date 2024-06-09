#include "CCerrarSesion.h"

CCerrarSesion* CCerrarSesion::instancia = NULL;

CCerrarSesion::CCerrarSesion(){}

CCerrarSesion* CCerrarSesion::getInstancia(){
    if (instancia == NULL)
        instancia = new CCerrarSesion();
    return instancia;
}

void CCerrarSesion::cerrarSesion(){
    printf("Cerrar sesion\n");
}