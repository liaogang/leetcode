//
//  main.cpp
//  Range Sum Query
//
//  Created by liaogang on 15/12/1.
//  Copyright © 2015年 liaogang. All rights reserved.
//

#include <iostream>


/**
 Range Sum Query - Immutable
 
 Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j); inclusive.
 
 Example:
 
 Given nums = [-2, 0, 3, -5, 2, -1]
 
 sumRange(0, 2) -> 1
 sumRange(2, 5) -> -1
 sumRange(0, 5) -> -3
 
 Note:
 
 You may assume that the array does not change.
 There are many calls to sumRange function.
 
 */

#include "../leetcode.h"

class NumArray {
    int* sumArr;
public:
    NumArray(vector<int> &nums)
    {
        int size = nums.size();
        sumArr = new int[size];
        
        int sum=0;
        for (int k =0 ; k < size; k++) {
            sum += nums[k];
            sumArr[k]=sum;
        }
        
        
    }
    
    int sumRange(int i, int j) {
        return sumArr[j] - (i == 0? 0 : sumArr[i-1]) ;
    }
    
    
    //dealloc , delete sum array
};



int main(int argc, const char * argv[]) {
    
    vector<int> b({-2,0,3,-5,2,-1});
    NumArray numArray(b);
    numArray.sumRange(2, 5);
    
    
    return 0;
}


