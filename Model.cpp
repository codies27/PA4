//
//  Model.cpp
//  PA4
//
//  Created by Codie Smith on 5/2/14.
//  Copyright (c) 2014 Codie's Midterm. All rights reserved.
//

#include "Model.h"
#include "Miner.h"
#include "Tower.h"
#include "Candy_Mine.h"
#include "C_Point.h"
#include "Warrior.h"


Model::Model()
{
    time = 0;
    
    C_Point loc1(5,1);
    C_Point loc2(10,1);
    C_Point loc3(1,20);
    C_Point loc4(10,20);
    C_Point loc5(5,15);
    C_Point loc6(10,15);
   
    Miner* m1 = new Miner(1,loc1);
    Miner* m2 = new Miner(2,loc2);
    Candy_Mine* c1 = new Candy_Mine(1,loc3);
    Candy_Mine* c2 = new Candy_Mine(1,loc4);
    Tower* t1 = new Tower;
    Warrior* w1 = new Warrior(3,loc5);
    Warrior* w2 = new Warrior(4,loc6);
    
    num_objects = 7;
    num_people = 4;
    
    game_object_ptrs[0] = m1;
    game_object_ptrs[1] = m2;
    game_object_ptrs[2] = c1;
    game_object_ptrs[3] = c2;
    game_object_ptrs[4] = t1;
    game_object_ptrs[5] = w1;
    game_object_ptrs[6] = w2;
    
    person_ptrs[0] = m1;
    person_ptrs[1] = m2;
    person_ptrs[2] = w1;
    person_ptrs[3] = w2;
    
    mine_ptrs[0] = c1;
    mine_ptrs[1] = c2;
    
    tower_ptrs[0] = t1;

    cout << "Model Default Constructed" << endl;
    
}
 

bool Model::update()
{
    bool temp = false;
    time++;
    for (int i=0;i<num_objects;i++)
    {
        if(game_object_ptrs[i]->update())
        {
            temp = true;
        }
    }
    return temp;
}

void Model::display(View &view)
{
    cout << "Time is: " << time << endl;
    
    for (int i=0;i<num_objects;i++)
    {
        view.plot(game_object_ptrs[i]);
    }
    view.draw();
}

void Model::show_status()
{
    for (int i=0;i<num_objects;i++)
    {
        game_object_ptrs[i]->show_status();
    }
}

Person* Model::get_person_ptr(int id)
{
    Person* newptr = 0;
    for (int i=0;i<num_people;i++)
    {
        if (person_ptrs[i]->get_id() == id)
        {
            newptr = person_ptrs[i];
        }
    }
    return newptr;
}

Candy_Mine* Model::get_mine_ptr(int id)
{
    Candy_Mine* newptr = 0;
    for (int i=0;i<num_mines;i++)
    {
        if (mine_ptrs[i]->get_id() == id)
        {
            newptr = mine_ptrs[i];
        }
    }
    return newptr;
}

Tower* Model::get_tower_ptr(int id)
{
    Tower* newptr = 0;
    for (int i=0;i<num_towers;i++)
    {
        if (tower_ptrs[i]->get_id() == id)
        {
            newptr = tower_ptrs[i];
        }
    }
    return newptr;
}



