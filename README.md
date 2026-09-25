# Sistema de estadísticas para torneo amateur

## Descripción

Este proyecto consiste en un programa para organizar y consultar las estadísticas de jugadores de un torneo de fútbol amateur.

Cada jugador tiene información sobre su equipo, goles, minutos jugados, tarjetas amarillas y tarjetas rojas. El programa cuenta con algunos datos precargados y permite actualizar las estadísticas agregando goles, minutos o tarjetas.

También permite ordenar a los jugadores según diferentes estadísticas, por ejemplo, para consultar la tabla de goleadores o saber quiénes han jugado más minutos.

## ¿Cómo usar el programa?

Al iniciar el programa se muestra un menú con las siguientes opciones:

1. Mostrar jugadores
2. Mostrar tabla de goleadores
3. Mostrar minutos jugados
4. Mostrar tarjetas amarillas
5. Mostrar tarjetas rojas
6. Agregar gol
7. Agregar minutos
8. Agregar tarjeta amarilla
9. Agregar tarjeta roja
10. Salir

Para consultar una clasificación se selecciona la opción correspondiente. Para actualizar las estadísticas de un jugador, se selecciona la opción deseada, después se indica el número del jugador y, cuando corresponde, la cantidad de minutos que se quieren agregar.

## ¿Cómo compilar y ejecutar desde consola?

Para compilar el programa desde consola, primero asegúrate de tener los archivos `main.cpp`, `Jugador.h` y `sorts.h` en la misma carpeta.

**COMO SE USA:**

Presiona: **Win + R** → escribe `"cmd"` → Enter.

En la consola escribe:

```bash
cd /d "C:\(la carpeta donde están tus archivos)"
```

y presiona Enter.

Ya dentro de la carpeta del proyecto, escribe:

```bash
g++ main.cpp -o torneo
```

Para ejecutar el programa en Windows escribe:

```bash
torneo
```

En Mac o Linux, después de compilarlo, se ejecuta con:

```bash
./torneo
```

## Cumplimiento de las sub-competencias

### SICT0301: Evalúa los componentes

Para organizar a los jugadores según sus estadísticas se utiliza **Merge Sort**. Este algoritmo divide los datos en partes más pequeñas, las ordena y después las vuelve a juntar.

La complejidad de Merge Sort es `O(n log n)` en el mejor, promedio y peor caso. Esto permite conocer de manera clara cuánto puede aumentar el tiempo de ejecución conforme aumenta la cantidad de jugadores.

En el programa, la función `merge()` que junta las partes ordenadas tiene una complejidad de `O(n)`. Las operaciones para consultar o actualizar una estadística de un jugador tienen una complejidad de `O(1)`.

### SICT0302: Toma decisiones

Se eligió **Merge Sort** porque el programa necesita ordenar a los jugadores utilizando diferentes estadísticas y la cantidad de datos puede aumentar conforme crezca el torneo. Se consideraron otros métodos vistos anteriormente, como selección y burbuja, pero estos pueden llegar a tener una complejidad de `O(n²)`.

Por esta razón, Merge Sort permite que el programa mantenga un buen funcionamiento aunque aumente la cantidad de jugadores.

También se aplicó la modularidad separando el programa en diferentes archivos:

* `Jugador.h`: contiene la información y las operaciones de los jugadores.
* `sorts.h`: contiene el algoritmo utilizado para ordenar los datos.
* `main.cpp`: contiene el menú y la interacción con el usuario.
