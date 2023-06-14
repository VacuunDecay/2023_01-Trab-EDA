#include "Menus.h"
#include "test.h"
 // made in part by chatGPT
void exercicoA(){

}
void exercicoB(){

}
void exercicoC(){

}
void exercicoD(){

}
void exercicoE(){

}
void exercicoF(){

}
void exercicoG(){

}
void MenuDeTestes(){

}

// Clear the screen based on the operating system
void clearScreen(){
    #ifdef _WIN32
        system("cls"); // For Windows
    #else
        system("clear"); // For Linux and macOS
    #endif
}

int Menu(){
    int choice;
    int submenuChoice;

    while (1) {
        clearScreen();
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
            case 1: exercicoA(); break;
            case 2: exercicoB(); break;
            case 3: exercicoC(); break;
            case 4: exercicoD(); break;
            case 5: exercicoE(); break;
            case 6: exercicoF(); break;
            case 7: exercicoG(); break;
            case 9:
                clearScreen();
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        if (choice == 8) {
            while (1) {
                clearScreen();
                printf("\n------ Menu de Exercicios ------\n");
                printf("1. Teste da BTree Horiginal\n");
                printf("2. Teste da Lista Modificada\n");
                // Add submenu options 3 to 9 here
                printf("9. Go back to Main Menu\n");
                printf("Enter your choice: ");
                scanf("%d", &submenuChoice);

                switch (submenuChoice) {
                    case 1: profTeste(); break;
                    case 2: testeLista(); break;
                    //Adicione mas opsoes aqui
                    case 9:
                        clearScreen();
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

// Implement the functions for the menu options and submenu options here
