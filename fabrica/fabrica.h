#ifndef FABRICA_H
#define FABRICA_H

#include "../controllers/CUsuario.h"
#include "../controllers/CConsulta.h"

class Fabrica{
private:
    static Fabrica* instancia;
    Fabrica();
public:
    static Fabrica* getInstancia();
    IUsuario* getIUsuario();
    IConsulta* getIConsulta();
    ~Fabrica();
};

#endif