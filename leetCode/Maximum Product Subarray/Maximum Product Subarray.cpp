//
//  main.cpp
//  Maximum Product Subarray
//
//  Created by liaogang on 14/11/18.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//

#include <iostream>

/**
 Find the contiguous subarray within an array (containing at least one number) which has the largest product(乘积).
 
 For example, given the array [2,3,-2,4],
 the contiguous subarray [2,3] has the largest product = 6.
 
 */


///传入第一个和最后一个负数出现的位置。
int calcGroupsMax(int A[],int groupLen,int totalSum,int negs,int firstNeg,int lastNeg,int firstNegSum)
{
    if (negs%2 == 0)
        return totalSum;
    else
    {
        if (groupLen == 1 )
            return totalSum;
       
        if (negs == 1 && (firstNeg == 0 || firstNeg == groupLen-1 ) ) {
            return totalSum/ A[firstNeg];
        }
        
        int lastNegSum = 1;
        for (int i = lastNeg; i < groupLen ; i++)
        {
            lastNegSum*=A[i];
        }
        
        int maxPartSum  ;
        int minPartSum ;
        if (firstNegSum < lastNegSum)
        {
            maxPartSum = lastNegSum;
            minPartSum = firstNegSum;
        }
        else
        {
            maxPartSum = firstNegSum;
            minPartSum = lastNegSum;
        }
        
        
        if (negs == 1)
            return minPartSum/A[firstNeg];
        
        return totalSum/maxPartSum;
    }
}

int maxProduct(int num[], int n)
{
    if (n == 0) {
        return 0;
    }
    else
    if (n == 1) {
        return num[0];
    }


    int sum=0;      //积分值
    int max=0;
    
    int negs=0;
    int firstNeg=-1;
    int lastNeg;
    int firstNegSum;
    int groupCount=0;
    for (int j=0;j<=n;++j)
    {

        int value = num[j];
        
        if (j == n ) {
            value = 0;
        }
        
        if(value == 0 )
        {
            int groupBeg = j - groupCount;
            int groupMax  = calcGroupsMax((int*)num+ groupBeg, groupCount, sum, negs, firstNeg - groupBeg, lastNeg - groupBeg, firstNegSum);
            
            if (groupMax > max)
                max = groupMax;
            
            
            /// next group
            firstNeg=-1;
            firstNegSum=1;
            groupCount=0;
            sum=0;
            negs=0;
            continue;
        }

        
        if (sum == 0) {
            sum = value;
        }
        else
            sum*=value;
 
        groupCount++;
        if (value<0)
        {
            negs++;
            
            if (firstNeg == -1)
            {
                firstNeg = j;
                firstNegSum = sum;
            }
            
            lastNeg = j;
        }
        
        
        

    }
    
    return max;
}


int main(int argc, const char * argv[])
{
    int test[]={0,-2,0};
    printf("%d\n",maxProduct(test, sizeof(test)/sizeof(test[0])) );
    
    return 0;
}
