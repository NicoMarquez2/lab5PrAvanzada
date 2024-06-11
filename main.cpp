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

bool correcto(string ci){
   if(!isNumber(ci) || ci.length() < 8 || ci.length() > 8)
      return false;
   return true;
}

int main(){
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

   Usuario* usuarioSesion = new Usuario();
   map<string, Usuario*> usersCollection;
   Fecha fecha = Fecha(2001, 10, 22);
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
   string cedula;
   string pass;
   printf("\t\tBIENVENIDO\n\n");
   printf("Iniciar sesion\n");
   printf("Ingrese su cedula: ");
   while (!valido){
      cin >> cedula;
      valido = correcto(cedula);
      if(!valido){
         cout << "cedula invalida\n";
      }
   }

   auto it = usersCollection.find(cedula);
      if (it != usersCollection.end()) {
         Usuario* u = it->second;
         cout << "\nIngrese su contrasena: ";
         cin >> pass;
         if(u->getActivo() == false && u->getContrasena() == " "){
            u->setContrasena(pass);
            u->setActivo(true);
         } else if(u->getActivo() == true){
            if(u->esContrasena(pass)){
               usuarioSesion = u;
            }
         }
      } else {
         cout << "Usuario no encontrado" << endl;
      }
   
   if(usuarioSesion->getCedula() != "11111111"){
      bool salir = false;
      int option = 0;
      while (!salir){
         cout << "\nBienvenido " << usuarioSesion->getNombre() << endl;
         if(dynamic_cast<Socio*>(usuarioSesion->getCategoria())){
            cout << "¿Que desea hacer socio?" << endl;
            cout << "1 - " << endl;
            cout << "2 - " << endl;
            cout << "3 - " << endl;
            cout << "4 - " << endl;
            cout << "5 - Salir socio" << endl;
         } else if(dynamic_cast<Medico*>(usuarioSesion->getCategoria())){
            cout << "¿Que desea hacer medico?" << endl;
            cout << "1 - " << endl;
            cout << "2 - " << endl;
            cout << "3 - " << endl;
            cout << "4 - " << endl;
            cout << "5 - Salir medico" << endl;
         } else if(dynamic_cast<Administrativo*>(usuarioSesion->getCategoria())){
            cout << "¿Que desea hacer admin?" << endl;
            cout << "1 - " << endl;
            cout << "2 - " << endl;
            cout << "3 - " << endl;
            cout << "4 - " << endl;
            cout << "5 - Salir admin" << endl;
         }
         cin >> option;
         switch(option){
         case 5:
            salir = true;
            break;
         
         default:
            break;
         }
      }
   }
   
   iAD->agregarDescripcion("descripcion");
   iAU->salir();
   ICS->cerrarSesion();
   return 0;
}