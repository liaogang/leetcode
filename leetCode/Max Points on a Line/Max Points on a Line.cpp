//
//  main.cpp
//  Max Points on a Line
//
//  Created by liaogang on 14/12/31.
//  Copyright (c) 2014年 liaogang. All rights reserved.
//

#include <iostream>
#include "../../leetcode.h"

/**
    Max Points on a Line
 
 Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 */


bool isOnLine(Line ln , Point &pt)
{
    return (ln.b.y - ln.a.y ) * (pt.x - ln.a.x) == (ln.b.x - ln.a.x) * (pt.y - ln.a.y );
}

int maxPoints(vector<Point> &points)
{
    unsigned int countPt = (unsigned int)points.size();
    
    
    if (countPt == 0) {
        return 0;
    }
    else if( countPt == 1)
    {
        return 1;
    }
    else if (countPt == 2)
    {
        return 2;
    }
    else if (countPt == 3)
    {
        return isOnLine(Line( points[0], points[1]), points[2])?3:2;
    }
    else
    {
        return 4;
    }
    
}


int main(int argc, const char * argv[])
{
    vector<Point> points({ {-4,1},{-7,7},{-1,5},{9,-25}});
    
    cout<<maxPoints(points)<<endl;
    
    return 0;
}
