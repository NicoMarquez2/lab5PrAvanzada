#include "dtFarm.h"

DtFarm::DtFarm(string desc, string medic){
    this->descripcion = desc;
    this->medicamento = medic;
}

DtFarm::~DtFarm(){}

string DtFarm::getDescripcion(){
    return this->descripcion;
}

string DtFarm::getMedicamento(){
    return this->medicamento;
}