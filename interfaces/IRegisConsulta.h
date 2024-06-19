#ifndef IREGISCONSULTA_H
#define IREGISCONSULTA_H

#include <string>
#include <iostream>
#include "stdio.h"
#include "../dataTypes/dtFecha.h"

using namespace std;

class IRegisConsulta
{
public:
    virtual void registroReserva(string ciMed, string ciPac, bool asiste, Fecha fecha, Fecha fechaReserva) = 0;
    virtual void registroEmergencia(string ciMed, string ciPac, Fecha fecha, string motivo) = 0;
};

#endif