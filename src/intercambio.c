#include <stdio.h>
#include <stdlib.h>

//#define MAX_DATOS 0x10000

#define ROWS (MAX_DATOS/256)
#define COLS (256)

int main(int argc, char** argv){
    double tripple_arr[ROWS][COLS];
#if CASO == 1   
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            tripple_arr[i][j] = (double)(i+COLS+ROWS+j);
        }
    }
    return 0;
#else
    for(int j=0; j<COLS; j++){
        for(int i=0; i<ROWS; i++){
            tripple_arr[i][j] = (double)(i+COLS+ROWS+j);
        }
    }
    return 0;
#endif
}
