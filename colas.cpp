#include<iostream>
using namespace std;

struct Nodo {
    int dato, prio;
    Nodo *siguiente;
};

void insertarcola(Nodo *&, Nodo *&, int, int);
void mostrarcolas(Nodo *);
void eliminar(Nodo *&,Nodo *&,int);
void menu();

Nodo *frente = NULL;
Nodo *fin = NULL;

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

                insertarcola(frente, fin, dato, prio);
                break;

            case 2:
                cout << "Ingrese la prioridad que desea eliminar: ";
                cin >> prioridadEliminar;
                eliminar(frente, fin, prioridadEliminar);
                break;

            case 3:
                cout << "La lista de numeros ingresados es:   ";
                mostrarcolas(frente);
                break;
        }
    } while (opcion != 4);
}

void insertarcola(Nodo *&frente, Nodo *&fin, int n, int p) {
    Nodo *nuevo = new Nodo();
    nuevo->dato = n;
    nuevo->prio = p;
    nuevo->siguiente = NULL;

    if (frente == NULL) {
        frente = nuevo;
    } else {
        fin->siguiente = nuevo;
    }

    fin = nuevo;

    cout << "Se ingreso el numero " << nuevo->dato << " con una prioridad de: " << nuevo->prio << endl;
}

void mostrarcolas(Nodo *frente) {
    Nodo *actual = frente;

    while (actual != NULL) {
        cout << actual->dato << " - " << actual->prio << " -> ";
        actual = actual->siguiente;
    }
    cout << endl;
}

void eliminar(Nodo *&frente, Nodo *&fin, int prioridadEliminar) {
    if (frente != NULL) {
        Nodo *aux = frente;
        Nodo *ant = NULL;

        while (aux != NULL) {
            if (aux->prio == prioridadEliminar) {
                if (ant == NULL) {
                    frente = aux->siguiente;
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
        cout << "La cola está vacía" << endl;
    }
}

