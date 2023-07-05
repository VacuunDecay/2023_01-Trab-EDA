#include <stdio.h>
#include <stdlib.h>
#include "Menus.h"
#include "TLSE.h"
#include "BTree.h"
#include "MyUtil.h"
#include "exercicios.h"

int main()
{
    int t = 4;

    BT* bt = BT_Cria(t);


    bt = BT_preench_arvore(bt, t);
    BT_Imprime(bt);

    Menu(bt, t);

    BT_Libera(bt);


    return 0;
}
