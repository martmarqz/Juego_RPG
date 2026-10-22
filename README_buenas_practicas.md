# Buenas prácticas 

## Modularización

El código se divide en módulos. <br>

Los modulos se encuentran en el README principal<br>

Cada módulo busca encargarse de una responsabilidad específica para evitar concentrar toda la lógica del programa en un solo archivo.

## Organización de las funciones

Las funciones deben realizar una tarea específica y evitar mezclar responsabilidades diferentes. <br>

Una función encargada de agregar un objeto al inventario no debería encargarse también de mostrar el menú principal.

## Manejo de memoria

Cuando se utilice memoria dinámica, el programa deberá comprobar que la asignación haya sido exitosa. Toda memoria reservada dinámicamente deberá ser liberada cuando deje de utilizarse. Se evitarán fugas de memoria y accesos a memoria que ya haya sido liberada.

## Validación de entradas

Las entradas proporcionadas por el usuario deberán ser validadas antes de ser utilizadas. <br>
El programa deberá manejar correctamente opciones inválidas y evitar que una entrada incorrecta provoque un comportamiento inesperado.

Los mensajes mostrados al usuario deberán indicar claramente qué ocurrió y, cuando corresponda, cómo continuar.

## Comentarios y documentación

Los comentarios se utilizarán principalmente para explicar partes del código cuya lógica pueda resultar compleja. <br>
Las funciones importantes deberán estar documentadas indicando: <br>

- Propósito de la función. <br>
- Parámetros recibidos. <br>
- Valor retornado. <br>
- Posibles errores. <br>

Se evitarán comentarios innecesarios que simplemente repitan lo que hace el código.

## Control de versiones

El proyecto será desarrollado utilizando Git. <br>
Los cambios deberán registrarse mediante commits relacionados con modificaciones del proyecto. <br>
Se procurará utilizar mensajes de commit claros que permitan identificar qué se modificó. <br>

## Organización del trabajo

El trabajo será dividido entre los integrantes del grupo procurando que cada integrante participe en funcionalidades relevantes del proyecto. <br>
La distribución de tareas considerará tanto la implementación de funcionalidades como el desarrollo de las estructuras de datos requeridas. <br>
Además, todos los integrantes deberán comprender el funcionamiento general del proyecto para poder explicar y defender el código durante la presentación. <br>

## Compilación

El proyecto contará con un Makefile que permitirá compilar y ejecutar el programa en un entorno Linux. El objetivo es poder construir el proyecto sin tener que escribir manualmente todos los comandos de compilación.