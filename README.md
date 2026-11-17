# Sistema de estadísticas para torneo amateur

## Descripción

Este proyecto consiste en un programa para organizar y consultar las estadísticas de jugadores de un torneo de fútbol amateur.

Cada jugador cuenta con información sobre su nombre, equipo, goles, minutos jugados, tarjetas amarillas y tarjetas rojas. Los datos se cargan desde un archivo de texto llamado `jugadores.txt`, lo que permite modificar los registros sin tener que cambiar el código del programa.

Para almacenar y buscar jugadores se utiliza un árbol binario de búsqueda (BST), organizado por nombre. Por otra parte, Merge Sort permite generar clasificaciones de acuerdo con las diferentes estadísticas. El programa también permite actualizar los datos de cada jugador y guardar los cambios realizados para conservarlos en futuras ejecuciones.

## ¿Cómo usar el programa?

Al iniciar, el programa lee los registros de `jugadores.txt` y muestra un menú con las siguientes opciones:

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

La opción de mostrar jugadores presenta todos los registros en orden alfabético. Las opciones de clasificación ordenan a los jugadores de mayor a menor según la estadística seleccionada.

Para actualizar los datos, se elige la operación deseada. Después, el programa muestra los nombres de los jugadores registrados para facilitar su selección y solicita escribir el nombre completo. En el caso de agregar minutos, también se debe indicar la cantidad que se desea añadir.

Al seleccionar la opción 10, el programa guarda automáticamente los cambios realizados en `jugadores.txt`. De esta manera, las estadísticas actualizadas se conservan y se cargan nuevamente cuando se ejecuta el programa.

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

Cuando el usuario termina de utilizar el programa, la función `guardarArchivo()` recorre el árbol en orden y escribe los registros actualizados en `jugadores.txt`. Esto permite conservar los cambios realizados durante la ejecución.

Es importante que `jugadores.txt` se encuentre en la carpeta desde la que se ejecuta el programa, o en la carpeta de trabajo configurada en el entorno de desarrollo.

## ¿Cómo compilar y ejecutar desde consola?

Desde la carpeta donde se encuentran los archivos del proyecto, utiliza los siguientes comandos:

**Compilar:**

```bash
g++ main.cpp -o torneo
```

**Ejecutar en Windows (CMD):**

```bash
torneo.exe
```

**Ejecutar en Linux:**

```bash
./torneo
```

Es necesario que `jugadores.txt` se encuentre en la carpeta desde la que se ejecuta el programa.

## Cumplimiento de las subcompetencias

### SICT0301: Evalúa los componentes

En el programa se utilizan dos estructuras principales: un árbol binario de búsqueda (BST) para almacenar y buscar jugadores, y un vector junto con Merge Sort para ordenar las estadísticas. También se utilizan archivos de texto para cargar y guardar la información.

**Árbol binario de búsqueda (BST)**

El árbol organiza a los jugadores por nombre, colocando los nombres menores a la izquierda y los mayores a la derecha.

- **Búsqueda e inserción:** tienen una complejidad de `O(h)`, donde `h` es la altura del árbol. Si está razonablemente equilibrado, su costo es `O(log n)`. En el peor caso, cuando el árbol se encuentra desbalanceado, llega a `O(n)`.
- **Recorrido en orden:** tiene una complejidad de `O(n)`, porque visita todos los jugadores una vez. Se utiliza para obtener la lista alfabética y para guardar los registros en el archivo.
- **Memoria:** el árbol requiere `O(n)` espacio para almacenar los jugadores.

Como el árbol no se equilibra automáticamente, su rendimiento depende del orden en que se agregan los jugadores.

**Merge Sort**

Se utiliza para ordenar a los jugadores por goles, minutos y tarjetas, de mayor a menor.

- **Mejor caso, caso promedio y peor caso:** `O(n log n)`.
- **Espacio adicional:** `O(n)`, debido a los vectores temporales utilizados durante el ordenamiento.

La función `merge()` combina las partes ordenadas en tiempo `O(n)`, mientras que `mergeSort()` divide el vector y ordena sus partes.

**Lectura y escritura de archivos**

La función `cargarJugadores()` lee el archivo línea por línea, valida los registros y agrega los jugadores al árbol. La lectura y validación requiere recorrer los `n` registros. Sin embargo, el costo de construir el árbol depende de su altura:

- **Caso promedio:** `O(n log n)`.
- **Peor caso:** `O(n²)`, si los jugadores se insertan en un orden que provoca un árbol desbalanceado.

Por otro lado, `guardarArchivo()` recorre el árbol en orden y escribe cada jugador en `jugadores.txt`. Como visita todos los nodos una sola vez, su complejidad es `O(n)`.

**Consultas y actualización de estadísticas**

La búsqueda de un jugador mediante `buscar()` tiene una complejidad de `O(h)`. Una vez localizado, agregar goles, minutos o tarjetas requiere `O(1)`, ya que únicamente se modifica el valor correspondiente.

Para generar una clasificación, primero se obtienen los jugadores del árbol en `O(n)` y después se ordenan con Merge Sort en `O(n log n)`. Por lo tanto, el costo total de esta operación es `O(n log n)`.

**Complejidad general y memoria**

El programa no tiene un único costo de ejecución, ya que depende de la operación seleccionada. La carga inicial puede llegar a `O(n²)` en el peor caso por la inserción en el BST. Las clasificaciones requieren `O(n log n)`, mientras que guardar los datos necesita `O(n)`.

En cuanto a memoria, el árbol almacena `O(n)` jugadores. Cuando se generan clasificaciones o se obtiene la lista, también se utiliza un vector de `O(n)` elementos. Por lo tanto, el espacio adicional utilizado por estas operaciones es `O(n)`.

### SICT0302: Toma decisiones

Para seleccionar la estructura de almacenamiento se compararon tres alternativas: vector, lista enlazada y árbol binario de búsqueda. Los criterios considerados fueron el costo de buscar jugadores por nombre, insertar registros y recorrer la información en orden alfabético.

| Estructura | Búsqueda por nombre | Inserción | Recorrido alfabético |
|---|---|---|---|
| Vector sin ordenar | `O(n)` | `O(1)` al final | `O(n log n)` si se ordena |
| Lista enlazada | `O(n)` | `O(1)` al inicio | `O(n log n)` si se ordena |
| BST | `O(h)` | `O(h)` | `O(n)` si se recorre en orden |

Las complejidades del BST dependen de su altura: en un árbol razonablemente equilibrado, la búsqueda y la inserción son `O(log n)`, mientras que en el peor caso son `O(n)`.

Se eligió el BST porque el programa necesita localizar jugadores por nombre para actualizar sus estadísticas y también mostrar los registros en orden alfabético. Aunque un vector ordenado permitiría utilizar búsqueda binaria en `O(log n)`, insertar nuevos registros manteniendo ese orden puede requerir desplazar elementos, con un costo de `O(n)`. La lista enlazada tampoco ofrece una búsqueda eficiente por nombre.

Para las clasificaciones se mantuvo Merge Sort, ya que el orden de los jugadores cambia según la estadística que se quiera consultar. Utilizar el BST para organizar cada clasificación implicaría trabajar con un criterio diferente al nombre. En cambio, reunir los jugadores en un vector y aplicar Merge Sort permite generar las distintas tablas en `O(n log n)`.

Por estas razones, se decidió utilizar ambas estructuras de acuerdo con su función: el BST para almacenar, buscar y recorrer jugadores por nombre, y el vector con Merge Sort para generar las clasificaciones.

### SICT0303: Implementa acciones científicas

El programa implementa mecanismos para almacenar, consultar, modificar y conservar información mediante estructuras de datos y archivos de texto.

- **Lectura de archivos:** `cargarJugadores()` abre `jugadores.txt` y lee sus registros línea por línea. Utiliza `stringstream` para separar los campos.
- **Validación:** se revisa que los registros tengan los campos necesarios, que las estadísticas sean números válidos y que no existan valores negativos. También se evitan nombres duplicados.
- **Almacenamiento:** cada registro válido se convierte en un objeto `Jugador` y se agrega al BST mediante `agregar()`.
- **Búsqueda:** `buscar()` localiza a un jugador por su nombre para consultar o actualizar sus estadísticas.
- **Consulta y ordenamiento:** `obtenerJugadores()` reúne los registros en un vector y Merge Sort los ordena según la estadística seleccionada.
- **Actualización:** las funciones de la clase `Jugador` permiten agregar goles, minutos y tarjetas sin modificar directamente sus atributos.
- **Escritura de archivos:** `guardarArchivo()` recorre el BST en orden y escribe los datos actualizados en `jugadores.txt`. Esta operación se realiza al seleccionar la opción de salir del programa.

De esta manera, la información no se limita a mantenerse durante la ejecución: también se conserva en el archivo para que pueda recuperarse cuando el programa vuelva a iniciarse.

### SEG0701: Cultura digital

El programa busca facilitar la consulta y el seguimiento de las estadísticas de un torneo amateur mediante una herramienta sencilla de utilizar. Permite consultar clasificaciones, localizar jugadores y actualizar sus registros desde un menú, sin necesidad de modificar directamente el código.

Además, al guardar los cambios en el archivo de texto, la información se conserva entre ejecuciones. La validación de los registros ayuda a evitar que datos incompletos o valores negativos se incorporen al sistema.
