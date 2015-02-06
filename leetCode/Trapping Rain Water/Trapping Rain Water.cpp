//
//  main.cpp
//  Trapping Rain Water
//
//  Created by liaogang on 14/12/25.
//  Copyright (c) 2014年 liaogang. All rights reserved.
//

#include <iostream>
/**
 Trapping Rain Water
 @see: https://oj.leetcode.com/problems/trapping-rain-water/
 
 Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 
 For example,
 Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 
 
 The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
 */


#define TEST 1

int trap(int A[], int n)
{
    if (n < 3)
        return 0;
    
    int totalRain=0;
    int rain=0;
    
    int leftTopPos = -1;
    int rightTopPos = -1;
    int valleyPos = -1;
    
    int last = A[0];
    for (int i = 1; i <= n ; i++)
    {
        int a = i == n ? 0 : A[i];
        
#ifdef TEST
        printf("~~~~~~~currPos:%d ,value:%d ~~~~~~~~\n",i,a);
#endif
        
        if(a < last )
        {
            // go down
            
            if(valleyPos != -1)
            {
                if (rightTopPos == -1)
                {
                    rightTopPos = i -1;
#ifdef TEST
                    printf("right: %d\n",rightTopPos);
#endif
                    //calc
                    int offset = A[rightTopPos] - A[leftTopPos];
                    if ( offset < 0 )
                        rain += offset * (rightTopPos - leftTopPos);
                    
                    totalRain += rain;
                    
                    // reset
                    rain = 0;
                    leftTopPos=rightTopPos=valleyPos=-1;
                }
            }
            
            
            if (leftTopPos == -1)
            {
                leftTopPos = i -1;
#ifdef TEST
                printf("leftpos: %d ,value: %d\n",leftTopPos,A[leftTopPos]);
#endif
            }
        }
        else
        {
            if (valleyPos == -1)
                valleyPos = i -1;
        }
       
        int g = A[leftTopPos] - a;
        

        if (valleyPos != -1 && a > A[leftTopPos])
            ;
        else
        {
            rain += g;
#ifdef TEST
            printf("get: %d\n",g);
#endif
        }
        
        last = A[i];
    }
    
    return totalRain;
}



int main(int argc, const char * argv[])
{
    int A[] = {0,2,0};
//    int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int len = sizeof(A)/sizeof(A[0]);
    
    printf("%d\n", trap(A, len ) );
    
    return 0;
}
