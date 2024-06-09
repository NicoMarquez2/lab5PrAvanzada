#include "CAltaDiagnostico.h"

CAltaDiagnostico* CAltaDiagnostico::instancia = NULL;

CAltaDiagnostico::CAltaDiagnostico(){}

CAltaDiagnostico* CAltaDiagnostico::getInstancia(){
    if (instancia == NULL)
        instancia = new CAltaDiagnostico();
    return instancia;
}

vector<DtConsulta> CAltaDiagnostico::obtenerConsultas(){
    DtConsulta c = DtConsulta();
    vector<DtConsulta> s = {c};
    cout << "obtenerConsultas";
    return s;
}

DtConsulta CAltaDiagnostico::seleccionarConsulta(string ci){
    DtConsulta c = DtConsulta();
    cout << "seleccionarConsulta";
    return c;
}

void CAltaDiagnostico::obtenerCategorias(){
    cout << "obtenerCategorias";
}

void CAltaDiagnostico::seleccionarCategoria(string categoria){
    cout << "seleccionarCategoria";
}

void CAltaDiagnostico::obtenerDiagnosticos(){
    cout << "obtenerDiagnosticos";
}

void CAltaDiagnostico::seleccionarDiagnostico(string diagnostico){
    cout << "seleccionarDiagnostico";
}

void CAltaDiagnostico::agregarDescripcion(string descripcion){
    cout << "agregarDescripcion";
}

void CAltaDiagnostico::agregarTratamiento(string descripcion, string tipo){
    cout << "agregarTratamiento";
}

void CAltaDiagnostico::agregarFecha(Fecha fecha){
    cout << "agregarFecha";
}

void CAltaDiagnostico::agregarMedicamento(string medicamento){
    cout << "agregarMedicamento";
}
