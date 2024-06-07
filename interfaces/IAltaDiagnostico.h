#ifndef IALTADIAGNOSTICO_H
#define IALTADIAGNOSTICO_H

#include <set>
#include <string.h>
#include "fecha.h"
#include "dtConsulta.h"

using namespace std;

class IAltaDiagnostico
{
public:
   set<DtConsulta> obtenerConsultas();
   DtConsulta seleccionarConsulta(string ci);
/*+

+seleccionarConsulta(ci: string): Consulta

+obtenerCategorias()

+seleccionarCategoria(categoria: string)

+obtenerDiagnosticos()

+seleccionarDiagnostico(diagnostico: string)

+agregarDescripcion(descripcion: string)

+agregarTratamiento(descripcion: string, tipo: string)

+agregarFecha(fecha: DtFecha)

+agregarMedicamento(medicamento: string)*/
};

#endif
