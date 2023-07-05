#include "TLSE.h"

TLSE* TLSE_insere(TLSE *l, int ano){
  TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
  novo->prox = l;
  novo->ano = ano;
  novo->info = (int*)malloc(sizeof(int)*4);

  for(int i = 0; i < 4;i++){
    novo->info[i] = 0;
  }
  return novo;
}

TLSE* TLSE_insere_t(TLSE *l,int* title, int ano){
  //OBS: title precisa ser alocado dinamicamente previamente
  TLSE *novo = (TLSE *) malloc(sizeof(TLSE));
  novo->prox = l;
  novo->ano = ano;
  novo->info = title;
  return novo;
}
void TLSE_imprime(TLSE *l){
  TLSE *p = l;
  while(p){
    int *vet = p->info;
    printf("--------------------\n");
    printf("Ano: %d ", p->ano);
    printf("Slams: %d, %d, %d, %d\n", p->info[0], p->info[1], p->info[2], p->info[3]);
    p = p->prox;
  }
  printf("\n");
}

void TLSE_imprime_ident(TLSE *l, int andar){
  TLSE *p = l;
  int j;
  while(p){
    int *vet = p->info;
    if(p != l)
        for(j=0; j<=andar; j++) printf("\t");
    printf("--------------------\n");

    for(j=0; j<=andar; j++) printf("\t");
    printf("Ano: %d\n", p->ano);

    for(j=0; j<=andar; j++) printf("\t");
    printf("Slams: %d, %d, %d, %d\n", p->info[0], p->info[1], p->info[2], p->info[3]);
    p = p->prox;
  }
  printf("\n");
}


void TLSE_libera(TLSE *l){
  TLSE *p = l, *q;
  while(p){
    q = p;
    p = p->prox;
    free(q->info);
    free(q);
  }
}

TLSE* TLSE_busca(TLSE *l, int ano){
  TLSE *p = l;
  while((p) && (p->ano != ano)) p = p->prox;
  return p;
}

//By chatGPT
TLSE* TLSE_retira(TLSE *l, int ano) {
    TLSE *ant = NULL; 
    TLSE *p = l; 

    while (p != NULL && p->ano != ano) {
        ant = p;
        p = p->prox;
    }

    
    if (p != NULL) {
        if (ant == NULL)
            l = p->prox;
        else
            ant->prox = p->prox;
        free(p); 
    }

    return l; 
}

