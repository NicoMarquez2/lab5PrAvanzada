#ifndef CALTADIAGNOSTICO_H
#define CALTADIAGNOSTICO_H

#include "../interfaces/IAltaDiagnostico.h"

class CAltaDiagnostico: public IAltaDiagnostico
{
private:
    static CAltaDiagnostico* instancia;
    CAltaDiagnostico();
public:
    static CAltaDiagnostico* getInstancia();
    set<DtConsulta> obtenerConsultas();
    DtConsulta seleccionarConsulta(string ci);
    void obtenerCategorias();
    void seleccionarCategoria(string categoria);
    void obtenerDiagnosticos();
    void seleccionarDiagnostico(string diagnostico);
    void agregarDescripcion(string descripcion);
    void agregarTratamiento(string descripcion, string tipo);
    void agregarFecha(Fecha fecha);
    void agregarMedicamento(string medicamento);
};

#endif