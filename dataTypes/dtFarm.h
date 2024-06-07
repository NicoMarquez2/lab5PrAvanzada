#ifndef DTFARM_H
#define DTFARM_H

#include <string>

using namespace std;

class DtFarm
{
private:
    string descripcion;
    string medicamento;
public:
    DtFarm(string desc, string medic);
    string getDescripcion();
    string getMedicamento();
    ~DtFarm();
};

#endif