#ifndef Player_H
#define Player_H


#include "TLSE.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Active{
    int idade, point;
    char nasc[30];
}Act;

typedef struct PlayTree{
  char *name;
  TLSE* slans;
  Active *active; // Null if inactive
}BT;

//Nada aqui foi mechido
BT *BT_Inicializa();
BT *BT_Cria(int t);
BT *BT_Libera(BT *a);
BT *BT_Busca_Nome(BT* x, char* name);
BT *BT_Busca_Pais(BT* x, char* pais);
BT *BT_Carrega(BT *T, int k, int t);
BT *BT_Insere(BT *T, int k, int t); //TODO: Mudar parametros
BT* BT_Retira(BT* arv, int k, int t);
void BT_Imprime(BT *a);


#endif // Player_H
