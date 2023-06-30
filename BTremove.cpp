#include "BTree.h"

BT* remover(BT* arv, char* ch, int t) {
    if (!arv) return arv;
    int i;
    printf("Removendo %s...\n", ch);
    for (i=0; i<arv->nchaves && strcmp(arv->chave[i], ch) < 0; i++);
    if (i < arv->nchaves && strcmp(ch, arv->chave[i]) == 0) { //CASOS 1, 2A, 2B e 2C
        if (arv->folha) { //CASO 1
            printf("\nCASO 1\n");
            int j;
            for(j=i;j<arv->nchaves-1;j++) {
                arv->chave[j] = strdup(arv->chave[j + 1]); 
                arv->active[j] = arv->active[j+1];
                arv->slans[j] = arv->slans[j+1];
            }
            arv->nchaves--;
            if (!arv->nchaves) {
                BT_Libera(arv);
                arv = NULL;
            }
            return arv;
        }
        if (!arv->folha && arv->filho[i]->nchaves >= t) { //CASO 2A
            printf("\nCASO 2A\n");
            BT* y = arv->filho[i];  //Encontrar o predecessor k' de k na árvore com raiz em y
            while (!y->folha) y = y->filho[y->nchaves];
            char* temp = strdup(y->chave[y->nchaves-1]);
            Act* temp_active = y->active[y->nchaves-1];
            TLSE* temp_slans = y->slans[y->nchaves-1];
            arv->filho[i] = remover(arv->filho[i], temp, t);
            //Eliminar recursivamente K e substitua K por K' em x
            //free(arv->chave[i]);
            arv->chave[i] = strdup(temp);
            arv->active[i] = temp_active;
            arv->slans[i] = temp_slans;
            //free(temp);
            return arv;
        }
        if (!arv->folha && arv->filho[i+1]->nchaves >= t) { //CASO 2B
            printf("\nCASO 2B\n");
            BT* y = arv->filho[i+1];  //Encontrar o sucessor k' de k na árvore com raiz em y
            while(!y->folha) y = y->filho[0];
            char* temp = strdup(y->chave[0]);
            Act* temp_active = y->active[0];
            TLSE* temp_slans = y->slans[0];
            y = remover(arv->filho[i + 1], temp, t);
            //Eliminar recursivamente K e substitua K por K' em x
            //free(arv->chave[i]);
            arv->chave[i] = strdup(temp);
            arv->active[i] = temp_active;
            arv->slans[i] = temp_slans;
            //free(temp);
            return arv;
        }
        if (!arv->folha && arv->filho[i]->nchaves == t - 1 && arv->filho[i + 1]->nchaves == t - 1) { //CASO 2C
            printf("\nCASO 2C\n");
            BT* y = arv->filho[i];
            BT* z = arv->filho[i+1];
            int j;
            //Juntar K e todos os K' e descendentes em um único nó e eliminar K de x
            y->chave[t-1] = strdup(arv->chave[i]);
            y->active[t-1] = arv->active[i];
            y->slans[t-1] = arv->slans[i];
            for (j=0; j<t-1; j++) {
                y->chave[t+j] = strdup(z->chave[j]);
                y->slans[t+j] = z->slans[j];
                y->active[t+j] = z->active[j];
            }
            if (!y->folha) {//esse if nao ta no original
                for (j=0; j < t; j++) {
                    y->filho[t+j] = z->filho[j];
                    z->filho[j] = NULL;
                }
            }
            BT_Libera(z);
            y->nchaves = 2*t-1;
            for (j=i; j < arv->nchaves-1; j++) {
                arv->chave[j] = strdup(arv->chave[j+1]);
                arv->active[j] = arv->active[j+1];
                arv->slans[j] = arv->slans[j+1];
            }
            for (j = i + 1; j <= arv->nchaves; j++) {
                arv->filho[j] = arv->filho[j+1];
            }
            arv->filho[j] = NULL;
            arv->nchaves--;
            if (!arv->nchaves) {
                BT *temp = arv;
                arv = arv->filho[0];
                BT_Libera(temp);
                arv = remover(arv, ch, t);
            }
            else arv->filho[i] = remover(arv->filho[i], ch, t);
            return arv;
        }
    }

    BT* y = arv->filho[i], *z = NULL;
    if(y->nchaves == t-1){
        if((i < arv->nchaves) && (arv->filho[i+1]->nchaves >= t)){
            printf("\nCASO 3A: i menor que nchaves\n");
            z = arv->filho[i+1];

            y->chave[t-1] = strdup(arv->chave[i]);
            y->slans[t-1] = arv->slans[i];
            y->active[t-1] = arv->active[i];
            
            y->nchaves++;
            
            arv->chave[i] = strdup(z->chave[0]);
            arv->slans[i] = z->slans[0];
            arv->active[i] = z->active[0];

            int j;

            for (j = 0; j < z->nchaves-1; j++) {
                z->chave[j] = strdup(z->chave[j+1]);
                z->slans[j] = z->slans[j+1];
                z->active[j] = z->active[j+1];
            }
            y->filho[y->nchaves] = z->filho[0];
            for(j=0; j < z->nchaves; j++)       //ajustar filhos de z
                z->filho[j] = z->filho[j+1];
            z->nchaves--;
            arv->filho[i] = remover(arv->filho[i], ch, t);
            return arv;
        }
        if((i > 0) && (!z) && (arv->filho[i-1]->nchaves >=t)){ //CASO 3A
            printf("\nCASO 3A: i igual a nchaves\n");
            z = arv->filho[i-1];
            int j;
            for(j = y->nchaves; j>0; j--){
                y->chave[j] = y->chave[j-1];
                y->slans[j] = y->slans[j-1];
                y->active[j] = y->active[j-1];
            }
            for(j = y->nchaves+1; j>0; j--)             //encaixar lugar dos filhos da nova chave
                y->filho[j] = y->filho[j-1];

            y->chave[0] = arv->chave[i-1]; 
            y->slans[0] = arv->slans[i-1]; 
            y->active[0] = arv->active[i-1]; 

            y->nchaves++;

            arv->chave[i-1] = z->chave[z->nchaves-1];
            arv->slans[i-1] = z->slans[z->nchaves-1];
            arv->active[i-1] = z->active[z->nchaves-1];

            y->filho[0] = z->filho[z->nchaves];         //enviar ponteiro de z para o novo elemento em y
            z->nchaves--;
            arv->filho[i] = remover(y, ch, t);
            return arv;
        }
        if(!z){ //CASO 3B
            if(i < arv->nchaves && arv->filho[i+1]->nchaves == t-1){
                printf("\nCASO 3B: i menor que nchaves\n");
                z = arv->filho[i+1];
                
                y->chave[t-1] = arv->chave[i];
                y->slans[t-1] = arv->slans[i];
                y->active[t-1] = arv->active[i];
                
                y->nchaves++;
                int j;
                for(j=0; j < t-1; j++){
                    y->chave[t+j] = z->chave[j];
                    y->slans[t+j] = z->slans[j];
                    y->active[t+j] = z->active[j];
                    
                    y->nchaves++;
                }
        if(!y->folha){
          for(j=0; j<t; j++){
            y->filho[t+j] = z->filho[j];
            z->filho[j] = NULL; //ultima revisao: 04/2020
          }
          TARVB_Libera(z);
        }
        for(j=i; j < arv->nchaves-1; j++){ //limpar referências de i
          arv->chave[j] = arv->chave[j+1];
          arv->filho[j+1] = arv->filho[j+2];
        }
        arv->filho[arv->nchaves] = NULL;
        arv->nchaves--;
        if(!arv->nchaves){ //ultima revisao: 04/2020
          TARVB *temp = arv;
          arv = arv->filho[0];
          temp->filho[0] = NULL;
          TARVB_Libera(temp);
        }
        arv = remover(arv, ch, t);
        return arv;
      }
      if((i > 0) && (arv->filho[i-1]->nchaves == t-1)){
        printf("\nCASO 3B: i igual a nchaves\n");
        z = arv->filho[i-1];
        if(i == arv->nchaves)
          z->chave[t-1] = arv->chave[i-1]; //pegar chave[i] e poe ao final de filho[i-1]
        else
          z->chave[t-1] = arv->chave[i];   //pegar chave [i] e poe ao final de filho[i-1]
        z->nchaves++;
        int j;
        for(j=0; j < t-1; j++){
          z->chave[t+j] = y->chave[j];     //passar filho[i+1] para filho[i]
          z->nchaves++;
        }
        if(!z->folha){
          for(j=0; j<t; j++){
            z->filho[t+j] = y->filho[j];
            y->filho[j] = NULL; //ultima revisao: 04/2020
          }
          TARVB_Libera(y);
        }
        arv->filho[arv->nchaves] = NULL;
        arv->nchaves--;
        if(!arv->nchaves){ //ultima revisao: 04/2020
          TARVB *temp = arv;
          arv = arv->filho[0];
          temp->filho[0] = NULL;
          TARVB_Libera(temp);
        }
        else arv->filho[i-1] = z;
        arv = remover(arv, ch, t);
        return arv;
      }
    }
  }
  arv->filho[i] = remover(arv->filho[i], ch, t);
  return arv;
}
    /*
    else { //CASO 3
        printf("\nCASO 3\n");
        BT* y = arv->filho[i];
        if (!y) {
            printf("Elemento %s não encontrado!\n", ch);
            return arv;
        }
        if (y->nchaves == t - 1) {
            BT* z = arv->filho[i + 1];
            if (i < arv->nchaves && z->nchaves >= t) { //CASO 3A
                printf("\nCASO 3A\n");
                int j;
                // Mover uma chave de arv[i] para arv[i+1]
                y->chave[t - 1] = strdup(arv->chave[i]);
                y->slans[t - 1] = arv->slans[i];
                y->active[t - 1] = arv->active[i];
                arv->chave[i] = strdup(z->chave[0]);
                arv->slans[i] = z->slans[0];
                arv->active[i] = z->active[0];
                //free(z->chave[0]);
                for (j = 0; j < z->nchaves - 1; j++) {
                    z->chave[j] = strdup(z->chave[j + 1]);
                    z->slans[j] = z->slans[j + 1];
                    z->active[j] = z->active[j + 1];
                }
            
                if (!z->folha) {
                    y->filho[t] = z->filho[0];
                    for (j = 0; j < z->nchaves; j++) {
                        z->filho[j] = z->filho[j + 1];
                    }
                }
                y->nchaves++;
                z->nchaves--;
                arv->filho[i] = remover(y, ch, t);
                return arv;
            }
            else if (i > 0 && arv->filho[i - 1]->nchaves >= t) { //CASO 3A (versão simétrica)
                printf("\nCASO 3A (versão simétrica)\n");
                int j;
                // Mover uma chave de arv[i-1] para arv[i]
                for (j = y->nchaves; j > 0; j--) {
                    y->chave[j] = strdup(y->chave[j - 1]);
                    y->slans[j] = y->slans[j - 1];
                    y->active[j] = y->active[j - 1];
                }
                y->chave[0] = strdup(arv->chave[i - 1]);
                y->slans[0] = arv->slans[i - 1];
                y->active[0] = arv->active[i - 1];
                arv->chave[i - 1] = strdup(arv->filho[i - 1]->chave[arv->filho[i - 1]->nchaves - 1]);
                arv->slans[i - 1] = arv->filho[i - 1]->slans[arv->filho[i - 1]->nchaves - 1];
                arv->active[i - 1] = arv->filho[i - 1]->active[arv->filho[i - 1]->nchaves - 1];
                //free(arv->filho[i - 1]->chave[arv->filho[i - 1]->nchaves - 1]);
                if (!y->folha) {
                    for (j = y->nchaves + 1; j > 0; j--) {
                        y->filho[j] = y->filho[j - 1];
                    }
                    y->filho[0] = arv->filho[i - 1]->filho[arv->filho[i - 1]->nchaves];
                }
                y->nchaves++;
                arv->filho[i - 1]->nchaves--;
                arv->filho[i] = remover(y, ch, t);
                return arv;
            }
            else if (i < arv->nchaves) { //CASO 3B
                printf("\nCASO 3B\n");
                int j;
                // Juntar arv[i] e arv[i+1] e arv[i] em uma única chave em arv[i]
                y->chave[t - 1] = strdup(arv->chave[i]);
                y->slans[t - 1] = arv->slans[i];
                y->active[t - 1] = arv->active[i];
                for (j = 0; j < t - 1; j++) {
                    y->chave[t + j] = strdup(z->chave[j]);
                    y->slans[t + j] = z->slans[j];
                    y->active[t + j] = z->active[j];
                }
                if (!y->folha) {
                    for (j = 0; j < t; j++) {
                        y->filho[t + j] = z->filho[j];
                    }
                }
                //free(arv->chave[i]);
                for (j = i; j < arv->nchaves - 1; j++) {
                    arv->chave[j] = strdup(arv->chave[j + 1]);
                    arv->active[j] = arv->active[j+1];
                    arv->slans[j] = arv->slans[j+1];
                }
                for (j = i + 1; j <= arv->nchaves; j++) {
                    arv->filho[j] = arv->filho[j + 1];
                }
                arv->nchaves--;
                if (!arv->nchaves) {
                    BT_Libera(arv);
                    arv = y;
                }
                arv->filho[i] = remover(y, ch, t);
                return arv;
            }
            else if (i > 0) { //CASO 3B (versão simétrica)
                printf("\nCASO 3B (versão simétrica)\n");
                int j;
                // Juntar arv[i-1] e arv[i] em uma única chave em arv[i-1]
                arv->filho[i - 1]->chave[t - 1] = strdup(arv->chave[i - 1]);
                for (j = 0; j < t - 1; j++) {
                    arv->filho[i - 1]->chave[t + j] = strdup(y->chave[j]);
                }
                if (!arv->filho[i - 1]->folha) {
                    for (j = 0; j < t; j++) {
                        arv->filho[i - 1]->filho[t + j] = y->filho[j];
                    }
                }
                //free(arv->chave[i - 1]);
                for (j = i - 1; j < arv->nchaves - 1; j++) {
                    arv->chave[j] = strdup(arv->chave[j + 1]);
                    arv->active[j] = arv->active[j+1];
                    arv->slans[j] = arv->slans[j+1];
                }
                for (j = i; j <= arv->nchaves; j++) {
                    arv->filho[j] = arv->filho[j + 1];
                }
                arv->nchaves--;
                if (!arv->nchaves) {
                    BT_Libera(arv);
                    arv = arv->filho[i - 1];
                }
                arv->filho[i - 1] = remover(arv->filho[i - 1], ch, t);
                return arv;
            }
        }
        arv->filho[i] = remover(y, ch, t);
        return arv;
    }
}
*/