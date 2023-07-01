#include "TLSEplayer.h"



PL* PL_criaPL(BT* b, char* nome){
  int pos = 0;

  PL* novo = (PL*)malloc(sizeof(PL));

  novo->nome = nome;
  novo->no = BT_Busca_Nome(b, nome, &pos);
  novo->indice = pos;

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

  printf("inserindo: %s\n", novo->info->nome);

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

/*
TLSEp* TLSEp_busca(TLSEp *l, int point){
  TLSEp *p = l;
  while((p) && (p->point != point)) p = p->prox;
  return p;
}

//By chatGPT
TLSEp* TLSEp_retira(TLSEp *l, int point) {
    TLSEp *ant = NULL; // Pointer to the previous node
    TLSEp *p = l; // Pointer to traverse the list

    // Search for the element in the list
    while (p != NULL && p->point != point) {
        ant = p;
        p = p->prox;
    }

    // If the element is found
    if (p != NULL) {
        // If it's the first element
        if (ant == NULL)
            l = p->prox;
        else
            ant->prox = p->prox;

        free(p); // Free the memory for the node
    }

    return l; // Return the updated list
}
    */

