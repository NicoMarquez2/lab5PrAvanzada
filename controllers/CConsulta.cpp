#include "CConsulta.h"

CUsuario* CU = CUsuario::getInstancia();

CConsulta* CConsulta::instancia = NULL;

CConsulta::CConsulta(){}

CConsulta* CConsulta::getInstancia(){
    if (instancia == NULL)
        instancia = new CConsulta();
    return instancia;
}

void CConsulta::cargarDatos(vector<Consulta*> consultas, map<string, Diagnostico*> diagnosticos, vector<CodDiagnostico*> codigos){
    this->consultas = consultas;
    this->diagnosticos = diagnosticos;
    this->codigos = codigos;
}

vector<Consulta*> CConsulta::getConsultas(){
    return this->consultas;
}
map<string, Diagnostico*> CConsulta::getDiagnosticos(){
    return this->diagnosticos;
}
vector<CodDiagnostico*> CConsulta::getCodigos(){
    return this->codigos;
}

void CConsulta::setConsultas(vector<Consulta*> consultas){
    this->consultas = consultas;
}
void CConsulta::setDiagnosticos(map<string, Diagnostico*> diagnosticos){
    this->diagnosticos = diagnosticos;
}
void CConsulta::setCodigos(vector<CodDiagnostico*> codigos){
    this->codigos = codigos;
}

vector<DtConsulta> CConsulta::obtenerConsultas(){}
DtConsulta CConsulta::seleccionarConsulta(string ci){}
void CConsulta::obtenerCategorias(){}
void CConsulta::seleccionarCategoria(string categoria){}
void CConsulta::obtenerDiagnosticos(){}
void CConsulta::seleccionarDiagnostico(string diagnostico){}
void CConsulta::agregarDescripcion(string descripcion){}
void CConsulta::agregarTratamiento(string descripcion, string tipo){}
void CConsulta::agregarFecha(Fecha fecha){}
void CConsulta::agregarMedicamento(string medicamento){}
void CConsulta::registroReserva(string ciMed, string ciPac, Fecha fecha, Fecha fechaReserva){
    map<string,Usuario*> users = CU->getUsuarios();

    map<string, Usuario*>::iterator it;
    Usuario* med;
    Usuario* pac;
    Reserva* r;

    it = users.find(ciMed);
    if (it != users.end()) {
        med = it->second;
    }
    it = users.find(ciPac);
    if (it != users.end()) {
        pac = it->second;
        r = new Reserva(fecha, Hora(), pac, med, fechaReserva);
        this->consultas.push_back(r);
    }
}

void CConsulta::reservaConsulta(Fecha f, Hora h, string ciSoc, string ciMed){
    map<string,Usuario*> users = CU->getUsuarios();

    map<string, Usuario*>::iterator it;
    Usuario* m;
    Usuario* s;
    Consulta* c;

    it = users.find(ciMed);
    if (it != users.end()) {
        m = it->second;
    }
    it = users.find(ciSoc);
    if (it != users.end()) {
        s = it->second;
        c = new Consulta(f, h, s, m);
        this->reservas.push_back(c);
        CU->reservaConsultaUser(s, c);
    }
}

void CConsulta::registroEmergencia(string ciMed, string ciPac, Fecha fecha, string motivo){  
    map<string,Usuario*> users = CU->getUsuarios();

    map<string, Usuario*>::iterator it;
    Usuario* med;
    Usuario* pac;
    Emergencia* e;

    it = users.find(ciMed);
    if (it != users.end()) {
        med = it->second;
    }
    it = users.find(ciPac);
    if (it != users.end()) {
        pac = it->second;
        e = new Emergencia(fecha, Hora(), pac, med, motivo);
        this->consultas.push_back(e);
    }
}
void CConsulta::listarRepresentacionesEstandarizadas(){}