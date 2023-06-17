#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "Menus.h"
#include "TLSE.h"
#include "BTree.h"
#include "MyUtil.h"

int main()
{
    FILE* fp = fopen("era_aberta_grand_slams.txt", "r");
    if (fp == NULL) {
        printf("Failed to open the file.\n");
        exit(1);
    }
    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL) {
        int numTokens = 4;
        char** tokens = splitStr(line, "\t", numTokens);

        printf("Tokens:\n");
        for (int i = 0; i < numTokens; i++) {
            printf("%s\n", tokens[i]);
            free(tokens[i]);
        }

        free(tokens);
    }
    return 0;
}
