#include <string>
#include <iostream>

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