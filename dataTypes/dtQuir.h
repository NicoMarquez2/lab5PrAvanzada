#ifndef DTQUIR_H
#define DTQUIR_H

#include <string>
#include <iostream>
#include "../dataTypes/dtFecha.h"

using namespace std;

class DtQuir
{
private:
    string descripcion;
    Fecha fechaIntervencion;
public:
    DtQuir(string desc, Fecha fechaInt);
    DtQuir();
    string getDescripcion();
    Fecha getFechaIntervencion();
    ~DtQuir();
};

#endif