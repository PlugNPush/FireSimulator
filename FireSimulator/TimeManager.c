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
