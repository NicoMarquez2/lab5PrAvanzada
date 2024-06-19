#ifndef FECHA_H
#define FECHA_H

#include "stdio.h"
#include <string>
#include <iostream>

using namespace std;

class Fecha
{
private:
    int anio;
    int mes;
    int dia;
public:
    Fecha(int a, int m, int d);
    Fecha(const Fecha& f);
    Fecha();
    int getAnio() const;
    int getMes() const;
    int getDia() const;

    bool operator<(const Fecha& other) const {
        if (anio != other.anio) {
            return anio < other.anio;
        }
        if (mes != other.mes) {
            return mes < other.mes;
        }
        return dia < other.dia;
    }

    bool operator!=(const Fecha& other) const {
        return dia != other.dia || mes != other.mes || anio != other.anio;
    }

    ~Fecha();
};

#endif