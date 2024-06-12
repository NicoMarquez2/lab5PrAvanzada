#include "../headers/registroUsuario.h"

RegistroUsuario::RegistroUsuario(){
    this->usuario = new Usuario();
}

RegistroUsuario::RegistroUsuario(Usuario* u){
    this->usuario = u;
}

Usuario* RegistroUsuario::getUsuario(){
    return this->usuario;
}

void RegistroUsuario::setUsuario(Usuario* u){
    this->usuario = u;
}