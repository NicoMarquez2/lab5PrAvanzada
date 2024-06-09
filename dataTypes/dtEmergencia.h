#ifndef DTEMERGENCIA_H
#define DTEMERGENCIA_H

#include <string>
#include <iostream>
#include "../dataTypes/fecha.h"
#include "../dataTypes/hora.h"
#include "../headers/usuario.h"

using namespace std;

class DtEmergencia
{
private:
    Fecha fecha;
    Hora hora;
    string motivo;
    Usuario* paciente;
    Usuario* medico;
public:
    DtEmergencia(Fecha f, Hora h, string mot, Usuario* pac, Usuario* med);
    Fecha getFecha();
    Hora getHora();
    string getMotivo();
    Usuario* getSocio();
    Usuario* getMedico();
    ~DtEmergencia();
};

#endif