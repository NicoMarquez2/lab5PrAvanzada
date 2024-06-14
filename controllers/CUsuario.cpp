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
    this->userSesion = u;
    return u;
}

bool CUsuario::ingresarCedulaAlta(string ci){
    this->ci = ci;
    map<string, Usuario*>::iterator it;
    it = this->usuarios.find(ci);
    if(it != usuarios.end()){
        this->user = it->second;
        return true;
    } else {
        return false;
    }
}

void CUsuario::ingresarDatos(string nombre, string apellido, string sexo, Fecha fechaNacimiento, CategoriaUsuario* categoria){
    Usuario* u = new Usuario(nombre, apellido, this->ci, sexo, fechaNacimiento, false, categoria);
    this->usuarios.insert({this->ci,u});
}
void CUsuario::activarUsuario(string ci){
    this->user->setActivo(true);
}
void CUsuario::salir(){
    cout << "salir";
    delete this->user;
}
bool CUsuario::registrarContrasena(string pass){
    cout << "registrar ci: " << pass << endl;
    return true;
}
bool CUsuario::ingresarContrasena(string pass){
    cout << "ingresar ci: " << pass << endl;
    this->pass = pass;
    return (this->userSesion->esContrasena(pass));
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