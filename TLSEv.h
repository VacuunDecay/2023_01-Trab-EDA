#ifndef TLSEV_H
#define TLSEV_H

#include "BTree.h"
#include "TLSE.h"

typedef struct LSEv{
  int titulos, id;
  char* nome;
  TLSE* slans;
  struct LSEv *prox;
}TLSEv;

TLSEv* TLSEv_insere(TLSEv *l, int titulos, char* nome, TLSE *slan);

void TLSEv_libera(TLSEv *l);

TLSEv* TLSEv_inicializa();

void TLSEv_imprime(TLSEv* l);

TLSEv* TLSEv_remove(TLSEv* l, int id);
#endif // TLSEV_H
