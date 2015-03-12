//
//  main.cpp
//  Gray Code
//
//  Created by liaogang on 15/3/12.
//  Copyright (c) 2015年 liaogang. All rights reserved.
//

#include <iostream>
#include "../leetcode.h"

/*
 Gray Code
 
 The gray code is a binary numeral system where two successive values differ in only one bit.
 
 Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
 
 For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 
 00 - 0
 01 - 1
 11 - 3
 10 - 2

 */


vector<int> grayCode(int n)
{
    if ( n <= 2)
    {
        vector<int> result;
        
        if (n == 0) {
            result.push_back(0);
        }
        else if( n == 1) {
            result.push_back(0);
            result.push_back(1);
        }
        else {
            result.push_back(0);
            result.push_back(1);
            result.push_back(3);
            result.push_back(2);
        }
        
        return result;
    }
    else
    {
        vector<int> r1 = grayCode(n-1);
        
        int len =(int) r1.size();
        
        r1.reserve(len + len);
        
        for (int i = len -1 ; i >= 0; i--)
            r1.push_back(r1[i] | 1 << (n -1));
        
        return r1;
    }
    
}


int main(int argc, const char * argv[])
{
    auto c = grayCode(4);
    
    printContainer(c);
    
    return 0;
}
