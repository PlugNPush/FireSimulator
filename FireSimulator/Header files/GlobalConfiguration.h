//
//  GlobalConfiguration.h
//  FireSimulator
//
//  Created by PlugN on 16/05/2019.
//  Copyright © 2019 Groupe MINASTE. All rights reserved.
//

#ifndef GlobalConfiguration_h
#define GlobalConfiguration_h

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element {
    int type;
    int degree;
    int state;
}Element;

typedef struct Forest {
    Element field[500][500];
    int firex;
    int firey;
    int sizex;
    int sizey;
}Forest;

#endif /* GlobalConfiguration_h */
