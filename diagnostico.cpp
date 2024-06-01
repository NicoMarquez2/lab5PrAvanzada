#include "diagnostico.h"

using namespace std;

Diagnostico::Diagnostico(string et, string desc, CodDiagnostico* cod){
    this->etiqueta = et;
    this->descripcion = desc;
    this->codigo = cod;
}
Diagnostico::Diagnostico(){
    this->etiqueta = "etiqueta";
    this->descripcion = "";
    this->codigo = 0;
}

string Diagnostico::getEtiqueta(){
    return this->etiqueta;
}    
string Diagnostico::getDescripcion(){
    return this->descripcion;
}
CodDiagnostico* Diagnostico::getCodDiagnostico(){
    return this->codigo;
}