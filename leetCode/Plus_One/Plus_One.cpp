//
//  main.cpp
//  Plus_One
//
//  Created by liaogang on 14/11/10.
//  Copyright (c) 2014年 gang.liao. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


/**
 Given a non-negative number represented as an array of digits, plus one to the number.
 
 The digits are stored such that the most significant digit is at the head of the list.
 （位数大的在数组的前面，即从个位在最右边。）
 
 */




class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> result;
        
        
        int jinWei = true;
        size_t len = digits.size();
        int i = (int) len -1 ;
        for (; i >= 0 ; i--)
        {
            if (jinWei == false)
                break;
            
            int add = digits[i];
            add += 1 ;
            
            if (add>9)
            {
                add =0;
                jinWei = true;
            }
            else
            {
                jinWei=false;
            }
            
            digits[i]=add;
        }
       
        
        if (i == -1 && jinWei == true)
        {
            result.push_back(1);
        }
        
        auto end=digits.end();
        for (auto i = digits.begin(); i != end; i++)
        {
            result.push_back(*i);
        }
        
        
        return result;
    }
};


int main(int argc, const char * argv[])
{
    Solution s;
    vector<int> test({9});
    
    vector<int> result = s.plusOne(test);
    
    
    return 0;
}
