#include "CDevolucionReserva.h"

CDevolucionReserva* CDevolucionReserva::instancia = NULL;

CDevolucionReserva::CDevolucionReserva(){}

CDevolucionReserva* CDevolucionReserva::getInstancia(){
    if (instancia == NULL)
        instancia = new CDevolucionReserva();
    return instancia;
}

vector<DtReserva> CDevolucionReserva::obtenerReservas(){
    cout << "obtener reservas";
    vector<DtReserva> s = {DtReserva()};
    return s;
}

void CDevolucionReserva::cancelarReserva(DtReserva reserva){
    cout << "cancelar reserva";
}