#include "CUsuario.h"

CUsuario* CUsuario::instancia = NULL;

CUsuario::CUsuario(){}

CUsuario* CUsuario::getInstancia(){
    if (instancia == NULL)
        instancia = new CUsuario();
    return instancia;
}

void CUsuario::cargarDatos(map<string, Usuario*> usersCol){
    this->usuarios = usersCol;
}

Usuario* CUsuario::getUser(){
    return this->user;
}

map<string, Usuario*> CUsuario::getUsuarios(){
    return this->usuarios;
}

Usuario* CUsuario::ingresarCedula(string ci){
    cout << "ingresar ci: " << ci << endl;
    map<string, Usuario*>::iterator it;
    it = this->usuarios.find(ci);
    Usuario* u = it->second;
    this->user = u;
    return u;
}
void CUsuario::ingresarDatos(string nombre, string apellido, string sexo, Fecha fechaNacimiento, string categoria){
    cout << "ingresar datos: " << nombre << endl;
}
void CUsuario::activarUsuario(string ci){
    cout << "activar usuario: " << ci << endl;
}
void CUsuario::salir(){
    cout << "salir";
}
bool CUsuario::registrarContrasena(string pass){
    cout << "registrar ci: " << pass << endl;
    return true;
}
bool CUsuario::ingresarContrasena(string pass){
    cout << "ingresar ci: " << pass << endl;
    this->pass = pass;
    return (this->user->esContrasena(pass));
}
void CUsuario::cerrarSesion(){
    cout << "cerrar sesion";
}
void CUsuario::cancelar(){
    cout << "cancelar" ;
}
void CUsuario::obtenerHistorialPaciente(string ci){
    cout << "obtener istorial: " << ci << endl;
}