//
//  TimeManager.h
//  FireSimulator
//
//  Created by PlugN on 16/05/2019.
//  Copyright © 2019 Groupe MINASTE. All rights reserved.
//

#ifndef TimeManager_h
#define TimeManager_h

#include "GlobalConfiguration.h"
#include "DisplayManager.h"
void setTime(Forest * forest);
void tplus(int num, Forest * forest);
void tequal(int num, Forest * forest);
void resetTime(Forest * forest);
void getElementInfo(Forest * forest);
#endif /* TimeManager_h */
