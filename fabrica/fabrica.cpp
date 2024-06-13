#include "fabrica.h"

Fabrica* Fabrica::instancia = NULL;

Fabrica::Fabrica(){}

Fabrica* Fabrica::getInstancia(){
    if (instancia == NULL)
        instancia = new Fabrica();
    return instancia;
}

IIniciarSesion* Fabrica::getIIniciarSesion(){
    return CIniciarSesion::getInstancia();
}

IAltaDiagnostico* Fabrica::getIAltaDiagnostico(){
    return CAltaDiagnostico::getInstancia();
}

IAltaUsuario* Fabrica::getIAltaUsuario(){
    return CAltaUsuario::getInstancia();
}

ICerrarSesion* Fabrica::getICerrarSesion(){
    return CCerrarSesion::getInstancia();
}

IDevolucionReserva* Fabrica::getIDevolucionReserva(){
    return CDevolucionReserva::getInstancia();
}

IObtenerHistorial* Fabrica::getIObtenerHistorial(){
    return CObtenerHistorial::getInstancia();
}

IRegisConsulta* Fabrica::getIRegisConsulta(){
    return CRegisConsulta::getInstancia();
}

IListarRepresentaciones* Fabrica::getIListarRepresentaciones(){
    return CListarRepresentaciones::getInstancia();
}

IUsuario* Fabrica::getIUsuario(){
    return CUsuario::getInstancia();
}

Fabrica::~Fabrica(){}