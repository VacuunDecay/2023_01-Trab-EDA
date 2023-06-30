#include "exercicios.h"
#include "MyUtil.h"
#include "BTree.h"
#include "TLSE.h"
//#include "TLSEno.h"

/**Nao implementada*/
void exer_1 (){

}
/*Nao testada*/
void exercicioB(BT *a){
    if(!a)return;
    aux_exercicioB(a,a);
}
void aux_exercicioB(BT *a,BT *b){
    if(!a||!b)return;
    for(int i=0;i<a->nchaves;i++){
        for(int j=0;j<b->nchaves;j++){
            if((a->active[i])&&(b->active[j])&&(strcmp(a->active[i]->nasc,b->active[j]->nasc)==0)){
                int year = 2023-(a->active[i]->idade);
                TLSE *l=b->slans[j];
                while(l){
                    if(l->ano==year&&(l->info[0)==1)printf("\nJogador %s ganhou no ano %d que nasceu %s.\n",b->chave[j],year,a->chave[i]);
                    l=l->prox;
                }
            }
        }
    }
    for(int j=0;j<b->nchaves+1;j++)aux_exercicioB(a,b->filho[j]);
    for(int i=0;i<a->nchaves+1;i++)aux_exercicioB(a->filho[i],b);
}

/**Nao implementada*/
void exer_3 (){

}
/**Nao implementada*/
void exer_4 (){

}

/**Nao implementada*/
int Qe (BT * a, int av){
  int alguem_venceu = av;
    if(a){
      for(int i = 0; i<=a->nchaves;i++){
        if((!a->active[i]) && (a->slans)){
          int slans_vencidos = 0;
          TLSE *p = a->slans[i];
          while(p){
            if(p->info[0] == 1 && p->info[1] == 1 && p->info[2] == 1 && p->info[3] == 1){
              alguem_venceu++;
              printf("%s venceu todos os slans no ano %d\n", a->chave[i], p->ano);
            }
            p = p->prox;
          }
        }
        alguem_venceu = Qe(a->filho[i], alguem_venceu);
      }
    }
    return alguem_venceu;
}

void exer_5(BT * bt){
  if(Qe(bt, 0) == 0)printf("Nenhum jogador aposentado venceu todos os slans no mesmo ano.\n");
}

/**Nao implementada*/
int Qf(BT * a, int av){
  int alguem_venceu = av;
  if(a){
    for(int i = 0; i<=a->nchaves;i++){
      if((a->active[i]) && (a->slans)){
        int slans_vencidos = 0;
        TLSE *p = a->slans[i];
        while(p){
          if(p->info[0] == 1 && p->info[1] == 1 && p->info[2] == 1 && p->info[3] == 1){
            alguem_venceu++;
            printf("%s venceu todos os slans no ano %d\n", a->chave[i], p->ano);
          }
          p = p->prox;
        }
      }
      alguem_venceu = Qf(a->filho[i], alguem_venceu);
    }
  }
  return alguem_venceu;
}

void exer_6 (BT * bt){
  if(Qf(bt, 0) == 0)printf("Nenhum jogador ativo venceu todos os slans no mesmo ano.\n");
}

/**Nao implementada*/
BT* exercicioG(BT *a,char *c){
    if(!a)return;
    int t=(sizeof(a->nchaves)/sizeof(a->chave[0]));//testar para saber de funciona com vetor de char P.S:funciona com vetor de int
    for(int i=0;i<a->nchaves;i++){
        if(a->active[i]){
            if(strcmp(a->active[i]->nasc,c)==0)a=BT_Retira(a,a->chave[i],t);//se o jogador for ativo e a nacionalidade for igual a digitada remove
            i=0;//repassa a arvore para evitar que haja qualquer jogador de tal nacionalidade que tenha sido movido por alguma rotação
        }
    }
    for(int i=0;i<a->nchaves;i++)a->filho[i]=exercicioG(a->filho[i],c);
    return a;
}

