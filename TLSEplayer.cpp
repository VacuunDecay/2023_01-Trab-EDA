#include "TLSEplayer.h"



PL* PL_criaPL(BT* b, int ind){

  PL* novo = (PL*)malloc(sizeof(PL));

  novo->nome = b->chave[ind];
  novo->no = b;
  novo->indice = ind;

  return novo;
}

TLSEp* TLSEp_insere(TLSEp *l, int point, PL* p){
  TLSEp *novo = (TLSEp *) malloc(sizeof(TLSEp));
  if(!novo) return l;
  novo->point = point;
  novo->info = p;
  novo->prox = NULL;

  if (!novo->info) {
    free(novo);
    return l;
  }

  if (l == NULL || point > l->point) {
    novo->prox = l;
    return novo;
  }

  TLSEp* atual = l;
  TLSEp* anterior = NULL;

  while (atual != NULL && point < atual->point) {
    anterior = atual;
    atual = atual->prox;
  }

  if (anterior != NULL) {
    anterior->prox = novo;
  }

  novo->prox = atual;

  return l;
}


void TLSEp_imprime(TLSEp *l){
  if(!l) return;
  TLSEp *p = l;
  int i = 0;
  while(p){
    i++;
    printf("--------------------\n");
    printf("Nome: %s\n", p->info->nome);
    printf("Colocacao: %d\n", i);
    printf("Pontuacao: %d\n", p->point);
    p = p->prox;
  }
  printf("\n");
}


void TLSEp_libera(TLSEp *l){
  TLSEp *p = l, *q = NULL;
  while(p){
    q = p;
    p = p->prox;
    free(q->info);
    free(q);
  }
}

