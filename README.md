# priority_queue

Este documento explica cómo implementar una cola de prioridad usando la representación de un árbol binario en un array. Un heap binario es un árbol binario completo, que puede ser representado de manera eficiente usando un array. La cola de prioridad soporta inserción y eliminación eficiente del elemento mínimo.

## Conceptos Básicos del Heap Binario

Un heap binario puede ser de dos tipos:
1. **Min-Heap**: El valor del nodo padre es menor o igual que los valores de sus hijos.
2. **Max-Heap**: El valor del nodo padre es mayor o igual que los valores de sus hijos.

Para este ejemplo, usaremos un Min-Heap.

## Representación en Array

En una representación en array de un heap binario:
- El nodo raíz está en el índice 0.
- Para cualquier nodo en el índice `i`:
  - El hijo izquierdo está en el índice `2*i + 1`.
  - El hijo derecho está en el índice `2*i + 2`.
  - El nodo padre está en el índice `(i - 1) // 2`.

### Fórmulas

Dado un nodo en el índice `i`:
- **Hijo Izquierdo**: `izquierdo(i) = 2 * i + 1`
- **Hijo Derecho**: `derecho(i) = 2 * i + 2`
- **Padre**: `padre(i) = (i - 1) // 2`

## Operaciones

### Insertar

Para insertar un elemento en el heap:
1. Añadir el elemento al final del array.
2. Heapify up: Comparar el elemento insertado con su padre; si el elemento insertado es más pequeño, intercambiarlo con su padre y repetir el proceso hasta que se restablezca la propiedad del heap.

### Eliminar Mínimo

Para eliminar el elemento mínimo (raíz) del heap:
1. Reemplazar la raíz con el último elemento del array.
2. Eliminar el último elemento.
3. Heapify down: Comparar la nueva raíz con sus hijos; si la nueva raíz es mayor que cualquiera de sus hijos, intercambiarla con el hijo más pequeño y repetir el proceso hasta que se restablezca la propiedad del heap.
