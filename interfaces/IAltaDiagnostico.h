#ifndef IALTADIAGNOSTICO_H
#define IALTADIAGNOSTICO_H

#include <vector>
#include <string.h>
#include "../dataTypes/fecha.h"
#include "../dataTypes/dtConsulta.h"

using namespace std;

class IAltaDiagnostico
{
public:
   virtual vector<DtConsulta> obtenerConsultas() = 0;
   virtual DtConsulta seleccionarConsulta(string ci) = 0;
   virtual void obtenerCategorias() = 0;
   virtual void seleccionarCategoria(string categoria) = 0;
   virtual void obtenerDiagnosticos() = 0;
   virtual void seleccionarDiagnostico(string diagnostico) = 0;
   virtual void agregarDescripcion(string descripcion) = 0;
   virtual void agregarTratamiento(string descripcion, string tipo) = 0;
   virtual void agregarFecha(Fecha fecha) = 0;
   virtual void agregarMedicamento(string medicamento) = 0;
};

#endif
