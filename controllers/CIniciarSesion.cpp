#include "CIniciarSesion.h"

CIniciarSesion* CIniciarSesion::instancia = NULL;

CIniciarSesion::CIniciarSesion(){}

CIniciarSesion* CIniciarSesion::getInstancia(){
    if (instancia == NULL)
        instancia = new CIniciarSesion();
    return instancia;
}

void CIniciarSesion::ingresarCedula(string ci){
    cout << "cedula: " << ci;
};

bool CIniciarSesion::registrarContrasena(string ci){
    printf("funciono");
    return true;
};

bool CIniciarSesion::ingresarContrasena(string ci){
    printf("funciono");
    return true;
};

void CIniciarSesion::cancelar(){
    printf("funciono");
};
