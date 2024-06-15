#ifndef IUSUARIO_H
#define IUSUARIO_H

#include <string.h>
#include "../dataTypes/fecha.h"
#include "../dataTypes/dtUsuario.h"
#include <iostream>
#include "stdio.h"
#include <map>
#include "../headers/usuario.h"
#include "../headers/categoriaUsuario.h"

using namespace std;

class IUsuario
{
public:
    virtual void cargarDatos(map<string, Usuario*> usersCol) = 0;
    virtual DtUsuario ingresarCedula(string ci) = 0;
    virtual void ingresarDatos(string nombre, string apellido, string sexo, Fecha fechaNacimiento, CategoriaUsuario* categoria) = 0;
    virtual void activarUsuario(string ci) = 0;
    virtual void salir() = 0;
    virtual DtUsuario ingresarCedulaAlta(string ci) = 0;
    virtual bool registrarContrasena(string pass) = 0;
    virtual bool ingresarContrasena(string pass) = 0;
    virtual void cerrarSesion() = 0;
    virtual void cancelar() = 0;
    virtual void obtenerHistorialPaciente(string ci) = 0;
};

#endif