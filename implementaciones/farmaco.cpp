#include "../headers/farmaco.h"

Farmaco::Farmaco(){
    this->medicamento = "Medicamento";
}

Farmaco::Farmaco(string desc, string medic): 
    Tratamiento(desc), medicamento(medic){}

string Farmaco::getMedicamento(){
    return this->medicamento;
}

void Farmaco::setMedicamento(string medic){
    this->medicamento = medic;
}
Farmaco::~Farmaco(){}