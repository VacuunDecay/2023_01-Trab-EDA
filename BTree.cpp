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
