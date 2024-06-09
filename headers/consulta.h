#ifndef CONSULTA_H
#define CONSULTA_H

#include <set>
#include <string>
#include <iostream>
#include "../dataTypes/fecha.h"
#include "../dataTypes/hora.h"

class Consulta
{
private:
    Fecha fecha;
    Hora hora;
public:
    Consulta(Fecha f, Hora h);
    Consulta();

    Fecha getFecha();
    Hora getHora();

    void setFecha(Fecha f);
    void setHora(Hora h);

    ~Consulta();
};

#endif