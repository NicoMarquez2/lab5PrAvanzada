#include "CAltaUsuario.h"

CAltaUsuario* CAltaUsuario::instancia = NULL;

CAltaUsuario::CAltaUsuario(){}

CAltaUsuario* CAltaUsuario::getInstancia(){
    if (instancia == NULL)
        instancia = new CAltaUsuario();
    return instancia;
}

void CAltaUsuario::ingresarCedula(string ci){
    cout << "ingresarCedula";
}

void CAltaUsuario::ingresarDatos(string nombre, string apellido, string sexo, Fecha fechaNacimiento, string categoria){
    cout << "ingresarDatos";
}

void CAltaUsuario::activarUsuario(string ci){
    cout << "activarUsuario";
}

void CAltaUsuario::salir(){
    cout << "salir";
}