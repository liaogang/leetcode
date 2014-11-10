//
//  main.cpp
//  Sqrt
//
//  Created by liaogang on 14/10/29.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//

#include <iostream>
using namespace std;

/**
 Implement int sqrt(int x).
 
 Compute and return the square root of x.
 */

///@see http://en.wikipedia.org/wiki/Newton%27s_method
int sqrt(int m)
{
    double a = m/2.0;
    
    double last=0;
    while (a!=last)
    {
        last=a;
        a=(a+m/a)/2;
    }
    
    return a;
}


int main(int argc, const char * argv[])
{
    cout<< sqrt(1) <<endl;
    cout<< sqrt(0) <<endl;
    cout<< sqrt(4) <<endl;
    cout<< sqrt(9) <<endl;
    cout<< sqrt(16) <<endl;
    cout<< sqrt(2147395599) <<endl;
    //expected: 46339
    
    return 0;
}

