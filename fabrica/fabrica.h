#ifndef FABRICA_H
#define FABRICA_H
#include "../controllers/CIniciarSesion.h"

class Fabrica{
private:
    static Fabrica* instancia;
    Fabrica();
public:
    static Fabrica* getInstancia();
    IIniciarSesion* getIIniciarSesion();
    ~Fabrica();
};

#endif