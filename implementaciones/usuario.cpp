#include "../headers/usuario.h"
#include "../dataTypes/dtEmergencia.h"
#include "../dataTypes/dtReserva.h"
#include "../dataTypes/dtFarm.h"
#include "../dataTypes/dtQuir.h"
#include <chrono>
#include <ctime>
#include <iostream>

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

Usuario::Usuario(string cont, string nom, string ap, string ced, string se, Fecha fechaNac, bool act, CategoriaUsuario* cat){
    this->contrasena = cont;
    this->nombre = nom;
    this->apellido = ap;
    this->cedula = ced;
    this->sexo = se;
    this->fechaNacimiento = fechaNac;
    this->edad = calcularEdad(fechaNac);
    this->activo = act;
    this->categoria = cat;
}

Usuario::Usuario(string nom, string ap, string ci, string se, Fecha fechaNac, bool act, CategoriaUsuario* cat){
    this->contrasena = " ";
    this->nombre = nom;
    this->apellido = ap;
    this->cedula = ci;
    this->sexo = se;
    this->fechaNacimiento = fechaNac;
    this->edad = calcularEdad(fechaNac);
    this->activo = act;
    this->categoria = cat;
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

CategoriaUsuario* Usuario::getCategoria(){
    return this->categoria;
}

vector<Consulta*> Usuario::getConsultas(){
    return this->consultas;
}

bool Usuario::esContrasena(string pass){
    return this->contrasena == pass;
}

vector<DtReserva> Usuario::obtenerReservas(){
    vector<DtReserva> setDtR;
    DtReserva DtR;
    vector<Consulta*>::iterator it;
    for (it=consultas.begin(); it!=consultas.end(); ++it){
            this->consulta = *it;
            Reserva* reserva = dynamic_cast<Reserva*>(consulta);
            DtR = DtReserva(reserva->getFecha(), reserva->getHora(), reserva->getFechaReserva(), reserva->getSocio(), reserva->getMedico(), reserva->getAsiste());
            setDtR.push_back(DtR);
    }    
    return setDtR;
}

vector<DtConsulta> Usuario::obtenerConsultas(){
    vector<DtConsulta> setDtC;
    vector<Consulta*>::iterator it;
    for (it=consultas.begin(); it!=consultas.end(); ++it){
            map<string, DtDiagnostico> dtDiag;
            DtConsulta DtC;
            this->consulta = *it;
            Reserva* reserva = dynamic_cast<Reserva*>(consulta);
            map<string, Diagnostico*> diag = reserva->getDiagnosticos();
            map<string, Diagnostico*>::iterator it2;
            for (it2=diag.begin(); it2!=diag.end(); ++it2){
                string cod = it2->first;
                DtDiagnostico DtD;
                Diagnostico codDiag = *it2->second;
                string desc = codDiag.getDescripcion();
                DtCodDiagnostico *tmp = new DtCodDiagnostico(codDiag.getCodDiagnostico()->getCodigoCategoria(), codDiag.getCodDiagnostico()->getCategoria(),
                                                codDiag.getCodDiagnostico()->getCodigoDiagnostico(), codDiag.getCodDiagnostico()->getEtiqueta());
                DtCodDiagnostico dtCod = *tmp;

                vector<Tratamiento*> tratDiag = it2->second->getTratamientos();
                vector<Tratamiento*>::iterator itTrat;
                vector<DtFarm> setDtFarm;
                vector<DtQuir> setDtQuir;
                string quirFarm;
                for (itTrat=tratDiag.begin(); itTrat !=tratDiag.end(); ++itTrat){
                    Tratamiento *t = *itTrat;
                    if (dynamic_cast<Farmaco*>(t)){
                        Farmaco *f = dynamic_cast<Farmaco*>(t);
                        DtFarm *tmp = new DtFarm(f->getDescripcion(), f->getMedicamento());
                        DtFarm DtF = *tmp;
                        setDtFarm.push_back(DtF);
                        quirFarm = "farmaco";
                    } else if (dynamic_cast<Quirurgico*>(t)){
                        Quirurgico *q = dynamic_cast<Quirurgico*>(t);
                        DtQuir *tmp = new DtQuir(q->getDescripcion(), q->getFechaintervencion());
                        DtQuir DtQ = *tmp;
                        setDtQuir.push_back(DtQ);
                        quirFarm = "quirurgico";
                    }
                }
                if (quirFarm == "farmaco"){
                    DtDiagnostico *tmp2 = new DtDiagnostico(dtCod, desc, setDtFarm);
                    DtD = *tmp2;
                }
                else if (quirFarm == "quirurgico"){
                    DtDiagnostico *tmp2 = new DtDiagnostico(dtCod, desc, setDtQuir);
                    DtD = *tmp2;
                }else{
                    DtDiagnostico *tmp2 = new DtDiagnostico(dtCod, desc);
                    DtD = *tmp2;
                }
                dtDiag.insert({DtD.getCodDiagnostico().getCodigoDiagnostico(), DtD});
            }

            DtConsulta *tmp3 = new DtConsulta(reserva->getFecha(), reserva->getHora(), reserva->getSocio(), reserva->getMedico(), dtDiag);
            DtC = *tmp3;
            setDtC.push_back(DtC);
    }
    return setDtC;
}

map<string, DtConsulta> Usuario::obtenerDiagnosticosConsultas(){
}

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

void Usuario::setCategoria(CategoriaUsuario* cat){
    this->categoria = cat;
}

void Usuario::setConsultas(vector<Consulta*> consultasUser){
    this->consultas = consultasUser;
}

void Usuario::ingresarConsulta(Consulta* consultaUser){
    this->consultas.push_back(consultaUser);
}

Usuario::~Usuario(){}