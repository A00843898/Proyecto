#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <string>
using namespace std;

class Jugador {
private:
    string nombre;
    string equipo;
    int goles;
    int minutos;
    int amarillas;
    int rojas;

public:
    Jugador() {
        nombre = "";
        equipo = "";
        goles = 0;
        minutos = 0;
        amarillas = 0;
        rojas = 0;
    }

    Jugador(string nombre, string equipo, int goles, int minutos,
            int amarillas, int rojas) {
        this->nombre = nombre;
        this->equipo = equipo;
        this->goles = goles;
        this->minutos = minutos;
        this->amarillas = amarillas;
        this->rojas = rojas;
    }

    string getNombre() {
        return nombre;
    }

    string getEquipo() {
        return equipo;
    }

    int getGoles() {
        return goles;
    }

    int getMinutos() {
        return minutos;
    }

    int getAmarillas() {
        return amarillas;
    }

    int getRojas() {
        return rojas;
    }

    void agregarGol() {
        goles++;
    }

    void agregarMinutos(int cantidad) {
        if (cantidad > 0) {
            minutos += cantidad;
        }
    }

    void agregarAmarilla() {
        amarillas++;
    }

    void agregarRoja() {
        rojas++;
    }
};

#endif