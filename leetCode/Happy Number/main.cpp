//
//  main.cpp
//  Happy Number
//
//  Created by liaogang on 16/3/11.
//  Copyright © 2016年 liaogang. All rights reserved.
//

#include <iostream>


/**
 Write an algorithm to determine if a number is "happy".
 
 A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 
 Example: 19 is a happy number
 
 12 + 92 = 82
 82 + 22 = 68
 62 + 82 = 100
 12 + 02 + 02 = 1

 */

#include "../leetcode.h"

class Solution {
public:
    bool isHappy(int n) {
        bool result;
        
        const int maxlen = 20;
        int v[maxlen] = {0};
        
        int ten = 10;
        int w;//位数
        for (int i = 0; i < maxlen ; i++) {
            
            if ( n < ten) {
                w = i;
                break;
            }
            
            
            ten = ten*10;
        }
        
        
        
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    
    Solution a;
    
    a.isHappy(19);
    
    
    
    return 0;
}
