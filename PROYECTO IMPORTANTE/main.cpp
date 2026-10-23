
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include "Jugador.h"
#include "BST.h"
#include "sorts.h"

using namespace std;

bool cargarJugadores(BST& arbol, string archivo, int& cargados) {
    ifstream entrada(archivo.c_str());
    string linea;

    cargados = 0;

    if (!entrada.is_open()) {
        return false;
    }

    while (getline(entrada, linea)) {
        if (linea.empty()) {
            continue;
        }

        stringstream datos(linea);

        string nombre;
        string equipo;
        string golesTexto;
        string minutosTexto;
        string amarillasTexto;
        string rojasTexto;

        if (!getline(datos, nombre, ';') ||
            !getline(datos, equipo, ';') ||
            !getline(datos, golesTexto, ';') ||
            !getline(datos, minutosTexto, ';') ||
            !getline(datos, amarillasTexto, ';') ||
            !getline(datos, rojasTexto)) {

            cout << "Registro incompleto, se omitio una linea.\n";
            continue;
        }

        int goles = 0;
        int minutos = 0;
        int amarillas = 0;
        int rojas = 0;

        stringstream conversionGoles(golesTexto);
        stringstream conversionMinutos(minutosTexto);
        stringstream conversionAmarillas(amarillasTexto);
        stringstream conversionRojas(rojasTexto);

        if (!(conversionGoles >> goles) ||
            !(conversionMinutos >> minutos) ||
            !(conversionAmarillas >> amarillas) ||
            !(conversionRojas >> rojas)) {

            cout << "Datos numericos invalidos, se omitio una linea.\n";
            continue;
        }

        if (nombre.empty() || equipo.empty() ||
            goles < 0 || minutos < 0 ||
            amarillas < 0 || rojas < 0) {

            cout << "Datos invalidos, se omitio una linea.\n";
            continue;
        }

        Jugador jugador(nombre, equipo, goles, minutos,
                        amarillas, rojas);

        if (arbol.agregar(jugador)) {
            cargados++;
        }
        else {
            cout << "Jugador duplicado: " << nombre << ". Se omitio.\n";
        }
    }

    entrada.close();
    return true;
}

void mostrarJugadores(vector<Jugador> jugadores) {
    cout << "\nLISTA DE JUGADORES\n";
    cout << "--------------------------------------------------------------------------\n";

    cout << left
         << setw(18) << "Nombre"
         << setw(16) << "Equipo"
         << setw(8) << "Goles"
         << setw(10) << "Minutos"
         << setw(12) << "Amarillas"
         << setw(8) << "Rojas"
         << "\n";

    cout << "--------------------------------------------------------------------------\n";

    for (int i = 0; i < jugadores.size(); i++) {
        cout << left
             << setw(18) << jugadores[i].getNombre()
             << setw(16) << jugadores[i].getEquipo()
             << setw(8) << jugadores[i].getGoles()
             << setw(10) << jugadores[i].getMinutos()
             << setw(12) << jugadores[i].getAmarillas()
             << setw(8) << jugadores[i].getRojas()
             << "\n";
    }

    if (jugadores.empty()) {
        cout << "No hay jugadores registrados.\n";
    }
}

void mostrarClasificacion(BST& arbol, int criterio) {
    vector<Jugador> jugadores;
    Sorts sort;

    arbol.obtenerJugadores(jugadores);
    sort.ordenar(jugadores, criterio);

    if (criterio == GOLES) {
        cout << "\n--- TABLA DE GOLEADORES ---\n";
    }
    else if (criterio == MINUTOS) {
        cout << "\n--- MINUTOS JUGADOS ---\n";
    }
    else if (criterio == AMARILLAS) {
        cout << "\n--- TARJETAS AMARILLAS ---\n";
    }
    else {
        cout << "\n--- TARJETAS ROJAS ---\n";
    }

    for (int i = 0; i < jugadores.size(); i++) {
        cout << i + 1 << ". "
             << jugadores[i].getNombre()
             << " - " << jugadores[i].getEquipo()
             << " - ";

        if (criterio == GOLES) {
            cout << jugadores[i].getGoles() << " goles\n";
        }
        else if (criterio == MINUTOS) {
            cout << jugadores[i].getMinutos() << " minutos\n";
        }
        else if (criterio == AMARILLAS) {
            cout << jugadores[i].getAmarillas() << " amarillas\n";
        }
        else {
            cout << jugadores[i].getRojas() << " rojas\n";
        }
    }
}

Jugador* seleccionarJugador(BST& arbol) {
    string nombre;

    cin.ignore(1000, '\n');

    cout << "Escribe el nombre del jugador: ";
    getline(cin, nombre);

    Jugador* jugador = arbol.buscar(nombre);

    if (jugador == 0) {
        cout << "\nNo se encontro ese jugador.\n";
    }

    return jugador;
}

int main() {
    BST arbol;
    int cargados = 0;

    if (!cargarJugadores(arbol, "jugadores.txt", cargados)) {
        cout << "No se pudo abrir jugadores.txt.\n";
        cout << "Verifica que el archivo este en la carpeta del proyecto.\n";
        return 1;
    }

    cout << "Se cargaron " << cargados << " jugadores correctamente.\n";

    int opcion = 0;
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
            vector<Jugador> jugadores;
            arbol.obtenerJugadores(jugadores);
            mostrarJugadores(jugadores);
        }
        else if (opcion >= 2 && opcion <= 5) {
            if (opcion == 2) {
                mostrarClasificacion(arbol, GOLES);
            }
            else if (opcion == 3) {
                mostrarClasificacion(arbol, MINUTOS);
            }
            else if (opcion == 4) {
                mostrarClasificacion(arbol, AMARILLAS);
            }
            else {
                mostrarClasificacion(arbol, ROJAS);
            }
        }
        else if (opcion >= 6 && opcion <= 9) {
            Jugador* jugador = seleccionarJugador(arbol);

            if (jugador != 0) {
                if (opcion == 6) {
                    jugador->agregarGol();
                    cout << "\nGol agregado correctamente.\n";
                }
                else if (opcion == 7) {
                    cout << "Minutos a agregar: ";
                    cin >> minutos;

                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "\nCantidad de minutos no valida.\n";
                    }
                    else if (minutos > 0) {
                        jugador->agregarMinutos(minutos);
                        cout << "\nMinutos agregados correctamente.\n";
                    }
                    else {
                        cout << "\nLos minutos deben ser mayores a cero.\n";
                    }
                }
                else if (opcion == 8) {
                    jugador->agregarAmarilla();
                    cout << "\nTarjeta amarilla agregada correctamente.\n";
                }
                else {
                    jugador->agregarRoja();
                    cout << "\nTarjeta roja agregada correctamente.\n";
                }
            }
        }
        else if (opcion != 10) {
            cout << "\nOpcion no valida.\n";
        }

    } while (opcion != 10);

    cout << "\nPrograma finalizado.\n";

    return 0;
} 