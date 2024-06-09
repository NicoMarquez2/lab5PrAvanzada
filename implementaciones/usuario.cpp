#include "../headers/usuario.h"

Usuario::Usuario(string cont, string nom, string ap, string ced, string se, Fecha fechaNac, int ed, bool act){
    this->contrasena = cont;
    this->nombre = nom;
    this->apellido = ap;
    this->cedula = ced;
    this->sexo = se;
    this->fechaNacimiento = fechaNac;
    this->edad = ed;
    this->activo = act;
}

Usuario::Usuario(){
    this->contrasena = "p";
    this->nombre = "juan";
    this->apellido = "perez";
    this->cedula = "11111111";
    this->sexo = "masculino";
    this->fechaNacimiento = Fecha::Fecha();
    this->edad = 1;
    this->activo = false;
}