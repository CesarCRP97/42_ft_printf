*Este proyecto ha sido creado como parte del currículo de 42 por crubio-p.*

# ft_printf

## Descripción

`ft_printf` es una implementación propia de la función `printf` de la biblioteca
estándar de C. El objetivo del proyecto es comprender cómo funcionan las
funciones variádicas, el análisis de cadenas de formato y la escritura de datos
por la salida estándar.

La función principal, `ft_printf`, recibe una cadena de formato y una lista
variable de argumentos. A partir de los especificadores encontrados, delega la
impresión en funciones auxiliares para caracteres, cadenas, números, punteros,
enteros sin signo, hexadecimal y el símbolo de porcentaje.

Conversiones soportadas:

- `%c`: imprime un carácter.
- `%s`: imprime una cadena de caracteres.
- `%p`: imprime una dirección de memoria.
- `%d` / `%i`: imprime un entero con signo en base decimal.
- `%u`: imprime un entero sin signo en base decimal.
- `%x`: imprime un entero en hexadecimal con letras minúsculas.
- `%X`: imprime un entero en hexadecimal con letras mayúsculas.
- `%%`: imprime el carácter `%`.

## Instrucciones

Para compilar la biblioteca, ejecuta:

```sh
make
```

Esto genera el archivo `libftprintf.a`, incluyendo la implementación de
`ft_printf` y la `libft` necesaria para el proyecto.

Para eliminar los archivos objeto:

```sh
make clean
```

Para eliminar los archivos objeto y la biblioteca generada:

```sh
make fclean
```

Para recompilar desde cero:

```sh
make re
```

Para usar la biblioteca en otro archivo C, incluye la cabecera:

```c
#include "ft_printf.h"
```

Ejemplo de compilación con un archivo de prueba:

```sh
cc -Wall -Wextra -Werror main.c libftprintf.a -o ft_printf_test
```

## Recursos

- Manual de `printf`: `man 3 printf`.
- Manual de argumentos variables: `man 3 stdarg`.
- Documentación de `write`: `man 2 write`.
- The GNU C Library Manual, secciones sobre formatted output y variadic
  functions.
- cppreference.com, páginas sobre `<stdarg.h>` y funciones variádicas en C.
- Enunciado oficial del proyecto `ft_printf` de 42.

### Uso de IA

Se ha utilizado IA como apoyo para redactar y estructurar este README, revisando
que incluya una descripción clara del proyecto, instrucciones de compilación y
una sección de recursos conforme a los requisitos indicados.

La IA no sustituye la comprensión del código ni la validación manual del
proyecto. Cualquier cambio funcional en la implementación debe ser revisado,
probado y entendido por el autor antes de su entrega.
