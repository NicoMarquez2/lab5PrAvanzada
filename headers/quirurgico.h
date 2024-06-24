#ifndef QUIRURGICO_H
#define QUIRURGICO_H

#include "tratamiento.h"
#include "../dataTypes/dtFecha.h"

class Quirurgico: public Tratamiento
{
private:
    Fecha fechaIntervencion;
public:
    Quirurgico(string desc, Fecha fecha);
    Quirurgico();
    Fecha getFechaintervencion();
    void setFechaIntervencion(Fecha fecha);
    ~Quirurgico();
};

#endif
