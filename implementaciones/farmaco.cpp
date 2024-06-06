#include "farmaco.h"

Farmaco::Farmaco(string medic){
    this->medicamento = medic;
}

Farmaco::Farmaco(){
    this->medicamento = "Medicamento"
}

string Farmaco::getMedicamento(){
    return this->medicamento;
}

void Farmaco::setMedicamento(string medic){
    this->medicamento = medic;
}