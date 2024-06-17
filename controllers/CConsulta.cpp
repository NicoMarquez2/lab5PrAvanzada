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
    it = users.find(ciMed);
    Usuario* med = it->second;

    it = users.find(ciPac);
    Usuario* pac = it->second;
    Reserva* r = new Reserva(fecha, Hora(), pac, med, fechaReserva);

    this->consultas.push_back(r);
}

void CConsulta::registroEmergencia(string ciMed, string ciPac, Fecha fecha, string motivo){  
    map<string,Usuario*> users = CU->getUsuarios();

    map<string, Usuario*>::iterator it;
    it = users.find(ciMed);
    Usuario* med = it->second;

    it = users.find(ciPac);
    Usuario* pac = it->second;
    Emergencia* e = new Emergencia(fecha, Hora(), pac, med, motivo);

    this->consultas.push_back(e);
}
void CConsulta::listarRepresentacionesEstandarizadas(){}