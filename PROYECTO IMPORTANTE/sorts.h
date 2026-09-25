#ifndef SORTS_H_
#define SORTS_H_

#include <vector>
#include "Jugador.h"

using namespace std;

class Sorts {
private:

    int obtenerDato(Jugador jugador, int criterio) {
        if (criterio == 1) {
            return jugador.getGoles();
        }
        else if (criterio == 2) {
            return jugador.getMinutos();
        }
        else if (criterio == 3) {
            return jugador.getAmarillas();
        }
        else {
            return jugador.getRojas();
        }
    }

    void merge(vector<Jugador>& jugadores, int izquierda, int medio,
               int derecha, int criterio) {

        vector<Jugador> izquierdaVector;
        vector<Jugador> derechaVector;

        int i = izquierda;
        int j = medio + 1;

        while (i <= medio) {
            izquierdaVector.push_back(jugadores[i]);
            i++;
        }

        while (j <= derecha) {
            derechaVector.push_back(jugadores[j]);
            j++;
        }

        i = 0;
        j = 0;
        int k = izquierda;

        while (i < izquierdaVector.size() &&
               j < derechaVector.size()) {

            if (obtenerDato(izquierdaVector[i], criterio) >=
                obtenerDato(derechaVector[j], criterio)) {

                jugadores[k] = izquierdaVector[i];
                i++;
            }
            else {
                jugadores[k] = derechaVector[j];
                j++;
            }

            k++;
        }

        while (i < izquierdaVector.size()) {
            jugadores[k] = izquierdaVector[i];
            i++;
            k++;
        }

        while (j < derechaVector.size()) {
            jugadores[k] = derechaVector[j];
            j++;
            k++;
        }
    }

    void mergeSort(vector<Jugador>& jugadores, int izquierda,
                   int derecha, int criterio) {

        if (izquierda < derecha) {

            int medio = (izquierda + derecha) / 2;

            mergeSort(jugadores, izquierda, medio, criterio);
            mergeSort(jugadores, medio + 1, derecha, criterio);

            merge(jugadores, izquierda, medio, derecha, criterio);
        }
    }

public:

    void ordenaGoles(vector<Jugador>& jugadores) {
        if (jugadores.size() > 1) {
            mergeSort(jugadores, 0, jugadores.size() - 1, 1);
        }
    }

    void ordenaMinutos(vector<Jugador>& jugadores) {
        if (jugadores.size() > 1) {
            mergeSort(jugadores, 0, jugadores.size() - 1, 2);
        }
    }

    void ordenaAmarillas(vector<Jugador>& jugadores) {
        if (jugadores.size() > 1) {
            mergeSort(jugadores, 0, jugadores.size() - 1, 3);
        }
    }

    void ordenaRojas(vector<Jugador>& jugadores) {
        if (jugadores.size() > 1) {
            mergeSort(jugadores, 0, jugadores.size() - 1, 4);
        }
    }
};

#endif