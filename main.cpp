#include "stdio.h"
#include <string>
#include <iostream>
#include "fabrica/fabrica.h"

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
   Fecha fechaNac = Fecha(2001,10,22);
   Usuario* usuario = new Usuario("string nom", "string ap", "string ci", "string se", fechaNac, 10, true);
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
   
   cout << "\nIngrese su contrasena: ";
   cin >> pass;
   iSesion->ingresarCedula(cedula);
   iAD->agregarDescripcion("descripcion");
   iAU->salir();
   ICS->cerrarSesion();
   cout <<"\n" << usuario->getApellido();
   cout <<"\n" << usuario->getFechaNacimiento().getAnio();
   cout <<"\n" << usuario->getEdad();
   return 0;
}