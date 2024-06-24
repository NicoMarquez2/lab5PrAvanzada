#ifndef FARMACO_H
#define FARMACO_H

#include "tratamiento.h"

using namespace std;

class Farmaco: public Tratamiento
{
private:
    string medicamento;
public:
    Farmaco(string desc, string medic);
    Farmaco();
    string getMedicamento();
    void setMedicamento(string medic);
    ~Farmaco();
};

#endif