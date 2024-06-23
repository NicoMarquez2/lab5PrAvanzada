#ifndef CUSUARIO_H
#define CUSUARIO_H

#include <map>
#include <set>
#include "../interfaces/IUsuario.h"
#include "../dataTypes/dtFecha.h"
#include "../headers/usuario.h"

class CUsuario : public IUsuario
{
private:
    static CUsuario* instancia;
    CUsuario();
    Usuario* userSesion;
    Usuario* user;
    string ci;
    string pass;
    map<string, Usuario*> usuarios;
public:
    static CUsuario* getInstancia();
    void cargarDatos(map<string, Usuario*> usersCol);
    Usuario* getUser();
    map<string, Usuario*> getUsuarios();
    DtUsuario ingresarCedula(string ci);

    vector<DtReserva> obtenerReservasUser(string ci);
    vector<DtConsulta> obtenerConsultasUser(string ci);
    map<string, DtConsulta> obtenerDiagnosticosConsultaUser(string ci);

    void ingresarDatos(string nombre, string apellido, string sexo, Fecha fechaNacimiento, string categoria);
    void activarUsuario(string ci);
    void salir();
    DtUsuario ingresarCedulaAlta(string ci);
    bool registrarContrasena(string pass);
    bool ingresarContrasena(string pass);
    void cerrarSesion();
    void cancelar();
    void obtenerHistorialPaciente(string ci);
    map<string, DtUsuario> obtenerMedicos();

    void setConsultasUser(Usuario* usuario, vector<Consulta*> consultasUser);
    void reservaConsultaUser(Usuario* usuario, Consulta* consultaUser);
    
};

#endif