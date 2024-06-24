#ifndef DIAGNOSTICO_H
#define DIAGNOSTICO_H

#include "codDiagnostico.h"
#include "tratamiento.h"
#include "stdio.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Diagnostico
{
private:
    CodDiagnostico *codigo;
    string descripcion;
    vector<Tratamiento*> tratamientos;
public:
    Diagnostico(CodDiagnostico* cod, string desc);
    Diagnostico();

    string getDescripcion();
    CodDiagnostico* getCodDiagnostico();
    vector<Tratamiento*> getTratamientos();

    void ingresarTratamiento(Tratamiento* t);

    void setDescripcion();
    void setCodigo();
    ~Diagnostico();
};

#endif
