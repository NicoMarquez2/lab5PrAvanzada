#ifndef USUARIOSOCIO_H
#define USUARIOSOCIO_H

#include "categoriaUsuario.h"
#include "usuario.h"
#include "../dataTypes/dtConsulta.h"
#include "../dataTypes/dtReserva.h"
#include "../dataTypes/dtEmergencia.h"
#include "../headers/consulta.h"
#include "../headers/reserva.h"
#include "../headers/emergencia.h"
#include "../headers/usuarioSocio.h"
#include <vector>

class UsuarioSocio
{
private:
    Usuario* usuario;
    vector<Consulta*> consultas; 
public:
    UsuarioSocio();
    UsuarioSocio(Usuario* u);
    Usuario* getUsuario();
    vector<DtConsulta> getConsultas();
    vector<DtReserva> getReservas();
    void setConsultas(vector<Consulta*>);
    void borrarReserva(DtReserva reserva);
    void agregarReserva(DtReserva reserva);
    void agregarEmergencia(DtEmergencia emergencia);
    void setUsuario(Usuario* u);
    ~UsuarioSocio();
};

#endif