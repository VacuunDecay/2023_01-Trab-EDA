#include "TLSEv.h"
#include "TLSE.h"
#include "BTree.h"

TLSEv* TLSEv_inicializa(){
  return NULL;
}

TLSEv* TLSEv_insere(TLSEv *l, int titulo,char* nome, TLSE* slan){
  TLSEv *novo = (TLSEv *) malloc(sizeof(TLSEv));
  if(!novo) return l;
  novo->id = 0;
  novo->titulos = titulo;
  novo->nome = nome;
  novo->slans = slan;
  novo->prox = NULL;

  if (!novo->nome) {
    free(novo);
    return l;
  }

  if (l == NULL || titulo > l->titulos) {
    novo->prox = l;
    return novo;
  }

  TLSEv* atual = l;
  TLSEv* anterior = NULL;

  while (atual != NULL && titulo < atual->titulos) {
    anterior = atual;
    atual = atual->prox;
  }

  if (anterior != NULL) {
    anterior->prox = novo;
  }

  novo->prox = atual;

  return l;
}

void TLSEv_libera(TLSEv *l){
  if(l){
    TLSEv *p = l, *q = NULL;
    while(p){
      q = p;
      p = p->prox;
      free(q);
    }
  }
}

void TLSEv_imprime(TLSEv *l){
  if(!l) return;
  TLSEv *p = l;
  int i = 0;
  while(p){
    i++;
    printf("--------------------\n");
    printf("Nome: %s\n", p->nome);
    printf("Titulos: %d\n", p->titulos);
    printf("Slans:\n");
    TLSE_imprime(p->slans);
    p = p->prox;
  }
  printf("\n");
}

TLSEv* TLSEv_remove(TLSEv* l, int id){
  if(l){
    TLSEv * p = l, * ant = NULL;
    while(p && p->id != id){
      ant = p;
      p = p->prox;
    }
    if(!p)return l;
    if(ant == NULL){
      l = l->prox;
      free(p);
    }
    else{
      ant->prox = p->prox;
      free(p);
    }
  }
  return l;
}
