//
//  main.cpp
//  Combination Sum II
//
//  Created by liaogang on 14/12/30.
//  Copyright (c) 2014年 liaogang. All rights reserved.
//

#include <iostream>
#include "../../leetcode.h"

/**
    Combination Sum II
 
 Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 
 Each number in C may only be used once in the combination.
 
 Note:
 
 All numbers (including target) will be positive integers.
 Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 The solution set must not contain duplicate combinations.
 
 For example, given candidate set 10,1,2,7,6,1,5 and target 8,
 A solution set is:
 [1, 7]
 [1, 2, 5]
 [2, 6]
 [1, 1, 6]
 */

/// find the value is no larger than A[start] , and is no larger than sum ,till sum is zero.
void dfs( vector<int> &A , int start , int sum , vector<vector<int>>  &output ,vector<int> &result)
{
    int len = (int) A.size();
    
    
    for (; start < len ; start++)
    {
        int val = A[start];
        int sum_val = sum - val;
        if (sum_val == 0)
        {
            vector<int> result2 = result;
            result2.push_back(val);
            
            output.push_back(result2);
            break;
        }
        else if(sum_val > 0)
        {
            vector<int> result2 = result;
            result2.push_back(val);
            
            dfs(A, start + 1, sum_val , output ,result2);
        }
        else
            break;
        
        while (A[start+1] == val)
            start++;
    }
    
}


class Solution
{
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end() );
        
        vector<vector<int>> output;
        vector<int> result;
        
        dfs(candidates, 0, target, output, result);
        
        printVecVec(output);
        
        return output;
    }
};


int main(int argc, const char * argv[])
{
    vector<int> test({10,1,2,7,6,1,5});
    int target = 8;
    
    Solution s;
    
    s.combinationSum2(test, target);
    
    return 0;
}

