# MT - Máquina de Turing
Realizado por: Jorge González Delgado (alu0101330105@ull.edu.es)
## Introducción
Este programa recrea el funcionamiento de una máquina de Turing, para ello se ha implementado una clase `TuringMachine` que contiene los atributos necesarios para su funcionamiento, además de un método `isAccepted` que es el que pone a funcionar el autómata para reconocer la cadena dada.

## Funcionamiento
Mi implementación utiliza las clases propias `Transition`, `State` y `TuringMachine`.

### Transition

La forma en la que un objeto del tipo `Transition` funciona, es el mismo que si tubiéramos la transición escrita en una cadena pero de forma que podamos acceder a cada elemento de esta de manera sencilla sin preocuparnos de índices.

La clase contiene los atributos privados:

- `origin` : Estado de origen de la transición.
- `destiny` : Estado de destino de la transición.
- `symbol` : Símbolo que se lee de la cinta.
- `newTapeSymbol` : Símbolo que se escribe en la cinta.
- `movement` : Movimiento de la cabeza lectora.

Los métodos que contiene la clase sirven para obtener o modificar dichos atributos, además de un método `toString()` que formatea los atributos para su visualización por pantalla.

### State
Simboliza un estado del autómata, contiene atributos para almacenar su nombre, sus transiciones y si es un estado inicial y/ final.

### TuringMachine
Clase principal de la máquina, contiene atributos para almacenar toda la informacón de su configuración y hace uso de las clase `Transition` y `State`. El método `isAccepted` es el que pone a funcionar la máquina sobre la cadena que se encuentre en la cinta.

## Uso
Para utilizar este programa es necesario tener instalado `cmake` > 3.14 y googleTest

```sh
$ sudo apt install cmake;
$ sudo apt install googletest;
```

- Situarse dentro de la carpeta build (si no hay, se puede crear usando `mkdir build`)
  ```bash
  $ cd build
  ```
- Precompilar con `cmake`
  ```sh
  $ cmake ..
  ```
- Compilar el ejecutable
  ```sh
  $ make
  ```
- El ejecutable se encuentra dentro de la carpeta `bin` con el nombre `main`.

El archivo ejecutable puede tomar 2 argomentos:

```sh
$ ./main <archivo de entrada> <traza [0, 1]>
```

Si no se especifica, la traza estará deshabilitada por defecto.

### Comentarios
No se ha realizado Testing en esta practica porque aún no estoy familiarizado del todo con googletest.