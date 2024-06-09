#ifndef CLISTARREPRESENTACIONES_H
#define CLISTARREPRESENTACIONES_H

#include "../interfaces/IListarRepresentaciones.h"

class CListarRepresentaciones: public IListarRepresentaciones
{
private:
    static CListarRepresentaciones* instancia;
    CListarRepresentaciones();
public:
    static CListarRepresentaciones* getInstancia();
    void listarRepresentacionesEstandarizadas();
};

#endif