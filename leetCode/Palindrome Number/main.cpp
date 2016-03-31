//
//  main.cpp
//  Palindrome Number
//
//  Created by liaogang on 16/3/31.
//  Copyright © 2016年 liaogang. All rights reserved.
//

#include <iostream>
#include "../leetcode.h"

/**
 Determine whether an integer is a palindrome. Do this without extra space.
 
 click to show spoilers.
 Some hints:
 
 Could negative integers be palindromes? (ie, -1)
 
 If you are thinking of converting the integer to string, note the restriction of using extra space.
 
 You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
 
 There is a more generic way of solving this problem.

 */

long reverse(long x) {
    
    bool fu = x < 0;
    
    if (fu ) {
        x = -x;
    }
    
    int y=0;
    int n;
    while( x != 0){
        n = x%10;
        y = y*10 + n;
        x /= 10;
    }
    
    if (fu) {
        return y*-1;
    }
    
    return y;
}

bool isPalindrome(int x) {
    if (x < 0)
        return false;

    return x == reverse(x);
}


int main(int argc, const char * argv[])
{
    isPalindrome(9382);
    
    
    
    return 0;
}
