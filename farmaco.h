#include "tratamiento.h"

class Farmaco: public Tratamiento
{
private:
    string medicamento;
public:
    Farmaco(string medic);
    Farmaco();
    string getMedicamento();
    void setMedicamento(string medic);
    ~Farmaco();
};