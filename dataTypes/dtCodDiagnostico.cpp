#include "../dataTypes/dtCodDiagnostico.h"
#include "dtCodDiagnostico.h"

DtCodDiagnostico::DtCodDiagnostico(string codCat, string cat, string codDiag, string etiqueta){
    this->codCat = codCat;
    this->cat = cat;
    this->codDiag = codDiag;
    this->etiqueta = etiqueta;
}

DtCodDiagnostico::DtCodDiagnostico(){
    this->codCat = "";
    this->cat = "";
    this->codDiag = "";
    this->etiqueta = "";
}

string DtCodDiagnostico::getCodigoCategoria(){
    return this->codCat;
}
string DtCodDiagnostico::getCategoria(){
    return this->cat;
}
string DtCodDiagnostico::getCodigoDiagnostico(){
    return this->codDiag;
}
string DtCodDiagnostico::getEtiqueta(){
    return this->etiqueta;
}
DtCodDiagnostico::~DtCodDiagnostico(){}