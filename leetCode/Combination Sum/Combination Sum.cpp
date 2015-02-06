//
//  main.cpp
//  Combination Sum
//
//  Created by liaogang on 14/12/5.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//

#include <iostream>
#include "../../leetcode.h"

/**
    Combination Sum
 
 
 Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 
 The same repeated number may be chosen from C unlimited number of times.
 
 Note:
 
 All numbers (including target) will be positive integers.
 Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 The solution set must not contain duplicate combinations.
 
 For example, given candidate set 2,3,6,7 and target 7,
 A solution set is:
 [7]
 [2, 2, 3]
 
 */

#include <vector>

using namespace std;




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
            
            dfs(A, start, sum_val , output ,result2);
        }
        else
            break;
    }
    
}








class Solution
{
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target)
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
    vector<int> test({2,3,6,7});
    int target = 7;
    
    Solution s;
    
    s.combinationSum(test, target);
    
    return 0;
}
