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

char* country(char *a){//RETORNA O PAIS ENTRE COLCHETES
    char *b=(char*)malloc(sizeof(char*));
    strcpy(b,"[");
    strcat(b,a);
    strcat(b,"]");
    return b;
}

void cls() {
    #ifdef _WIN32
        // For Windows
        system("cls");
    #else
        // For UNIX-based systems (Linux, macOS, etc.)
        system("clear");
    #endif
}
