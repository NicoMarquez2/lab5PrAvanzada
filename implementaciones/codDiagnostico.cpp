#include "codDiagnostico.h"

CodDiagnostico::CodDiagnostico(int cod){
    this->codigo = cod;
}

CodDiagnostico::CodDiagnostico(){
    this->codigo = 0;
}

int CodDiagnostico::getCodigo(){
    return this->codigo;
}

void CodDiagnostico::setCodigo(int cod){
    this->codigo = cod;
}