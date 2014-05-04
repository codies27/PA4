//
//  Person.h
//  PA4
//
//  Created by Codie Smith on 4/27/14.
//  Copyright (c) 2014 Codie's Midterm. All rights reserved.
//

#ifndef PA4_Person_h
#define PA4_Person_h

#include <iostream>
#include "game_object.h"
#include "Candy_Mine.h"
#include "Tower.h"

using namespace std;

class Person: public Game_Object
{
public:
    Person();
    Person(char);
    Person(char,int,C_Point);
    
    void start_moving(C_Point);
    void stop();
    void show_status();
    virtual void start_mining(Candy_Mine*,Tower*);
    bool is_alive();
    void take_hit(int);
    virtual void start_attack(Person*);
    
    
    
protected:
    bool update_location();
    void setup_destination(C_Point);

private:
    double speed;
    C_Point destination;
    C_Vector delta;
    int health;
    
    
};

#endif
