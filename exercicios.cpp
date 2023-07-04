#include "exercicios.h"

//#include "TLSEno.h"

void aux_exercicioB(BT* a,BT* b){
    if(!a||!b)return;
    for(int i=0;i<a->nchaves;i++){
        for(int j=0;j<b->nchaves;j++){
            if((a->active[i])&&(b->active[j])&&(strcmp(a->active[i]->nasc,b->active[j]->nasc)==0)&&(strcmp(a->chave[i],b->chave[j])!=0)){
                int year = 2023-(b->active[j]->idade);
                TLSE *l=a->slans[i];
                while(l){
                    if((l->ano==year)&&(l->info[0])==1)printf("\nJogador %s ganhou no ano %d que nasceu %s.\n",a->chave[i],year,b->chave[j]);
                    l=l->prox;
                }
            }
        }
    }
    for(int j=0;j<b->nchaves+1;j++)aux_exercicioB(a,b->filho[j]);
    for(int i=0;i<a->nchaves+1;i++)aux_exercicioB(a->filho[i],b);
}

/*Nao testada*/
void nascmentoPremi(BT *a){
    if(!a)return;
    aux_exercicioB(a,a);
}




/*Exercicios C e D (3 e 4)*/
int pointCalc(TLSE* s){
  TLSE* no = s;
  int points = 0;
  while(no){
    for(int i = 0; i < 4; i++){
      if(no->info[i] == 0) continue;
      points+= (800*no->info[i])+400;
    }
    no = no->prox;
  }
  return points;

}

TLSEp* prencheLiastaHank(BT *a, TLSEp* l, int isAtivo){
  if (a){
    int i, j;
    for (i = 0; i <= a->nchaves-1; i++){
      l = prencheLiastaHank(a->filho[i], l, isAtivo);
      if((a->active[i] == 0 && isAtivo == 0) || (a->active[i] != 0 && isAtivo != 0)){
      //if(a->active == 0){
        if(a->slans != 0){
          l = TLSEp_insere(l, pointCalc(a->slans[i]), PL_criaPL(a, i)); // cria um novo elemento pra l com o calculo da pontuação e um struct com referencias para o no original
          //TLSEp_imprime(l);
        }
      }
    }
    l = prencheLiastaHank(a->filho[i], l, isAtivo);
  }
  return l;
}

void makeSlanHank(BT* a, int isAtivo){
  TLSEp* rankFicticio = NULL;

  rankFicticio =  prencheLiastaHank(a, rankFicticio, isAtivo);
  printf("inprinminto o novo hank\n");
  TLSEp_imprime(rankFicticio);

}

/**Nao implementada*/
TLSEp* Qe(BT * a, TLSEp* l){
  if(a){
    for(int i = 0; i < a->nchaves;i++){
      if((!a->active[i]) && (a->slans[i])){
        int slans_vencidos = 0;
        TLSE *p = a->slans[i];
        while(p){
          if(p->info[0] !=0 && p->info[1] !=0 && p->info[2] !=0 && p->info[3] !=0 ){
            l = TLSEp_insere(l, p->ano, PL_criaPL(a, i));

          }
          p = p->prox;
        }
      }
      l = Qe(a->filho[i], l);
    }
    l = Qe(a->filho[a->nchaves], l);
  }
  return l;
}

void exer_5(BT * bt){
  TLSEp* lista = NULL;
  lista = Qe(bt, lista);

  TLSEp* no = lista;
  if(lista)
    while(no){
      printf("%s venceu todos os slans no ano %d\n", no->info->no->chave[no->info->indice], no->info->no->slans[no->info->indice]);
      no = no->prox;
    }
  else
    printf("Nenhum jogador aposentado venceu todos os slans no mesmo ano.\n");


}


TLSEp* Qf(BT * a, TLSEp* l){
  if(a){
    for(int i = 0; i < a->nchaves;i++){
      if((a->active[i]) && (a->slans[i])){
        int slans_vencidos = 0;
        TLSE *p = a->slans[i];
        while(p){
          if(p->info[0] !=0 && p->info[1] !=0 && p->info[2] !=0 && p->info[3] !=0 ){
            l = TLSEp_insere(l, p->ano, PL_criaPL(a, i));

          }
          p = p->prox;
        }
      }
      l = Qf(a->filho[i], l);
    }
    l = Qf(a->filho[a->nchaves], l);
  }
  return l;
}

void exer_6 (BT * bt){
  TLSEp* lista = NULL;
  lista = Qf(bt, lista);

  TLSEp* no = lista;
  if(lista)
    while(no){
      printf("%s venceu todos os slans no ano %d\n", no->info->no->chave[no->info->indice], no->info->no->slans[no->info->indice]);
      no = no->prox;
    }
  else
    printf("Nenhum jogador aposentado venceu todos os slans no mesmo ano.\n");


}


BT* retiraPais(BT *a,char *c,int t){
    if(!a)return a;
    for(int i=0;i<a->nchaves;i++){
        if(a->active[i]){
            if(strcmp(a->active[i]->nasc,c)==0){
                a = BT_Retira(a,a->chave[i],t);//se o jogador for ativo e a nacionalidade for igual a digitada remove
                i=0;//repassa a arvore para evitar que haja qualquer jogador de tal nacionalidade que tenha sido movido por alguma rotação
            }
        }
    }
    for(int i=0;i<=a->nchaves;i++)a->filho[i]=retiraPais(a->filho[i],c,t);
    return a;
}

BT* mostraPais(BT *a,char *c,int t){
    if(!a)return a;
    for(int i=0;i<a->nchaves;i++){
        if(a->active[i]){
            if(strcmp(a->active[i]->nasc,c)==0)BT_Imprime_el(a, c);
        }
    }
    for(int i=0;i<=a->nchaves;i++)a->filho[i]=mostraPais(a->filho[i],c,t);
    return a;
}



/*Exercico C e D*/


