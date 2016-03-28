//
//  main.cpp
//  Contains Duplicate
//
//  Created by liaogang on 16/3/25.
//  Copyright © 2016年 liaogang. All rights reserved.
//

#include <iostream>

/**
 Contains Duplicate
  Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
 */

#include "../leetcode.h"
#include <set>
#include <unordered_set>

bool containsDuplicate(vector<int>& nums)
{
    unordered_set<int> tb;
//  std::set<int> tb;
    
    for (int a : nums) {
        if (tb.find(a) == tb.end() ) {
            tb.insert(a);
        }
        else{
            return true;
        }
    }
    
    return false;
}


int main(int argc, const char * argv[])
{
    
    
    return 0;
}
