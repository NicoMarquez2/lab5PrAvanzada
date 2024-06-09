#include "stdio.h"
#include <string>
#include <iostream>
#include "fabrica/fabrica.h"

using namespace std;

int main(){
   Fabrica* f;
   IIniciarSesion* c;
   f = Fabrica::getInstancia();
   c = f->getIIniciarSesion();
   string cedula;
   string pass;
   printf("\t\tBIENVENIDO\n\n");
   printf("Iniciar sesion\n");
   printf("Ingrese su cedula: ");
   cin >> cedula;
   cout << "\nIngrese su contrasena: ";
   cin >> pass;
   c->ingresarCedula(pass);
   return 0;
}