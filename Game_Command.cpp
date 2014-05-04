//
//  Game_Command.cpp
//  PA4
//
//  Created by Codie Smith on 5/3/14.
//  Copyright (c) 2014 Codie's Midterm. All rights reserved.
//

#include "Game_Command.h"
#include "Miner.h"


void move_function(Model &model)
{
    int idnum;
    int xval;
    int yval;
    cin >> idnum >> xval >> yval;
    Person* m1 = model.get_person_ptr(idnum);
    C_Point loc(xval,yval);
    m1->start_moving(loc);
}

void work_function(Model &model)
{
    int ID1, ID2, ID3;
    cin >> ID1 >> ID2 >> ID3;
    Person* m1 = model.get_person_ptr(ID1);
    Candy_Mine* c1 = model.get_mine_ptr(ID2);
    Tower* t1 = model.get_tower_ptr(ID3);
    
    m1->start_mining(c1,t1);
    
}

void stop_function(Model &model)
{
    int ID;
    cin >> ID;
    Person* m1 = model.get_person_ptr(ID);
    m1->stop();
}

void go_function(Model &model)
{
    model.update();
    
}

void run_function(Model &model)
{
    while(!model.update())
    {
        model.update();
    }
}
