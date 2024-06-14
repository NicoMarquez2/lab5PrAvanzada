#include "stdio.h"
#include <string>
#include <iostream>
#include <map>
#include "fabrica/fabrica.h"
#include "../headers/socio.h"
#include "../headers/medico.h"
#include "../headers/administrativo.h"

using namespace std;

bool isNumber(const string& str) {
    for (char const& c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

bool correcto(string ci) {
    if (!isNumber(ci) || ci.length() != 8)
        return false;
    return true;
}

int main() {
   bool valido = false;
   Fabrica* f;
   IIniciarSesion* iSesion;
   IAltaDiagnostico* iAD;
   IAltaUsuario* iAU;
   ICerrarSesion* ICS;
   IDevolucionReserva* iDR;
   IListarRepresentaciones* iLR;
   IObtenerHistorial* iOH;
   IRegisConsulta* iRG;
   IUsuario* IU;
   Fecha fecha = Fecha(2001, 10, 22);

   Usuario* usuarioSesion = new Usuario();
   map<string, Usuario*> usersCollection;
   Socio* catS = new Socio();
   Medico* catM = new Medico();
   Administrativo* catA = new Administrativo();
   Usuario* pruebaU = new Usuario("contrasena", "Nicolas", "Marquez", "51467384", "masculino", fecha, true, catS);
   Usuario* pruebaM = new Usuario("medico", "medico", "medicoAp", "12345678", "femenino", fecha, true, catM);
   Usuario* pruebaA = new Usuario("admin", "admin", "adminAp", "87654321", "masculino", fecha, true, catA);
   usersCollection.insert({pruebaU->getCedula(), pruebaU});
   usersCollection.insert({pruebaM->getCedula(), pruebaM});
   usersCollection.insert({pruebaA->getCedula(), pruebaA});

   f = Fabrica::getInstancia();
   iSesion = f->getIIniciarSesion();
   iAD = f->getIAltaDiagnostico();
   iAU = f->getIAltaUsuario();
   ICS = f->getICerrarSesion();
   iDR = f->getIDevolucionReserva();
   iLR = f->getIListarRepresentaciones();
   iOH = f->getIObtenerHistorial();
   iRG = f->getIRegisConsulta();
   IU = f->getIUsuario();

   IU->cargarDatos(usersCollection);
   string cedula;
   string pass;
   cout << "\t\tBIENVENIDO\n\n";
   cout << "Iniciar sesion\n";
   cout << "Ingrese su cedula: ";
   while (!valido) {
      cin >> cedula;
      valido = correcto(cedula);
      if (!valido) {
         cout << "cedula invalida\n";
      }
   }

   usuarioSesion = IU->ingresarCedula(cedula);
   cout << "\nCedula del usuario: " << usuarioSesion->getCedula() << endl;
   bool correcto = false;
   if (usuarioSesion->getContrasena() == " ") {
      cout << "Ingrese su contrsena" << endl;
      while (!correcto && pass != "-1") {
         correcto = IU->registrarContrasena(pass);
      }
   } else {
      cout << "Ingrese su contrsena (ingrese -1 si desea cancelar)" << endl;
      while (!correcto && pass != "-1") {
         cin >> pass;
         correcto = IU->ingresarContrasena(pass);
         if (!correcto && pass != "-1")
               cout << "Contrasena incorrecta" << endl;
      }
   }

   if (pass == "-1") {
      return 0;
   }

   if (usuarioSesion->getCedula() != "11111111") {
      bool salir = false;
      int option = 0;
      while (!salir) {
         cout << "\nBienvenido " << usuarioSesion->getNombre() << endl;
         if (dynamic_cast<Socio*>(usuarioSesion->getCategoria())) {
               cout << "Que desea hacer socio?" << endl;
               cout << "1 - Realizar reserva" << endl;
               cout << "2 - Cancelar reserva" << endl;
               cout << "4 - Salir" << endl;
               cin >> option;
               switch (option) {
                  case 1:
                     cout << "Realizar reserva" << endl;
                     break;
                  case 2:
                     cout << "Cancelar reserva" << endl;
                     break;
                  case 3:
                     salir = true;
                     break;
                  default:
                     break;
               }
         } else if (dynamic_cast<Medico*>(usuarioSesion->getCategoria())) {
               cout << "Que desea hacer medico?" << endl;
               cout << "1 - " << endl;
               cout << "2 - " << endl;
               cout << "3 - " << endl;
               cout << "4 - " << endl;
               cout << "5 - Salir medico" << endl;
               cin >> option;
               switch (option) {
                  case 1:
                     cout << "Realizar reserva" << endl;
                     break;
                  case 2:
                     cout << "Cancelar reserva" << endl;
                     break;
                  case 5:
                     salir = true;
                     break;
                  default:
                     break;
               }
         } else if (dynamic_cast<Administrativo*>(usuarioSesion->getCategoria())) {
               string input;
               cout << "Que desea hacer admin?" << endl;
               cout << "1 - Alta/Reactivacion de usuario" << endl;
               cout << "2 - " << endl;
               cout << "3 - " << endl;
               cout << "4 - " << endl;
               cout << "5 - Salir admin" << endl;
               cin >> option;

               string nombre, apellido, sexo, categoria;
               int anio, mes, dia;
               bool encuentra;
               switch (option) {
                  case 1:
                     while (input != "-1") {
                           cout << "Ingrese una cedula (ingrese -1 si desea salir): ";
                           cin >> input;
                           if (input == "-1"){
                              break;
                           }                           
                           encuentra = IU->ingresarCedulaAlta(input);
                           if (!encuentra) {
                              cout << "ingrese el nombre del usuario: ";
                              cin >> nombre;
                              cout << "\ningrese el apellido del usuario: ";
                              cin >> apellido;
                              cout << "\ningrese el sexo del usuario: ";
                              cin >> sexo;
                              cout << "\ningrese el anio, mes y dia de nacimiento del usuario: ";
                              cin >> anio >> mes >> dia;
                              cout << "\ningrese la categoria del usuario: ";
                              cin >> categoria;

                              Fecha fecha(anio, mes, dia);
                              if (categoria == "socio")
                                 IU->ingresarDatos(nombre, apellido, sexo, fecha, catS);
                              else if (categoria == "medico")
                                 IU->ingresarDatos(nombre, apellido, sexo, fecha, catM);
                              else
                                 IU->ingresarDatos(nombre, apellido, sexo, fecha, catA);
                           } else {
                              // Aquí deberías tener una lógica para mostrar los datos del usuario encontrado
                              // cout << "\n Nombre: " << u->getNombre();
                              // cout << "\n Apellido:" << u->getApellido();
                              // cout << "\n Sexo: " << u->getSexo();
                              // cout << "\n Edad: " << u->getEdad();
                              // cout << "\n Activo: " << u->getActivo();
                              // if(dynamic_cast<Administrativo*>(u->getCategoria())){
                              //    cout << "\n Categoria: Administrativo";
                              // } else if(dynamic_cast<Socio*>(u->getCategoria())){
                              //    cout << "\n Categoria: Socio";
                              // } else if(dynamic_cast<Medico*>(u->getCategoria())){
                              //    cout << "\n Categoria: Medico";
                              // }

                              // if(u->getActivo() == false){
                              //    cout << "desea reactivar el usuario?" << endl;
                              //    cout << "1- SI\t\t2- NO";
                              //    cin >> option;

                              //    if(option == 1){
                              //       IU->activarUsuario(u->getCedula());
                              //       cout << "Usuario reactivado";
                              //    }
                              // }
                           }
                     }
                     IU->salir();
                     break;
                  case 2:
                     cout << "Cancelar reserva" << endl;
                     break;
                  case 5:
                     salir = true;
                     break;
                  default:
                     break;
               }
         }
      }
   }

   iAD->agregarDescripcion("descripcion");
   iAU->salir();
   ICS->cerrarSesion();
   return 0;
}