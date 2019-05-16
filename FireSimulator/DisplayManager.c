//
//  DisplayManager.c
//  FireSimulator
//
//  Created by PlugN on 16/05/2019.
//  Copyright © 2019 Groupe MINASTE. All rights reserved.
//

#include "Header files/DisplayManager.h"

void printElement(Element e){
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
