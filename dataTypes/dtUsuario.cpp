#include "../dataTypes/dtUsuario.h"
#include <chrono>
#include <ctime>

int calcEdad(Fecha fecha){
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

DtUsuario::DtUsuario(string cont, string nom, string ap, string ced,
                string s, Fecha fechaNac, bool activo, CategoriaUsuario* cat){
    this->contrasena = cont;
    this->nombre = nom;
    this->apellido = ap;
    this->cedula = ced;
    this->sexo = s;
    this->fechaNacimiento = fechaNac;
    this->edad = calcEdad(fechaNac);
    this->activo = activo;
    this->categoria = cat;
}

DtUsuario::DtUsuario(){
    this->contrasena = " ";
    this->nombre = "nombre";
    this->apellido = "apellido";
    this->cedula = "11111111";
    this->sexo = "s";
    this->fechaNacimiento = Fecha();
    this->edad = calcEdad(this->fechaNacimiento);
    this->activo = false;
    this->categoria = nullptr;
}

string DtUsuario::getContrasena(){
    return this->contrasena;
}
string DtUsuario::getNombre(){
    return this->nombre;
}
string DtUsuario::getApellido(){
    return this->apellido;
}

string DtUsuario::getCedula(){
    return this->cedula;
}
string DtUsuario::getSexo(){
    return this->sexo;
}
Fecha DtUsuario::getFechaNacimiento(){
    return this->fechaNacimiento;
}
int DtUsuario::getEdad(){
    return this->edad;
}
bool DtUsuario::getActivo(){
    return this->activo;
}

CategoriaUsuario* DtUsuario::getCategoria(){
    return this->categoria;
}

DtUsuario::~DtUsuario(){

}