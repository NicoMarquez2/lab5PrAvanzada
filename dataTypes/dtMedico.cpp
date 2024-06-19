#include "../dataTypes/dtMedico.h"
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

DtMedico::DtMedico(string cont, string nom, string ap, string ced,
                string s, Fecha fechaNac, bool activo, string cat){
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

DtMedico::DtMedico(){
    this->contrasena = " ";
    this->nombre = "nombre";
    this->apellido = "apellido";
    this->cedula = "11111111";
    this->sexo = "s";
    this->fechaNacimiento = Fecha();
    this->edad = calcEdad(this->fechaNacimiento);
    this->activo = false;
    this->categoria = " ";
}

string DtMedico::getContrasena(){
    return this->contrasena;
}
string DtMedico::getNombre(){
    return this->nombre;
}
string DtMedico::getApellido(){
    return this->apellido;
}

string DtMedico::getCedula(){
    return this->cedula;
}
string DtMedico::getSexo(){
    return this->sexo;
}
Fecha DtMedico::getFechaNacimiento(){
    return this->fechaNacimiento;
}
int DtMedico::getEdad(){
    return this->edad;
}
bool DtMedico::getActivo(){
    return this->activo;
}

string DtMedico::getCategoria(){
    return this->categoria;
}

DtMedico::~DtMedico(){

}