#ifndef CODDIAGNOSTICO_H
#define CODDIAGNOSTICO_H

#include "stdio.h"
#include <string>
#include <map>
#include <iostream>

using namespace std;

class CodDiagnostico
{
private:
    string codCat;
    string cat;
    string codDiag;
    string etiqueta;
public:
    CodDiagnostico(string codCat, string cat, string codDiag, string etiqueta);
    CodDiagnostico();

    string getCodigoCategoria();
    string getCategoria();
    string getCodigoDiagnostico();
    string getEtiqueta();

    void setCodigoCategoria(string cod);
    void setCategoria(string cat);
    void setCodigoDiagnostico(string codDiag);
    void setEtiqueta(string etiqueta);
    ~CodDiagnostico();
};

#endif