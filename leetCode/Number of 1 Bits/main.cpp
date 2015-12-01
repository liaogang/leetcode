//
//  main.cpp
//  Number of 1 Bits
//
//  Created by liaogang on 15/3/17.
//  Copyright (c) 2015年 liaogang. All rights reserved.
//

#include <iostream>
#include "../leetcode.h"

/**
 Number of 1 Bits
 
 Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
 
 For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
 */




int hammingWeight(uint32_t n)
{
    int total = 0;
    for(int i = 0; i<32; i++)
    {
        total += (n & (1 << i))? 1: 0;
    }
    
    return total;
}


int hammingWeight2(uint32_t n)
{
    int table[]={0,1,1,2,1,2,1,3};
    
    
    
}


int main(int argc, const char * argv[])
{
    cout<<hammingWeight(2)<<endl;
    return 0;
}
