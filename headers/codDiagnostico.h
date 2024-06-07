#ifndef CODDIAGNOSTICO_H
#define CODDIAGNOSTICO_H

#include "stdio.h"
#include <string>
#include <iostream>

using namespace std;

class CodDiagnostico
{
private:
    int codigo;
public:
    CodDiagnostico(int cod);
    CodDiagnostico();

    int getCodigo();

    void setCodigo(int cod);
    ~CodDiagnostico();
};

#endif