#ifndef USUARIO_H
#define USUARIO_H

#include <vector>
#include <string>
#include <iostream>
#include "../dataTypes/fecha.h"
#include "../headers/categoriaUsuario.h"

using namespace std;
class DtEmergencia;
class DtReserva;

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
public:
    Usuario(string contrasena, string nombre, string apellido, string cedula, string sexo, Fecha fechaNacimiento, bool activo);
    Usuario(string nombre, string apellido, string cedula, string sexo, Fecha fechaNacimiento, bool activo);
    Usuario();

    string getContrasena();
    string getNombre();
    string getApellido();
    string getCedula();
    string getSexo();
    Fecha getFechaNacimiento();
    int getEdad();
    bool getActivo();
    bool esContrasena(string pass);
    vector<DtReserva> getReservas();

    void setContrasena(string cont);
    void setNombre(string nom);
    void setApellido(string ap);
    void setCedula(string ced);
    void setSexo(string s);
    void setFechaNacimiento(Fecha fecha);
    void setActivo(bool act);
    void borrarReserva(DtReserva reserva);
    void agregarReserva(DtReserva reserva);
    void agregarEmergencia(DtEmergencia emergencia);

    ~Usuario();
};

#endif
