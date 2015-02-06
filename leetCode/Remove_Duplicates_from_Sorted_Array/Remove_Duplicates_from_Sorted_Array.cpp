//
//  main.cpp
//  Remove_Duplicates_from_Sorted_Array
//
//  Created by liaogang on 14/11/17.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//

#include <iostream>

/**
 Remove Duplicates from Sorted Array
 
 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 
 Do not allocate extra space for another array, you must do this in place with constant memory.
 
 For example,
 Given input array A = [1,1,2],
 
 Your function should return length = 2, and A is now [1,2].
 */


int removeDuplicates(int A[], int n)
{
    int newLen = n;
    
    int duplicates=0;
    int last = A[0]==0?1:0;
    int dupBeg = -1;
    for (int i = 0; i <= newLen ; i ++)
    {
        if ( i < newLen && A[i] == last)
        {
            duplicates++;
            if (duplicates == 1)
                dupBeg = i;
        }
        
        if (A[i] != last || i == newLen )
        {
            last=A[i];
           
            if (duplicates>0)
            {
                printf("delete from %d , len: %d\n",A[dupBeg],duplicates);
                
                ///move  [i,newLen-1] to [dupBeg,dup]
                ///newLen -= dup -1 ;
                memmove( A + dupBeg , A + i , sizeof(int)*(newLen - i));
                newLen -= duplicates ;
                
                i -= duplicates;
                duplicates = 0;
            }
        }

    }
    
    return newLen;
}


/**
 Remove Duplicates from Sorted Array II
 Follow up for "Remove Duplicates":
 What if duplicates are allowed at most twice?
 
 For example,
 Given sorted array A = [1,1,1,2,2,3],
 
 Your function should return length = 5, and A is now [1,1,2,2,3].
 */


int removeDuplicates2(int A[], int n)
{
    int newLen = n;
    
    int duplicates=0;
    int last = A[0]==0?1:0;
    int dupBeg = -1;
    for (int i = 0; i <= newLen ; i ++)
    {
        if ( i < newLen && A[i] == last)
        {
            duplicates++;
            if (duplicates == 2)
                dupBeg = i;
        }
        
        if (A[i] != last || i == newLen )
        {
            last=A[i];
            
            if (duplicates>=2)
            {
                duplicates-=1;
                
                printf("delete from %d , len: %d\n",A[dupBeg],duplicates);
                
                ///move  [i,newLen-1] to [dupBeg,dup]
                ///newLen -= dup -1 ;
                memmove( A + dupBeg , A + i , sizeof(int)*(newLen - i));
                newLen -= duplicates ;
                
                i -= duplicates;
            }
            
            duplicates = 0;
        }
        
    }
    
    return newLen;
}

int main(int argc, const char * argv[])
{
    //int test[] = {0,0,0,0,0,1,2,2,3,3,4,4};
    int test[] = {1,1,2,2};
    int newLen = removeDuplicates2(test, sizeof(test)/sizeof(test)[0]);
    printf("%d\n",newLen);
  
    
    for (int i = 0; i < newLen ; i++) {
        printf("%d",test[i]);
        if (i != newLen -1)
            printf(", ");
    }

    printf("\n");
    
    return 0;
}
