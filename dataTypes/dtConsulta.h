#ifndef DTCONSULTA_H
#define DTCONSULTA_H

#include <string>
#include <iostream>
#include "../dataTypes/dtFecha.h"
#include "../dataTypes/dtDiagnostico.h"
#include "../dataTypes/hora.h"
#include "../headers/usuario.h"

using namespace std;

class DtConsulta
{
private:
    Fecha fecha;
    Hora hora;
    Usuario* paciente;
    Usuario* medico;
    map<string, DtDiagnostico> diagnosticos;
public:
    DtConsulta(Fecha f, Hora h, Usuario* pac, Usuario* med, map<string, DtDiagnostico> diag);
    DtConsulta();
    Fecha getFecha();
    Hora getHora();
    Usuario* getSocio();
    Usuario* getMedico();
    map<string, DtDiagnostico> getDiagnosticos();
    ~DtConsulta();
};

#endif
