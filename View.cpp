//
//  View.cpp
//  PA4
//
//  Created by Codie Smith on 4/28/14.
//  Copyright (c) 2014 Codie's Midterm. All rights reserved.
//

#include "View.h"

View::View()
{
    size = 11;
    scale = 2;
    
}

void View::clear()
{
    for (int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
                grid[i][j][0] = '.';
                grid[i][j][1] = ' ';
            
        }
    }
            
}

bool View::get_subscripts(int &ix,int &iy,C_Point location)
{
    C_Point newpoint = origin + ((location-origin)/scale);
    ix = -newpoint.x;
    iy = -newpoint.y;
    if ((ix<=20) && (ix>=0) && (iy<=20) && (iy>=0))
    {
        return true;
    }
    else
    {
        cout << "YOU'Z OUTSIDE!!!" << endl;
        return false;
    }
}

void View::plot(Game_Object * ptr)
{
    int one,two;
    char C[2];
    C_Point newloc = ptr->get_location();
    get_subscripts(one,two,newloc);
    ptr->drawself(C);
    if (grid[one][two][0] == '.')
    {
        grid[one][two][0] = *C;
        grid[one][two][1] = *(C+1);
    }
    else
    {
        grid[one][two][0] = '*';
        grid[one][two][1] = ' ';
    }
    
}

void View::draw()
{
    for (int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            cout << grid[i][j][0] << grid[i][j][1];
        }
        cout << endl;
    }
}
