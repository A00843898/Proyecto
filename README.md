# Sistema de estadísticas para torneo amateur

## Descripción

Este proyecto consiste en un programa para organizar y consultar las estadísticas de jugadores de un torneo de fútbol amateur.

Cada jugador tiene información sobre su nombre, equipo, goles, minutos jugados, tarjetas amarillas y tarjetas rojas. Los datos se cargan desde un archivo de texto llamado `jugadores.txt`, por lo que es posible modificar la información inicial sin cambiar el código del programa.

Para almacenar y buscar jugadores se utiliza un árbol binario de búsqueda (BST), mientras que Merge Sort permite generar clasificaciones según las diferentes estadísticas. El programa también permite actualizar los datos de un jugador agregando goles, minutos o tarjetas durante la ejecución.

## ¿Cómo usar el programa?

Al iniciar el programa, se leen los registros de `jugadores.txt` y se muestra un menú con las siguientes opciones:

1. Mostrar jugadores.
2. Mostrar tabla de goleadores.
3. Mostrar minutos jugados.
4. Mostrar tarjetas amarillas.
5. Mostrar tarjetas rojas.
6. Agregar gol.
7. Agregar minutos.
8. Agregar tarjeta amarilla.
9. Agregar tarjeta roja.
10. Salir.

Para consultar una clasificación, se selecciona la opción correspondiente. Para actualizar las estadísticas de un jugador, se elige la operación deseada y se escribe su nombre completo. Si se quieren agregar minutos, también se indica la cantidad.

La opción de mostrar jugadores presenta los registros en orden alfabético por nombre. Las clasificaciones, en cambio, ordenan a los jugadores de mayor a menor según la estadística seleccionada.

Los cambios realizados durante la ejecución se mantienen en la memoria del programa, pero no se guardan automáticamente en el archivo `jugadores.txt`. Al cerrar el programa, estos cambios se pierden.

## Archivo de datos

El programa utiliza un archivo de texto llamado `jugadores.txt`. Cada línea representa a un jugador y contiene seis campos separados por punto y coma, en el siguiente orden:

`Nombre;Equipo;Goles;Minutos;Amarillas;Rojas`

Por ejemplo:

```text
Ana;Tigres;8;540;1;0
Sofia;Halcones;5;620;2;0
Valeria;Leones;10;480;0;1
```

Al iniciar el programa, la función `cargarJugadores()` lee el archivo línea por línea, separa los campos y convierte las estadísticas numéricas a enteros. Después, crea un objeto `Jugador` y lo inserta en el árbol binario de búsqueda.

Si una línea está incompleta, contiene datos numéricos inválidos o presenta valores negativos, se omite. También se omiten los jugadores con nombres duplicados, ya que el árbol utiliza el nombre como criterio de búsqueda.

Es importante que `jugadores.txt` se encuentre en la carpeta desde la que se ejecuta el programa, o en la carpeta de trabajo configurada en el entorno de desarrollo.

## ¿Cómo compilar y ejecutar desde consola?

Asegúrate de tener los siguientes archivos en la carpeta del proyecto:

- `main.cpp`
- `Jugador.h`
- `BST.h`
- `sorts.h`
- `jugadores.txt`

Para compilar y ejecutar el programa en Windows:

1. Presiona **Win + R**, escribe `cmd` y presiona Enter.
2. En la consola, escribe la ruta de la carpeta donde se encuentran los archivos:

   ```bat
   cd /d "C:\ruta\de\tu\proyecto"
   ```

3. Compila el programa con:

   ```bat
   g++ main.cpp -o torneo
   ```

4. Ejecuta el programa con:

   ```bat
   torneo.exe
   ```

En Mac o Linux puedes compilar con el mismo comando y ejecutar con:

```bash
./torneo
```

## Cumplimiento de las subcompetencias

### SICT0301: Evalúa los componentes

En el programa se utilizan dos estructuras principales: un árbol binario de búsqueda (BST) para guardar y buscar jugadores, y un vector junto con Merge Sort para ordenar las estadísticas.

**Árbol binario de búsqueda (BST)**

El árbol organiza a los jugadores por nombre, colocando los nombres menores a la izquierda y los mayores a la derecha.

- **Búsqueda e inserción:** tienen una complejidad de `O(h)`, donde `h` es la altura del árbol. Si está razonablemente equilibrado, pueden tener un costo de `O(log n)`. En el peor caso, llegan a `O(n)`.
- **Recorrido en orden:** tiene una complejidad de `O(n)`, porque visita todos los jugadores una vez.
- **Memoria:** el árbol requiere `O(n)` espacio para almacenar los jugadores. El vector utilizado para reunirlos también necesita `O(n)` espacio.

Como el árbol no se equilibra automáticamente, su rendimiento depende del orden en que se agregan los jugadores.

**Merge Sort**

Se utiliza para ordenar a los jugadores por goles, minutos y tarjetas, de mayor a menor.

- **Mejor caso, caso promedio y peor caso:** `O(n log n)`.
- **Espacio adicional:** `O(n)`, debido a los vectores temporales utilizados durante el ordenamiento.

La función `merge()` combina las partes ordenadas en tiempo `O(n)`, mientras que `mergeSort()` divide el vector y ordena sus partes.

**Lectura del archivo**

La función `cargarJugadores()` lee el archivo línea por línea y agrega los registros válidos al árbol. Para `n` jugadores, la construcción del árbol tiene un costo promedio de `O(n log n)` y puede llegar a `O(n²)` en el peor caso. La lectura y validación del archivo también depende de la cantidad de datos que contiene.

### SICT0302: Toma decisiones

Se consideraron tres opciones para almacenar los jugadores:

- **Vector:** permite acceder a los elementos por posición y facilita el ordenamiento, pero buscar un jugador por nombre requiere recorrer los elementos si no están ordenados por ese criterio.
- **Lista enlazada:** permite recorrer y agregar elementos, pero buscar un jugador también requiere, en general, revisar los registros uno por uno.
- **Árbol binario de búsqueda (BST):** organiza a los jugadores por nombre y permite buscarlos mediante comparaciones. Su rendimiento depende de la altura del árbol.

Se eligió el BST porque el programa necesita buscar jugadores por nombre para consultar y actualizar sus estadísticas. Se conservó Merge Sort porque permite ordenar las clasificaciones en `O(n log n)` sin cambiar la organización del árbol.

Así, cada estructura cumple una función distinta: el BST permite buscar jugadores y obtener la lista alfabética, mientras que el vector y Merge Sort se utilizan para generar las clasificaciones.

### SICT0303: Implementa acciones científicas

El programa permite leer datos desde un archivo, almacenarlos y realizar consultas sobre ellos.

- **Lectura de archivos:** `cargarJugadores()` abre `jugadores.txt` y separa los datos usando `stringstream`.
- **Validación:** se revisa que los registros tengan los campos necesarios y que las estadísticas sean números válidos y no negativos.
- **Almacenamiento:** cada registro válido se convierte en un objeto `Jugador` y se agrega al BST mediante `agregar()`.
- **Búsqueda:** `buscar()` localiza a un jugador por su nombre para consultar o actualizar sus estadísticas.
- **Consulta y ordenamiento:** `obtenerJugadores()` reúne los registros en un vector y Merge Sort los ordena según la estadística seleccionada.

Con estas funciones, el programa puede cargar información desde un archivo, buscar jugadores y generar clasificaciones a partir de sus estadísticas.
