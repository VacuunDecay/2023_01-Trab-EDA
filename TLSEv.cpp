#include "TLSEv.h"
#include "TLSE.h"
#include "BTree.h"

TLSEv* TLSEv_inicializa(){
  return NULL;
}

TLSEv* TLSEv_insere(TLSEv *l, int titulos, char* nome){
  TLSEv *novo = (TLSEv *) malloc(sizeof(TLSEv));
  novo->nome = nome;
  if(l){novo->id = l->id + 1;}
  else{novo->id = 0;}
  novo->prox = l;
  return novo;
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

void TLSEv_imprime_ord_e_libera(TLSEv* l, BT* b){
  if(l){
    TLSEv* maior = NULL, * aux = l;
    while(aux){
      if(maior == NULL)maior = aux;
      if(aux->titulos > maior->titulos)maior = aux;
      BT_Imprime_el_vencedor(b, maior->nome);
      aux = aux->prox;
      l = TLSEv_remove(l, maior->id);
    }
  }
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
