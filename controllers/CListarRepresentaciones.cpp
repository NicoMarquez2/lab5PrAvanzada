#include "CListarRepresentaciones.h"

CListarRepresentaciones* CListarRepresentaciones::instancia = NULL;

CListarRepresentaciones::CListarRepresentaciones(){}

CListarRepresentaciones* CListarRepresentaciones::getInstancia(){
    if (instancia == NULL)
        instancia = new CListarRepresentaciones();
    return instancia;
}

void CListarRepresentaciones::listarRepresentacionesEstandarizadas(){
    cout << "Listar representaciones";
}