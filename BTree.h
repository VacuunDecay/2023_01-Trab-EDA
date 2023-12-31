#ifndef Player_H
#define Player_H


#include "TLSE.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Active{
    char* nasc;
    int idade, point, rancking;
}Act;

typedef struct PlayTree{
    int nchaves, folha;
    struct PlayTree **filho;
    char **chave; //Um vetor de strigs cada string gurda o nome de um jogador
    TLSE **slans;
    Active **active; // Null if inactive
}BT;

//Implementadas
BT *BT_Cria(int t);
BT *BT_Inicializa();
BT *BT_Libera(BT *a);
BT *BT_Insere(BT *T, char* k, int t); //TODO: Mudar parametros
/**Imprime a arvore emordem com identação*/
void BT_Imprime(BT *a);
/**Imprime apenas um elemento*/
void BT_Imprime_el(BT *a, char* nome);
/** pos recebe ponteiro ou seja &intVar ou NULL onde intVar é um inteiro qualquer */
BT *BT_Busca_Nome(BT* x, char* nome, int* pos); // IPC 1
BT* BT_Preenche_Slam(BT* T, char** line, int t);
BT* BT_Preenche_Act(BT* T, char** line, int t);
BT* BT_preench_arvore(BT* bt, int t);
//Imcolpletas
//Nao implementadas
BT *BT_Busca_Pais(BT* x, char* pais);
BT *BT_Carrega(BT *T, int k, int t); // ?
BT* BT_Retira(BT* arv, char* k, int t);
void Limpa_Remocao(BT *a);


//para a A
void BT_Imprime_el_vencedor(BT *a, char* nome);


#endif // Player_H
