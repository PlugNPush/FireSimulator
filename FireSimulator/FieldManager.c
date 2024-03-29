//
//  FieldManager.c
//  FireSimulator
//
//  Created by PlugN on 16/05/2019.
//  Copyright © 2019 Groupe MINASTE. All rights reserved.
//


#include "Header files/FieldManager.h"

Element dropElement(){
    
    Element ground = {0, 0, 0};
    Element grass = {1, 3, 0};
    Element tree = {2, 4, 0};
    Element Leaf = {3, 2, 0};
    Element rock = {4, 5, 0};
    Element water = {5, 0, 0};
    
    int drop = rand() % 6;
    
    if (drop == 0) {
        return ground;
    } else if (drop == 1) {
        return grass;
    } else if (drop == 2) {
        return tree;
    } else if (drop == 3) {
        return Leaf;
    } else if (drop == 4){
        return rock;
    } else {
        return water;
    }
}

Element setElement(Element e, int drop){
    
    Element ground = {0, 0, e.state};
    Element grass = {1, 3, e.state};
    Element tree = {2, 4, e.state};
    Element Leaf = {3, 2, e.state};
    Element rock = {4, 5, e.state};
    Element water = {5, 0, e.state};
    
    if (drop == 0) {
        return ground;
    } else if (drop == 1) {
        return grass;
    } else if (drop == 2) {
        return tree;
    } else if (drop == 3) {
        return Leaf;
    } else if (drop == 4){
        return rock;
    } else {
        return water;
    }
}


void setSize(Forest * forest){
    printf("Please enter the x dim of the field: ");
    scanf("%d", &forest->sizex);
    printf("Now enter the y dim of the field: ");
    scanf("%d", &forest->sizey);
    
    if (forest->sizex > 500 || forest->sizey > 500){
        printf("You must use reasonable values.\n");
        setSize(forest);
    }
}

void initField(Forest * forest){
    int i, j;
    for (i = 0; i < 500; i++) {
        for (j = 0; j < 500; j++) {
            forest->field[i][j] = dropElement();
        }
    }
}

void setFireStart(Forest * forest){
    int posx, posy;
    fpurge(stdin);
    printf("Enter the fire start position x [0 - %d]: ", forest->sizex - 1);
    scanf("%d", &posx);
    printf("Enter the fire start position y [0 - %d]: ", forest->sizey - 1);
    scanf("%d", &posy);
    
    if (forest->field[posx][posy].type == 0 || forest->field[posx][posy].type == 5){
        printf("You cannot set the fire start on water or ground.\n");
        setFireStart(forest);
        return;
    }
    
    forest->firex = posx;
    forest->firey = posy;
}

void customizeField(Forest * forest){
        char confirmation;
        printf("\nYour field has been generated. Do you want to customize it? (y/[n]): ");
        fpurge(stdin);
        scanf("%c", &confirmation);
        while (confirmation == 'y') {
            int posx, posy, elem;
//
            printf("Enter position x [0 - %d]: ", forest->sizex - 1);
            scanf("%d", &posx);
            printf("Enter position y [0 - %d]: ", forest->sizey - 1);
            scanf("%d", &posy);
            
            if (posx > 500 || posy > 500){
                printf("You must use reasonable values!\n");
                confirmation = 'n';
                editField(forest);
                return;
            }
            
            printf("Enter the element you want to place (0 - ground / 1 - grass / 2 - tree / 3 - leaf / 4 - rock / [5 - water]): ");
            scanf("%d", &elem);
//
            forest->field[posx][posy] = setElement(forest->field[posx][posy], elem);
            printField(forest->field, forest->sizex, forest->sizey);
//
            printf("Do you want to continue customizing? (y/[n]): ");
            fpurge(stdin);
            scanf("%c", &confirmation);
        }

}

void editField(Forest * forest){
    char confirmation = 'y';
    while (confirmation == 'y') {
        int posx, posy, elem;
            //
        printf("Enter position x [0 - %d]: ", forest->sizex - 1);
        scanf("%d", &posx);
        printf("Enter position y [0 - %d]: ", forest->sizey - 1);
        scanf("%d", &posy);
        
        if (posx > 500 || posy > 500){
            printf("You must use reasonable values!\n");
            confirmation = 'n';
            editField(forest);
            return;
        }
        
        printf("Enter the element you want to place (0 - ground / 1 - grass / 2 - tree / 3 - leaf / 4 - rock / [5 - water]): ");
        scanf("%d", &elem);
            //
        forest->field[posx][posy] = setElement(forest->field[posx][posy], elem);
        printField(forest->field, forest->sizex, forest->sizey);
            //
        printf("Do you want to continue editing? (y/[n]): ");
        fpurge(stdin);
        scanf("%c", &confirmation);
    }
    
}

void changeFireSource(Forest * forest){
    int t0 = forest->field[forest->firex][forest->firey].state;
    resetTime(forest);
    setFireStart(forest);
    setTime(forest);
    tplus(t0, forest);
}

void createField(Forest * forest){
    setSize(forest);
    initField(forest);
    printField(forest->field, forest->sizex, forest->sizey);
    customizeField(forest);
    setFireStart(forest);
    setTime(forest);
    printField(forest->field, forest->sizex, forest->sizey);
}

void extendField(Forest * forest){
    setSize(forest);
}
