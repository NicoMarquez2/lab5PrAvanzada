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
   
   vector<CodDiagnostico*> codDiagCollection;
   CodDiagnostico* codiag1 = new CodDiagnostico("A", "Afecciones pulmonares", "A01", "Asma");
   CodDiagnostico* codiag2 = new CodDiagnostico("A", "Afecciones pulmonares", "A02", "Congestion");
   CodDiagnostico* codiag3 = new CodDiagnostico("B", "Aparato Digestivo", "B01", "Nauseas");
   codDiagCollection.push_back(codiag1);
   codDiagCollection.push_back(codiag2);
   codDiagCollection.push_back(codiag3);


   map<string, Diagnostico*> diagCollection;




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
            IC->cargarDatos(codDiagCollection);
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
               cout << "2 - Ver reservas" << endl;
               cout << "3 - Cancelar reserva" << endl;
               cout << "4 - Salir" << endl;
               cin >> option;
               switch (option) {
                  case 1: {
                     cout << "Realizar reserva" << endl;
                     int anio, mes, dia, hora, minutos;
                     string input, nombre, apellido, sexo, categoria, ciMed, motivo;
                     map<string, DtUsuario> medicos;
                     medicos = IU->obtenerMedicos();
                     map<string, DtUsuario>::iterator it;
                     
                     for (it=medicos.begin(); it!=medicos.end(); ++it) {
                        cout << it->second.getNombre() << " " << it->second.getApellido() << " - " << it->second.getCedula() << endl;
                     }
                     cout << "Ingrese CI del medico para la reserva (ingrese -1 si desea salir): " << endl;
                     cin >> input;
                     if (input == "-1"){
                        break;
                     } else {
                        ciMed = input;
                        cout << "\ningrese el anio, mes y dia de la reserva: " << endl;
                        cin >> anio >> mes >> dia;
                        Fecha fechaConsulta(anio, mes, dia);
                        cout << "\ningrese el hora, minutos: " << endl;
                        cin >> hora >> minutos;
                        Hora horaConsulta(hora, minutos);
                        IC->reservaConsulta(fechaConsulta, horaConsulta, usuarioSesion.getCedula(), ciMed);
                     }

                     break;
                  }
                  case 2: {
                     cout << "Ver reservas" << endl;
                     vector<DtReserva> consultas;
                     consultas = IU->obtenerReservasUser(usuarioSesion.getCedula());
                     vector<DtReserva>::iterator it;
                     for (it=consultas.begin(); it!=consultas.end(); ++it) {
                        Fecha fechaConsulta = it->getFecha();
                        Fecha fechaReserva = it->getFechaReserva();
                        Hora horaConsulta = it->getHora();
                        Usuario* medicoConsulta = it->getMedico();
                        bool asisteConsulta = it->getAsiste();
                        cout << fechaConsulta.getAnio() << "/" << fechaConsulta.getMes() << "/" << fechaConsulta.getDia() << " - " 
                        << horaConsulta.getHoras() << ":" << horaConsulta.getMinutos() << " - " 
                        << medicoConsulta->getNombre() << " " << medicoConsulta->getApellido() << " - "
                        << fechaReserva.getAnio() << "/" << fechaReserva.getMes() << "/" << fechaReserva.getDia();
                        if (asisteConsulta)
                           cout << " asiste" << endl;
                        else
                           cout << " no asiste" << endl;
                     }
                     break;
                  }
                  case 3:
                     cout << "Cancelar reserva" << endl;

                     break;
                  case 4:
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
                  case 1:{
                     cout << "Alta diagnosticos de consulta" << endl;
                     cout << endl;
                     cout << "Consultas del dia: " << endl;

                     string input, ciPac, codCat, codDiag, descripcion;
                     string cat = "Z";
                     vector<DtConsulta> consultas;
                     consultas = IU->obtenerConsultasUser(usuarioSesion.getCedula());
                     vector<DtConsulta>::iterator it;

                     for (it=consultas.begin(); it!=consultas.end(); ++it) {
                        Fecha fechaConsulta = it->getFecha();
                        Hora horaConsulta = it->getHora();
                        Usuario* pacConsulta = it->getSocio();
                        time_t now = time(nullptr);
                        tm* ltm = localtime(&now);
                        Fecha ahora = Fecha(1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday);
                        if (fechaConsulta.getAnio() == ahora.getAnio() && fechaConsulta.getMes() == ahora.getMes() && fechaConsulta.getDia()){
                           cout << pacConsulta->getNombre() << " " << pacConsulta->getApellido()
                           << " - " << pacConsulta->getCedula() << endl << endl;
                        }
                     }
                     
                     cout << "Ingrese cedula del paciente de la consulta deseada (-1 para salir): ";
                     cin >> input;
                     if (input != "-1")
                        ciPac = input;
                     else 
                        break;

                     vector<DtCodDiagnostico> setDtCD;
                     setDtCD = IC->obtenerCodDiagnosticos();
                     vector<DtCodDiagnostico>::iterator it2;

                     while (input != "-1"){
                        cout << "Desea agregar diagnostico? (S para agregar, -1 para salir): ";
                        cin >> input;
                        if (input != "-1" && input == "S"){
                           cout << "Categorias de diagnostico: " << endl;
                           for (it2=setDtCD.begin(); it2!=setDtCD.end(); ++it2) {
                              DtCodDiagnostico DtDC = *it2;
                              if (cat.compare(DtDC.getCodigoCategoria())!=0){
                                 cat = DtDC.getCodigoCategoria();
                                 cout << DtDC.getCodigoCategoria() << " - " << DtDC.getCategoria() << endl;
                              }
                           }
                        } else
                           break;
                        cout << "Ingrese categoria deseada (Codigo de familia, -1 para salir): " << endl;
                        cin >> input;
                        if (input != "-1"){
                           codCat = input;
                           for (it2=setDtCD.begin(); it2!=setDtCD.end(); ++it2) {
                              DtCodDiagnostico DtDC = *it2;
                              if (DtDC.getCodigoCategoria() == input){
                                 cout << DtDC.getCodigoDiagnostico() << " - " << DtDC.getEtiqueta() << endl;
                              }
                           }
                        } else
                           break;
                        cout << "Ingrese la representacion deseada (Codigo de diagnostico, -1 para salir): " << endl;
                        cin >> input;
                        if (input != "-1"){
                           codDiag = input;
                           cout << "Agregar descripcion (vacio si no desea agregar nada): " << endl;
                           cin >> descripcion;
                           IC->altaDiagnostico(ciPac, usuarioSesion.getCedula(), codCat, codDiag, descripcion);
                        } else
                           break;
                     }
                     break;
                  }
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
                  case 1: {
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
                  }
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
                        cout << "\nIngrese anio, mes y dia de la consulta: ";
                        cin >> anio >> mes >> dia;
                        cout << "\nIngrese anio, mes y dia de la reserva: ";
                        cin >> anioR >> mesR >> diaR;

                        IC->registroReserva(ciMed, ciPac, Fecha(anio, mes, dia), Fecha(anioR, mesR, diaR));
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