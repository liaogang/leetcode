//
//  main.cpp
//  Single Number
//
//  Created by liaogang on 15/2/5.
//  Copyright (c) 2015年 liaogang. All rights reserved.
//

#include <iostream>
#include "../../leetcode.h"

/**
 Single Number
 
 Given an array of integers, every element appears twice except for one. Find that single one.
 
 Note:
 Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */




int singleNumber(int A[], int n)
{
    while (--n)
        A[n - 1] ^= A[n];
    return A[0];
}

void printHexString(int h)
{
    int c = sizeof(h) * 8;
    while (c--) {
        printf("%d", (h & (1 << c)) ? 1 : 0 );
    }
    
    printf("\n" );
}

int singleNumber2(int A[], int n)
{
    if (n == 1)
        return A[0];
    

    int ones = 0 ,twos = 0;
    
    for (int i =0 ; i < n ; i ++)
    {
        ones = (A[i] ^ ones)  & ~twos ;
        
        twos = (A[i] ^ twos ) & ~ones;
        
        printf("   A: ");
        printHexString( A[i]);
        printf("ones: ");
        printHexString( ones);
        printf("twos: ");
        printHexString( twos);
        //printHexString( ones | twos);
        printf("next\n");
    }
    
    return ones | twos ;
}


int main(int argc, const char * argv[])
{
    printHexString( 8 );
    printHexString( 1 );
    
     int test[] = {1,2,3,3,2,1,4,4,4,4,6,5,6,5};
    
    int r = singleNumber( test , (int) (sizeof(test)/sizeof(test[0]) ) );
    
    cout<<"result: "<<r<<endl;
    
//    int test2[] = {3,12,12,12,3,4,4,4,8,8,8};
//    int test2[] = { -2, -2,  -4, -2 };
    int test2[] = { 2, 2,  4, 2 };
    
    int r2 = singleNumber2( test2 , (int) (sizeof(test2)/sizeof(test2[0]) ) );
    
    cout<<"result: "<<r2<<endl;
    
    return 0;
}


