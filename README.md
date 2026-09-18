# Motor de Cálculo con Caché Memoizado

Un programa interactivo de consola en C++20 diseñado para optimizar la ejecución de operaciones matemáticas mediante memoización. El sistema almacena los resultados en memoria para evitar recalcular operaciones ejecutadas previamente, reduciendo el tiempo de respuesta a tiempo constante.

## Funcionamiento

1. **Consulta:** El motor intercepta la operación y sus argumentos.
2. **Acierto en Caché (Cache Hit):** Si la operación ya fue evaluada, se devuelve el resultado almacenado inmediatamente.
3. **Fallo en Caché (Cache Miss):** Si es la primera vez que se solicita, se ejecuta el cálculo, se registra en la memoria y se entrega el resultado.
4. **Política de Desalojo (LRU):** Cuando se alcanza el límite de capacidad de la memoria, el sistema elimina automáticamente el elemento que lleva más tiempo sin ser consultado.

## Operaciones Soportadas

El motor permite ejecutar tanto operaciones aritméticas elementales como algoritmos de mayor coste computacional:

* **Operaciones básicas:** Suma, resta, multiplicación y división.
* **Cálculos de alta carga (de momento):**
  * Serie de Fibonacci (evaluación recursiva).
  * Comprobación de números primos y descomposición en factores primos.
  * Cálculo de factorial.

## Funcionalidades del Sistema

* **Medición de rendimiento:** Medición exacta del tiempo de ejecución en microsegundos para comparar la diferencia de velocidad entre el cálculo directo y la lectura desde memoria.
* **Estadísticas de uso:** Registro de aciertos, fallos y porcentaje de eficiencia (Hit Ratio).
* **Gestión dinámica:** Capacidad para ajustar el tamaño máximo de la caché en tiempo de ejecución y vaciar la memoria manualmente, además de poder cambiar la política de expulsión.
* **Persistencia:** Exportación e importación del estado de la caché en archivos de disco.
