#ifndef DTCONSULTA_H
#define DTCONSULTA_H

#include <string>
#include <iostream>
#include "fecha.h"
#include "hora.h"
#include "usuario.h"

using namespace std;

class DtConsulta
{
private:
    Fecha fecha;
    Hora hora;
    Usuario* paciente;
    Usuario* medico;
public:
    DtConsulta(Fecha f, Hora h, Usuario* pac, Usuario* med);
    Fecha getFecha();
    Hora getHora();
    Usuario* getSocio();
    Usuario* getMedico();
    ~DtConsulta();
};

#endif
