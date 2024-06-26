#ifndef ICONSULTA_H
#define ICONSULTA_H

#include <string>
#include <vector>
#include "../dataTypes/dtConsulta.h"
#include "../dataTypes/dtCodDiagnostico.h"
#include "../dataTypes/dtDiagnostico.h"
#include "../dataTypes/dtFecha.h"
#include "../dataTypes/hora.h"

class IConsulta
{
public:
    virtual void cargarDatos(vector<Consulta*> consultas, map<string, Diagnostico*> diagnosticos, vector<CodDiagnostico*> codigos, vector<Tratamiento*> tratamientos) = 0;
    virtual void cargarConsultas(vector<Consulta*> consultas) = 0;
    virtual void cargarDiagnosticos(map<string, Diagnostico*> diagnosticos) = 0;
    virtual void cargarCodigos(vector<CodDiagnostico*> codigos) = 0;
    virtual vector<DtConsulta> obtenerConsultas() = 0;
    virtual vector<DtCodDiagnostico> obtenerCodDiagnosticos() = 0;
    virtual DtConsulta seleccionarConsulta(string ci) = 0;
    virtual map<string, DtDiagnostico> obtenerDiagnosticos() = 0;
    virtual void reservaConsulta(Fecha f, Hora h, string ciSoc, string ciMed) = 0;
    virtual void obtenerCategorias() = 0;
    virtual void seleccionarCategoria(string categoria) = 0;
    virtual void seleccionarDiagnostico(string diagnostico) = 0;
    virtual void agregarDescripcion(string descripcion) = 0;
    virtual void agregarTratamiento(string descripcion, string tipo, string med, Fecha fechaQ) = 0;
    virtual void agregarFecha(Fecha fecha) = 0;
    virtual void agregarMedicamento(string medicamento) = 0;
    virtual void registroReserva(string ciMed, string ciPac, Fecha fecha, Fecha fechaReserva) = 0;
    virtual void registroEmergencia(string ciMed, string ciPac, Fecha fecha, string motivo) = 0;
    virtual void listarRepresentacionesEstandarizadas() = 0;
    virtual void altaDiagnostico(string ciPac, string ciMed, string codCat, string codDiag, string desc) = 0;
};

#endif