#ifndef CONSULTA_H
#define CONSULTA_H

#include <set>
#include <string>
#include <iostream>
#include "../dataTypes/dtFecha.h"
#include "../dataTypes/hora.h"
#include "../headers/diagnostico.h"

class Usuario;

class Consulta
{
private:
    Fecha fecha;
    Hora hora;
    Usuario* socio;
    Usuario* medico;
    map<string, Diagnostico*> Diagnosticos; 
public:
    Consulta(Fecha f, Hora h, Usuario* soc, Usuario* med);
    Consulta(Fecha f, Hora h, Usuario* soc);
    Consulta();

    Fecha getFecha();
    Hora getHora();
    Usuario* getSocio();
    Usuario* getMedico();
    map<string, Diagnostico*> getDiagnosticos();

    void setFecha(Fecha f);
    void setHora(Hora h);
    void setSocio(Usuario* soc);
    void setMedico(Usuario* med);
    void setDiagnosticos(map<string, Diagnostico*> diag);

    void agregarDiagnostico(Diagnostico* diag);

    
    virtual ~Consulta();
};

#endif