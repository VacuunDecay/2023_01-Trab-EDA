#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "Menus.h"
#include "TLSE.h"
#include "BTree.h"

int main()
{
    BT* tree = BT_Inicializa();

    tree = BT_Insere(tree, "Jorge", 2);
    tree = BT_Insere(tree, "Felipe", 2);
    tree = BT_Insere(tree, "Camila", 2);
    tree = BT_Insere(tree, "Clay", 2);
    tree = BT_Insere(tree, "Glory", 2);
    tree = BT_Insere(tree, "Starflat", 2);
    tree = BT_Insere(tree, "Kastrel", 2);
    tree = BT_Insere(tree, "Amanda", 2);

    BT_Imprime(tree);
    //Menu();
    return 0;
}
