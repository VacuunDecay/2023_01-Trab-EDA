#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "Menus.h"
#include "TLSE.h"
#include "BTree.h"
#include "MyUtil.h"



int main()
{
    int t = 5;
    BT* bt = BT_Cria(t);

    bt = BT_preench_arvore(bt, t);


    BT_Imprime(bt);
    ln();
    BT_Retira(bt, "Daniil Medvedev", 5);
    BT_Retira(bt, "Carlos Alcaraz", 5);
    BT_Retira(bt, "Novak Djokovic", 5);
    BT_Retira(bt, "Novak Djokovic", 5);
    BT_Retira(bt, "Jenson Brooksby", 5);
    BT_Retira(bt, "Dominic Thiem", 5);
    BT_Imprime_el(bt, "Daniil Medvedev");
    BT_Imprime_el(bt, "Novak Djokovic");
    BT_Imprime_el(bt, "Jenson Brooksby");
    BT_Imprime_el(bt, "Dominic Thiem");


    BT_Libera(bt);

    return 0;
}
