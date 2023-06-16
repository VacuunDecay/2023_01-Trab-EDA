#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "Menus.h"
#include "TLSE.h"
#include "BTree.h"
void ln(){
    printf("\n");
}
int main()
{
    BT* tree = BT_Inicializa();

    tree = BT_Insere(tree, "J", 2);
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
    return 0;
}
