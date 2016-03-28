//
//  main.cpp
//  Missing Number
//
//  Created by liaogang on 16/3/25.
//  Copyright © 2016年 liaogang. All rights reserved.
//

#include <iostream>


/**
 Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
 
 For example,
 Given nums = [0, 1, 3] return 2.
 
 Note:
 Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 
 */

#include "../leetcode.h"

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int min = 0;
        int count = nums.size();
        int max = count;
        int sum = 0;
        for (int i = 0; i < count; i++) {
            int v = nums[i];
            
            if (v < min) {
                min = v;
            }
            
            if (v > max) {
                max = v;
            }
            
            sum += v;
        }
        
        int eCount = count + 1;
        int eSum = ( max+min ) * eCount / 2;
        
        
        int result = eSum - sum;
        return result;
    }
};


int main(int argc, const char * argv[]) {
    
//    vector<int> nums({0,1,3});
    vector<int> nums({1});
    Solution a;
    a.missingNumber(nums);
    
    
    
    return 0;
}
