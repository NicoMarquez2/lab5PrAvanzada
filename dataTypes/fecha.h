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
    ~Fecha();
};