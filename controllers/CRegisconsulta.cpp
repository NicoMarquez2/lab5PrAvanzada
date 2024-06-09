#include "CRegisConsulta.h"

CRegisConsulta* CRegisConsulta::instancia = NULL;

CRegisConsulta::CRegisConsulta(){}

CRegisConsulta* CRegisConsulta::getInstancia(){
    if (instancia == NULL)
        instancia = new CRegisConsulta();
    return instancia;
}

void CRegisConsulta::registroReserva(string ciMed, string ciPac, bool asiste, Fecha fecha, Fecha fechaReserva){
    cout << "registro reserva\n";
}

void CRegisConsulta::registroEmergencia(string ciMed, string ciPac, Fecha fecha, string motivo){
    cout << "registro emergencia\n";
}