#ifndef COBTENERHISTORIAL_H
#define COBTENERHISTORIAL_H

#include "../interfaces/IObtenerHistorial.h"

class CObtenerHistorial: public IObtenerHistorial
{
private:
    static CObtenerHistorial* instancia;
    CObtenerHistorial();
public:
    static CObtenerHistorial* getInstancia();
    void obtenerHistorialPaciente(string ci);
};

#endif