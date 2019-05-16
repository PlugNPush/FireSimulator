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

