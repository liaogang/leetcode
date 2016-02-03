//
//  main.cpp
//  Add Digits
//
//  Created by liaogang on 16/2/3.
//  Copyright © 2016年 liaogang. All rights reserved.
//

#include <iostream>

/**
 Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 
 For example:
 
 Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
 
 Follow up:
 Could you do it without any loop/recursion in O(1) runtime?
 
 Hint:
 
 A naive implementation of the above process is trivial. Could you come up with other methods?
 What are all the possible results?
 How do they occur, periodically or randomly?
 You may find this Wikipedia article useful.

 */

#include "../leetcode.h"
#include <assert.h>

int addDigits(int num) {
   
        int result;
        int base = num / 10;
        result = base + num - base*10;
        
        if (result >= 10)
            return addDigits(result);
        else
            return result;
    
}

int addDigits2(int num)
{
    return num<10 ? num : num%9==0 ? 9 : (num-9)%9 ;
}

int main(int argc, const char * argv[]) {
    
    addDigits(19);
    
//    for (int i = 0; i < 9999; i++) {
//        addDigits(i);
//    }
    
    
    
    
    return 0;
}
