//
//  FieldManager.c
//  FireSimulator
//
//  Created by PlugN on 16/05/2019.
//  Copyright © 2019 Groupe MINASTE. All rights reserved.
//


#include "Header files/FieldManager.h"

Element ground = {0, 0, 0};
Element grass = {1, 3, 0};
Element tree = {2, 4, 0};
Element Leaf = {3, 2, 0};
Element rock = {4, 5, 0};
Element water = {5, 0, 0};

Element dropElement(){
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

Element getElement(int drop){
    
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
}

void initField(Forest * forest){
    int i, j;
    for (i = 0; i < forest->sizex; i++) {
        for (j = 0; j < forest->sizey; j++) {
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
            printf("Enter the element you want to place (0 - ground / 1 - grass / 2 - tree / 3 - leaf / 4 - rock / [5 - water]): ");
            scanf("%d", &elem);
//
            forest->field[posx][posy] = getElement(elem);
            emergencyPrint(forest->field, forest->sizex, forest->sizey);
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
        printf("Enter the element you want to place (0 - ground / 1 - grass / 2 - tree / 3 - leaf / 4 - rock / [5 - water]): ");
        scanf("%d", &elem);
            //
        forest->field[posx][posy] = getElement(elem);
        emergencyPrint(forest->field, forest->sizex, forest->sizey);
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
    emergencyPrint(forest->field, forest->sizex, forest->sizex);
    customizeField(forest);
    setFireStart(forest);
    setTime(forest);
    emergencyPrint(forest->field, forest->sizex, forest->sizex);
}
