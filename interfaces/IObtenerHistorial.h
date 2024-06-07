#ifndef IOBTENERHISTORIAL_H
#define IOBTENERHISTORIAL_H

#include <string>

using namespace std;

class IObtenerHistorial
{
public:
    virtual void obtenerHistorialPaciente(string ci) = 0;
};

#endif