#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "Menus.h"
#include "TLSE.h"
#include "BTree.h"
#include "MyUtil.h"


int main()
{
    int t = 2;
    BT* bt = BT_Cria(t);


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

    //BT_Imprime(bt);
    ln();
    BT_Imprime_el(bt, "Carlos Alcaraz");
    BT_Imprime_el(bt, "Daniil Medvedev");
    BT_Imprime_el(bt, "Novak Djokovic");
    BT_Imprime_el(bt, "Jenson Brooksby");
    BT_Imprime_el(bt, "Dominic Thiem");


    BT_Libera(bt);
    fclose(fiJogs);
    fclose(fiSlans);

    return 0;
}
