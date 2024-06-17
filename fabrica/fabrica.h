#ifndef FABRICA_H
#define FABRICA_H
#include "../controllers/CIniciarSesion.h"
#include "../controllers/CAltaDiagnostico.h"
#include "../controllers/CAltaUsuario.h"
#include "../controllers/CCerrarSesion.h"
#include "../controllers/CDevolucionReserva.h"
#include "../controllers/CListarRepresentaciones.h"
#include "../controllers/CObtenerHistorial.h"
#include "../controllers/CRegisConsulta.h"
#include "../controllers/CUsuario.h"
#include "../controllers/CConsulta.h"

class Fabrica{
private:
    static Fabrica* instancia;
    Fabrica();
public:
    static Fabrica* getInstancia();
    IIniciarSesion* getIIniciarSesion();
    IAltaDiagnostico* getIAltaDiagnostico();
    IAltaUsuario* getIAltaUsuario();
    ICerrarSesion* getICerrarSesion();
    IDevolucionReserva* getIDevolucionReserva();
    IListarRepresentaciones* getIListarRepresentaciones();
    IObtenerHistorial* getIObtenerHistorial();
    IRegisConsulta* getIRegisConsulta();
    IUsuario* getIUsuario();
    IConsulta* getIConsulta();
    ~Fabrica();
};

#endif