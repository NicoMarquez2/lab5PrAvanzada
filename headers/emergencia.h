#ifndef EMERGENCIA_H
#define EMERGENCIA_H

#include <set>
#include <string>
#include <iostream>
#include "consulta.h"

class Emergencia : public Consulta
{
private:
    string motivo;
public:
    Emergencia(Fecha f, Hora h, string mot);
    Emergencia();

    string getMotivo();

    void setMotivo(string mot);

    ~Emergencia();
};

#endif