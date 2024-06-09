#ifndef CCERRARSESION_H
#define CCERRARSESION_H

#include "../interfaces/ICerrarSesion.h"

class CCerrarSesion : public ICerrarSesion
{
private:
    static CCerrarSesion* instancia;
    CCerrarSesion();
public:
    static CCerrarSesion* getInstancia();
    void cerrarSesion();
};

#endif