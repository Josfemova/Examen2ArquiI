#include <stdio.h>
#include <stdlib.h>

// Se define con el Makefile a partir de una variable de ambiente
// #define MAX_DATOS 0x10000

#if CASO == 1
/**
 * Struct que contiene las 4 coordenadas
 */
typedef struct {
  double x;
  double y;
  double z;
  double t;
} coords;
#endif

int main(int argc, char** argv) {
  // Inicializar variables. No se les da un valor puesto que no importa
  // qué datos estén en los arreglos.
#if CASO == 1
  // caso en que se aplica la optimización.
  coords datos[MAX_DATOS];
#else
  // caso en que no se aplica la optimización. Los datos de cada coordenada
  // están en arreglos por separado.
  double coords_x[MAX_DATOS];
  double coords_y[MAX_DATOS];
  double coords_z[MAX_DATOS];
  double coords_t[MAX_DATOS];
#endif
  // Recorrer toda la lista de datos calculando el valor de cada coordenada
  // basado en coordenadas del mismo index. El cálculo no tiene nada especial,
  // solo busca hacer un cálculo que se beneficie de localidad espacial de los
  // datos
  for (int i = 0; i < MAX_DATOS; i++) {
#if CASO == 1
    // datos de este caso están todos contiguos en memoria pues son
    // parte de la misma instancia de un struct
    datos[i].x = datos[i].y - datos[i].z + datos[i].t;
    datos[i].y = datos[i].x + datos[i].z - datos[i].t;
    datos[i].z = datos[i].y * datos[i].x / datos[i].t;
    datos[i].t = datos[i].x - datos[i].z * datos[i].y;
#else
    // Datos de este caso se encuentran en distintos arreglos, por lo cual
    // su ubicación en memoria no es contigua.
    coords_x[i] = coords_y[i] - coords_z[i] + coords_t[i];
    coords_y[i] = coords_x[i] + coords_z[i] - coords_t[i];
    coords_z[i] = coords_y[i] * coords_x[i] / coords_t[i];
    coords_t[i] = coords_x[i] - coords_z[i] * coords_y[i];
#endif
  }

  return 0;
}
