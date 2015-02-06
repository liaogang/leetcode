//
//  main.cpp
//  Median of Two Sorted Arrays
//
//  Created by liaogang on 14/11/18.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//

#include <iostream>
/**
 Median of Two Sorted Arrays
 
 There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 
 中值 中值是一组数中间位置的数；即一半数的值比中值大，另一半数的值比中值小。例如，2、3、3、5、7 和 10 的中值是 4。

 */


/// 获取比给定的值数值大的与数值小的个数的差值。
int getOffsetNumbers()
{
    
}

double findMedianSortedArrays(int A[], int m, int B[], int n)
{
    double r ;
    int maxLen,minLen;
    int *max,*min;
    
    if (m < n)
    {
        max = b;
        maxLen = n;
        
        min = a;
        minLen = m;
    }
    else
    {
        min = b;
        mixLen = n;
        
        max = a;
        manLen = m;
    }
    
    
    int a = maxLen/2;
    const double offset = 0.1f;
    r = max[a] + offset; ///midian of max array
    
    
    int sortedSame = (bool)(max[1] - max[0]) == (bool)(min[1] - min[0]);
    
    int offsetMax = minLen /2 ;
    int offsetMin;
    
    int largerNumbersInMax = max /2 ;
    int littleNumbersInMax = max /2 ;
    
    int largerNumbersInMin ;
    int littleNumbersInMin ;
    
    while ( offsetMax != offsetMin)
    {
        
    }
    
    
    
}

int main(int argc, const char * argv[])
{
    return 0;
}
