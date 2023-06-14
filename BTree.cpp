#include "BTree.h"

BT *BT_Inicializa(){
    return NULL;
}

BT *BT_Cria(int t){
  BT* novo = (BT*)malloc(sizeof(BT));
  novo->nchaves = 0;
  novo->folha=1;
  novo->filho = (BT**)malloc(sizeof(BT*)*t*2);
  novo->chave =(char**)malloc(sizeof(char*)*((t*2)-1));
  novo->slans = NULL;
  novo->active = NULL;
  int i;
  for(i = 0; i < (t*2); i++) novo->filho[i] = NULL;
  for(i = 0; i < (t*2); i++)
    novo->chave[i] =(char*)malloc(sizeof(char)*50);// 50 � arbitrario
  return novo;
}

BT *BT_Libera(BT *a){

}

BT *BT_Busca_Nome(BT* x, char* name){

}

BT *BT_Busca_Pais(BT* x, char* pais){

}

BT *Divisao(BT *x, int i, BT* y, int t){
  BT *z=BT_Cria(t);
  z->nchaves= t - 1;
  z->folha = y->folha;
  int j;
  for(j=0;j<t-1;j++) z->chave[j] = y->chave[j+t];
  if(!y->folha){
    for(j=0;j<t;j++){
      z->filho[j] = y->filho[j+t];
      y->filho[j+t] = NULL;
    }
  }
  y->nchaves = t-1;
  for(j=x->nchaves; j>=i; j--) x->filho[j+1]=x->filho[j];
  x->filho[i] = z;
  for(j=x->nchaves; j>=i; j--) x->chave[j] = x->chave[j-1];
  x->chave[i-1] = y->chave[t-1];
  x->nchaves++;
  return x;
}

// Acho que para comparar strins preciso da biblioteca strings
BT *Insere_Nao_Completo(BT *x, char* k, int t){
  int i = x->nchaves-1;
  if(x->folha){
    while((i>=0) && (k<x->chave[i])){
      x->chave[i+1] = x->chave[i];
      i--;
    }
    x->chave[i+1] = k;
    x->nchaves++;
    return x;
  }
  while((i>=0) && (k<x->chave[i])) i--;
  i++;
  if(x->filho[i]->nchaves == ((2*t)-1)){
    x = Divisao(x, (i+1), x->filho[i], t);
    if(k>x->chave[i]) i++;
  }
  x->filho[i] = Insere_Nao_Completo(x->filho[i], k, t);
  return x;
}


BT *BT_Insere(BT *T, char* k, int t){
  if(BT_Busca_Nome(T,k)) return T;
  if(!T){
    T=BT_Cria(t);
    T->chave[0] = k;
    T->nchaves=1;
    return T;
  }
  if(T->nchaves == (2*t)-1){
    BT *S = BT_Cria(t);
    S->nchaves=0;
    S->folha = 0;
    S->filho[0] = T;
    S = Divisao(S,1,T,t);
    S = Insere_Nao_Completo(S,k,t);
    return S;
  }
  T = Insere_Nao_Completo(T,k,t);
  return T;
}


BT* BT_Retira(BT* arv, int k, int t){

}

void imp_rec(BT *a, int andar){
  if(a){
    int i,j;
    for(i=0; i<=a->nchaves-1; i++){
      imp_rec(a->filho[i],andar+1);
      for(j=0; j<=andar; j++) printf("\t");
      printf("----------------------\n");

      for(j=0; j<=andar; j++) printf("\t");
      printf("Nome: %s\n", a->chave[i]);

      for(j=0; j<=andar; j++) printf("\t");
      printf("Active: %d\n", a->active);

      for(j=0; j<=andar; j++) printf("\t");
      printf("Slams: %d, %d, %d, %d\n",
             a->slans->info[0],
             a->slans->info[1],
             a->slans->info[2],
             a->slans->info[3]);
    }
    imp_rec(a->filho[i],andar+1);
  }
}


void BT_Imprime(BT *a){
  imp_rec(a, 0);
}

