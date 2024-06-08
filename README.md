
# 1. Get started

- Clonar el repositorio
- Se dispone de un Makefile con las reglas `all`, `push_swap`, `checker`, `clean`, `fclean`, `re` y `see`
- Ejecutando el comando `make` se compila el binario `push_swap` que contiene el programa
- Ejecutando el comando `make checker` se compila el binario `checker` que permite testear los algoritmos

Se ejecuta `push_swap`, introduciéndole como input los números del stack A en su posición inicial, ya sea como argumentos independientes o en un único string.  
El programa nos devolverá los movimientos necesarios para ordenar los números.
```bash
# Por string
>./push_swap "5 1 -2"
ra
sa
# Por n parámetros
>./push_swap 5 1 -2
ra
sa
```

Al ejecutar el checker deben indicarse los números del stack A y será es posible:
- introducir los movimientos por entrada estándar, indicando su final con la combinación de teclas `Ctrl + D`
- pasarle los movimientos propuestos por el `push_swap` que se quiere checkear mediante una pipe

```bash
>./checker 5 1 -2
ra
sa   # Pulsamos Ctrl + D para indicar el final de los movimientos
OK
> ARG="5 1 -2"; ./push_swap $ARG | ./checker $ARG
OK
```

Si se introduce algún movimiento no permitido, el checker finalizará su ejecución indicando Error. Igualmente en caso de introducir números no válidos.
```bash
>./checker 5 1 -2
ra
rrrrrrrrrrr
Error
>./checker 5 5 1 -2
Error
```

# 2. Contenido del repositorio

- El repositorio contiene **push_swap**, sexto proyecto del Cursus de 42, correspondiente al segundo círculo (Rank 02).
- El proyecto sigue la [Norminette](https://github.com/42School/norminette), norma de estilo oficial del Campus.

##  push_swap 42 Project (Rank 02)
Score: 125/100

### Explicación del proyecto

El propósito principal del proyecto push_swap es ordenar una lista de números enteros utilizando una serie de operaciones específicas.
Inicialmente se disponen de dos stacks A y B, encontrándose los números desordenados en el stack A.
No pueden darse números repetidos.

Como bonus, se implementa un _checker_  que informa de si los movimientos propuestos verdaderamente ordenan los números del stack A.

#### Movimientos permitidos
Para mover los números, se permiten las siguientes operaciones:

- `sa`: Intercambia los dos primeros elementos en el stack A.
- `sb`: Intercambia los dos primeros elementos en el stack B.
- `ss`: Realiza `sa` y `sb` simultáneamente.
- `pa`: Toma el primer elemento de B y lo coloca en A.
- `pb`: Toma el primer elemento de A y lo coloca en B.
- `ra`: Desplaza todos los elementos de A hacia arriba (el primer elemento pasa al final).
- `rb`: Desplaza todos los elementos de B hacia arriba.
- `rr`: Realiza `ra` y `rb` simultáneamente.
- `rra`: Desplaza todos los elementos de A hacia abajo (el último elemento pasa al principio).
- `rrb`: Desplaza todos los elementos de B hacia abajo.
- `rrr`: Realiza `rra` y `rrb` simultáneamente.

#### (BONUS) Checker
Los bonus `server_bonus` y `client_bonus` deben aplicar:
- El servidor comunica al cliente que el mensaje ha sido recibido
- Es posible enviar caracteres unicode (esta feature se encuentra soportada en todo mi proyecto)   

#### Python Visualizer
Por motivos didácticos, se incluye en este proyecto el programa `python_visualizer.py` del alumno de 42 School [eruaud](https://profile.intra.42.fr/users/eruaud) que, ejecutando la regla `make see` permitirá ver de forma gráfica la ejecución del algoritmo.

# 3. Evaluación
Para la evaluación se requiere la generación de N números aleatorios. Podemos ayudarnos de algún lenguaje de scripting (como Ruby o Python) para generarlos.

En Ruby es posible tomar n números enteros aleatorios del intervalo `[l,m]` ejecutando la siguiente sentencia:
```ruby
puts (l..m).to_a.shuffle.take(n).join(' ')
```

Así en la evaluación es posible ejecutar lo siguiente:
```bash
# Genera números alatorios entre -200 y 200, los ordena aleatoriamente y toma 200 números pasándoselos a push_swap
ARG=`ruby -e "puts (-200..200).to_a.shuffle.take(200).join(' ')"`; ./push_swap $ARG
# Genera números alatorios entre -200 y 200, los ordena aleatoriamente y toma 200 números pasándoselos a push_swap y contando el número de movimientos
ARG=`ruby -e "puts (-200..200).to_a.shuffle.take(200).join(' ')"`; ./push_swap $ARG | wc -l
# Genera números alatorios entre -200 y 200, los ordena aleatoriamente y toma 200 números pasándoselos a push_swap y, posteriormente, evaluando la salida con el checker
ARG=`ruby -e "puts (-200..200).to_a.shuffle.take(200).join(' ')"`; ./push_swap $ARG | ./checker $ARG
```