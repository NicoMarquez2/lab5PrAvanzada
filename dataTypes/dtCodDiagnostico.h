#ifndef DTCODDIAGNOSTICO_H
#define DTCODDIAGNOSTICO_H

#include <string>
#include <iostream>
#include "../dataTypes/dtFecha.h"
#include "../dataTypes/hora.h"
#include "../headers/diagnostico.h"

using namespace std;

class DtCodDiagnostico
{
private:
    string codCat;
    string cat;
    string codDiag;
    string etiqueta;
public:
    DtCodDiagnostico(string codCat, string cat, string codDiag, string etiqueta);
    DtCodDiagnostico();

    string getCodigoCategoria();
    string getCategoria();
    string getCodigoDiagnostico();
    string getEtiqueta();
    
    ~DtCodDiagnostico();
};

#endif