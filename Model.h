//
//  Model.h
//  PA4
//
//  Created by Codie Smith on 5/2/14.
//  Copyright (c) 2014 Codie's Midterm. All rights reserved.
//

#ifndef PA4_Model_h
#define PA4_Model_h
#include <iostream>
#include "View.h"
#include "Person.h"
#include "Candy_Mine.h"
#include "Tower.h"

using namespace std;

class Model
{
public:
    Model();
    bool update();
    void display(View&);
    void show_status();
    Person* get_person_ptr(int);
    Candy_Mine* get_mine_ptr(int);
    Tower* get_tower_ptr(int);

private:
    int time;
    Game_Object* game_object_ptrs[10];
    int num_objects;
    Person* person_ptrs[10];
    int num_people;
    Candy_Mine* mine_ptrs[10];
    int num_mines;
    Tower* tower_ptrs[10];
    int num_towers;
    
    
};

#endif
