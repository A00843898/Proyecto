#include <iostream>
#include <vector>
#include <iomanip>
#include "Jugador.h"
#include "sorts.h"

using namespace std;

void mostrarJugadores(vector<Jugador> jugadores) {

    cout << "\n";
    cout << "LISTA DE JUGADORES\n";
    cout << "---------------------------------------------------------------\n";

    cout << left
         << setw(5) << "No."
         << setw(15) << "Nombre"
         << setw(15) << "Equipo"
         << setw(8) << "Goles"
         << setw(10) << "Minutos"
         << setw(12) << "Amarillas"
         << setw(8) << "Rojas"
         << "\n";

    cout << "---------------------------------------------------------------\n";

    for (int i = 0; i < jugadores.size(); i++) {

        cout << left
             << setw(5) << i + 1
             << setw(15) << jugadores[i].getNombre()
             << setw(15) << jugadores[i].getEquipo()
             << setw(8) << jugadores[i].getGoles()
             << setw(10) << jugadores[i].getMinutos()
             << setw(12) << jugadores[i].getAmarillas()
             << setw(8) << jugadores[i].getRojas()
             << "\n";
    }
}

int seleccionarJugador(vector<Jugador> jugadores) {

    int jugadorSeleccionado = 0;

    mostrarJugadores(jugadores);

    cout << "\nSelecciona el numero del jugador: ";
    cin >> jugadorSeleccionado;

    if (cin.fail()) {

        cin.clear();
        cin.ignore(1000, '\n');

        cout << "\nEntrada no valida.\n";

        return -1;
    }

    if (jugadorSeleccionado < 1 ||
        jugadorSeleccionado > jugadores.size()) {

        cout << "\nNumero de jugador no valido.\n";

        return -1;
    }

    return jugadorSeleccionado - 1;
}

void mostrarGoleadores(vector<Jugador> jugadores) {

    Sorts sort;

    sort.ordenaGoles(jugadores);

    cout << "\n--- TABLA DE GOLEADORES ---\n";

    for (int i = 0; i < jugadores.size(); i++) {

        cout << i + 1 << ". "
             << jugadores[i].getNombre()
             << " - " << jugadores[i].getEquipo()
             << " - " << jugadores[i].getGoles()
             << " goles\n";
    }
}

void mostrarMinutos(vector<Jugador> jugadores) {

    Sorts sort;

    sort.ordenaMinutos(jugadores);

    cout << "\n--- MINUTOS JUGADOS ---\n";

    for (int i = 0; i < jugadores.size(); i++) {

        cout << i + 1 << ". "
             << jugadores[i].getNombre()
             << " - " << jugadores[i].getEquipo()
             << " - " << jugadores[i].getMinutos()
             << " minutos\n";
    }
}

void mostrarAmarillas(vector<Jugador> jugadores) {

    Sorts sort;

    sort.ordenaAmarillas(jugadores);

    cout << "\n--- TARJETAS AMARILLAS ---\n";

    for (int i = 0; i < jugadores.size(); i++) {

        cout << i + 1 << ". "
             << jugadores[i].getNombre()
             << " - " << jugadores[i].getEquipo()
             << " - " << jugadores[i].getAmarillas()
             << " amarillas\n";
    }
}

void mostrarRojas(vector<Jugador> jugadores) {

    Sorts sort;

    sort.ordenaRojas(jugadores);

    cout << "\n--- TARJETAS ROJAS ---\n";

    for (int i = 0; i < jugadores.size(); i++) {

        cout << i + 1 << ". "
             << jugadores[i].getNombre()
             << " - " << jugadores[i].getEquipo()
             << " - " << jugadores[i].getRojas()
             << " rojas\n";
    }
}

int main() {

    vector<Jugador> jugadores;

    jugadores.push_back(Jugador("Ana", "Tigres", 8, 540, 1, 0));
    jugadores.push_back(Jugador("Sofia", "Halcones", 5, 620, 2, 0));
    jugadores.push_back(Jugador("Valeria", "Leones", 10, 480, 0, 1));
    jugadores.push_back(Jugador("Mariana", "Aguilas", 3, 700, 3, 0));
    jugadores.push_back(Jugador("Daniela", "Tigres", 6, 590, 1, 0));
    jugadores.push_back(Jugador("Camila", "Leones", 4, 510, 2, 1));

    int opcion = 0;
    int posicionJugador = -1;
    int minutos = 0;

    do {

        cout << "\n========== TORNEO AMATEUR ==========\n";
        cout << "1. Mostrar jugadores\n";
        cout << "2. Mostrar tabla de goleadores\n";
        cout << "3. Mostrar minutos jugados\n";
        cout << "4. Mostrar tarjetas amarillas\n";
        cout << "5. Mostrar tarjetas rojas\n";
        cout << "6. Agregar gol\n";
        cout << "7. Agregar minutos\n";
        cout << "8. Agregar tarjeta amarilla\n";
        cout << "9. Agregar tarjeta roja\n";
        cout << "10. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        if (cin.fail()) {

            cin.clear();
            cin.ignore(1000, '\n');

            cout << "\nEntrada no valida.\n";
            opcion = 0;
        }

        else if (opcion == 1) {
            mostrarJugadores(jugadores);
        }

        else if (opcion == 2) {
            mostrarGoleadores(jugadores);
        }

        else if (opcion == 3) {
            mostrarMinutos(jugadores);
        }

        else if (opcion == 4) {
            mostrarAmarillas(jugadores);
        }

        else if (opcion == 5) {
            mostrarRojas(jugadores);
        }

        else if (opcion == 6) {

            posicionJugador = seleccionarJugador(jugadores);

            if (posicionJugador != -1) {

                jugadores[posicionJugador].agregarGol();

                cout << "\nGol agregado correctamente.\n";
            }
        }

        else if (opcion == 7) {

            posicionJugador = seleccionarJugador(jugadores);

            if (posicionJugador != -1) {

                cout << "Minutos a agregar: ";
                cin >> minutos;

                if (cin.fail()) {

                    cin.clear();
                    cin.ignore(1000, '\n');

                    cout << "\nCantidad de minutos no valida.\n";
                }
                else if (minutos > 0) {

                    jugadores[posicionJugador].agregarMinutos(minutos);

                    cout << "\nMinutos agregados correctamente.\n";
                }
                else {
                    cout << "\nLos minutos deben ser mayores a cero.\n";
                }
            }
        }

        else if (opcion == 8) {

            posicionJugador = seleccionarJugador(jugadores);

            if (posicionJugador != -1) {

                jugadores[posicionJugador].agregarAmarilla();

                cout << "\nTarjeta amarilla agregada correctamente.\n";
            }
        }

        else if (opcion == 9) {

            posicionJugador = seleccionarJugador(jugadores);

            if (posicionJugador != -1) {

                jugadores[posicionJugador].agregarRoja();

                cout << "\nTarjeta roja agregada correctamente.\n";
            }
        }

        else if (opcion != 10) {

            cout << "\nOpcion no valida.\n";
        }

    } while (opcion != 10);

    cout << "\nPrograma finalizado.\n";

    return 0;
}
