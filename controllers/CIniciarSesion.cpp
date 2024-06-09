#include "CIniciarSesion.h"

CIniciarSesion* CIniciarSesion::instancia = NULL;

CIniciarSesion::CIniciarSesion(){}

CIniciarSesion* CIniciarSesion::getInstancia(){
    if (instancia == NULL)
        instancia = new CIniciarSesion();
    return instancia;
}

void CIniciarSesion::ingresarCedula(string ci){
    printf("funciono");
};

void CIniciarSesion::ingresarDatos(string nombre, string apellido, string sexo, Fecha fechaNacimiento ,string categoria){
    printf("funciono");
};

void CIniciarSesion::activarUsuario(string ci){
    printf("funciono");
};

void CIniciarSesion::salir(){
    printf("funciono");
};
