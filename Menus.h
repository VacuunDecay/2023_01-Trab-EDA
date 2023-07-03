#ifndef MENUS_H
#define MENUS_H

#include <stdio.h>
#include <stdlib.h>
#include "MyUtil.h"
#include "exercicios.h"
#include "BTree.h"

// Function prototypes
void exercicoA();
void exercicoB();
void exercicoC(BT* bt);
void exercicoD(BT* bt);
void exercicoE(BT* bt);
void exercicoF(BT* bt);
void exercicoG(BT* bt);
//void MenuDeTestes(); // Acho que isso nao serve pra nada...
//void TesteDeBTreeOriginal();
//void TesteDeListaModificada();
void menuRemover(BT* bt, int t);
void menuImprimir(BT* bt);
void menuInprimir_El(BT* bt);

int Menu(BT* bt, int t);


#endif // MENUS_H
