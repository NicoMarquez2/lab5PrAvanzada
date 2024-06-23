#ifndef CCONSULTA_H
#define CCONSULTA_H

#include <vector>
#include <map>
#include "../interfaces/IConsulta.h"
#include "../headers/consulta.h"
#include "../headers/diagnostico.h"
#include "../headers/codDiagnostico.h"
#include "../headers/reserva.h"
#include "../headers/emergencia.h"
#include "CUsuario.h"

class CConsulta : public IConsulta
{
private:
    static CConsulta* instancia;
    CConsulta();
    vector<Consulta*> consultas;
    map<string, Diagnostico*> diagnosticos;
    vector<CodDiagnostico*> codigos;
    
public:
    static CConsulta* getInstancia();
    void cargarDatos(vector<Consulta*> consultas, map<string, Diagnostico*> diagnosticos, vector<CodDiagnostico*> codigos);
    void cargarDatos(vector<CodDiagnostico*> codigos);
    vector<Consulta*> getConsultas();
    map<string, Diagnostico*> getDiagnosticos();
    vector<CodDiagnostico*> getCodigos();

    void reservaConsulta(Fecha f, Hora h, string ciSoc, string ciMed);

    void setConsultas(vector<Consulta*> consultas);
    void setDiagnosticos(map<string, Diagnostico*> diagnosticos);
    void setCodigos(vector<CodDiagnostico*> codigos);

    vector<DtConsulta> obtenerConsultas();
    vector<DtCodDiagnostico> obtenerCodDiagnosticos();
    DtConsulta seleccionarConsulta(string ci);
    map<string, DtDiagnostico> obtenerDiagnosticos();

    void obtenerCategorias();
    void seleccionarCategoria(string categoria);
    void seleccionarDiagnostico(string diagnostico);
    void agregarDescripcion(string descripcion);
    void agregarTratamiento(string descripcion, string tipo);
    void agregarFecha(Fecha fecha);
    void agregarMedicamento(string medicamento);
    void registroReserva(string ciMed, string ciPac, Fecha fecha, Fecha fechaReserva);
    void registroEmergencia(string ciMed, string ciPac, Fecha fecha, string motivo);
    void listarRepresentacionesEstandarizadas();
    void altaDiagnostico(string ciPac, string ciMed, string codCat, string codDiag, string desc);
};

#endif