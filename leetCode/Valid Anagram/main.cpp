//
//  main.cpp
//  Valid Anagram
//
//  Created by liaogang on 16/3/25.
//  Copyright © 2016年 liaogang. All rights reserved.
//

#include <iostream>


/**
 Given two strings s and t, write a function to determine if t is an anagram of s.
 
 For example,
 s = "anagram", t = "nagaram", return true.
 s = "rat", t = "car", return false.
 
 Note:
 You may assume the string contains only lowercase alphabets.
 
 Follow up:
 What if the inputs contain unicode characters? How would you ad
 
 */

#include "../leetcode.h"



bool isAnagram2(const char * s,const char * t) {
    
    int len = strlen(s);
    int tb[26] = {0};
    
    if (len == strlen(t) )
    {
        for (int i = 0; i < len ; i++) {
            tb[ s[i]-'a' ]++;
            tb[ t[i] - 'a']--;
        }
        
        for (int i = 0; i < 26 ; i++) {
            if (tb[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
    else
    {
        return false;
    }
    
}



bool isAnagram(string s, string t) {
    return isAnagram2(s.c_str(), t.c_str());
    
//    if (s.length() == t.length())
//    {
//        sort(t.begin(), t.end());
//        sort(s.begin(), s.end());
//        
//        return s.compare(t) == 0;
//    }
//    else
//        return false;
    
}

int main(int argc, const char * argv[]) {
   
    isAnagram("nl", "cs");
    
    return 0;
}
