#include "../headers/usuario.h"
#include "../dataTypes/dtEmergencia.h"
#include "../dataTypes/dtReserva.h"
#include <chrono>
#include <ctime>

int calcularEdad(Fecha fecha){
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&now_c);

    int anioActual = now_tm->tm_year + 1900;
    int mesActual = now_tm->tm_mon + 1;
    int diaActual = now_tm->tm_mday;

    int edad = anioActual - fecha.getAnio();

    if (mesActual < fecha.getMes() || (mesActual == fecha.getMes() && diaActual < fecha.getDia())) {
        edad--;
    }

    return edad;
}

Usuario::Usuario(string cont, string nom, string ap, string ced, string se, Fecha fechaNac, bool act){
    this->contrasena = cont;
    this->nombre = nom;
    this->apellido = ap;
    this->cedula = ced;
    this->sexo = se;
    this->fechaNacimiento = fechaNac;
    this->edad = calcularEdad(fechaNac);
    this->activo = act;
}

Usuario::Usuario(string nom, string ap, string ci, string se, Fecha fechaNac, bool act){
    this->contrasena = " ";
    this->nombre = nom;
    this->apellido = ap;
    this->cedula = ci;
    this->sexo = se;
    this->fechaNacimiento = fechaNac;
    this->edad = calcularEdad(fechaNac);
    this->activo = act;
}

Usuario::Usuario(){
    this->contrasena = " ";
    this->nombre = "juan";
    this->apellido = "perez";
    this->cedula = "11111111";
    this->sexo = "masculino";
    this->fechaNacimiento = Fecha();
    this->edad = calcularEdad(this->fechaNacimiento);
    this->activo = false;
}

string Usuario::getContrasena(){
    return this->contrasena;
}
string Usuario::getNombre(){
    return this->nombre;
}
string Usuario::getApellido(){
    return this->apellido;
}
string Usuario::getCedula(){
    return this->cedula;
}
string Usuario::getSexo(){
    return this->sexo;
}
Fecha Usuario::getFechaNacimiento(){
    return this->fechaNacimiento;
}
int Usuario::getEdad(){
    return this->edad;
}
bool Usuario::getActivo(){
    return this->activo;
}
bool Usuario::esContrasena(string pass){
    return this->contrasena == pass;
}
vector<DtReserva> Usuario::getReservas(){}

void Usuario::setContrasena(string cont){
    this->contrasena = cont;
}
void Usuario::setNombre(string nom){
    this->nombre = nom;
}
void Usuario::setApellido(string ap){
    this->apellido = ap;
}
void Usuario::setCedula(string ced){
    this->cedula = ced;
}
void Usuario::setSexo(string s){
    this->sexo = s;
}
void Usuario::setFechaNacimiento(Fecha fecha){
    this->fechaNacimiento = fecha;
}
void Usuario::setActivo(bool act){
    this->activo = act;
}
void Usuario::borrarReserva(DtReserva reserva){}
void Usuario::agregarReserva(DtReserva reserva){}
void Usuario::agregarEmergencia(DtEmergencia emergencia){}

Usuario::~Usuario(){}