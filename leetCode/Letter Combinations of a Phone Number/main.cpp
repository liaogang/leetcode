//
//  main.cpp
//  Letter Combinations of a Phone Number
//
//  Created by liaogang on 16/2/18.
//  Copyright © 2016年 liaogang. All rights reserved.
//

#include <iostream>
#include "../leetcode.h"


/**
 @link https://leetcode.com/problems/letter-combinations-of-a-phone-number
 Given a digit string, return all possible letter combinations that the number could represent.
 
 A mapping of digit to letters (just like on the telephone buttons) is given below.
 
 
 
 Input:Digit string "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 
 Note:
 Although the above answer is in lexicographical order, your answer could be in any order you want.
 
 */
//////////////////////1   2     3    4       5   6     7      8
const char *map2[] = {"&","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz","+"," ","#"};


void combine(vector<string> &collector,string &combines,vector<int> &idigits,int dp)
{
    if (dp == idigits.size()) {
        collector.push_back(combines);
        return;
    }
    
    int phoneNumber = idigits[dp];
    
    const char *phoneLetters = map2[phoneNumber-1];

    int len = strlen(phoneLetters);
    for (int i= 0; i < len; i++) {
        char l = phoneLetters[i];

        string cb2 = combines;
        cb2+=l;
        
        combine(collector, cb2 , idigits,dp+1);
    }
   
}

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        
        if (digits.size() > 0) {
            
            
            vector<int> idigits;
            
            for ( auto i = digits.begin() ;i != digits.end(); i++)
            {
                char d = *i;
                
                idigits.push_back(d-('1'-1) );
            }
            
            string e;
            combine(result,e,idigits,0);
        }
        
        return result;
    }
};


int main(int argc, const char * argv[]) {
    
    Solution a;
    a.letterCombinations("");
    a.letterCombinations("23");
    
    return 0;
}

