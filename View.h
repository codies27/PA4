//
//  View.h
//  PA4
//
//  Created by Codie Smith on 4/28/14.
//  Copyright (c) 2014 Codie's Midterm. All rights reserved.
//

#ifndef PA4_View_h
#define PA4_View_h
#include "C_Point.h"
#include <iostream>
#include "game_object.h"
using namespace std;

const int view_maxsize = 20;

class View
{
public:
    View();
    void clear();
    void plot(Game_Object *);
    void draw();

private:
    int size;
    double scale;
    C_Point origin;
    char grid[view_maxsize][view_maxsize][2];
    bool get_subscripts(int &,int &,C_Point);
    
    
};

#endif
