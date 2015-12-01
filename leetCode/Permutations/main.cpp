//
//  main.cpp
//  Permutations
//
//  Created by liaogang on 15/6/17.
//  Copyright (c) 2015年 liaogang. All rights reserved.
//

#include <iostream>
#include "../leetcode.h"

/*
 Given a collection of numbers, return all possible permutations.
 
 For example,
 [1,2,3] have the following permutations:
 [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */

void two(vector<int> &nums,vector<int> &curr,int left,int right,vector<vector<int>> &collecter)
{
    auto  r1 = curr;
    auto r2 = curr;
    
    r1.push_back(nums[left]);
    r1.push_back(nums[right]);

    r2.push_back(nums[right]);
    r2.push_back(nums[left]);
    
    collecter.push_back(r1);
    collecter.push_back(r2);
}


void dfs(vector<int> &nums,vector<int> &curr,int start,vector<vector<int>> &collecter)
{
    int c = nums.size();
    
    if (start + 1 == c  ) {
        two(nums,curr,start,start+1,collecter);
    }
    else
    {
        for (int i = start; i < c - 1; i++) {
            
            vector<int> temp = curr;
            vector<int> nums2 = nums;
            nums2.erase(nums2.begin()+i);
            
            temp.push_back(nums[i]);
            
            dfs(nums, temp, start + 1, collecter);
        }
        
    }
}

// 深度搜索,保存中间值?
// [1,[n,m]]的全排列就是1与 [n,m]的全排列 的全排列。

vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> collecter;
    vector<int> curr;
    dfs(nums, curr, 0, collecter);
    
    
    return collecter;
}

int main(int argc, const char * argv[])
{
    vector<int> nums({1,2,3});
    vector<vector<int>> result = permute( nums );
    
    printVecVec(result);
    
    
    return 0;
}
