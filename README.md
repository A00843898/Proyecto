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

Para desarrollar el programa fue necesario analizar la complejidad de las estructuras y los algoritmos utilizados, considerando las operaciones que realiza cada uno. Se utilizan principalmente un árbol binario de búsqueda (BST), un vector y Merge Sort. También se incluyen procesos para leer y guardar información en archivos.

**Árbol binario de búsqueda (BST)**

El BST almacena a los jugadores de acuerdo con su nombre. Cuando se agrega un jugador, se compara su nombre con el de los nodos existentes: los nombres menores se colocan a la izquierda y los mayores a la derecha.

- **Inserción:** tiene una complejidad de `O(h)`, donde `h` representa la altura del árbol. Si el árbol está equilibrado, el costo es `O(log n)`, mientras que en el peor caso puede llegar a `O(n)`.
- **Búsqueda:** utiliza el mismo principio de comparación para localizar a un jugador por su nombre. Su complejidad también es `O(h)`, con un mejor rendimiento cuando el árbol está equilibrado.
- **Recorrido en orden:** tiene una complejidad de `O(n)`, porque visita todos los nodos una vez. Se utiliza para obtener la lista de jugadores en orden alfabético y para reunirlos antes de realizar una clasificación.
- **Memoria:** requiere `O(n)` espacio para almacenar los nodos del árbol.

El BST no se equilibra automáticamente, por lo que su rendimiento depende del orden en que se insertan los jugadores.

**Vector**

El vector se utiliza para reunir temporalmente los jugadores del árbol y trabajar con sus estadísticas sin modificar la organización original del BST.

- **Recorrido y copia de los jugadores:** requiere `O(n)` tiempo y `O(n)` espacio adicional.
- **Acceso por posición:** tiene una complejidad de `O(1)`, lo que permite consultar y modificar los elementos durante el ordenamiento.

**Merge Sort**

Se utiliza para generar las clasificaciones de goles, minutos jugados y tarjetas, ordenando a los jugadores de mayor a menor según la estadística seleccionada.

- **Mejor caso, caso promedio y peor caso:** `O(n log n)`.
- **Espacio adicional:** `O(n)`, debido a los vectores temporales que se utilizan para combinar las partes ordenadas.

El algoritmo divide el vector en partes más pequeñas hasta que cada una contiene un elemento. Después, las combina en el orden correspondiente. La combinación requiere `O(n)` tiempo por nivel de división, mientras que el algoritmo trabaja con aproximadamente `log n` niveles.

**Lectura y escritura de archivos**

La función `cargarJugadores()` lee los registros de `jugadores.txt` y los inserta en el BST. La lectura y validación de los datos requiere `O(n)` tiempo, considerando que cada registro contiene una cantidad fija de campos. La construcción del árbol requiere, en promedio, `O(n log n)` y puede llegar a `O(n²)` si las inserciones generan un árbol completamente desbalanceado.

Por otra parte, la función `guardarArchivo()` recorre el árbol en orden y escribe los datos de cada jugador en el archivo. Este proceso tiene una complejidad de `O(n)`, ya que cada nodo se visita una sola vez.

**Complejidad general**

La complejidad depende de la operación que se realice:

- Cargar los jugadores: `O(n log n)` en promedio y `O(n²)` en el peor caso.
- Buscar un jugador: `O(log n)` si el árbol está equilibrado y `O(n)` en el peor caso.
- Mostrar todos los jugadores: `O(n)`.
- Generar una clasificación: `O(n log n)`, debido al ordenamiento con Merge Sort.
- Guardar los cambios: `O(n)`.

Por lo tanto, el ordenamiento de las clasificaciones tiene un costo de `O(n log n)`, mientras que la búsqueda y la carga dependen de la altura del árbol. En el peor caso, la construcción del BST puede llegar a `O(n²)`, por lo que no sería correcto asignar una sola complejidad a todas las operaciones del programa.

### SICT0302: Toma decisiones

Para decidir cómo almacenar y organizar la información, primero se consideró qué necesitaba hacer el programa. No era suficiente con guardar los registros: también debía permitir buscar a una jugadora por su nombre para actualizar sus estadísticas, mostrar la lista en orden alfabético y generar clasificaciones por goles, minutos y tarjetas.

A partir de estas necesidades, se consideraron tres alternativas:

**1. Vector**

Un vector permite almacenar los registros de forma sencilla y acceder directamente a ellos mediante su posición. Además, facilita aplicar algoritmos de ordenamiento como Merge Sort.

Sin embargo, para encontrar a una jugadora por nombre sería necesario recorrer sus elementos uno por uno, lo que requiere `O(n)` tiempo. También sería necesario ordenar el vector por nombre para realizar búsquedas binarias, y esto tendría un costo adicional de ordenamiento. Aunque es una alternativa útil para generar las clasificaciones, no resulta tan conveniente como estructura principal si se realizan búsquedas y actualizaciones por nombre.

**2. Lista enlazada**

Una lista enlazada permite agregar registros y recorrerlos en orden. También facilita insertar elementos sin desplazar los demás, como sucede en un vector.

Sin embargo, para encontrar a una jugadora por nombre se tendría que recorrer la lista hasta localizarla, por lo que la búsqueda tendría una complejidad de `O(n)`. Además, no permite acceder directamente a un elemento por su posición. Por estas razones, tampoco representa la mejor opción para las búsquedas que necesita el programa.

**3. Árbol binario de búsqueda (BST)**

El BST organiza los registros utilizando el nombre como criterio de comparación. Esto permite dirigir la búsqueda hacia la izquierda o la derecha del árbol, sin tener que revisar todos los jugadores cuando su altura es reducida.

Su búsqueda e inserción tienen una complejidad de `O(log n)` cuando el árbol está equilibrado, aunque pueden llegar a `O(n)` en el peor caso. Otra ventaja es que permite obtener los nombres en orden alfabético mediante un recorrido en orden, sin necesitar un ordenamiento adicional.

**Comparación y decisión**

Al comparar las tres alternativas, se tomó en cuenta el tiempo necesario para buscar una jugadora, la facilidad para agregar registros y la posibilidad de obtener la información en orden alfabético.

El vector y la lista enlazada permiten almacenar y recorrer los datos, pero sus búsquedas por nombre requieren revisar los elementos uno por uno. En cambio, el BST utiliza las comparaciones entre nombres para dirigir la búsqueda y también permite obtener los registros en orden alfabético.

Por eso se eligió el BST como estructura principal. Aunque no garantiza búsquedas de `O(log n)` en todos los casos, responde mejor a las operaciones que necesita el programa, especialmente porque las actualizaciones requieren localizar primero a una jugadora.

Para las clasificaciones se tomó una decisión distinta. Se consideró ordenar directamente los datos del BST, pero esto modificaría su organización por nombre. También se podía utilizar un algoritmo de ordenamiento sencillo, como Bubble Sort, cuya complejidad promedio y en el peor caso es `O(n²)`. Finalmente, se eligió Merge Sort porque permite ordenar las estadísticas en `O(n log n)`.

De esta manera, se utiliza cada estructura para la tarea en la que resulta más conveniente: el BST mantiene y busca a los jugadores por nombre, mientras que el vector y Merge Sort permiten generar las diferentes clasificaciones sin alterar el árbol.

### SICT0303: Implementa acciones científicas

El programa incluye mecanismos para consultar, actualizar y conservar la información de los jugadores. Para esto, se utilizan las siguientes funciones:

- **Carga de información:** `cargarJugadores()` abre `jugadores.txt`, lee cada línea y separa sus campos mediante `stringstream`. Después de validar los datos, crea un objeto `Jugador` y lo agrega al BST.
- **Búsqueda:** `buscar()` localiza a una jugadora utilizando su nombre. Esto permite acceder directamente a sus datos dentro del árbol y realizar las actualizaciones correspondientes.
- **Consulta de registros:** `obtenerJugadores()` recorre el árbol en orden y reúne los registros en un vector. Así se puede mostrar la lista completa en orden alfabético.
- **Clasificaciones:** `mostrarClasificacion()` obtiene los jugadores mediante `obtenerJugadores()` y utiliza Merge Sort para ordenarlos según la estadística seleccionada.
- **Actualización:** las funciones de la clase `Jugador` permiten agregar goles, minutos y tarjetas. Los cambios se realizan sobre el registro encontrado en el BST.
- **Guardado de información:** `guardarArchivo()` recorre el árbol en orden y escribe los datos actualizados en `jugadores.txt`. Esta función se ejecuta cuando el usuario selecciona la opción de salir.

También se consideró la facilidad de uso al momento de consultar y actualizar los registros. Antes de solicitar el nombre de una jugadora, el programa muestra los nombres disponibles. Esto permite que el usuario conozca las opciones registradas y reduce los errores al escribir el nombre.

Con estos mecanismos, la información no solamente se almacena, sino que puede localizarse, consultarse, modificarse y conservarse en el archivo para futuras ejecuciones.

### SEG0701: Cultura digital

El programa busca facilitar la consulta y el seguimiento de las estadísticas de un torneo amateur mediante una herramienta sencilla de utilizar. Permite consultar clasificaciones, localizar jugadores y actualizar sus registros desde un menú, sin necesidad de modificar directamente el código.

Además, al guardar los cambios en el archivo de texto, la información se conserva entre ejecuciones. La validación de los registros ayuda a evitar que datos incompletos o valores negativos se incorporen al sistema.
