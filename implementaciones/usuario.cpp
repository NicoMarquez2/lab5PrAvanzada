#include "../headers/usuario.h"
#include "../dataTypes/dtEmergencia.h"
#include "../dataTypes/dtReserva.h"

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

Usuario::Usuario(string nom, string ap, string ci, string se, Fecha fechaNac, int ed, bool act){
    this->contrasena = " ";
    this->nombre = nom;
    this->apellido = ap;
    this->cedula = ci;
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
    this->fechaNacimiento = Fecha();
    this->edad = 1;
    this->activo = false;
}

string Usuario::getContrasena(){}
string Usuario::getNombre(){}
string Usuario::getApellido(){
    return this->apellido;
}
string Usuario::getCedula(){}
string Usuario::getSexo(){}
Fecha Usuario::getFechaNacimiento(){}
int Usuario::getEdad(){}
bool Usuario::getActivo(){}
bool Usuario::esContrasena(string pass){}
vector<DtReserva> Usuario::getReservas(){}

void Usuario::setContrasena(string cont){}
void Usuario::setNombre(string nom){}
void Usuario::setApellido(string ap){}
void Usuario::setCedula(string ced){}
void Usuario::setSexo(string s){}
void Usuario::setFechaNacimiento(Fecha fecha){}
void Usuario::setActivo(bool act){}
void Usuario::borrarReserva(DtReserva reserva){}
void Usuario::agregarReserva(DtReserva reserva){}
void Usuario::agregarEmergencia(DtEmergencia emergencia){}

Usuario::~Usuario(){}