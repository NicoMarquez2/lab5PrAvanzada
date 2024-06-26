#ifndef USUARIO_H
#define USUARIO_H

#include <vector>
#include <string>
#include <iostream>
#include "../dataTypes/dtFecha.h"
#include "../headers/categoriaUsuario.h"
#include "../headers/consulta.h"
#include "../headers/reserva.h"
#include "../dataTypes/dtConsulta.h"
#include "../dataTypes/dtReserva.h"
#include "../headers/tratamiento.h"
#include "../headers/farmaco.h"
#include "../headers/quirurgico.h"

using namespace std;
class DtEmergencia;
class DtReserva;
class DtConsulta;

class Usuario
{
private:
    string contrasena;
    string nombre;
    string apellido;
    string cedula;
    string sexo;
    Fecha fechaNacimiento;
    int edad;
    bool activo;
    CategoriaUsuario* categoria;
    Consulta* consulta;
    vector<Consulta*> consultas;
public:
    Usuario(string contrasena, string nombre, string apellido, string cedula, string sexo, Fecha fechaNacimiento, bool activo, CategoriaUsuario* cat);
    Usuario(string nombre, string apellido, string cedula, string sexo, Fecha fechaNacimiento, bool activo, CategoriaUsuario* cat);
    Usuario();

    string getContrasena();
    string getNombre();
    string getApellido();
    string getCedula();
    string getSexo();
    Fecha getFechaNacimiento();
    int getEdad();
    bool getActivo();
    vector<Consulta*> getConsultas();
    CategoriaUsuario* getCategoria();
    bool esContrasena(string pass);
    vector<DtReserva> obtenerReservas();
    vector<DtConsulta> obtenerConsultas();
    map<string, DtConsulta> obtenerDiagnosticosConsultas();

    void setContrasena(string cont);
    void setNombre(string nom);
    void setApellido(string ap);
    void setCedula(string ced);
    void setSexo(string s);
    void setFechaNacimiento(Fecha fecha);
    void setActivo(bool act);
    void setCategoria(CategoriaUsuario* cat);
    void setConsultas(vector<Consulta*> consultasUser);
    void ingresarConsulta(Consulta* consultaUser);

    ~Usuario();
};

#endif
