#include<iostream>
#include "nodoLista.h"


using namespace std;

int TAM_HASH = 20;

int hashF(string clave){

    int acum=0;

    for(char c : clave){
        //cout<<endl<<c+0;
        acum = acum + c;
    }
    //cout<<endl<<acum<<endl;
    return acum % TAM_HASH;
}

void recorrerHash(Nodo **T){
    
}

Nodo *busqueda(string DNI){
//Función Búsqueda

}

//Función Agregar elementos
//Función eliminar elementos
//Modificar elementos
//Reportar Hash

int main(){

    /*
    string clave = "zapatito";
    string clave2 = "zapato";
    string clave3 = "patito";

    cout<<endl<<"indice para clave "<<clave<<" es: "<<hashF(clave);
    cout<<endl<<"indice para clave "<<clave2<<" es: "<<hashF(clave2);
    cout<<endl<<"indice para clave "<<clave3<<" es: "<<hashF(clave3); */

    //Crear arreglo de Nodos
    Nodo **TablaHash, *n;
    TablaHash = new Nodo*[TAM_HASH];

    //Inicializamos el arreglo
    for(int i=0; i<TAM_HASH; i++){
        TablaHash[i]=NULL;
    }

    //int ed, string dni, string nom, string apel

    n = new Nodo(15, "Cd54125", "Carlos", "Diaz");

    recorrerHash(TablaHash);
    

    return 0;
}
