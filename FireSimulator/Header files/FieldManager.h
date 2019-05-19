//
//  FieldManager.h
//  FireSimulator
//
//  Created by PlugN on 16/05/2019.
//  Copyright © 2019 Groupe MINASTE. All rights reserved.
//

#ifndef FieldManager_h
#define FieldManager_h

#include "GlobalConfiguration.h"
#include "DisplayManager.h"
#include "TimeManager.h"

Element dropElement(void);
void setSize(Forest * forest);
void initField(Forest * forest);
void customizeField(Forest * forest);
void setFireStart(Forest * forest);
void changeFireSource(Forest * forest);
void editField(Forest * forest);
void createField(Forest * forest);
#endif /* FieldManager_h */
