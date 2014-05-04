//
//  game_object.h
//  PA4
//
//  Created by Codie Smith on 4/27/14.
//  Copyright (c) 2014 Codie's Midterm. All rights reserved.
//

#ifndef PA4_game_object_h
#define PA4_game_object_h

#include "C_Point.h"
#include <iostream>
using namespace std;

class Game_Object
{
public:
    Game_Object();
    Game_Object(char);
    Game_Object(char,int,C_Point);
    
    C_Point get_location();
    int get_id();
    virtual void show_status();
    void drawself(char *);
    virtual bool update() = 0;
    
protected:
    C_Point location;
    char display_code;
    char state;
    
private:
    int id_num;
    
};


#endif
