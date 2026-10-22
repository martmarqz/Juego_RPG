# RPG - Proyecto 2

## Descripción

Proyecto de un juego de rol desarrollado en lenguaje C.

El jugador puede crear y administrar un personaje, explorar distintas zonas, obtener objetos, administrar su inventario, enfrentarse a enemigos, consultar un historial de acciones y guardar o cargar su partida.

El proyecto utiliza listas enlazadas, pilas y colas implementadas por el grupo.

## Organización de los archivos

- personaje: creación, carga y estado del personaje. <br>
- objeto: definición y manejo de objetos. <br>
- inventario: administración de los objetos del personaje. <br>
- enemigo: creación y manejo de enemigos. <br>
- aventura: exploración y generación de eventos. <br>
- combate: lógica de los enfrentamientos. <br>
- historial: registro y consulta de acciones. <br>
- lista: implementación de la lista enlazada. <br>
- pila: implementación de la pila. <br>
- cola: implementación de la cola. <br>
- archivo: guardado y carga de partidas. <br>
- interfaz: menús y comunicación con el usuario. <br>

## Organozacion del proyecto

- En conjunto: README, pruebas, informe y presentacion <br>

- Eban: inventario.c y objetos.c. Se encargará de programar la lógica base de los ítems en objetos.c y de construir el sistema de catálogo en inventario.c para agregar, buscar, equipar y eliminar objetos. <br>

- Yanira: historial.c y personajes.c. Se encarga de la responsabilidad central es historial.c, donde registrará los eventos y validará la función de extraer solo para deshacer objetos descartados. Además se encarga de personajes.c, que gestiona los atributos (vida, ataque, defensa) y el estado actual del protagonista.<br>

- Martina: combate.c y archivos.c. se encarga de desarrollar combate.c forzando el orden de enfrentamiento de los enemigos según su aparición. Además, se encarga de archivos.c, construyendo la lógica para escribir y guardar el progreso del juego en un archivo y cargarlo al reiniciar.


## Convención de nombres

Se utilizará snake_case como convención de nombres para variables y funciones.

## Compilación

El proyecto incluye un `Makefile` para facilitar la compilación y ejecución del programa en un entorno Linux. <br>

La compilación se realizará mediante: <br>

make <br>

La ejecución del programa se realizará mediante: <br>

make run <br>