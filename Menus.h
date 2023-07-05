#ifndef MENUS_H
#define MENUS_H

#include <stdio.h>
#include <stdlib.h>
#include "MyUtil.h"
#include "exercicios.h"
#include "BTree.h"
#include "TLSEv.h"

// Function prototypes
void exercicoA(BT* bt);
void exercicoB();
void exercicoC(BT* bt);
void exercicoD(BT* bt);
void exercicoE(BT* bt);
void exercicoF(BT* bt);
BT* exercicoG(BT* bt);
//void MenuDeTestes(); // Acho que isso nao serve pra nada...
//void TesteDeBTreeOriginal();
//void TesteDeListaModificada();
BT* menuRemover(BT* bt, int t);
void menuImprimir(BT* bt);
void menuInprimir_El(BT* bt);

int Menu(BT* bt, int t);


#endif // MENUS_H
