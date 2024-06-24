#ifndef DTDIAGNOSTICO_H
#define DTDIAGNOSTICO_H

#include "../headers/codDiagnostico.h"
#include "../headers/tratamiento.h"
#include "../dataTypes/dtCodDiagnostico.h"
#include "../dataTypes/dtQuir.h"
#include "../dataTypes/dtFarm.h"
#include "stdio.h"
#include <string>
#include <iostream>

using namespace std;

class DtDiagnostico
{
private:
    DtCodDiagnostico codigo;
    string descripcion;
    vector<DtQuir> quirurjico;
    vector<DtFarm> farmacologico;

public:
    DtDiagnostico(DtCodDiagnostico cod, string desc);
    DtDiagnostico(DtCodDiagnostico cod, string desc, vector<DtQuir> quir);
    DtDiagnostico(DtCodDiagnostico cod, string desc, vector<DtFarm> farm);
    DtDiagnostico();

    string getDescripcion();
    DtCodDiagnostico getCodDiagnostico();
    vector<DtQuir> getQuirurjico();
    vector<DtFarm> getFarmacologico();

    void setDescripcion();
    void setCodigo();
    ~DtDiagnostico();
};

#endif
