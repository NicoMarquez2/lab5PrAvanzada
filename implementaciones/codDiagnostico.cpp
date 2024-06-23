#include "../headers/codDiagnostico.h"

CodDiagnostico::CodDiagnostico(string codCat, string cat, string codDiag, string etiqueta){
    this->codCat = codCat;
    this->cat = cat;
    this->codDiag = codDiag;
    this->etiqueta = etiqueta;
}

CodDiagnostico::CodDiagnostico(){
    this->codCat = "";
    this->cat = "";
    this->codDiag = "";
    this->etiqueta = "";
}

string CodDiagnostico::getCodigoCategoria(){
    return this->codCat;
}
string CodDiagnostico::getCategoria(){
    return this->cat;
}
string CodDiagnostico::getCodigoDiagnostico(){
    return this->codDiag;
}
string CodDiagnostico::getEtiqueta(){
    return this->etiqueta;
}


void CodDiagnostico::setCodigoCategoria(string codCat){
    this->codCat = codCat;
}

void CodDiagnostico::setCategoria(string cat){
    this->cat = cat;
}

void CodDiagnostico::setCodigoDiagnostico(string codDiag){
    this->codDiag = codDiag;
}

void CodDiagnostico::setEtiqueta(string etiqueta){
    this->etiqueta = etiqueta;
}
