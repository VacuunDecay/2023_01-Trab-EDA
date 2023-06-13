#include "Menus.h"
 
 // made in part by chatGPT
void option1(){

}
void option2(){

}
void submenuOption1(){

}
void submenuOption2(){

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
        printf("\n------ Main Menu ------\n");
        printf("1. Option 1\n");
        printf("2. Option 2\n");
        printf("3. SubMenu\n");
        // Add menu options 3 to 9 here
        printf("9. Exit\n");
        printf("Digite sua escolha: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                option1();
                break;
            case 2:
                option2();
                break;
            // Add cases for options 3 to 9 here
            case 9:
                clearScreen();
                printf("Exiting the program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        if (choice == 3) {
            while (1) {
                clearScreen();
                printf("\n------ Submenu ------\n");
                printf("1. Submenu Option 1\n");
                printf("2. Submenu Option 2\n");
                // Add submenu options 3 to 9 here
                printf("9. Go back to Main Menu\n");
                printf("Enter your choice: ");
                scanf("%d", &submenuChoice);

                switch (submenuChoice) {
                    case 1:
                        submenuOption1();
                        break;
                    case 2:
                        submenuOption2();
                        break;
                    // Add cases for submenu options 3 to 9 here
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
