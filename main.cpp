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
   IIniciarSesion* c;
   f = Fabrica::getInstancia();
   c = f->getIIniciarSesion();
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
   c->ingresarCedula(cedula);
   return 0;
}