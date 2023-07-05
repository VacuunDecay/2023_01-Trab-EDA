#include "Menus.h"


void exercicoA(BT* bt){
    TLSEv * lAtivos = TLSEv_inicializa();
    TLSEv * lAposentados = TLSEv_inicializa();

    lAtivos = Qa(bt, lAtivos, 1);
    lAposentados = Qa(bt, lAposentados, 0);

    TLSEv_imprime(lAposentados);
    waitKey();
    TLSEv_imprime(lAtivos);
    waitKey();
}
void exercicoB(BT* bt){
  nascmentoPremi(bt);
  waitKey();
}
void exercicoC(BT* bt){
    printf("-------------inativos--------------:\n");
    waitKey();
    makeSlanHank(bt, 0);
}
void exercicoD(BT* bt){
    printf("--------------ativos---------------:\n");
    waitKey();
    makeSlanHank(bt, 1);
    waitKey();
}
void exercicoE(BT* bt){
  TLSEp* lista = NULL;
  lista = Qe(bt, lista);

  TLSEp* no = lista;
  if(lista)
    while(no){
      printf("%s venceu todos os slans no ano %d\n", no->info->no->chave[no->info->indice], no->point);
      no = no->prox;
    }
  else
    printf("Nenhum jogador aposentado venceu todos os slans no mesmo ano.\n");

  waitKey();
}
void exercicoF(BT* bt){
  TLSEp* lista = NULL;
  lista = Qf(bt, lista);

  TLSEp* no = lista;
  if(lista)
    while(no){
      printf("%s venceu todos os slans no ano %d\n", no->info->no->chave[no->info->indice], no->point);
      no = no->prox;
    }
  else
    printf("Nenhum jogador aposentado venceu todos os slans no mesmo ano.\n");

  waitKey();
}
BT* exercicoG(BT* bt,int t){
    char pais[50];
    printf("Digite um pais:");
    scanf("%s", &pais);

    mostraPais(bt, pais, t);
    printf("Removendo os jogadores vindos de %s", pais);
    bt = retiraPais(bt, pais,t);
    BT_Imprime(bt);
    mostraPais(bt, pais, t);
    waitKey();
    return bt;
}

BT* menuRemover(BT* bt, int t){
    char nome[50];
    printf("Qual jogador quer remover: ");
    scanf(" %[^\n]", &nome);

    bt = BT_Retira(bt, nome, t);
    printf("Jogador removido\n");
    BT_Imprime(bt);
    BT_Imprime_el(bt, nome);
    waitKey();
    return bt;
}
void menuImprimir(BT* bt){
    BT_Imprime(bt);
    waitKey();
}
void menuInprimir_El(BT* bt){
    char nome[50];
    printf("Que jogador gostaria de ver:");
    scanf(" %[^\n]", &nome);

    BT_Imprime_el(bt, nome);
    waitKey();
}


int Menu(BT* bt, int t){
    int choice;
    int submenuChoice;

    while (1) {
        cls();
        printf("\n------ Principal Menu ------\n");
        printf("1. exercico A\n");
        printf("2. exercico B\n");
        printf("3. exercico C\n");
        printf("4. exercico D\n");
        printf("5. exercico E\n");
        printf("6. exercico F\n");
        printf("7. exercico G\n");
        printf("8. Menu de Testes\n");
        printf("9. Exit\n");
        printf("Digite sua escolha: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: exercicoA(bt); break;
            case 2: exercicoB(bt); break;
            case 3: exercicoC(bt); break;
            case 4: exercicoD(bt); break;
            case 5: exercicoE(bt); break;
            case 6: exercicoF(bt); break;
            case 7: bt = exercicoG(bt,t); break;
            case 9:
                cls();
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        if (choice == 8) {
            while (1) {
                cls();
                printf("\n------ De testes ------\n");
                printf("1. Remover Jogador\n");
                printf("2. Ver Arvore\n");
                printf("3. Ver Jogador\n");
                printf("9. Go back to Main Menu\n");
                printf("Enter your choice: ");
                scanf("%d", &submenuChoice);

                switch (submenuChoice) {
                    case 1: menuRemover(bt, t); break;
                    case 2: menuImprimir(bt); break;
                    case 3: menuInprimir_El(bt); break;
                    case 9:
                        cls();
                        printf("Returning to Main Menu...\n");
                        break;
                    default:
                        printf("Invalid choice. Please try again.\n");
                }

                if (submenuChoice == 9)
                    break;
            }
        }
    }

    return 0;
}
