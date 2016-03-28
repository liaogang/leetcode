//
//  main.cpp
//  Maximum Subarray
//
//  Created by liaogang on 16/3/21.
//  Copyright © 2016年 liaogang. All rights reserved.
//

#include <iostream>
#include "../leetcode.h"

/**
 Maximum Subarray
 
 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
 
 For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 the contiguous subarray [4,−1,2,1] has the largest sum = 6.
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int len = nums.size();
        if (len == 1) {
            return nums[0];
        }
        else if( len == 2)
        {
            int a = nums[0];
            int b = nums[1];
            int c = a+b;
            
            int max = a;
            
            if (b > max)
                max = b;
            
            if (c > max)
                max = c;
            
            
            return max;
        }
        
        
        
        int min=nums[0];//保存最小的那个
        int max=min;   //最大的
        int sum=0;      //积分值
        int numMax = min;

        if (min > 0)
            min = 0;
        
        
        for (int j=0;j<len;++j)
        {
            int v = nums[j];
            sum+=v;
            
            printf("sum: %d\n",sum);
            
            if (sum<min)
                min=sum;
            if (sum>max)
                max=sum;
            if (v > numMax)
                numMax = v;
        }
        
        int mn = max - min;
        if (max < 0) {
            return numMax;
        }
        
        
        
//        int mmax = mn;
//        if (max > mmax) {
//            mmax = max;
//        }
//        
//        if (numMax > mmax) {
//            mmax = numMax;
//        }
//        
//        return mmax;
        
        return mn > numMax ? mn : numMax ;
    }
};


int main(int argc, const char * argv[]) {
    
//    const int num[]= {-2,1,-3,4,-1,2,1,-5,4};
//    const int num[]= {-2,1};
//    const int num[]= {-2,-3,-1};
//    const int num[]= {0,1,2,-1};
    
    
//    const int num[8]={1, -2, 3, 10, -4, 7, 2, -5};
    
    {
        const int num[]= {0,1,-1,-2};
        int len= sizeof(num) / sizeof(int);
        vector<int> nums(num,num+len);
        Solution a;
        int r = a.maxSubArray(nums);
        assert(r == 1);
    }
   
    
    {
        const int num[]= {0,8,-19,5,-4,20};
        int len= sizeof(num) / sizeof(int);
        vector<int> nums(num,num+len);
        Solution a;
        int r = a.maxSubArray(nums);
        assert(r == 21);
    }
    
    
    return 0;
}

/**


*/