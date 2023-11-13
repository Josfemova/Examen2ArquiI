#include <stdio.h>
#include <stdlib.h>

//#define MAX_DATOS 0x10000

#if CASO == 1
typedef struct{
    double x;
    double y;
    double z;
    double t;
}coords;
#endif

int main(int argc, char** argv){
#if CASO == 1
    coords datos[MAX_DATOS];
#else
    double coords_x[MAX_DATOS];
    double coords_y[MAX_DATOS];
    double coords_z[MAX_DATOS];
    double coords_t[MAX_DATOS];
#endif
    // algoritmo a aplicar 
    for(int i=0; i< MAX_DATOS; i++){
#if CASO == 1
        datos[i].x = datos[i].y - datos[i].z + datos[i].t;
        datos[i].y = datos[i].x + datos[i].z - datos[i].t;
        datos[i].z = datos[i].y * datos[i].x / datos[i].t;
        datos[i].t = datos[i].x - datos[i].z * datos[i].y;
#else
        coords_x[i] = coords_y[i] - coords_z[i] + coords_t[i];
        coords_y[i] = coords_x[i] + coords_z[i] - coords_t[i];
        coords_z[i] = coords_y[i] * coords_x[i] / coords_t[i];
        coords_t[i] = coords_x[i] - coords_z[i] * coords_y[i];
#endif
    }

    return 0;
}
