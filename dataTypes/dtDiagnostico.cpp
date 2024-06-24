#include "../dataTypes/dtDiagnostico.h"

using namespace std;

DtDiagnostico::DtDiagnostico(DtCodDiagnostico cod, string desc){
    this->descripcion = desc;
    this->codigo = cod;
}

DtDiagnostico::DtDiagnostico(DtCodDiagnostico cod, string desc, vector<DtQuir> quir){
    this->descripcion = desc;
    this->codigo = cod;
    this->quirurjico = quir;
}

DtDiagnostico::DtDiagnostico(DtCodDiagnostico cod, string desc, vector<DtFarm> farm){
    this->descripcion = desc;
    this->codigo = cod;
    this->farmacologico = farm;
}

DtDiagnostico::DtDiagnostico(){
    this->descripcion = "";
}

vector<DtQuir> DtDiagnostico::getQuirurjico(){
    return this->quirurjico;
}
vector<DtFarm> DtDiagnostico::getFarmacologico(){
    return this->farmacologico;
}

string DtDiagnostico::getDescripcion(){
    return this->descripcion;
}
DtCodDiagnostico DtDiagnostico::getCodDiagnostico(){
    return this->codigo;
}

DtDiagnostico::~DtDiagnostico(){}