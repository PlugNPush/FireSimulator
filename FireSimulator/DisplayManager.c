//
//  DisplayManager.c
//  FireSimulator
//
//  Created by PlugN on 16/05/2019.
//  Copyright © 2019 Groupe MINASTE. All rights reserved.
//

#include "Header files/DisplayManager.h"

void printElement(Element e){
    
    if (e.type != 0 && e.type != 5 && e.state > 0){
        if (e.state <= e.degree)
            printf("🔥");
        else if (e.state == e.degree + 1)
            printf("🌫");
        else if (e.state > e.degree + 1)
            printf("⬛️");
        return;
    }
    
    switch (e.type) {
        case 0:
            printf("🛤️");
            break;
        case 1:
            printf("🌿");
            break;
        case 2:
            printf("🌴");
            break;
        case 3:
            printf("🍂");
            break;
        case 4:
            printf("🗿");
            break;
        case 5:
            printf("🌊");
            break;
            
        default:
            break;
    }
}

void printNaturalElement(Element e){
    switch (e.type) {
        case 0:
            printf("🛤️");
            break;
        case 1:
            printf("🌿");
            break;
        case 2:
            printf("🌴");
            break;
        case 3:
            printf("🍂");
            break;
        case 4:
            printf("🗿");
            break;
        case 5:
            printf("🌊");
            break;
            
        default:
            break;
    }
}

void standardPrint(Forest forest){
    int i, j;
    for (i = 0; i < forest.sizex; i++) {
        for (j = 0; j < forest.sizey; j++) {
            printElement(forest.field[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}

void extractStateField(Forest forest){
    int i, j;
    for (i = 0; i < forest.sizex; i++) {
        for (j = 0; j < forest.sizey; j++) {
            printf("%d", forest.field[i][j].state);
            printf(" ");
        }
        printf("\n");
    }
}

void printField(Element field[][500], int sizex, int sizey){
    int i, j;
    for (i = 0; i < sizex; i++) {
        for (j = 0; j < sizey; j++) {
            printElement(field[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}
