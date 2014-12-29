//
//  main.cpp
//  Remove Element
//
//  Created by liaogang on 14/12/29.
//  Copyright (c) 2014年 liaogang. All rights reserved.
//

#include <iostream>
#include "../../leetcode.h"

/**
    Remove Element
 
    Given an array and a value, remove all instances of that value in place and return the new length.
 
    The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */

int removeElement(int A[], int n, int elem)
{
    int newLen = n;
    int start = -1;
    
    for (int i =0; i <= newLen ; i++)
    {
        int val = A[i];
        bool bEnd = false;
        if (i == newLen )
        {
            val = elem - 1;
            bEnd = true;
        }
        
        if (val == elem)
        {
            if (start == -1)
                start = i;
        }
        else
        {
            if (start != -1)
            {
                int eLen = i - start;
                
                // delete [start,end)
                memmove( A + start, A + i, (newLen -1 - start) * sizeof(int));
                
                newLen -= eLen;
                
                if ( bEnd )
                    break;
                
                i -= eLen;
                start = -1;
            }
        }
    }
    
    return newLen;
}

int main(int argc, const char * argv[])
{
    //0,3,1,1,0,1,3,0,3,
    //3,0,3,
    int test[] = {3,3,1,3};
    //int test222[200] = {0};
    int target = 3;
    
    
    const int len = sizeof(test)/sizeof(test[0]) ;
    
    int newLen = removeElement(test,len,target);
    
    printf("newLen: %d\n",newLen);
    
    for (int i =0; i < newLen; i++) {
        printf("%d\n",test[i]);
    }
    
    return 0;
}

