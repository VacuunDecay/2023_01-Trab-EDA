#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "Menus.h"
#include "TLSE.h"
#include "BTree.h"
#include "MyUtil.h"
#include "exercicios.h"

int main()
{
    int t = 5;

    BT* bt = BT_Cria(t);


    bt = BT_preench_arvore(bt, t);
    //T_Imprime(bt);

    Menu(bt, t);
    //bt = BT_Retira(bt, "Carlos Alcaraz", t);
    //bt = BT_Retira(bt, "Hubert Hurkacz", t);
    //bt = BT_Retira(bt, "Francisco Cerundolo", t);
    //bt = BT_Retira(bt, "Alexander Zverev", t);
    //bt = BT_Retira(bt, "Nicolas Jarry", t);

    //BT_Imprime(bt);
    //ln();


    BT_Libera(bt);


    return 0;
}
