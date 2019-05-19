//
//  main.c
//  FireSimulator
//
//  Created by PlugN on 16/05/2019.
//  Copyright © 2019 Groupe MINASTE. All rights reserved.
//


#include "Header files/main.h"

void menu(Forest * forest){
    int choice;
    printf("To control time by t+x, enter 1. To control time by t=x, enter 2. To edit an element, enter 3. To reset the board, enter 4. To change the fire source, enter 5. To exit, enter 6: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("Enter the value to execute (t+x). Use a negative value to rewind: ");
            scanf("%d", &choice);
            tplus(choice, forest);
            break;
        case 2:
            printf("Enter the value to execute (t=x): ");
            scanf("%d", &choice);
            tequal(choice, forest);
            break;
        case 3:
            editField(forest);
            break;
        case 4:
            resetTime(forest);
            break;
        case 5:
            changeFireSource(forest);
            break;
        case 6:
            return;
            break;
            
        default:
            printf("Error in selection.\n");
            menu(forest);
            break;
    }
    
    emergencyPrint(forest->field, forest->sizex, forest->sizex);
    menu(forest);
    
}

int main(int argc, const char * argv[]) {
    Forest forest;
    srand((unsigned int)time(NULL));
    
    createField(&forest);
    menu(&forest);
    
    return 0;
}
