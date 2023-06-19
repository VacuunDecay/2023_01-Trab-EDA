#include "TARVB.h"
#include "test.h"
#include "TLSE.h"
#include "MyUtil.h"
#include "BTree.h"
#include "MyUtil.h"

void testeBTreeInset(){
    BT* tree = BT_Inicializa();

    tree = BT_Insere(tree, "Joao", 2);
    tree = BT_Insere(tree, "Amanda", 2);
    tree = BT_Insere(tree, "Felipe", 2);
    tree = BT_Insere(tree, "Camila", 2);
    tree = BT_Insere(tree, "Clay", 2);
    tree = BT_Insere(tree, "Glory", 2);
    tree = BT_Insere(tree, "Starflat", 2);
    tree = BT_Insere(tree, "Kastrel", 2);
    tree = BT_Insere(tree, "Amanda", 2);

    BT_Imprime(tree);
    ln();
    BT_Imprime_el(tree, "Clay");

    //Menu();
    BT_Libera(tree);

}

int testeLista(){
    int banco[5][4] = {
        {1, 0, 0, 0},
        {2, 1, 0, 0},
        {0, 2, 1, 0},
        {0, 0, 2, 1},
        {0, 0, 0, 2}
    };
    int **vet = (int**)malloc(sizeof(int)*5*4);
    for(int i=0; i < 5; i++){
        vet[i] =(int*)malloc(sizeof(int)*4);
        for(int j=0; j < 4; j++){
            vet[i][j] = banco[i][j];
        }
    }




    TLSE *lista = NULL;

    for(int i=0; i<5; i++)
        lista = TLSE_insere(lista, vet[i], 2000+i);

    TLSE_retira(lista, 2001);
    TLSE_imprime(lista);

    TLSE_imprime(TLSE_busca(lista, 2002));
    TLSE_libera(lista);

    waitKey();
    return 0;
}
int profTeste(){
  TARVB *arvore = TARVB_Inicializa();
  int t;
  printf("Digite o grau minimo. Se o valor digitado for menor que 2, t sera considerado igual a 2...\n");
  scanf("%d", &t);
  if(t < 2) t = 2;
  int num = 0, from, to;
  while(num != -1){
    printf("Digite um numero para adicionar. 0 para imprimir. -9 para remover e -1 para sair\n");
    scanf("%d", &num);
    if(num == -9){
      scanf("%d", &from);
      arvore = TARVB_Retira(arvore, from, t);
      TARVB_Imprime(arvore);
    }
    else if(num == -1){
      printf("\n");
      TARVB_Imprime(arvore);
      TARVB_Libera(arvore);
      return 0;
    }
    else if(!num){
      printf("\n");
      TARVB_Imprime(arvore);
    }
    else arvore = TARVB_Insere(arvore, num, t);
    printf("\n\n");
  }
}
