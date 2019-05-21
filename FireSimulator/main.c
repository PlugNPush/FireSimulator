//
//  main.c
//  FireSimulator
//
//  Created by PlugN on 16/05/2019.
//  Copyright © 2019 Groupe MINASTE. All rights reserved.
//


#include "Header files/main.h"

void menu(Forest * forest){
    int* choice = malloc(sizeof(int));
    printf("To control time by t+x, enter 1. To control time by t=x, enter 2. To edit an element, enter 3. To reset the board, enter 4. To change the fire source, enter 5. To change the size of the field, enter 6. To exit, enter 7: ");
    scanf("%d", choice);
    
    switch (*choice) {
        case 1:
            free(choice);
            printf("Enter the value to execute (t+x). Use a negative value to rewind: ");
            scanf("%d", choice);
            tplus(*choice, forest);
            break;
        case 2:
            free(choice);
            printf("Enter the value to execute (t=x): ");
            scanf("%d", choice);
            tequal(*choice, forest);
            break;
        case 3:
            free(choice);
            editField(forest);
            break;
        case 4:
            free(choice);
            resetTime(forest);
            break;
        case 5:
            free(choice);
            changeFireSource(forest);
            break;
        case 6:
            free(choice);
            extendField(forest);
            break;
        case 7:
            free(choice);
            return;
            break;
            
        default:
            free(choice);
            printf("Error in selection.\n");
            menu(forest);
            break;
    }
    int* t0 = malloc(sizeof(int));
    *t0 = forest->field[forest->firex][forest->firey].state;
    printf("t=%d\n", *t0);
    free(t0);
    printField(forest->field, forest->sizex, forest->sizey);
    menu(forest);
    
}

int main(int argc, const char * argv[]) {
    Forest* forest = malloc(sizeof(Forest));
    srand((unsigned int)time(NULL));
    
    createField(forest);
    menu(forest);
    
    free(forest);
    
    return 0;
}
