//
//  Person.cpp
//  PA4
//
//  Created by Codie Smith on 4/27/14.
//  Copyright (c) 2014 Codie's Midterm. All rights reserved.
//

#include "Person.h"
#include <cmath>

Person::Person()
{
    speed = 5;
    health = 5;
    cout << "Person default constructed." << endl;
}

Person::Person(char incode): Game_Object(incode)
{
    speed = 5;
    health = 5;
    cout << "Person constructed." << endl;
    
}

Person::Person(char incode,int in_id,C_Point in_loc): Game_Object(incode,in_id,in_loc)
{
    speed = 5;
    health = 5;
    cout << "Person constructed." << endl;
}

void Person::setup_destination(C_Point dest)
{
    delta = (dest-location)*(speed/C_distance(dest,location));
    destination = dest;
}

void Person::start_moving(C_Point dest)
{
    int ID = get_id();
    setup_destination(dest);
    state = 'm';
    cout << "Moving " << ID << " to " << dest << endl;
    cout << display_code << " " << ID << ": On my way." << endl;
}

void Person::stop()
{
    int ID = get_id();
    state = 's';
    cout << "Stopping " << display_code << " " << ID << "." << endl;
    cout << display_code << " " << ID << ": All right." << endl;
}

void Person::show_status()
{
    Game_Object::show_status();
    switch (state)
    {
        case 's':
        {
            cout << "Stopped." << endl;
            cout << "Health is: " << health << endl;
            break;
        }
        case 'm':
        {
            cout << "Moving at speed " << speed << " to " << destination << ", amounts on each step are " << delta << "." << endl;
            cout << "Health is: " << health << endl;
            break;
        }
        case 'x':
        {
            cout << "is dead. R.I.P." << endl;
        }
    }

}

bool Person::update_location()
{
        double xval = fabs(destination.x-location.x);
        double yval = fabs(destination.y-location.y);
        if(xval <= delta.x && yval <=delta.y)
        {
            location = destination;
            cout << "Arrived!" << endl;
            return true;
        }
        else
        {
            location = location + delta;
            cout << "step..." << endl;
            return false;
        }

}

void Person::start_mining(Candy_Mine* c1,Tower* t1)
{
    cout << "Sorry, I can't mine right now." << endl;
}

bool Person::is_alive()
{
    if (state == 'x')
    {
        return false;
    }
    else
        return true;
}

void Person::start_attack(Person* target)
{
    cout << "Sorry, I can't attack right now." << endl;
}

void Person::take_hit(int attack_strength)
{
    health = health-attack_strength;
    if (health <= 0)
    {
        cout << "AGHHHHH!!!!!!" << endl;
        state = 'x';
    }
}
