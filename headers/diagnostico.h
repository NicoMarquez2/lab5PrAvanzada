#include "codDiagnostico.h"
#include "tratamiento.h"
#include "stdio.h"
#include <string>
#include <iostream>

using namespace std;

class Diagnostico
{
private:
    string etiqueta;
    string descripcion;
    CodDiagnostico *codigo;
public:
    Diagnostico(string eti, string desc, CodDiagnostico* cod);
    Diagnostico();

    string getEtiqueta();
    string getDescripcion();
    CodDiagnostico* getCodDiagnostico();

    void setEtiqueta();
    void setDescripcion();
    void setCodigo();
    ~Diagnostico();
};
