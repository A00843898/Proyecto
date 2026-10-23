
#ifndef BST_H_
#define BST_H_

#include <string>
#include <vector>
#include "Jugador.h"

using namespace std;

class NodoBST {
public:
    Jugador dato;
    NodoBST* izquierda;
    NodoBST* derecha;

    NodoBST(Jugador jugador) {
        dato = jugador;
        izquierda = 0;
        derecha = 0;
    }
};

class BST {
private:
    NodoBST* raiz;

    void limpiar(NodoBST* nodo) {
        if (nodo != 0) {
            limpiar(nodo->izquierda);
            limpiar(nodo->derecha);
            delete nodo;
        }
    }

    void recorrerEnOrden(NodoBST* nodo, vector<Jugador>& jugadores) {
        if (nodo != 0) {
            recorrerEnOrden(nodo->izquierda, jugadores);
            jugadores.push_back(nodo->dato);
            recorrerEnOrden(nodo->derecha, jugadores);
        }
    }

public:
    BST() {
        raiz = 0;
    }

    ~BST() {
        limpiar(raiz);
    }

    bool agregar(Jugador jugador) {
        NodoBST* nodoNuevo = new NodoBST(jugador);

        if (raiz == 0) {
            raiz = nodoNuevo;
            return true;
        }

        NodoBST* actual = raiz;
        NodoBST* anterior = 0;

        while (actual != 0) {
            anterior = actual;

            if (jugador.getNombre() < actual->dato.getNombre()) {
                actual = actual->izquierda;
            }
            else if (jugador.getNombre() > actual->dato.getNombre()) {
                actual = actual->derecha;
            }
            else {
                delete nodoNuevo;
                return false;
            }
        }

        if (jugador.getNombre() < anterior->dato.getNombre()) {
            anterior->izquierda = nodoNuevo;
        }
        else {
            anterior->derecha = nodoNuevo;
        }

        return true;
    }

    Jugador* buscar(string nombre) {
        NodoBST* actual = raiz;

        while (actual != 0) {
            if (nombre == actual->dato.getNombre()) {
                return &(actual->dato);
            }
            else if (nombre < actual->dato.getNombre()) {
                actual = actual->izquierda;
            }
            else {
                actual = actual->derecha;
            }
        }

        return 0;
    }

    void obtenerJugadores(vector<Jugador>& jugadores) {
        jugadores.clear();
        recorrerEnOrden(raiz, jugadores);
    }
};

#endif
