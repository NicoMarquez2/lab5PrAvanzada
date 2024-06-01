#include "tratamiento.h"
#include "fecha.h"

class Quirurgico
{
private:
    Fecha fechaIntervencion;
public:
    Quirurgico(Fecha fecha);
    Quirurgico();
    Fecha getFechaintervencion();
    void setFechaIntervencion(Fecha fecha);
    ~Quirurgico();
};
