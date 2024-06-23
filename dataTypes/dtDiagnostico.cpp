#include "../dataTypes/dtDiagnostico.h"

using namespace std;

DtDiagnostico::DtDiagnostico(DtCodDiagnostico cod, string desc){
    this->descripcion = desc;
    this->codigo = cod;
}
DtDiagnostico::DtDiagnostico(){
    this->descripcion = "";
}
string DtDiagnostico::getDescripcion(){
    return this->descripcion;
}
DtCodDiagnostico DtDiagnostico::getCodDiagnostico(){
    return this->codigo;
}