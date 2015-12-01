//
//  main.cpp
//  Number of Digit One
//
//  Created by liaogang on 15/7/8.
//  Copyright (c) 2015年 liaogang. All rights reserved.
//

#include <iostream>
#include "../leetcode.h"

/*
 Number of Digit One
 
 Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
 
 For example:
 Given n = 13,
 Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 
 Hint:
 
 Beware of overflow.

 */

// 0~9 , 0~99 , 0~999

/**
    nn must be 100... , w代表位数
    计算0 ~ 9xx 中的个数.
 */


static int cache[32] = {};


void fillCache( int w )
{
    for ( int iw = 1 ; iw <= w ; iw++ )
    {
        int totalNumber = 0;
        
        int powerW = 1;
        for (int ipw = 0; ipw < iw - 1 ; ipw ++) {
            powerW *= 10;
        }
        
        
        totalNumber += powerW ;
        totalNumber += ( ( iw == 1) ? 0 : cache[iw-1] ) * 9;
        
        cache[iw] = totalNumber;
    }

}





int countDigitOne(int n)
{
    int digits[32] = {0};
    int digitNumber = 0;
    
    int v = 10;
    for (int i = 1; i < 32 && n * 10 >= v ; i++ , v *= 10) {
        digits[i] = ( n % v ) / ( v / 10);
        digitNumber++;
    }
    
    reverse(digits+1, digits+digitNumber+1);
    
    fillCache(digitNumber);
    
    
    
    int numberOfOne = 0;
 
    for (int iw = 1  ; iw <= digitNumber ; iw++ ) {
        
        printf("current parsing: %d\n",digits[iw]);
        
        int powerW = 1;
        for (int ipw = 1; ipw < iw ; ipw ++) {
            powerW *= 10;
        }
        
        if ( digits[iw] >= 1 )
        {
            int abc =  n % (powerW * 10);
            numberOfOne += abc + 1;
        }
        else
        {
            numberOfOne += ( ( iw == 1) ? 0 : cache[iw-1] ) * ( digits[iw] + 1 );
        }
        

    }
    
    
    
    
    return numberOfOne;
}


int main(int argc, const char * argv[]) {
    
    int result = countDigitOne(13);
    
//    fillCache(5);
    
    return 0;
}
