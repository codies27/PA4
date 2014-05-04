//
//  Warrior.cpp
//  PA4
//
//  Created by Codie Smith on 5/3/14.
//  Copyright (c) 2014 Codie's Midterm. All rights reserved.
//

#include "Warrior.h"
#include "C_Vector.h"
#include <cmath>

Warrior::Warrior(): Person('W')
{
    attack_strength = 2;
    range = 2.0;
}

Warrior::Warrior(int ID,C_Point loc): Person('W',ID,loc)
{
    attack_strength = 2;
    range = 2.0;
}

void Warrior::start_attack(Person* targ)
{
    C_Point targetloc = targ->get_location();
    C_Vector dist = location-targetloc;
    int hyp = sqrt(pow(dist.x,2)+pow(dist.y,2));
    if (hyp > range)
    {
        cout << "Target is out of range!" << endl;
    }
    else
    {
        cout << "CLANG!" << endl;
        target = targ;
        state = 'a';
        
    }
}

bool Warrior::update()
{
    switch (state)
    {
            case 'x':
        {
            return false;
            break;
        }
            case 's':
        {
            return false;
            break;
        }
            case 'm':
        {
            if (update_location() == true)
            {
                state = 's';
                return true;
            }
            else
                return false;
            break;
        }
            case 'a':
        {
            C_Vector dist = location-target->get_location();
            double hyp = sqrt(pow(dist.x,2)+pow(dist.y,2));
            if (hyp > range)
            {
                cout << "not close enough!" << endl;
            }
            else
            {
                if(target->is_alive() == true)
                {
                    cout << "clang!" << endl;
                    target->take_hit(attack_strength);
                    return false;
                    break;
                }
            else
                {
                    cout << "I triumphed!" << endl;
                    state = 's';
                    return true;
                    break;
                }
            }
            
        }
        default:
            return false;
    }
}

    
void Warrior::show_status()
{
    Person::show_status();
    if (state == 'a')
    {
        cout << "Attacking!" << endl;
    }
    else
    {
        cout << "not attacking!" << endl;
    }
}