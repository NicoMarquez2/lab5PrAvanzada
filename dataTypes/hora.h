#ifndef HORA_H
#define HORA_H

#include "stdio.h"
#include <string>
#include <iostream>

using namespace std;

class Hora
{
private:
    int horas;
    int minutos;
public:
    Hora();
    Hora(int h, int m);
    int getHoras();
    int getMinutos();
    ~Hora();
};

#endif
