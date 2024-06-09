#ifndef REGISCONSULTA_H
#define REGISCONSULTA_H

#include "../interfaces/IRegisConsulta.h"
#include "../dataTypes/Fecha.h"

class CRegisConsulta: public IRegisConsulta
{
private:
    static CRegisConsulta* instancia;
    CRegisConsulta();
public:
    static CRegisConsulta* getInstancia();
    void registroReserva(string ciMed, string ciPac, bool asiste, Fecha fecha, Fecha fechaReserva);
    void registroEmergencia(string ciMed, string ciPac, Fecha fecha, string motivo);
};

#endif