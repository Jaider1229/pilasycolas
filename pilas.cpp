#include<iostream>
using namespace std;

struct Nodo {
    int dato, prio;
    Nodo *siguiente;
};

void insertarpila(Nodo *&, int, int);
void mostrarpilas(Nodo *);
void eliminar(Nodo *&, int);
void menu();

Nodo *pila = NULL;

int main() {
    menu();
    return 0;
}

void menu() {
    int opcion, dato, prio, prioridadEliminar;

    do {
        cout << "\t. MENU \n";
        cout << "\n1. Ingresar un numero";
        cout << "\n2. Eliminar un numero por prioridad";
        cout << "\n3. Mostrar los datos";
        cout << "\n4. Salir";
        cout << "\nOpcion:   ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingresar un numero: ";
                cin >> dato;

                cout << "Ingresar una prioridad: ";
                cin >> prio;

                insertarpila(pila, dato, prio);
                break;

            case 2:
                cout << "Ingrese la prioridad que desea eliminar: ";
                cin >> prioridadEliminar;
                eliminar(pila, prioridadEliminar);
                break;

            case 3:
                cout << "La lista de numeros ingresados es:   ";
                mostrarpilas(pila);
                break;
        }
    } while (opcion != 4);
}

void insertarpila(Nodo *&pila, int n, int p) {
    Nodo *pilas = new Nodo();
    pilas->dato = n;
    pilas->prio = p;
    pilas->siguiente = pila;
    pila = pilas;

    cout << "Se ingreso el numero " << pilas->dato << " con una prioridad de: " << pilas->prio;
}

void mostrarpilas(Nodo *pila) {
    Nodo *actual = pila;

    while (actual != NULL) {
        cout << actual->dato << " - " << actual->prio << " -> ";
        actual = actual->siguiente;
    }
}

void eliminar(Nodo *&pila, int prioridadEliminar) {
    if (pila != NULL) {
        Nodo *aux = pila;
        Nodo *ant = NULL;

        while (aux != NULL) {
            if (aux->prio == prioridadEliminar) {
                if (ant == NULL) {
                    pila = aux->siguiente;
                } else {
                    ant->siguiente = aux->siguiente;
                }
                delete aux;
                cout << "Se eliminaron todos los nodos con prioridad " << prioridadEliminar << endl;
                return;
            }
            ant = aux;
            aux = aux->siguiente;
        }
        cout << "No se encontraron nodos con la prioridad especificada" << endl;
    } else {
        cout << "La pila está vacía" << endl;
    }
}





























