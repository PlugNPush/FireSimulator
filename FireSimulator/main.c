//
//  main.c
//  FireSimulator
//
//  Created by PlugN on 16/05/2019.
//  Copyright © 2019 Groupe MINASTE. All rights reserved.
//


#include "Header files/main.h"

Element field[500][500];
int sizex, sizey;

void initField(){
    int i, j;
    for (i = 0; i < sizex; i++) {
        for (j = 0; j < sizey; j++) {
            field[i][j] = dropElement();
        }
    }
}

void printField(){
    int i, j;
    for (i = 0; i < sizex; i++) {
        for (j = 0; j < sizey; j++) {
            printElement(field[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}



int main(int argc, const char * argv[]) {
    srand((unsigned int)time(NULL));
    sizex = 10;
    sizey = 10;
    initField();
    printField();
    return 0;
}
