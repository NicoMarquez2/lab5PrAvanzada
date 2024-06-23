#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H

#include "codDiagnostico.h"
#include "tratamiento.h"
#include "stdio.h"
#include <string>
#include <iostream>

using namespace std;

class Diagnostico
{
private:
    CodDiagnostico *codigo;
    string descripcion;
public:
    Diagnostico(CodDiagnostico* cod, string desc);
    Diagnostico();

    string getDescripcion();
    CodDiagnostico* getCodDiagnostico();

    void setDescripcion();
    void setCodigo();
    ~Diagnostico();
};

#endif
