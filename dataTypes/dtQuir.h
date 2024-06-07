#include <string>
#include <iostream>
#include "fecha.h"

using namespace std;

class DtQuir
{
private:
    string descripcion;
    Fecha fechaIntervencion;
public:
    DtQuir(string desc, Fecha fechaInt);
    string getDescripcion();
    Fecha getFechaIntervencion();
    ~DtQuir();
};