#include <stdio.h>
#include <stdlib.h>

// Se define con el Makefile a partir de una variable de ambiente
// #define MAX_DATOS 0x10000

// Dimensiones del arreglo de prueba
#define ROWS (MAX_DATOS / 256)
#define COLS (256)

int main(int argc, char** argv) {
  // Se crea la matriz a recorrer. No importan los datos iniciales del arreglo
  // pues nunca se leen.
  double tripple_arr[ROWS][COLS];
#if CASO == 1
  // Recorrer el arreglo por el orden FILAS->COLUMNAS. Este es el caso
  // optimizado. El intercambio de ciclos hace que el acceso al arreglo resulte
  // en accesos contiguos en memoria
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      tripple_arr[i][j] = (double)(i + COLS + ROWS + j);
    }
  }
  return 0;
#else
  // Recorrer el arreglo por orden COLUMNAS->FILAS. Este caso es el no
  // optimizado. En vez de ser accesos contiguos, cada acceso está separado por
  // COLS datos
  for (int j = 0; j < COLS; j++) {
    for (int i = 0; i < ROWS; i++) {
      tripple_arr[i][j] = (double)(i + COLS + ROWS + j);
    }
  }
  return 0;
#endif
}
