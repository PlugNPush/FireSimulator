//
//  TimeManager.c
//  FireSimulator
//
//  Created by PlugN on 16/05/2019.
//  Copyright © 2019 Groupe MINASTE. All rights reserved.
//

#include "Header files/TimeManager.h"

int computeTime(int firex, int firey, int posx, int posy){
    int time, time2;
    
    time = -abs(firex - posx);
    time2 = -abs(firey - posy);
    
    if (time < time2){
        return time;
    } else {
        return time2;
    }
    
}

void setTime(Forest * forest){
    int i, j;
    for (i = 0; i < 500; i++) {
        for (j = 0; j < 500; j++) {
            forest->field[i][j].state = computeTime(forest->firex, forest->firey, i, j);
        }
    }
}

void tplus(int num, Forest * forest){
    int i, j;
    for (i = 0; i < 500; i++) {
        for (j = 0; j < 500; j++) {
            forest->field[i][j].state = forest->field[i][j].state + num;
        }
    }
}

void tequal(int num, Forest * forest){
    int t0 = forest->field[forest->firex][forest->firey].state;
    int reset = num - t0;
    tplus(reset, forest);
}

void resetTime(Forest * forest){
    int t0 = forest->field[forest->firex][forest->firey].state;
    int reset = 0 - t0;
    tplus(reset, forest);
}

void getElementInfo(Forest * forest){
    int posx, posy;
    
    fpurge(stdin);
    printf("Enter position x [0 - %d]: ", forest->sizex - 1);
    scanf("%d", &posx);
    printf("Enter position y [0 - %d]: ", forest->sizey - 1);
    scanf("%d", &posy);
    
    if (posx > 500 || posy > 500){
        printf("You must use reasonable values!\n");
        getElementInfo(forest);
        return;
    }
    
    printf("Element: ");
    printNaturalElement(forest->field[posx][posy]);
    printf("\n");
    
    if(forest->field[posx][posy].type == 0 || forest->field[posx][posy].type == 5){
        printf("This element is constant.\n");
    }
    
    else if (forest->field[posx][posy].state <= 0){
        int turn = abs(forest->field[posx][posy].state) + 1;
        int ash = abs(forest->field[posx][posy].state) + 1 + forest->field[posx][posy].degree;
        printf("The element will be on fire in %d steps.\n", turn);
        printf("The element will be ashes in %d steps.\n", ash);
        printf("The element will be extinguished ashes in %d steps.\n", ash+1);
    }
    
    else if (forest->field[posx][posy].state > 0 && forest->field[posx][posy].state <= forest->field[posx][posy].degree){
        int ash = (forest->field[posx][posy].degree - (abs(forest->field[posx][posy].state))) + 1;
        printf("This element is on fire.\n");
        printf("The element will be ashes in %d steps.\n", ash);
        printf("The element will be extinguished ashes in %d steps.\n", ash+1);
    }
    
    else if (forest->field[posx][posy].state > 0 && forest->field[posx][posy].state == forest->field[posx][posy].degree + 1){
        printf("This element is in ashes.\n");
        printf("The element will be extinguished ashes in 1 step.\n");
    }
    
    else {
        printf("This element is in extinguished ashes.\n");
    }
}
