#include "MyUtil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ln(){
    printf("\n");
}

void waitKey() {
    printf("Aperte enter para continuar...");
    getchar(); // Por causa do enter
    getchar(); // Espera uma tecla
}

char** splitStr(char* line, char* key, int numCol){
    char** cols = (char**)malloc(sizeof(char*)*numCol);
    char* col;
    int i = 0;

    col = strtok(line, key);
    while(col != NULL & i < numCol){
        cols[i] = strdup(col);
        i++;
        col = strtok(NULL, key);
    }

    //*numCol = i;

    return cols;
}
