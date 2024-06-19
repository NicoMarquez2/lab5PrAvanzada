#ifndef DtUsuario_H
#define DtUsuario_H

#include <vector>
#include <string>
#include <iostream>
#include "../dataTypes/dtFecha.h"
#include "../headers/categoriaUsuario.h"

using namespace std;
class DtEmergencia;
class DtReserva;

class DtUsuario
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
    string categoria;
public:
    DtUsuario(string cont, string nom, string ap, string ced,
                string s, Fecha fechaNac, bool activo, string cat);
    DtUsuario();
    string getContrasena();
    string getNombre();
    string getApellido();
    string getCedula();
    string getSexo();
    Fecha getFechaNacimiento();
    int getEdad();
    bool getActivo();
    string getCategoria();

    bool operator<(const DtUsuario& other) const {
        if (cedula != other.cedula) {
            return cedula < other.cedula;
        }
        if (nombre != other.nombre) {
            return nombre < other.nombre;
        }
        if (apellido != other.apellido) {
            return apellido < other.apellido;
        }
        if (sexo != other.sexo) {
            return sexo < other.sexo;
        }
        if (fechaNacimiento != other.fechaNacimiento) {
            return fechaNacimiento < other.fechaNacimiento;
        }
        if (edad != other.edad) {
            return edad < other.edad;
        }
        if (activo != other.activo) {
            return !activo; // Assuming false < true
        }
        return categoria < other.categoria;
    }

    std::string getNombre() const { return nombre; }
    std::string getApellido() const { return apellido; }
    std::string getCedula() const { return cedula; }
    std::string getSexo() const { return sexo; }
    Fecha getFechaNacimiento() const { return fechaNacimiento; }
    int getEdad() const { return edad; }
    bool getActivo() const { return activo; }
    std::string getCategoria() const { return categoria; }

    ~DtUsuario();
};

#endif