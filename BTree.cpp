#include "BTree.h"
#include "MyUtil.h"


BT *BT_Inicializa(){
    return NULL;
}

BT *BT_Cria(int t){
    BT* novo = (BT*)malloc(sizeof(BT));
    novo->nchaves = 0;
    novo->folha=1;
    novo->filho = (BT**)malloc(sizeof(BT*)*t*2);
    novo->chave =(char**)malloc(sizeof(char*)*((t*2)-1));
    novo->slans = (TLSE**)malloc(sizeof(TLSE*)*((t*2)-1));
    novo->active = (Active**)malloc(sizeof(Active*)*((t*2)-1));
    int i;
    for(i = 0; i < (t*2); i++) novo->filho[i] = NULL;
    for (i = 0; i < ((2 * t) - 1); i++) {
        novo->chave[i] = (char*)malloc(sizeof(char) * 50);
        novo->chave[i][0] = '\0';
    }

    for (i = 0; i < ((2 * t) - 1); i++) {
        novo->slans[i] = NULL;
    }

    for (i = 0; i < ((2 * t) - 1); i++) {
        novo->active[i] = NULL;
    }
    return novo;
}

BT *BT_Libera(BT *a){
  if(a){
    if(!a->folha){
      int i;
      for(i = 0; i <= a->nchaves; i++) BT_Libera(a->filho[i]);
    }
    free(a->chave);
    free(a->filho);
    for(int i = 0; i > a->nchaves; i++)
        free(a->active[i]);
    free(a->active);
    for(int i = 0; i < a->nchaves; i++)
        TLSE_libera(a->slans[i]);
    free(a->slans);
    free(a);
    return NULL;
  }
}

BT *BT_Busca_Nome(BT* x, char* nome, int* pos){
  if(!x) return NULL;
  int i = 0;
  while(i < x->nchaves && strcmp(nome, x->chave[i]) > 0) i++;
  if(i < x->nchaves && strcmp(nome, x->chave[i]) == 0){
    if(pos)
      *pos = i;
    return x;
  }
  if(x->folha) return NULL;
  return BT_Busca_Nome(x->filho[i], nome, pos);
}

BT *BT_Busca_Pais(BT* x, char* pais){

}
/**x = pai, y = no*/
BT *Divisao(BT *x, int i, BT* y, int t){
  BT *z=BT_Cria(t);
  z->nchaves= t - 1;
  z->folha = y->folha;
  int j;
  for(j=0;j<t-1;j++) {
        z->chave[j] = y->chave[j+t];
        z->slans[j] = y->slans[j+t];
        z->active[j] = y->active[j+t];

  }
  if(!y->folha){
    for(j=0;j<t;j++){
      z->filho[j] = y->filho[j+t];
      y->filho[j+t] = NULL;
    }
  }
  y->nchaves = t-1;
  for(j=x->nchaves; j>=i; j--) x->filho[j+1]=x->filho[j];
  x->filho[i] = z;
  for(j=x->nchaves; j>=i; j--) {
    x->chave[j] = x->chave[j-1];
    x->slans[j] = x->slans[j-1];
    x->active[j] = x->active[j-1];
  }
  x->chave[i-1] = y->chave[t-1];
  x->slans[i-1] = y->slans[t-1];
  x->active[i-1] = y->active[t-1];
  x->nchaves++;
  return x;
}

BT *Insere_Nao_Completo(BT *x, char* k, int t) {
    int i = x->nchaves - 1;
    if (x->folha) {
        while ((i >= 0) && (strcmp(k, x->chave[i]) < 0)) {
            char* aux2 = x->chave[i+1];//?
            char* aux1 = x->chave[i];//?
            x->chave[i+1] = x->chave[i];
            x->slans[i+1] = x->slans[i];
            x->active[i+1] = x->active[i];
            i--;
        }
        x->chave[i+1] = k;
        //slans e active?
        x->nchaves++;
        return x;
    }
    while ((i >= 0) && (strcmp(k, x->chave[i]) < 0))
        i--;
    i++;
    if (x->filho[i]->nchaves == ((2*t)-1)) {
        x = Divisao(x, (i+1), x->filho[i], t);
        if (strcmp(k, x->chave[i]) > 0)
            i++;
    }
    x->filho[i] = Insere_Nao_Completo(x->filho[i], k, t);
    return x;
}

BT *BT_Insere(BT *T, char* k, int t){
  if(BT_Busca_Nome(T,k, NULL)) return T;
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
      printf("\n");

      for(j=0; j<=andar; j++) printf("\t");
      printf("Nome: %s\n", a->chave[i]);

      for(j=0; j<=andar; j++) printf("\t");
      printf("Active: %d\n", a->active[i]);


      for(j=0; j<=andar; j++) printf("\t");
      if(!a->slans[i]){
            printf("Jogador nao tem slans\n");
            continue;
      }
      printf("Slans: %d\n", a->slans[i]);
      //TLSE_imprime_ident(a->slans[i], andar);

    }
    imp_rec(a->filho[i],andar+1);
  }
}


void BT_Imprime(BT *a){
    cls();
    imp_rec(a, 0);
}


void BT_Imprime_el(BT *a, char* nome){
    int pos = 0;
    BT* no = BT_Busca_Nome(a, nome, &pos);

    if(!no){
        printf("no Nao encontrado");
        return;
    }

    printf("\n");
    printf("Nome: %s\n", no->chave[pos]);

    if(!no->active){
        printf("Active: Nao\n");
    }else{
        printf("Active: Sim\n");
        printf("   pais: %s\n", no->active[pos]->nasc);
        printf("   pontos: %d\n", no->active[pos]->point);
        printf("   rank: %d\n", no->active[pos]->rancking);
        printf("   idade: %d\n", no->active[pos]->idade);
    }

    if(!no->slans[pos]){
        printf("Slans: Nao\n");
        return;
    }else{
        printf("Slans: Sim\n");
        TLSE_imprime(no->slans[pos]);
    }


}
BT* BT_Preenche_Slam(BT* T, char** line, int t)

{
    //estrae de char os valores do campo
    int ano = atoi(line[0]);
    char* win = line[2];
    char* vice = line[3];
    strtok(vice, "\n");

    //posicoes dos jogadores dentro do no
    int posW = -1;
    int posV = -1;

    //criando os nos se eles nao existirem
    BT* noWin = BT_Busca_Nome(T, win, &posW);
    if(!noWin){
        T = BT_Insere(T, win, t);
    }

    BT* noVice = BT_Busca_Nome(T, vice, &posV);
    if(!noVice){
        T = BT_Insere(T, vice, t);
    }


    if(!noWin){
        noWin = BT_Busca_Nome(T, win, &posW);
    }
    if(!noVice){
        noVice = BT_Busca_Nome(T, vice, &posV);
    }

    if(posW == -1){
        printf("Algo deu errado com o nome do vencedor\n");
        return NULL;
    }

    if(posV == -1){
        printf("Algo deu errado com o nome do vice\n");
        return NULL;
    }

    int camp = 0;
    switch (line[1][0]){
    case 'U': camp = 0;  break;
    case 'W': camp = 1;  break;
    case 'F': camp = 2;  break;
    case 'A': camp = 3;  break;
    default: camp = -1; break;
    }
    if(camp == -1){
        printf("Nome passado para campeonato nao valido: %s\n", line[1]);
        return NULL;
    }

    //preencendo a informa��o do slam
    TLSE* liW = TLSE_busca(noWin->slans[posW], ano);
    TLSE* liV = TLSE_busca(noVice->slans[posV], ano);
    if(!liW){
        liW = TLSE_insere(noWin->slans[posW], ano);
    }
    if(!liV){
        liV = TLSE_insere(noVice->slans[posV], ano);
    }

    liW->info[camp] = 1;
    liV->info[camp] = 2;

    noWin->slans[posW] = liW;
    noVice->slans[posV] = liV;


    return T;
}

BT* BT_Preenche_Act(BT* T, char** line, int t){
    int ranking = atoi(line[0]);
    char* pais = line[1];
    char* nome = (char*)malloc(sizeof(char)*(strlen(line[2])+1));
    nome = line[2];
    int point = atoi(line[3]);
    int idade = atoi(line[4]);

    int pos = -1;

    BT* no = BT_Busca_Nome(T, nome, &pos);
    if(!no){
        T = BT_Insere(T, nome, t);
    }


    if(!no){
        no = BT_Busca_Nome(T, nome, &pos);
    }

    if(pos == -1){
        printf("Algo deu errado com o nome do jogador\n");
        return NULL;
    }

    Act* ac = ac =(Act*)malloc(sizeof(Act));

    ac->idade = idade;
    ac->nasc = pais;
    ac->point = point;
    ac->rancking = ranking;

    no->active[pos] = ac;

    return T;
}

BT* BT_preench_arvore(BT* bt, int t){
    FILE* fiJogs = fopen("jog_atuais.txt", "r");
    FILE* fiSlans = fopen("era_aberta_grand_slams.txt", "r");
    if (fiJogs == NULL) {
        printf("Failed to open the file atuais.\n");
        exit(1);
    }
    if (fiSlans == NULL) {
        printf("Failed to open the file slam.\n");
        exit(1);
    }
    char line[100];
    while (fgets(line, sizeof(line), fiSlans) != NULL) {
        int numTokens = 4;
        char** tokens = splitStr(line, "\t", numTokens);

        bt = BT_Preenche_Slam(bt, tokens, t);



        free(tokens);
    }

    while (fgets(line, sizeof(line), fiJogs) != NULL) {
        int numTokens = 5;
        char** tokens = splitStr(line, "\t", numTokens);

        bt = BT_Preenche_Act(bt, tokens, t);



        free(tokens);
    }
    fclose(fiJogs);
    fclose(fiSlans);
    return bt;
};
BT* remover(BT* arv,char *nome,int t){
    int i;
    printf("REMOVENDO:%s",nome);
    for(i=0; i < arv->nchaves && strcmp(arv->chave[i],nome) <0 ;i++);
    if(arv->folha){//CASO 1
        int j;
        for(j=i;j<arv->nchaves;j++){
            strcpy(arv->chave[j],arv->chave[j+1]);
            arv->slans[j]=arv->slans[j+1];
            arv->active[j]=arv->active[j+1];
        }
        arv->nchaves--;
        if(!arv->nchaves){
            BT_Libera(arv);
            arv=NULL;
        }
        return arv;
    }
    if(!arv->folha && arv->filho[i]->nchaves >= t){//CASO 2A
        printf("\nCASO 2A\n");
        BT *y = arv->filho[i];
        while(!y->folha)y=y->filho[y->nchaves];
        char *temp;
        TLSE *l=y->slans[y->nchaves-1];
        Act *a=y->active[y->nchaves-1];
        strcpy(temp,y->chave[y->nchaves-1]);
        arv->filho[i]=remover(arv->filho[i],temp,t);
        strcpy(arv->chave[i],temp);
        arv->slans[i]=l;
        arv->active[i]=a;
        return arv;
    }
    if(!arv->folha && arv->filho[i+1]->nchaves >= t){//CASO 2B verificas os outros atributos
        printf("\n CASO 2B\n");
        BT *y =arv->filho[i+1];
        while(!y->folha)y=y->filho[0];
        char *temp;
        strcpy(temp,y->chave[0]);
        TLSE *l=y->slans[0];
        Act *a=y->active[0];
        y=remover(arv->filho[i+1],temp,t);
        strcpy(arv->chave[i],temp);
        arv->slans[i]=l;
        arv->active[i]=a;
        return arv;
    }
    if(!arv->folha && arv->filho[i+1]->nchaves == t-1 && arv->filho[i]->nchaves == t-1){//CASO 2C verificar os outros atributos
        printf("\nCASO 2C\n");
        BT *y=arv->filho[i];
        BT *z=arv->filho[i+1];
        strcpy(y->chave[y->nchaves],nome);
        int j;
        for(j=0;j<t-1;j++){
            strcpy(y->chave[t+j],z->chave[j]);
            y->slans[t+j]=z->slans[j];
            y->active[t+j]=z->active[j];
        }
        for(j=0;j<=t;j++){
            y->filho[t+j]=z->filho[j];
            z->filho[j]=NULL;
        }
        BT_Libera(z);
        y->nchaves = (2*t)-1;
        for(j=i;j< arv->nchaves-1;j++){
            strcpy(arv->chave[j],arv->chave[j+1]);
            arv->slans[j]=arv->slans[j+1];
            arv->active[j]=arv->active[j+1];
        }
        for(j=i+1;j<=arv->nchaves;j++)arv->filho[j]=arv->filho[j+1];
        Limpa_Remocao(arv->filho[j]);
        BT_Libera(arv->filho[j]);
        arv->filho[j]=NULL;
        arv->nchaves--;
        if(!arv->nchaves){
            BT *temp=arv;
            arv=arv->filho[0];
            temp->filho[0]=NULL;
            BT_Libera(temp);
            arv=remover(arv,nome,t);
        }
        else arv->filho[i]=remover(arv->filho[i],nome,t);
        return arv;
    }
    BT *y=arv->filho[i],*z=NULL;
    if(y->nchaves == t-1){//CASOS 3A E 3B
        if((i < arv->nchaves)&&(arv->filho[i+1]->nchaves >= t)){//CASO 3A
            printf("\nCASO 3A: i menor que nchaves\n");
            z = arv->filho[i+1];
            strcpy(y->chave[t-1],arv->chave[i]);
            y->slans[t-1]=arv->slans[i];
            y->active[t-1]=arv->active[i];
            y->nchaves++;
            strcpy(arv->chave[i],z->chave[0]);
            int j;
            for(j=0;j < z->nchaves-1;j++){
                strcpy(z->chave[j],z->chave[j+1]);
                z->slans[j]=z->slans[j+1];
                z->active[j]=z->active[j+1];
            }
            y->filho[y->nchaves]=z->filho[0];
            for(j=0;j<z->nchaves;j++)z->filho[i]=remover(arv->filho[i],nome,t);
            return arv;
        }
        if((i>0)&&(!z)&&(arv->filho[i-1]->nchaves >= t)){//CASO 3A
            printf("\nCASO 3A: i igual a nchaves\n");
            z=arv->filho[i-1];
            int j;
            for(j=y->nchaves;j>0;j--){
                strcpy(y->chave[j],y->chave[j-1]);
                y->slans[j]=y->slans[j-1];
                y->active[j]=y->active[j-1];
            }
            for(j=y->nchaves+1;j>0;j--)y->filho[j]=y->filho[j-1];
            strcpy(y->chave[0],arv->chave[i-1]);
            y->slans[0]=arv->slans[i-1];
            y->active[0]=arv->active[i-1];
            y->nchaves++;
            strcpy(arv->chave[i-1],z->chave[z->nchaves-1]);
            arv->slans[i-1]=z->slans[i-1];
            arv->active[i-1]=z->active[i-1];
            y->filho[0]=z->filho[z->nchaves];
            z->nchaves--;
            arv->filho[i]=remover(y,nome,t);
            return arv;
        }
        if(!z){//CASO 3B
            if(i < arv->nchaves && arv->filho[i+1]->nchaves == t-1){
                printf("\nCASO 3B: i menor que nchaves \n");
                z = arv->filho[i+1];
                strcpy(y->chave[t-1],arv->chave[i]);
                y->slans[t-1]=arv->slans[i];
                y->active[t-1]=arv->active[t-1];
                y->nchaves++;
                int j;
                for(j=0;j<t-1;j++){
                    strcpy(y->chave[t+j],z->chave[j]);
                    y->slans[t+j]=z->slans[t+j];
                    y->active[t+j]=z->active[t+j];
                    y->nchaves++;
                }
                if(!y->folha){
                    for(j=0;j<t;j++){
                        y->filho[t+j]=z->filho[j];
                        z->filho[j]=NULL;
                    }
                    BT_Libera(z);
                }
                for(j=i;j<arv->nchaves-1;j++){
                    strcpy(arv->chave[j],arv->chave[j+1]);
                    arv->slans[j]=arv->slans[j+1];
                    arv->active[j]=arv->active[j+1];
                    arv->filho[j+1]=arv->filho[j+2];
                }
                arv->filho[arv->nchaves]=NULL;
                arv->nchaves--;
                if(!arv->nchaves){
                    BT *temp=arv;
                    arv=arv->filho[0];
                    temp->filho[0]=NULL;
                    BT_Libera(temp);
                }
                arv=remover(arv,nome,t);
                return arv;
            }
            if((i>0)&&(arv->filho[i-1]->nchaves == t-1)){
                printf("\nCASO 3B: i igual a nchaves\n");
                z=arv->filho[i-1];
                if(i==arv->nchaves){
                    strcpy(z->chave[t-1],arv->chave[i-1]);
                    z->slans[t-1]=arv->slans[i-1];
                    z->active[t-1]=arv->active[i-1];
                }
                else{
                    strcpy(z->chave[t-1],arv->chave[i]);
                    z->slans[t-1]=arv->slans[i];
                    z->active[t-1]=arv->active[i];
                }
                z->nchaves++;
                int j;
                for(j=0;j<t-1;j++){
                    strcpy(z->chave[t+j],y->chave[j]);
                    z->slans[t+j]=y->slans[j];
                    z->active[t+j]=arv->active[j];
                    z->nchaves++;
                }
                if(!z->folha){
                    for(j=0;j<t;j++){
                        z->filho[t+j]=y->filho[j];
                        y->filho[j]=NULL;
                    }
                    BT_Libera(y);
                }
                arv->filho[arv->nchaves]=NULL;
                arv->nchaves--;
                if(!arv->nchaves){
                    BT *temp =arv;
                    arv=arv->filho[0];
                    temp->filho[0]=NULL;
                    BT_Libera(temp);
                }
                else arv->filho[i-1]=z;
                arv=remover(arv,nome,t);
                return arv;
            }
        }
    }
    arv->filho[i]=remover(arv->filho[i],nome,t);
    return arv;
}
BT* BT_Retira(BT *arv,char *nome,int t){
    if(!arv)return NULL;
    return remover(arv,nome,t);
}
void Limpa_Remocao(BT *a){
  if(!a) return;
  int i;
  for(i = 0; i <= a->nchaves; i++) a->filho[i] = NULL;
}
