#include "BTree.h"

typedef struct LSEv{
  int titulos, id;
  char* nome;
  struct LSEv *prox;
}TLSEv;

TLSEv* TLSEv_insere(TLSEv *l, int titulos, char* nome);

void TLSEv_libera(TLSEv *l);

TLSEv* TLSEv_inicializa();

void TLSEv_imprime_ord_e_libera(TLSEv* l, BT* b);

TLSEv* TLSEv_remove(TLSEv* l, int id);
