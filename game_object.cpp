//
//  game_object.cpp
//  PA4
//
//  Created by Codie Smith on 4/27/14.
//  Copyright (c) 2014 Codie's Midterm. All rights reserved.
//

#include "game_object.h"

Game_Object::Game_Object()
{
    display_code = 's';
    state = 's';
    id_num = 0;
    
    cout << "Game_Object default constructed." << endl;
    
}

Game_Object::Game_Object(char incode)
{
    display_code = incode;
    state = 's';
    id_num = 0;
    
    cout << "Game_Object constructed." << endl;
}

Game_Object::Game_Object(char incode,int in_id,C_Point in_loc)
{
    display_code = incode;
    state = 's';
    id_num = in_id;
    location = in_loc;
    
    cout << "Game_Object constructed." << endl;
}

C_Point Game_Object::get_location()
{
    return location;
}

int Game_Object::get_id()
{
    return id_num;
}

void Game_Object::show_status()
{
    cout << display_code << " " << id_num << " " << location << endl;
    
}

void Game_Object::drawself(char *ptr)
{
    *ptr = display_code;
    *(ptr+1) = id_num + '0';
}
