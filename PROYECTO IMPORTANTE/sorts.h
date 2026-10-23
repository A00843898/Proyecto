
#ifndef SORTS_H_
#define SORTS_H_

#include <vector>
#include "Jugador.h"

#define GOLES 1
#define MINUTOS 2
#define AMARILLAS 3
#define ROJAS 4

using namespace std;

class Sorts {
private:
    int obtenerDato(Jugador jugador, int criterio) {
        if (criterio == GOLES) {
            return jugador.getGoles();
        }
        else if (criterio == MINUTOS) {
            return jugador.getMinutos();
        }
        else if (criterio == AMARILLAS) {
            return jugador.getAmarillas();
        }
        else {
            return jugador.getRojas();
        }
    }

    void merge(vector<Jugador>& jugadores, int izquierda,
               int medio, int derecha, int criterio) {

        vector<Jugador> izquierdaVector;
        vector<Jugador> derechaVector;

        for (int i = izquierda; i <= medio; i++) {
            izquierdaVector.push_back(jugadores[i]);
        }

        for (int i = medio + 1; i <= derecha; i++) {
            derechaVector.push_back(jugadores[i]);
        }

        int i = 0;
        int j = 0;
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
    void ordenar(vector<Jugador>& jugadores, int criterio) {
        if (jugadores.size() > 1) {
            mergeSort(jugadores, 0, jugadores.size() - 1, criterio);
        }
    }
};

#endif
