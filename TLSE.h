#include <stdio.h>
#include <stdlib.h>

//Lista modificada para as necessidades do trabalho
//Nao precisa mecher mais aqui a principio

typedef struct lse{
  int ano;
  int *info; // [FR, AU, US, WI] 0 = lost, 1 = finalist, 2 = winner
  struct lse *prox;
} TLSE;

TLSE* TLSE_insere(TLSE *l, int* title, int ano);
void TLSE_imprime(TLSE *l);
void TLSE_libera(TLSE *l);
TLSE* TLSE_busca(TLSE *l, int ano);
TLSE* TLSE_retira(TLSE *l, int ano);
