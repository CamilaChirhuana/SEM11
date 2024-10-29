int main() {
    Nodo *TablaHash = new Nodo[TAM_HASH];
    for (int i = 0; i < TAM_HASH; i++) {
        TablaHash[i] = nullptr;
    }

    int opcion, edad, indice;
    string dni, nombre, apellido;

    do 
    {
        cout << "\n\tMENU\t\n";
        cout << "1. Agregar Elemento\n";
        cout << "2. Buscar Elemento\n";
        cout << "3. Modificar Elemento\n";
        cout << "4. Eliminar Elemento\n";
        cout << "5. Reportar Hash Completo\n";
        cout << "6. Imprimir un Indice\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

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
                    cout << "Elemento encontrado: " << resultado->get_DNI() << ", " << resultado->get_nombre() << " " << resultado->get_apellido() << ", Edad: " << resultado->get_edad() << "\n";
                } 
                else 
                {
                    cout << "Elemento no encontrado.\n";
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
                cout << "Ingrese el indice que desea imprimir: "; cin >> indice;
                imprimirIndice(TablaHash, indice);
                break;

            case 7:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion no valida.\n";
                break;
        }
    } while (opcion != 7);

    
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
