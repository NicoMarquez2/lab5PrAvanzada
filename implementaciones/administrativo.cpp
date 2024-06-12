#include "../headers/administrativo.h"

Administrativo::Administrativo(){
    this->registros = {};
}

Administrativo::Administrativo(vector<RegistroUsuario*> reg){
    this->registros = reg;
}

vector<RegistroUsuario*> Administrativo::getRegistros(){
    return this->registros;
}

void Administrativo::setRegistros(vector<RegistroUsuario*> reg){
    this->registros = reg;
}

Administrativo::~Administrativo(){}