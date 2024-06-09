#include "CObtenerHistorial.h"

CObtenerHistorial* CObtenerHistorial::instancia = NULL;

CObtenerHistorial::CObtenerHistorial(){}

CObtenerHistorial* CObtenerHistorial::getInstancia(){
    if (instancia == NULL)
        instancia = new CObtenerHistorial();
    return instancia;
}

void CObtenerHistorial::obtenerHistorialPaciente(string ci){
    cout<< "obtener historial paciente";
}