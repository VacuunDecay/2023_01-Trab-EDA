#include "MyUtil.h"
#include <stdio.h>

void waitKey() {
    printf("Aperte enter para continuar...");
    getchar(); // Por causa do enter
    getchar(); // Espera uma tecla
}
