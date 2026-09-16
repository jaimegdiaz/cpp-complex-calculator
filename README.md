# Engine de Cálculo y Caché Memoizado en C++ (CLI)

Un motor de cálculo en consola escrito en C++20 que optimiza la ejecución de operaciones complejas mediante un sistema de caché en memoria (**Memoización**) basado en la política de desalojo **LRU (Least Recently Used)**.

---

## Especificación Técnica del Proyecto

### 1. Visión General
El objetivo del proyecto es interceptar las peticiones de cómputo del usuario, evaluar si el resultado ya fue calculado previamente y, de ser así, devolverlo en tiempo constante $\mathcal{O}(1)$. Si el resultado no existe en memoria (*Cache Miss*), se realiza el cálculo, se registra en la caché y se devuelve al usuario. Cuando la memoria alcanza su capacidad límite, el sistema aplica la política LRU para desalojar el elemento menos utilizado.

---

### 2. Arquitectura de Datos y Caché LRU
* **Capacidad Configurable:** La caché se inicializa con una capacidad máxima de $N$ elementos, ampliable o reducible en tiempo de ejecución.
* **Complejidad Temporal Requerida:**
  * **Búsqueda (*Hit/Miss*):** $\mathcal{O}(1)$
  * **Inserción / Actualización:** $\mathcal{O}(1)$
  * **Desalojo del elemento menos usado:** $\mathcal{O}(1)$
* **Estructura Interna:** Combinación de un mapa hash (`std::unordered_map`) para acceso directo por clave y una lista doblemente enlazada (`std::list`) para mantener el orden cronológico de uso.

---

### 3. Funcionalidades y Requisitos

#### A. Motor de Cálculo
- **Operaciones de prueba:**
  - Recursión pesada (ej. Serie de Fibonacci).
  - Cálculo intensivo de iteraciones (ej. Evaluación de números primos / Factoriales).
  - Operaciones compuestas configurables.
- **Identificación de Claves:** Generación de claves unificadas únicas formateando la operación y sus operandos (ej. `"fibonacci:40"`, `"potencia:2,10"`).

#### B. Rendimiento y Medición
- **Medición de Tiempos:** Integración de `<chrono>` para medir e imprimir la duración exacta de cada llamada en microsegundos ($\mu s$).
- **Módulo de Estadísticas:**
  - Contador de *Hits* y *Misses*.
  - Cálculo del *Hit Ratio* ($Hit\ Ratio = \frac{Hits}{Hits + Misses} \times 100$).
  - Inspección visual del estado de la caché en orden de uso (desde el elemento más recientemente usado hasta el LRU).

#### C. Interfaz de Usuario (CLI)
Un bucle interactivo que ofrece las siguientes opciones:
1. `[1] Ejecutar Operación` (Ingresar operación y parámetros).
2. `[2] Ver Estado de la Caché` (Listado de claves ordenadas en memoria).
3. `[3] Ver Estadísticas y Rendimiento` (Metricas de Hit/Miss Ratio y tiempos).
4. `[4] Configurar Tamaño de Caché` (Ajustar capacidad máxima en caliente).
5. `[5] Limpiar Caché (Flush)` (Vaciar la caché manualmente).
6. `[6] Exportar / Cargar Caché a Disco` (Persistencia en archivo `.txt` / `.dat`).
7. `[7] Salir`

---

## 🛠️ Compilación y Ejecución

Para compilar el proyecto utilizando C++20:

```bash
g++ -std=c++20 -O2 main.cpp -o memo_calc
./memo_calc
