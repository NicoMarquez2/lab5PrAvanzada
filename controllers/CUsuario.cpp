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

DtUsuario CUsuario::ingresarCedula(string ci){
    cout << "ingresar ci: " << ci << endl;
    map<string, Usuario*>::iterator it;
    DtUsuario DtU;
    it = this->usuarios.find(ci);
    if (it != usuarios.end()) {
        Usuario* u = it->second;
        this->userSesion = u;
        DtU = DtUsuario(u->getContrasena(), u->getNombre(), u->getApellido(), u->getCedula(),
                        u->getSexo(), u->getFechaNacimiento(), u->getActivo(), u->getCategoria());
    } else {
        DtU = DtUsuario();
    }
    return DtU;
}

DtUsuario CUsuario::ingresarCedulaAlta(string ci){
    DtUsuario DtU;
    this->ci = ci;
    map<string, Usuario*>::iterator it;
    it = this->usuarios.find(ci);
    if(it != usuarios.end()){
        this->user = it->second;
        DtU = DtUsuario(user->getContrasena(), user->getNombre(), user->getApellido(), user->getCedula(),
                    user->getSexo(), user->getFechaNacimiento(), user->getActivo(), user->getCategoria());
    } else {
        DtU = DtUsuario();
    }
    return DtU;
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
    return (pass.length() >= 6 && pass.length() <= 9);
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