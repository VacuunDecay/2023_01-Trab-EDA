#ifndef TLSEPLAYER_H
#define TLSEPLAYER_H

#include "BTree.h"
#include "MyUtil.h"

typedef struct player{
    char* nome;
    BT* no;
    int indice;
}PL;


typedef struct lsee{
  int point;
  PL *info; // [FR, AU, US, WI] 0 = lost, 1 = finalist, 2 = winner
  struct lsee *prox;
} TLSEp;

PL* PL_criaPL(BT* b, char* nome);

TLSEp* TLSEp_insere(TLSEp *l, int point, PL* p);

void TLSEp_imprime(TLSEp *l);

void TLSEp_libera(TLSEp *l);

#endif
