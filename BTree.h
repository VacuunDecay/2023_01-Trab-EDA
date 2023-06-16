#ifndef Player_H
#define Player_H


#include "TLSE.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Active{
    char nasc[30];
    int idade, point;
}Act;

typedef struct PlayTree{
    int nchaves, folha;
    struct PlayTree **filho;
    char **chave; //Um vetor de strigs cada string gurda o nome de um jogador
    TLSE **slans;
    Active **active; // Null if inactive
}BT;

//Implementadas
BT *BT_Inicializa();
BT *BT_Insere(BT *T, char* k, int t); //TODO: Mudar parametros
void BT_Imprime(BT *a);
void BT_Imprime_el(BT *a, char* nome);

//Nao implementadas
BT *BT_Cria(int t);
BT *BT_Libera(BT *a);
BT *BT_Busca_Nome(BT* x, char* nome); // IPC 1
BT *BT_Busca_Pais(BT* x, char* pais);
BT *BT_Carrega(BT *T, int k, int t); // ?
BT* BT_Retira(BT* arv, char* k, int t);


#endif // Player_H
