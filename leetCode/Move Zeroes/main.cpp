//
//  main.cpp
//  Move Zeroes
//
//  Created by liaogang on 16/3/14.
//  Copyright © 2016年 liaogang. All rights reserved.
//

#include <iostream>
#include "../leetcode.h"



/**
 Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
 
 For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
 
 Note:
 
 You must do this in-place without making a copy of the array.
 Minimize the total number of operations.
 

 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    
        
        int zeroCount = 0;
        for (auto i = nums.end() - 1 ;  ; i-- ) {
            
            if (*i == 0) {
                nums.erase(i);
                zeroCount++;
            }
            
            if( i == nums.begin() )
            {
                break;
            }
        }
        
        while (zeroCount > 0) {
            nums.push_back(0);
            zeroCount--;
        }
        
        
    }
};

int main(int argc, const char * argv[]) {
    
//    vector<int> b({0, 1, 0, 3, 12});
    vector<int> b({0,  0});
    Solution a;
    a.moveZeroes(b);
    
    return 0;
}
