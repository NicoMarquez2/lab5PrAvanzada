#include "CConsulta.h"

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

vector<DtConsulta> obtenerConsultas(){}
DtConsulta seleccionarConsulta(string ci){}
void obtenerCategorias(){}
void seleccionarCategoria(string categoria){}
void obtenerDiagnosticos(){}
void seleccionarDiagnostico(string diagnostico){}
void agregarDescripcion(string descripcion){}
void agregarTratamiento(string descripcion, string tipo){}
void agregarFecha(Fecha fecha){}
void agregarMedicamento(string medicamento){}
void registroReserva(string ciMed, string ciPac, bool asiste, Fecha fecha, Fecha fechaReserva){}
void registroEmergencia(string ciMed, string ciPac, Fecha fecha, string motivo){}
void listarRepresentacionesEstandarizadas(){}