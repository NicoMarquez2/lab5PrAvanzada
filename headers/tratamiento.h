#ifndef TRATAMIENTO_H
#define TRATAMIENTO_H

#include "stdio.h"
#include <string>
#include <iostream>

using namespace std;

class Tratamiento
{
private:
    string descripcion;
public:
    Tratamiento(string desc);
    Tratamiento();
    string getDescripcion();

    void setDescripcion(string desc);
    ~Tratamiento();
};

#endif