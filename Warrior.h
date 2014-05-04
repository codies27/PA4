//
//  Warrior.h
//  PA4
//
//  Created by Codie Smith on 5/3/14.
//  Copyright (c) 2014 Codie's Midterm. All rights reserved.
//

#ifndef PA4_Warrior_h
#define PA4_Warrior_h
#include "Person.h"

class Warrior: public Person
{
public:
    void start_attack(Person*);
    Warrior();
    Warrior(int,C_Point);
    void show_status();
    bool update();
    
private:
    int attack_strength;
    double range;
    Person* target;
    
    
};

#endif
