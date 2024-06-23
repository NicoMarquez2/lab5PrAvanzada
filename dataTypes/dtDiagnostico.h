#ifndef DTDIAGNOSTICO_H
#define DTDIAGNOSTICO_H

#include "../headers/codDiagnostico.h"
#include "../headers/tratamiento.h"
#include "../dataTypes/dtCodDiagnostico.h"
#include "stdio.h"
#include <string>
#include <iostream>

using namespace std;

class DtDiagnostico
{
private:
    DtCodDiagnostico codigo;
    string descripcion;
public:
    DtDiagnostico(DtCodDiagnostico cod, string desc);
    DtDiagnostico();

    string getDescripcion();
    DtCodDiagnostico getCodDiagnostico();

    void setDescripcion();
    void setCodigo();
    ~DtDiagnostico();
};

#endif
