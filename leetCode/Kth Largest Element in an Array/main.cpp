//
//  main.cpp
//  Kth Largest Element in an Array
//
//  Created by liaogang on 16/3/25.
//  Copyright © 2016年 liaogang. All rights reserved.
//

#include <iostream>

/**
 Kth Largest Element in an Array
 Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
 
 For example,
 Given [3,2,1,5,6,4] and k = 2, return 5.
 
 Note:
 You may assume k is always valid, 1 ≤ k ≤ array's length.
 */

#include "../leetcode.h"

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
        reverse(nums.begin(), nums.end());
        
        return nums[k - 1];
    }
};

int main(int argc, const char * argv[]) {
    
    
    Solution a;
    vector<int> b ({1});
    a.findKthLargest(b, 1);
    
    
    return 0;
}
