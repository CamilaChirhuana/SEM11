#include<iostream>
#include "nodoLista.h"
using namespace std;

int TAM_HASH = 20;

int hashF(string dni) 
{
    long acum = 0;
    for (char c : dni) {
        acum = acum * 31 + (c - '0');
    }
    return acum % TAM_HASH;
}

void agregarElemento(Nodo** TablaHash, int edad, string DNI, string nombre, string apellido) 
{
    int i = hashF(DNI);
    Nodo* nodo = new Nodo(edad, DNI, nombre, apellido);
    nodo->set_sig(TablaHash[i]);
    TablaHash[i] = nodo;
}

void eliminarElemento(Nodo **T, string dni) 
{
    int indice = hashF(dni);
    Nodo *aux = T[indice];
    Nodo *prev = NULL;

    while (aux != NULL && aux->get_DNI() != dni) {
        prev = aux;
        aux = aux->get_sig();
    }

    if (aux == NULL) {
        cout << "Persona no encontrada.\n";
        return;
    }

    if (prev == NULL) {
        T[indice] = aux->get_sig();
    } else {
        prev->set_sig(aux->get_sig());
    }
    delete aux;
    cout << "Persona eliminada.\n";
}

void reportarHash(Nodo** TablaHash) {
    for (int i = 0; i < TAM_HASH; i++) {
        cout << "Índice " << i << ": ";
        Nodo* actual = TablaHash[i];
        while (actual != nullptr) {
      
            cout << "[" << actual->get_DNI() << ", " << actual->get_nombre() << " " << actual->get_apellido() << ", Edad: " << actual->get_edad() << "] -> ";
            actual = actual->get_sig();
        }
        cout << "NULL" << endl;
    }
}

void modificarElemento(Nodo **TablaHash, string dni, int nuevaEdad, string nuevoNombre, string nuevoApellido) 
{
    int index = hashF(dni); 
    Nodo *current = TablaHash[index];
     while (current != nullptr) 
    {
        if (current->get_DNI() == dni) 
        {
            current->set_edad(nuevaEdad);
            current->set_nombre(nuevoNombre);
            current->set_apellido(nuevoApellido);
            cout << "Modificación exitosa.\n";
            return;
        }
        current = current->get_sig();
    }
    cout << "Persona no encontrada en la tabla hash.\n";
}

int main() 
{
    Nodo **TablaHash = new Nodo*[TAM_HASH];
    for (int i = 0; i < TAM_HASH; i++) 
    {
        TablaHash[i] = NULL;
    }

    int opcion, edad, indice;
    string dni, nombre, apellido;

    do 
    {
        cout << "\n\tMENU\t\n";
        cout << "1. Agregar persona\n";
        cout << "2. Buscar persona\n";
        cout << "3. Modificar persona\n";
        cout << "4. Eliminar persona\n";
        cout << "5. Reportar Hash Completo\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("cls");
        switch(opcion)
        {
            case 1:
                cout << "Ingrese DNI: "; cin >> dni;
                cout << "Ingrese Nombre: "; cin >> nombre;
                cout << "Ingrese Apellido: "; cin >> apellido;
                cout << "Ingrese Edad: "; cin >> edad;
                agregarElemento(TablaHash, edad, dni, nombre, apellido);
                break;

            case 2:
                cout << "Ingrese DNI a buscar: "; cin >> dni;
                if (Nodo *resultado = buscarElemento(TablaHash, dni)) 
                {
                    cout << "Persona encontrada: " << resultado->get_DNI() << ", " << resultado->get_nombre() << " " << resultado->get_apellido() << ", Edad: " << resultado->get_edad() << "\n";
                } 
                else 
                {
                    cout << "Persona no encontrada.\n";
                }
                break;

            case 3:
                cout << "Ingrese DNI a modificar: "; cin >> dni;
                cout << "Ingrese nueva Edad: "; cin >> edad;
                cout << "Ingrese nuevo Nombre: "; cin >> nombre;
                cout << "Ingrese nuevo Apellido: "; cin >> apellido;
                modificarElemento(TablaHash, dni, edad, nombre, apellido);
                break;

            case 4:
                cout << "Ingrese DNI a eliminar: "; cin >> dni;
                eliminarElemento(TablaHash, dni);
                break;

            case 5:
                reportarHash(TablaHash);
                break;

            case 6:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion no valida.\n";
                break;
        }
    } while (opcion != 6);

    
    for (int i = 0; i < TAM_HASH; i++) 
    {
        Nodo *temp = TablaHash[i];
        while (temp != nullptr) {
            Nodo *siguiente = temp->get_sig();
            delete temp;
            temp = siguiente;
        }
    }
    delete[] TablaHash;

    return 0;
}
