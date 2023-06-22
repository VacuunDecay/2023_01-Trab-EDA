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
    BT_Imprime_el(bt, "Carlos Alcaraz");
    BT_Imprime_el(bt, "Daniil Medvedev");
    BT_Imprime_el(bt, "Novak Djokovic");
    BT_Imprime_el(bt, "Jenson Brooksby");
    BT_Imprime_el(bt, "Dominic Thiem");


    BT_Libera(bt);

    return 0;
}
