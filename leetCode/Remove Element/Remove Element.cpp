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

int removeElement(int A[], int newLen, int elem)
{
    int start = -1;
    
    int i =0;
    for (; i < newLen ; i++)
    {
        if (A[i] == elem)
        {
            if (start == -1)
                start = i;
        }
        else
        {
            if (start != -1)
            {
                int eLen = i - start;
                
                // move from [i,array end] to  [start,i -1 ]
                memmove( A + start, A + i, (newLen -1 - start) * sizeof(int));
                
                newLen -= eLen;
                i -= eLen;
                start = -1;
            }
        }
    }
    
    
    if (start != -1)
    {
        int eLen = i - start;
        
        memmove( A + start, A + i, (newLen -1 - start) * sizeof(int));
        
        newLen -= eLen;
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

