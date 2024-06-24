#include "../headers/diagnostico.h"

using namespace std;

Diagnostico::Diagnostico(CodDiagnostico* cod, string desc){
    this->descripcion = desc;
    this->codigo = cod;
}
Diagnostico::Diagnostico(){
    this->descripcion = "";
    this->codigo = 0;
}
string Diagnostico::getDescripcion(){
    return this->descripcion;
}
CodDiagnostico* Diagnostico::getCodDiagnostico(){
    return this->codigo;
}
vector<Tratamiento*> Diagnostico::getTratamientos(){
    return this->tratamientos;
}

void Diagnostico::ingresarTratamiento(Tratamiento* t){
    this->tratamientos.push_back(t);
}

Diagnostico::~Diagnostico(){}