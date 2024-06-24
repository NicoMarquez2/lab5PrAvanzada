#include "stdio.h"
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
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
   Usuario* JA = new Usuario("admin", "James", "Peer", "34567645", "masculino", Fecha(1988, 12, 28), true, catA);
   Usuario* TM = new Usuario("socio", "Tifany", "McKensey", "34562345", "femenino", Fecha(1990, 1, 01), true, catS);
   Usuario* DP = new Usuario("socio", "Diego", "Perez", "12345435", "masculino", Fecha(1980, 3, 03), true, catS);
   Usuario* JM = new Usuario("medico", "Juan", "Montoya", "65436667", "masculino", Fecha(1970, 4, 07), true, catM);
   Usuario* DC = new Usuario("medico", "Debora", "Corral", "43521343", "femenino", Fecha(1993, 7, 13), true, catM);
   Usuario* AL = new Usuario("medico", "Ana", "Lopez", "98056743", "femenino", Fecha(1981, 9, 24), true, catM);
   usersCollection.insert({pruebaU->getCedula(), pruebaU});
   usersCollection.insert({pruebaM->getCedula(), pruebaM});
   usersCollection.insert({pruebaM2->getCedula(), pruebaM2});
   usersCollection.insert({JA->getCedula(), JA});
   usersCollection.insert({TM->getCedula(), TM});
   usersCollection.insert({DP->getCedula(), DP});
   usersCollection.insert({JM->getCedula(), JM});
   usersCollection.insert({DC->getCedula(), DC});
   usersCollection.insert({AL->getCedula(), AL});

   

   vector<Consulta*> consultCollection;
   Reserva* C1 = new Reserva(Fecha(2024, 6, 24), Hora(10, 10), TM, JM, Fecha(2014, 6, 21));
   Reserva* C2 = new Reserva(Fecha(2024, 6, 24), Hora(11, 11), TM, DC, Fecha(2015, 7, 21));
   Reserva* C3 = new Reserva(Fecha(2024, 6, 24), Hora(12, 12), DP, JM, Fecha(2016, 4, 26));
   Reserva* C4 = new Reserva(Fecha(2024, 6, 24), Hora(13, 13), DP, AL, Fecha(2017, 9, 30));
   Emergencia* U1 = new Emergencia(Fecha(2024, 6, 24), Hora(10, 10), TM, JM, "Fiebre alta");
   Emergencia* U2 = new Emergencia(Fecha(2024, 6, 24), Hora(10, 10), DP, DC, "Asma");
   Emergencia* U3 = new Emergencia(Fecha(2024, 6, 24), Hora(10, 10), DP, AL, "Mareos");
   consultCollection.push_back(C1);
   consultCollection.push_back(C2);
   consultCollection.push_back(C3);
   consultCollection.push_back(C4);
   consultCollection.push_back(U1);
   consultCollection.push_back(U2);
   consultCollection.push_back(U3);
   
   map<string, Usuario*>::iterator it800;
   it800 = usersCollection.find(C1->getSocio()->getCedula());
   if(it800 != usersCollection.end()){
      it800->second->ingresarConsulta(C1);
      /*vector<DtConsulta>::iterator it809;
      for (it809=it800->second->obtenerConsultas().begin(); it809!=it800->second->obtenerConsultas().end(); ++it809){
         cout << it809->getMedico()->getCedula() << " - " << it809->getSocio()->getCedula() << endl;
      }*/
   }
   it800 = usersCollection.find(C1->getMedico()->getCedula());
   if(it800 != usersCollection.end()){
      it800->second->ingresarConsulta(C1);
   }
   it800 = usersCollection.find(C2->getSocio()->getCedula());
   if(it800 != usersCollection.end()){
      it800->second->ingresarConsulta(C2);
   }
   it800 = usersCollection.find(C2->getMedico()->getCedula());
   if(it800 != usersCollection.end()){
      it800->second->ingresarConsulta(C2);
   }
   it800 = usersCollection.find(C3->getSocio()->getCedula());
   if(it800 != usersCollection.end()){
      it800->second->ingresarConsulta(C3);
   }
   it800 = usersCollection.find(C3->getMedico()->getCedula());
   if(it800 != usersCollection.end()){
      it800->second->ingresarConsulta(C3);
   }
   it800 = usersCollection.find(C4->getSocio()->getCedula());
   if(it800 != usersCollection.end()){
      it800->second->ingresarConsulta(C4);
   }
   it800 = usersCollection.find(C4->getMedico()->getCedula());
   if(it800 != usersCollection.end()){
      it800->second->ingresarConsulta(C4);
   }
   /*
   it800 = usersCollection.find(U1->getSocio()->getCedula());
   if(it800 != usersCollection.end()){
      it800->second->ingresarConsulta(U1);
      vector<DtConsulta>::iterator it809;
      for (it809=it800->second->obtenerConsultas().begin(); it809!=it800->second->obtenerConsultas().end(); ++it809){
         cout << it809->getMedico()->getCedula() << " - " << it809->getSocio()->getCedula() << endl;
      }
   }
   it800 = usersCollection.find(U1->getMedico()->getCedula());
   if(it800 != usersCollection.end()){
      it800->second->ingresarConsulta(U1);
      vector<DtConsulta>::iterator it809;
      for (it809=it800->second->obtenerConsultas().begin(); it809!=it800->second->obtenerConsultas().end(); ++it809){
         cout << it809->getMedico()->getCedula() << " - " << it809->getSocio()->getCedula() << endl;
      }
   }
   */
   
   /*
   map<string, Usuario*>::iterator it801;
   for (it801=usersCollection.begin(); it801 !=usersCollection.end(); ++it801){
      Usuario *us = it801->second;
      cout << " - " << us->getCedula() << endl;
      vector<DtConsulta>::iterator it803;
      for (it803=it801->second->obtenerConsultas().begin(); it803!=it801->second->obtenerConsultas().end(); ++it803){
         cout << it803->getMedico()->getCedula() << " - " << it803->getSocio()->getCedula() << endl;
      }
   }*/
   
   
   
   vector<CodDiagnostico*> codDiagCollection;
   CodDiagnostico* R1 = new CodDiagnostico("A", "Afecciones pulmonares", "A01", "Asma");
   CodDiagnostico* R2 = new CodDiagnostico("A", "Afecciones pulmonares", "A02", "Congestion");
   CodDiagnostico* R3 = new CodDiagnostico("B", "Aparato Digestivo", "B01", "Nauseas");
   codDiagCollection.push_back(R1);
   codDiagCollection.push_back(R2);
   codDiagCollection.push_back(R3);


   map<string, Diagnostico*> diagCollection;
   Diagnostico* D1 = new Diagnostico(R2, "Desc1");
   Diagnostico* D2 = new Diagnostico(R3, "Desc2");
   Diagnostico* D3 = new Diagnostico(R2, "Desc3");
   Diagnostico* D4 = new Diagnostico(R3, "Desc4");
   Diagnostico* D5 = new Diagnostico(R1, "Desc5");
   Diagnostico* D6 = new Diagnostico(R2, "Desc6");
   diagCollection.insert({D1->getCodDiagnostico()->getCodigoDiagnostico(), D1});
   diagCollection.insert({D2->getCodDiagnostico()->getCodigoDiagnostico(), D2});
   diagCollection.insert({D3->getCodDiagnostico()->getCodigoDiagnostico(), D3});
   diagCollection.insert({D4->getCodDiagnostico()->getCodigoDiagnostico(), D4});
   diagCollection.insert({D5->getCodDiagnostico()->getCodigoDiagnostico(), D5});
   diagCollection.insert({D6->getCodDiagnostico()->getCodigoDiagnostico(), D6});

   auto it900 = find_if(consultCollection.begin(), consultCollection.end(), [&C1](Consulta* consulta) {
               return consulta != nullptr 
               && consulta->getSocio()->getCedula() == C1->getSocio()->getCedula()
               && consulta->getMedico()->getCedula() == C1->getMedico()->getCedula();
   });
   if (it900 != consultCollection.end()) {
      Consulta *con = *it900;
      con->agregarDiagnostico(D1);
      con->agregarDiagnostico(D2);
   }
   auto it901 = find_if(consultCollection.begin(), consultCollection.end(), [&C3](Consulta* consulta) {
               return consulta != nullptr 
               && consulta->getSocio()->getCedula() == C3->getSocio()->getCedula()
               && consulta->getMedico()->getCedula() == C3->getMedico()->getCedula();
   });
   if (it901 != consultCollection.end()) {
      Consulta *con = *it901;
      con->agregarDiagnostico(D3);
   }
   auto it902 = find_if(consultCollection.begin(), consultCollection.end(), [&U1](Consulta* consulta) {
               return consulta != nullptr 
               && consulta->getSocio()->getCedula() == U1->getSocio()->getCedula()
               && consulta->getMedico()->getCedula() == U1->getMedico()->getCedula();
   });
   if (it902 != consultCollection.end()) {
      Consulta *con = *it902;
      con->agregarDiagnostico(D4);
   }
   auto it903 = find_if(consultCollection.begin(), consultCollection.end(), [&U2](Consulta* consulta) {
               return consulta != nullptr 
               && consulta->getSocio()->getCedula() == U2->getSocio()->getCedula()
               && consulta->getMedico()->getCedula() == U2->getMedico()->getCedula();
   });
   if (it903 != consultCollection.end()) {
      Consulta *con = *it903;
      con->agregarDiagnostico(D5);
      con->agregarDiagnostico(D5);
   }

   vector<Tratamiento*> tratamientoCollection;
   Farmaco* F1 = new Farmaco("Desc 1", "M1");
   Farmaco* F2 = new Farmaco("Desc 2", "M2");
   Quirurgico* Q1 = new Quirurgico("Desc 11", Fecha(2014, 7, 25));
   Quirurgico* Q2 = new Quirurgico("Desc 22", Fecha(2015, 2, 1));
   tratamientoCollection.push_back(F1);
   tratamientoCollection.push_back(F2);
   tratamientoCollection.push_back(Q1);
   tratamientoCollection.push_back(Q2);
   map<string, Diagnostico*>::iterator it950;
   it950 = diagCollection.find(D1->getCodDiagnostico()->getCodigoDiagnostico());
   if(it950 != diagCollection.end()){
      Diagnostico *diag = it950->second;
      diag->ingresarTratamiento(F1);
      diag->ingresarTratamiento(F2);
   }
   it950 = diagCollection.find(D2->getCodDiagnostico()->getCodigoDiagnostico());
   if(it950 != diagCollection.end()){
      Diagnostico *diag = it950->second;
      diag->ingresarTratamiento(Q1);
   }
   it950 = diagCollection.find(D3->getCodDiagnostico()->getCodigoDiagnostico());
   if(it950 != diagCollection.end()){
      Diagnostico *diag = it950->second;
      diag->ingresarTratamiento(Q2);
   }

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
            IC->cargarDatos(consultCollection, diagCollection, codDiagCollection, tratamientoCollection);
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
               cout << "2 - Obtener historial de paciente" << endl;
               cout << "3 - Salir" << endl;
               cin >> option;
               switch (option) {
                  case 1:{
                     cout << "Alta diagnosticos de consulta" << endl;
                     cout << endl;
                     cout << "Consultas del dia: " << endl;

                     string input, ciPac, codCat, codDiag, descripcion, tratamiento, descripcionT, medicamento;
                     Fecha tQuirurjico;
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
                        if (fechaConsulta.getAnio() == ahora.getAnio() && fechaConsulta.getMes() == ahora.getMes() && fechaConsulta.getDia() == ahora.getDia()){
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
                        if (input != "-1") {
                           codDiag = input;
                           cout << "Agregar descripcion (vacio si no desea agregar nada): " << endl;
                           cin.ignore();
                           getline(cin, descripcion);
                        }
                        cout << "Desea agregar un tratamiento? (S para agregar, -1 para salir): " << endl;
                        cin >> input;
                        if (input != "-1" && input == "S") {
                           cout << "Seleccine el tipo" << endl;
                           cout << "1- Farmaco" << " \t\t " << "2- Quirurjico" << endl;
                           cin >> input;
                           if (input == "1") {
                              tratamiento = "farmaco";
                              cout << "Farmaco - Agregar descripción: " << endl;
                              cin.ignore();
                              getline(cin, descripcionT);
                              cout << "Farmaco - Agregar medicamento: " << endl;
                              cin.ignore();
                              getline(cin, medicamento);
                           } else if (input == "2") {
                              tratamiento = "quirurjico";
                              cout << "Quirurjico - Agregar descripción: " << endl;
                              cin.ignore();
                              getline(cin, descripcionT);
                              cout << "Quirurjico - Agregar fecha (anio, mes, dia): " << endl;
                              int anio, mes, dia;
                              cin >> anio >> mes >> dia;
                              tQuirurjico = Fecha(anio, mes, dia);
                           }
                           IC->agregarTratamiento(descripcionT, tratamiento, medicamento, tQuirurjico);         
                        } else  {
                           input = "";
                        } 
                           IC->altaDiagnostico(ciPac, usuarioSesion.getCedula(), codCat, codDiag, descripcion); 
                     }
                     break;
                  }
                  case 2:{
                     string input, ciPac;
                     DtUsuario paciente;
                     vector<DtConsulta> consultasPacciente;
                     cout << "Obtener historial de paciente" << endl;
                     cout << endl;
                     cout << "Ingrese CI del paciente (-1 para salir): ";
                     cin >> input;
                     if (input != "-1") {
                        ciPac = input;
                        paciente = IU->ingresarCedula(ciPac);
                        cout << paciente.getCedula() << " - " << paciente.getNombre() << " " << paciente.getApellido() 
                           << " - " << paciente.getFechaNacimiento().getAnio() << "/" 
                           << paciente.getFechaNacimiento().getMes() << "/"
                           << paciente.getFechaNacimiento().getDia() << endl;

                        consultasPacciente = IU->obtenerConsultasUser(ciPac);
                        vector<DtConsulta>::iterator it;

                        for (it=consultasPacciente.begin(); it!=consultasPacciente.end(); ++it) {
                           time_t now = time(nullptr);
                           tm* ltm = localtime(&now);
                           Fecha ahora = Fecha(1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday);

                           Fecha fechaConsulta = it->getFecha();
                           Hora horaConsulta = it->getHora();
                           Usuario* pacConsulta = it->getSocio();
                           Usuario* medConsulta = it->getMedico();
                           map<string, DtDiagnostico> dtDiag = it->getDiagnosticos();
                           map<string, DtDiagnostico>::iterator it2;

                           if (fechaConsulta.getAnio() <= ahora.getAnio() && fechaConsulta.getMes() <= ahora.getMes() && fechaConsulta.getDia() <= ahora.getDia()){
                              cout << fechaConsulta.getAnio() << "/" << fechaConsulta.getMes() << "/" << fechaConsulta.getDia() << " - "
                                 << medConsulta->getCedula() << " - " << medConsulta->getNombre() << " " << medConsulta->getApellido() << endl;
                              for (it2=dtDiag.begin(); it2!=dtDiag.end(); ++it2){
                                 cout << "- " << it2->second.getCodDiagnostico().getCodigoDiagnostico() << " - " << it2->second.getCodDiagnostico().getEtiqueta()
                                       << " - " << it2->second.getDescripcion() << endl;
                                 
                                 vector<DtFarm> dtFarm = it2->second.getFarmacologico();
                                 vector<DtQuir> dtQuir = it2->second.getQuirurgico();

                                 if (dtFarm.size() != 0){
                                    vector<DtFarm>::iterator it3;
                                    for (it3=dtFarm.begin(); it3 !=dtFarm.end(); ++it3){
                                       DtFarm DtF = *it3;
                                       cout << " -- ";
                                       cout << DtF.getDescripcion();
                                       cout << " - " << DtF.getMedicamento() << endl;
                                    }
                                 }
                                 if (dtQuir.size() != 0){
                                    vector<DtQuir>::iterator it4;
                                    for (it4=dtQuir.begin(); it4 !=dtQuir.end(); ++it4){
                                       cout << " -- " << it4->getDescripcion() << " - " 
                                       << it4->getFechaIntervencion().getAnio() << "/" 
                                       << it4->getFechaIntervencion().getMes() << "/" 
                                       << it4->getFechaIntervencion().getDia() << endl;
                                    }
                                 }
                              }
                           }
                        }
                     } 

                     break;
                  }
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