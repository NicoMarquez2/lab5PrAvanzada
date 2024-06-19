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
   Fabrica* f;
   IUsuario* IU;
   IConsulta* IC;
   Fecha fecha = Fecha(2001, 10, 22);

   map<string, Usuario*> usersCollection;
   Socio* catS = new Socio();
   Medico* catM = new Medico();
   Administrativo* catA = new Administrativo();
   Usuario* pruebaU = new Usuario("contrasena", "Nicolas", "Marquez", "51467384", "masculino", fecha, true, catS);
   Usuario* pruebaM = new Usuario("medico", "medico", "medicoAp", "12345678", "femenino", fecha, true, catM);
   Usuario* pruebaM2 = new Usuario("medico", "medico", "medicoAp2", "12345679", "femenino", fecha, true, catM);
   Usuario* pruebaA = new Usuario("admin", "admin", "adminAp", "87654321", "masculino", fecha, true, catA);
   usersCollection.insert({pruebaU->getCedula(), pruebaU});
   usersCollection.insert({pruebaM->getCedula(), pruebaM});
   usersCollection.insert({pruebaM2->getCedula(), pruebaM2});
   usersCollection.insert({pruebaA->getCedula(), pruebaA});

   f = Fabrica::getInstancia();
   IU = f->getIUsuario();
   IC = f->getIConsulta();

   DtUsuario usuarioSesion = DtUsuario();
   string cedula = "-1";
   string pass;
   bool salir = false;
   bool cedulaValida = false;
   bool passCorrecto = false;
   bool datosCargados = false;
   int opcion = -1;
   cout << "\t\tBIENVENIDO\n\n";
   while (!salir){
      cout << "Que desea hacer?\n";
      cout << "0- Cargar datos\n";
      cout << "1- Iniciar sesion\n";
      cout << "2- Salir\n";
      cin >> opcion;
      switch (opcion){
      case  0:
         if(!datosCargados){        
            IU->cargarDatos(usersCollection);
            datosCargados = true;  
         } else {
            cout << "\nLos datos ya fueron cargados" << endl;
         }
         break;
      
      case 1:
         cout << "Ingrese su cedula: ";
         while (!cedulaValida) {
            cin >> cedula;
            cedulaValida = correcto(cedula);
            if (!cedulaValida) {
               cout << "cedula invalida\n";
            }
         }
         usuarioSesion = IU->ingresarCedula(cedula);
         if(usuarioSesion.getCedula() == "11111111"){
            cout << "\n\n USUARIO NO ENCONTRADO\n\n";
            cedula = "-1";
            cedulaValida = false;
            break;
         } else {
            cout << "\n\n USUARIO SESION NOMBRE: " << usuarioSesion.getNombre() <<"\t\tCEDULA: " << usuarioSesion.getCedula() << "\n\n";
         }

         if (usuarioSesion.getContrasena() == " ") {
            cout << "Ingrese su contrsena (ingrese -1 si desea cancelar)\n" << endl;
            while (!passCorrecto) {
               cin >> pass;
               if(pass == "-1"){
                  usuarioSesion = DtUsuario();
                  cedula = "-1";
                  cedulaValida = false;
                  passCorrecto = false;
                  break;
               }
               passCorrecto = IU->registrarContrasena(pass);
               if (!passCorrecto)
                     cout << "Contrasena invalida\n" << endl;
            }
            pass = "";
         } else {
            while (!passCorrecto) {
               cout << "Ingrese su contrasena (ingrese -1 si desea cancelar)\n" << endl;
               cin >> pass;
               if(pass == "-1"){
                  usuarioSesion = DtUsuario();
                  cedula = "-1";
                  cedulaValida = false;
                  passCorrecto = false;
                  break;
               }
               passCorrecto = IU->ingresarContrasena(pass);
               if (!passCorrecto)
                     cout << "Contrasena incorrecta\n" << endl;
            }
            pass = "";
         }
         break;
      
      case 2:
         salir = true;
         break;

      default:
         cout << "\nOpcion invalida\n\n";
         break;
      }

      if (usuarioSesion.getCedula() != "11111111") {
         bool salirSesion = false;
         int option = 0;
         while (!salirSesion) {
            cout << "\nBienvenido " << usuarioSesion.getNombre() << endl;
            if (usuarioSesion.getCategoria() == "socio") {
               
               cout << "Que desea hacer socio?" << endl;
               cout << "1 - Realizar reserva" << endl;
               cout << "2 - Cancelar reserva" << endl;
               cout << "3 - Salir" << endl;
               cin >> option;
               switch (option) {
                  case 1: {
                     cout << "Realizar reserva" << endl;
                     int anio, mes, dia;
                     string input, nombre, apellido, sexo, categoria, ciMed, ciPac, motivo;
                     map<string, DtUsuario> medicos;
                     medicos = IU->obtenerMedicos();
                     map<string, DtUsuario>::iterator it;
                     
                     for (it=medicos.begin(); it!=medicos.end(); ++it) {
                        cout << it->second.getNombre() << " " << it->second.getApellido() << " - " << it->second.getCedula() << endl;
                     }
                     /*
                     out << "Ingrese CI del medico para la reserva (ingrese -1 si desea salir): " << endl;
                     cin >> input;
                     if (input == "-1"){
                        break;
                     } else {
                        cout << "\ningrese el anio, mes y dia de la reserva: ";
                        cin >> anio >> mes >> dia;
                        cout << "\ningrese la categoria del usuario: ";
                        cin >> categoria;


                        registroReserva(string ciMed, string ciPac, Fecha fecha, Fecha fechaReserva)
                     }
                     */

                     break;
                  }
                  case 2:
                     cout << "Cancelar reserva" << endl;
                     break;
                  case 3:
                     cedula = "-1";
                     pass = " ";
                     usuarioSesion = DtUsuario();
                     cedulaValida = false;
                     passCorrecto = false;
                     salirSesion = true;
                     break;
                  default:
                     break;
               }
            } else if (usuarioSesion.getCategoria() == "medico") {
               cout << "Que desea hacer medico?" << endl;
               cout << "1 - Alta diagnosticos de consulta" << endl;
               cout << "2 - Salir" << endl;
               cin >> option;
               switch (option) {
                  case 1:
                     cout << "Alta diagnosticos de consulta" << endl;
                     break;
                  case 2:
                     cedula = "-1";
                     pass = " ";
                     usuarioSesion = DtUsuario();
                     cedulaValida = false;
                     passCorrecto = false;
                     salirSesion = true;
                     break;
                  default:
                     break;
               }
            } else if (usuarioSesion.getCategoria() == "administrativo") {
               string input, nombre, apellido, sexo, categoria, ciMed, ciPac, motivo;
               int anio, mes, dia, anioR, mesR, diaR, opcionConsulta;
               DtUsuario user = DtUsuario();
               cout << "Que desea hacer admin?" << endl;
               cout << "1 - Alta/Reactivacion de usuario" << endl;
               cout << "2 - Registro de consulta" << endl;
               cout << "3 - Salir" << endl;
               cin >> option;

               switch (option) {
                  case 1:
                     while (input != "-1") {
                           cout << "Ingrese una cedula (ingrese -1 si desea salir): ";
                           cin >> input;
                           if (input == "-1"){
                              break;
                           }                           
                           user = IU->ingresarCedulaAlta(input);
                           if (user.getCedula() == "11111111") {
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
                                 IU->ingresarDatos(nombre, apellido, sexo, fecha, categoria);
                              else if (categoria == "medico")
                                 IU->ingresarDatos(nombre, apellido, sexo, fecha, categoria);
                              else
                                 IU->ingresarDatos(nombre, apellido, sexo, fecha, categoria);
                           } else {
                              cout << "\n Nombre: " << user.getNombre();
                              cout << "\n Apellido: " << user.getApellido();
                              cout << "\n Sexo: " << user.getSexo();
                              cout << "\n Edad: " << user.getEdad();
                              cout << "\n Activo: " << user.getActivo();
                              cout << "\n Categoria: " << user.getCategoria();

                              if(user.getActivo() == false){
                                 cout << "\ndesea reactivar el usuario?" << endl;
                                 cout << "1- SI\t\t2- NO" << endl;
                                 cin >> option;

                                 if(option == 1){
                                    IU->activarUsuario(user.getCedula());
                                    cout << "Usuario reactivado" << endl;
                                 }
                              }
                           }
                     }
                     IU->salir();
                     break;
                  case 2:
                     cout << "Desea ingresar una reserva o una emergencia?" << endl;
                     cout << "1- RESERVA\t\t\t2- EMERGENCIA" << endl;
                     cin >> opcionConsulta;
                     if(opcionConsulta == 1){
                        cout << "Registro de consulta" << endl;
                        cout << "Ingrese la ci del medico: ";
                        cin >> ciMed;
                        cout << "\nIngrese la ci del paciente: ";
                        cin >> ciPac;
                        cout << "\nIngrese dia, mes y anio de la consulta: ";
                        cin >> dia >> mes >> anio;
                        cout << "\nIngrese dia, mes y anio de la reserva: ";
                        cin >> diaR >> mesR >> anioR;

                        IC->registroReserva(ciMed, ciPac, Fecha(dia, mes, anio), Fecha(diaR, mesR, anioR));
                     } else {
                        cout << "Registro de emergencia" << endl;
                        cout << "Ingrese la ci del medico: ";
                        cin >> ciMed;
                        cout << "\nIngrese la ci del paciente: ";
                        cin >> ciPac;
                        cout << "\nIngrese dia, mes y anio de la consulta: ";
                        cin >> dia >> mes >> anio;
                        cout << "\nIngrese el motivo de la emergencia: ";
                        cin >> motivo;

                        IC->registroEmergencia(ciMed, ciPac, Fecha(dia, mes, anio), motivo);
                     }
                     break;
                  case 3:
                     cedula = "-1";
                     pass = " ";
                     usuarioSesion = DtUsuario();
                     cedulaValida = false;
                     passCorrecto = false;
                     salirSesion = true;
                     break;
                  default:
                     break;
               }
            }
         }
      }
   }
   cout << "\n\nsalgo\n\n";

   return 0;
}