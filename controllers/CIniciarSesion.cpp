#include "CIniciarSesion.h"

CIniciarSesion* CIniciarSesion::instancia = NULL;

CIniciarSesion::CIniciarSesion(){}

CIniciarSesion* CIniciarSesion::getInstancia(){
    if (instancia == NULL)
        instancia = new CIniciarSesion();
    return instancia;
}

void CIniciarSesion::ingresarCedula(string ci){
};
