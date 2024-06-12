#ifndef CONSULTAMEDICO_H
#define CONSULTAMEDICO_H

#include "medico.h"
#include "consulta.h"

class ConsultaMedico
{
private:
    Medico* medico;
    Consulta* consulta;
public:
    ConsultaMedico(Medico* med, Consulta* cons);
    ConsultaMedico();
    
    Medico* getMedico();
    Consulta* getConsulta();

    void setMedico(Medico* med);
    void setConsulta(Consulta* cons);
    ~ConsultaMedico();
};

#endif