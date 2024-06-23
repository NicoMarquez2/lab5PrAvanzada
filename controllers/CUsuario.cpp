#include "CUsuario.h"
#include "../headers/socio.h"
#include "../headers/administrativo.h"
#include "../headers/medico.h"

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
    DtUsuario DtU;
    string cat;
    this->ci = ci;
    map<string, Usuario*>::iterator it;
    it = this->usuarios.find(ci);
    if(it != usuarios.end()){
        this->user = it->second;
        if(dynamic_cast<Socio*>(user->getCategoria()))
            cat = "socio";
        if(dynamic_cast<Medico*>(user->getCategoria()))
            cat = "medico";
        if(dynamic_cast<Administrativo*>(user->getCategoria()))
            cat = "administrativo";
        DtU = DtUsuario(user->getContrasena(), user->getNombre(), user->getApellido(), user->getCedula(),
                    user->getSexo(), user->getFechaNacimiento(), user->getActivo(), cat);
    } else {
        DtU = DtUsuario();
    }
    return DtU;
}

DtUsuario CUsuario::ingresarCedulaAlta(string ci){
    DtUsuario DtU;
    string cat;
    this->ci = ci;
    map<string, Usuario*>::iterator it;
    it = this->usuarios.find(ci);
    if(it != usuarios.end()){
        this->user = it->second;
        if(dynamic_cast<Socio*>(user->getCategoria()))
            cat = "socio";
        if(dynamic_cast<Medico*>(user->getCategoria()))
            cat = "medico";
        if(dynamic_cast<Administrativo*>(user->getCategoria()))
            cat = "administrativo";
        DtU = DtUsuario(user->getContrasena(), user->getNombre(), user->getApellido(), user->getCedula(),
                    user->getSexo(), user->getFechaNacimiento(), user->getActivo(), cat);
    } else {
        DtU = DtUsuario();
    }
    return DtU;
}

void CUsuario::ingresarDatos(string nombre, string apellido, string sexo, Fecha fechaNacimiento, string categoria){
    // Verificar si la cédula ha sido establecida previamente
    if (this->ci.empty()) {
        cout << "Error: Cédula no establecida." << endl;
        return;
    }
    CategoriaUsuario* cat;
    if (categoria == "socio")
        cat = new Socio();
    else if(categoria == "medico")
        cat = new Medico();
    else 
        cat = new Administrativo();
    // Crear un nuevo usuario con los datos proporcionados
    Usuario* u = new Usuario(nombre, apellido, this->ci, sexo, fechaNacimiento, false, cat);
    
    // Insertar el nuevo usuario en la colección
    auto result = this->usuarios.insert({this->ci, u});
    
    // Verificar si la inserción fue exitosa
    if (!result.second) {
        // Si la inserción no fue exitosa, significa que ya existe un usuario con la misma cédula
        cout << "Error: Ya existe un usuario con la cédula " << this->ci << endl;
        delete u; // Liberar la memoria del usuario creado
    } else {
        cout << "Usuario con cedula " << this->ci << " ingresado exitosamente." << endl;
    }
}
void CUsuario::activarUsuario(string ci){
    this->user->setActivo(true);
}
void CUsuario::salir(){
    cout << "salir";
    //delete this->user;
    //delete this->userSesion;
}
bool CUsuario::registrarContrasena(string pass){
    cout << "registrar pass: " << pass << endl;
    if (pass.length() >= 6 && pass.length() <= 9){
        this->user->setContrasena(pass);
        this->user->setActivo(true);
    }
    
    return (pass.length() >= 6 && pass.length() <= 9);
}
bool CUsuario::ingresarContrasena(string pass){
    cout << "ingresar pass: " << pass << endl;
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

map<string, DtUsuario> CUsuario::obtenerMedicos(){
    map<string, DtUsuario> setDtU;
    DtUsuario DtU;
    string cat;
    map<string, Usuario*>::iterator it;

    for (it=usuarios.begin(); it!=usuarios.end(); ++it){
        this->user = it->second;
        if(dynamic_cast<Medico*>(user->getCategoria())){
            cat = "medico";
            DtU = DtUsuario(user->getContrasena(), user->getNombre(), user->getApellido(), user->getCedula(),
                    user->getSexo(), user->getFechaNacimiento(), user->getActivo(), cat);
            setDtU.insert({DtU.getCedula(), DtU});
        }
    }    
    return setDtU;
}

vector<DtReserva> CUsuario::obtenerReservasUser(string ci){
    this->ci = ci;
    map<string, Usuario*>::iterator it;
    it = this->usuarios.find(ci);
    if(it != usuarios.end()){}
        this->user = it->second;
    return user->obtenerReservas();
}

vector<DtConsulta> CUsuario::obtenerConsultasUser(string ci){
    this->ci = ci;
    map<string, Usuario*>::iterator it;
    it = this->usuarios.find(ci);
    if(it != usuarios.end()){}
        this->user = it->second;
    return user->obtenerConsultas();
}

map<string, DtDiagnostico> CUsuario::obtenerDiagnosticosConsultaUser(string ci){
    this->ci = ci;
    map<string, Usuario*>::iterator it;
    it = this->usuarios.find(ci);
    if(it != usuarios.end()){}
        this->user = it->second;
    return user->obtenerDiagnosticosConsulta();
}

void CUsuario::setConsultasUser(Usuario* usuario, vector<Consulta*> consultasUser){
    map<string, Usuario*>::iterator it;
    it = this->usuarios.find(usuario->getCedula());
    if(it != usuarios.end())
        it->second->setConsultas(consultasUser);
}

void CUsuario::reservaConsultaUser(Usuario* usuario, Consulta* consultaUser){
    map<string, Usuario*>::iterator it;
    it = this->usuarios.find(usuario->getCedula());
    if(it != usuarios.end())
        it->second->ingresarConsulta(consultaUser);
}

