#include <iostream>
using namespace std;

class Nodo {
protected:
  int edad;
  string DNI;
  string nombre;
  string apellido;
  Nodo *Sig;

public:
  Nodo() {} //Defecto
  Nodo(int ed, string dni, string nom, string apel);
  Nodo(int ed, string dni, string nom, string apel, Nodo *s);
  ~Nodo() {}

  int get_edad();
  void set_edad(int e);
  string get_DNI();
  void set_DNI(string dni);
  string get_nombre();
  void set_nombre(string nom);
  string get_apellido();
  void set_apellido(string apel);
  Nodo *get_sig();
  void set_sig(Nodo *P);
};

Nodo::Nodo(int ed, string dni, string nom, string apel) {
  edad = ed;
  DNI = dni;
  nombre = nom;
  apellido = apel;
  Sig = NULL;
}
Nodo::Nodo(int ed, string dni, string nom, string apel, Nodo *s) {
  edad = ed;
  DNI = dni;
  nombre = nom;
  apellido = apel;
  Sig = s;
}

int Nodo::get_edad() { return edad; }
void Nodo::set_edad(int ed) { edad = ed; }

string Nodo::get_DNI() { return DNI; }
void Nodo::set_DNI(string dni) { DNI = dni; }

//Adaptar el getter y setter para apellido y nombre similar a DNI
string Nodo::get_nombre() { return nombre; }
void Nodo::set_nombre(string nom) { nombre = nom; }

string Nodo::get_apellido() { return apellido; }
void Nodo::set_apellido(string apel) { apellido = apel; }

Nodo *Nodo::get_sig() { return Sig; }
void Nodo::set_sig(Nodo *p) { Sig = p; }
