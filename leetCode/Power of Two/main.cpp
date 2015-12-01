//
//  main.cpp
//  Power of Two
//
//  Created by liaogang on 15/7/8.
//  Copyright (c) 2015年 liaogang. All rights reserved.
//

#include <iostream>
#include "../leetcode.h"

/*
 Given an integer, write a function to determine if it is a power of two. 
 */

bool isPowerOfTwo(int n)
{
    if (n <= 0)
        return false;
    
    
    while ( n > 1) {
        if (n & 0x1) {
            return false;
        }
        
        n >>= 1;
    }
    
    return n & 0x1;
}


int main(int argc, const char * argv[]) {
    
    isPowerOfTwo(2);
    
    int n = 0;
    while (n++ < 30000) {
        if (isPowerOfTwo(n)) {
        printf("%d is power of two.\n",n);
        }
        
        //printf("%d is power of two: %d\n",n,isPowerOfTwo(n));
    }
    
    
    
    return 0;
}
