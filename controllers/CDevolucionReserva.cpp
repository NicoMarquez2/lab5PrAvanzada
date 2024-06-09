#include "CDevolucionReserva.h"

CDevolucionReserva* CDevolucionReserva::instancia = NULL;

CDevolucionReserva::CDevolucionReserva(){}

CDevolucionReserva* CDevolucionReserva::getInstancia(){
    if (instancia == NULL)
        instancia = new CDevolucionReserva();
    return instancia;
}

set<DtReserva> CDevolucionReserva::obtenerReservas(){
    cout << "obtener reservas";
    set<DtReserva> s = {DtReserva::DtReserva()};
    return s;
}

void CDevolucionReserva::cancelarReserva(DtReserva reserva){
    cout << "cancelar reserva";
}