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
    map<string, DtDiagnostico> dtDiag;
    DtConsulta DtC;
    vector<Consulta*>::iterator it;
    for (it=consultas.begin(); it!=consultas.end(); ++it){
            this->consulta = *it;
            Reserva* reserva = dynamic_cast<Reserva*>(consulta);
            map<string, Diagnostico*> diag = reserva->getDiagnosticos();
            map<string, Diagnostico*>::iterator it2;
            for (it2=diag.begin(); it2!=diag.end(); ++it2){
                string cod = it2->first;
                Diagnostico codDiag = *it2->second;
                string desc = codDiag.getDescripcion();
                DtCodDiagnostico *tmp = new DtCodDiagnostico(codDiag.getCodDiagnostico()->getCodigoCategoria(), codDiag.getCodDiagnostico()->getCategoria(),
                                                codDiag.getCodDiagnostico()->getCodigoDiagnostico(), codDiag.getCodDiagnostico()->getEtiqueta());
                DtCodDiagnostico dtCod = *tmp;
                DtDiagnostico *tmp2 = new DtDiagnostico(dtCod, desc);
                DtDiagnostico DtD = *tmp2;
                dtDiag.insert({DtD.getCodDiagnostico().getCodigoDiagnostico(), DtD});
            }

            DtC = DtConsulta(reserva->getFecha(), reserva->getHora(), reserva->getSocio(), reserva->getMedico(), dtDiag);
            dtDiag.clear();
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