# ♜ Clase Torre - C++

## 📌 Descripción

Este proyecto implementa una clase `Torre` en C++ que representa una torre de ajedrez.

La clase permite:

- Crear torres blancas y negras.
- Definir su posición inicial en el tablero.
- Obtener y modificar sus atributos.
- Validar movimientos.
- Mover la torre horizontal o verticalmente.
- Mostrar el estado actual de la torre.
- Representar visualmente la torre mediante texto.

El tablero utilizado tiene dimensiones de **8 x 8**, utilizando filas y columnas numeradas del **1 al 8**.

---

## 🧩 Clase `Torre`

La clase contiene los siguientes atributos:

### Atributos privados

```cpp
bool esNegro;

Indica el color de la torre:

true → Torre negra.
false → Torre blanca.
Atributos públicos
short fila;
short columna;

Representan la posición actual de la torre en el tablero.

fila → posición vertical, de 1 a 8.
columna → posición horizontal, de 1 a 8.
🔧 Constructor

El constructor permite crear una torre indicando su color y posición inicial.

Torre(bool black, int initialRow, int initialColumn)
{
    esNegro = black;
    fila = initialRow;
    columna = initialColumn;
}
Ejemplo
Torre whiteRook(false, 1, 1);
Torre blackRook(true, 8, 8);

En este caso:

whiteRook es una torre blanca ubicada en (1,1).
blackRook es una torre negra ubicada en (8,8).
🎯 Validación de movimientos

Una torre de ajedrez solamente puede desplazarse:

Horizontalmente.
Verticalmente.

No puede desplazarse diagonalmente.

La función encargada de validar esto es:

bool validateMovement(int newFil, int newCol)

La primera condición comprueba si la nueva columna es igual a la columna actual:

if (newCol == columna && newFil != fila)
{
    return true;
}

Esto representa un movimiento vertical.

La segunda condición comprueba si la nueva fila es igual a la fila actual:

if (newFil == fila && newCol != columna)
{
    return true;
}

Esto representa un movimiento horizontal.

Si ninguna condición se cumple, el movimiento es inválido.

🚶 Método move()

El método:

bool move(int newFila, int newColumna)

se encarga de realizar el movimiento de la torre.

Primero comprueba que la nueva posición esté dentro del tablero:

if (newFila < 1 || newFila > 8 ||
    newColumna < 1 || newColumna > 8)

Después utiliza validateMovement() para comprobar que el movimiento sea horizontal o vertical.

Si el movimiento es válido, se actualiza la posición:

fila = newFila;
columna = newColumna;
🔍 Getters

El programa contiene métodos para obtener los valores de los atributos:

int getFila()

Obtiene la fila actual.

int getColumna()

Obtiene la columna actual.

bool getEsNegro()

Obtiene el color de la torre.

✏️ Setters

También se utilizan métodos para modificar los atributos.

Cambiar fila
void setFila(int newFila)

Solo permite valores entre 1 y 8.

Cambiar columna
void setColumn(int newColumna)

Solo permite valores entre 1 y 8.

Cambiar color
void setEsNegro(bool Negro)

Permite modificar el color de la torre.

🎨 Método draw()

El método draw() proporciona una representación visual de la torre:

string draw()

Para la torre negra:

[##]

Para la torre blanca:

[TT]
📊 Método printState()

Este método muestra la información actual de la torre:

void printState()

Por ejemplo:

[TT] White at Row: 1, Col: 1

o:

[##] Black at Row: 8, Col: 8
🖥️ Funcionamiento del programa

El programa principal crea dos objetos:

Torre whiteRook(false, 1, 1);
Torre blackRook(true, 8, 8);

Después muestra sus posiciones iniciales.

Posteriormente solicita al usuario una nueva fila y columna para la torre blanca.

Si el movimiento es inválido, el programa vuelve a solicitar los datos:

while (!movimientoValido)

El mismo procedimiento se realiza posteriormente para la torre negra.

▶️ Ejemplo de ejecución
===== ESTADO INICIAL =====

Torre blanca: [TT] White at Row: 1, Col: 1
Torre negra: [##] Black at Row: 8, Col: 8

===== TORRE BLANCA =====

Ingrese nueva fila (1-8): 1
Ingrese nueva columna (1-8): 5

Movimiento valido.

Estado final de la torre blanca:
[TT] White at Row: 1, Col: 5

Si se intenta realizar un movimiento diagonal:

Ingrese nueva fila (1-8): 4
Ingrese nueva columna (1-8): 5

Error: movimiento invalido.
La torre solo puede moverse horizontal o verticalmente.

El programa volverá a solicitar una posición.

🛠️ Tecnologías utilizadas
Lenguaje: C++
Paradigma: Programación Orientada a Objetos (POO)
Entrada/Salida: iostream
Cadenas: string
