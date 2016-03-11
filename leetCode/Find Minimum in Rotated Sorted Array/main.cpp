//
//  main.cpp
//  Find Minimum in Rotated Sorted Array
//
//  Created by liaogang on 16/3/11.
//  Copyright © 2016年 liaogang. All rights reserved.
//

#include <iostream>

/**
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 
 Find the minimum element.
 
 You may assume no duplicate exists in the array.
 */
#include "../leetcode.h"

class Solution {
public:
    
    /// touch mid , return mid posiiton of the break point
    /// -1 : left side , 1 : right side
    int touchmid(vector<int> & nums , int arrayBegValue, int arrayEndValue , int beg, int end)
    {
//        printf("find from %d, %d\n",beg,end);
        
        int mid = (end + beg) / 2;
        
        int result = -1;
        
        if (beg == end) {
            return  nums[beg];
        }
        else if ( end - beg == 1)
        {
            if( nums[beg] < nums[end])
                return nums[beg];
            else
                return nums[end];
        }
        
        
        
        if (nums[mid] > arrayBegValue) {
            beg = mid;
            return touchmid(nums, arrayBegValue, arrayEndValue, beg, end);
        }
        else
        {
            end = mid;
            return touchmid(nums, arrayBegValue, arrayEndValue, beg, end);
        }

        
        return result;
    }
    
    
    int findMin(vector<int>& nums) {
        
        int beg = 0;
        int end = nums.size()-1;
        
        
        bool breaked = false;
        if (nums[beg] < nums[end]) {
            breaked = false;
            
            return nums[beg];
        }
        else
        {
            breaked = true;
            
        }
        
        int  min = touchmid(nums, nums.front() , nums.back() , 0, end);
        
        printf("min %d\n",min);
        
        return min;
    }
    
};

int main(int argc, const char * argv[]) {
    
    Solution a;
    
//    vector<int> nums ({ 4,5,6,7,0,1,2 });
    
//    vector<int> nums ({ 2,3,1 });
    vector<int> nums ({ 1,2,3 });
    
    a.findMin(nums);
    
    
    
    return 0;
}
